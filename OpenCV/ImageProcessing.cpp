#include "ImageProcessing.h"

const std::vector<int> ImageProcessing::defaultCuttingValues = { 75,105,135,150,165 };

void ImageProcessing::setLayerPixels()
{

    if (processImg.empty()) {
		std::cout << "Don't have picture for ImageProcessing::setLayerPixels()!" << std::endl;
		return;
	}

	// MAKE THE LAYERS //////////////////////
    for (int x = 0; x < processImg.rows; x++) {
        for (int y = 0; y < processImg.cols; y++) {
			// You can now access the pixel value colored -> as cv::Vec3b / grayscale -> as cv::uchar
			//std::cout << "x: " << x << "y: " << y << std::endl;

            uchar pixel = processImg.at<uchar>(x, y);
			
			#pragma omp parallel for
            for (int i = 0; i < layersBToW.size(); i++) {
				// Black out the pixels on the layers with the treshhold lower then the pixel's color
				layersBToW[i].setPixel(x, y, pixel);
				// Black out the pixels on the layers with the treshhold bigger then the pixel's color
				layersWToB[i].setPixel(x, y, pixel);
			}
		}
	}
}

void ImageProcessing::detectMSERs()
{
	// MAKE MSER OBJECTS //////////////////////
    #pragma omp parallel for
    for (int i = 0; i < cutingValues.size(); i++) {
        layersBToW[i].makeMSERs();
        // std::cout << "number of object on " << layersBToW[i].layerName << ": " << layersBToW[i].mserObjects.size() << std::endl;
		layersWToB[i].makeMSERs();
        // std::cout << "number of object on " << layersWToB[i].layerName << ": " << layersWToB[i].mserObjects.size() << std::endl;
	}
}

ImageProcessing::ImageProcessing()
{
}

ImageProcessing::~ImageProcessing()
{
}

void ImageProcessing::detectImage(cv::Mat image) {
	setImage(image);
	detectImage();
}

void ImageProcessing::detectImage()
{
    setCuttingValues();
	setLayerPixels();
	detectMSERs();
    std::cout << "detectedObjects: " << detectedObjects() << std::endl;
}

void ImageProcessing::showDetections(std::string wName, cv::Mat img, cv::Scalar color)
{
	cv::Mat tmp = img.clone();
    for (size_t i = 0; i < cutingValues.size(); i++) {
        layersBToW[i].drawAllDetection(tmp, color);
        layersWToB[i].drawAllDetection(tmp, color);
    }
    cv::imshow(wName,tmp);
}

MSERObject ImageProcessing::detectClickedObject(cv::Point p)
{
	MSERObject mser = MSERObject();
	std::cout << "Clicked point: " << p << std::endl;

    double minArea = -1;

    for (size_t i = 0; i < cutingValues.size(); i++) {
        //#pragma omp parallel for
        for (size_t j = 0; j < layersBToW[i].getAllMSERObjects().size(); j++) {
            MSERObject act = layersBToW[i].getAllMSERObjects()[j];

            if (pointInsideMSER(act, p, shrinkRate)) { // Check inclusion (THE clicked point is SKRINKED down to the process image!)
                std::cout << act << std::endl;
                if (act.getArea() < minArea || 0 > minArea) { // Save the smallest inclusion (0 > -> it's the first)
                    mser = act;
                    minArea = mser.getArea();
                }
			}
        }

        //#pragma omp parallel for
        for (size_t j = 0; j < layersWToB[i].getAllMSERObjects().size(); j++) {
            MSERObject act = layersWToB[i].getAllMSERObjects()[j];

            if (pointInsideMSER(act, p, shrinkRate)) { // Check inclusion (THE clicked point is SKRINKED down to the process image!)
                std::cout << act << std::endl;
                if (act.getArea() < minArea || 0 > minArea) { // Save the smallest inclusion (0 > -> it's the first)
                    mser = act;
                    minArea = mser.getArea();
                }
            }
        }

	}
    return mser;
}

