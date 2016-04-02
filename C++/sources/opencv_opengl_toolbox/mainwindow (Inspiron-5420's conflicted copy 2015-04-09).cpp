#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include <QMetaObject>
#include <QMetaMethod>
#include <iostream>
#include <QSlider>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->mdiArea->setLayoutDirection(Qt::LeftToRight);
    ui->mdiArea->setAttribute(Qt::WA_DeleteOnClose);
    //    ui->mdiArea->setBackground(*new QBrush(*new QPixmap(":/background/images/back1")));
    histogramWindow = new ExplorerHisto;
    hCorner = new HarrisCorner;
    morphUI = new customMorph(this);
    morpher = new morphProcess;
    threshUI = new thresholdUI(this);
    calibUI = new calibWindow(this);
    showHistogram = false;
    sm = new someClass(this);
    contourParam = new contoursUI(this);
    showConsole = true;
    ui->command->setVisible(!showConsole);
    ui->temp->setVisible(!showConsole);

    connect(ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(subwindowChanged(QMdiSubWindow*)));
    ui->command->setText("<<<<<Welcome to Manandhar's Computer Vision toolbox v1.2>>>>>\n");
    // this->
    /***********histogram Window**************/
    //  ui->mdiArea->addSubWindow(histogramWindow);
    // histogramWindow->show();
    /*****************************************/
}

MainWindow::~MainWindow()
{
    delete histogramWindow;
    delete hCorner;
    delete morpher;
    delete ui;
}



void MainWindow::on_actionOpen_triggered()
{
    cvWindow = new CvGlWidget(this);

    ui->mdiArea->addSubWindow(cvWindow);

    cv::Mat image;
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image file"), "..//vrml", tr("JPG image (*.jpg);;Portable Network Graphics(*.png)"));
    image = cv::imread(filename.toStdString());
    if(!image.data) return;
    cvWindow->setWindowTitle(filename + " -original");
    image.copyTo(cvWindow->inputImage);

    cvWindow->showImage(image);
    cvWindow->buildHistogram();

    cvWindow->show();
    makeHistogram();
}

void MainWindow::on_actionGray_triggered()
{

    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    if(actCV->cvImage.data == NULL) return;
    // if(actCV->cvImage.channels() == 1) return;
    cv::Mat image;
    cv::cvtColor(actCV->inputImage, image, CV_BGR2GRAY);

    actCV->showImage(image);
    actCV->buildHistogram();
    makeHistogram();

    //cv::imshow("asdf", gray);
}



void MainWindow::on_actionHistogram_triggered()
{

    showHistogram =!showHistogram;
    if(showHistogram){
        if(!activeMdiChild()) return;
        CvGlWidget *actCV = activeMdiChild();
        histogramWindow->buildHistogram(actCV->histo, actCV->statistics, actCV->hmax);
        //   ui->mdiArea->addSubWindow(histogramWindow);
        histogramWindow->show();
        ui->actionHistogram->setChecked(true);
        //     qDebug()<<"opened";


    }
    else
    {

        histogramWindow->close();
        ui->actionHistogram->setChecked(false);
        //        if(QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        //            if(qobject_cast<ExplorerHisto *>(activeSubWindow->widget())) return;
        ////////////////////////////////////////////  ui->mdiArea->setActiveSubWindow(qobject_cast<QMdiSubWindow *>(histogramWindow));
        //  ui->mdiArea->currentSubWindow()->
        ///////////////////////////////////////////  ui->mdiArea->removeSubWindow(qobject_cast<ExplorerHisto *>(histogramWindow));
        //        qDebug()<<ui->mdiArea->currentSubWindow();

        //  qobject_cast<ExplorerHisto *>(histogramWindow);
        //    qDebug()<<"closed";
    }

}

