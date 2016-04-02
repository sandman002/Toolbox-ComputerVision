#include "kernel2d.h"

kernel2D::kernel2D()
{
}

void kernel2D::filter(cv::Mat &image, int i)
{
    switch(i){
    case 0:
        cv::blur(image, image, cvSize(size,size));

        break;
    case 1:
        cv::GaussianBlur(image, image, cvSize(size,size), .2, .2);
        break;
    case 2:
        cv::filter2D(image, image, image.depth(), kernel, cv::Point(-1,-1), 0,  cv::BORDER_REFLECT_101);
        break;
    }
}
