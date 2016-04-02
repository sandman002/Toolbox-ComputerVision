#include "fundoptui.h"
#include "ui_fundoptui.h"

fundOptUI::fundOptUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::fundOptUI)
{
    ui->setupUi(this);
    ransacConf = ui->spinConfidence->value();
    ransacDist = ui->spinDist->value();
    ransacNN = ui->spinNN->value();
    d = ui->methodcombo->currentIndex();
}

fundOptUI::~fundOptUI()
{
    delete ui;
}

void fundOptUI::on_comboBox_currentIndexChanged(const QString &arg1)
{

}

void fundOptUI::on_spinConfidence_valueChanged(double arg1)
{
    ransacConf = arg1;
}

void fundOptUI::on_spinNN_valueChanged(double arg1)
{
    ransacNN = arg1;
}

void fundOptUI::on_spinDist_valueChanged(int arg1)
{
    ransacNN = arg1;
}

void fundOptUI::on_methodcombo_currentIndexChanged(int index)
{
        d= index;
}
