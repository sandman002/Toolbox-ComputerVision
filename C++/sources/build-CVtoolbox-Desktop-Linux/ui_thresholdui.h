/********************************************************************************
** Form generated from reading UI file 'thresholdui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THRESHOLDUI_H
#define UI_THRESHOLDUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_thresholdUI
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QSlider *GlobalSlider;
    QLabel *label_2;
    QSlider *localSlider;
    QLabel *label_3;
    QSlider *horizontalSlider;
    QLabel *label_4;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_3;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox;

    void setupUi(QDialog *thresholdUI)
    {
        if (thresholdUI->objectName().isEmpty())
            thresholdUI->setObjectName(QStringLiteral("thresholdUI"));
        thresholdUI->setWindowModality(Qt::WindowModal);
        thresholdUI->resize(318, 187);
        gridLayout = new QGridLayout(thresholdUI);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(thresholdUI);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        GlobalSlider = new QSlider(thresholdUI);
        GlobalSlider->setObjectName(QStringLiteral("GlobalSlider"));
        GlobalSlider->setMaximum(255);
        GlobalSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(0, QFormLayout::FieldRole, GlobalSlider);

        label_2 = new QLabel(thresholdUI);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        localSlider = new QSlider(thresholdUI);
        localSlider->setObjectName(QStringLiteral("localSlider"));
        localSlider->setMinimum(1);
        localSlider->setMaximum(20);
        localSlider->setOrientation(Qt::Horizontal);

        formLayout->setWidget(1, QFormLayout::FieldRole, localSlider);

        label_3 = new QLabel(thresholdUI);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        horizontalSlider = new QSlider(thresholdUI);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setMinimum(1);
        horizontalSlider->setMaximum(255);
        horizontalSlider->setSingleStep(2);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickInterval(2);

        formLayout->setWidget(2, QFormLayout::FieldRole, horizontalSlider);

        label_4 = new QLabel(thresholdUI);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        comboBox = new QComboBox(thresholdUI);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBox);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        spinBox_2 = new QSpinBox(thresholdUI);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));

        horizontalLayout_3->addWidget(spinBox_2);

        spinBox_3 = new QSpinBox(thresholdUI);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));

        horizontalLayout_3->addWidget(spinBox_3);

        spinBox = new QSpinBox(thresholdUI);
        spinBox->setObjectName(QStringLiteral("spinBox"));

        horizontalLayout_3->addWidget(spinBox);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);


        retranslateUi(thresholdUI);
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), spinBox, SLOT(setValue(int)));
        QObject::connect(localSlider, SIGNAL(valueChanged(int)), spinBox_3, SLOT(setValue(int)));
        QObject::connect(GlobalSlider, SIGNAL(valueChanged(int)), spinBox_2, SLOT(setValue(int)));
        QObject::connect(spinBox, SIGNAL(valueChanged(int)), horizontalSlider, SLOT(setValue(int)));

        QMetaObject::connectSlotsByName(thresholdUI);
    } // setupUi

    void retranslateUi(QDialog *thresholdUI)
    {
        thresholdUI->setWindowTitle(QApplication::translate("thresholdUI", "Dialog", 0));
        label->setText(QApplication::translate("thresholdUI", "Global Threshold", 0));
        label_2->setText(QApplication::translate("thresholdUI", "Local Threshold", 0));
        label_3->setText(QApplication::translate("thresholdUI", "Kernel Size", 0));
        label_4->setText(QApplication::translate("thresholdUI", "Border Type", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("thresholdUI", "Constant (0)", 0)
         << QApplication::translate("thresholdUI", "Replicate", 0)
         << QApplication::translate("thresholdUI", "Reflect", 0)
         << QApplication::translate("thresholdUI", "Reflect101", 0)
        );
    } // retranslateUi

};

namespace Ui {
    class thresholdUI: public Ui_thresholdUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THRESHOLDUI_H
