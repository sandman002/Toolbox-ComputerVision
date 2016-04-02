#include "someclass.h"
#include <QDebug>
#include <iostream>
#include <QMetaProperty>

void someClass::gray(int c)
{
    if(inIm.channels() == 1)
        return;
    cv::cvtColor(inIm, inIm, CV_BGR2GRAY);

}

void someClass::YCrCb()
{
    if(inIm.channels() == 1)
        cv::cvtColor(inIm, inIm, CV_GRAY2BGR);
    cv::cvtColor(inIm, inIm, CV_BGR2YCrCb);
}

void someClass::HSV()
{
    if(inIm.channels() == 1)
        cv::cvtColor(inIm, inIm, CV_GRAY2BGR);
    cv::cvtColor(inIm, inIm, CV_BGR2HSV);
}

void someClass::HLS()
{
    if(inIm.channels() == 1)
        cv::cvtColor(inIm, inIm, CV_GRAY2BGR);
    cv::cvtColor(inIm, inIm, CV_BGR2HLS);
}

void someClass::Lab()
{
    if(inIm.channels() == 1)
        cv::cvtColor(inIm, inIm, CV_GRAY2BGR);
    cv::cvtColor(inIm, inIm, CV_BGR2Lab);
}

void someClass::Luv()
{
    if(inIm.channels() == 1)
        cv::cvtColor(inIm, inIm, CV_GRAY2BGR);
    cv::cvtColor(inIm, inIm, CV_BGR2Luv);
}


void someClass::flipV(int)
{
    cv::flip(inIm, inIm, 0);
}

void someClass::flipH(int d)
{
    cv::flip(inIm, inIm, 1);
}
void someClass::flipL(int d)
{
    cv::flip(inIm, inIm, -1);
}

void someClass::filter(int a)
{
    cv::filter2D(inIm, inIm, inIm.depth(), kernel, cv::Point(-1,-1), 0,  cv::BORDER_REFLECT_101);
}


void someClass::saltNpepper()
{

    //cv::filter2D(inIm, inIm, inIm.depth(), kernel, cv::Point(-1,-1), 0,  cv::BORDER_REFLECT_101);
    // std::cout<<kernel<<endl;

    cv::Mat saltPep = cv::Mat::zeros(inIm.rows, inIm.cols, CV_8U);
    cv::randu(saltPep, 0, 255);
    cv::Mat black = saltPep < 2;
    cv::Mat white = saltPep > 245;

    cv::Mat saltPepIm = inIm;
    saltPepIm.setTo(255, white);
    saltPepIm.setTo(0, black);
}

void someClass::gaussianNoise()
{
    cv::Mat gaussian_noise(inIm.size(), inIm.type());
    cv::randn(gaussian_noise, 0, 5);
    inIm += gaussian_noise;
    cv::Mat clamp1 = cv::Mat::ones(inIm.size(), inIm.type());
    cv::Mat clamp0 = cv::Mat::zeros(inIm.size(), inIm.type());
    inIm = cv::max(inIm, clamp0);
    inIm = cv::min(inIm, clamp1);
}

void someClass::canny(int cannyL, int cannyH)
{
    if(inIm.channels() == 3)
        this->gray();

    qDebug()<<cannyLowThresh<<cannyhighThresh;
    cv::Canny(inIm, inIm, cannyLowThresh, cannyhighThresh);
}

void someClass::sobel()
{
    cv::Mat sobelX, sobelY, sobelMagnitude, sobelOrientation;
    cv::Sobel(inIm,sobelX,CV_32F,1,0,aperature);
    cv::Sobel(inIm,sobelY,CV_32F,0,1,aperature);
    // Compute magnitude and orientation
    cv::cartToPolar(sobelX,sobelY,sobelMagnitude,sobelOrientation);
    if(option == 1){
        cv::Mat bin;
        sobelMagnitude.convertTo(bin, CV_8U);
        cv::threshold(bin, bin, thresh, 255, cv::THRESH_BINARY_INV);
        inIm = bin;
    }
    else if(option == 2){
        cv::Mat bin;
        sobelOrientation.convertTo(bin, CV_8U, 90.0/3.1415926);
        bin.copyTo(inIm);
    }
    else if(option == 3){ //sobel image
        cv::Mat bin;
        double minval, maxval;
        cv::minMaxLoc(sobelMagnitude, &minval, &maxval);
        sobelMagnitude.convertTo(bin, CV_8U, 255/maxval);
        inIm = bin;
    }
}