void MainWindow::on_actionBinary_triggered()
{

    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    if(actCV->cvImage.data == NULL) return;
    if(actCV->cvImage.channels() == 1) return;
    cv::Mat image;
    cv::cvtColor(actCV->inputImage, image, CV_BGR2HSV_FULL);
    actCV->showImage(image);
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::subwindowChanged(QMdiSubWindow *currentSubWindow)
{
    CvGlWidget *actCV = qobject_cast<CvGlWidget *>(currentSubWindow);
    makeHistogram();
}

CvGlWidget *MainWindow::activeMdiChild()
{
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<CvGlWidget *>(activeSubWindow->widget());   //returns 0 if no casting possible
    return 0;
}

cam *MainWindow::activeCam()
{
    if (QMdiSubWindow *activeSubWindow = ui->mdiArea->activeSubWindow())
        return qobject_cast<cam *>(activeSubWindow->widget());   //returns 0 if no casting possible
    return 0;
}

void MainWindow::makeHistogram()
{
    CvGlWidget *actCV = activeMdiChild();
    if(actCV == NULL) return;
    if(actCV->cvImage.data == NULL) return;
    histogramWindow->setWindowTitle(actCV->windowTitle() + "histogram");
    histogramWindow->buildHistogram(actCV->histo, actCV->statistics, actCV->hmax);
    histogramWindow->repaint();
}

void MainWindow::applyFilter(int i)
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    if(actCV->cvImage.data == NULL) return;

    k2D.filter(actCV->cvImage, i);
    actCV->showImage(actCV->cvImage);
    makeHistogram();
}

void MainWindow::addImage()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    double alpha = 0.75;
    double beta = ( 1.0 - alpha );
    addWeighted( actCV->cvImage, alpha, actCV->inputImage, beta, 0.0, actCV->cvImage);
    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("Blended");
    actCV->buildHistogram();
    makeHistogram();
}

bool MainWindow::findSubWin(QWidget *w)
{
    int i = 0;
    if(QString::fromStdString((w->metaObject()->className())) == QString("cam)")) qDebug()<<"haha";
    //foreach(QMdiSubWindow *window, ui->mdiArea->subWindowList()){
    //   qDebug()<<++i;
    //   qDebug()<<window->objectName();
    //     qDebug()<<ui->mdiArea->subWindowList();
    //  }
    qDebug()<<w->metaObject()->className();
    return true;
    //  else return false;

}

void MainWindow::on_actionHarris_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    if(actCV->inputImage.data == NULL) return;
    hCorner->dectect(actCV->inputImage);
    vector<cv::Point> keyPoints;
    hCorner->getCorners(keyPoints, .5);
    cv::Mat drawnImage(actCV->cvImage);
    hCorner->drawOnImage(drawnImage, keyPoints,cv::Scalar(0,255,0), 3, 2);
    actCV->showImage(drawnImage);
}

void MainWindow::on_actionCustom_triggered()
{
    kernelUI = new customKernel(this);
    connect(kernelUI, SIGNAL(sendKernel(cv::Mat)), this, SLOT(applyCustomFilter(cv::Mat)));
    kernelUI->show();
}

void MainWindow::on_actionMean_triggered()
{
    k2D.getSize(3);
    applyFilter(0);
}

void MainWindow::applyCustomFilter(Mat m)
{

    k2D.getKernel(m);
    applyFilter(2);
    /******************for camera video******************/
    if(activeCam()){
        camui->sm->setKernel(m);
        QString slotName = "blur()";
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());

        if(d < 0) return;
        camui->sm->commandList.push_back(d);
    }

}

void MainWindow::on_actionOriginal_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    cv::Mat image;
    actCV->inputImage.copyTo(image);
    QString fname = actCV->windowTitle();
    CvGlWidget *originalWindow = new CvGlWidget(this);
    ui->mdiArea->addSubWindow(originalWindow);
    originalWindow->setWindowTitle("original - " +fname );
    image.copyTo(originalWindow->inputImage);
    originalWindow->showImage(image);
    originalWindow->buildHistogram();
    originalWindow->show();
    makeHistogram();
}

void MainWindow::on_actionDilate_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    morpher->setElemNSize(morphUI->elementType, morphUI->kernelSize, morphUI->iteration);
    morpher->Morph(actCV->cvImage, 0);
    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("dilate - ");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionErode_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    morpher->setElemNSize(morphUI->elementType, morphUI->kernelSize, morphUI->iteration);
    morpher->Morph(actCV->cvImage,1);
    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("dilate - ");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionOpening_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    morpher->setElemNSize(morphUI->elementType, morphUI->kernelSize, morphUI->iteration);
    morpher->Morph(actCV->cvImage,2);
    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("dilate - ");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionClosing_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    morpher->setElemNSize(morphUI->elementType, morphUI->kernelSize, morphUI->iteration);
    morpher->Morph(actCV->cvImage,3);
    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("dilate - ");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionGradient_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    morpher->setElemNSize(morphUI->elementType, morphUI->kernelSize, morphUI->iteration);
    morpher->Morph(actCV->cvImage,4);
    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("dilate - ");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionTop_Hat_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    morpher->setElemNSize(morphUI->elementType, morphUI->kernelSize, morphUI->iteration);
    morpher->Morph(actCV->cvImage, 5);
    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("dilate - ");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionBlack_Hat_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    morpher->setElemNSize(morphUI->elementType, morphUI->kernelSize, morphUI->iteration);
    morpher->Morph( actCV->cvImage, 6);
    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("dilate - ");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionTune_parameters_triggered()
{
    morphUI->show();
}

