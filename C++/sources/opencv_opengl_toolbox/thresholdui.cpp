#include "thresholdui.h"
#include "ui_thresholdui.h"

thresholdUI::thresholdUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::thresholdUI)
{
    ui->setupUi(this);
    ui->localSlider->setValue(128);
    ui->GlobalSlider->setValue(50);
    ui->horizontalSlider->setValue(5);
    localThresh = 128;
    globalThresh = 50;
    kernelSize = 5;
    borderType = 0;
}

thresholdUI::~thresholdUI()
{
    delete ui;
}

void thresholdUI::on_GlobalSlider_valueChanged(int value)
{
    localThresh = value;
}

void thresholdUI::on_localSlider_valueChanged(int value)
{
    globalThresh = value;
}

void thresholdUI::on_horizontalSlider_valueChanged(int value)
{
    kernelSize = value;
}

void thresholdUI::on_comboBox_currentIndexChanged(int index)
{
    borderType = index;
}
