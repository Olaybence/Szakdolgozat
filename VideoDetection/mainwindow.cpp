#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ps = new PSettings();
    det = new Detector();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete ps;
    delete det;
    // delete display;
    cv::destroyAllWindows();
}

void MainWindow::on_selectImage_clicked()
{
    // Pop-up dialog
    QString url = QFileDialog::getOpenFileName(this,
        tr("Add Image"), QDir::homePath(), tr("Image Files (*.png *.jpg *.bmp)"));

    // If didn't chose
    if(url.isEmpty()) return;

    // Check the correction of the url
    std::cout << url.toStdString() << std::endl;
    cv::Mat cvImg = cv::imread(url.toStdString());

    if(!cvImg.empty()) { // Accepted image format
        ui->selectedImageUrl->setText(url);
        MSER::actImageUrl = url;
        MSER::actImage = cvImg;
        MSER::printMSER(std::cout);
    } else { // Invalid - cv::Mat couldn't load it
        QMessageBox msg;
        std::string tmp = "Invalid image format! (for OpenCV - cv::Mat)";
        QString error(tmp.c_str());
        msg.setText(error);
        msg.exec();
    }
}

void MainWindow::on_selectVideo_clicked()
{

    // Pop-up dialog
    QString url = QFileDialog::getOpenFileName(this,
        tr("Add Video"), QDir::homePath(), tr("Video Files (*.mp4 *.avi *.gif *mpg)"));

    // If didn't chose
    if(url.isEmpty()) return;

    // Check the correction of the url
    cv::VideoCapture cvVideo = cv::VideoCapture(url.toStdString());
    if(cvVideo.isOpened()) { // Accepted video format
        ui->selectedVideoUrl->setText(url);
        MSER::actVideoUrl = url;
        MSER::actVideo = cvVideo;
        MSER::printMSER(std::cout);
    } else { // Invalid - cv::VideoCapture couldn't load it
        QMessageBox msg;
        std::string tmp = "Invalid video format! (for OpenCV - cv::VideoCapture)";
        QString error(tmp.c_str());
        msg.setText(error);
        msg.exec();
    }
}

void MainWindow::on_parameterSettings_clicked()
{
    ps->show();
}

void MainWindow::on_detectImage_clicked()
{
    if(MSER::actImageUrl.isEmpty()) {
        QMessageBox msg;
        std::string tmp = "Missing image!";
        QString error(tmp.c_str());
        msg.setText(error);
        msg.exec();
        return;
    }
    cv::destroyAllWindows();
    det->setImage(MSER::actImage);
    det->setWindow(Detector::imageWName);
    det->playImage();
}

void MainWindow::on_detectVideo_clicked()
{
    if(MSER::actVideoUrl.isEmpty()) {
        QMessageBox msg;
        std::string tmp = "Missing video!";
        QString error(tmp.c_str());
        msg.setText(error);
        msg.exec();
        return;
    }

    cv::destroyAllWindows();
    det->setVideo(MSER::actVideo);
    det->setWindow(Detector::videoWName);
    det->playVideo();
}

void MainWindow::on_exit_clicked()
{
    QApplication::quit();
}
