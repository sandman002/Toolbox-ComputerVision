#include "morphprocess.h"

morphProcess::morphProcess()
{
     morph_elem = 2;
     morph_size = 4;
     morph_operator = 0;
     max_operator = 4;
     max_elem = 2;
     max_kernel_size = 21;
     basicType = 0;

}

void morphProcess::Morph(cv::Mat &src, int i)
{



    if(i == 0){ //dilate
        int dilation_type;
          if( basicType == 0 ){ dilation_type = MORPH_RECT; }
          else if( basicType == 1 ){ dilation_type = MORPH_CROSS; }
          else if( basicType == 2) { dilation_type = MORPH_ELLIPSE; }

          Mat element = getStructuringElement( dilation_type,
                                               Size( 2*morph_size + 1, 2*morph_size+1 ),
                                               Point( morph_size, morph_size ) );

          dilate( src, src, element );
    }
    else if( i == 1){

        int erosion_type;
       // qDebug()<<basicType;
       // cv::flip(src, src, -1);
          if( basicType == 0 ){ erosion_type = MORPH_RECT; }
          else if( basicType == 1 ){ erosion_type = MORPH_CROSS; }
          else if( basicType == 2) { erosion_type = MORPH_ELLIPSE; }
          Mat element = getStructuringElement( erosion_type,
                                               Size( 2*morph_size + 1, 2*morph_size+1 ),
                                               Point( morph_size, morph_size ) );

          erode( src, src, element );
    }
    else{
    Mat element = getStructuringElement( morph_elem, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );
     /// Apply the specified morphology operation
     morphologyEx( src,src, i, element );
    }

}

void morphProcess::setElemNSize(int elem, int size, int iterations)
{
    morph_elem = elem;
    morph_size = size;
    iteration = iterations;
}
