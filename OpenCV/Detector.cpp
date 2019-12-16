#include "Detector.h"

#include <sys/cdefs.h>

const std::string Detector::videoWName = std::string("Video detection");
const std::string Detector::imageWName = std::string("Image detection");



Detector::Detector(std::string wName) : wName(wName) {
}

Detector::Detector(cv::VideoCapture video, std::string wName) : video(video), wName(wName) {
}

Detector::Detector(cv::Mat image, std::string wName) : img(image), wName(wName)
{
    imgProc.setImage(image);
}

Detector::~Detector()
{
}

void Detector::setWindow(std::string windowName)
{
    wName = windowName;
}

void Detector::setImage(cv::Mat image)
{
	imgProc.setImage(image);
	img = image;
}

void Detector::setVideo(cv::VideoCapture v)
{
	Click::resetAll();
	video = v;
    MSER::actVideo = v;
}

void Detector::playVideo()
{

	if (!video.isOpened()) {
		std::cout << "No video added!" << std::endl;
		return;
    }

    // Set the timer of the video to the beginning
    video.set(CV_CAP_PROP_POS_FRAMES, 0);

	cv::Mat frame;
	int frameCounter = 0;
    std::chrono::duration<double> detDur;

    video >> frame;
    if (frame.empty()) {
        std::string tmp = "Couldn't read frame from video.";
        QMessageBox msg(QMessageBox::Warning,"Video error",tmp.c_str());
        msg.exec();
        return;
    }
    setImage(frame);
    showImage();

    cv::waitKey(100);
    while (isWindowOpen(wName)) {

        video >> frame;
		// Exit if there's no more frame
        if (frame.empty() || !video.isOpened()) {
            std::cout << "Video ended! (no more frames)\n";
            break;
        }

		detStart = std::chrono::system_clock::now();
		frameCounter++;
		setImage(frame);
		std::cout << frameCounter << "th frame loaded!" << std::endl;
        switch (MSER::detectionMode) {
        case MSER::FULL_DET: // Show all the detections' rectangle
            detAllMode();
            break;
        case MSER::SELECT_DET: // Detect mouse clicks then show and track clicked object
            selectedOnlyMode();
			break;
		default:
            std::cout << "There's no video playing mode with ID: " << MSER::detectionMode << std::endl;
            break;
		}

		detEnd = std::chrono::system_clock::now();
        detDur = detEnd - detStart;

        if(MSER::detectionMode == MSER::SELECT_DET && !Click::object.empty()) { // Selected only and was actual detection
            std::cout << "Detection duration: " << detDur.count() << std::endl;
            detDurSum += detDur.count();
            detCount++;
        } else if(MSER::detectionMode == MSER::FULL_DET){ // Full detection
            detDurSum += detDur.count();
            detCount++;
        }

        double waitTime = frameTime - detDur.count() * 1000 > 0 ? frameTime - detDur.count() * 1000 : 1;
        std::cout << "added waitTime (millisecond): " << waitTime << std::endl;
        if (cv::waitKey(static_cast<int>(waitTime + 1)) == 27) {
            cv::destroyWindow(wName);
            break;
        }
    }

    std::cout << "Video end!\n";
    cv::destroyWindow(wName);
    video.release();

    if(detCount != 0) {
        std::string tmp = "Video end!\n\nAverage duration: " + std::to_string( detDurSum / detCount ) + "\n" +
                          "Detected frames: " + std::to_string(detCount) + "\n" +
                          "Time of detections: " + std::to_string(detDurSum) + "\n";
        QMessageBox msg(QMessageBox::Information,"Detect informacions",tmp.c_str());
        msg.exec();

        detCount = 0;
        detDurSum = 0;
    }
}

void Detector::playImage() {
    switch(MSER::detectionMode) {
        case MSER::FULL_DET:
            detAllMode();
        break;
        case MSER::SELECT_DET:

            // Add the mouse click callback function
            showImage();
            cv::setMouseCallback(wName, mouseClick, (void*)this);

            cv::waitKey(100);
            while(isWindowOpen(wName)) {
                if(Click::done) {
                    imgProc.detectImage();
                    if(!Click::object.empty()) {
                        showImageWithDet();
                    } else {
                        cv::displayOverlay(wName,"Object not detected",2000);
                    }
                    Click::resetAll();
                }

                if(cv::waitKey(static_cast<int>(frameTime)) == 27) {
                    cv::destroyWindow(wName);
                    break;
                }
            }
            std::cout << "checking!"<< std::endl;
        break;
        default:
            std::string text = "There's no image playing mode like this.\nPlease choose one from the settings!";
            QMessageBox msg(QMessageBox::Information,"Error",text.c_str());
            msg.exec();
        break;
    }
}

void Detector::showImage()
{
    std::cout << "Just showImage()!" << std::endl;
	if (!wName.empty() && !img.empty()) {
        cv::imshow(wName,img);
    } else {
        if (wName.empty()) std::cout << "No window name given!" << std::endl;
        if (img.empty()) std::cout << "No image given!" << std::endl;
	}
}

cv::Mat Detector::getImg() {
    return img;
}

void Detector::showImageWithDet()
{
    if (!wName.empty() && !img.empty()) {
        cv::Mat withDet = img.clone();
        if(!Click::object.empty()) {
            std::cout << "Object was detected!" << std::endl;

            // Draw the object's Rect onto the image
            Click::object.drawOntoImage(withDet, imgProc.getScaling(), MSER::drawingColor);

            // Output the result
            cv::imshow(wName,withDet);
        } else {
            std::cout << "Unfortionately no obejt detected!" << std::endl;

            // Output the result
            cv::imshow(wName,img);
        }
    } else {
        if (!wName.empty()) std::cout << "No window name given!" << std::endl;
        if (!img.empty()) std::cout << "No image given!" << std::endl;
	}
}

cv::Mat Detector::getImgWithDet() {
    cv::Mat withDet = img.clone();
    if(!Click::object.empty()) {
        // Draw the object's Rect onto the image
        Click::object.drawOntoImage(withDet, imgProc.getScaling(), MSER::drawingColor);
    }
    return withDet;
}

void Detector::detAllMode()
{
    imgProc.detectImage();
    imgProc.showDetections(wName, img, MSER::drawingColor);
}

void Detector::selectedOnlyMode()
{
	// Add the mouse click callback function
    cv::setMouseCallback(wName, mouseClick,(void*)this);

	if (Click::done) { // The USER clicked
        cv::Point clicked = Click::point;
        Click::resetAll();

        imgProc.detectImage();
        Click::object = imgProc.detectClickedObject(clicked);

        if (!Click::object.empty()) {
			showImageWithDet();
            Click::tracking = true;
		}
		else {
            showImage();
            cv::displayOverlay(wName,"Couldn't detect any object",2000);
        }
	}
    // It's in tracking mode
    else if (Click::tracking) {
        std::cout << "Detected object tracking!" << std::endl;
        imgProc.detectImage();

        MSERObject nextObj = imgProc.trackClickedObject();

        // If detected -> ok
        if(!nextObj.empty()) {
            Click::object = nextObj;
            showImageWithDet();
        }
        // Doesn't found a new object
        // -> it's undetected
        else {
            showImage();
            Click::undetectedCounter++;
            std::cout << "object undetectedCounter: " << Click::undetectedCounter << "\n";
            if(Click::undetectedCounter > MSER::loseTracking) {
                cv::displayOverlay(wName,"Object lost",2000);
                Click::resetAll();
            }
        }
	}
	// Just show it
	else {
		showImage();
	}
}
