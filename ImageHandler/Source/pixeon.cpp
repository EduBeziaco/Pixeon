#include "pixeon.h"
#include "ui_pixeon.h"
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QApplication>
#include <QClipboard>
#include <QColorSpace>
#include <QDir>
#include <QFileDialog>
#include <QImageReader>
#include <QImageWriter>
#include <QLabel>
#include <QMenuBar>
#include <QMessageBox>
#include <QMimeData>
#include <QPainter>
#include <QScreen>
#include <QScrollArea>
#include <QScrollBar>
#include <QStandardPaths>
#include <QStatusBar>
#include <QStandardItemModel>
#include <QStandardItem>

Pixeon::Pixeon(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Pixeon)
    ,imageLabel(new QLabel)
    ,original(new QLabel)
    ,model(new QStandardItemModel)
{
    ui->setupUi(this);

    //associa os trigers as chamadas de funções
    //associação para a ação Open, que abre os arquivos
    connect(ui->actionOpen, &QAction::triggered, this, &Pixeon::open);
    //associações para detectar quando os sliders são alterados pelo usuario
    connect(ui->sliderBrilho,    SIGNAL(valueChanged(int)), this, SLOT(valuesChanged()));
    connect(ui->sliderContraste, SIGNAL(valueChanged(int)), this, SLOT(valuesChanged()));
    //associação para detectar quando um item do listview é selecionado
    bool success = connect(ui->listView,SIGNAL(clicked(const QModelIndex)),this,SLOT(handleSelectionChanged(QModelIndex)));
    Q_ASSERT(success);

    //configura o imageLabel
    imageLabel->setBackgroundRole(QPalette::Base);
    imageLabel->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imageLabel->setScaledContents(true);

    //configura o scroll principal
    ui->mainScroll->setBackgroundRole(QPalette::Dark);
    ui->mainScroll->setWidget(imageLabel);
    ui->mainScroll->setWidgetResizable(false);

    //cria as ações no menu de opções
    createActions();

    //escalonando a janela da aplicação
    resize(QGuiApplication::primaryScreen()->availableSize() * 3 / 5);

    //configura o listView
    ui->listView->setModel( model );
    ui->listView->setSelectionMode(QAbstractItemView::SingleSelection);

    //salva uma versão original da imagem que está sendo editada
    original->setVisible(false);
}

Pixeon::~Pixeon()
{
    delete ui;
}
void Pixeon:: valuesChanged()
{
    //faz uma copia da imagem
    QImage image = original->pixmap().toImage();

    //QImage image = imageLabel->pixmap().toImage();

    //aplica ambos os efeitos
    contrastChanged(image,ui->sliderContraste->value());
    brightnessChanged(image,ui->sliderBrilho->value());

    //passa a imagem para o pixmal da imageLabel
    imageLabel->setPixmap(QPixmap::fromImage(image));
}

QImage* Pixeon:: brightnessChanged(QImage& image, int  value)
{
    //verifica se o valor realmente está dentro da margem permitida
    if (value >= -255 && value <= 255){
        //variaveis temporarias para trabalhar com cada canal de cor individualmente
        int red, green, blue;
        int pixels = image.width() * image.height();
        //cria um ponteiro de acesso aos bits da imagem
        unsigned int *data = (unsigned int *)image.bits();
        //percorre todos os pixels da imagem
        for (int i = 0; i < pixels; ++i) {
            //aplica o brilho e verifica se está dentro do permetido (Hexadecimal)
            red= qRed(data[i])+ value;
            red = (red < 0x00) ? 0x00 : (red > 0xff) ? 0xff : red;
            green= qGreen(data[i])+value;
            green = (green < 0x00) ? 0x00 : (green > 0xff) ? 0xff : green;
            blue= qBlue(data[i])+value;
            blue =  (blue  < 0x00) ? 0x00 : (blue  > 0xff) ? 0xff : blue ;

            //depois dos valores alterados, atribui os mesmo a imagem
            data[i] = qRgba(red, green, blue, qAlpha(data[i]));
        }
    }

    return &image;
}


QImage* Pixeon::contrastChanged(QImage& image, int  value)
{
    //verifica se o valor realmente está dentro da margem permitida
    if (value > 0 && value < 20){
        double contrast = (100.0+value)/100.0;
        //variaveis temporarias para trabalhar com cada canal de cor individualmente
        double red, green, blue;
        int pixels = image.width() * image.height();
        //cria um ponteiro de acesso aos bits da imagem
        unsigned int *data = (unsigned int *)image.bits();
        //percorre todos os pixels da imagem
        for (int i = 0; i < pixels; ++i) {
            //aplica o contraste e verifica se está dentro do permetido (Hexadecimal)
            red= 128+ contrast*(qRed(data[i])-128);
            red = (red < 0x00) ? 0x00 : (red > 0xff) ? 0xff : red;
            green= 128+ contrast*(qGreen(data[i])-128);
            green = (green < 0x00) ? 0x00 : (green > 0xff) ? 0xff : green;
            blue= 128+ contrast*(qBlue(data[i])-128);
            blue =  (blue  < 0x00) ? 0x00 : (blue  > 0xff) ? 0xff : blue ;

            //depois dos valores alterados, atribui os mesmo a imagem
            data[i] = qRgba(red, green, blue, qAlpha(data[i]));
        }
    }
    return &image;
}