void MainWindow::on_actionMake_Border_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    cv::Mat paddedImage;
    int top = 20, bottom = 20, left = 20, right = 20;
    int borderType = BORDER_CONSTANT; //BORDER_REPLICATE BORDER_REFLECT101
    copyMakeBorder(actCV->cvImage, paddedImage, top, bottom, left, right, borderType, Scalar(0));
    actCV->showImage(paddedImage);
    actCV->setWindowTitle("Padded Image");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionLocal_threshold_triggered()
{

    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    cv::Mat paddedImage;
    int kSize = threshUI->kernelSize;
    int UIT = threshUI->localThresh;
    int top = kSize, bottom = kSize, left = kSize, right = kSize;
    int borderType = threshUI->borderType; //BORDER_REPLICATE BORDER_REFLECT101
    copyMakeBorder(actCV->cvImage, paddedImage, top, bottom, left, right, borderType, Scalar(0));
    int r = actCV->cvImage.rows;  int c = actCV->cvImage.cols;

    //    paddedImage.convertTo(paddedImage, CV_64FC1);
    //    actCV->cvImage.convertTo(actCV->cvImage, CV_64FC1);
    cv::Mat t_im = Mat::zeros(r, c, CV_8UC1);

    cv::Mat sum;
    integral(actCV->cvImage, sum, CV_64FC1);

    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            float sum = 0;
            //   int it = 0;
            //run the kernel now
            for(int u = -(kSize - 1)/2; u <= (kSize - 1)/2; u++)
                for(int v = -(kSize - 1)/2; v <=(kSize -1)/2; v++){
                    sum += (float)paddedImage.at<uchar>(i +kSize+ u,j +kSize+ v);
                }
            //threshold here; 7 is ok
            float t = (float)sum/(kSize*kSize) - 7;
            if((float)actCV->cvImage.at<uchar>(i, j) > t) t_im.at<uchar>(i, j) = 255;
            else t_im.at<uchar>(i, j) = 0;
        }
    }

    actCV->showImage(t_im);
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionSelect_Level_triggered()
{
    threshUI->show();
}

void MainWindow::on_actionEqualize_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    if(actCV->cvImage.channels() == 1){

        equalizeHist(actCV->cvImage, actCV->cvImage);
        actCV->showImage(actCV->cvImage);
        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_temp_returnPressed()
{


    if(activeCam()){
        QString slotName = ui->temp->text() + "()";
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        print(ui->temp->text(), CMD);
        if(d < 0) {
            print(ui->temp->text() + QString(" - no such command"), WARNING);
            return;
        }
        camui->sm->commandList.push_back(d);
        qDebug()<<"mainWin camui: "<<camui->sm->commandList.size();

        // camui->sm->kernel = k2D.kernel;


    }

    /******************if image***************/
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        this->sm->inIm = actCV->cvImage;
        QString slotName = ui->temp->text() + "()";
        int d = this->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        QMetaMethod method = this->sm->metaObject()->method(d);
        method.invoke(sm);


        actCV->showImage(actCV->cvImage);
    }
}

void MainWindow::on_actionOpen_Camera_triggered()
{
    foreach(QMdiSubWindow *w, ui->mdiArea->subWindowList()){
        if(qobject_cast<cam *>(w->widget())) return;
    }
    camui= new cam(); camui->setObjectName("camWin");
    ui->mdiArea->addSubWindow(camui);
    camui->show();
}

void MainWindow::on_actionCascade_triggered()
{
    ui->mdiArea->cascadeSubWindows();
}

void MainWindow::on_actionTile_triggered()
{
    ui->mdiArea->tileSubWindows();
}

void MainWindow::on_actionAdd_triggered()
{
    addImage();
}

