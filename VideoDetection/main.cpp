#include "mainwindow.h"

#include <iostream>
#include <cstdlib>
#include <chrono>
#include <string>

#include <omp.h>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

#include "OpenCV/Utils.h"
#include "OpenCV/Detector.h"

#include <QApplication>
#include <QDirIterator>
#include <QDir>

int main(int argc, char *argv[])
{
    printf("OpenCV: %s", cv::getBuildInformation().c_str());
    MSER::loadFromFile();
    QApplication a(argc, argv);
    MainWindow w;
    w.setAttribute(Qt::WA_QuitOnClose);
    w.show();
    return a.exec();
}
