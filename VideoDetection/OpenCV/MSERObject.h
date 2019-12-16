#pragma once

#include <vector>
#include <opencv2/opencv.hpp>
#include "Utils.h"

class MSERObject
{
public:
    // Number of MSER's pixels
    int pNumber;

    // Extremal (Maximum and Minimum) values of X and Y values.
    // The MSER's pixels' lowest and highest values of X and Y.
    ExtremeValues globalX, globalY;

    // The average color of the pixels
    double colorAvg = -1;

    // Gray level where this object is created
    int gl;

    // If the object is declared = true
    // else = false
    bool declared;

	MSERObject();
    MSERObject(int pointNumber, ExtremeValues x, ExtremeValues y, double colAvg = -1, int gl = -1);
	~MSERObject();

    // Calc the area from Extremal values
	double getArea();

    // Calc the center from Extremal values
    cv::Point getCenter();

    // Is the object empty?
    bool empty();

    // Draw the object onto an image (should have the scaling = original / shrinked)
    // to scale its values up
	void drawOntoImage(cv::Mat& img, double scaling, cv::Scalar color);

    // For write it out if u want
	friend std::ostream& operator<<(std::ostream& os, const MSERObject& mser);
};

std::ostream& operator<<(std::ostream& os, const MSERObject& mser);
