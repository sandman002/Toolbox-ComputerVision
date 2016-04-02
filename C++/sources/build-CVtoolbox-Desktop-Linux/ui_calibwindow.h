/********************************************************************************
** Form generated from reading UI file 'calibwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALIBWINDOW_H
#define UI_CALIBWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "cvglcam.h"

QT_BEGIN_NAMESPACE

class Ui_calibWindow
{
public:
    QAction *actionLoad_config;
    QAction *actionSave_config;
    QAction *actionOpen;
    QAction *actionCalibrate;
    QAction *actionSolve_PnP;
    QAction *actionAbout;
    QAction *actionHelp;
    QAction *actionSave_Transformation_Function;
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout;
    CvGlCam *viewport;
    QVBoxLayout *verticalLayout;
    QLCDNumber *timeKeeper;
    QProgressBar *progress;
    QPushButton *pushButton;
    CvGlCam *review;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QLabel *label;
    QLabel *label_2;
    QSpinBox *boardW;
    QSpinBox *boardH;
    QLabel *label_3;
    QSpinBox *spinBox;
    QMenuBar *menubar;
    QMenu *menuOpen_Camera;
    QMenu *menuCalibrate;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *calibWindow)
    {
        if (calibWindow->objectName().isEmpty())
            calibWindow->setObjectName(QStringLiteral("calibWindow"));
        calibWindow->resize(790, 454);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(calibWindow->sizePolicy().hasHeightForWidth());
        calibWindow->setSizePolicy(sizePolicy);
        actionLoad_config = new QAction(calibWindow);
        actionLoad_config->setObjectName(QStringLiteral("actionLoad_config"));
        actionSave_config = new QAction(calibWindow);
        actionSave_config->setObjectName(QStringLiteral("actionSave_config"));
        actionOpen = new QAction(calibWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionCalibrate = new QAction(calibWindow);
        actionCalibrate->setObjectName(QStringLiteral("actionCalibrate"));
        actionSolve_PnP = new QAction(calibWindow);
        actionSolve_PnP->setObjectName(QStringLiteral("actionSolve_PnP"));
        actionAbout = new QAction(calibWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionHelp = new QAction(calibWindow);
        actionHelp->setObjectName(QStringLiteral("actionHelp"));
        actionSave_Transformation_Function = new QAction(calibWindow);
        actionSave_Transformation_Function->setObjectName(QStringLiteral("actionSave_Transformation_Function"));
        centralwidget = new QWidget(calibWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        horizontalLayout = new QHBoxLayout(centralwidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        viewport = new CvGlCam(centralwidget);
        viewport->setObjectName(QStringLiteral("viewport"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(viewport->sizePolicy().hasHeightForWidth());
        viewport->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(viewport);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        timeKeeper = new QLCDNumber(centralwidget);
        timeKeeper->setObjectName(QStringLiteral("timeKeeper"));

        verticalLayout->addWidget(timeKeeper);

        progress = new QProgressBar(centralwidget);
        progress->setObjectName(QStringLiteral("progress"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(progress->sizePolicy().hasHeightForWidth());
        progress->setSizePolicy(sizePolicy2);
        progress->setMaximum(7);
        progress->setValue(-1);

        verticalLayout->addWidget(progress);

        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        review = new CvGlCam(centralwidget);
        review->setObjectName(QStringLiteral("review"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(review->sizePolicy().hasHeightForWidth());
        review->setSizePolicy(sizePolicy3);

        verticalLayout->addWidget(review);

        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        boardW = new QSpinBox(centralwidget);
        boardW->setObjectName(QStringLiteral("boardW"));
        boardW->setValue(8);

        verticalLayout->addWidget(boardW);

        boardH = new QSpinBox(centralwidget);
        boardH->setObjectName(QStringLiteral("boardH"));
        boardH->setValue(6);

        verticalLayout->addWidget(boardH);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        verticalLayout->addWidget(spinBox);


        horizontalLayout->addLayout(verticalLayout);

        calibWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(calibWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 790, 25));
        menuOpen_Camera = new QMenu(menubar);
        menuOpen_Camera->setObjectName(QStringLiteral("menuOpen_Camera"));
        menuCalibrate = new QMenu(menubar);
        menuCalibrate->setObjectName(QStringLiteral("menuCalibrate"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        calibWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(calibWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        calibWindow->setStatusBar(statusbar);

        menubar->addAction(menuOpen_Camera->menuAction());
        menubar->addAction(menuCalibrate->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuOpen_Camera->addAction(actionOpen);
        menuOpen_Camera->addSeparator();
        menuOpen_Camera->addAction(actionLoad_config);
        menuOpen_Camera->addAction(actionSave_config);
        menuCalibrate->addAction(actionCalibrate);
        menuCalibrate->addAction(actionSolve_PnP);
        menuCalibrate->addAction(actionSave_Transformation_Function);
        menuHelp->addAction(actionAbout);
        menuHelp->addAction(actionHelp);

        retranslateUi(calibWindow);

        QMetaObject::connectSlotsByName(calibWindow);
    } // setupUi

    void retranslateUi(QMainWindow *calibWindow)
    {
        calibWindow->setWindowTitle(QApplication::translate("calibWindow", "Camera calibration Wizard", 0));
        actionLoad_config->setText(QApplication::translate("calibWindow", "Load config", 0));
        actionSave_config->setText(QApplication::translate("calibWindow", "Save config", 0));
        actionOpen->setText(QApplication::translate("calibWindow", "Open Camera", 0));
        actionCalibrate->setText(QApplication::translate("calibWindow", "Calibrate", 0));
        actionSolve_PnP->setText(QApplication::translate("calibWindow", "Solve PnP", 0));
        actionAbout->setText(QApplication::translate("calibWindow", "About", 0));
        actionHelp->setText(QApplication::translate("calibWindow", "Help", 0));
        actionSave_Transformation_Function->setText(QApplication::translate("calibWindow", "Save Transformation Function", 0));
        pushButton->setText(QApplication::translate("calibWindow", "Calibrate", 0));
        pushButton_2->setText(QApplication::translate("calibWindow", "Show", 0));
        pushButton_3->setText(QApplication::translate("calibWindow", "Undistort", 0));
        label->setText(QApplication::translate("calibWindow", "Err :", 0));
        label_2->setText(QApplication::translate("calibWindow", "BoardSize", 0));
        label_3->setText(QApplication::translate("calibWindow", "Image Count", 0));
        menuOpen_Camera->setTitle(QApplication::translate("calibWindow", "Open ", 0));
        menuCalibrate->setTitle(QApplication::translate("calibWindow", "Operation", 0));
        menuHelp->setTitle(QApplication::translate("calibWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class calibWindow: public Ui_calibWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALIBWINDOW_H
