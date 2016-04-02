/********************************************************************************
** Form generated from reading UI file 'brightcontrastui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BRIGHTCONTRASTUI_H
#define UI_BRIGHTCONTRASTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_brightContrastUI
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QSlider *horizontalSlider;
    QLabel *label_2;
    QSlider *horizontalSlider_2;

    void setupUi(QDialog *brightContrastUI)
    {
        if (brightContrastUI->objectName().isEmpty())
            brightContrastUI->setObjectName(QStringLiteral("brightContrastUI"));
        brightContrastUI->setWindowModality(Qt::ApplicationModal);
        brightContrastUI->resize(223, 128);
        verticalLayout = new QVBoxLayout(brightContrastUI);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(brightContrastUI);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        horizontalSlider = new QSlider(brightContrastUI);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(0);
        horizontalSlider->setMaximum(100);
        horizontalSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider);

        label_2 = new QLabel(brightContrastUI);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        horizontalSlider_2 = new QSlider(brightContrastUI);
        horizontalSlider_2->setObjectName(QStringLiteral("horizontalSlider_2"));
        horizontalSlider_2->setMinimum(100);
        horizontalSlider_2->setMaximum(300);
        horizontalSlider_2->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(horizontalSlider_2);


        retranslateUi(brightContrastUI);

        QMetaObject::connectSlotsByName(brightContrastUI);
    } // setupUi

    void retranslateUi(QDialog *brightContrastUI)
    {
        brightContrastUI->setWindowTitle(QApplication::translate("brightContrastUI", "Brightness And Contrast", 0));
        label->setText(QApplication::translate("brightContrastUI", "Brightness", 0));
        label_2->setText(QApplication::translate("brightContrastUI", "Contrast", 0));
    } // retranslateUi

};

namespace Ui {
    class brightContrastUI: public Ui_brightContrastUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BRIGHTCONTRASTUI_H
