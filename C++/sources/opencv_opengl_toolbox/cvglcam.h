#ifndef CVGLCAM_H
#define CVGLCAM_H

#include <QGLWidget>
#include <QMutex>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

class CvGlCam : public QGLWidget
{
    Q_OBJECT
public:
    explicit CvGlCam(QWidget *parent);
    virtual QSize sizeHint () const;
      int w, h;
    cv::Mat cvImage, original;
    /*threads*/
    void process();
    QMutex mutex;
    void requestWork();
    void abortWork();
    /********/
        void setImage(cv::Mat &);
protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);

    void updateScene();
    void renderImage();

private:
    bool sceneChanged; //scene redraw required
    /*threads*/
    bool working;
    bool abort;
    /********/

    QImage renderQtImage;


    QColor bgColor;
    int hImg; int wImg; //ht and width of the image
    float imgRatio;
    int imgPosX, imgPosY; //top left x and y of rendered image

signals:
    void imageSizeChanged(int imageW, int imageH);
    /*threads*/
    void finished();
    void workRequested();
    /********/

public slots:

    bool showImage();
signals:

public slots:

};

#endif // CVGLCAM_H
