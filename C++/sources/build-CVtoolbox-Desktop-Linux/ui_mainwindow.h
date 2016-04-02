/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionGray;
    QAction *actionHistogram;
    QAction *actionHarris;
    QAction *actionMean;
    QAction *actionMedian;
    QAction *actionGaussian;
    QAction *actionCustom;
    QAction *actionOriginal;
    QAction *actionDilate;
    QAction *actionErode;
    QAction *actionOpening;
    QAction *actionClosing;
    QAction *actionGradient;
    QAction *actionTop_Hat;
    QAction *actionBlack_Hat;
    QAction *actionTune_parameters;
    QAction *actionMake_Border;
    QAction *actionSelect_Level;
    QAction *actionLocal_threshold;
    QAction *actionEqualize;
    QAction *actionOpen_Camera;
    QAction *actionCascade;
    QAction *actionTile;
    QAction *actionAdd;
    QAction *actionCalibrate;
    QAction *actionFundamental_Matrix;
    QAction *actionConsole;
    QAction *actionSalt_and_Pepper;
    QAction *actionGaussian_2;
    QAction *actionCanny_Edge;
    QAction *actionContours_only;
    QAction *actionSuper_Imposed;
    QAction *actionBounding_Box;
    QAction *actionRectangles;
    QAction *actionCircles;
    QAction *actionMoments;
    QAction *actionConvex_hull;
    QAction *actionMagnitude_map;
    QAction *actionOrientation_map;
    QAction *actionSobel_Image;
    QAction *actionLaplacian;
    QAction *actionOptions;
    QAction *actionHough_lines;
    QAction *actionHough_Circles;
    QAction *actionOptions_2;
    QAction *actionClose_All_Subwindows;
    QAction *actionCompute_Homography;
    QAction *actionFast;
    QAction *actionSURF;
    QAction *actionSIFT;
    QAction *actionMSER;
    QAction *actionOptions_3;
    QAction *actionSave;
    QAction *actionBrightness_Contrast;
    QAction *actionUpSample_2x;
    QAction *actionDownSample_1_2x;
    QAction *actionDetect_human_faces;
    QAction *actionGrayscale;
    QAction *actionYCbCr;
    QAction *actionHSV;
    QAction *actionLab;
    QAction *actionLuv;
    QAction *actionHLS;
    QAction *actionAbout;
    QAction *actionHough_PLines;
    QAction *actionExit;
    QAction *actionOpen_Motion_Picture;
    QAction *actionCrop;
    QAction *actionTransparency;
    QAction *actionWatermark_it;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QMdiArea *mdiArea;
    QVBoxLayout *verticalLayout;
    QTextEdit *command;
    QLineEdit *temp;
    QLabel *info;
    QMenuBar *menuBar;
    QMenu *menuOpen;
    QMenu *menuConvert;
    QMenu *menuThreshold;
    QMenu *menuColor_Space;
    QMenu *menuPlace_watermark;
    QMenu *menuWindows;
    QMenu *menuView;
    QMenu *menuFeatures;
    QMenu *menuFilters;
    QMenu *menuNoise_2;
    QMenu *menuMorphology;
    QMenu *menuCamera_Geometry;
    QMenu *menuContours;
    QMenu *menuBlobs;
    QMenu *menuSobel_Edges;
    QMenu *menuLearning;
    QMenu *menuHelp;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(848, 497);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionGray = new QAction(MainWindow);
        actionGray->setObjectName(QStringLiteral("actionGray"));
        actionHistogram = new QAction(MainWindow);
        actionHistogram->setObjectName(QStringLiteral("actionHistogram"));
        actionHistogram->setCheckable(true);
        actionHarris = new QAction(MainWindow);
        actionHarris->setObjectName(QStringLiteral("actionHarris"));
        actionMean = new QAction(MainWindow);
        actionMean->setObjectName(QStringLiteral("actionMean"));
        actionMedian = new QAction(MainWindow);
        actionMedian->setObjectName(QStringLiteral("actionMedian"));
        actionGaussian = new QAction(MainWindow);
        actionGaussian->setObjectName(QStringLiteral("actionGaussian"));
        actionCustom = new QAction(MainWindow);
        actionCustom->setObjectName(QStringLiteral("actionCustom"));
        actionOriginal = new QAction(MainWindow);
        actionOriginal->setObjectName(QStringLiteral("actionOriginal"));
        actionDilate = new QAction(MainWindow);
        actionDilate->setObjectName(QStringLiteral("actionDilate"));
        actionErode = new QAction(MainWindow);
        actionErode->setObjectName(QStringLiteral("actionErode"));
        actionOpening = new QAction(MainWindow);
        actionOpening->setObjectName(QStringLiteral("actionOpening"));
        actionClosing = new QAction(MainWindow);
        actionClosing->setObjectName(QStringLiteral("actionClosing"));
        actionGradient = new QAction(MainWindow);
        actionGradient->setObjectName(QStringLiteral("actionGradient"));
        actionTop_Hat = new QAction(MainWindow);
        actionTop_Hat->setObjectName(QStringLiteral("actionTop_Hat"));
        actionBlack_Hat = new QAction(MainWindow);
        actionBlack_Hat->setObjectName(QStringLiteral("actionBlack_Hat"));
        actionTune_parameters = new QAction(MainWindow);
        actionTune_parameters->setObjectName(QStringLiteral("actionTune_parameters"));
        actionMake_Border = new QAction(MainWindow);
        actionMake_Border->setObjectName(QStringLiteral("actionMake_Border"));
        actionSelect_Level = new QAction(MainWindow);
        actionSelect_Level->setObjectName(QStringLiteral("actionSelect_Level"));
        actionLocal_threshold = new QAction(MainWindow);
        actionLocal_threshold->setObjectName(QStringLiteral("actionLocal_threshold"));
        actionEqualize = new QAction(MainWindow);
        actionEqualize->setObjectName(QStringLiteral("actionEqualize"));
        actionOpen_Camera = new QAction(MainWindow);
        actionOpen_Camera->setObjectName(QStringLiteral("actionOpen_Camera"));
        actionCascade = new QAction(MainWindow);
        actionCascade->setObjectName(QStringLiteral("actionCascade"));
        actionTile = new QAction(MainWindow);
        actionTile->setObjectName(QStringLiteral("actionTile"));
        actionAdd = new QAction(MainWindow);
        actionAdd->setObjectName(QStringLiteral("actionAdd"));
        actionCalibrate = new QAction(MainWindow);
        actionCalibrate->setObjectName(QStringLiteral("actionCalibrate"));
        actionFundamental_Matrix = new QAction(MainWindow);
        actionFundamental_Matrix->setObjectName(QStringLiteral("actionFundamental_Matrix"));
        actionConsole = new QAction(MainWindow);
        actionConsole->setObjectName(QStringLiteral("actionConsole"));
        actionConsole->setCheckable(true);
        actionSalt_and_Pepper = new QAction(MainWindow);
        actionSalt_and_Pepper->setObjectName(QStringLiteral("actionSalt_and_Pepper"));
        actionGaussian_2 = new QAction(MainWindow);
        actionGaussian_2->setObjectName(QStringLiteral("actionGaussian_2"));
        actionCanny_Edge = new QAction(MainWindow);
        actionCanny_Edge->setObjectName(QStringLiteral("actionCanny_Edge"));
        actionContours_only = new QAction(MainWindow);
        actionContours_only->setObjectName(QStringLiteral("actionContours_only"));
        actionSuper_Imposed = new QAction(MainWindow);
        actionSuper_Imposed->setObjectName(QStringLiteral("actionSuper_Imposed"));
        actionBounding_Box = new QAction(MainWindow);
        actionBounding_Box->setObjectName(QStringLiteral("actionBounding_Box"));
        actionRectangles = new QAction(MainWindow);
        actionRectangles->setObjectName(QStringLiteral("actionRectangles"));
        actionCircles = new QAction(MainWindow);
        actionCircles->setObjectName(QStringLiteral("actionCircles"));
        actionMoments = new QAction(MainWindow);
        actionMoments->setObjectName(QStringLiteral("actionMoments"));
        actionConvex_hull = new QAction(MainWindow);
        actionConvex_hull->setObjectName(QStringLiteral("actionConvex_hull"));
        actionMagnitude_map = new QAction(MainWindow);
        actionMagnitude_map->setObjectName(QStringLiteral("actionMagnitude_map"));
        actionOrientation_map = new QAction(MainWindow);
        actionOrientation_map->setObjectName(QStringLiteral("actionOrientation_map"));
        actionSobel_Image = new QAction(MainWindow);
        actionSobel_Image->setObjectName(QStringLiteral("actionSobel_Image"));
        actionLaplacian = new QAction(MainWindow);
        actionLaplacian->setObjectName(QStringLiteral("actionLaplacian"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionHough_lines = new QAction(MainWindow);
        actionHough_lines->setObjectName(QStringLiteral("actionHough_lines"));
        actionHough_Circles = new QAction(MainWindow);
        actionHough_Circles->setObjectName(QStringLiteral("actionHough_Circles"));
        actionOptions_2 = new QAction(MainWindow);
        actionOptions_2->setObjectName(QStringLiteral("actionOptions_2"));
        actionClose_All_Subwindows = new QAction(MainWindow);
        actionClose_All_Subwindows->setObjectName(QStringLiteral("actionClose_All_Subwindows"));
        actionCompute_Homography = new QAction(MainWindow);
        actionCompute_Homography->setObjectName(QStringLiteral("actionCompute_Homography"));
        actionFast = new QAction(MainWindow);
        actionFast->setObjectName(QStringLiteral("actionFast"));
        actionSURF = new QAction(MainWindow);
        actionSURF->setObjectName(QStringLiteral("actionSURF"));
        actionSIFT = new QAction(MainWindow);
        actionSIFT->setObjectName(QStringLiteral("actionSIFT"));
        actionMSER = new QAction(MainWindow);
        actionMSER->setObjectName(QStringLiteral("actionMSER"));
        actionOptions_3 = new QAction(MainWindow);
        actionOptions_3->setObjectName(QStringLiteral("actionOptions_3"));
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionBrightness_Contrast = new QAction(MainWindow);
        actionBrightness_Contrast->setObjectName(QStringLiteral("actionBrightness_Contrast"));
        actionUpSample_2x = new QAction(MainWindow);
        actionUpSample_2x->setObjectName(QStringLiteral("actionUpSample_2x"));
        actionDownSample_1_2x = new QAction(MainWindow);
        actionDownSample_1_2x->setObjectName(QStringLiteral("actionDownSample_1_2x"));
        actionDetect_human_faces = new QAction(MainWindow);
        actionDetect_human_faces->setObjectName(QStringLiteral("actionDetect_human_faces"));
        actionGrayscale = new QAction(MainWindow);
        actionGrayscale->setObjectName(QStringLiteral("actionGrayscale"));
        actionYCbCr = new QAction(MainWindow);
        actionYCbCr->setObjectName(QStringLiteral("actionYCbCr"));
        actionHSV = new QAction(MainWindow);
        actionHSV->setObjectName(QStringLiteral("actionHSV"));
        actionLab = new QAction(MainWindow);
        actionLab->setObjectName(QStringLiteral("actionLab"));
        actionLuv = new QAction(MainWindow);
        actionLuv->setObjectName(QStringLiteral("actionLuv"));
        actionHLS = new QAction(MainWindow);
        actionHLS->setObjectName(QStringLiteral("actionHLS"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionHough_PLines = new QAction(MainWindow);
        actionHough_PLines->setObjectName(QStringLiteral("actionHough_PLines"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        actionOpen_Motion_Picture = new QAction(MainWindow);
        actionOpen_Motion_Picture->setObjectName(QStringLiteral("actionOpen_Motion_Picture"));
        actionCrop = new QAction(MainWindow);
        actionCrop->setObjectName(QStringLiteral("actionCrop"));
        actionTransparency = new QAction(MainWindow);
        actionTransparency->setObjectName(QStringLiteral("actionTransparency"));
        actionWatermark_it = new QAction(MainWindow);
        actionWatermark_it->setObjectName(QStringLiteral("actionWatermark_it"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        mdiArea = new QMdiArea(centralWidget);
        mdiArea->setObjectName(QStringLiteral("mdiArea"));
        QBrush brush(QColor(234, 230, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        mdiArea->setBackground(brush);

        gridLayout->addWidget(mdiArea, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        command = new QTextEdit(centralWidget);
        command->setObjectName(QStringLiteral("command"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(command->sizePolicy().hasHeightForWidth());
        command->setSizePolicy(sizePolicy);
        command->setReadOnly(true);

        verticalLayout->addWidget(command);

        temp = new QLineEdit(centralWidget);
        temp->setObjectName(QStringLiteral("temp"));

        verticalLayout->addWidget(temp);


        gridLayout->addLayout(verticalLayout, 0, 1, 1, 1);

        info = new QLabel(centralWidget);
        info->setObjectName(QStringLiteral("info"));

        gridLayout->addWidget(info, 1, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 848, 25));
        menuOpen = new QMenu(menuBar);
        menuOpen->setObjectName(QStringLiteral("menuOpen"));
        menuConvert = new QMenu(menuBar);
        menuConvert->setObjectName(QStringLiteral("menuConvert"));
        menuThreshold = new QMenu(menuConvert);
        menuThreshold->setObjectName(QStringLiteral("menuThreshold"));
        menuColor_Space = new QMenu(menuConvert);
        menuColor_Space->setObjectName(QStringLiteral("menuColor_Space"));
        menuPlace_watermark = new QMenu(menuConvert);
        menuPlace_watermark->setObjectName(QStringLiteral("menuPlace_watermark"));
        menuWindows = new QMenu(menuBar);
        menuWindows->setObjectName(QStringLiteral("menuWindows"));
        menuView = new QMenu(menuWindows);
        menuView->setObjectName(QStringLiteral("menuView"));
        menuFeatures = new QMenu(menuBar);
        menuFeatures->setObjectName(QStringLiteral("menuFeatures"));
        menuFilters = new QMenu(menuBar);
        menuFilters->setObjectName(QStringLiteral("menuFilters"));
        menuNoise_2 = new QMenu(menuFilters);
        menuNoise_2->setObjectName(QStringLiteral("menuNoise_2"));
        menuMorphology = new QMenu(menuBar);
        menuMorphology->setObjectName(QStringLiteral("menuMorphology"));
        menuCamera_Geometry = new QMenu(menuBar);
        menuCamera_Geometry->setObjectName(QStringLiteral("menuCamera_Geometry"));
        menuContours = new QMenu(menuBar);
        menuContours->setObjectName(QStringLiteral("menuContours"));
        menuBlobs = new QMenu(menuContours);
        menuBlobs->setObjectName(QStringLiteral("menuBlobs"));
        menuSobel_Edges = new QMenu(menuContours);
        menuSobel_Edges->setObjectName(QStringLiteral("menuSobel_Edges"));
        menuLearning = new QMenu(menuBar);
        menuLearning->setObjectName(QStringLiteral("menuLearning"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuOpen->menuAction());
        menuBar->addAction(menuConvert->menuAction());
        menuBar->addAction(menuFilters->menuAction());
        menuBar->addAction(menuContours->menuAction());
        menuBar->addAction(menuMorphology->menuAction());
        menuBar->addAction(menuFeatures->menuAction());
        menuBar->addAction(menuCamera_Geometry->menuAction());
        menuBar->addAction(menuWindows->menuAction());
        menuBar->addAction(menuLearning->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuOpen->addAction(actionOpen);
        menuOpen->addAction(actionOpen_Camera);
        menuOpen->addAction(actionOpen_Motion_Picture);
        menuOpen->addSeparator();
        menuOpen->addAction(actionSave);
        menuOpen->addAction(actionExit);
        menuConvert->addAction(menuColor_Space->menuAction());
        menuConvert->addSeparator();
        menuConvert->addAction(actionBrightness_Contrast);
        menuConvert->addAction(actionMake_Border);
        menuConvert->addAction(menuThreshold->menuAction());
        menuConvert->addAction(actionEqualize);
        menuConvert->addSeparator();
        menuConvert->addAction(actionCrop);
        menuConvert->addAction(menuPlace_watermark->menuAction());
        menuConvert->addAction(actionAdd);
        menuConvert->addAction(actionUpSample_2x);
        menuConvert->addAction(actionDownSample_1_2x);
        menuThreshold->addAction(actionSelect_Level);
        menuThreshold->addSeparator();
        menuThreshold->addAction(actionLocal_threshold);
        menuColor_Space->addAction(actionGrayscale);
        menuColor_Space->addAction(actionHSV);
        menuColor_Space->addAction(actionYCbCr);
        menuColor_Space->addAction(actionLab);
        menuColor_Space->addAction(actionLuv);
        menuColor_Space->addAction(actionHLS);
        menuPlace_watermark->addAction(actionTransparency);
        menuPlace_watermark->addAction(actionWatermark_it);
        menuWindows->addAction(actionOriginal);
        menuWindows->addSeparator();
        menuWindows->addAction(actionHistogram);
        menuWindows->addAction(menuView->menuAction());
        menuWindows->addSeparator();
        menuWindows->addAction(actionConsole);
        menuWindows->addAction(actionClose_All_Subwindows);
        menuView->addAction(actionCascade);
        menuView->addAction(actionTile);
        menuFeatures->addAction(actionHarris);
        menuFeatures->addAction(actionFast);
        menuFeatures->addAction(actionSURF);
        menuFeatures->addAction(actionSIFT);
        menuFeatures->addAction(actionMSER);
        menuFeatures->addSeparator();
        menuFeatures->addAction(actionOptions_3);
        menuFilters->addAction(actionMean);
        menuFilters->addAction(actionMedian);
        menuFilters->addAction(actionGaussian);
        menuFilters->addSeparator();
        menuFilters->addAction(actionCustom);
        menuFilters->addAction(menuNoise_2->menuAction());
        menuNoise_2->addAction(actionSalt_and_Pepper);
        menuNoise_2->addAction(actionGaussian_2);
        menuMorphology->addAction(actionDilate);
        menuMorphology->addAction(actionErode);
        menuMorphology->addSeparator();
        menuMorphology->addAction(actionOpening);
        menuMorphology->addAction(actionClosing);
        menuMorphology->addAction(actionGradient);
        menuMorphology->addAction(actionTop_Hat);
        menuMorphology->addAction(actionBlack_Hat);
        menuMorphology->addSeparator();
        menuMorphology->addAction(actionTune_parameters);
        menuCamera_Geometry->addAction(actionCalibrate);
        menuCamera_Geometry->addAction(actionFundamental_Matrix);
        menuCamera_Geometry->addAction(actionCompute_Homography);
        menuCamera_Geometry->addAction(actionOptions_2);
        menuContours->addAction(actionCanny_Edge);
        menuContours->addAction(menuBlobs->menuAction());
        menuContours->addAction(menuSobel_Edges->menuAction());
        menuContours->addAction(actionLaplacian);
        menuContours->addAction(actionHough_Circles);
        menuContours->addAction(actionHough_PLines);
        menuContours->addAction(actionHough_lines);
        menuContours->addSeparator();
        menuContours->addAction(actionOptions);
        menuBlobs->addAction(actionContours_only);
        menuBlobs->addAction(actionSuper_Imposed);
        menuBlobs->addAction(actionBounding_Box);
        menuBlobs->addAction(actionRectangles);
        menuBlobs->addAction(actionCircles);
        menuBlobs->addAction(actionMoments);
        menuBlobs->addAction(actionConvex_hull);
        menuSobel_Edges->addAction(actionMagnitude_map);
        menuSobel_Edges->addAction(actionOrientation_map);
        menuSobel_Edges->addAction(actionSobel_Image);
        menuLearning->addAction(actionDetect_human_faces);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionOpen->setText(QApplication::translate("MainWindow", "Open Image", 0));
        actionGray->setText(QApplication::translate("MainWindow", "Grayscale", 0));
        actionHistogram->setText(QApplication::translate("MainWindow", "Histogram", 0));
        actionHarris->setText(QApplication::translate("MainWindow", "Harris Corners", 0));
        actionMean->setText(QApplication::translate("MainWindow", "Blur", 0));
        actionMedian->setText(QApplication::translate("MainWindow", "Median", 0));
        actionGaussian->setText(QApplication::translate("MainWindow", "Gaussian", 0));
        actionCustom->setText(QApplication::translate("MainWindow", "Custom..", 0));
        actionOriginal->setText(QApplication::translate("MainWindow", "Original", 0));
        actionDilate->setText(QApplication::translate("MainWindow", "Dilate", 0));
        actionErode->setText(QApplication::translate("MainWindow", "Erode", 0));
        actionOpening->setText(QApplication::translate("MainWindow", "Opening", 0));
        actionClosing->setText(QApplication::translate("MainWindow", "Closing", 0));
        actionGradient->setText(QApplication::translate("MainWindow", "Gradient", 0));
        actionTop_Hat->setText(QApplication::translate("MainWindow", "Top Hat", 0));
        actionBlack_Hat->setText(QApplication::translate("MainWindow", "Black Hat", 0));
        actionTune_parameters->setText(QApplication::translate("MainWindow", "Options..", 0));
        actionMake_Border->setText(QApplication::translate("MainWindow", "Make Border", 0));
        actionSelect_Level->setText(QApplication::translate("MainWindow", "Select Level..", 0));
        actionLocal_threshold->setText(QApplication::translate("MainWindow", "Local threshold", 0));
        actionEqualize->setText(QApplication::translate("MainWindow", "Equalize", 0));
        actionOpen_Camera->setText(QApplication::translate("MainWindow", "Open Camera", 0));
        actionCascade->setText(QApplication::translate("MainWindow", "Cascade", 0));
        actionTile->setText(QApplication::translate("MainWindow", "Tile", 0));
        actionAdd->setText(QApplication::translate("MainWindow", "Add", 0));
        actionCalibrate->setText(QApplication::translate("MainWindow", "Calibrate", 0));
        actionFundamental_Matrix->setText(QApplication::translate("MainWindow", "Fundamental Matrix", 0));
        actionConsole->setText(QApplication::translate("MainWindow", "Console", 0));
        actionSalt_and_Pepper->setText(QApplication::translate("MainWindow", "Salt and Pepper", 0));
        actionGaussian_2->setText(QApplication::translate("MainWindow", "Gaussian", 0));
        actionCanny_Edge->setText(QApplication::translate("MainWindow", "Canny Edge", 0));
        actionContours_only->setText(QApplication::translate("MainWindow", "Contours only", 0));
        actionSuper_Imposed->setText(QApplication::translate("MainWindow", "Overlayed", 0));
        actionBounding_Box->setText(QApplication::translate("MainWindow", "Bounding Box", 0));
        actionRectangles->setText(QApplication::translate("MainWindow", "Polygonal", 0));
        actionCircles->setText(QApplication::translate("MainWindow", "Circles", 0));
        actionMoments->setText(QApplication::translate("MainWindow", "Moments", 0));
        actionConvex_hull->setText(QApplication::translate("MainWindow", "Convex hull", 0));
        actionMagnitude_map->setText(QApplication::translate("MainWindow", "Magnitude map", 0));
        actionOrientation_map->setText(QApplication::translate("MainWindow", "Orientation map", 0));
        actionSobel_Image->setText(QApplication::translate("MainWindow", "Sobel Image", 0));
        actionLaplacian->setText(QApplication::translate("MainWindow", "Laplacian", 0));
        actionOptions->setText(QApplication::translate("MainWindow", "Options..", 0));
        actionHough_lines->setText(QApplication::translate("MainWindow", "Hough Lines", 0));
        actionHough_Circles->setText(QApplication::translate("MainWindow", "Hough Circles", 0));
        actionOptions_2->setText(QApplication::translate("MainWindow", "Options", 0));
        actionClose_All_Subwindows->setText(QApplication::translate("MainWindow", "Close All Subwindows", 0));
        actionCompute_Homography->setText(QApplication::translate("MainWindow", "Compute Homography", 0));
        actionFast->setText(QApplication::translate("MainWindow", "Fast", 0));
        actionSURF->setText(QApplication::translate("MainWindow", "SURF(NON FREE)", 0));
        actionSIFT->setText(QApplication::translate("MainWindow", "SIFT", 0));
        actionMSER->setText(QApplication::translate("MainWindow", "MSER", 0));
        actionOptions_3->setText(QApplication::translate("MainWindow", "Options..", 0));
        actionSave->setText(QApplication::translate("MainWindow", "Save Image", 0));
        actionBrightness_Contrast->setText(QApplication::translate("MainWindow", "Brightness & Contrast", 0));
        actionUpSample_2x->setText(QApplication::translate("MainWindow", "UpSample (2x)", 0));
        actionDownSample_1_2x->setText(QApplication::translate("MainWindow", "DownSample(1/2x)", 0));
        actionDetect_human_faces->setText(QApplication::translate("MainWindow", "Detect human faces", 0));
        actionGrayscale->setText(QApplication::translate("MainWindow", "Grayscale", 0));
        actionYCbCr->setText(QApplication::translate("MainWindow", "YCbCr", 0));
        actionHSV->setText(QApplication::translate("MainWindow", "HSV", 0));
        actionLab->setText(QApplication::translate("MainWindow", "Lab", 0));
        actionLuv->setText(QApplication::translate("MainWindow", "Luv", 0));
        actionHLS->setText(QApplication::translate("MainWindow", "HLS", 0));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0));
        actionHough_PLines->setText(QApplication::translate("MainWindow", "Hough PLines", 0));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0));
        actionOpen_Motion_Picture->setText(QApplication::translate("MainWindow", "Open Motion Picture", 0));
        actionCrop->setText(QApplication::translate("MainWindow", "Crop", 0));
        actionTransparency->setText(QApplication::translate("MainWindow", "Transparency...", 0));
        actionWatermark_it->setText(QApplication::translate("MainWindow", "watermark it!!", 0));
        info->setText(QString());
        menuOpen->setTitle(QApplication::translate("MainWindow", "File", 0));
        menuConvert->setTitle(QApplication::translate("MainWindow", "Image", 0));
        menuThreshold->setTitle(QApplication::translate("MainWindow", "Threshold", 0));
        menuColor_Space->setTitle(QApplication::translate("MainWindow", "Color Space", 0));
        menuPlace_watermark->setTitle(QApplication::translate("MainWindow", "Place watermark", 0));
        menuWindows->setTitle(QApplication::translate("MainWindow", "Windows", 0));
        menuView->setTitle(QApplication::translate("MainWindow", "View", 0));
        menuFeatures->setTitle(QApplication::translate("MainWindow", "Features", 0));
        menuFilters->setTitle(QApplication::translate("MainWindow", "Filters", 0));
        menuNoise_2->setTitle(QApplication::translate("MainWindow", "Add Noise", 0));
        menuMorphology->setTitle(QApplication::translate("MainWindow", "Morphology", 0));
        menuCamera_Geometry->setTitle(QApplication::translate("MainWindow", "Camera Geometry", 0));
        menuContours->setTitle(QApplication::translate("MainWindow", "Contours", 0));
        menuBlobs->setTitle(QApplication::translate("MainWindow", "blobs", 0));
        menuSobel_Edges->setTitle(QApplication::translate("MainWindow", "Sobel Edges", 0));
        menuLearning->setTitle(QApplication::translate("MainWindow", "Learning", 0));
        menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
