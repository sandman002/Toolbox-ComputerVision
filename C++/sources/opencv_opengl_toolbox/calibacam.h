#ifndef CALIBACAM_H
#define CALIBACAM_H
#include <opencv2/calib3d/calib3d.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <vector>
#include <qdebug.h>
using namespace std;
using namespace cv;
class CalibACam
{
public:
    CalibACam();
    vector<vector <Point3f> > objectPoints;
    vector<vector <Point2f> > imagePoints;
    vector<int> point_counts;
    Size imageSize;
    Mat cameraMatrix;
    Mat distCoeffs;
    vector<Mat> rotationVecs;
    vector<Mat> translationVecs;
    float squareLength;
    Mat image, map1, map2;
    Mat chessImage;

    int flag;
    bool findChessboard(Mat& img, Size& boardSize){
        vector<Point2f> imageCorners;
        vector<Point3f> objectCorners;
        for(int i = 0; i<boardSize.height;i++){
            for(int j = 0; j < boardSize.width; j++){
                objectCorners.push_back(Point3f(float(i)*squareLength,  //square length written in the constructor
                                        float(j)*squareLength, 0.0f));
            }
        }
        int success = 0;
        image = img;
        image.copyTo(chessImage);
        imageSize = image.size();
        bool found = findChessboardCorners(image, boardSize, imageCorners);
        if(found){
            Mat gray;
            cvtColor(image, gray, CV_BGR2GRAY);
        cornerSubPix(gray, imageCorners, Size(5,5), Size( -1, -1 ),
                     TermCriteria( CV_TERMCRIT_ITER | CV_TERMCRIT_EPS, 20, 0.03 ) );}
        if(imageCorners.size() == boardSize.area()){
            imagePoints.push_back(imageCorners);
            objectPoints.push_back(objectCorners);
            success++;
        }
        qDebug()<<imageCorners.size();
        drawChessboardCorners(chessImage, boardSize, imageCorners, found);
      //  imshow("asdfasf", chessImage);
        return found;
    }

    double calibrate(){
        return cv::calibrateCamera(objectPoints,
                                    imagePoints,
                                    imageSize,
                                    cameraMatrix,
                                    distCoeffs,
                                    rotationVecs,
                                    translationVecs,
                                     CV_CALIB_FIX_ASPECT_RATIO|CV_CALIB_FIX_K4|CV_CALIB_FIX_K5
                                    );
    }


    void remap(const cv::Mat &image, cv::Mat &undistorted){
                cv::initUndistortRectifyMap(
                    cameraMatrix,
                    distCoeffs,
                    cv::Mat(),
                    cameraMatrix,
                    image.size(),
                    CV_32FC1,
                    map1,map2);

            cv::remap(image,undistorted,map1,map2,cv::INTER_LINEAR);
            imshow("undistorted", undistorted);
        }

    double computeReprojectionErrors()
    {
    vector<Point2f> imagePoints2;
    int i, totalPoints = 0;
    double totalErr = 0, err;

    for( i = 0; i < (int)objectPoints.size(); ++i )
    {
      projectPoints( Mat(objectPoints[i]), rotationVecs[i], translationVecs[i], cameraMatrix,
                                           distCoeffs, imagePoints2);
      err = norm(Mat(imagePoints[i]), Mat(imagePoints2), CV_L2);
      int n = (int)objectPoints[i].size();

      totalErr        += err*err;
      totalPoints     += n;
    }

    return std::sqrt(totalErr/totalPoints);              // calculate the arithmetical mean
    }

};

#endif // CALIBACAM_H
