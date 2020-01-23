#pragma once
#include <iostream>
#include <fstream>
#include <future>
#include <omp.h>

#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/highgui/highgui_c.h>

#include "OpenCV/ImageProcessing.h"
#include "OpenCV/MSER.h"

class Detector
{
private:
    // The image processing unit
    ImageProcessing imgProc = ImageProcessing();

    // The actual image
	cv::Mat img;

    // The actual video
	cv::VideoCapture video;

    // The name of the display window
    std::string wName;

    // Start time of actual detection
    std::chrono::system_clock::time_point detStart;

    // End time of actual detection
	std::chrono::system_clock::time_point detEnd;
	
    // The minimum time (milliseconds) of a frame to show
    double frameTime = 30;

    // The SUM of all the detection time in one detection
    double detDurSum = 0;

    // The Count of the detected frames
    int detCount = 0;
public:
    // The name of the window which contains the video
    static const std::string videoWName;

    // The name of the window which contains the image
    static const std::string imageWName;


    Detector(std::string wName = "Video detection");
	Detector(cv::VideoCapture video, std::string wName);
	Detector(cv::Mat image, std::string wName);
	~Detector();

	// Setters
    // Sets the name of the window where it will display image
    void setWindow(std::string wName);
    // Set the image
	void setImage(cv::Mat image);
    // Set the video
    void setVideo(cv::VideoCapture video);

    // Plays video with the 2 modes
    // Selected only -> MSER::CLICKED_DET
    // shows video frame by frame and if there's any change in CLICK struct
    // it will detect the clicked object and track it (if there's)
    // Detect all -> MSER::FULL_DET
    // shows the video frame by frame with all the detected objects
    void playVideo();

    // Show img with the 2 modes
    // Selected only -> MSER::CLICKED_DET
    // shows img and if there's any change in CLICK struct
    // it will detect the clicked object and show that (if there's)
    // Detect all -> MSER::FULL_DET
    // shows the image with all the detected objects
    void playImage();
	
	// Image Stuff ////////
    // Show image
	void showImage();
    // Returns image
    cv::Mat getImg();

    // It will show the clicked detection's result if
    // there was any show it anyway just the picture
    void showImageWithDet();

    // Returns the image with clicked detection if there was show it anyway just the picture
    cv::Mat getImgWithDet();

    // Show an image's all detection
    void detAllMode();

    // Show an image.
    // Detect the clicked region.
    void selectedOnlyMode();
};

