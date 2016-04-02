#ifndef MORPHPROCESS_H
#define MORPHPROCESS_H
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QDebug>
using namespace cv;
class morphProcess
{

public:
    morphProcess();

    int morph_elem;
    int morph_size ;
    int morph_operator ;
    int  max_operator ;
    int max_elem ;
    int max_kernel_size ;
    int basicType;
    int iteration;
    void Morph(Mat &, int);
    void setElemNSize(int elem = 2 , int size = 3, int iterations = 1);
};

#endif // MORPHPROCESS_H
