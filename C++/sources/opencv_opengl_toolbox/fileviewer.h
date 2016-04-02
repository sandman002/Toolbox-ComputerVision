#ifndef FILEVIEWER_H
#define FILEVIEWER_H

#include <QWidget>

namespace Ui {
class fileViewer;
}

class fileViewer : public QWidget
{
    Q_OBJECT

public:
    explicit fileViewer(QWidget *parent = 0);
    ~fileViewer();

private:
    Ui::fileViewer *ui;
};

#endif // FILEVIEWER_H
