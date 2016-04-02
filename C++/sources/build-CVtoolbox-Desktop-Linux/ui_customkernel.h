/********************************************************************************
** Form generated from reading UI file 'customkernel.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMKERNEL_H
#define UI_CUSTOMKERNEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_customKernel
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *vBox;
    QFormLayout *formLayout;
    QSpinBox *spinBox;
    QLabel *info;
    QPushButton *rogerThat;
    QCheckBox *normalizeCheck;

    void setupUi(QDialog *customKernel)
    {
        if (customKernel->objectName().isEmpty())
            customKernel->setObjectName(QStringLiteral("customKernel"));
        customKernel->resize(400, 300);
        gridLayout = new QGridLayout(customKernel);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        vBox = new QVBoxLayout();
        vBox->setObjectName(QStringLiteral("vBox"));

        gridLayout->addLayout(vBox, 1, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        spinBox = new QSpinBox(customKernel);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(-1);
        spinBox->setMaximum(99);
        spinBox->setSingleStep(2);
        spinBox->setValue(-1);

        formLayout->setWidget(0, QFormLayout::LabelRole, spinBox);

        info = new QLabel(customKernel);
        info->setObjectName(QStringLiteral("info"));

        formLayout->setWidget(0, QFormLayout::FieldRole, info);

        rogerThat = new QPushButton(customKernel);
        rogerThat->setObjectName(QStringLiteral("rogerThat"));

        formLayout->setWidget(1, QFormLayout::LabelRole, rogerThat);

        normalizeCheck = new QCheckBox(customKernel);
        normalizeCheck->setObjectName(QStringLiteral("normalizeCheck"));

        formLayout->setWidget(1, QFormLayout::FieldRole, normalizeCheck);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);


        retranslateUi(customKernel);

        QMetaObject::connectSlotsByName(customKernel);
    } // setupUi

    void retranslateUi(QDialog *customKernel)
    {
        customKernel->setWindowTitle(QApplication::translate("customKernel", "Custom Kernel2D", 0));
        info->setText(QApplication::translate("customKernel", "Select the kernel size", 0));
        rogerThat->setText(QApplication::translate("customKernel", "Make it Happen", 0));
        normalizeCheck->setText(QApplication::translate("customKernel", "Normalize", 0));
    } // retranslateUi

};

namespace Ui {
    class customKernel: public Ui_customKernel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMKERNEL_H
