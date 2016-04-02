#ifndef SOMECLASS_H
#define SOMECLASS_H
#include <QMetaObject>
#include <QObject>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <vector>
#include <QString>
#include <QDebug>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/nonfree/features2d.hpp>
#include "opencv2/objdetect/objdetect.hpp"
#include "harriscorner.h"
#include "customkernel.h"
#include <iostream>
using namespace std;
class someClass:public QObject
{
    Q_OBJECT

public:
    cv::Mat inIm, orig;
    vector<int> commandList;
    someClass();
    someClass(QObject *parent): QObject(parent){
        kernel = cv::Mat::ones(3, 3, CV_32FC1);
        kernel = kernel/9;

        //for sift
        featThresh = 0.03; threshReduce = 10.0;
        featurePoints = 40;
        basicType = 0;
        morph_size = 5;
        hCorner = new HarrisCorner();
        alpha = 1.0;
        beta = 0;
        circDist = 300;  // minimum distance between two circle
            minVotes = 100; // minimum number of votes
            minRad = 200; maxRad = 400;
pSize = 2;
        rho = 1; thresh = 80; minLineLength = 30; maxLineGap = 10;
        //face detection module initialization
        canFaceDetect = true;
        option = 1;
        face_cascade_name = "haarcascade_frontalface_alt.xml";
        eyes_cascade_name = "haarcascade_eye_tree_eyeglasses.xml";
cannyLowThresh = 40; cannyhighThresh = 120;
        if( !face_cascade.load( face_cascade_name ) ){ canFaceDetect = false; };
        if( !eyes_cascade.load( eyes_cascade_name ) ){ canFaceDetect = false; };
    }

    /***********parameter stuffs***********/
    cv::Mat kernel;
    customKernel *kUI;
    vector<cv::KeyPoint> keypoints;
    double featThresh, threshReduce;
    unsigned int cannyLowThresh, cannyhighThresh;
    int rho, thresh, minLineLength, maxLineGap;
    int aperature;
    unsigned int featurePoints;
    int circDist,  // minimum distance between two circle
    minVotes, // minimum number of votes
    minRad, maxRad;
int pSize;
    int basicType;
    int morph_elem, morph_size;
    double alpha; //contrast //>=1
    int beta; //brightness
    HarrisCorner *hCorner;
    String face_cascade_name;
    String eyes_cascade_name;
    CascadeClassifier face_cascade;
    CascadeClassifier eyes_cascade;
    bool canFaceDetect;
int option;
public slots:
    void getAlphaBeta(double a, double b){
        alpha = a;
        beta = b;
    }

    void setKernel(cv::Mat m){kernel = m; std::cout<<m;}

    Q_INVOKABLE void gray(int =1);
    Q_INVOKABLE void YCrCb();
    Q_INVOKABLE void HSV();
    Q_INVOKABLE void HLS();
    Q_INVOKABLE void Lab();
    Q_INVOKABLE void Luv();
    Q_INVOKABLE void flipH(int =1);
    Q_INVOKABLE void flipV(int =1);
    Q_INVOKABLE void flipL(int =1);
    Q_INVOKABLE void filter(int =1);


    //noise
    Q_INVOKABLE void saltNpepper();
    Q_INVOKABLE void gaussianNoise();

    //contours
    Q_INVOKABLE void canny(int cannyLowThresh = 125, int cannyhighThresh = 350);
    Q_INVOKABLE void sobelMode(double option = 1);
    Q_INVOKABLE void sobel();
    Q_INVOKABLE void blob(int option = 1);
    Q_INVOKABLE void laplacian(int kSize = 3);
    Q_INVOKABLE void hough(int option = 1, int cannyLowThresh = 125, int cannyhighThresh = 350,
                           int minVotes = 100, int minRad=100, int MaxRad=300, int cirDist=80);

    Q_INVOKABLE void fast();
    Q_INVOKABLE  void surf();
    Q_INVOKABLE  void sift();
    Q_INVOKABLE   void mser();
    Q_INVOKABLE   void harris();

    Q_INVOKABLE void morph_dilate();
    Q_INVOKABLE   void morph_erode();
    Q_INVOKABLE  void morph_open();
    Q_INVOKABLE   void morph_close();
    Q_INVOKABLE   void morph_gradient();
    Q_INVOKABLE   void morph_tophat();
    Q_INVOKABLE   void morph_blackhat();
    void brightnessContrast();
    Q_INVOKABLE   void whatsup();
    Q_INVOKABLE void upSample();
    Q_INVOKABLE void downSample();
    Q_INVOKABLE void findFace();
    Q_INVOKABLE void median();
    Q_INVOKABLE void houghPLines();
    Q_INVOKABLE void lowthresh(double a);
    Q_INVOKABLE void highthresh(double b);
    Q_INVOKABLE void minimumCircleDis(double d);
    Q_INVOKABLE void votes(double v);
    Q_INVOKABLE void minimumRadius(double r);
    Q_INVOKABLE void maximumRadius(double r);
    Q_INVOKABLE void RHO(double h);
    Q_INVOKABLE void houghPthresh(double d);
    Q_INVOKABLE void minimumLineLength(double d);
    Q_INVOKABLE void maximumLineGap(double d);
    Q_INVOKABLE void editKernel(double d);
    Q_INVOKABLE void aperatureSize(double d);
    Q_INVOKABLE void neighbourhood(double d);
    Q_INVOKABLE void sobelMapSwitch(double d);

};
#endif // SOMECLASS_H
