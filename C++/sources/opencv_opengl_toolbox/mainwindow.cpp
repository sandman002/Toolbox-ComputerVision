#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include <QMetaObject>
#include <QMetaMethod>
#include <iostream>
#include <QSlider>
#include <QComboBox>
#include <QMessageBox>
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
    featUI = new featuresUI(this);
    showHistogram = false;
    sm = new someClass(this);
    contourParam = new contoursUI(this);
    showConsole = true;
    ui->command->setVisible(!showConsole);
    ui->temp->setVisible(!showConsole);
    fundaMethod = 1;
    ransacDist = 1; ransacConf = 0.98; ransacNN = 0.68; alpha = 0.7;
    brightContrastAdjust = new brightContrastUI(this);
    methodBox = new fundOptUI(this);

    connect(ui->mdiArea, SIGNAL(subWindowActivated(QMdiSubWindow*)), this, SLOT(subwindowChanged(QMdiSubWindow*)));
    connect(featUI, SIGNAL(sendParams()), this, SLOT(uiFeatureConnect()));
    connect(contourParam, SIGNAL(paramChanged()), this, SLOT(uiContourConnect()));
    ui->command->setText("<<<<<Welcome to Manandhar's Computer Vision toolbox v1.2>>>>>\n");
    // this->
    /***********histogram Window**************/
    //  ui->mdiArea->addSubWindow(histogramWindow);
    // histogramWindow->show();
    /*****************************************/

}

MainWindow::~MainWindow()
{
    histogramWindow->close();
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
                                                    tr("Open Image file"), "../images", tr("JPG image (*.jpg);;Portable Network Graphics(*.png);;bitmap(*.bmp"));
    image = cv::imread(filename.toStdString());
    if(!image.data) return;
    cvWindow->oriX = image.cols;
    cvWindow->oriY = image.rows;
    cvWindow->setWindowTitle(filename + " -original");
    image.copyTo(cvWindow->inputImage);

    cvWindow->showImage(image);
    cvWindow->buildHistogram();

    cvWindow->show();
    makeHistogram();
    int wd = image.cols; int ht = image.rows;

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
    ui->info->setText(QString("Image Size: ") + QString::number(actCV->cvImage.cols) +
                      "x" + QString::number(actCV->cvImage.rows));
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
    if(actCV->cvImage.channels() == 1 ||actCV->cvImage.size() != actCV->inputImage.size())
        return;

    addWeighted( actCV->cvImage, alpha, actCV->inputImage,1-alpha, 0.0, actCV->cvImage);
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

