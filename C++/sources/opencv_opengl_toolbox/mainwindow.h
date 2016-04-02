#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <CvGlWidget.h>
#include "explorerhisto.h"
#include <QMdiSubWindow>
#include <harriscorner.h>
#include <customkernel.h>
#include <kernel2d.h>
#include <morphprocess.h>
#include <custommorph.h>
#include <thresholdui.h>
#include <contoursui.h>
#include <someclass.h>
#include <cvglcam.h>
#include <cam.h>
#include <collage.h>
#include <matcher.h>
#include "calibwindow.h"
#include "fundoptui.h"
#include <featuresui.h>
#include <brightcontrastui.h>
#include "functionSet.cpp"
#define WARNING -1
#define CMD 0
#define RESULT 1

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool showHistogram;
    bool showConsole;
private slots:
    void on_actionOpen_triggered();

    void on_actionGray_triggered();

    void on_actionHistogram_triggered();

    void on_actionBinary_triggered();

    void subwindowChanged(QMdiSubWindow *);

    void on_actionHarris_triggered();

    void on_actionCustom_triggered();

    void on_actionMean_triggered();

    void applyCustomFilter(cv::Mat);

    void on_actionOriginal_triggered();

    void on_actionDilate_triggered();

    void on_actionErode_triggered();

    void on_actionOpening_triggered();

    void on_actionBlack_Hat_triggered();

    void on_actionClosing_triggered();

    void on_actionGradient_triggered();

    void on_actionTop_Hat_triggered();

    void on_actionTune_parameters_triggered();

    void on_actionMake_Border_triggered();

    void on_actionLocal_threshold_triggered();

    void on_actionSelect_Level_triggered();

    void on_actionEqualize_triggered();

    void on_temp_returnPressed();

    void on_actionOpen_Camera_triggered();



    void on_actionCascade_triggered();

    void on_actionTile_triggered();

    void on_actionAdd_triggered();

    void on_actionFundamental_Matrix_triggered();

    void on_actionConsole_triggered();

     void print(QString, int );

     void on_actionSalt_and_Pepper_triggered();

     void on_actionGaussian_2_triggered();

     void on_actionCanny_Edge_triggered();

     void on_actionBlobs_triggered();

     void on_actionContours_only_triggered();

     void on_actionSuper_Imposed_triggered();

     void on_actionBounding_Box_triggered();

     void on_actionRectangles_triggered();

     void on_actionCircles_triggered();

     void on_actionMoments_triggered();

     void on_actionConvex_hull_triggered();

     void on_actionMagnitude_map_triggered();

     void on_actionOrientation_map_triggered();

     void on_actionSobel_Image_triggered();

     void on_actionLaplacian_triggered();

     void on_actionOptions_triggered();

     void on_actionHough_lines_triggered();

     void on_actionHough_Circles_triggered();

     void on_actionCalibrate_triggered();

     void on_actionOptions_2_triggered();

     void fundaPoints(int fundaSeq = 1, int option = 1);

     void on_actionClose_All_Subwindows_triggered();

     void on_actionCompute_Homography_triggered();

     void on_actionFast_triggered();

     void on_actionSURF_triggered();

     void on_actionSIFT_triggered();

     void on_actionMSER_triggered();

     void on_actionOptions_3_triggered();

     void uiFeatureConnect();
      void uiContourConnect();
     void on_actionROI_triggered();

     void on_actionSave_triggered();
        void closeEvent(QCloseEvent *);

        void on_actionBrightness_Contrast_triggered();
void BC(double,int);
void on_actionUpSample_2x_triggered();

void on_actionDownSample_1_2x_triggered();
void keyPressEvent(QKeyEvent *);
void on_actionDetect_human_faces_triggered();

void on_actionMedian_triggered();

void on_actionGrayscale_triggered();

void on_actionYCbCr_triggered();



void on_actionHSV_triggered();

void on_actionLab_triggered();

void on_actionLuv_triggered();

void on_actionHLS_triggered();

void on_actionAbout_triggered();

void on_actionHough_PLines_triggered();

void on_actionExit_triggered();

void on_actionOpen_Motion_Picture_triggered();

void on_actionCrop_triggered();

void on_actionWatermark_it_triggered();

void on_actionTransparency_triggered();
void setAlpha(int a){
    alpha = (double)a/100.0;
}

private:
    /***********ui's and windows***********/
    Ui::MainWindow *ui;
    CvGlWidget *cvWindow;
    ExplorerHisto *histogramWindow;
    customMorph *morphUI;
    customKernel *kernelUI;
    thresholdUI *threshUI;
    contoursUI *contourParam;
    calibWindow *calibUI;
    fundOptUI *methodBox;
    featuresUI *featUI;
    brightContrastUI *brightContrastAdjust;
    /***********cvProcesses***********/
    HarrisCorner *hCorner;
    someClass *sm;
    morphProcess *morpher;
    RobustMatcher *rmatcher;
    cam *camui;
    /**********variables*************/
    cv::Mat kernel;
    kernel2D k2D;
    collage *processing;
    int fundaMethod;
    double ransacConf, ransacDist, ransacNN;
    double alpha;
    /**********fucntions*************/
    CvGlWidget *activeMdiChild();
    cam *activeCam();
    void makeHistogram();
    void applyFilter(int i);
    void addImage();
    bool findSubWin(QWidget *);
    void computeHomography(int option = 1);


signals:
    void morphing(int i);

    
};

#endif // MAINWINDOW_H
