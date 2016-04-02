#ifndef THRESHOLDUI_H
#define THRESHOLDUI_H

#include <QDialog>

namespace Ui {
class thresholdUI;
}

class thresholdUI : public QDialog
{
    Q_OBJECT

public:
    explicit thresholdUI(QWidget *parent = 0);
    ~thresholdUI();
    int localThresh, globalThresh, kernelSize, borderType;
private slots:
    void on_GlobalSlider_valueChanged(int value);

    void on_localSlider_valueChanged(int value);

    void on_horizontalSlider_valueChanged(int value);

    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::thresholdUI *ui;
};

#endif // THRESHOLDUI_H
