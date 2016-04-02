/********************************************************************************
** Form generated from reading UI file 'fundoptui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNDOPTUI_H
#define UI_FUNDOPTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_fundOptUI
{
public:
    QGridLayout *gridLayout;
    QLabel *label_4;
    QComboBox *methodcombo;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QDoubleSpinBox *spinConfidence;
    QLabel *label_2;
    QSpinBox *spinDist;
    QLabel *label_3;
    QDoubleSpinBox *spinNN;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *fundOptUI)
    {
        if (fundOptUI->objectName().isEmpty())
            fundOptUI->setObjectName(QStringLiteral("fundOptUI"));
        fundOptUI->setWindowModality(Qt::ApplicationModal);
        fundOptUI->resize(429, 213);
        gridLayout = new QGridLayout(fundOptUI);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label_4 = new QLabel(fundOptUI);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 0, 0, 1, 1);

        methodcombo = new QComboBox(fundOptUI);
        methodcombo->setObjectName(QStringLiteral("methodcombo"));

        gridLayout->addWidget(methodcombo, 0, 1, 1, 1);

        groupBox = new QGroupBox(fundOptUI);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinConfidence = new QDoubleSpinBox(groupBox);
        spinConfidence->setObjectName(QStringLiteral("spinConfidence"));
        spinConfidence->setMaximum(0.99);
        spinConfidence->setSingleStep(0.01);
        spinConfidence->setValue(0.98);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinConfidence);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        spinDist = new QSpinBox(groupBox);
        spinDist->setObjectName(QStringLiteral("spinDist"));
        spinDist->setMaximum(10);
        spinDist->setValue(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinDist);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        spinNN = new QDoubleSpinBox(groupBox);
        spinNN->setObjectName(QStringLiteral("spinNN"));
        spinNN->setMaximum(0.99);
        spinNN->setSingleStep(0.01);
        spinNN->setValue(0.68);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinNN);


        gridLayout->addWidget(groupBox, 1, 0, 1, 1);

        buttonBox = new QDialogButtonBox(fundOptUI);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout->addWidget(buttonBox, 2, 0, 1, 2);


        retranslateUi(fundOptUI);
        QObject::connect(buttonBox, SIGNAL(accepted()), fundOptUI, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), fundOptUI, SLOT(reject()));

        QMetaObject::connectSlotsByName(fundOptUI);
    } // setupUi

    void retranslateUi(QDialog *fundOptUI)
    {
        fundOptUI->setWindowTitle(QApplication::translate("fundOptUI", "Dialog", 0));
        label_4->setText(QApplication::translate("fundOptUI", "Calculate Fundamental Matrix by :", 0));
        methodcombo->clear();
        methodcombo->insertItems(0, QStringList()
         << QApplication::translate("fundOptUI", "Choose Method", 0)
         << QApplication::translate("fundOptUI", "7 point", 0)
         << QApplication::translate("fundOptUI", "8 point", 0)
         << QApplication::translate("fundOptUI", "RANSAC", 0)
        );
        groupBox->setTitle(QApplication::translate("fundOptUI", "RANSAC Parameters", 0));
        label->setText(QApplication::translate("fundOptUI", "Confidence level", 0));
        label_2->setText(QApplication::translate("fundOptUI", "Epipolar distance", 0));
        label_3->setText(QApplication::translate("fundOptUI", "N N ratio", 0));
    } // retranslateUi

};

namespace Ui {
    class fundOptUI: public Ui_fundOptUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNDOPTUI_H
