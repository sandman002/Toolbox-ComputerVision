#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "QDebug"
#include <QMetaObject>
#include <QMetaMethod>
#include <iostream>


void MainWindow::print(QString txt, int w)
{
    if( w == WARNING) ui->command->setTextColor(Qt::red);
    else if( w == CMD) ui->command->setTextColor(Qt::blue);
    else if( w == RESULT) ui->command->setTextColor(Qt::green);
      ui->command->append(QString("decree>> ") + txt );
//    ui->command->moveCursor(QTextCursor::End);
//    ui->command->insertPlainText(QString("decree>>"));
//    ui->command->moveCursor(QTextCursor::End);
//    ui->command->insertPlainText(txt +'\n');
}
