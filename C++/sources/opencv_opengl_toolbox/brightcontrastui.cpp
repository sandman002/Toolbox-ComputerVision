#include "brightcontrastui.h"
#include "ui_brightcontrastui.h"
#include<QDebug>
brightContrastUI::brightContrastUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::brightContrastUI)
{
    ui->setupUi(this);
     alpha = 1;
     beta = 0;
}

brightContrastUI::~brightContrastUI()
{
    delete ui;
}

void brightContrastUI::on_horizontalSlider_sliderMoved(int position)
{

}

void brightContrastUI::on_horizontalSlider_2_sliderMoved(int position)
{

}

void brightContrastUI::on_horizontalSlider_valueChanged(int value)
{

    beta = value;
    sendalphabeta(alpha/100.0, beta);
}

void brightContrastUI::on_horizontalSlider_2_valueChanged(int value)
{
    alpha = value;
    sendalphabeta(alpha/100.0, beta);
}
