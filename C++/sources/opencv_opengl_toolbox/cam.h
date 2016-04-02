#ifndef CAM_H
#define CAM_H

#include <QDialog>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QThread>
#include <collage.h>
#include <vector>
#include <someclass.h>
#include <QMetaObject>
#include <QMetaMethod>
using namespace std;
namespace Ui {
class cam;
}

class cam : public QDialog
{
    Q_OBJECT

public:
    explicit cam(QWidget *parent = 0);
    ~cam();
    QThread *thread;
    cv::VideoCapture captureCam;    //video stream from camera0
    cv::Mat image;  //image to be processed
    int timerID50MS; //for updating cvglviewer
     collage *processing;
    bool CAMCAPTURED;
    int mode;
    void startCapture();
       void setMode(int a){

           mode = a;
           qDebug()<<"mode selection: " <<mode;
       }
    someClass *sm;
    protected:
     //1 = cam; 2= vid
    void timerEvent(QTimerEvent *event);

private:
    Ui::cam *ui;


signals:

};

#endif // CAM_H