void Pixeon:: handleSelectionChanged(QModelIndex  index)
{
    //carrega a imagem selecionado pelo listView
    loadFile(ui->listView->currentIndex().data(Qt::DisplayRole).toString());
    //reseta os sliders
    ui->sliderBrilho->setValue(0);
    ui->sliderContraste->setValue(0);
    //qDebug() << "Mudou a seleção para : " << index;
}


static void initializeImageFileDialog(QFileDialog &dialog, QFileDialog::AcceptMode acceptMode)
{
    static bool firstDialog = true;
    //verifica se é a primeira vez abrindo o QDialog, se for salva o diretorio
    if (firstDialog) {
        firstDialog = false;
        const QStringList picturesLocations = QStandardPaths::standardLocations(QStandardPaths::PicturesLocation);
        dialog.setDirectory(picturesLocations.isEmpty() ? QDir::currentPath() : picturesLocations.last());
    }

    QStringList mimeTypeFilters;
    const QByteArrayList supportedMimeTypes = acceptMode == QFileDialog::AcceptOpen? QImageReader::supportedMimeTypes() : QImageWriter::supportedMimeTypes();
    for (const QByteArray &mimeTypeName : supportedMimeTypes)
        mimeTypeFilters.append(mimeTypeName);

    mimeTypeFilters.sort();
    dialog.setMimeTypeFilters(mimeTypeFilters);
    dialog.selectMimeTypeFilter("image/jpeg");
    dialog.setAcceptMode(acceptMode);
    if (acceptMode == QFileDialog::AcceptSave)
        dialog.setDefaultSuffix("jpg");
}

void Pixeon::setImage(const QImage &newImage)
{
    //seta a imagem nova
    image = newImage;
    if (image.colorSpace().isValid())
        image.convertToColorSpace(QColorSpace::SRgb);

    //seta a imagem do label e salva uma versão original
    imageLabel->setPixmap(QPixmap::fromImage(image));
    original->setPixmap(QPixmap::fromImage(image));


    scaleFactor = 1.0;
    fitToWindowAct->setEnabled(true);
    updateActions();

    if (!fitToWindowAct->isChecked())
        imageLabel->adjustSize();
}


bool Pixeon::loadFile(const QString &fileName)
{
    //carrega a imagem
    QImageReader reader(fileName);
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
                                 tr("Cannot load %1: %2")
                                 .arg(QDir::toNativeSeparators(fileName), reader.errorString()));
        return false;
    }

    setImage(newImage);
    setWindowFilePath(fileName);

    //display de infos da imagem que foi carregada
    const QString message = tr("Opened \"%1\", %2x%3, Depth: %4")
        .arg(QDir::toNativeSeparators(fileName)).arg(image.width()).arg(image.height()).arg(image.depth());
    statusBar()->showMessage(message);
    return true;

}

void Pixeon::loadList(const QStringList &fileNames)
{
    //carrega a lista de todos os arquivos selecionados para o listView
    for (int i = 0; i < fileNames.size(); ++i){
       QStandardItem *item;
       item = new QStandardItem();
       item->setText(fileNames[i]);
       item->setEditable( false );
       model->appendRow( item );
       //qDebug() << "result : " << i;
   }
}

void Pixeon::open()
{
    //inicia o QFileDialog
    QFileDialog dialog(this, tr("Open File"));
    dialog.setFileMode(QFileDialog::ExistingFiles);
    initializeImageFileDialog(dialog, QFileDialog::AcceptOpen);

    while (dialog.exec() == QDialog::Accepted && !loadFile(dialog.selectedFiles().constFirst())) {}
    loadList(dialog.selectedFiles());
}


void Pixeon::adjustScrollBar(QScrollBar *scrollBar, double factor)
{
    //ajusta a barra de rolagem
    scrollBar->setValue(int(factor * scrollBar->value() + ((factor - 1) * scrollBar->pageStep()/2)));
}

void Pixeon::scaleImage(double factor)
{
    //escala a imagem conforme o fator
    scaleFactor *= factor;
    imageLabel->resize(scaleFactor * imageLabel->pixmap(Qt::ReturnByValue).size());

    //atualiza a escala da versão original também
    original->resize(scaleFactor * original->pixmap(Qt::ReturnByValue).size());

    //ajusta as barras de rolagem conforme a mudança de tamanho
    adjustScrollBar( ui->mainScroll->horizontalScrollBar(), factor);
    adjustScrollBar( ui->mainScroll->verticalScrollBar(), factor);

    //seta um minimo e um maximo para se escalar a imagem
    zoomInAct->setEnabled(scaleFactor < 3.0);
    zoomOutAct->setEnabled(scaleFactor > 0.333);
}

