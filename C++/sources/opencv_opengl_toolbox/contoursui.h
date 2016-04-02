#ifndef CONTOURSUI_H
#define CONTOURSUI_H

#include <QDialog>

namespace Ui {
class contoursUI;
}

class contoursUI : public QDialog
{
    Q_OBJECT

public:
    explicit contoursUI(QWidget *parent = 0);
    ~contoursUI();
    int cannyMin, cannyMax;
    int laplaceKSize;
    int sobelAperature, sobelThresh;
    int minVotes, minRad, maxRad, minCircDist;
    int rho, thresh, minLen, maxGap;

private slots:
    void on_spinSobelApt_valueChanged(int arg1);

    void on_spinSobelThresh_valueChanged(int arg1);

    void on_spinLapKSize_valueChanged(int arg1);

    void on_spinCannyMin_valueChanged(int arg1);

    void on_spinCannyMax_valueChanged(int arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_spinMinRad_valueChanged(int arg1);

    void on_spinMaxRad_valueChanged(int arg1);

    void on_spinCircDist_valueChanged(int arg1);

    void on_spinrho_valueChanged(int arg1);

    void on_spinthresh_valueChanged(int arg1);

    void on_spinmin_valueChanged(int arg1);

    void on_spinmax_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::contoursUI *ui;
signals:
    void paramChanged();
};

#endif // CONTOURSUI_H
