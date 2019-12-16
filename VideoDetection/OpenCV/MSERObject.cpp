#include "MSERObject.h"
#include <vector>
#include <opencv2/opencv.hpp>

MSERObject::MSERObject() : declared(false)
{
}

MSERObject::MSERObject(int pNumber, ExtremeValues x, ExtremeValues y, double colAvg, int grayLevel)
    : pNumber(pNumber), globalX(x), globalY(y), colorAvg(colAvg), gl(grayLevel), declared(true)
{
}

MSERObject::~MSERObject()
{
}

bool MSERObject::empty() {
    return !declared;
}

double MSERObject::getArea()
{
    if (empty()) {
		std::cout << "MSERObj not declared in getArea() returned with 0" << std::endl;
		return 0;
	} else return (globalX.max - globalX.min)*(globalY.max - globalY.min);
}

cv::Point MSERObject::getCenter()
{
    if (empty()) {
		std::cout << "MSERObj not declared in getCenter() returned with (-1,-1)" << std::endl;
		return cv::Point(-1, -1);
    } else return cv::Point(static_cast<int>(globalX.min + std::abs(globalX.max - globalX.min)/2),
                            static_cast<int>(globalY.min + std::abs(globalY.max - globalY.min)/2));
}

void MSERObject::drawOntoImage(cv::Mat& img, double scaling, cv::Scalar color) {
    if (empty()) {
		std::cout << "MSERObj not declared in drawOntoImage()" << std::endl;
		return;
	}
    cv::rectangle(img, cv::Rect(cv::Point(static_cast<int>(globalY.min * scaling), static_cast<int>(globalX.min * scaling)),
                                cv::Point(static_cast<int>(globalY.max * scaling), static_cast<int>(globalX.max * scaling))),
								color);
}

std::ostream& operator<<(std::ostream& os, const MSERObject& mser)
{
	os << "[" << mser.globalX.max << "," << mser.globalY.max << "] - ["
		<< mser.globalX.min << "," << mser.globalY.min << "]";
	return os;
}