void MainWindow::on_actionFundamental_Matrix_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    Mat img1 = actCV->cvImage;

    Mat img2;
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image file"), "..//vrml", tr("JPG image (*.jpg);;Portable Network Graphics(*.png)"));
    img2 = cv::imread(filename.toStdString());
    if(!img2.data) return;

    vector<KeyPoint> keypoints1, keypoints2;
    cv::SurfFeatureDetector surf(3000);

    surf.detect(img1, keypoints1);
    surf.detect(img2, keypoints2);

    cv::Mat imageKP;
    drawKeypoints(img1, keypoints1, imageKP, Scalar(255,255,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    imshow("RIGHT SURF features", imageKP);
    drawKeypoints(img2, keypoints2, imageKP, Scalar(255,255,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    imshow("LEFT SURF features", imageKP);

    cv::SurfDescriptorExtractor surfDesc;
    cv::Mat descriptors1, descriptors2;
    surfDesc.compute(img1, keypoints1, descriptors1);
    surfDesc.compute(img2, keypoints2, descriptors2);

    BFMatcher matcher(NORM_L2);
    std::vector<DMatch> matches;
    matcher.match(descriptors1, descriptors2, matches);
    std::vector<cv::DMatch> selMatches;

    selMatches.push_back(matches[14]);
    selMatches.push_back(matches[16]);
    selMatches.push_back(matches[141]);
    selMatches.push_back(matches[146]);
    selMatches.push_back(matches[235]);
    selMatches.push_back(matches[238]);
    selMatches.push_back(matches[274]);
  //  selMatches.push_back(matches[222]);

    Mat imageMatches;
    drawMatches(img1, keypoints1,
                img2, keypoints2,
                matches,
                imageMatches,
                Scalar(255,255,255));
    imshow("Matches", imageMatches);

    std::vector<int> pointIndexes1;
    std::vector<int> pointIndexes2;
    for(std::vector<DMatch>::iterator it = selMatches.begin();
        it != selMatches.end(); ++it){

        // Get the indexes of the selected matched keypoints
        pointIndexes1.push_back(it->queryIdx);
        pointIndexes2.push_back(it->trainIdx);
    }



    std::vector<cv::Point2f> selPoints1, selPoints2;
        cv::KeyPoint::convert(keypoints1,selPoints1,pointIndexes1);
        cv::KeyPoint::convert(keypoints2,selPoints2,pointIndexes2);

        // check by drawing the points
//        std::vector<cv::Point2f>::iterator it= selPoints1.begin();
//        while (it!=selPoints1.end()) {

//            // draw a circle at each corner location
//            cv::circle(img1,*it,3,cv::Scalar(255,255,255),2);
//            ++it;
//        }

//        it= selPoints2.begin();
//        while (it!=selPoints2.end()) {

//            // draw a circle at each corner location
//            cv::circle(img2,*it,3,cv::Scalar(255,255,255),2);
//            ++it;
//        }

        // Compute F matrix from 7 matches
        cv::Mat fundemental= cv::findFundamentalMat(
            cv::Mat(selPoints1), // points in first image
            cv::Mat(selPoints2), // points in second image
            CV_FM_7POINT);       // 7-point method

//        std::cout << "F-Matrix size= " << fundemental.rows << "," << fundemental.cols << std::endl;

//        // draw the left points corresponding epipolar lines in right image
//        std::vector<cv::Vec3f> lines1;
//        cv::computeCorrespondEpilines(
//            cv::Mat(selPoints1), // image points
//            1,                   // in image 1 (can also be 2)
//            fundemental, // F matrix
//            lines1);     // vector of epipolar lines

//        // for all epipolar lines
//        for (vector<cv::Vec3f>::const_iterator it= lines1.begin();
//             it!=lines1.end(); ++it) {

//                 // draw the epipolar line between first and last column
//                 cv::line(img2,cv::Point(0,-(*it)[2]/(*it)[1]),
//                                 cv::Point(img2.cols,-((*it)[2]+(*it)[0]*img2.cols)/(*it)[1]),
//                                 cv::Scalar(255,255,255));
//        }

//        // draw the left points corresponding epipolar lines in left image
//        std::vector<cv::Vec3f> lines2;
//        cv::computeCorrespondEpilines(cv::Mat(selPoints2),2,fundemental,lines2);
//        for (vector<cv::Vec3f>::const_iterator it= lines2.begin();
//             it!=lines2.end(); ++it) {

//                 // draw the epipolar line between first and last column
//                 cv::line(img1,cv::Point(0,-(*it)[2]/(*it)[1]),
//                                 cv::Point(img1.cols,-((*it)[2]+(*it)[0]*img1.cols)/(*it)[1]),
//                                 cv::Scalar(255,255,255));
//        }


//        cv::namedWindow("Right Image Epilines");
//            cv::imshow("Right Image Epilines",img1);
//            cv::namedWindow("Left Image Epilines");
//            cv::imshow("Left Image Epilines",img2);





















/*

    rmatcher = new RobustMatcher();
    rmatcher->setConfidenceLevel(0.98);
    rmatcher->setMinDistanceToEpipolar(1.0);
    rmatcher->setRatio(0.65f);
    Ptr<FeatureDetector> pfd = new SurfFeatureDetector(10);

    vector<DMatch> matches;

    Mat fundamental = rmatcher->match(img1, img2, matches, keypoints1, keypoints2);

    Mat imageMatches;
    drawMatches(img1, keypoints1,
                img2, keypoints2,
                matches, imageMatches, Scalar(255,255,255));

    cvWindow = new CvGlWidget(this);
    ui->mdiArea->addSubWindow(cvWindow);
    cvWindow->setWindowTitle("Matching Images");
    cvWindow->showImage(imageMatches);
    cvWindow->show();
    imshow("matches", imageMatches);
    vector<Point2f> points1, points2;

    for(vector<DMatch>::const_iterator it = matches.begin();
        it!=matches.end(); ++it){
        float x= keypoints1[it->queryIdx].pt.x;
        float y= keypoints1[it->queryIdx].pt.y;
        points1.push_back(Point2f(x,y));
        circle(img1, Point(x,y), 3, Scalar(255,255,255), 3);
        x = keypoints1[it->trainIdx].pt.x;
        y = keypoints2[it->trainIdx].pt.y;
        circle(img2, Point(x,y), 3, Scalar(255,255,255),3);
        points2.push_back(Point2f(x, y));
    }
    //drawing epipolar lines here
    Scalar color(RNG(256),RNG(256),RNG(256));
    vector<Vec3f> lines1;
    computeCorrespondEpilines(Mat(points1), 1, fundamental, lines1);
    for(vector<Vec3f>::const_iterator it = lines1.begin();it!=lines1.end(); ++it){
        line(img2, Point(0, -(*it)[2]/(*it)[1]),
                Point(img2.cols, -((*it)[2] + (*it)[0]*img2.cols)/(*it)[1]),
                color);
    }
    vector<Vec3f> lines2;
    computeCorrespondEpilines(Mat(points2), 2, fundamental, lines2);
    for(vector<Vec3f>::const_iterator it = lines2.begin();it!=lines2.end(); ++it){
        line(img1, Point(0, -(*it)[2]/(*it)[1]),
                Point(img1.cols, -((*it)[2] + (*it)[0]*img1.cols)/(*it)[1]),
                color);
    }
    cvWindow = new CvGlWidget(this);
    ui->mdiArea->addSubWindow(cvWindow);
    cvWindow->setWindowTitle("Right Image Epilines(RANSAC");
    cvWindow->showImage(img1);
    cvWindow->show();
    cvWindow = new CvGlWidget(this);
    ui->mdiArea->addSubWindow(cvWindow);
    cvWindow->setWindowTitle("Left Image Epilines(RANSAC");
    cvWindow->showImage(img2);
    cvWindow->show();
*/
}


void MainWindow::on_actionConsole_triggered()
{
    showConsole = !showConsole;
    ui->command->setHidden(showConsole);
    ui->temp->setHidden(showConsole);
}

void MainWindow::on_actionSalt_and_Pepper_triggered()
{
    if(activeCam()){
        QString slotName = "saltNpepper()";
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        camui->sm->commandList.push_back(d);

        // camui->sm->kernel = k2D.kernel;


    }

    /******************if image***************/
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        this->sm->inIm = actCV->cvImage;

        sm->saltNpepper();

        actCV->showImage(actCV->cvImage);

        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionGaussian_2_triggered()
{
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        this->sm->inIm = actCV->cvImage;

        sm->gaussianNoise();

        actCV->showImage(actCV->cvImage);

        actCV->buildHistogram();
        makeHistogram();

    }
}

void MainWindow::on_actionCanny_Edge_triggered()
{
    if(activeCam()){
        QString slotName = "canny(int, int)";
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        this->sm->inIm = actCV->cvImage;

        sm->canny(contourParam->cannyMin, contourParam->cannyMax);
        actCV->showImage(sm->inIm);
        qDebug()<<contourParam->cannyMin;
        actCV->buildHistogram();
        makeHistogram();

    }
}

void MainWindow::on_actionBlobs_triggered()
{

}

void MainWindow::on_actionContours_only_triggered()
{
    if(activeCam()){
        QString slotName = "blob()";
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->inputImage.copyTo(this->sm->inIm); //dont change original image


        // QString slotName = "blob()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("blob(int)");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 2));
        actCV->showImage(sm->inIm);

        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionSuper_Imposed_triggered()
{
    if(activeCam()){
        QString slotName = "blob()";
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->inputImage.copyTo(this->sm->inIm); //dont change original image


        // QString slotName = "blob()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("blob(int)");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 2));
        actCV->showImage(sm->inIm);

        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionBounding_Box_triggered()
{
    if(activeCam()){
        QString slotName = "blob()";
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->inputImage.copyTo(this->sm->inIm); //dont change original image


        // QString slotName = "blob()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("blob(int)");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 3));
        actCV->showImage(sm->inIm);

        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionRectangles_triggered()
{
    if(activeCam()){
        QString slotName = "blob()";
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->inputImage.copyTo(this->sm->inIm); //dont change original image


        // QString slotName = "blob()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("blob(int)");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 5)); //polygonal
        actCV->showImage(sm->inIm);

        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionCircles_triggered()
{
    if(activeCam()){
        QString slotName = "blob()";
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->inputImage.copyTo(this->sm->inIm); //dont change original image


        // QString slotName = "blob()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("blob(int)");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 4)); //polygonal
        actCV->showImage(sm->inIm);

        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionMoments_triggered()
{
    if(activeCam()){
        QString slotName = "blob()";
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->inputImage.copyTo(this->sm->inIm); //dont change original image


        // QString slotName = "blob()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("blob(int)");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 7));
        actCV->showImage(sm->inIm);

        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionConvex_hull_triggered()
{
    if(activeCam()){
        QString slotName = "blob()";
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->inputImage.copyTo(this->sm->inIm); //dont change original image


        // QString slotName = "blob()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("blob(int)");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 6));
        actCV->showImage(sm->inIm);

        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionMagnitude_map_triggered()
{
    if(activeCam()){
        QString slotName = "blob()";
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image


        // QString slotName = "sobel()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("sobel(int, int, int)");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 3), Q_ARG(int, contourParam->sobelAperature), Q_ARG(int, contourParam->sobelThresh));
        actCV->showImage(sm->inIm);

        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionOrientation_map_triggered()
{
    int aperature = 3, threshold = 128;
    if(activeCam()){
        QString slotName = "blob()";
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image


        // QString slotName = "sobel()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("sobel(int, int, int)");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 3), Q_ARG(int, contourParam->sobelAperature), Q_ARG(int, contourParam->sobelThresh));
        actCV->showImage(sm->inIm);

        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionSobel_Image_triggered()
{
    if(activeCam()){
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("sobel(int, int, int)");
        int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image


        // QString slotName = "sobel()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("sobel(int, int, int)");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 3), Q_ARG(int, contourParam->sobelAperature), Q_ARG(int, contourParam->sobelThresh));
        actCV->showImage(sm->inIm);

        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionLaplacian_triggered()
{

    if(activeCam()){
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("laplacian(int, int)");
        int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image


        // QString slotName = "sobel()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("laplacian(int)");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, contourParam->laplaceKSize));
        actCV->showImage(sm->inIm);

        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionOptions_triggered()
{
    contourParam->show();
}

void MainWindow::on_actionHough_lines_triggered()
{
    if(activeCam()){
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("laplacian(int, int)");
        int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->inputImage.copyTo(this->sm->inIm); //dont change original image


        // QString slotName = "sobel()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("hough(int)");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 1));
        actCV->showImage(sm->inIm);
        actCV->buildHistogram();
        makeHistogram();

    }
}

void MainWindow::on_actionHough_Circles_triggered()
{
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->inputImage.copyTo(this->sm->inIm); //dont change original image

        // QString slotName = "sobel()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("hough(int, int, int, int, int, int)");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 2), Q_ARG(int, contourParam->cannyMin), Q_ARG(int, contourParam->cannyMax),
                      Q_ARG(int, contourParam->minVotes), Q_ARG(int, contourParam->minRad), Q_ARG(int, contourParam->maxRad),Q_ARG(int, contourParam->minCircDist));
        actCV->showImage(sm->inIm);
        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionCalibrate_triggered()
{
    calibUI->show();
}
