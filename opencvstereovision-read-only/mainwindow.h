#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include "stereocamera.h"
#include "stereovision.h"
#include <QTimer>


namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void trace(QString str);
    Ui::MainWindow *ui;
    StereoVision::BMsetting BMset;
private:
    StereoCamera camera;
    StereoVision* vision;
    QTimer timer;
    int sampleTimeout;
    CvMat* imageRectifiedPair;




    void displayOutput();
    void stereoVisionTest(QString image_path,int cornersX,int cornersY);

private slots:
    void on_pushButtonSave_clicked();
    void on_pushButtonLoad_clicked();
    void on_pushButtonCalibrate_clicked();
    void timeout();

    void on_CaptureButton_clicked();
    void on_CloseButton_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_valueChanged(int value);
};

#endif // MAINWINDOW_H