MSERObject ImageProcessing::trackClickedObject()
{
    MSERObject mser = MSERObject();
    double clickedArea = Click::object.getArea();
    cv::Point clickedCenter = Click::object.getCenter();
    std::cout << "Tracking: " << Click::object << std::endl;

    double minArea = -1;

    for (size_t i = 0; i < cutingValues.size(); i++) {
        #pragma omp parallel for
        for (size_t j = 0; j < layersBToW[i].getAllMSERObjects().size(); j++) {
            MSERObject act = layersBToW[i].getAllMSERObjects()[j];

            if (pointInsideMSER(act, clickedCenter, 1) &&
                    std::abs(clickedArea - act.getArea()) < MSER::maxDiversity) { // Check inclusion

                if (act.getArea() < minArea || 0 > minArea) { // Save the smallest inclusion (0 > -> it's the first)
                    mser = act;
                    minArea = mser.getArea();
                }
            }
        }

        #pragma omp parallel for
        for (size_t j = 0; j < layersWToB[i].getAllMSERObjects().size(); j++) {
            MSERObject act = layersWToB[i].getAllMSERObjects()[j];

            if (pointInsideMSER(act, clickedCenter, 1) &&
                    std::abs(clickedArea - act.getArea()) < MSER::maxDiversity) { // Check inclusion

                if (act.getArea() < minArea || 0 > minArea) { // Save the smallest inclusion (0 > -> it's the first)
                    mser = act;
                    minArea = mser.getArea();
                }
            }
        }
    }

    return mser;
}

void ImageProcessing::showLayers(cv::Mat image)
{
	// SHOW/SAVE THE LAYERS
	#pragma omp parallel for
    for (int i = 0; i < cutingValues.size(); i++) {
		//std::cout << "mserObjects.size()" << layersBToW[i].mserObjects.size() << std::endl;
		cv::Mat tmp = image.clone();
        layersWToB[i].drawAllDetection(tmp,MSER::drawingColor);
        cv::imshow(layersBToW[i].layerName,tmp);

		//std::cout << "mserObjects.size()" << layersBToW[i].mserObjects.size() << std::endl;
		tmp = image.clone();
        layersWToB[i].drawAllDetection(tmp, MSER::drawingColor);
        cv::imshow(layersWToB[i].layerName,tmp);
	}
}

// Get the most frequent grayScales of the image
// and initialize the layers
void ImageProcessing::setCuttingValues()
{
    if (!Click::object.empty()) {
        int cAvg = static_cast<int>(std::floor(Click::object.colorAvg));
        std::cout << "Object average color: " << cAvg << std::endl;
    }
    //     std::vector<int> calculatedLevels;
    //
    //     calculatedLevels.push_back( cAvg - cAvg % 10 > 0    ? cAvg - cAvg % 10 : 0);
    //     calculatedLevels.push_back( cAvg + cAvg % 10 < 255  ? cAvg + cAvg % 10 : 255);
    //     calculatedLevels.push_back(Click::object.gl);
    //
    //     cutingValues = calculatedLevels;
    // } else {
        cutingValues = defaultCuttingValues;
    // }
    std::cout << "cutingValues.size(): " << cutingValues.size() << std::endl;
	layersBToW.clear();
	layersWToB.clear();
	
    for (size_t i = 0; i < cutingValues.size(); i++) {
		// Black to White layer initialize
        Layer tmp1 = Layer(cutingValues[i], Layer::BToW);
		layersBToW.push_back(tmp1);

		// White to Black layer initialize
        Layer tmp2 = Layer(cutingValues[i], Layer::WToB);
		layersWToB.push_back(tmp2);
	}

	#pragma omp parallel for
    for (size_t i = 0; i < layersBToW.size(); i++) {
        layersBToW[i].setImg(processImg, shrinkRate);
        layersWToB[i].setImg(processImg, shrinkRate);
	}
}

void ImageProcessing::setImage(cv::Mat image)
{
	if (image.empty()) {
		std::cout << "SetImage returned - because of empty image" << std::endl;
		return;
	}

    origImg = image;

    cv::Mat shrinkedImg;

    cv::Size origImgSize = image.size();
    double biggerSide = origImgSize.height > origImgSize.width ? origImgSize.height : origImgSize.width;

    if (biggerSide > MSER::maxResolution) {
		shrinkRate = biggerSide / MSER::maxResolution;
        resize(image, shrinkedImg, cv::Size(), 1 / shrinkRate, 1 / shrinkRate);
	} else {
        shrinkedImg = cv::Mat(image);
		shrinkRate = 1;
	}
	// Blur the image a bit
	cv::GaussianBlur(shrinkedImg, shrinkedImg, MSER::gaussBlurKernelSize, 0);

    // Make it black and white
    processImg = cv::Mat();
    cv::cvtColor(shrinkedImg, processImg, cv::COLOR_BGR2GRAY, CV_8U);

    imgSize = processImg.size();
    imgType = processImg.type();
	
	// This will be set at the time of detection.
	cutingValues = {};
}

int ImageProcessing::detectedObjects()
{
	int n = 0;
    for (size_t i = 0; i < cutingValues.size(); i++) {
        n += static_cast<int>(layersBToW[i].getAllMSERObjects().size());
        n += static_cast<int>(layersWToB[i].getAllMSERObjects().size());
	}
	return n;
}

double ImageProcessing::getScaling() {
	return shrinkRate;
}
