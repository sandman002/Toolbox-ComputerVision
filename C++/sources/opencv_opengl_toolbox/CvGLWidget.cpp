#include "CvGlWidget.h"
CvGlWidget::CvGlWidget(QWidget *parent) :
    QGLWidget(parent)
{
    setAttribute(Qt::WA_DeleteOnClose);
    w = parent->width()/3; h = parent->height()/3; //intialize widget size to 1/3 of parent size
    sizeHint();
    sceneChanged = false;
    bgColor = QColor::fromRgb(150,150,150);
    // setBaseSize(parent->width()/3, parent->height()/3);
    // setGeometry(2, 2, 100, 40);
    hImg = 0; wImg = 0;
    imgRatio = 4.0/3.0f;
    imgPosX = 0; imgPosY = 0;
    setObjectName("view");
    band = new QRubberBand(QRubberBand::Rectangle, this);
    QPalette bandStyle;
    bandStyle.setBrush(QPalette::Foreground, QBrush(Qt::white));
    bandStyle.setBrush(QPalette::Base, QBrush(Qt::green));
    band->setPalette(bandStyle);
    moveBand = false;
rtClickContext = false;


}

void CvGlWidget::initializeGL(){

    glClearColor(0.5f, 0.5f, 0.5f, 100.0f);
    glEnable (GL_BLEND);
    glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

//updating routine
void CvGlWidget::updateScene(){
    if(sceneChanged && this->isVisible()) updateGL();
}

void CvGlWidget::paintGL(){
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

void CvGlWidget::resizeGL(int w, int h){

    glViewport(0, 0, (GLint)w, (GLint)h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, w, 0, h, 0, 1); //it's image, no 3D so perspective not necessary

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

    curImScale = oriX/wImg; //reduce scale


    sceneChanged = true;
    updateScene();
}

void CvGlWidget::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton){
        origin = e->pos();
        //    origin.setX( e->pos().x() - imgPosX);
        //    origin.setY( e->pos().y() - imgPosY);
        band->setGeometry(QRect(origin, QSize()));
        band->show();
    }
    else if(e->button() == Qt::RightButton){
        this->setContextMenuPolicy(Qt::CustomContextMenu);
        connect(this, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(showContextMenu(QPoint)));
    }

}

void CvGlWidget::mouseMoveEvent(QMouseEvent *e)
{
    //    QPoint pos;
    //    pos.setX( e->pos().x() - imgPosX);
    //    pos.setY( e->pos().y() - imgPosY);
    band->setGeometry(QRect(origin, e->pos()).normalized());
}

void CvGlWidget::mouseReleaseEvent(QMouseEvent *e)
{

    ROI.setX(band->geometry().x() - imgPosX);
    ROI.setY(band->geometry().y() - imgPosY);
    ROI.setWidth(band->geometry().width());
    ROI.setHeight(band->geometry().height());

    if(ROI.x() < 0 || ROI.y() < 0) //sanity check
    {
        band->hide();
    }

}
//rendering routine; not doing this thing in paint GL ;D

void CvGlWidget::renderImage(){

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

bool CvGlWidget::showImage(cv::Mat image){
    image.copyTo(cvImage);
    imgRatio = (float)image.cols/(float)image.rows;

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

    return true;

}

void CvGlWidget::showContextMenu(QPoint pos)
{

}

QSize CvGlWidget::sizeHint() const
{
    return QSize(w, h);
}

void CvGlWidget::buildHistogram()
{
    using namespace cv;


    int nc = cvImage.channels();
    vector<vector<float> > hist(nc+1, vector<float> (256));
    Mat temp;
    qDebug()<<"histogram here";
    if(nc == 3){
        for (int i = 0; i < cvImage.rows; i++)
        {
            for (int j = 0; j < cvImage.cols; j++)
            {
                for (int k = 0; k < nc; k++)
                {
                    uchar val = cvImage.at<Vec3b>(i,j)[k];
                    hist[k+1].at(val) += 1;
                }
            }
        }
        cvtColor(cvImage, temp, CV_BGR2GRAY);
    }
    else
        temp = cvImage;
    for (int i = 0; i < temp.rows; i++)
    {
        for (int j = 0; j < temp.cols; j++)
        {
                uchar val = temp.at<uchar>(i,j);
                hist[0].at(val) += 1;
        }
    }



    histo.clear();
    histo = hist;
    // qDebug()<<histo.size();
    /*************for statistics************/
    vector<vector<float> > stats(nc+1, vector<float> (2));    //mean and standard deviation

    for (int k = 0; k < nc+1; k++)
    {
        for (int i = 0; i < cvImage.rows; i++)
        {
            for (int j = 0; j < cvImage.cols; j++)
            {
                uchar val = nc == 1 ? cvImage.at<uchar>(i,j) : cvImage.at<Vec3b>(i,j)[k];
                stats[k].at(0) += (float)val;
            }
        }
        stats[k].at(0) /= cvImage.rows*cvImage.cols;

    }

    for (int k = 0; k < nc+1; k++)
    {
        for (int i = 0; i < cvImage.rows; i++)
        {
            for (int j = 0; j < cvImage.cols; j++)
            {
                uchar val = nc == 1 ? cvImage.at<uchar>(i,j) : cvImage.at<Vec3b>(i,j)[k];
                stats[k].at(1) += std::pow(((float)val - stats[k].at(0)),2);
            }
        }
        stats[k].at(1) /= cvImage.rows*cvImage.cols;
        stats[k].at(1) = std::sqrt(stats[k].at(1));
    }
    statistics.clear();
    statistics = stats;

    /**********find max of all channels**********/
    hmax = new double[nc+1];
    /*****find max value to normalize*****/
    for (int i = 0; i < nc+1; i++)
    {
        for (int j = 0; j < 255; j++)
            hmax[i] = histo[i].at(j) > hmax[i] ? histo[i].at(j) : hmax[i];
        //  qDebug()<<hmax[i];
    }

}

void CvGlWidget::requestWork()
{
    mutex.lock();
    working = true;
    abort = false;
    mutex.unlock();
    emit workRequested();
}


void CvGlWidget::abortWork()
{
    if(working)
        abort = true;
}






