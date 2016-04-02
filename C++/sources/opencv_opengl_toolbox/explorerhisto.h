#ifndef EXPLORERHISTO_H
#define EXPLORERHISTO_H

#include <QDialog>
#include "QPainter"
#include <vector>
#include <QGraphicsScene>
//#include <QCloseEvent>
//#include <QGuiApplication>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace std;
namespace Ui {
class ExplorerHisto;
}

class ExplorerHisto : public QDialog
{
    Q_OBJECT

public:
    explicit ExplorerHisto(QWidget *parent = 0);
    ~ExplorerHisto();

private:
    Ui::ExplorerHisto *ui;
    QGraphicsScene *sceneIntensity, *sceneRed, *sceneBlue, *sceneGreen;
    vector<vector<float> > histo;
    vector<vector<float> > statistics;
    void paintEvent(QPaintEvent *e);
  //  void setWindowTitle(const QString &d);
    double *hmax;
    int tabIndex; //Qt's index order not working  wierd!!!
public:
    /**************flags**************/
    bool gotHistogram;
    void buildHistogram(vector<vector<float> > histData,
                        vector<vector<float> > statData,
                        double *maxData);
    void setColorBar(int);
    void clearHistoData();
protected:
//    void closeEvent ( QCloseEvent *event ) {
//    event->ignore();
//    //QMessageBox::information( this, "Close?", "Close? No way!" );
//    }

private slots:
    void on_histogram_tabBarClicked(int index);

    void on_grayValue_valueChanged(int arg1);
};

#endif // EXPLORERHISTO_H
