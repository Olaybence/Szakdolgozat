#include "Layer.h"
#include <string> 

const std::string Layer::BToW = "BToW";
const std::string Layer::WToB = "WToB";

Layer::Layer(int gl, std::string direction)
	: grayLevel(gl),
    dirBToW(direction == BToW),
	layerName(std::to_string(gl) + "layer" + direction) {}

Layer::~Layer()
{
}

void Layer::setPixel(int x, int y, uchar color) {
	if (img.empty()) {
		std::cout << "Layer" << layerName << " had no img given" << std::endl;
		return;
	}

    int c = static_cast<int>(color);
    if ( (dirBToW && c < grayLevel) ||
         (!dirBToW && grayLevel < c)) {
        blackPoints[x][y] = true;
	}
}

void Layer::setImg(cv::Mat image, double s) {
    img = image;
    xMax = image.size().height;
    yMax = image.size().width;
	scaling = s;
    blackPoints = std::vector<std::vector<bool>>(xMax, std::vector<bool>(yMax, false)); // xMax row num./ yMax col num.
}

void Layer::makeMSERs()
{
	/*std::cout << "Start waterflood " << layerName << std::endl;
	std::cout << "x range (0-" << xMax << ") | y range (0-" << yMax << ")\n";*/
    for (int x = 0; x < xMax; x++) {
        for (int y = 0; y < yMax; y++) {
			if (blackPoints[x][y]) {
				//std::cout << layerName << " - getMSERObject(" << x << "," << y << ")\n";
                MSERObject tmp = getMSERObject(x, y);
				// If the area isn't big enough or huge (like a background) don't add it to the array
				if (MSER::minArea < tmp.pNumber &&
					tmp.pNumber < MSER::maxArea) {
					mserObjects.push_back(tmp);
				}
				//std::cout << "After waterFlood - size: " << tmp.pNumber << " extreme values: ("
				//	<< tmp.globalX.max << "," << tmp.globalY.max << " - (" << " " << tmp.globalX.min << "," << tmp.globalY.min << std::endl;
			}
		}
	}
}

MSERObject Layer::getMSERObject(int x, int y) {
	
	// Start with a point ///////////
	// The extreme points
	ExtremeValues xEV(x), yEV(y);
	
	// Number of points in the object
	int mserPN = 1;
	int colorSum = 0;
	std::vector<cv::Point> points;

	// If it's not a matrix variable of it's not a black point on the picture
	// Don't start the explicit recursive algorithm!
    if (x < 0 || xMax < x ||
        y < 0 || yMax < y ||
		!blackPoints[x][y]) {
		return MSERObject();
	}

	// The stack of the potential pixel points.
	std::deque<cv::Point> worklist;
	worklist.push_back(cv::Point(x, y));

	// Explicit recursive call (Implicit would provide STACKOVERFLOW!)
	cv::Point act;
	while (!worklist.empty()) {
		//std::cout << "In the stack: " << worklist.size() << " act: " << act << "\n";

		act = worklist[0];
		worklist.pop_front();

		mserPN++;
		points.push_back(act);
		colorSum += img.at<uchar>(x, y);
		xEV.change(act.x);
		yEV.change(act.y);
		blackPoints[act.x][act.y] = false;

		std::array<cv::Point, 8> indexes = {
			cv::Point(act.x - 1,act.y - 1),
			cv::Point(act.x - 1,act.y),
			cv::Point(act.x - 1,act.y + 1),

			cv::Point(act.x,	act.y - 1),
			cv::Point(act.x,	act.y + 1),

			cv::Point(act.x + 1,act.y - 1),
			cv::Point(act.x + 1,act.y),
			cv::Point(act.x + 1,act.y + 1),
		};

        for (size_t i = 0; i < indexes.size(); i++) {
			// PUT into the worklist ONLY IF 
            cv::Rect imageFrame(cv::Point(0,0), cv::Point(xMax,yMax));
			if (std::find(worklist.begin(), worklist.end(), indexes[i]) == worklist.end() && // NOT in the worklist already
				imageFrame.contains(indexes[i]) &&
				blackPoints[indexes[i].x][indexes[i].y]) // AND has TRUE value
			{
				worklist.push_back(indexes[i]);
			}
		}

	}

	/*std::cout << "After waterFlood - size: " << mserPN << " extreme values: (" 
				<< xEV.max << "," << yEV.max << " - (" << " " << xEV.min << "," << yEV.min << std::endl;*/
    double colorAvg = colorSum / mserPN;
    return MSERObject(static_cast<int>(points.size()),xEV,yEV,colorAvg, grayLevel);
}

std::vector<MSERObject> Layer::getAllMSERObjects()
{
	return mserObjects;
}

void Layer::displayLayerWithDet(cv::Scalar c)
{
	cv::Mat tmp = img.clone();
    for (size_t i = 0; i < mserObjects.size(); i++) {
		mserObjects[i].drawOntoImage(tmp, scaling, c);
	}
    cv::imshow(layerName,tmp);
}

void Layer::drawDetections(cv::Mat& image, size_t n, cv::Scalar color)
{
    for (size_t i = 0; i < n && i < n; i++) {
        mserObjects[i].drawOntoImage(image, scaling, color);
	}
}

void Layer::drawAllDetection(cv::Mat & image, cv::Scalar color)
{
    drawDetections(image, static_cast<int>(mserObjects.size()), color);
}
