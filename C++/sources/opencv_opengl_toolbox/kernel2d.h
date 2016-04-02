#ifndef KERNEL2D_H
#define KERNEL2D_H
#include<opencv2/core/core.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <QDebug>
/* opencv filter2d creation and convolution/correlation over image
 * */
class kernel2D
{
public:
    kernel2D();
    cv::Mat kernel;
    int size;
    void filter(cv::Mat &image, int i = 0);
    void getSize(int s){size = s;}
    void getKernel(cv::Mat m){kernel = m;}
};

#endif // KERNEL2D_H
