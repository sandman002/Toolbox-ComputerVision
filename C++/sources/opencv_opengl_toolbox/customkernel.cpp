#include "customkernel.h"
#include "ui_customkernel.h"
#include <iostream>
customKernel::customKernel(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::customKernel)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);
}

customKernel::~customKernel()
{
    delete ui;
}

void customKernel::on_spinBox_valueChanged(int sz)
{
    if(sz <= 0 || sz%2 == 0) {
        qDebug()<<"even";
        return;
    }
    clearLayout(ui->vBox, true);

    for(int i = 0; i < sz; i++){
        //so we will add some hBoxes of sz count
        QHBoxLayout *hBox = new QHBoxLayout(this);  //one new hBox to be served
        for(int j = 0; j < sz; j++){
            //so we will add some QLineEdit of sz count
            QLineEdit *cell = new QLineEdit;
            cell->setText("0");
            cell->setMaximumSize(60,30);
            hBox->addWidget(cell);
        }
        ui->vBox->addLayout(hBox);
    }
}


void customKernel::makeKernel()
{
    //std::vector <double>  k;
    int sz = ui->vBox->count(); //counts of hBoxes
    float *k;
    k = new float[sz*sz];
    float sum = 0;
    for(int i = 0; i < sz; i++){
        if(QLayoutItem *b = (ui->vBox->itemAt(i)))    //go through each item at hBoxes; false if no hBox returned by itemAt(i)
        {
            QHBoxLayout *h = qobject_cast<QHBoxLayout *>(b->layout());
            // vector<double> cellValue; cellValue.clear();
            for(int j = 0; j < sz; j++){
                if(QLayoutItem *e = h->itemAt(j)){
                    QLineEdit *cell = qobject_cast<QLineEdit *>(e->widget());

                    double d = cell->text().toDouble();
                    k[i*sz+j] = d;
                    sum += d;
                }
            }
        }
    }
    if(ui->normalizeCheck->isChecked()) //if normalize
        for(int i = 0; i < sz*sz; i++)
            if(sum > 0)
                k[i] /= sum;

    cv::Mat m = cv::Mat(sz, sz, CV_32FC1, k);
 //   std::cout<<m;
    emit sendKernel(m);
}

void customKernel::on_rogerThat_clicked()
{
    makeKernel();
    this->close();
}
