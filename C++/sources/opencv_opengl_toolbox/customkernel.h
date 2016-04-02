#ifndef CUSTOMKERNEL_H
#define CUSTOMKERNEL_H

#include <QDialog>
#include <QDebug>
#include <opencv2/core/core.hpp>
#include "QLineEdit"
#include "QVBoxLayout"
#include "QHBoxLayout"
namespace Ui {
class customKernel;
}

class customKernel : public QDialog
{
    Q_OBJECT

public:
    explicit customKernel(QWidget *parent = 0);
    ~customKernel();

private slots:
    void on_spinBox_valueChanged(int sz);

    void on_rogerThat_clicked();

private:
    Ui::customKernel *ui;

    void clearLayout(QLayout* layout, bool deleteWidgets = true)
    {
        while (QLayoutItem* item = layout->takeAt(0))
        {
            if (deleteWidgets)
            {
                if (QWidget* widget = item->widget())
                    delete widget;
            }
            if (QLayout* childLayout = item->layout())
                clearLayout(childLayout, deleteWidgets);
            delete item;
        }
    }

    void makeKernel();

signals:
    void sendKernel(cv::Mat);

};

#endif // CUSTOMKERNEL_H