void MainWindow::computeHomography(int option)
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    Mat img1;
    actCV->cvImage.copyTo(img1);

    Mat img2;
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Image file"), "..//vrml", tr("JPG image (*.jpg);;Portable Network Graphics(*.png)"));
    img2 = cv::imread(filename.toStdString());
    if(!img2.data) return;

    RobustMatcher rmatcher;
    rmatcher.setConfidenceLevel(methodBox->ransacConf);
    rmatcher.setMinDistanceToEpipolar(methodBox->ransacDist);
    rmatcher.setRatio(methodBox->ransacNN);
    cv::Ptr<cv::FeatureDetector> pfd= new cv::SurfFeatureDetector(10);
    rmatcher.setFeatureDetector(pfd);

    // Match the two images
    std::vector<cv::DMatch> matches;
    std::vector<cv::KeyPoint> keypoints1, keypoints2;
    cv::Mat fundamental= rmatcher.match(img1,img2,matches, keypoints1, keypoints2);

    // draw the matches
    cv::Mat imageMatches;
    cv::drawMatches(img1,keypoints1,  // 1st image and its keypoints
                    img2,keypoints2,  // 2nd image and its keypoints
                    matches,			// the matches
                    imageMatches,		// the image produced
                    cv::Scalar(255,255,255)); // color of the lines

    cvWindow = new CvGlWidget(this);
    ui->mdiArea->addSubWindow(cvWindow);
    cvWindow->setWindowTitle("matches");
    cvWindow->showImage(imageMatches);
    cvWindow->show();

    // Convert keypoints into Point2f
    std::vector<cv::Point2f> points1, points2;
    for (std::vector<cv::DMatch>::const_iterator it= matches.begin();
         it!= matches.end(); ++it) {

        // Get the position of left keypoints
        float x= keypoints1[it->queryIdx].pt.x;
        float y= keypoints1[it->queryIdx].pt.y;
        points1.push_back(cv::Point2f(x,y));
        // Get the position of right keypoints
        x= keypoints2[it->trainIdx].pt.x;
        y= keypoints2[it->trainIdx].pt.y;
        points2.push_back(cv::Point2f(x,y));
    }

    //    std::cout << points1.size() << " " << points2.size() << std::endl;

    // Find the homography between image 1 and image 2
    std::vector<uchar> inliers(points1.size(),0);
    cv::Mat homography= cv::findHomography(
                cv::Mat(points1),cv::Mat(points2), // corresponding points
                inliers,	// outputed inliers matches
                CV_RANSAC,	// RANSAC method
                1.);	    // max distance to reprojection point

    // Draw the inlier points
    std::vector<cv::Point2f>::const_iterator itPts= points1.begin();
    std::vector<uchar>::const_iterator itIn= inliers.begin();
    while (itPts!=points1.end()) {

        // draw a circle at each inlier location
        if (*itIn)
            cv::circle(img1,*itPts,3,cv::Scalar(0,0,255),1);

        ++itPts;
        ++itIn;
    }
    Mat im2; img2.copyTo(im2);
    itPts= points2.begin();
    itIn= inliers.begin();
    while (itPts!=points2.end()) {

        // draw a circle at each inlier location
        if (*itIn)
            cv::circle(im2,*itPts,3,cv::Scalar(0,255,0),1);

        ++itPts;
        ++itIn;
    }

    // Display the images with points

    cvWindow = new CvGlWidget(this);
    ui->mdiArea->addSubWindow(cvWindow);
    cvWindow->setWindowTitle("Image 1 Homography Points");
    cvWindow->showImage(img1);
    cvWindow->show();

    cvWindow = new CvGlWidget(this);
    ui->mdiArea->addSubWindow(cvWindow);
    cvWindow->setWindowTitle("Image 2 Homography Points");
    cvWindow->showImage(im2);
    cvWindow->show();
    // Warp image 1 to image 2
    cv::Mat result;
    cv::warpPerspective(actCV->cvImage, // input image
                        result,			// output image
                        homography,		// homography
                        cv::Size(2*img1.cols,img1.rows)); // size of output image

    // Copy image 1 on the first half of full image
    cv::Mat half(result,cv::Rect(0,0,img2.cols,img2.rows));
    img2.copyTo(half);

    // Display the warp image
    cvWindow = new CvGlWidget(this);
    ui->mdiArea->addSubWindow(cvWindow);
    cvWindow->setWindowTitle("Wraping up");
    cvWindow->showImage(result);
    cvWindow->show();
}

