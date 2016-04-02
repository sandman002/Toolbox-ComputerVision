#include "calibwindow.h"
#include "ui_calibwindow.h"
#include <QMessageBox>
#include <iostream>
#include "misc.cpp"
calibWindow::calibWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::calibWindow)
{
    ui->setupUi(this);
    thread = new QThread();
    search = new QTimer();
    ui->viewport->moveToThread(thread);
    connect(ui->viewport, SIGNAL(workRequested()), thread, SLOT(start()));
    connect(thread, SIGNAL(started()), ui->viewport, SLOT(showImage()));
    connect(ui->viewport, SIGNAL(finished()), thread, SLOT(quit()), Qt::DirectConnection);
    calib1 = new CalibACam();
    connect(search, SIGNAL(timeout()), this, SLOT(timeOutSlot()));
    ui->pushButton->setDisabled(true);
    counterMsec = 0;
    err = 0;
    totalFrame = 8;
    ui->progress->setMaximum(totalFrame);
}

calibWindow::~calibWindow()
{
    delete ui;
}

void calibWindow::on_actionOpen_triggered()
{
    startCapture();
    ui->pushButton->setDisabled(true);
}

void calibWindow::timerEvent(QTimerEvent *event)
{

        captureCam >> image;

        ui->viewport->setImage(image);

        ui->viewport->workRequested();

}

void calibWindow::keyPressEvent(QKeyEvent *e)
{
    if(e->key() == Qt::Key_T){
        if(!captureCam.isOpened()) return;
        if(search->isActive()) search->stop();
        else search->start(1000);
    }
    else  if(e->key() == Qt::Key_P){
        if(!captureCam.isOpened()) return;
        cv::Mat saveImg; image.copyTo(saveImg);
        imshow("printed", saveImg);
        //     cvtColor(saveImg, saveImg, CV_BGR2GRAY);
        QString saveName = getRandomString();
        vector<int> compression_params;
        compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
        compression_params.push_back(98);
        if(cv::imwrite("//home/iron/CamCalib/saveName.jpg", saveImg, compression_params))
            qDebug()<<"saved..";
    }
}
void calibWindow::startCapture()
{
    if(!captureCam.isOpened())
        if(!captureCam.open(0)) //put d here
            return;

    captureCam.set(CV_CAP_PROP_FRAME_WIDTH,640);
    captureCam.set(CV_CAP_PROP_FRAME_HEIGHT,480);
    timerID50MS = startTimer(50); //creates timer event in every 50 ms

}

void calibWindow::on_actionCalibrate_triggered()
{
    if(!captureCam.isOpened()) return;
    if(search->isActive()) search->stop();
    else search->start(1000);
}

void calibWindow::chessFinder()
{
    Size sz =Size(ui->boardW->value(),ui->boardH->value());
    if(calib1->findChessboard(image, sz)){
        calib1->chessImage.copyTo(reviewImg);
        ui->review->setImage(reviewImg);
        ui->review->showImage();
        int count = ui->progress->value();
        ui->progress->setValue(++count);
        qDebug()<<count;
    }
    if(ui->progress->value() == totalFrame){
        search->stop();
        ui->pushButton->setDisabled(false);
    }

     ui->viewport->setImage(calib1->chessImage);
}

void calibWindow::timeOutSlot()
{
    counterMsec++;
    ui->timeKeeper->display(counterMsec);
    if(counterMsec == 3){
        chessFinder();
        counterMsec = 0;
    }
}

void calibWindow::on_pushButton_clicked()
{
    err = calib1->calibrate();
    ui->label->setText(QString("Err:")+QString::number(err));
}

void calibWindow::on_pushButton_2_clicked()
{
    namedWindow("found Chessboard");

    setMouseCallback( "found Chessboard", onMouse, this );
    imshow("found Chessboard", reviewImg);
}

void calibWindow::on_pushButton_3_clicked()
{
    Mat undImg;
    calib1->remap(image, undImg);
}
void calibWindow::on_actionHelp_triggered()
{
     int i = QMessageBox::information(this, tr("HELP"), tr("Open Camera from file menu\nPress key 'T' to start or pause calibration"));
}

