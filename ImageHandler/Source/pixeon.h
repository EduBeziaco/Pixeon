#ifndef PIXEON_H
#define PIXEON_H

#include <QMainWindow>
#include <QLabel>
#include <QScrollArea>
#include <QStandardItemModel>
#include <QItemSelection>

QT_BEGIN_NAMESPACE
namespace Ui { class Pixeon; }
QT_END_NAMESPACE

class Pixeon : public QMainWindow
{
    Q_OBJECT

public:
    Pixeon(QWidget *parent = nullptr);
    ~Pixeon();
    bool loadFile(const QString &fileName);
    void loadList(const QStringList &fileNames);

private slots:
    void open();
    void zoomIn();
    void zoomOut();
    void normalSize();
    void fitToWindow();
    void about();
    void rotLeft();
    void rotRight();
    void handleSelectionChanged(QModelIndex index );
    QImage* brightnessChanged(QImage& image, int value);
    QImage* contrastChanged(QImage& image, int value);
    void valuesChanged();



private:
    Ui::Pixeon *ui;
    void createActions();
    void createMenus();
    void updateActions();
    void setImage(const QImage &newImage);
    void scaleImage(double factor);
    void adjustScrollBar(QScrollBar *scrollBar, double factor);

    QImage image;
    QLabel *imageLabel;
    QLabel *original;
    double scaleFactor = 1;
    QStandardItemModel *model;

    QAction *zoomInAct;
    QAction *zoomOutAct;
    QAction *normalSizeAct;
    QAction *fitToWindowAct;
    //
    QAction *leftRotAct;
    QAction *rightRotAct;
};
#endif // PIXEON_H