void MainWindow::fundaPoints( int fundaSeq, int option)
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    Mat img1;
    actCV->cvImage.copyTo(img1);

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
    cvWindow = new CvGlWidget(this);
    ui->mdiArea->addSubWindow(cvWindow);
    cvWindow->setWindowTitle("RIGHT SURF features");
    cvWindow->showImage(imageKP);
    cvWindow->show();


    drawKeypoints(img2, keypoints2, imageKP, Scalar(255,255,255), DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
    cvWindow = new CvGlWidget(this);
    ui->mdiArea->addSubWindow(cvWindow);
    cvWindow->setWindowTitle("LEFT SURF features");
    cvWindow->showImage(imageKP);
    cvWindow->show();


    cv::SurfDescriptorExtractor surfDesc;
    cv::Mat descriptors1, descriptors2;
    surfDesc.compute(img1, keypoints1, descriptors1);
    surfDesc.compute(img2, keypoints2, descriptors2);

    BFMatcher matcher(NORM_L2);
    std::vector<DMatch> matches;
    matcher.match(descriptors1, descriptors2, matches);
    if(matches.empty() == true) return;
    std::vector<cv::DMatch> selMatches;

    selMatches.push_back(matches[1]);
    selMatches.push_back(matches[2]);
    selMatches.push_back(matches[3]);
    selMatches.push_back(matches[4]);
    selMatches.push_back(matches[5]);
    selMatches.push_back(matches[6]);
    selMatches.push_back(matches[7]);
    if(option == 2)
        selMatches.push_back(matches[8]);

    Mat imageMatches;
    drawMatches(img1, keypoints1,
                img2, keypoints2,
                matches,
                imageMatches,
                Scalar(255,255,255));

    cvWindow = new CvGlWidget(this);
    ui->mdiArea->addSubWindow(cvWindow);
    cvWindow->setWindowTitle("Matches");
    cvWindow->showImage(imageMatches);
    cvWindow->show();


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

    //        // check by drawing the points
    std::vector<cv::Point2f>::const_iterator it= selPoints1.begin();
    while (it!=selPoints1.end()) {

        // draw a circle at each corner location
        cv::circle(img1,*it,3,cv::Scalar(255,255,255),2);
        ++it;
    }

    it= selPoints2.begin();
    while (it!=selPoints2.end()) {

        // draw a circle at each corner location
        cv::circle(img2,*it,3,cv::Scalar(255,255,255),2);
        ++it;
    }

    cv::Mat fundamental;
    // Compute F matrix from 7 matches
    if(option == 1)
        fundamental= cv::findFundamentalMat(
                    cv::Mat(selPoints1), // points in first image
                    cv::Mat(selPoints2), // points in second image
                    CV_FM_7POINT);       // 7-point method
    else if(option == 2)
        fundamental= cv::findFundamentalMat(
                    cv::Mat(selPoints1), // points in first image
                    cv::Mat(selPoints2), // points in second image
                    CV_FM_8POINT);       // 7-point method



    Mat funde3 ;

    // if(fundaSeq == 1)
    funde3 = fundamental(Range(0,3), Range(0,3));
    //  else if(fundaSeq == 2 && option != 1)
    //      funde3 = fundamental(Range(3,6), Range(0,3));
    //  else if(fundaSeq == 3 && option != 1)
    //     funde3 = fundamental(Range(6,3), Range(0,3));

    //         draw the left points corresponding epipolar lines in right image
    std::vector<cv::Vec3f> lines1;
    cv::computeCorrespondEpilines(
                cv::Mat(selPoints1), // image points
                1,                   // in image 1 (can also be 2)
                funde3, // F matrix
                lines1);     // vector of epipolar lines

    // for all epipolar lines
    for (vector<cv::Vec3f>::const_iterator it= lines1.begin();
         it!=lines1.end(); ++it) {

        // draw the epipolar line between first and last column
        cv::line(img2,cv::Point(0,-(*it)[2]/(*it)[1]),
                cv::Point(img2.cols,-((*it)[2]+(*it)[0]*img2.cols)/(*it)[1]),
                cv::Scalar(255,255,255));
    }

    // draw the left points corresponding epipolar lines in left image
    std::vector<cv::Vec3f> lines2;
    cv::computeCorrespondEpilines(cv::Mat(selPoints2),2,funde3,lines2);
    for (vector<cv::Vec3f>::const_iterator it= lines2.begin();
         it!=lines2.end(); ++it) {

        // draw the epipolar line between first and last column
        cv::line(img1,cv::Point(0,-(*it)[2]/(*it)[1]),
                cv::Point(img1.cols,-((*it)[2]+(*it)[0]*img1.cols)/(*it)[1]),
                cv::Scalar(255,255,255));
    }


    cvWindow = new CvGlWidget(this);
    ui->mdiArea->addSubWindow(cvWindow);
    cvWindow->setWindowTitle("Right Image Epilines");
    cvWindow->showImage(img1);
    cvWindow->show();

    cvWindow = new CvGlWidget(this);
    ui->mdiArea->addSubWindow(cvWindow);
    cvWindow->setWindowTitle("Left Image Epilines");
    cvWindow->showImage(img2);
    cvWindow->show();

}

