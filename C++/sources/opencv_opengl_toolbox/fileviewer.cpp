#include "fileviewer.h"
#include "ui_fileviewer.h"

fileViewer::fileViewer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::fileViewer)
{
    ui->setupUi(this);
}

fileViewer::~fileViewer()
{
    delete ui;
}
