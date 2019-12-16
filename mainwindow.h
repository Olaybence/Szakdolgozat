#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QLabel>
#include <QMessageBox>
#include <QSettings>
#include <QStandardPaths>

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "OpenCV/Utils.h"
#include "psettings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Click function of select image
    // Open file browser and save the path of image
    // If there was file selected
    void on_selectImage_clicked();

    // Click function of select video
    // Open file browser and save the path of video
    // If there was file selected
    void on_selectVideo_clicked();

    // Open the parameters settings menu
    void on_parameterSettings_clicked();

    // Start detection of the given image
    // If there's no then error message
    void on_detectImage_clicked();

    // Start detection of the given video
    // If there's no then error message
    void on_detectVideo_clicked();

    // Exit the application
    void on_exit_clicked();

private:
    Ui::MainWindow *ui;
    PSettings* ps;
    Detector* det;
};
#endif // MAINWINDOW_H
