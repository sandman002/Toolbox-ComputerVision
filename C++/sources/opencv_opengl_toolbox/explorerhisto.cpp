#include "explorerhisto.h"
#include "ui_explorerhisto.h"
#include <QDebug>
ExplorerHisto::ExplorerHisto(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExplorerHisto)
{
    ui->setupUi(this);
//    setAttribute(Qt::WA_DeleteOnClose);

    sceneIntensity = new QGraphicsScene(this);
    sceneRed= new QGraphicsScene(this);
    sceneGreen = new QGraphicsScene(this);
    sceneBlue = new QGraphicsScene(this);
    ui->histoIntensity->setScene(sceneIntensity);
    ui->histoRed->setScene(sceneRed);
    ui->histoGreen->setScene(sceneGreen);
    ui->histoBlue->setScene(sceneBlue);
    ui->histoIntensity->scale(1,-1);
    ui->histoRed->scale(1,-1);
    ui->histoGreen->scale(1,-1);
    ui->histoBlue->scale(1,-1);
    ui->histogram->setCurrentIndex(0);
    tabIndex = 0;
    /***********setting flags**********/
    gotHistogram = false;
}

ExplorerHisto::~ExplorerHisto()
{
    delete ui;
}

void ExplorerHisto::paintEvent(QPaintEvent *e)
{

   sceneIntensity->clear(); sceneRed->clear();
   sceneBlue->clear(); sceneGreen->clear();
    //int w = ui->histoIntensity->width();
    int h = ui->histoIntensity->height();
    /********Pen*******/
    QPen grayPen(Qt::gray);
    QPen redPen(Qt::red);
    QPen greenPen(Qt::green);
    QPen bluePen(Qt::blue);

    if(histo.size() == 1){ //RGB
        for(int j = 0; j < histo[0].size(); j++)
            sceneIntensity->addLine(j+2,histo[0].at(j)*(h-80)/hmax[0], j+2, (55-h/2), redPen);
        return;
    }

    if(histo.size() == 4){ //BGR image; R => 3 G => 2 B => 1
        for(int j = 0; j < histo[3].size()-1; j++)
            sceneRed->addLine(j+2, (80 - h/2), j+2,histo[3].at(j)*(h-80)/hmax[3], redPen);

        for(int j = 0; j < histo[2].size()-1 ; j++)
            sceneGreen->addLine(j+2, (80-h/2), j+2,histo[2].at(j)*(h-80)/hmax[2], greenPen);

        for(int j = 0; j < histo[1].size() -1; j++)
            sceneBlue->addLine(j+2, (80-h/2), j+2,  histo[1].at(j)*(h-80)/hmax[1], bluePen);

        for(int j = 0; j < histo[0].size() -1; j++)
            sceneIntensity->addLine(j+2,(80-h/2), j+2,  histo[0].at(j)*(h-80)/hmax[0] , grayPen);

    }

    setColorBar(histo.size());
}

//void ExplorerHisto::setWindowTitle(const QString &d)
//{
//    setWindowTitle(d);
//}

void ExplorerHisto::buildHistogram(vector<vector<float> > histData,
                                   vector<vector<float> > statData,
                                   double *maxData)
{
    histo = histData;
    statistics = statData;
    hmax = maxData;
    gotHistogram = true;

}



void ExplorerHisto::setColorBar(int N)
{
    int h = ui->histoIntensity->height();
    QPen barPen(QColor(0,0,0));
    if(N == 1){

        for(int j = 0; j < 255; j++){
            barPen.setColor(QColor(j,j,j));
            sceneIntensity->addLine(j+2, 60-h/2 , j+2, -h/2+75, barPen);
        }
        return;
    }
    else if(N == 4){
        for(int j = 0; j < 255; j++){
            barPen.setColor(QColor(j,0,0)); //Red
            sceneRed->addLine(j+2, 60-h/2 , j+2, -h/2+75, barPen);
        }
        for(int j = 0; j < 255; j++){
            barPen.setColor(QColor(0,0,j)); //blue
            sceneBlue->addLine(j+2, 60-h/2 , j+2, -h/2+75, barPen);
        }
        for(int j = 0; j < 255; j++){
            barPen.setColor(QColor(0,j,0)); //green
            sceneGreen->addLine(j+2, 60-h/2 , j+2, -h/2+75, barPen);
        }

        for(int j = 0; j < 255; j++){
            barPen.setColor(QColor(j,j,j));
            sceneIntensity->addLine(j+2, 60-h/2 , j+2, -h/2+75, barPen);
        }
    }

}

void ExplorerHisto::clearHistoData()
{
    if(histo.empty()) return;
    else histo.clear();
    if(statistics.empty()) return;
    else statistics.clear();
}


void ExplorerHisto::on_histogram_tabBarClicked(int index)
{
    double sum = 0;
    tabIndex = index;
    if(!gotHistogram) return;
    for (int j = 0; j < 256; j++)
        sum += histo[0].at(j);
    ui->totalCount->setText(QString::number(sum));
    if(statistics.empty()) return;

    if(index==0){
            ui->Mean->setText(QString::number((statistics[0].at(0))));
            ui->sd->setText(QString::number((statistics[0].at(1))));
    }

    if(histo.size() == 4){
        ui->histogram->setTabEnabled(1, 1);
        ui->histogram->setTabEnabled(2, 1);
        ui->histogram->setTabEnabled(3, 1);
//        ui->Mean->setText(QString::number((statistics[4-index].at(0))));
//        ui->sd->setText(QString::number((statistics[4-index].at(1))));
    if(index==1){
        ui->Mean->setText(QString::number((statistics[3].at(0))));
        ui->sd->setText(QString::number((statistics[3].at(1))));
    }
    else if(index==2){
        ui->Mean->setText(QString::number((statistics[2].at(0))));
        ui->sd->setText(QString::number((statistics[2].at(1))));
    }
    else if(index==3){
        ui->Mean->setText(QString::number((statistics[1].at(0))));
        ui->sd->setText(QString::number((statistics[1].at(1))));
    }
    }
    else
    {
        ui->histogram->setTabEnabled(1, 0);
        ui->histogram->setTabEnabled(2, 0);
        ui->histogram->setTabEnabled(3, 0);
    }

    //ui->levelCount->setText(QString::number(histo[tabIndex].at(ui->grayValue->value())));
}



void ExplorerHisto::on_grayValue_valueChanged(int arg1)
{
    if(ui->histogram->currentIndex() == 0)
        ui->levelCount->setText(QString::number(histo[0].at(arg1)));
    else
        ui->levelCount->setText(QString::number(histo[4-tabIndex].at(arg1)));
}