void MainWindow::on_actionHarris_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    if(actCV->inputImage.data == NULL) return;
    actCV->inputImage.copyTo(sm->inIm);
    sm->hCorner->aperature = featUI->hApert;
    sm->hCorner->neighbourhood = featUI->hNeigh;
    sm->hCorner->maxStrength = featUI->hMaxStr;
    sm->hCorner->k = featUI->hPara;
    sm->hCorner->threshold = featUI->hThresh;
    sm->harris();
    actCV->showImage(sm->inIm);
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
        QString slotName = "filter()";
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
    //    morpher->setElemNSize(morphUI->elementType, morphUI->kernelSize, morphUI->iteration);
    //    morpher->Morph(actCV->cvImage, 0);

    sm->basicType = morphUI->elementType;
    sm->morph_size = morphUI->kernelSize;
    sm->inIm = actCV->cvImage;
    sm->morph_dilate();
    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("dilate - ");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionErode_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();

    sm->basicType = morphUI->elementType;
    sm->morph_size = morphUI->kernelSize;
    sm->inIm = actCV->cvImage;
    sm->morph_erode();
    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("erode - ");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionOpening_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    sm->basicType = morphUI->elementType;
    sm->morph_size = morphUI->kernelSize;
    sm->inIm = actCV->cvImage;
    sm->morph_open();
    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("opened - ");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionClosing_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    sm->basicType = morphUI->elementType;
    sm->morph_size = morphUI->kernelSize;
    sm->inIm = actCV->cvImage;
    sm->morph_close();
    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("closed - ");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionGradient_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    sm->basicType = morphUI->elementType;
    sm->morph_size = morphUI->kernelSize;
    sm->inIm = actCV->cvImage;
    sm->morph_gradient();
    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("morphological gradient - ");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionTop_Hat_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    sm->basicType = morphUI->elementType;
    sm->morph_size = morphUI->kernelSize;
    sm->inIm = actCV->cvImage;
    sm->morph_tophat();


    actCV->showImage(actCV->cvImage);
    actCV->setWindowTitle("dilate - ");
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionBlack_Hat_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();

    sm->basicType = morphUI->elementType;
    sm->morph_size = morphUI->kernelSize;
    sm->inIm = actCV->cvImage;
    sm->morph_blackhat();

    actCV->showImage(actCV->cvImage);
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

    QRegExp rx("\\b(remove)\\d\\d?\\b");    //check for word "remove" immediately followed by [0-9] repeated [0 or 1] times
    QRegExp prx("^([a-z|A-Z]+):[-+]?[0-9]*\.?[0-9]+$");
    if(activeCam()){
        if(ui->temp->text() == QString("whatsup")){
            int listSize  = camui->sm->commandList.size();
            const QMetaObject* mtobj = camui->sm->metaObject();
            print(QString("What's going on so far..."), CMD);
            if(listSize == 0){
                print("NOTHING's going on", RESULT);
            }else
                for(int i = 0; i < listSize; ++i){
                    print(QString::fromLatin1(mtobj->method(camui->sm->commandList.at(i)).methodSignature()), WARNING);
                }
            return;
        }
        else if(rx.indexIn(ui->temp->text()) == 0){

            QStringList list = (ui->temp->text()).split(rx.cap(1));
            if(list.isEmpty()) return;
            int remIdx = list[1].toInt();   //retreive the number from remove command
            if(remIdx < camui->sm->commandList.size()){ //check of the number is valid index
                qDebug()<<"removing";
                camui->sm->commandList.erase(camui->sm->commandList.begin()+remIdx); //remove the command as specified by the number
                qDebug()<<"removed";
                int listSize  = camui->sm->commandList.size();
                const QMetaObject* mtobj = camui->sm->metaObject();
                print(QString("What's going on so far..."), CMD);
                for(int i = 0; i < listSize; ++i){
                    print(QString::fromLatin1(mtobj->method(camui->sm->commandList.at(i)).methodSignature()), WARNING);
                }
            }
            else
                print("No such command index found!!!", WARNING);
            return;
        }
        else if(prx.indexIn(ui->temp->text()) == 0 && ui->temp->text().contains(":")){
            qDebug()<<"listing...";
            QStringList list;
            list= ui->temp->text().split(":");
            if(list.isEmpty()) return;
            double parameter = list[1].toDouble(); //this is where my parameter lies
            qDebug()<<list;
            qDebug()<<parameter;
            QByteArray normalizedSignature = QMetaObject::normalizedSignature((list[0] + "(double)").toStdString().c_str());
            int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
            print(ui->temp->text(), CMD);
            if(d < 0) {
                print(ui->temp->text() + QString(" - no such command"), WARNING);
                return;
            }

            QMetaMethod method = camui->sm->metaObject()->method(d);
            method.invoke(camui->sm, Qt::DirectConnection, Q_ARG(double, parameter));
            return;
        }


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
        print(ui->temp->text(), CMD);
        if(d < 0) {
            print(ui->temp->text() + QString(" - no such command"), WARNING);
            return;
        }
        QMetaMethod method = this->sm->metaObject()->method(d);
        method.invoke(sm);


        actCV->showImage(actCV->cvImage);
    }

    ui->temp->setText(NULL);
}

