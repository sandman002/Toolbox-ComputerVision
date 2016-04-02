/********************************************************************************
** Form generated from reading UI file 'featuresui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FEATURESUI_H
#define UI_FEATURESUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_featuresUI
{
public:
    QGridLayout *gridLayout_3;
    QTabWidget *Harris;
    QWidget *tab_5;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label;
    QSpinBox *hNeigh;
    QLabel *label_2;
    QSpinBox *hAperature;
    QLabel *label_3;
    QDoubleSpinBox *hThresh;
    QLabel *label_4;
    QDoubleSpinBox *hMaxStr;
    QLabel *label_5;
    QDoubleSpinBox *hParam;
    QLabel *label_9;
    QSpinBox *spinSize;
    QWidget *tab_6;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_2;
    QLabel *label_6;
    QLabel *label_7;
    QDoubleSpinBox *siftThresh;
    QDoubleSpinBox *edgeThresh;
    QLabel *label_8;
    QSpinBox *gthresh;
    QPushButton *pushButton;

    void setupUi(QDialog *featuresUI)
    {
        if (featuresUI->objectName().isEmpty())
            featuresUI->setObjectName(QStringLiteral("featuresUI"));
        featuresUI->setWindowModality(Qt::ApplicationModal);
        featuresUI->resize(256, 277);
        gridLayout_3 = new QGridLayout(featuresUI);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        Harris = new QTabWidget(featuresUI);
        Harris->setObjectName(QStringLiteral("Harris"));
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        groupBox = new QGroupBox(tab_5);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 0, 217, 195));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        hNeigh = new QSpinBox(groupBox);
        hNeigh->setObjectName(QStringLiteral("hNeigh"));
        hNeigh->setMinimum(1);
        hNeigh->setSingleStep(2);
        hNeigh->setValue(3);

        gridLayout->addWidget(hNeigh, 0, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        hAperature = new QSpinBox(groupBox);
        hAperature->setObjectName(QStringLiteral("hAperature"));
        hAperature->setMinimum(1);
        hAperature->setSingleStep(2);
        hAperature->setValue(3);

        gridLayout->addWidget(hAperature, 1, 1, 1, 1);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        hThresh = new QDoubleSpinBox(groupBox);
        hThresh->setObjectName(QStringLiteral("hThresh"));
        hThresh->setMaximum(1);
        hThresh->setSingleStep(0.0001);
        hThresh->setValue(0.01);

        gridLayout->addWidget(hThresh, 3, 1, 1, 1);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 3, 0, 1, 1);

        hMaxStr = new QDoubleSpinBox(groupBox);
        hMaxStr->setObjectName(QStringLiteral("hMaxStr"));
        hMaxStr->setSingleStep(0.2);

        gridLayout->addWidget(hMaxStr, 2, 1, 1, 1);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 4, 0, 1, 1);

        hParam = new QDoubleSpinBox(groupBox);
        hParam->setObjectName(QStringLiteral("hParam"));
        hParam->setMaximum(1);
        hParam->setSingleStep(0.01);
        hParam->setValue(0.01);

        gridLayout->addWidget(hParam, 4, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout->addWidget(label_9, 5, 0, 1, 1);

        spinSize = new QSpinBox(groupBox);
        spinSize->setObjectName(QStringLiteral("spinSize"));
        spinSize->setMinimum(1);

        gridLayout->addWidget(spinSize, 5, 1, 1, 1);

        Harris->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QStringLiteral("tab_6"));
        gridLayout_2 = new QGridLayout(tab_6);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox_2 = new QGroupBox(tab_6);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(17, 25, 96, 17));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(17, 58, 103, 17));
        siftThresh = new QDoubleSpinBox(groupBox_2);
        siftThresh->setObjectName(QStringLiteral("siftThresh"));
        siftThresh->setGeometry(QRect(126, 25, 61, 27));
        siftThresh->setMaximum(1);
        siftThresh->setSingleStep(0.01);
        siftThresh->setValue(0.02);
        edgeThresh = new QDoubleSpinBox(groupBox_2);
        edgeThresh->setObjectName(QStringLiteral("edgeThresh"));
        edgeThresh->setGeometry(QRect(126, 58, 69, 27));
        edgeThresh->setValue(10);
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(17, 91, 69, 17));
        gthresh = new QSpinBox(groupBox_2);
        gthresh->setObjectName(QStringLiteral("gthresh"));
        gthresh->setGeometry(QRect(126, 91, 65, 27));
        gthresh->setMaximum(1000);
        gthresh->setValue(40);

        gridLayout_2->addWidget(groupBox_2, 0, 0, 1, 1);

        Harris->addTab(tab_6, QString());

        gridLayout_3->addWidget(Harris, 0, 0, 1, 1);

        pushButton = new QPushButton(featuresUI);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(pushButton->sizePolicy().hasHeightForWidth());
        pushButton->setSizePolicy(sizePolicy);

        gridLayout_3->addWidget(pushButton, 1, 0, 1, 1);


        retranslateUi(featuresUI);

        Harris->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(featuresUI);
    } // setupUi

    void retranslateUi(QDialog *featuresUI)
    {
        featuresUI->setWindowTitle(QApplication::translate("featuresUI", "Features Parameters", 0));
        groupBox->setTitle(QApplication::translate("featuresUI", "Harris Parameters", 0));
        label->setText(QApplication::translate("featuresUI", "Neighbourhood", 0));
        label_2->setText(QApplication::translate("featuresUI", "Aperature", 0));
        label_3->setText(QApplication::translate("featuresUI", "Max Strength", 0));
        label_4->setText(QApplication::translate("featuresUI", "threshold", 0));
        label_5->setText(QApplication::translate("featuresUI", "Harris Parameter", 0));
        label_9->setText(QApplication::translate("featuresUI", "Point Size", 0));
        Harris->setTabText(Harris->indexOf(tab_5), QApplication::translate("featuresUI", "Harris", 0));
        groupBox_2->setTitle(QApplication::translate("featuresUI", "Fast/SURF/SIFT", 0));
        label_6->setText(QApplication::translate("featuresUI", "Sift Threshold", 0));
        label_7->setText(QApplication::translate("featuresUI", "EdgeThreshold", 0));
        label_8->setText(QApplication::translate("featuresUI", "Threshold", 0));
        Harris->setTabText(Harris->indexOf(tab_6), QApplication::translate("featuresUI", "Fast/SURF/SIFT", 0));
        pushButton->setText(QApplication::translate("featuresUI", "Okay", 0));
    } // retranslateUi

};

namespace Ui {
    class featuresUI: public Ui_featuresUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FEATURESUI_H
