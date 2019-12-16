#include "psettings.h"
#include "ui_psettings.h"

PSettings::PSettings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PSettings)
{
    ui->setupUi(this);
    ui->gbks->setValue(MSER::gaussBlurKernelSize.width);
    ui->maxArea->setValue(static_cast<int>(MSER::maxArea));
    ui->minArea->setValue(static_cast<int>(MSER::minArea));
    if(MSER::detectionMode == MSER::SELECT_DET) ui->selectedObject->click();
    if(MSER::detectionMode == MSER::FULL_DET) ui->allObject->click();
    ui->maxResolution->setValue(static_cast<int>(MSER::maxResolution));
    ui->blue->setValue(static_cast<int>(MSER::drawingColor[0]));
    ui->green->setValue(static_cast<int>(MSER::drawingColor[1]));
    ui->red->setValue(static_cast<int>(MSER::drawingColor[2]));
    ui->maxDiversity->setValue(MSER::maxDiversity);
    ui->loseTracking->setValue(MSER::loseTracking);

    MSER::printMSER(std::cout);
    vpmC = -1;
}

PSettings::~PSettings()
{
    delete ui;
}

void PSettings::on_selectedObject_clicked()
{
   vpmC = MSER::SELECT_DET;
}

void PSettings::on_allObject_clicked()
{
   vpmC = MSER::FULL_DET;
}

void PSettings::on_buttonBox_clicked(QAbstractButton *button)
{
    std::cout << "on_buttonBox_clicked button-text:" << button->text().toStdString() << std::endl;
    std::string bName = button->text().toStdString();
    if(bName == "Apply") { // Apply clicked
        saveSettings();
    } else if(bName == "&OK") { // OK clicked
        saveSettings();
    } else if(bName == "&Cancel") { // Cancel clicked
        std::cout << "Canceled" << std::endl;
    }
    MSER::printMSER(std::cout);
}

void PSettings::on_SaveIntoFile_clicked()
{
    saveSettings();
    MSER::writeParamsIntoFile();
}

void PSettings::saveSettings() {
    MSER::minArea = ui->minArea->value();
    MSER::maxArea = ui->maxArea->value();
    MSER::gaussBlurKernelSize = cv::Size(ui->gbks->value(),ui->gbks->value());
    MSER::maxResolution = ui->maxResolution->value();
    MSER::drawingColor = cv::Scalar(ui->blue->value(),
                                    ui->green->value(),
                                    ui->red->value());
    MSER::maxDiversity = ui->maxDiversity->value();
    MSER::loseTracking = ui->loseTracking->value();

    if(vpmC != -1) MSER::detectionMode = vpmC;

    std::cout << "Saved" << std::endl;
    MSER::printMSER(std::cout);

    vpmC = -1;
}
