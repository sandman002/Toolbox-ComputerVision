#include "stage.h"
#include "ui_stage.h"

stage::stage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stage)
{
    ui->setupUi(this);
}

stage::~stage()
{
    delete ui;
}
