/********************************************************************************
** Form generated from reading UI file 'cam.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAM_H
#define UI_CAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QProgressBar>
#include "cvglcam.h"

QT_BEGIN_NAMESPACE

class Ui_cam
{
public:
    QGridLayout *gridLayout;
    CvGlCam *rView;
    QLabel *info;
    CvGlCam *lView;
    QProgressBar *progress;

    void setupUi(QDialog *cam)
    {
        if (cam->objectName().isEmpty())
            cam->setObjectName(QStringLiteral("cam"));
        cam->resize(587, 259);
        gridLayout = new QGridLayout(cam);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        rView = new CvGlCam(cam);
        rView->setObjectName(QStringLiteral("rView"));

        gridLayout->addWidget(rView, 0, 0, 1, 1);

        info = new QLabel(cam);
        info->setObjectName(QStringLiteral("info"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(info->sizePolicy().hasHeightForWidth());
        info->setSizePolicy(sizePolicy);
        info->setMaximumSize(QSize(16777215, 15));

        gridLayout->addWidget(info, 1, 0, 1, 1);

        lView = new CvGlCam(cam);
        lView->setObjectName(QStringLiteral("lView"));

        gridLayout->addWidget(lView, 0, 1, 1, 1);

        progress = new QProgressBar(cam);
        progress->setObjectName(QStringLiteral("progress"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(progress->sizePolicy().hasHeightForWidth());
        progress->setSizePolicy(sizePolicy1);
        progress->setValue(24);

        gridLayout->addWidget(progress, 1, 1, 1, 1);


        retranslateUi(cam);

        QMetaObject::connectSlotsByName(cam);
    } // setupUi

    void retranslateUi(QDialog *cam)
    {
        cam->setWindowTitle(QApplication::translate("cam", "Camera Feed", 0));
        info->setText(QApplication::translate("cam", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class cam: public Ui_cam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAM_H
