/********************************************************************************
** Form generated from reading UI file 'contoursui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTOURSUI_H
#define UI_CONTOURSUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_contoursUI
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox_2;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *spinSobelApt;
    QLabel *label_5;
    QSpinBox *spinSobelThresh;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout_2;
    QLabel *label_2;
    QSpinBox *spinLapKSize;
    QGroupBox *groupBox;
    QFormLayout *formLayout_3;
    QLabel *label_3;
    QSpinBox *spinCannyMin;
    QLabel *label_4;
    QSpinBox *spinCannyMax;
    QTabWidget *Circle;
    QWidget *tab;
    QGroupBox *groupBox_4;
    QFormLayout *formLayout_4;
    QLabel *label_6;
    QSpinBox *spinVotes;
    QLabel *label_7;
    QSpinBox *spinMinRad;
    QLabel *label_8;
    QSpinBox *spinMaxRad;
    QLabel *label_9;
    QSpinBox *spinCircDist;
    QWidget *tab_2;
    QGridLayout *gridLayout_3;
    QLabel *label_10;
    QSpinBox *spinrho;
    QLabel *label_11;
    QSpinBox *spinthresh;
    QLabel *label_12;
    QSpinBox *spinmin;
    QLabel *label_13;
    QSpinBox *spinmax;
    QPushButton *pushButton;

    void setupUi(QDialog *contoursUI)
    {
        if (contoursUI->objectName().isEmpty())
            contoursUI->setObjectName(QStringLiteral("contoursUI"));
        contoursUI->resize(254, 526);
        gridLayout = new QGridLayout(contoursUI);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox_2 = new QGroupBox(contoursUI);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        formLayout = new QFormLayout(groupBox_2);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        spinSobelApt = new QSpinBox(groupBox_2);
        spinSobelApt->setObjectName(QStringLiteral("spinSobelApt"));
        spinSobelApt->setValue(3);

        formLayout->setWidget(0, QFormLayout::FieldRole, spinSobelApt);

        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        spinSobelThresh = new QSpinBox(groupBox_2);
        spinSobelThresh->setObjectName(QStringLiteral("spinSobelThresh"));
        spinSobelThresh->setMaximum(255);
        spinSobelThresh->setValue(128);

        formLayout->setWidget(1, QFormLayout::FieldRole, spinSobelThresh);


        gridLayout->addWidget(groupBox_2, 0, 0, 1, 1);

        groupBox_3 = new QGroupBox(contoursUI);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        formLayout_2 = new QFormLayout(groupBox_3);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label_2);

        spinLapKSize = new QSpinBox(groupBox_3);
        spinLapKSize->setObjectName(QStringLiteral("spinLapKSize"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(4);
        sizePolicy.setHeightForWidth(spinLapKSize->sizePolicy().hasHeightForWidth());
        spinLapKSize->setSizePolicy(sizePolicy);
        spinLapKSize->setValue(3);

        formLayout_2->setWidget(0, QFormLayout::FieldRole, spinLapKSize);


        gridLayout->addWidget(groupBox_3, 1, 0, 1, 1);

        groupBox = new QGroupBox(contoursUI);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        formLayout_3 = new QFormLayout(groupBox);
        formLayout_3->setObjectName(QStringLiteral("formLayout_3"));
        formLayout_3->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_3->setWidget(0, QFormLayout::LabelRole, label_3);

        spinCannyMin = new QSpinBox(groupBox);
        spinCannyMin->setObjectName(QStringLiteral("spinCannyMin"));
        spinCannyMin->setMaximum(500);
        spinCannyMin->setValue(125);

        formLayout_3->setWidget(0, QFormLayout::FieldRole, spinCannyMin);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout_3->setWidget(1, QFormLayout::LabelRole, label_4);

        spinCannyMax = new QSpinBox(groupBox);
        spinCannyMax->setObjectName(QStringLiteral("spinCannyMax"));
        spinCannyMax->setMaximum(1000);
        spinCannyMax->setValue(380);

        formLayout_3->setWidget(1, QFormLayout::FieldRole, spinCannyMax);


        gridLayout->addWidget(groupBox, 2, 0, 1, 1);

        Circle = new QTabWidget(contoursUI);
        Circle->setObjectName(QStringLiteral("Circle"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox_4 = new QGroupBox(tab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(0, 0, 227, 162));
        formLayout_4 = new QFormLayout(groupBox_4);
        formLayout_4->setObjectName(QStringLiteral("formLayout_4"));
        label_6 = new QLabel(groupBox_4);
        label_6->setObjectName(QStringLiteral("label_6"));

        formLayout_4->setWidget(0, QFormLayout::LabelRole, label_6);

        spinVotes = new QSpinBox(groupBox_4);
        spinVotes->setObjectName(QStringLiteral("spinVotes"));
        spinVotes->setMaximum(1000);
        spinVotes->setValue(100);

        formLayout_4->setWidget(0, QFormLayout::FieldRole, spinVotes);

        label_7 = new QLabel(groupBox_4);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_4->setWidget(1, QFormLayout::LabelRole, label_7);

        spinMinRad = new QSpinBox(groupBox_4);
        spinMinRad->setObjectName(QStringLiteral("spinMinRad"));
        spinMinRad->setMaximum(1000);
        spinMinRad->setValue(100);

        formLayout_4->setWidget(1, QFormLayout::FieldRole, spinMinRad);

        label_8 = new QLabel(groupBox_4);
        label_8->setObjectName(QStringLiteral("label_8"));

        formLayout_4->setWidget(2, QFormLayout::LabelRole, label_8);

        spinMaxRad = new QSpinBox(groupBox_4);
        spinMaxRad->setObjectName(QStringLiteral("spinMaxRad"));
        spinMaxRad->setMaximum(1000);
        spinMaxRad->setValue(300);

        formLayout_4->setWidget(2, QFormLayout::FieldRole, spinMaxRad);

        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));

        formLayout_4->setWidget(3, QFormLayout::LabelRole, label_9);

        spinCircDist = new QSpinBox(groupBox_4);
        spinCircDist->setObjectName(QStringLiteral("spinCircDist"));
        spinCircDist->setMaximum(1000);
        spinCircDist->setValue(200);

        formLayout_4->setWidget(3, QFormLayout::FieldRole, spinCircDist);

        Circle->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        gridLayout_3 = new QGridLayout(tab_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        label_10 = new QLabel(tab_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_3->addWidget(label_10, 0, 0, 1, 1);

        spinrho = new QSpinBox(tab_2);
        spinrho->setObjectName(QStringLiteral("spinrho"));
        spinrho->setValue(1);

        gridLayout_3->addWidget(spinrho, 0, 1, 1, 1);

        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_3->addWidget(label_11, 1, 0, 1, 1);

        spinthresh = new QSpinBox(tab_2);
        spinthresh->setObjectName(QStringLiteral("spinthresh"));
        spinthresh->setMaximum(255);
        spinthresh->setValue(80);

        gridLayout_3->addWidget(spinthresh, 1, 1, 1, 1);

        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_3->addWidget(label_12, 2, 0, 1, 1);

        spinmin = new QSpinBox(tab_2);
        spinmin->setObjectName(QStringLiteral("spinmin"));
        spinmin->setValue(30);

        gridLayout_3->addWidget(spinmin, 2, 1, 1, 1);

        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        gridLayout_3->addWidget(label_13, 3, 0, 1, 1);

        spinmax = new QSpinBox(tab_2);
        spinmax->setObjectName(QStringLiteral("spinmax"));
        spinmax->setValue(10);

        gridLayout_3->addWidget(spinmax, 3, 1, 1, 1);

        Circle->addTab(tab_2, QString());

        gridLayout->addWidget(Circle, 3, 0, 1, 1);

        pushButton = new QPushButton(contoursUI);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 4, 0, 1, 1);


        retranslateUi(contoursUI);

        Circle->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(contoursUI);
    } // setupUi

    void retranslateUi(QDialog *contoursUI)
    {
        contoursUI->setWindowTitle(QApplication::translate("contoursUI", "Contour settings", 0));
        groupBox_2->setTitle(QApplication::translate("contoursUI", "Sobel Parameters", 0));
        label->setText(QApplication::translate("contoursUI", "Sobel Aperature", 0));
        label_5->setText(QApplication::translate("contoursUI", "Threshold", 0));
        groupBox_3->setTitle(QApplication::translate("contoursUI", "Laplacian Parameters", 0));
        label_2->setText(QApplication::translate("contoursUI", "Laplacian Kernel", 0));
        groupBox->setTitle(QApplication::translate("contoursUI", "Canny Parameters", 0));
        label_3->setText(QApplication::translate("contoursUI", "Minimum Threshold", 0));
        label_4->setText(QApplication::translate("contoursUI", "Maximum Threshold", 0));
        groupBox_4->setTitle(QApplication::translate("contoursUI", "Hough Parameters", 0));
        label_6->setText(QApplication::translate("contoursUI", "Min votes", 0));
        label_7->setText(QApplication::translate("contoursUI", "Min Radius", 0));
        label_8->setText(QApplication::translate("contoursUI", "Max Radius", 0));
        label_9->setText(QApplication::translate("contoursUI", "Min Circle Distance", 0));
        Circle->setTabText(Circle->indexOf(tab), QApplication::translate("contoursUI", "Circle", 0));
        label_10->setText(QApplication::translate("contoursUI", "Rho", 0));
        label_11->setText(QApplication::translate("contoursUI", "Threshold", 0));
        label_12->setText(QApplication::translate("contoursUI", "Min line length", 0));
        label_13->setText(QApplication::translate("contoursUI", "Max Line Gap", 0));
        Circle->setTabText(Circle->indexOf(tab_2), QApplication::translate("contoursUI", "P-Lines", 0));
        pushButton->setText(QApplication::translate("contoursUI", "Apply", 0));
    } // retranslateUi

};

namespace Ui {
    class contoursUI: public Ui_contoursUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTOURSUI_H
