#pragma once

#include <opencv2/opencv.hpp>
#include <string>

#include "OpenCV/Layer.h"
#include "OpenCV/Utils.h"
#include "OpenCV/MSER.h"

class ImageProcessing
{
private:
    // The original image
    cv::Mat origImg;

    // The scaled down, grayscaled, Gaussian blured image for processing
    cv::Mat processImg;
	
	// The original was shrinked by this much 
	// shrinkedImg = origImg / shrinkRate
	// -> origImg = shrinkRate * shrinkedImg
	double shrinkRate;

    // Layers from black to white
    std::vector<Layer> layersBToW;

    // Layers from white to black
    std::vector<Layer> layersWToB;

    // The default cutting values
    static const std::vector<int> defaultCuttingValues;

    // The cutting values for the layers
    // This will make the cut in the 0-255 range of pixel value
    std::vector<int> cutingValues = defaultCuttingValues;

    // It goes throw the whole procesImg
    // and give the pixel value to the layers
    // so the layers can make them own boolean matrix of the image
	void setLayerPixels();

    // This will call the MSER region maker function of all the layers
	void detectMSERs();
public:
	ImageProcessing();
	~ImageProcessing();
	
    // Set the image
    void setImage(cv::Mat img);

    // Set the cutting values
    // Set the Layers pixels
    // Make the MSERs from the Layers
    // Detect if there was any click (call detectClickedObject())
    // Track if there is any object (call trackClickedObject())
    void detectImage();

    // Set the image and call detectImage()
    void detectImage(cv::Mat inImg);

    // Go throw all layers' MSERs and
    // check if the MSER suitable for the click
    MSERObject detectClickedObject(cv::Point p);

    // Go throw all layers' MSERs and
    // check if the MSER is the tracked object
    MSERObject trackClickedObject();

    // Show all detections of layers
    void showDetections(std::string wName, cv::Mat img, cv::Scalar color);


    // Show each layer's detected mserObject an image
    void showLayers(cv::Mat image);

    // Set the cutting values
    // If there's an object detected then make less and targeted values
    // Otherwise use the defaultCV-s
    void setCuttingValues();

    // Returns the number of detected objects on the different layers.
    int detectedObjects();
    double getScaling();
};

