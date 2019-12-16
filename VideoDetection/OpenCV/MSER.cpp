#include "MSER.h"
#include "OpenCV/Utils.h"
#include "OpenCV/MSERObject.h"
#include "OpenCV/Detector.h"

int MSER::detectionMode = MSER::SELECT_DET;

// MSERparams ///////////////////

const QString MSER::dataPath("./Logs/MSERparams.csv");
cv::Scalar MSER::drawingColor = cv::Scalar(0, 255, 0);

QString MSER::actImageUrl = QString();
cv::Mat MSER::actImage = cv::Mat();
QString MSER::actVideoUrl = QString();
cv::VideoCapture MSER::actVideo = cv::VideoCapture();

double MSER::maxResolution = 150;
cv::Size MSER::gaussBlurKernelSize = cv::Size(3, 3);

double MSER::minArea = 5;
double MSER::maxArea = 3000;
double MSER::maxDiversity = 100;
unsigned int MSER::loseTracking = 10;

void MSER::writeParamsIntoFile() {
    // We create the directory if needed
    if (!QDir().exists("Logs")) {
        QDir().mkpath("Logs");
    }

    QFile mserFile(MSER::dataPath);
    if(!mserFile.isOpen()) {
        mserFile.open(QIODevice::ReadWrite);
        mserFile.setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner |
                                  QFileDevice::ReadUser | QFileDevice::WriteUser |
                                  QFileDevice::ReadOther | QFileDevice::WriteOther |
                                  QFileDevice::ReadGroup | QFileDevice::WriteGroup);
    }

    mserFile.flush();
    QTextStream mserf(&mserFile);

    mserf << "maxResolution;"   << MSER::maxResolution << "\n";
    mserf << "gbks;"           << MSER::gaussBlurKernelSize.width << "\n";
    mserf << "minArea;"         << MSER::minArea << "\n";
    mserf << "maxArea;"         << MSER::maxArea << "\n";
    mserf << "videoPlayMode;"   << MSER::detectionMode << "\n";
    mserf << "DrawingBlue;"   << MSER::drawingColor[0] << "\n";
    mserf << "DrawingGreen;"   << MSER::drawingColor[1] << "\n";
    mserf << "DrawingRed;"   << MSER::drawingColor[2] << "\n";
    mserf << "maxDiversity;" << MSER::maxDiversity << "\n";
    mserf << "loseTracking;" << MSER::loseTracking << "\n";
    mserFile.close();
    std::cout << "Saved into file" << std::endl;
}

void MSER::loadFromFile() {
    QFile paramsFile(MSER::dataPath);

    if(!paramsFile.isOpen()) {
        paramsFile.open(QIODevice::ReadWrite);
        paramsFile.setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner |
                                  QFileDevice::ReadUser | QFileDevice::WriteUser |
                                  QFileDevice::ReadOther | QFileDevice::WriteOther |
                                  QFileDevice::ReadGroup | QFileDevice::WriteGroup);
    }
    if(!paramsFile.isOpen()) {
        std::cout << "Couldn't open the file!" << paramsFile.fileName().toStdString() << std::endl;
        return;
    }

    std::map<std::string, int> paramParser;
    paramParser["maxResolution"] = 0;
    paramParser["gbks"] = 1;
    paramParser["minArea"] = 2;
    paramParser["maxArea"] = 3;
    paramParser["maxEvolution"] = 4;
    paramParser["videoPlayMode"] = 5;
    paramParser["DrawingBlue"] = 6;
    paramParser["DrawingGreen"] = 7;
    paramParser["DrawingRed"] = 8;
    paramParser["maxDiversity"] = 9;
    paramParser["loseTracking"] = 10;

    std::string name, value, line;
    std::string deli = ";";
    std::cout << "Parameters:" << std::endl;
    std::cout << "Name ---> Value" << std::endl;
    QTextStream params(&paramsFile);
    std::cout << paramsFile.fileName().toStdString() << std::endl;
    while (!params.atEnd()) {
        line= (params.readLine()).toStdString();
        std::cout << line << std::endl;
        name = line.substr(0, line.find(deli));
        value = line.substr(line.find(deli) + deli.size());
        switch (paramParser[name]) {
        case 0: // maxResolution
            MSER::maxResolution = atof(value.c_str());
            break;
        case 1: // Gauss Blur cv::Size
            MSER::gaussBlurKernelSize = cv::Size(atoi(value.c_str()),atoi(value.c_str()));
            break;
        case 2: // minArea
            MSER::minArea = atof(value.c_str());
            break;
        case 3: // maxArea
            MSER::maxArea = atof(value.c_str());
            break;
        case 5: // videoPlayMode
            MSER::detectionMode = atoi(value.c_str());
            break;
        case 6: // drawingColor0
            MSER::drawingColor[0] = atoi(value.c_str());
            break;
        case 7: // drawingColor1
            MSER::drawingColor[1] = atoi(value.c_str());
            break;
        case 8: // drawingColor2
            MSER::drawingColor[2] = atoi(value.c_str());
            break;
        case 9: // maxDiversity
            MSER::maxDiversity = atof(value.c_str());
            break;
        case 10: // loseTracking
            MSER::loseTracking = atoi(value.c_str());
            break;
        default:
            std::cout << "No parameter like '" << name << "'" << std::endl;
            break;
        }
    }

    paramsFile.close();
    std::cout << "READ FROM FILE:" << std::endl;
    //printMSER(std::cout);
}

void MSER::printMSER(std::ostream& os) {
    os << "MSER properties:" << std::endl;
    os << "actVideo: "              << MSER::actVideoUrl.toStdString()<< std::endl;
    os << "actImage: "              << MSER::actImageUrl.toStdString()<< std::endl;
    os << "maxResolution: "         << MSER::maxResolution       << std::endl;
    os << "minArea: "               << MSER::minArea             << std::endl;
    os << "maxArea: "               << MSER::maxArea             << std::endl;
    os << "gaussBlurKernelSize: "   << MSER::gaussBlurKernelSize << std::endl;
    os << "videoPlayMode: "         << MSER::detectionMode       << std::endl;
    os << "drawingColor: "          << MSER::drawingColor        << std::endl;
    os << "MSER END" << std::endl;
}