void someClass::blob(int option)
{

    std::vector<std::vector<cv::Point> > contours;
    vector<Vec4i> hierarchy;
    cv::Mat original;
    inIm.copyTo(original);
    this->gray();
    Canny(inIm, inIm, cannyLowThresh, cannyhighThresh, 3);
    RNG rng(12345);
    cv::findContours(inIm, contours, hierarchy,CV_RETR_LIST, CV_CHAIN_APPROX_NONE);

    int cmin = 100, cmax = 1000;
    std::vector<std::vector<cv::Point> >::iterator itc = contours.begin();
    while(itc != contours.end()){
        if(itc->size() < cmin || itc->size() > cmax)
            itc = contours.erase(itc);
        else
            ++itc;
    }

    if(option == 1){ //draw in original
        cv::drawContours(original, contours, -1, cv::Scalar(255,255,255), 2);
        inIm = original;
        return;
    }

    if(option == 2){    //draw binary
        inIm.convertTo(inIm, CV_8U);
        inIm = cv::Mat(inIm.size(), CV_8U, cv::Scalar(255));
        cv::drawContours(inIm, contours, -1, cv::Scalar(0), 2);
        return;
    }
    inIm.setTo(cv::Scalar(255));
    if(option == 3){

        cv::Rect r0= cv::boundingRect(cv::Mat(contours[0]));
        cv::rectangle(inIm,r0,cv::Scalar(0),2);
        return;
    }
    if(option == 4){
        // testing the enclosing circle
        //////////////////////////////////////////
        float radius;
        cv::Point2f center;
        cv::minEnclosingCircle(cv::Mat(contours[1]),center,radius);
        cv::circle(inIm,(center),static_cast<int>(radius),cv::Scalar(0),2);
        return;
    }
    if(option == 5){
        //////////////////////////////////////////
        std::vector<cv::Point> poly;
        cv::approxPolyDP(cv::Mat(contours[2]), poly, 5, true);

        std::vector<cv::Point>::iterator itp = poly.begin();
        while(itp != (poly.end()-1)){
            cv::line(inIm, *itp, *(itp+1), cv::Scalar(0), 2);
            ++itp;
        }

        cv::line(inIm, *(poly.begin()), *(poly.end()-1), cv::Scalar(20), 2);
        return;
    }
    //////////////////////////////////////////
    if(option == 6){
        std::vector<cv::Point> hull;
        cv::convexHull(cv::Mat(contours[3]), hull);
        std::vector<cv::Point>::iterator ith = hull.begin();
        while(ith!=(hull.end() - 1)){
            cv::line(inIm, *ith, *(ith + 1), cv::Scalar(0), 2);
            ++ith;
        }

        cv::line(inIm, *(hull.begin()), *(hull.end() - 1), cv::Scalar(20), 2);
        return;
    }
    //////////////////////////////////////////
    if(option == 7){
        itc = contours.begin();
        while(itc != contours.end()){
            cv::Moments mom = cv::moments(cv::Mat(*itc++));
            cv::circle(inIm, cv::Point(mom.m10/mom.m00, mom.m01/mom.m00),
                       2, cv::Scalar(0),2);
        }
        return;
    }
}

void someClass::laplacian(int kSize)
{
    cv::GaussianBlur(inIm, inIm, cv::Size(3,3), 0, 0, cv::BORDER_DEFAULT);
    if(inIm.channels() != 1)
        cvtColor(inIm, inIm, CV_RGB2GRAY);
    cv::Laplacian(inIm, inIm, CV_16S, kSize, 1, 0, cv::BORDER_DEFAULT);
    cv::convertScaleAbs(inIm, inIm);
}