void MainWindow::on_actionOpen_Camera_triggered()
{
    foreach(QMdiSubWindow *w, ui->mdiArea->subWindowList()){
        if(qobject_cast<cam *>(w->widget())) return;
    }
    camui= new cam();
camui->setMode(1);
camui->startCapture();
    camui->setObjectName("camWin");
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
    int d = methodBox->d;

    if(d == 1){ fundaPoints(1,1);} //7 points
    else if(d == 2) {fundaPoints(1,2);}
    else if(d == 3){
        if(!activeMdiChild()) return;
        CvGlWidget *actCV = activeMdiChild();
        Mat img1;
        actCV->cvImage.copyTo(img1);

        Mat img2;
        QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("Open Image file"), "..//vrml", tr("JPG image (*.jpg);;Portable Network Graphics(*.png)"));
        img2 = cv::imread(filename.toStdString());
        if(!img2.data) return;

        vector<KeyPoint> keypoints1, keypoints2;



        rmatcher = new RobustMatcher();
        rmatcher->setConfidenceLevel(methodBox->ransacConf);
        rmatcher->setMinDistanceToEpipolar(methodBox->ransacDist);
        rmatcher->setRatio(methodBox->ransacNN);
        Ptr<FeatureDetector> pfd = new SurfFeatureDetector(100);
        rmatcher->setFeatureDetector(pfd);
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
    }
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
        QString slotName = "sobel()";
        camui->sm->option = 1;
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image


        this->sm->option = 1;
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("sobel()");
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
        QString slotName = "sobel()";
        camui->sm->option = 2;
        int d = camui->sm->metaObject()->indexOfSlot(slotName.toStdString().c_str());
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image


        this->sm->option = 2;
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("sobel()");
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
        camui->sm->option = 3;
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("sobel()");
        int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image


        this->sm->option = 3;
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("sobel()");
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
        qDebug()<<contourParam->laplaceKSize;
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
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("hough(int)");
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

void MainWindow::on_actionOptions_2_triggered()
{
    if(!activeMdiChild()) return;

    methodBox->show();
}

