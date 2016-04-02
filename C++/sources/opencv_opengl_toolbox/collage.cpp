#include "collage.h"

collage::collage()
{
        morp = new morphProcess();
        k2D = new kernel2D();

}

collage::~collage()
{
    delete morp;
    delete k2D;
}



void collage::morph(int i)
{

    morp->Morph(im, i);

}

void collage::filter2(int i)
{
    k2D->filter(im, i);
}
