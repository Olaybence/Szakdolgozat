/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *detectVideo;
    QPushButton *parameterSettings;
    QPushButton *selectVideo;
    QPushButton *detectImage;
    QPushButton *selectImage;
    QLabel *selectedVideoLabel;
    QLabel *selectedImageLabel;
    QLabel *selectedImageUrl;
    QLabel *selectedVideoUrl;
    QLabel *author;
    QLabel *Title;
    QPushButton *exit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(680, 693);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-image: url(:/Background/mainBackground) no-repeat center center fixed;\n"
"background-repeat: no-repeat;"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        detectVideo = new QPushButton(centralwidget);
        detectVideo->setObjectName(QString::fromUtf8("detectVideo"));
        detectVideo->setGeometry(QRect(60, 570, 231, 25));
        detectVideo->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);\n"
"font: 75 12pt \"URW Bookman L\";\n"
"background-color: rgb(114, 159, 207);"));
        parameterSettings = new QPushButton(centralwidget);
        parameterSettings->setObjectName(QString::fromUtf8("parameterSettings"));
        parameterSettings->setGeometry(QRect(230, 620, 221, 25));
        parameterSettings->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);\n"
"font: 75 12pt \"URW Bookman L\";\n"
"background-color: rgb(114, 159, 207);"));
        selectVideo = new QPushButton(centralwidget);
        selectVideo->setObjectName(QString::fromUtf8("selectVideo"));
        selectVideo->setGeometry(QRect(60, 530, 231, 25));
        selectVideo->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);\n"
"font: 75 12pt \"URW Bookman L\";\n"
"background-color: rgb(114, 159, 207);"));
        detectImage = new QPushButton(centralwidget);
        detectImage->setObjectName(QString::fromUtf8("detectImage"));
        detectImage->setGeometry(QRect(390, 570, 231, 25));
        detectImage->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);\n"
"font: 75 12pt \"URW Bookman L\";\n"
"background-color: rgb(114, 159, 207);"));
        selectImage = new QPushButton(centralwidget);
        selectImage->setObjectName(QString::fromUtf8("selectImage"));
        selectImage->setGeometry(QRect(390, 530, 231, 25));
        selectImage->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);\n"
"font: 75 12pt \"URW Bookman L\";\n"
"background-color: rgb(114, 159, 207);"));
        selectedVideoLabel = new QLabel(centralwidget);
        selectedVideoLabel->setObjectName(QString::fromUtf8("selectedVideoLabel"));
        selectedVideoLabel->setGeometry(QRect(100, 430, 151, 21));
        selectedVideoLabel->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);\n"
"font: 75 12pt \"URW Bookman L\";"));
        selectedVideoLabel->setAlignment(Qt::AlignCenter);
        selectedImageLabel = new QLabel(centralwidget);
        selectedImageLabel->setObjectName(QString::fromUtf8("selectedImageLabel"));
        selectedImageLabel->setGeometry(QRect(430, 430, 151, 21));
        selectedImageLabel->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);\n"
"font: 75 12pt \"URW Bookman L\";"));
        selectedImageLabel->setAlignment(Qt::AlignCenter);
        selectedImageUrl = new QLabel(centralwidget);
        selectedImageUrl->setObjectName(QString::fromUtf8("selectedImageUrl"));
        selectedImageUrl->setGeometry(QRect(350, 460, 311, 61));
        selectedImageUrl->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);\n"
"font: 75 12pt \"URW Bookman L\";"));
        selectedImageUrl->setAlignment(Qt::AlignCenter);
        selectedImageUrl->setWordWrap(true);
        selectedVideoUrl = new QLabel(centralwidget);
        selectedVideoUrl->setObjectName(QString::fromUtf8("selectedVideoUrl"));
        selectedVideoUrl->setGeometry(QRect(20, 460, 311, 61));
        selectedVideoUrl->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);\n"
"font: 75 12pt \"URW Bookman L\";"));
        selectedVideoUrl->setAlignment(Qt::AlignCenter);
        selectedVideoUrl->setWordWrap(true);
        author = new QLabel(centralwidget);
        author->setObjectName(QString::fromUtf8("author"));
        author->setGeometry(QRect(30, 650, 101, 21));
        author->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);\n"
"font: italic 10pt \"URW Bookman L\";"));
        Title = new QLabel(centralwidget);
        Title->setObjectName(QString::fromUtf8("Title"));
        Title->setGeometry(QRect(210, 30, 271, 81));
        QFont font;
        font.setFamily(QString::fromUtf8("URW Bookman L"));
        font.setPointSize(22);
        font.setBold(false);
        font.setItalic(true);
        font.setWeight(50);
        Title->setFont(font);
        Title->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);\n"
"font: italic 22pt \"URW Bookman L\";"));
        Title->setWordWrap(true);
        exit = new QPushButton(centralwidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(570, 650, 81, 25));
        exit->setStyleSheet(QString::fromUtf8("color: rgb(114, 159, 207);\n"
"font: 75 12pt \"URW Bookman L\";\n"
"background-color: rgb(114, 159, 207);"));
        MainWindow->setCentralWidget(centralwidget);
        Title->raise();
        detectVideo->raise();
        parameterSettings->raise();
        selectVideo->raise();
        detectImage->raise();
        selectImage->raise();
        selectedVideoLabel->raise();
        selectedImageLabel->raise();
        selectedImageUrl->raise();
        selectedVideoUrl->raise();
        author->raise();
        exit->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        detectVideo->setText(QApplication::translate("MainWindow", "Detect video", nullptr));
        parameterSettings->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        selectVideo->setText(QApplication::translate("MainWindow", "Select video", nullptr));
        detectImage->setText(QApplication::translate("MainWindow", "Detect image", nullptr));
        selectImage->setText(QApplication::translate("MainWindow", "Select image", nullptr));
        selectedVideoLabel->setText(QApplication::translate("MainWindow", "Selected Video", nullptr));
        selectedImageLabel->setText(QApplication::translate("MainWindow", "Selected Image", nullptr));
        selectedImageUrl->setText(QApplication::translate("MainWindow", "Empty", nullptr));
        selectedVideoUrl->setText(QApplication::translate("MainWindow", "Empty", nullptr));
        author->setText(QApplication::translate("MainWindow", "By Bence Olay", nullptr));
        Title->setText(QApplication::translate("MainWindow", "Object detection with OpenCV & QT", nullptr));
        exit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
