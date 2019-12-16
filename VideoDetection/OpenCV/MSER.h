#ifndef MSER_H
#define MSER_H

#include <string>
#include <opencv2/opencv.hpp>

// QT
#include <QString>
#include <QDir>
#include <QFile>
#include <QImage>
#include <QMessageBox>

class MSER {
public:
    // Shared Data
    // Path of MSERparams.csv file
    static const QString    dataPath;
    // Act loaded image
    static cv::Mat          actImage;
    // Act loaded image's path
    static QString          actImageUrl;
    // Act loaded video
    static cv::VideoCapture actVideo;
    // Act loaded video's path
    static QString          actVideoUrl;

    // Detection Parameters

    // Drawing color
    static cv::Scalar   drawingColor;

    // If the image is bigger then resize it to a smaller one.
    static double   maxResolution;

    // prune the area which smaller than minArea
    static double   minArea;

    // prune the area which bigger than maxArea
    static double   maxArea;

    // for color image, the aperture size for edge blur
    static cv::Size gaussBlurKernelSize;

    // The maximum distance between the center of the fitting object
    // and the last detected object's center
    static double   maxDiversity;

    // If this much frame past from losing the tracking object
    // It's lost
    static unsigned int loseTracking;

    // Write the parameters into file
    static void writeParamsIntoFile();

    // Load the parameters from file
    static void loadFromFile();

    // Print MSER parameters onto OS
    static void printMSER(std::ostream& os);

    // This is the detection's mode
    static int detectionMode;

    // Playing modes

    // Selected only mode
    static const int SELECT_DET = 0;

    // Detect all mode
    static const int FULL_DET = 1;
};
#endif // MSER_H