void Pixeon::zoomIn()
{
    scaleImage(1.25);
}

void Pixeon::zoomOut()
{
    scaleImage(0.8);
}

void Pixeon::rotLeft()
{
    //aplica uma rotação em 90 graus para a esquerda ou no sentido anti-horario.
    QPixmap pixmap(imageLabel->pixmap());
    QTransform tr;
    tr.rotate(-90);
    pixmap = pixmap.transformed(tr);
    imageLabel->setPixmap(pixmap);

    //atualiza a rotação da versão original também
    QPixmap pixmapOriginal(original->pixmap());
    pixmapOriginal = pixmapOriginal.transformed(tr);
    original->setPixmap(pixmapOriginal);
}

void Pixeon::rotRight()
{
    //aplica uma rotação em 90 graus para a direita ou no sentido horario.
    QPixmap pixmap(imageLabel->pixmap());
    QTransform tr;
    tr.rotate(90);
    pixmap = pixmap.transformed(tr);
    imageLabel->setPixmap(pixmap);

    //atualiza a rotação da versão original também
    QPixmap pixmapOriginal(original->pixmap());
    pixmapOriginal = pixmapOriginal.transformed(tr);
    original->setPixmap(pixmapOriginal);
}


void Pixeon::normalSize()
{
    //retorna a imagem para sua escala original
    imageLabel->adjustSize();
    //atualiza a escala da versão original também
    original->adjustSize();
    scaleFactor = 1.0;
}

void Pixeon::fitToWindow()
{
    //ajusta o tamanho da imagem conforme o tamanho da aplicação
    bool fitToWindow = fitToWindowAct->isChecked();
    ui->mainScroll->setWidgetResizable(fitToWindow);
    if (!fitToWindow)
        normalSize();
    updateActions();
}

void Pixeon::about()
{
    QMessageBox::about(this, tr("About Image Viewer"),
            tr("<p>Essa aplicação foi desenvolvida por <b> Eduardo Batista Beziaco </b><br>"
               "Parte de um desafio técnico durante um processo seletivo. <br>"
               "Para maiores informações leia o arquivo <b> readme </b> nas pastas de arquivos do projeto.</p>"));
}


void Pixeon::createActions()
{
    //Cria as ações
    QMenu *fileMenu = menuBar()->addMenu(tr("&File"));

    QAction *openAct = fileMenu->addAction(tr("&Open..."), this, &Pixeon::open);
    openAct->setShortcut(QKeySequence::Open);

    fileMenu->addSeparator();

    QAction *exitAct = fileMenu->addAction(tr("E&xit"), this, &QWidget::close);
    exitAct->setShortcut(tr("Ctrl+Q"));

    QMenu *viewMenu = menuBar()->addMenu(tr("&View"));

    zoomInAct = viewMenu->addAction(tr("Zoom &In (25%)"), this, &Pixeon::zoomIn);
    zoomInAct->setShortcut(QKeySequence::ZoomIn);
    zoomInAct->setEnabled(false);

    zoomOutAct = viewMenu->addAction(tr("Zoom &Out (25%)"), this, &Pixeon::zoomOut);
    zoomOutAct->setShortcut(QKeySequence::ZoomOut);
    zoomOutAct->setEnabled(false);

    normalSizeAct = viewMenu->addAction(tr("&Normal Size"), this, &Pixeon::normalSize);
    normalSizeAct->setShortcut(tr("Ctrl+S"));
    normalSizeAct->setEnabled(false);

    //viewMenu->addSeparator();

    fitToWindowAct = viewMenu->addAction(tr("&Fit to Window"), this, &Pixeon::fitToWindow);
    fitToWindowAct->setEnabled(false);
    fitToWindowAct->setCheckable(true);
    fitToWindowAct->setShortcut(tr("Ctrl+F"));

    //Menu de rotação
    QMenu *RotateMenu = menuBar()->addMenu(tr("&Rotate"));

    leftRotAct = RotateMenu->addAction(tr("Rotate counter clockwise"), this, &Pixeon::rotLeft);
    leftRotAct->setEnabled(false);

    rightRotAct = RotateMenu->addAction(tr("Rotate clockwise"), this, &Pixeon::rotRight);
    rightRotAct->setEnabled(false);

    RotateMenu->addSeparator();

    //menu de ajuda
    QMenu *helpMenu = menuBar()->addMenu(tr("&Help"));

    helpMenu->addAction(tr("&About"), this, &Pixeon::about);
    helpMenu->addAction(tr("About &Qt"), &QApplication::aboutQt);
}

void Pixeon::updateActions()
{

    //atualiza as ações
    zoomInAct->setEnabled(!fitToWindowAct->isChecked());
    zoomOutAct->setEnabled(!fitToWindowAct->isChecked());
    normalSizeAct->setEnabled(!fitToWindowAct->isChecked());
    leftRotAct->setEnabled(true);
    rightRotAct->setEnabled(true);
}