void MainWindow::on_actionClose_All_Subwindows_triggered()
{
    ui->mdiArea->closeAllSubWindows();
}

void MainWindow::on_actionCompute_Homography_triggered()
{
    this->computeHomography();
}

void MainWindow::on_actionFast_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    actCV->inputImage.copyTo(sm->inIm);
    sm->featurePoints = featUI->gThresh;
    sm->fast();
    actCV->showImage(sm->inIm);
}

void MainWindow::on_actionSURF_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    actCV->inputImage.copyTo(sm->inIm);
    sm->featurePoints = featUI->gThresh;
    sm->surf();
    actCV->showImage(sm->inIm);
}

void MainWindow::on_actionSIFT_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    actCV->inputImage.copyTo(sm->inIm);
    sm->featThresh = featUI->siftThresh;
    sm->threshReduce = featUI->edgeThresh;
    sm->sift();
    actCV->showImage(sm->inIm);
}

void MainWindow::on_actionMSER_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    actCV->inputImage.copyTo(sm->inIm);
    sm->mser();
    actCV->showImage(sm->inIm);
}

void MainWindow::on_actionOptions_3_triggered()
{
    featUI->show();

}

void MainWindow::uiFeatureConnect()
{
    if(activeCam()){
        camui->sm->featurePoints = featUI->gThresh;
        camui->sm->featThresh = featUI->siftThresh;
        camui->sm->threshReduce = featUI->edgeThresh;
        camui->sm->hCorner->aperature = featUI->hApert;
        camui->sm->hCorner->neighbourhood = featUI->hNeigh;
        camui-> sm->hCorner->maxStrength = featUI->hMaxStr;
        camui->sm->hCorner->k = featUI->hPara;
        camui->sm->hCorner->threshold = featUI->hThresh;
        sm->pSize = featUI->pSize;
        return;
    }
    sm->featurePoints = featUI->gThresh;
    sm->featThresh = featUI->siftThresh;
    sm->threshReduce = featUI->edgeThresh;
    sm->hCorner->aperature = featUI->hApert;
    sm->hCorner->neighbourhood = featUI->hNeigh;
    sm->hCorner->maxStrength = featUI->hMaxStr;
    sm->hCorner->k = featUI->hPara;
    sm->hCorner->threshold = featUI->hThresh;
    sm->pSize = featUI->pSize;
}

void MainWindow::uiContourConnect()
{
    if(activeCam()){
        camui->sm->thresh = contourParam->thresh;
        camui->sm->rho = contourParam->rho;
        camui->sm->minLineLength = contourParam->minLen;
        camui->sm->maxLineGap = contourParam->maxGap;
        camui->sm->cannyLowThresh = contourParam->cannyMin;
        camui->sm->cannyhighThresh = contourParam->cannyMax;
        camui->sm->circDist = contourParam->minCircDist;
        camui->sm->minRad = contourParam->minRad;
        camui->sm->maxRad = contourParam->maxRad;
        camui->sm->minVotes = contourParam->minVotes;
        return;
    }
    sm->thresh = contourParam->thresh;
    sm->rho = contourParam->rho;
    sm->minLineLength = contourParam->minLen;
    sm->maxLineGap = contourParam->maxGap;
    sm->cannyLowThresh = contourParam->cannyMin;
    sm->cannyhighThresh = contourParam->cannyMax;
    sm->circDist = contourParam->minCircDist;
    sm->minRad = contourParam->minRad;
    sm->maxRad = contourParam->maxRad;
    sm->minVotes = contourParam->minVotes;
}

void MainWindow::on_actionROI_triggered()
{

}

void MainWindow::on_actionSave_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();

    vector<int> compression_params;
    compression_params.push_back(CV_IMWRITE_JPEG_QUALITY);
    compression_params.push_back(98);
    QString savename = QFileDialog::getSaveFileName(this, "Save file", "", ".jpg");
    savename = savename + ".jpg";
    if(cv::imwrite(savename.toStdString().c_str(), actCV->cvImage, compression_params) == false)
    {  QMessageBox::warning(
                    this,
                    tr("Error with Saving image"),
                    tr("Could not save the file") );
        return;}
    ui->info->setText("file has been saved");
}

