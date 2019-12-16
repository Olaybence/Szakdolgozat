#pragma once

#include <string>
#include <sstream>
#include <opencv2/opencv.hpp>

// QT
#include <QString>
#include <QDir>
#include <QFile>
#include <QStringList>
#include <QDebug>
#include <QImage>
#include <QLabel>
#include <QApplication>

class MSERObject;

// Global functions

// Returns the distance between a point and an MSER's center
double pointMSERDist(MSERObject mser, cv::Point point);

// Returns if a point inside an MSER object (MSERs are from a shrinked down img)
// so scale up required
bool pointInsideMSER(MSERObject mser, cv::Point p, double shrinkRate);

// Mouse callback for register the clicks
void mouseClick(int event, int x, int y, int flags, void* userdata);

// Check wether a window is on opened or not
bool isWindowOpen(std::string wName);

// Executes a linux command and returns the output of it
std::string exec(const char* cmd);

// Global structs

// Extreme values
// Stores a maximum and a minimum value
struct ExtremeValues {
    double min, max;
    // Is it declared or not
    bool declared = true;

	ExtremeValues();
	ExtremeValues(double x);
	ExtremeValues(double min, double max);

    // Change the values if it's needed
	void change(double x);
};

struct Click {
    // Was a click
    static bool done;

    // Click position
	static cv::Point point;

    // Detected object
	static MSERObject object;

    // Is it in tracking mode
    // (there was a detected which should be followed)
    static bool tracking;

    // This much frame passed from the last recognition
    static unsigned int undetectedCounter;

    // Reset the object point and click property
    static void resetAll();
};