void someClass::hough(int option, int cannyLowThresh, int cannyhighThresh ,
                      int minVotes, int minRad, int maxRad, int circDist)
{
    if(option == 1){
        cv::Mat contours;
        cv::Canny(inIm,contours,cannyLowThresh,cannyhighThresh);
        cv::Mat contoursInv;
        cv::threshold(contours,contoursInv,128,255,cv::THRESH_BINARY_INV);
        float PI = 3.1412956;
        std::vector<cv::Vec2f> lines;
        cv::HoughLines(contours,lines,1,PI/180,60);

        // Draw the lines
        cv::Mat result(contours.rows,contours.cols,CV_8U,cv::Scalar(255));
        inIm.copyTo(result);

        std::vector<cv::Vec2f>::iterator it= lines.begin();
        while (it!=lines.end()) {

            float rho= (*it)[0];   // first element is distance rho
            float theta= (*it)[1]; // second element is angle theta

            if (theta < PI/4. || theta > 3.*PI/4.) { // ~vertical line

                // point of intersection of the line with first row
                cv::Point pt1(rho/cos(theta),0);
                // point of intersection of the line with last row
                cv::Point pt2((rho-result.rows*sin(theta))/cos(theta),result.rows);
                // draw a white line
                cv::line( result, pt1, pt2, cv::Scalar(255), 1);

            } else { // ~horizontal line

                // point of intersection of the line with first column
                cv::Point pt1(0,rho/sin(theta));
                // point of intersection of the line with last column
                cv::Point pt2(result.cols,(rho-result.cols*cos(theta))/sin(theta));
                // draw a white line
                cv::line( result, pt1, pt2, cv::Scalar(255), 1);
            }

            ++it;
        }
        result.copyTo(inIm);
        return;
    }

    else if(option == 2){

        cv::Mat original;
        inIm.copyTo(original);
        gray();
        cv::GaussianBlur(inIm,inIm,cv::Size(5,5),1.5);
        std::vector<cv::Vec3f> circles;
        cv::HoughCircles(inIm, circles, CV_HOUGH_GRADIENT,
                         2,   // accumulator resolution (size of the image / 2)
                         circDist,  // minimum distance between two circles
                         cannyhighThresh, // Canny high threshold
                         minVotes, // minimum number of votes
                         minRad, maxRad); // min and max radius


        std::vector<cv::Vec3f>::iterator itc= circles.begin();
        while (itc!=circles.end()) {

            cv::circle(original,
                       cv::Point((*itc)[0], (*itc)[1]), // circle centre
                    (*itc)[2], // circle radius
                    cv::Scalar(0,0,255), // color
                    2); // thickness

            ++itc;
        }
        original.copyTo(inIm);
    }

}

void someClass::houghPLines(){
    vector<Vec4i> lines;
    cv::Mat contours;
    cv::Canny(inIm,contours,cannyLowThresh, cannyhighThresh);
    //     cv::Mat contoursInv;


    HoughLinesP( contours, lines, rho, CV_PI/180, thresh, minLineLength, maxLineGap );
    for( size_t i = 0; i < lines.size(); i++ )
    {
        line( inIm, Point(lines[i][0], lines[i][1]),
                Point(lines[i][2], lines[i][3]), Scalar(0,0,255), 1, 8 );
    }
    //    rho – Distance resolution of the accumulator in pixels.
    //    theta – Angle resolution of the accumulator in radians.
    //    threshold – Accumulator threshold parameter. Only those lines are returned that get enough votes ( >\texttt{threshold} ).
    //    minLineLength – Minimum line length. Line segments shorter than that are rejected.
    //    maxLineGap – Maximum allowed gap between poin
}

void someClass::fast()
{
    keypoints.clear();
    qDebug()<<featurePoints;
    cv::FastFeatureDetector fastFeat(featurePoints);
    fastFeat.detect(inIm, keypoints);
    cv::drawKeypoints(inIm, keypoints, inIm,cv::Scalar(255,255,255), cv::DrawMatchesFlags::DRAW_OVER_OUTIMG);
}

void someClass::surf()
{
    keypoints.clear();
    cv::SurfFeatureDetector surfFeat(featurePoints);
    surfFeat.detect(inIm, keypoints);
    cv::drawKeypoints(inIm, keypoints, inIm,cv::Scalar(255,255,255), cv::DrawMatchesFlags::DRAW_OVER_OUTIMG);
}