void MainWindow::closeEvent(QCloseEvent *)
{
    qDebug()<<"closed";
    histogramWindow->close();
}


void MainWindow::on_actionBrightness_Contrast_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    actCV->inputImage.copyTo(sm->orig);
    connect(brightContrastAdjust, SIGNAL(sendalphabeta(double,int)), this, SLOT(BC(double, int)));

    brightContrastAdjust->show();


}

void MainWindow::BC(double a, int b) //manange brightness contrast;
{

    sm->getAlphaBeta(a, b);
    sm->brightnessContrast();
    CvGlWidget *actCV = activeMdiChild();
    actCV->showImage(sm->inIm);
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionUpSample_2x_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    actCV->cvImage.copyTo(sm->inIm);
    sm->upSample();
    actCV->showImage(sm->inIm);
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::on_actionDownSample_1_2x_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    actCV->cvImage.copyTo(sm->inIm);
    sm->downSample();
    actCV->showImage(sm->inIm);
    actCV->buildHistogram();
    makeHistogram();
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{

    if(e->key() == Qt::Key_F9){
        on_actionConsole_triggered();
        ui->temp->setFocus();
    }
}

void MainWindow::on_actionDetect_human_faces_triggered()
{
    if(activeCam()){
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("findFace()");
        int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->inputImage.copyTo(this->sm->inIm); //dont change original image
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("findFace()");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 1));
        actCV->showImage(sm->inIm);
    }
}

void MainWindow::on_actionMedian_triggered()
{
    if(activeCam()){
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("median()");
        int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("median()");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 1));
        actCV->showImage(sm->inIm);
        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionGrayscale_triggered()
{
    if(activeCam()){
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("gray()");
        int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("gray()");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 1));
        actCV->showImage(sm->inIm);
        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionYCbCr_triggered()
{
    if(activeCam()){
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("YCrCb()");
        int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("YCrCb()");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 1));
        actCV->showImage(sm->inIm);
        actCV->buildHistogram();
        makeHistogram();
    }
}



void MainWindow::on_actionHSV_triggered()
{
    if(activeCam()){
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("HSV()");
        int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("HSV()");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 1));
        actCV->showImage(sm->inIm);
        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionLab_triggered()
{
    if(activeCam()){
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("Lab()");
        int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("Lab()");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 1));
        actCV->showImage(sm->inIm);
        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionLuv_triggered()
{
    if(activeCam()){
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("Luv()");
        int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("Luv()");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 1));
        actCV->showImage(sm->inIm);
        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionHLS_triggered()
{
    if(activeCam()){
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("HLS()");
        int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->cvImage.copyTo(this->sm->inIm); //dont change original image
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("HLS()");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 1));
        actCV->showImage(sm->inIm);
        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionAbout_triggered()
{
    int i = QMessageBox::information(this, tr("info"), tr("manandhar.sandeep@gmail.com\nUniversity of Burgundy, France"));
}

void MainWindow::on_actionHough_PLines_triggered()
{
    if(activeCam()){
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("houghPLines()");
        int d = camui->sm->metaObject()->indexOfSlot(normalizedSignature);
        camui->sm->commandList.push_back(d);
    }
    if(activeMdiChild()){
        CvGlWidget *actCV = activeMdiChild();
        actCV->inputImage.copyTo(this->sm->inIm); //dont change original image


        // QString slotName = "sobel()";
        QByteArray normalizedSignature = QMetaObject::normalizedSignature("houghPLines()");
        int methodIndex = this->sm->metaObject()->indexOfSlot(normalizedSignature);
        QMetaMethod method = this->sm->metaObject()->method(methodIndex);
        method.invoke(sm,Qt::DirectConnection,  Q_ARG(int, 1));
        actCV->showImage(sm->inIm);
        actCV->buildHistogram();
        makeHistogram();
    }
}

