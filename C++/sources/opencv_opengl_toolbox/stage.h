#ifndef STAGE_H
#define STAGE_H

#include <QDialog>

namespace Ui {
class stage;
}

class stage : public QDialog
{
    Q_OBJECT

public:
    explicit stage(QWidget *parent = 0);
    ~stage();

private:
    Ui::stage *ui;
};

#endif // STAGE_H
