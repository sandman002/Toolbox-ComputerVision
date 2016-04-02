#include "featuresui.h"
#include "ui_featuresui.h"

featuresUI::featuresUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::featuresUI)
{
    ui->setupUi(this);
    hNeigh = 3; hApert =3 ; hMaxStr = 0.5;
    hThresh = 10; siftThresh = 0.03; edgeThresh = 10; gThresh = 40;
    ui->edgeThresh->setValue(0.03);
    ui->gthresh->setValue(40);
    ui->hAperature->setValue(3);
    ui->hNeigh->setValue(3);
    ui->hMaxStr->setValue(0.5);
    ui->hParam->setAccelerated(0.01);
    ui->hThresh->setValue(10);
}

featuresUI::~featuresUI()
{
    delete ui;
}

void featuresUI::on_hNeigh_valueChanged(int arg1)
{
    hNeigh = arg1;
}

void featuresUI::on_hAperature_valueChanged(int arg1)
{
    hApert = arg1;
}

void featuresUI::on_hMaxStr_valueChanged(double arg1)
{
    hMaxStr = arg1;
}

void featuresUI::on_hThresh_valueChanged(double arg1)
{
    hThresh = arg1;
}

void featuresUI::on_hParam_valueChanged(double arg1)
{
    hPara = arg1;
}

void featuresUI::on_siftThresh_valueChanged(double arg1)
{
    siftThresh = arg1;
}

void featuresUI::on_edgeThresh_valueChanged(double arg1)
{
    edgeThresh = arg1;
}

void featuresUI::on_gthresh_valueChanged(int arg1)
{
    gThresh = arg1;
}

void featuresUI::on_pushButton_clicked()
{
    emit sendParams();
}

void featuresUI::on_spinSize_valueChanged(int arg1)
{
    pSize = arg1;
}