void MainWindow::on_actionExit_triggered()
{
    this->close();
}

void MainWindow::on_actionOpen_Motion_Picture_triggered()
{
    foreach(QMdiSubWindow *w, ui->mdiArea->subWindowList()){
        if(qobject_cast<cam *>(w->widget())) return;
    }
    camui= new cam();
camui->setMode(2);
camui->startCapture();
    camui->setObjectName("camWin");
    ui->mdiArea->addSubWindow(camui);
    camui->show();
}

void MainWindow::on_actionCrop_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    if(actCV->band->isVisible()){
        QRect ROI = actCV->ROI;

        double aspectRatio = (double)ROI.width()/ROI.height();
        double realWidth_ROI = (double)ROI.width()/actCV->wImg*actCV->oriX;
        double realHeight_ROI = realWidth_ROI/aspectRatio;

        double tlX = (double)ROI.x()/actCV->wImg*actCV->oriX; double tlY = (double)ROI.y()/actCV->hImg*actCV->oriY;
        Mat croppedIm = actCV->cvImage(Rect(tlX, tlY, realWidth_ROI, realHeight_ROI));

        cvWindow = new CvGlWidget(this);
        ui->mdiArea->addSubWindow(cvWindow);
        cvWindow->setWindowTitle("croped");
        cvWindow->showImage(croppedIm);
        cvWindow->show();
        cvWindow->buildHistogram();

        makeHistogram();

    }
}

void MainWindow::on_actionWatermark_it_triggered()
{
    if(!activeMdiChild()) return;
    CvGlWidget *actCV = activeMdiChild();
    if(actCV->band->isVisible()){
        QString filename = QFileDialog::getOpenFileName(this,
                                                        tr("Open Image file"), "..//vrml", tr("JPG image (*.jpg);;Portable Network Graphics(*.png)"));
        Mat logo = cv::imread(filename.toStdString());
        if(!logo.data) return;

        QRect ROI = actCV->ROI;

        double aspectRatio = (double)ROI.width()/ROI.height();
        double realWidth_ROI = (double)ROI.width()/actCV->wImg*actCV->oriX;
        double realHeight_ROI = realWidth_ROI/aspectRatio;

        double tlX = (double)ROI.x()/actCV->wImg*actCV->oriX; double tlY = (double)ROI.y()/actCV->hImg*actCV->oriY;
        // Mat im = actCV->cvImage(Rect(tlX, tlY, realWidth_ROI, realHeight_ROI));
        //imshow("cropped", im);

        cv::resize(logo, logo, cv::Size(realWidth_ROI, realHeight_ROI));
        Mat overlay = cv::Mat::zeros(actCV->cvImage.rows, actCV->cvImage.cols, actCV->cvImage.type());

        logo.copyTo(overlay(cv :: Rect (tlX, tlY, logo.cols, logo.rows)));


        /**********when overlay is required***********/
        Mat roi = actCV->cvImage(Rect (tlX, tlY, logo.cols, logo.rows));
        roi.setTo(0);

       // cv::add(actCV->cvImage, overlay, actCV->cvImage);
          addWeighted( actCV->cvImage, 1.0 - alpha, overlay, alpha, 0.0, actCV->cvImage);

        actCV->showImage(actCV->cvImage);
        actCV->buildHistogram();
        makeHistogram();

    }
}

void MainWindow::on_actionTransparency_triggered()
{
    QSlider *transSlider = new QSlider(this);
    transSlider->setOrientation(Qt::Horizontal);
    transSlider->setWindowFlags(Qt::Window);
    transSlider->setWindowTitle("Set Transparency");
    transSlider->setMaximum(100);
    transSlider->setMinimum(0);
    transSlider->show();
    connect(transSlider, SIGNAL(valueChanged(int)), this, SLOT(setAlpha(int)));
}
