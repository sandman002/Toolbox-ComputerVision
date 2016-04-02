#include <calibacam.h>

CalibACam::CalibACam(){
    cameraMatrix = Mat::eye(3, 3, CV_64F);

         cameraMatrix.at<double>(0,0) = 1.0;
         distCoeffs = Mat::zeros(8, 1, CV_64F);
         squareLength = 3.0;
}
