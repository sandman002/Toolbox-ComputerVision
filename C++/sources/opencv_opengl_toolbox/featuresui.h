#ifndef FEATURESUI_H
#define FEATURESUI_H

#include <QDialog>

namespace Ui {
class featuresUI;
}

class featuresUI : public QDialog
{
    Q_OBJECT

public:
    explicit featuresUI(QWidget *parent = 0);
    ~featuresUI();

    double hNeigh, hApert, hMaxStr, hThresh, hPara, siftThresh, edgeThresh, gThresh;
    int pSize;

private slots:
    void on_hNeigh_valueChanged(int arg1);

    void on_hAperature_valueChanged(int arg1);

    void on_hMaxStr_valueChanged(double arg1);

    void on_hThresh_valueChanged(double arg1);

    void on_hParam_valueChanged(double arg1);

    void on_siftThresh_valueChanged(double arg1);

    void on_edgeThresh_valueChanged(double arg1);

    void on_gthresh_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_spinSize_valueChanged(int arg1);

private:
    Ui::featuresUI *ui;
signals:
    void sendParams();
};

#endif // FEATURESUI_H
