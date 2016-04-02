/********************************************************************************
** Form generated from reading UI file 'explorerhisto.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXPLORERHISTO_H
#define UI_EXPLORERHISTO_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ExplorerHisto
{
public:
    QGridLayout *gridLayout;
    QFormLayout *formLayout_2;
    QLabel *label;
    QLabel *totalCount;
    QLabel *label_2;
    QLabel *Mean;
    QLabel *label_3;
    QLabel *sd;
    QLabel *label_7;
    QSpinBox *grayValue;
    QLabel *levelCount;
    QTabWidget *histogram;
    QWidget *Intensity;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *histoIntensity;
    QWidget *Red;
    QHBoxLayout *horizontalLayout_2;
    QGraphicsView *histoRed;
    QWidget *Green;
    QHBoxLayout *horizontalLayout_3;
    QGraphicsView *histoGreen;
    QWidget *Blue;
    QHBoxLayout *horizontalLayout_4;
    QGraphicsView *histoBlue;

    void setupUi(QDialog *ExplorerHisto)
    {
        if (ExplorerHisto->objectName().isEmpty())
            ExplorerHisto->setObjectName(QStringLiteral("ExplorerHisto"));
        ExplorerHisto->setWindowModality(Qt::WindowModal);
        ExplorerHisto->resize(296, 389);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ExplorerHisto->sizePolicy().hasHeightForWidth());
        ExplorerHisto->setSizePolicy(sizePolicy);
        ExplorerHisto->setSizeGripEnabled(false);
        ExplorerHisto->setModal(true);
        gridLayout = new QGridLayout(ExplorerHisto);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        label = new QLabel(ExplorerHisto);
        label->setObjectName(QStringLiteral("label"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, label);

        totalCount = new QLabel(ExplorerHisto);
        totalCount->setObjectName(QStringLiteral("totalCount"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, totalCount);

        label_2 = new QLabel(ExplorerHisto);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, label_2);

        Mean = new QLabel(ExplorerHisto);
        Mean->setObjectName(QStringLiteral("Mean"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, Mean);

        label_3 = new QLabel(ExplorerHisto);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, label_3);

        sd = new QLabel(ExplorerHisto);
        sd->setObjectName(QStringLiteral("sd"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, sd);

        label_7 = new QLabel(ExplorerHisto);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, label_7);

        grayValue = new QSpinBox(ExplorerHisto);
        grayValue->setObjectName(QStringLiteral("grayValue"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(grayValue->sizePolicy().hasHeightForWidth());
        grayValue->setSizePolicy(sizePolicy1);
        grayValue->setMaximum(255);

        formLayout_2->setWidget(4, QFormLayout::LabelRole, grayValue);

        levelCount = new QLabel(ExplorerHisto);
        levelCount->setObjectName(QStringLiteral("levelCount"));

        formLayout_2->setWidget(4, QFormLayout::FieldRole, levelCount);


        gridLayout->addLayout(formLayout_2, 1, 0, 1, 1);

        histogram = new QTabWidget(ExplorerHisto);
        histogram->setObjectName(QStringLiteral("histogram"));
        Intensity = new QWidget();
        Intensity->setObjectName(QStringLiteral("Intensity"));
        horizontalLayout = new QHBoxLayout(Intensity);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        histoIntensity = new QGraphicsView(Intensity);
        histoIntensity->setObjectName(QStringLiteral("histoIntensity"));
        sizePolicy1.setHeightForWidth(histoIntensity->sizePolicy().hasHeightForWidth());
        histoIntensity->setSizePolicy(sizePolicy1);
        histoIntensity->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        histoIntensity->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout->addWidget(histoIntensity);

        histogram->addTab(Intensity, QString());
        Red = new QWidget();
        Red->setObjectName(QStringLiteral("Red"));
        horizontalLayout_2 = new QHBoxLayout(Red);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        histoRed = new QGraphicsView(Red);
        histoRed->setObjectName(QStringLiteral("histoRed"));
        histoRed->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        histoRed->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_2->addWidget(histoRed);

        histogram->addTab(Red, QString());
        Green = new QWidget();
        Green->setObjectName(QStringLiteral("Green"));
        horizontalLayout_3 = new QHBoxLayout(Green);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        histoGreen = new QGraphicsView(Green);
        histoGreen->setObjectName(QStringLiteral("histoGreen"));
        histoGreen->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        histoGreen->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_3->addWidget(histoGreen);

        histogram->addTab(Green, QString());
        Blue = new QWidget();
        Blue->setObjectName(QStringLiteral("Blue"));
        horizontalLayout_4 = new QHBoxLayout(Blue);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        histoBlue = new QGraphicsView(Blue);
        histoBlue->setObjectName(QStringLiteral("histoBlue"));
        histoBlue->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        histoBlue->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        horizontalLayout_4->addWidget(histoBlue);

        histogram->addTab(Blue, QString());

        gridLayout->addWidget(histogram, 0, 0, 1, 1);


        retranslateUi(ExplorerHisto);

        histogram->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ExplorerHisto);
    } // setupUi

    void retranslateUi(QDialog *ExplorerHisto)
    {
        ExplorerHisto->setWindowTitle(QApplication::translate("ExplorerHisto", "Histogram", 0));
        label->setText(QApplication::translate("ExplorerHisto", "Total Pixels : ", 0));
        totalCount->setText(QApplication::translate("ExplorerHisto", "N/A", 0));
        label_2->setText(QApplication::translate("ExplorerHisto", "Mean : ", 0));
        Mean->setText(QApplication::translate("ExplorerHisto", "N/A", 0));
        label_3->setText(QApplication::translate("ExplorerHisto", "S.D :", 0));
        sd->setText(QApplication::translate("ExplorerHisto", "N/A", 0));
        label_7->setText(QApplication::translate("ExplorerHisto", "Select Level :", 0));
        levelCount->setText(QApplication::translate("ExplorerHisto", "N/A", 0));
        histogram->setTabText(histogram->indexOf(Intensity), QApplication::translate("ExplorerHisto", "Intensity", 0));
        histogram->setTabText(histogram->indexOf(Red), QApplication::translate("ExplorerHisto", "Red", 0));
        histogram->setTabText(histogram->indexOf(Green), QApplication::translate("ExplorerHisto", "Green", 0));
        histogram->setTabText(histogram->indexOf(Blue), QApplication::translate("ExplorerHisto", "Blue", 0));
    } // retranslateUi

};

namespace Ui {
    class ExplorerHisto: public Ui_ExplorerHisto {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXPLORERHISTO_H
