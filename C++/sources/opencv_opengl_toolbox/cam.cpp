#include "cam.h"
#include "ui_cam.h"
#include <QDebug>
#include <QFileDialog>
cam::cam(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::cam)
{
    setAttribute(Qt::WA_DeleteOnClose);
    ui->setupUi(this);
    thread = new QThread();
    sm = new someClass(this);
    processing = new collage(this);

}

cam::~cam()
{
    captureCam.release();
    ui->rView->abortWork();
    thread->wait();
    delete thread;
    delete ui->rView;
    delete ui;
}

void cam::timerEvent(QTimerEvent *event)
{
    captureCam >> image;

    ui->rView->setImage(image);

    ui->rView->workRequested();
    image.copyTo(sm->inIm);

    //to run only when offline video frames are available
    for(int i = 0; i < sm->commandList.size(); i++){
        if(mode == 2){
            if(captureCam.get(CV_CAP_PROP_POS_FRAMES) == captureCam.get(CV_CAP_PROP_FRAME_COUNT))
                break;
        }
        QMetaMethod method = sm->metaObject()->method(sm->commandList.at(i));
        method.invoke(sm);
    }
    if(mode == 2){
        ui->progress->setValue(captureCam.get(CV_CAP_PROP_POS_FRAMES));
        if(captureCam.get(CV_CAP_PROP_POS_FRAMES) == captureCam.get(CV_CAP_PROP_FRAME_COUNT)){
            captureCam.set(CV_CAP_PROP_POS_FRAMES, 0);
        }
    }

    ui->lView->setImage(sm->inIm);
    ui->lView->showImage();
    //processing->morph(1);
    /********************************************************
         * all the video operation goes here
         * requires flags
         * ******************************************************/

    //else if(some flag here) //do some thing

}

void cam::startCapture()
{
    qDebug()<<"now trying";
    if(mode == 1){
        qDebug()<<"camera trial";
        if(!captureCam.isOpened())
            if(!captureCam.open(0)){ //put d here
                captureCam.release();
                return;
            }
        ui->progress->setHidden(true);
    }
    else if(mode == 2){
        qDebug()<<"avi trial";
        QString videoName = QFileDialog::getOpenFileName(this,
                                                         tr("Open Video file"), "../videos", tr("AVI video (*.avi);;"));
        captureCam.open(videoName.toStdString().c_str());
        if(!captureCam.isOpened()){
            //cannot run
            return;
        }

        double fCount = captureCam.get(CV_CAP_PROP_FRAME_COUNT);
        ui->progress->setMaximum(fCount);
        ui->progress->setValue(0);

        ui->progress->setHidden(false);

    }

    double fps = captureCam.get(CV_CAP_PROP_FPS);
    double fwidth = captureCam.get(CV_CAP_PROP_FRAME_WIDTH);
    double fheight = captureCam.get(CV_CAP_PROP_FRAME_HEIGHT);
    ui->info->setText("RESOLUTION: "+QString::number(fwidth) + "x"+ QString::number(fheight));
    ui->rView->moveToThread(thread);
    connect(ui->rView, SIGNAL(workRequested()), thread, SLOT(start()));
    connect(thread, SIGNAL(started()), ui->rView, SLOT(showImage()));
    connect(ui->rView, SIGNAL(finished()), thread, SLOT(quit()), Qt::DirectConnection);
    timerID50MS = startTimer(50); //creates timer event in every 50 ms
    CAMCAPTURED = true;
}
