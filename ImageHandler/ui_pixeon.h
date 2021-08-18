/********************************************************************************
** Form generated from reading UI file 'pixeon.ui'
**
** Created by: Qt User Interface Compiler version 6.1.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PIXEON_H
#define UI_PIXEON_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pixeon
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QListView *listView;
    QScrollArea *mainScroll;
    QWidget *scrollAreaWidgetContents;
    QFrame *gSliders;
    QGridLayout *gridLayout_2;
    QLabel *label;
    QSlider *sliderBrilho;
    QLabel *label_2;
    QSlider *sliderContraste;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Pixeon)
    {
        if (Pixeon->objectName().isEmpty())
            Pixeon->setObjectName(QString::fromUtf8("Pixeon"));
        Pixeon->resize(800, 600);
        actionOpen = new QAction(Pixeon);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        centralwidget = new QWidget(Pixeon);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        listView = new QListView(centralwidget);
        listView->setObjectName(QString::fromUtf8("listView"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(2);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(listView->sizePolicy().hasHeightForWidth());
        listView->setSizePolicy(sizePolicy);

        gridLayout->addWidget(listView, 1, 0, 1, 1);

        mainScroll = new QScrollArea(centralwidget);
        mainScroll->setObjectName(QString::fromUtf8("mainScroll"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(8);
        sizePolicy1.setVerticalStretch(8);
        sizePolicy1.setHeightForWidth(mainScroll->sizePolicy().hasHeightForWidth());
        mainScroll->setSizePolicy(sizePolicy1);
        mainScroll->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 619, 478));
        mainScroll->setWidget(scrollAreaWidgetContents);

        gridLayout->addWidget(mainScroll, 1, 1, 1, 1);

        gSliders = new QFrame(centralwidget);
        gSliders->setObjectName(QString::fromUtf8("gSliders"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(gSliders->sizePolicy().hasHeightForWidth());
        gSliders->setSizePolicy(sizePolicy2);
        gSliders->setFrameShape(QFrame::StyledPanel);
        gSliders->setFrameShadow(QFrame::Raised);
        gridLayout_2 = new QGridLayout(gSliders);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label = new QLabel(gSliders);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_2->addWidget(label, 0, 0, 1, 1);

        sliderBrilho = new QSlider(gSliders);
        sliderBrilho->setObjectName(QString::fromUtf8("sliderBrilho"));
        sliderBrilho->setMinimum(-255);
        sliderBrilho->setMaximum(255);
        sliderBrilho->setSingleStep(0);
        sliderBrilho->setPageStep(10);
        sliderBrilho->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(sliderBrilho, 1, 0, 1, 1);

        label_2 = new QLabel(gSliders);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout_2->addWidget(label_2, 0, 1, 1, 1);

        sliderContraste = new QSlider(gSliders);
        sliderContraste->setObjectName(QString::fromUtf8("sliderContraste"));
        sliderContraste->setMaximum(19);
        sliderContraste->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(sliderContraste, 1, 1, 1, 1);


        gridLayout->addWidget(gSliders, 0, 1, 1, 1);

        Pixeon->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Pixeon);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 20));
        Pixeon->setMenuBar(menubar);
        statusbar = new QStatusBar(Pixeon);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        Pixeon->setStatusBar(statusbar);

        retranslateUi(Pixeon);

        QMetaObject::connectSlotsByName(Pixeon);
    } // setupUi

    void retranslateUi(QMainWindow *Pixeon)
    {
        Pixeon->setWindowTitle(QCoreApplication::translate("Pixeon", "Pixeon", nullptr));
        actionOpen->setText(QCoreApplication::translate("Pixeon", "Open", nullptr));
        label->setText(QCoreApplication::translate("Pixeon", "Brightness", nullptr));
        label_2->setText(QCoreApplication::translate("Pixeon", "Contrast", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Pixeon: public Ui_Pixeon {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PIXEON_H
