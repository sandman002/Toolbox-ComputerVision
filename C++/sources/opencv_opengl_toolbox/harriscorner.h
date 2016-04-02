#ifndef HARRISCORNER_H
#define HARRISCORNER_H
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QDebug>
using namespace cv;
class HarrisCorner
{

public:
    Mat cornerStrength;
    Mat cornerTh;
    Mat localMax;
    
    int neighbourhood;
    int aperature;
    double k;
    double maxStrength;
    double threshold;
//    int nonMaxSize; //kernel for non-max suppression
    Mat kernel;

    HarrisCorner() : neighbourhood(3), aperature(3),
        k(0.01), maxStrength(0.0),
        threshold(0.01)/*, nonMaxSize(3)*/ {

    }
    void dectect(const cv::Mat& image){
        cv::Mat gray;
        if(image.channels() == 3)
            cvtColor(image, gray, CV_BGR2GRAY);
        else
            image.copyTo(gray);
        cv::cornerHarris(gray, cornerStrength,
                         neighbourhood,
                         aperature,
                         k);
        double minStrength;
        cv::minMaxLoc(cornerStrength,
                      &minStrength, &maxStrength);

        cv::Mat dilated;
        cv::dilate(cornerStrength, dilated, cv::Mat());
        cv::compare(cornerStrength, dilated, localMax,
                    cv::CMP_EQ);
    }
    
    /*returns binary corner map of detected features
    * use different threshold here without repeating
    * harriscorner routine
    * ************/
    cv::Mat getCornerMap(double qualityLevel){
        cv::Mat cornerMap;

        //thresholding the corner strength
        threshold = qualityLevel*maxStrength;
        cv::threshold(cornerStrength, cornerTh, threshold, 255, cv::THRESH_BINARY);
        cornerTh.convertTo(cornerMap, CV_8U);
        
        //non-maxima suppression
        cv::bitwise_and(cornerMap, localMax, cornerMap);

        return cornerMap;
    }
    
    void getCorners(std::vector<cv::Point> &points, double qualityLevel){
        cv::Mat cornerMap = getCornerMap(qualityLevel);
        for(int y = 0; y < cornerMap.rows; y++){
            const uchar* rowPtr = cornerMap.ptr<uchar>(y);
            for(int x = 0; x < cornerMap.cols; x++){
                if(rowPtr[x]){
                    points.push_back(cv::Point(x,y));
                }
            }
        }
    }
    
    void drawOnImage(cv::Mat &image, const std::vector<cv::Point> &points,
                     cv::Scalar color = cv::Scalar(255,255,255),
                     int radius = 3, int thickness = 2){
        std::vector<cv::Point>::const_iterator it = points.begin();
        while(it != points.end()){
            cv::circle(image, *it, radius, color, thickness);
            it++;
        }
    }

};

#endif // HARRISCORNER_H
