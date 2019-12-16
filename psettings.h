#ifndef PSETTINGS_H
#define PSETTINGS_H

#include <QDialog>
#include <QAbstractButton>
#include <QTextStream>
#include <QFile>
#include <QMessageBox>

#include "OpenCV/Utils.h"
#include "OpenCV/Detector.h"

namespace Ui {
class PSettings;
}

class PSettings : public QDialog
{
    Q_OBJECT

public:
    explicit PSettings(QWidget *parent = nullptr);
    ~PSettings();

private slots:

    // Change the detect mode's value to MSER::SELECT_DET
    void on_selectedObject_clicked();
    // Change the detect mode's value to MSER::ALL_DET
    void on_allObject_clicked();

    // Save/Cancel/Apply buttons clicked
    void on_buttonBox_clicked(QAbstractButton *button);

    // Save settings into MSER object
    void saveSettings();

    // Save into object then into file
    void on_SaveIntoFile_clicked();

private:
    Ui::PSettings *ui;

    int vpmC = -1;
};

#endif // PSETTINGS_H
