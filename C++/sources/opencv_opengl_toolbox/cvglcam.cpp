#include "cvglcam.h"

CvGlCam::CvGlCam(QWidget *parent) :
    QGLWidget(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    w = parent->width()/3; h = parent->height()/3; //intialize widget size to 1/3 of parent size
    sizeHint();
    sceneChanged = false;
    bgColor = QColor::fromRgb(150,150,150);

    hImg = 0; wImg = 0;
    imgRatio = 4.0/3.0f;
    imgPosX = 0; imgPosY = 0;

    working = false;
    abort = false;
}

QSize CvGlCam::sizeHint() const
{
    return QSize(w, h);
}

void CvGlCam::process()
{

}

void CvGlCam::requestWork()
{
    mutex.lock();
    working = true;
    abort = false;
    mutex.unlock();
    emit workRequested();
}

void CvGlCam::abortWork()
{
    if(working)
        abort = true;
}

void CvGlCam::initializeGL()
{
    glClearColor(0.5f, 0.5f, 0.5f, 100.0f);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

//updating routine
void CvGlCam::updateScene(){
    if(sceneChanged && this->isVisible()) updateGL();
}

void CvGlCam::paintGL(){
    glColor3f(128, 0, 0);
    glBegin(GL_POLYGON);
    glVertex3d(30,30, 1);
    glVertex3d(30, 40, 1);
    glVertex3d(40, 40, 1);
    glVertex3d(40, 30, 1);
    glEnd();

    if(!sceneChanged) return;
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    renderImage();
    sceneChanged = false;
}

void CvGlCam::resizeGL(int w, int h){

    glViewport(0, 0, (GLint)w, (GLint)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, 0, 1); //think about this later

    glMatrixMode(GL_MODELVIEW);

    hImg = w/imgRatio;
    wImg = w;

    if(hImg > h){
        wImg = h*imgRatio;
        hImg = h;
    }
    emit imageSizeChanged(wImg, hImg);
    imgPosX = (w - wImg)/2;
    imgPosY = (h - hImg)/2;

    sceneChanged = true;
    updateScene();
}

void CvGlCam::renderImage(){

    glClear(GL_COLOR_BUFFER_BIT);
    if(!renderQtImage.isNull()){
        glLoadIdentity();
        QImage image;   //temporary purpose

        glPushMatrix();{
            int imageWidth = renderQtImage.width();
            int imageHeight = renderQtImage.height();

            if(imageWidth != this->size().width() &&
                    imageHeight != this->size().height()){
                image = renderQtImage.scaled(QSize(wImg, hImg),
                                             Qt::IgnoreAspectRatio,
                                             Qt::SmoothTransformation);
            }
            else
                image = renderQtImage;

            glRasterPos2i(imgPosX, imgPosY);
            imageWidth = image.width();
            imageHeight = image.height();
            //now we draw HAHAHAHA!!
            glDrawPixels(imageWidth, imageHeight, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());

        }
        glPopMatrix();

        glFlush();
    }
}

void CvGlCam::setImage(cv::Mat &camImage)
{
    this->cvImage = camImage;
}

bool CvGlCam::showImage(){
    /*************threads*************/
    mutex.lock();
    bool missionAbort = abort;
    mutex.unlock();
    if(missionAbort) return false; //don't do any work
    /**********************************/


    imgRatio = (float)cvImage.cols/(float)cvImage.rows;

    if(cvImage.channels() == 3){
        renderQtImage = QImage((const unsigned char*)(cvImage.data), cvImage.cols,
                               cvImage.rows, cvImage.step, QImage::Format_RGB888).rgbSwapped();
    }
    else if(cvImage.channels() == 1){
        renderQtImage = QImage((const unsigned char*)(cvImage.data), cvImage.cols,
                               cvImage.rows, cvImage.step, QImage::Format_Indexed8);

    }
    else
        return false;

    renderQtImage = QGLWidget::convertToGLFormat(renderQtImage);//some qtgl function
    sceneChanged = true;
    resizeGL(this->width(), this->height());
    updateScene();
    mutex.lock();
    working = false;
    mutex.unlock();

    emit finished();

    return true;

}
