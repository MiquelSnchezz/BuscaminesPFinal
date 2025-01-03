/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLCDNumber *score_lcd;
    QPushButton *start_button;
    QLCDNumber *time_lcd;
    QWidget *widget;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(380, 490);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(380, 490));
        MainWindow->setMaximumSize(QSize(380, 490));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow { \n"
"	background-color: rgb(51, 170, 43);\n"
"}\n"
""));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        score_lcd = new QLCDNumber(centralWidget);
        score_lcd->setObjectName(QString::fromUtf8("score_lcd"));
        sizePolicy.setHeightForWidth(score_lcd->sizePolicy().hasHeightForWidth());
        score_lcd->setSizePolicy(sizePolicy);
        score_lcd->setMinimumSize(QSize(110, 40));
        score_lcd->setMaximumSize(QSize(110, 40));
        score_lcd->setDigitCount(3);
        score_lcd->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(score_lcd);

        start_button = new QPushButton(centralWidget);
        start_button->setObjectName(QString::fromUtf8("start_button"));
        sizePolicy.setHeightForWidth(start_button->sizePolicy().hasHeightForWidth());
        start_button->setSizePolicy(sizePolicy);
        start_button->setMinimumSize(QSize(37, 37));
        start_button->setMaximumSize(QSize(37, 37));
        start_button->setIconSize(QSize(20, 20));

        horizontalLayout->addWidget(start_button);

        time_lcd = new QLCDNumber(centralWidget);
        time_lcd->setObjectName(QString::fromUtf8("time_lcd"));
        sizePolicy.setHeightForWidth(time_lcd->sizePolicy().hasHeightForWidth());
        time_lcd->setSizePolicy(sizePolicy);
        time_lcd->setMinimumSize(QSize(110, 40));
        time_lcd->setMaximumSize(QSize(110, 40));
        time_lcd->setDigitCount(3);
        time_lcd->setSegmentStyle(QLCDNumber::Flat);

        horizontalLayout->addWidget(time_lcd);


        verticalLayout->addLayout(horizontalLayout);

        widget = new QWidget(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(360, 360));
        widget->setMaximumSize(QSize(360, 360));

        verticalLayout->addWidget(widget);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 380, 21));
        MainWindow->setMenuBar(menuBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Buscaminas", nullptr));
        start_button->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