void someClass::sift()
{
    keypoints.clear();
    cv::SiftFeatureDetector siftFeat(featThresh, threshReduce);
    siftFeat.detect(inIm, keypoints);
    cv::drawKeypoints(inIm, keypoints, inIm,cv::Scalar(255,255,255), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
}

void someClass::mser()
{
    keypoints.clear();
    cv::MserFeatureDetector mserFeat;
    mserFeat.detect(inIm, keypoints);
    cv::drawKeypoints(inIm, keypoints, inIm,cv::Scalar(255,255,255), cv::DrawMatchesFlags::DRAW_RICH_KEYPOINTS);
}

void someClass::harris()
{
    hCorner->dectect(inIm);
    vector<cv::Point> keyPoints;
    hCorner->getCorners(keyPoints, .5);
    hCorner->drawOnImage(inIm, keyPoints,cv::Scalar(0,255,0), pSize, 2);
}

void someClass::morph_dilate()
{
    using namespace cv;

    Mat element = getStructuringElement( basicType,
                                         Size( 2*morph_size + 1, 2*morph_size+1 ),
                                         Point( morph_size, morph_size ) );
    dilate( inIm, inIm, element );
}

void someClass::morph_erode()
{
    using namespace cv;

    Mat element = getStructuringElement( basicType,
                                         Size( 2*morph_size + 1, 2*morph_size+1 ),
                                         Point( morph_size, morph_size ) );
    erode( inIm, inIm, element );
}

void someClass::morph_open()
{
    using namespace cv;
    Mat element = getStructuringElement( basicType, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
    morphologyEx( inIm, inIm, cv::MORPH_OPEN, element);
}

void someClass::morph_close()
{
    using namespace cv;
    Mat element = getStructuringElement( basicType, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
    morphologyEx( inIm, inIm, cv::MORPH_CLOSE, element);
}

void someClass::morph_gradient()
{
    using namespace cv;
    Mat element = getStructuringElement( basicType, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
    morphologyEx( inIm, inIm, cv::MORPH_GRADIENT, element);
}

void someClass::morph_tophat()
{
    using namespace cv;
    Mat element = getStructuringElement( basicType, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
    morphologyEx( inIm, inIm, cv::MORPH_TOPHAT, element);
}

void someClass::morph_blackhat()
{
    using namespace cv;
    Mat element = getStructuringElement( basicType, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
    morphologyEx( inIm, inIm, cv::MORPH_BLACKHAT, element);
}

void someClass::brightnessContrast()
{

    orig.copyTo(inIm);
    inIm.convertTo(inIm, -1, alpha, beta);

}

void someClass::whatsup()
{
}

void someClass::upSample()
{

    cv::pyrUp(inIm, inIm, cv::Size(inIm.cols*2, inIm.rows*2));
    qDebug()<<"up";


}
void someClass::downSample()
{ imshow("b4", inIm);
    cv::pyrDown(inIm, inIm,cv::Size(inIm.cols*1/2, inIm.rows*1/2));
    imshow("asdf", inIm);
}

void someClass::findFace()
{
    if(canFaceDetect){
        Mat grayFrame;
        std::vector<Rect> faces;
        if(inIm.channels() == 3)
            cvtColor(inIm, grayFrame, CV_BGR2GRAY);
        else
            inIm.copyTo(grayFrame);

        equalizeHist(grayFrame, grayFrame);
        face_cascade.detectMultiScale(grayFrame, faces, 1.1, 2, 0|CV_HAAR_SCALE_IMAGE, Size(30, 30));
        for(size_t i = 0; i < faces.size(); i++){
            //            qDebug()<<"ok";
            //            Point center( faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5 );
            //  ellipse( inIm, center, Size( faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar( 255, 0, 255 ), 4, 8, 0 );

            cv::rectangle(inIm, faces[i], Scalar(255, 0, 0), 2); //show detected face
            //now find eyes from the detected faces
            Mat faceROI = grayFrame(faces[i]);
            std::vector<Rect> eyes;
            eyes_cascade.detectMultiScale(faceROI,eyes, 1.1, 2, 0 |CV_HAAR_SCALE_IMAGE, Size(30, 30) );
            for(size_t j = 0; j < eyes.size(); j++){
                Point center(faces[i].x + eyes[j].x + eyes[j].x*0.5, faces[i].y + eyes[j].y + eyes[j].height*0.5);
                int radius = cvRound( (eyes[j].width + eyes[j].height)*0.25 );
                circle( inIm, center, radius, Scalar( 255, 0, 0 ), 4, 8, 0 );
            }
        }
        //        qDebug()<<"finding";
    }

}

void someClass::median()
{
    cv::medianBlur(inIm, inIm, 5);
}


void someClass::lowthresh(double a)
{

    cannyLowThresh = a;
}
void someClass::highthresh(double b)
{

    cannyhighThresh = b;
}
void someClass::minimumCircleDis(double d)
{
    circDist = 300;
}
void someClass::votes(double v)
{
    minVotes = v;
}
void someClass::minimumRadius(double r)
{
    minRad = r;
}
void someClass::maximumRadius(double r)
{
    maxRad = r;
}
void someClass::RHO(double h)
{
    rho = h;
}
void someClass::houghPthresh(double d)
{
    if(thresh <=0)
        thresh=1;
    return;
    thresh = d;
}
void someClass::minimumLineLength(double d)
{
    minLineLength = d;
}
void someClass::maximumLineGap(double d)
{
    maxLineGap = d;
}

void someClass::editKernel(double d)
{
    kUI = new customKernel;
    connect(this->kUI, SIGNAL(sendKernel(cv::Mat)), this, SLOT(setKernel(cv::Mat)));
    this->kUI->show();
}

void someClass::neighbourhood(double d)
{
    hCorner->neighbourhood = d;
}

void someClass::sobelMapSwitch(double d)
{

}

void someClass::sobelMode(double d)
{
    option = d;
}
void someClass::aperatureSize(double d)
{
    this->aperature = d;
    hCorner->aperature = d;
}

