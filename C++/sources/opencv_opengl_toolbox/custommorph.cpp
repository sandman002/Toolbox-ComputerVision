#include "custommorph.h"
#include "ui_custommorph.h"

customMorph::customMorph(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customMorph)
{
    ui->setupUi(this);
    ui->ElementTypeCombo->setCurrentIndex(0);
    ui->KernelSizeSlider->setValue(3);

    elementType = ui->ElementTypeCombo->currentIndex();
    kernelSize = ui->KernelSizeSlider->value();
    iteration = ui->iterationSpinner->value();
}

customMorph::~customMorph()
{
    delete ui;
}

void customMorph::on_ElementTypeCombo_currentIndexChanged(int index)
{
    elementType = index;
}

void customMorph::on_KernelSizeSlider_valueChanged(int value)
{
    kernelSize = value;
}

void customMorph::on_iterationSpinner_valueChanged(int arg1)
{
    iteration = arg1;
}
