#include "mainwindow.h"
#include "ui_mainwindow.h"
//test

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageRectifiedPair = 0;
    vision = new StereoVision(176,144);
    connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));

    //UNCOMMENT ONLY ONE OF THE FOLLOWING 3 LINES:
    //stereoVisionTest("../images/set1/",7,4);  //run test1, using pre-saved stereo images
    //stereoVisionTest("../images/set2/",9,6);  //run test2 using pre-saved stereo images
    timer.start(50); //run program normally , using 2 USB cammeras
}

MainWindow::~MainWindow()
{
    delete ui;
    cvReleaseMat(&imageRectifiedPair);
}

void MainWindow::trace(QString str){
    ui->plainTextEditTrace->appendPlainText(str);
}

void MainWindow::on_pushButtonCalibrate_clicked()
{
    vision->calibrationStart(ui->spinBoxCornersX->value(),ui->spinBoxCornersY->value());
    trace("Calibration Started. Place the chessboard so it is visible on both cameras.");
    trace(tr("Samples are taken every %1. Plase wait ... ").arg(ui->spinBoxInterval->value()));
    sampleTimeout = ui->spinBoxInterval->value()*1000;
    ui->pushButtonCalibrate->setEnabled(false);
}

void MainWindow::timeout(){
    ui->progressBar->setMaximum( ui->spinBoxSampleCount->value());
    ui->progressBar->setValue(vision->getSampleCount());



    if(!camera.ready){
        trace("Connecting to cameras...");
        if(RESULT_OK != camera.setup(cvSize(176,144))){
            trace("-FAILED");
        }else{
            trace("+OK");
            on_pushButtonLoad_clicked();
            cvNamedWindow( "left");
            cvNamedWindow( "right");
            cvNamedWindow( "rectified", 1 );
            cvNamedWindow( "depth", 1 );
            ui->pushButtonCalibrate->setEnabled(true);
        };
    }else{
        if(RESULT_OK == camera.capture()){
            cvShowImage("left",camera.frames[0]);
            cvShowImage("right",camera.frames[1]);
        };


        ui->pushButtonSave->setEnabled(vision->getCalibrationDone());



        if(vision->getCalibrationStarted()){
            if(sampleTimeout < 0){

                sampleTimeout = ui->spinBoxInterval->value()*1000;
                trace(tr("Processing sample %1 of %2 Finding chessboard corners ...").arg(vision->getSampleCount()+1).arg(ui->spinBoxSampleCount->value()));

                int result = vision->calibrationAddSample(camera.getFramesGray(0),camera.getFramesGray(1));

                if(RESULT_OK == result){
                    trace("+OK");
                    if(vision->getSampleCount() >= ui->spinBoxSampleCount->value()){
                        vision->calibrationEnd();
                        ui->pushButtonCalibrate->setEnabled(true);
                        trace("Calibration Done !");
                    }
                }else{
                    trace("-FAIL Try a different position. Chessboard should be visible on both cameras.");
                }

            }else{
                ui->lcdNumber->display(sampleTimeout/1000);
                sampleTimeout -= timer.interval();

            }
        }else{
            if(vision->getCalibrationDone()) displayOutput();
        }



    }

}

void MainWindow::displayOutput(){
    CvSize imageSize = vision->getImageSize();
    if(!imageRectifiedPair) imageRectifiedPair = cvCreateMat( imageSize.height, imageSize.width*2,CV_8UC3 );

    vision->stereoProcess(camera.getFramesGray(0), camera.getFramesGray(1));


    CvMat part;
    cvGetCols( imageRectifiedPair, &part, 0, imageSize.width );
    cvCvtColor( vision->imagesRectified[0], &part, CV_GRAY2BGR );
    cvGetCols( imageRectifiedPair, &part, imageSize.width,imageSize.width*2 );
    cvCvtColor( vision->imagesRectified[1], &part, CV_GRAY2BGR );
    for(int j = 0; j < imageSize.height; j += 16 )
        cvLine( imageRectifiedPair, cvPoint(0,j),cvPoint(imageSize.width*2,j),CV_RGB((j%3)?0:255,((j+1)%3)?0:255,((j+2)%3)?0:255));
    cvShowImage( "rectified", imageRectifiedPair );


    cvShowImage( "depth", vision->imageDepthNormalized );
}



void MainWindow::on_pushButtonLoad_clicked()
{
    trace(tr("Loading calibration file [%1]...").arg(ui->lineEditFilename->text()));
    if(RESULT_OK == vision->calibrationLoad(ui->lineEditFilename->text().toAscii())){
        trace("+OK");
    }else{
        trace("-FAIL");
    };
}

void MainWindow::on_pushButtonSave_clicked()
{
    trace(tr("Saving calibration file [%1]...").arg(ui->lineEditFilename->text()));
    if(RESULT_OK == vision->calibrationSave(ui->lineEditFilename->text().toAscii())){
        trace("+OK");
    }else{
        trace("-FAIL");
    };
}
