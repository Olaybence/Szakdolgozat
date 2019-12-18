/********************************************************************************
** Form generated from reading UI file 'psettings.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PSETTINGS_H
#define UI_PSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PSettings
{
public:
    QDialogButtonBox *buttonBox;
    QPushButton *SaveIntoFile;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *MinArea;
    QSpinBox *minArea;
    QVBoxLayout *verticalLayout_3;
    QLabel *MaxArea;
    QSpinBox *maxArea;
    QLabel *MaxMinAreaInfo;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_6;
    QLabel *ProcRes;
    QSpinBox *maxResolution;
    QLabel *ProcResInfo;
    QWidget *layoutWidget2;
    QHBoxLayout *WholeGauss;
    QLabel *Gauss;
    QSpinBox *gbks;
    QLabel *GaussInfo;
    QWidget *layoutWidget3;
    QHBoxLayout *DisplayedObjects;
    QLabel *dispObj;
    QVBoxLayout *RadioButtons;
    QRadioButton *selectedObject;
    QRadioButton *allObject;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_2;
    QSpinBox *red;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    QSpinBox *green;
    QVBoxLayout *verticalLayout;
    QLabel *label_4;
    QSpinBox *blue;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *maxDiv_Title;
    QDoubleSpinBox *maxDiversity;
    QLabel *label_5;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *loseTrackingTitle;
    QSpinBox *loseTracking;
    QLabel *label_7;
    QButtonGroup *DispObjSelect;

    void setupUi(QDialog *PSettings)
    {
        if (PSettings->objectName().isEmpty())
            PSettings->setObjectName(QString::fromUtf8("PSettings"));
        PSettings->resize(621, 561);
        buttonBox = new QDialogButtonBox(PSettings);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setGeometry(QRect(340, 520, 261, 25));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);
        SaveIntoFile = new QPushButton(PSettings);
        SaveIntoFile->setObjectName(QString::fromUtf8("SaveIntoFile"));
        SaveIntoFile->setGeometry(QRect(20, 520, 111, 25));
        layoutWidget = new QWidget(PSettings);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 240, 601, 70));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        MinArea = new QLabel(layoutWidget);
        MinArea->setObjectName(QString::fromUtf8("MinArea"));

        verticalLayout_2->addWidget(MinArea);

        minArea = new QSpinBox(layoutWidget);
        minArea->setObjectName(QString::fromUtf8("minArea"));
        minArea->setAlignment(Qt::AlignCenter);
        minArea->setMaximum(1000000);

        verticalLayout_2->addWidget(minArea);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        MaxArea = new QLabel(layoutWidget);
        MaxArea->setObjectName(QString::fromUtf8("MaxArea"));

        verticalLayout_3->addWidget(MaxArea);

        maxArea = new QSpinBox(layoutWidget);
        maxArea->setObjectName(QString::fromUtf8("maxArea"));
        maxArea->setAlignment(Qt::AlignCenter);
        maxArea->setMinimum(10);
        maxArea->setMaximum(1000000);

        verticalLayout_3->addWidget(maxArea);


        horizontalLayout_2->addLayout(verticalLayout_3);


        horizontalLayout_5->addLayout(horizontalLayout_2);

        MaxMinAreaInfo = new QLabel(layoutWidget);
        MaxMinAreaInfo->setObjectName(QString::fromUtf8("MaxMinAreaInfo"));
        MaxMinAreaInfo->setWordWrap(true);

        horizontalLayout_5->addWidget(MaxMinAreaInfo);

        horizontalLayout_5->setStretch(0, 1);
        horizontalLayout_5->setStretch(1, 2);
        layoutWidget1 = new QWidget(PSettings);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 170, 601, 61));
        horizontalLayout_6 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        ProcRes = new QLabel(layoutWidget1);
        ProcRes->setObjectName(QString::fromUtf8("ProcRes"));

        horizontalLayout_6->addWidget(ProcRes);

        maxResolution = new QSpinBox(layoutWidget1);
        maxResolution->setObjectName(QString::fromUtf8("maxResolution"));
        maxResolution->setMinimum(10);
        maxResolution->setMaximum(5000);

        horizontalLayout_6->addWidget(maxResolution);

        ProcResInfo = new QLabel(layoutWidget1);
        ProcResInfo->setObjectName(QString::fromUtf8("ProcResInfo"));
        ProcResInfo->setContextMenuPolicy(Qt::DefaultContextMenu);
        ProcResInfo->setStyleSheet(QString::fromUtf8(""));
        ProcResInfo->setWordWrap(true);

        horizontalLayout_6->addWidget(ProcResInfo);

        horizontalLayout_6->setStretch(0, 2);
        horizontalLayout_6->setStretch(2, 5);
        layoutWidget2 = new QWidget(PSettings);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 90, 601, 91));
        WholeGauss = new QHBoxLayout(layoutWidget2);
        WholeGauss->setObjectName(QString::fromUtf8("WholeGauss"));
        WholeGauss->setContentsMargins(0, 0, 0, 0);
        Gauss = new QLabel(layoutWidget2);
        Gauss->setObjectName(QString::fromUtf8("Gauss"));

        WholeGauss->addWidget(Gauss);

        gbks = new QSpinBox(layoutWidget2);
        gbks->setObjectName(QString::fromUtf8("gbks"));
        gbks->setAlignment(Qt::AlignCenter);
        gbks->setMinimum(1);

        WholeGauss->addWidget(gbks);

        GaussInfo = new QLabel(layoutWidget2);
        GaussInfo->setObjectName(QString::fromUtf8("GaussInfo"));
        GaussInfo->setAlignment(Qt::AlignCenter);
        GaussInfo->setWordWrap(true);

        WholeGauss->addWidget(GaussInfo);

        WholeGauss->setStretch(0, 2);
        WholeGauss->setStretch(1, 1);
        WholeGauss->setStretch(2, 5);
        layoutWidget3 = new QWidget(PSettings);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 20, 480, 56));
        DisplayedObjects = new QHBoxLayout(layoutWidget3);
        DisplayedObjects->setObjectName(QString::fromUtf8("DisplayedObjects"));
        DisplayedObjects->setContentsMargins(0, 0, 0, 0);
        dispObj = new QLabel(layoutWidget3);
        dispObj->setObjectName(QString::fromUtf8("dispObj"));

        DisplayedObjects->addWidget(dispObj);

        RadioButtons = new QVBoxLayout();
        RadioButtons->setObjectName(QString::fromUtf8("RadioButtons"));
        selectedObject = new QRadioButton(layoutWidget3);
        DispObjSelect = new QButtonGroup(PSettings);
        DispObjSelect->setObjectName(QString::fromUtf8("DispObjSelect"));
        DispObjSelect->addButton(selectedObject);
        selectedObject->setObjectName(QString::fromUtf8("selectedObject"));

        RadioButtons->addWidget(selectedObject);

        allObject = new QRadioButton(layoutWidget3);
        DispObjSelect->addButton(allObject);
        allObject->setObjectName(QString::fromUtf8("allObject"));

        RadioButtons->addWidget(allObject);


        DisplayedObjects->addLayout(RadioButtons);

        layoutWidget4 = new QWidget(PSettings);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(11, 440, 301, 53));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget4);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_3->addWidget(label);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_2 = new QLabel(layoutWidget4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_4->addWidget(label_2);

        red = new QSpinBox(layoutWidget4);
        red->setObjectName(QString::fromUtf8("red"));
        red->setAlignment(Qt::AlignCenter);
        red->setMinimum(0);
        red->setMaximum(255);

        verticalLayout_4->addWidget(red);


        horizontalLayout_3->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(layoutWidget4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(label_3);

        green = new QSpinBox(layoutWidget4);
        green->setObjectName(QString::fromUtf8("green"));
        green->setAlignment(Qt::AlignCenter);
        green->setMinimum(0);
        green->setMaximum(255);

        verticalLayout_5->addWidget(green);


        horizontalLayout_3->addLayout(verticalLayout_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_4 = new QLabel(layoutWidget4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_4);

        blue = new QSpinBox(layoutWidget4);
        blue->setObjectName(QString::fromUtf8("blue"));
        blue->setAlignment(Qt::AlignCenter);
        blue->setMinimum(0);
        blue->setMaximum(255);
        blue->setValue(0);

        verticalLayout->addWidget(blue);


        horizontalLayout_3->addLayout(verticalLayout);

        horizontalLayout_3->setStretch(0, 2);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);
        layoutWidget5 = new QWidget(PSettings);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 370, 601, 61));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        maxDiv_Title = new QLabel(layoutWidget5);
        maxDiv_Title->setObjectName(QString::fromUtf8("maxDiv_Title"));

        horizontalLayout_4->addWidget(maxDiv_Title);

        maxDiversity = new QDoubleSpinBox(layoutWidget5);
        maxDiversity->setObjectName(QString::fromUtf8("maxDiversity"));
        maxDiversity->setMaximum(10000.000000000000000);

        horizontalLayout_4->addWidget(maxDiversity);

        label_5 = new QLabel(layoutWidget5);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setAlignment(Qt::AlignCenter);
        label_5->setWordWrap(true);

        horizontalLayout_4->addWidget(label_5);

        horizontalLayout_4->setStretch(0, 2);
        horizontalLayout_4->setStretch(1, 1);
        horizontalLayout_4->setStretch(2, 5);
        layoutWidget6 = new QWidget(PSettings);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(10, 320, 601, 41));
        horizontalLayout_7 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        loseTrackingTitle = new QLabel(layoutWidget6);
        loseTrackingTitle->setObjectName(QString::fromUtf8("loseTrackingTitle"));

        horizontalLayout_7->addWidget(loseTrackingTitle);

        loseTracking = new QSpinBox(layoutWidget6);
        loseTracking->setObjectName(QString::fromUtf8("loseTracking"));
        loseTracking->setMaximum(200);

        horizontalLayout_7->addWidget(loseTracking);

        label_7 = new QLabel(layoutWidget6);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setAlignment(Qt::AlignCenter);
        label_7->setWordWrap(true);

        horizontalLayout_7->addWidget(label_7);

        horizontalLayout_7->setStretch(0, 2);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 5);

        retranslateUi(PSettings);
        QObject::connect(buttonBox, SIGNAL(accepted()), PSettings, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), PSettings, SLOT(reject()));

        QMetaObject::connectSlotsByName(PSettings);
    } // setupUi

    void retranslateUi(QDialog *PSettings)
    {
        PSettings->setWindowTitle(QApplication::translate("PSettings", "Dialog", nullptr));
        SaveIntoFile->setText(QApplication::translate("PSettings", "Save into file", nullptr));
        MinArea->setText(QApplication::translate("PSettings", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Minimum Area</span></p></body></html>", nullptr));
        MaxArea->setText(QApplication::translate("PSettings", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Maximum Area</span></p></body></html>", nullptr));
        MaxMinAreaInfo->setText(QApplication::translate("PSettings", "<html><head/><body><p align=\"center\">The pixel range of the detected object ( on process resolution )</p></body></html>", nullptr));
        ProcRes->setText(QApplication::translate("PSettings", "<html><head/><body><p><span style=\" font-weight:600;\">Process resolution:</span></p></body></html>", nullptr));
        ProcResInfo->setText(QApplication::translate("PSettings", "<html><head/><body><p align=\"center\">The image will be processed on this resolution, if bigger it will be shrinked down to this level ( shown on the original )</p></body></html>", nullptr));
        Gauss->setText(QApplication::translate("PSettings", "<html><head/><body><p align=\"center\"><span style=\" font-weight:600;\">Bluring effect</span></p></body></html>", nullptr));
        GaussInfo->setText(QApplication::translate("PSettings", "<html><head/><body><p>The program blur can make better transitioning at objects of one color and corrigate the failures caused by shadows</p></body></html>", nullptr));
        dispObj->setText(QApplication::translate("PSettings", "<html><head/><body><p><span style=\" font-weight:600;\">Displayed object(s):</span></p></body></html>", nullptr));
        selectedObject->setText(QApplication::translate("PSettings", "Selected only ( Show only the clicked object )", nullptr));
        allObject->setText(QApplication::translate("PSettings", "Detect all ( Show every object )", nullptr));
        label->setText(QApplication::translate("PSettings", "<html><head/><body><p><span style=\" font-weight:600;\">Marker Color:</span></p></body></html>", nullptr));
        label_2->setText(QApplication::translate("PSettings", "R", nullptr));
        label_3->setText(QApplication::translate("PSettings", "G", nullptr));
        label_4->setText(QApplication::translate("PSettings", "B", nullptr));
        maxDiv_Title->setText(QApplication::translate("PSettings", "<html><head/><body><p><span style=\" font-weight:600;\">Maximum Diversity:</span></p></body></html>", nullptr));
        label_5->setText(QApplication::translate("PSettings", "This much diversity distance can be beetween two frame's \"same\" object (on process resolution)", nullptr));
        loseTrackingTitle->setText(QApplication::translate("PSettings", "<html><head/><body><p><span style=\" font-weight:600;\">Lose Tracking:</span></p></body></html>", nullptr));
        label_7->setText(QApplication::translate("PSettings", "After losing the object tracking how many frame is available to get back into tracking", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PSettings: public Ui_PSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PSETTINGS_H
