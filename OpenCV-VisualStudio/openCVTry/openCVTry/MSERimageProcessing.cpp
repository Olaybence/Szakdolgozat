#include "pch.h"
#include <iostream>
#include <filesystem>
#include <string>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

string concatToFilename(string filename, string subfix) {
	return filename.substr(0, filename.find(".")) + subfix + "." + filename.substr(filename.find(".") + 1, filename.size());
}

Mat processImage(Mat img) {
	cout << "image size:" << img.size();
	Ptr<MSER> ms = MSER::create();
	vector<vector<Point> > regions;
	vector<Rect> mser_bbox;
	cout << "MSER, regions and mser_bbox created." << endl;
	cout << "detectRegions..." << endl;
	ms->detectRegions(img, regions, mser_bbox);
	cout << "number of regions: " <<  regions.size() << "drawing in the regions." << endl;
	for (int i = 0; i < regions.size(); i++)
	{
		drawContours(img, regions, i, Scalar(255, 0, 0), 1, 8);
	}

	imshow("mser", img);
	return img;
}

int main()
{
	string path = "Photos";
	for (const auto & entry : filesystem::directory_iterator(path)) {
		cout << entry.path() << endl;
		if (entry.path.find(".jpg")) {
			Mat image = imread(entry.path().string());
			Mat result = processImage(image);
			FileStorage file(concatToFilename(entry.path().string(),"_result"), FileStorage::WRITE);
			file << result;
		}
	}
	
	return 0;
}