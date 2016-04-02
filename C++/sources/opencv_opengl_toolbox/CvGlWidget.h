#ifndef CVGLWIDGET_H
#define CVGLWIDGET_H

#include <QGLWidget>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <QDebug>
#include <QMutex>
#include <QMouseEvent>
#include <QMenu>
#include <QRubberBand>
using namespace std;
class CvGlWidget : public QGLWidget
{
    Q_OBJECT
public:
    explicit CvGlWidget(QWidget *parent = 0);
    virtual QSize sizeHint () const;
    int w, h;
cv::Mat cvImage, inputImage;
QRubberBand *band;
QPoint origin;
bool moveBand;
QRect ROI;
int oriX, oriY; //native size;
double curImScale;

vector<vector<float> > histo;
vector<vector<float> > statistics;
double *hmax;
void buildHistogram();

/*threads*/
void process();
QMutex mutex;
void requestWork();
void abortWork();
/********/
void setImage(cv::Mat &camImage){this->cvImage = camImage;}

/*threads*/
bool working;
bool abort;
/********/

protected:
    void initializeGL();
    void paintGL();
    void resizeGL(int w, int h);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void updateScene();
    void renderImage();
public:
    bool sceneChanged; //scene redraw required
    bool rtClickContext;

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
    bool showImage(cv::Mat image);
    void showContextMenu(QPoint pos);
};

#endif // CVGLWIDGET_H
