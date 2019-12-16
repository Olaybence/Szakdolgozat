#pragma once

#include <cmath>

#include <opencv2/opencv.hpp>

#include "OpenCV/MSERObject.h"
#include "OpenCV/MSER.h"

// A Grayscale layer of the image
class Layer
{
    // Graylevel is the cutting value of the layer
    int grayLevel;

    // Is the direction from black to white
    bool dirBToW;

    // Processing image (the shrinked blacked out version)
    cv::Mat img;

    // Shrinking variable from the original image
    double scaling;

    // Width and height of the picture
    int xMax, yMax;

    // Number of black pixels on the layer
    int pCount = 0;
	
    // Bool matrix of the processed image
	std::vector<std::vector<bool>> blackPoints;
public:
    // Array of detected MSERs
    std::vector<MSERObject> mserObjects = std::vector<MSERObject>();

    // Name of the layer
    std::string layerName;

    // String black to white "BToW" for unique layerName's
    static const std::string BToW;

    // String white to black "WToB" for unique layerName's
    static const std::string WToB;
	
	Layer(int gl, std::string direction);
	Layer(int gl, std::string direction, cv::Size size, int type);
	Layer(int gl, std::string direction, cv::Mat image);
	~Layer();

    // Set a pixel's value (in the bool matrix) depending on the given color
    void setPixel(int x, int y, uchar color);

    // Set the size of the blackPoints bool matrix
    // the scaling of the original and shrinked image ( origImg = scaling * shrinkedImg )
    void setImg(cv::Mat image, double scaling);

    // Create the MSERs from the blackPoints matrix
    // Go throw the bool matrix and call an MSER generator from each true point.
	void makeMSERs();

    // This will generate the MSER from a point with the explicit graph admittance
    MSERObject getMSERObject(int x, int y);

    // Return all the detected MSERs
    std::vector<MSERObject> getAllMSERObjects();

    // display layer's image with the detection if there's
    void displayLayerWithDet(cv::Scalar color);
	
	// Draw detections onto an image
    // Just n number of MSERs (max number is mserObjects.size())
    void drawDetections(cv::Mat& image, size_t n, cv::Scalar color);
	
	// drawDetections with all the objects
    void drawAllDetection(cv::Mat& image, cv::Scalar color);
};
