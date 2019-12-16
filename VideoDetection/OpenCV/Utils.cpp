#pragma once

#include <string>
#include <opencv2/opencv.hpp>
#include <QImage>
#include "Detector.h"
#include "MSERObject.h"

// Global Functions ///////////////////

// Returns the distance beetween mser's center and the point 
// diveded by the square of MSER's area.
extern double pointMSERDist(MSERObject mser, cv::Point p) {
	return cv::norm(mser.getCenter() - p);
}

extern bool pointInsideMSER(MSERObject mser, cv::Point p, double shrinkRate) {
    cv::Rect mserFrame(	cv::Point(mser.globalX.min * shrinkRate, mser.globalY.min * shrinkRate),
                        cv::Point(mser.globalX.max * shrinkRate, mser.globalY.max * shrinkRate));
	return mserFrame.contains(p);
}

extern void mouseClick(int event, int x, int y, int flags, void* userdata)
{
	if (event == cv::EVENT_LBUTTONDOWN)
	{
        std::cout << "Left button of the mouse is clicked - position (" << std::to_string(y) << ", " << std::to_string(x) << ")" << std::endl;
		Click::done = true;
        Click::point = cv::Point(y, x);
    }
}

std::string exec(const char* cmd) {
    std::array<char, 128> buffer;
    std::string result;
    std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd, "r"), pclose);
    if (!pipe) {
        throw std::runtime_error("popen() failed!");
    }
    while (fgets(buffer.data(), buffer.size(), pipe.get()) != nullptr) {
        result += buffer.data();
    }
    return result;
}

bool isWindowOpen(std::string wName) {
    std::string line = exec("wmctrl -l");
    return line.find(wName) != std::string::npos;
}


// ExtremeValues ///////////////////

ExtremeValues::ExtremeValues() {}
ExtremeValues::ExtremeValues(double x) : min(x), max(x) {}
ExtremeValues::ExtremeValues(double min, double max) : min(min), max(max) {}
void ExtremeValues::change(double x) {
    if (x > max || declared) {
		max = x;
        declared = false;
	}
    if (x < min || declared) {
		min = x;
        declared = false;
	}
}

// Click ///////////////////

bool Click::done = false;
cv::Point Click::point = cv::Point(-1, -1);
MSERObject Click::object = MSERObject();
bool Click::tracking = false;
unsigned int Click::undetectedCounter = 0;

void Click::resetAll() {
	done = false;
	object = MSERObject();
    std::cout << "reseted empty(): " << (object.empty() ? "True" : "False") << std::endl;
	point = cv::Point(-1, -1);
    tracking = false;
    undetectedCounter = 0;
}
