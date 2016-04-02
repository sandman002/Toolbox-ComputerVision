/********************************************************************************
** Form generated from reading UI file 'custommorph.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMMORPH_H
#define UI_CUSTOMMORPH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_customMorph
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout;
    QLabel *label;
    QComboBox *ElementTypeCombo;
    QLabel *label_2;
    QSlider *KernelSizeSlider;
    QLabel *label_3;
    QSpinBox *iterationSpinner;

    void setupUi(QDialog *customMorph)
    {
        if (customMorph->objectName().isEmpty())
            customMorph->setObjectName(QStringLiteral("customMorph"));
        customMorph->resize(260, 118);
        gridLayout = new QGridLayout(customMorph);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(customMorph);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        ElementTypeCombo = new QComboBox(customMorph);
        ElementTypeCombo->setObjectName(QStringLiteral("ElementTypeCombo"));

        formLayout->setWidget(0, QFormLayout::FieldRole, ElementTypeCombo);

        label_2 = new QLabel(customMorph);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        KernelSizeSlider = new QSlider(customMorph);
        KernelSizeSlider->setObjectName(QStringLiteral("KernelSizeSlider"));
        KernelSizeSlider->setOrientation(Qt::Horizontal);
        KernelSizeSlider->setTickPosition(QSlider::TicksAbove);
        KernelSizeSlider->setTickInterval(1);

        formLayout->setWidget(1, QFormLayout::FieldRole, KernelSizeSlider);

        label_3 = new QLabel(customMorph);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        iterationSpinner = new QSpinBox(customMorph);
        iterationSpinner->setObjectName(QStringLiteral("iterationSpinner"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(iterationSpinner->sizePolicy().hasHeightForWidth());
        iterationSpinner->setSizePolicy(sizePolicy);
        iterationSpinner->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"color: rgb(255, 255, 255);"));
        iterationSpinner->setMinimum(1);

        formLayout->setWidget(2, QFormLayout::FieldRole, iterationSpinner);


        gridLayout->addLayout(formLayout, 0, 0, 1, 1);


        retranslateUi(customMorph);

        QMetaObject::connectSlotsByName(customMorph);
    } // setupUi

    void retranslateUi(QDialog *customMorph)
    {
        customMorph->setWindowTitle(QApplication::translate("customMorph", "Morphology Parameters", 0));
        label->setText(QApplication::translate("customMorph", "Morph Element :", 0));
        ElementTypeCombo->clear();
        ElementTypeCombo->insertItems(0, QStringList()
         << QApplication::translate("customMorph", "Rectangle", 0)
         << QApplication::translate("customMorph", "Cross", 0)
         << QApplication::translate("customMorph", "Ellipse", 0)
        );
        label_2->setText(QApplication::translate("customMorph", "Kernel Size", 0));
        label_3->setText(QApplication::translate("customMorph", "Total Iteration", 0));
    } // retranslateUi

};

namespace Ui {
    class customMorph: public Ui_customMorph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMMORPH_H