void calibWindow::on_actionAbout_triggered()
{
        int i = QMessageBox::information(this, tr("info"), tr("manandhar.sandeep@gmail.com\nUniversity of Burgundy, France"));
}





void calibWindow::on_actionSolve_PnP_triggered()
{
    vector<Point2f> imageCorners;
    vector<Point3f> objectCorners;
    Mat rotationVecs(3, 1, cv::DataType<double>::type);
    Mat translationVecs(3, 1, cv::DataType<double>::type);
    Size boardSz = Size(ui->boardW->value(),ui->boardH->value());
    int squareLength = 3.0;
    for(int i = 0; i<boardSz.height;i++){
        for(int j = 0; j < boardSz.width; j++){
            objectCorners.push_back(Point3f(float(i)*squareLength,
                                            float(j)*squareLength, 0.0f));
        }
    }

    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open param file"), "..//vrml", tr("jpg (*.jpg);;All files(*.*)"));
    if(filename.isEmpty()) return;
    if(!selectedPts.empty()) selectedPts.clear();
    cimage = imread(filename.toStdString().c_str());
    cimage.copyTo(ui->review->original);
    bool found = false;
    found = findChessboardCorners(cimage, boardSz, imageCorners);
    if(found){
        Mat gray;
        cvtColor(cimage, gray, CV_BGR2GRAY);
        cornerSubPix(gray, imageCorners, Size(5,5), Size( -1, -1 ),
                     TermCriteria( CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 20, 0.03 ));
    }

    drawChessboardCorners(cimage, boardSz, imageCorners, found);
    if(captureCam.isOpened()) captureCam.release();
    ui->review->setImage(cimage);
    ui->review->showImage();
    if(imageCorners.size() == objectCorners.size()){
        solvePnP(objectCorners, imageCorners, calib1->cameraMatrix, calib1->distCoeffs, rotationVecs, translationVecs);
        std::cout<<"Rotation Vector ="<<endl<<rotationVecs<<endl;
        std::cout<<"Translation Vector="<<endl<<translationVecs<<endl;

        Mat R;
        Rodrigues(rotationVecs, R); //from rodrigues vector to 3x3 rotation matrix
        R = R.t(); //inverse of R
        translationVecs = -R*translationVecs; // inverse of translationVecs
        cv::Mat T(4, 4, R.type());
        T(cv::Range(0, 3), cv::Range(0, 3)) = R*1;
        T(cv::Range(0, 3), cv::Range(3,4)) = translationVecs*1;    double *p = T.ptr<double>(3);
        p[0] = p[1] = p[2] = 0; p[3] = 1;
        std::cout<<"Transformation function: "<<endl<<T<<endl;

        QString filename = QFileDialog::getSaveFileName(this, "Save Parameters", "", ".xml");
        FileStorage fs(filename.toStdString().c_str(), FileStorage::WRITE);
        fs<<"Rotation"<<R;
        fs<<"Transformation"<<T;
        fs.release();
    }
}

void calibWindow::on_actionLoad_config_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open param file"), "..//vrml", tr("Yaml (*.yaml);;All files(*.*)"));

    if(filename.isEmpty()) return;
    FileStorage param(filename.toStdString().c_str(), FileStorage::READ);
    FileNode dist = param["distortion Coefficients"];
    FileNode cam = param["camera Matrix"];
    Mat cameraMat;
    Mat distCoef;
    read(dist, distCoef);
    read(cam, cameraMat);
    param.release();
    calib1->distCoeffs = distCoef;
    calib1->cameraMatrix = cameraMat;
}


void calibWindow::on_actionSave_config_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Save Parameters", "", ".xml");
    FileStorage fs(filename.toStdString().c_str(), FileStorage::WRITE);
    fs<<"total Frames"<<totalFrame;
    fs<<"distortion Coefficients"<<calib1->distCoeffs;
    fs<<"camera Matrix"<<calib1->cameraMatrix;
    fs<<"Translation Vector"<<calib1->translationVecs;
    fs<<"Rotation Vector"<<calib1->rotationVecs;
    fs.release();
}



void calibWindow::on_actionSave_Transformation_Function_triggered()
{

}

void calibWindow::closeEvent(QCloseEvent *)
{
        captureCam.release();
}
