#ifndef CUSTOMMORPH_H
#define CUSTOMMORPH_H

#include <QDialog>

namespace Ui {
class customMorph;
}

class customMorph : public QDialog
{
    Q_OBJECT

public:
    explicit customMorph(QWidget *parent = 0);
    ~customMorph();

    int elementType;
    int iteration;
    int kernelSize;

private slots:
    void on_ElementTypeCombo_currentIndexChanged(int index);

    void on_KernelSizeSlider_valueChanged(int value);

    void on_iterationSpinner_valueChanged(int arg1);

private:
    Ui::customMorph *ui;
};

#endif // CUSTOMMORPH_H
