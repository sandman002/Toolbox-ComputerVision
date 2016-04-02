#include "contoursui.h"
#include "ui_contoursui.h"

contoursUI::contoursUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::contoursUI)
{
    ui->setupUi(this);
    cannyMax = ui->spinCannyMax->value();
    cannyMin = ui->spinCannyMin->value();
    sobelAperature = ui->spinSobelApt->value();
    sobelThresh = ui->spinSobelThresh->value();
    laplaceKSize = ui->spinLapKSize->value();
    minRad = ui->spinMinRad->value();
    maxRad = ui->spinMaxRad->value();
    minVotes = ui->spinVotes->value();
    minCircDist = ui->spinCircDist->value();
    rho = ui->spinrho->value();
    thresh = ui->spinthresh->value();
    minLen = ui->spinmin->value();
    maxGap = ui->spinmax->value();
}

contoursUI::~contoursUI()
{
    delete ui;
}

void contoursUI::on_spinSobelApt_valueChanged(int arg1)
{
    sobelAperature = arg1;
}

void contoursUI::on_spinSobelThresh_valueChanged(int arg1)
{
    sobelThresh = arg1;
}

void contoursUI::on_spinLapKSize_valueChanged(int arg1)
{
    laplaceKSize = arg1;
}

void contoursUI::on_spinCannyMin_valueChanged(int arg1)
{
    cannyMin = arg1;
}

void contoursUI::on_spinCannyMax_valueChanged(int arg1)
{
    cannyMax = arg1;
}

void contoursUI::on_spinBox_valueChanged(int arg1)
{
    minVotes = arg1;
}

void contoursUI::on_spinMinRad_valueChanged(int arg1)
{
    minRad = arg1;
}

void contoursUI::on_spinMaxRad_valueChanged(int arg1)
{
    maxRad = arg1;
}

void contoursUI::on_spinCircDist_valueChanged(int arg1)
{
    minCircDist = arg1;
}

void contoursUI::on_spinrho_valueChanged(int arg1)
{
    rho = arg1;
}

void contoursUI::on_spinthresh_valueChanged(int arg1)
{
    thresh = arg1;
}

void contoursUI::on_spinmin_valueChanged(int arg1)
{
    minLen = arg1;
}

void contoursUI::on_spinmax_valueChanged(int arg1)
{
    maxGap = arg1;
}

void contoursUI::on_pushButton_clicked()
{
    emit paramChanged();
}
