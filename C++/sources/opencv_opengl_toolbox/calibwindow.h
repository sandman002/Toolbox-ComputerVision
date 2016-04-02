#ifndef CALIBWINDOW_H
#define CALIBWINDOW_H

#include <QMainWindow>
#include "cvglcam.h"
#include "calibacam.h"

#include <QThread>
#include <QFileDialog>
#include <QKeyEvent>
#include <QTimer>
#include <QMouseEvent>
#include <iostream>
namespace Ui {
class calibWindow;
}

class calibWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit calibWindow(QWidget *parent = 0);
    ~calibWindow();


    QThread *thread;
    QTimer *search;
    double err;
        cv::VideoCapture captureCam;    //video stream from camera0
        cv::Mat image, reviewImg;  //image to be processed
        int timerID50MS; //for updating cvglviewer
        int totalFrame;
        cv::Mat cimage;
    int counterMsec;
    std::vector<cv::Point> selectedPts;
private slots:
    void on_actionOpen_triggered();
    //

    void on_actionCalibrate_triggered();
    void chessFinder();
    void timeOutSlot();

    void on_pushButton_clicked();



    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_actionHelp_triggered();

    void on_actionAbout_triggered();



    void on_actionSolve_PnP_triggered();

    void on_actionLoad_config_triggered();

    void on_actionSave_config_triggered();

    void on_actionSave_Transformation_Function_triggered();
void closeEvent(QCloseEvent *);
protected:
       void timerEvent(QTimerEvent *event);
       void keyPressEvent(QKeyEvent *e);

private:
    Ui::calibWindow *ui;
    CalibACam *calib1;
    void startCapture();

    static void onMouse(int event, int x, int y, int flags, void* param){
        calibWindow *self = static_cast<calibWindow*>(param);
        self->doMouse(event, x, y, flags);
    }
    void doMouse(int event, int x, int y, int flags){
        if(event == EVENT_LBUTTONDOWN)
        {
            cv::circle(reviewImg,Point(x,y), 3, Scalar(255,255,0));
            qDebug()<<x<<y;
            imshow("found Chessboard", reviewImg);
            selectedPts.push_back(Point(x,y));
        }
    }
};



#endif // CALIBWINDOW_H
