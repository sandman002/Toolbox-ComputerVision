#ifndef BRIGHTCONTRASTUI_H
#define BRIGHTCONTRASTUI_H

#include <QDialog>

namespace Ui {
class brightContrastUI;
}

class brightContrastUI : public QDialog
{
    Q_OBJECT

public:
    explicit brightContrastUI(QWidget *parent = 0);
    ~brightContrastUI();
    double alpha; int beta;
private slots:
    void on_horizontalSlider_sliderMoved(int position);

    void on_horizontalSlider_2_sliderMoved(int position);

    void on_horizontalSlider_valueChanged(int value);

    void on_horizontalSlider_2_valueChanged(int value);

private:
    Ui::brightContrastUI *ui;
signals:
    void sendalphabeta(double ,int);
};

#endif // BRIGHTCONTRASTUI_H
