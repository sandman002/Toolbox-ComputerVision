#ifndef COLLAGE_H
#define COLLAGE_H
#include <QObject>
#include <morphprocess.h>
#include <kernel2d.h>
#include <QDebug>
using namespace cv;
class collage : public QObject
{
   Q_OBJECT
public:
    collage();
    collage(QObject *parent): QObject(parent){   morp = new morphProcess();
                                                 k2D = new kernel2D();
                                                      qDebug()<<"fall like rain";}
    ~collage();


    Mat im;
    morphProcess *morp;
    kernel2D *k2D;

public slots:
    void morph(int i);
    void filter2(int i);

};

#endif // COLLAGE_H
