#ifndef FUNDOPTUI_H
#define FUNDOPTUI_H

#include <QDialog>

namespace Ui {
class fundOptUI;
}

class fundOptUI : public QDialog
{
    Q_OBJECT

public:
    explicit fundOptUI(QWidget *parent = 0);
    ~fundOptUI();
    int d;
    double ransacConf, ransacDist, ransacNN;
private slots:
    void on_comboBox_currentIndexChanged(const QString &arg1);

    void on_spinConfidence_valueChanged(double arg1);

    void on_spinNN_valueChanged(double arg1);

    void on_spinDist_valueChanged(int arg1);

    void on_methodcombo_currentIndexChanged(int index);

private:
    Ui::fundOptUI *ui;
};

#endif // FUNDOPTUI_H
