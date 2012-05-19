#include "mainwindow.h"
#include "ui_mainwindow.h"

//int w = 640/2 , h = 480/2 ;
int w =640/2  , h =360/2 ;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    imageRectifiedPair = 0;

    vision = new StereoVision(w,h);
    connect(&timer, SIGNAL(timeout()), this, SLOT(timeout()));

    BMset.preFilterSize = 41;
    BMset.preFilterCap = 31;
    BMset.SADWindowSize = 41;
    BMset.minDisparity=-64;
    BMset.numberOfDisparities=128;
    BMset.textureThreshold=10;
    BMset.uniquenessRatio=15;

    //UNCOMMENT ONLY ONE OF THE FOLLOWING 3 LINES:
    //stereoVisionTest("../images/set1/",7,4);  //run test1, using pre-saved stereo images
    //stereoVisionTest("../images/set2/",9,6);  //run test2 using pre-saved stereo images
    //timer.start(50); //run program normally , using 2 USB cammeras
}

MainWindow::~MainWindow()
{
    delete ui;
    timer.stop();
    cvReleaseMat(&imageRectifiedPair);

    //cvReleaseImage( &imageRectifiedPair);
    //cvReleaseImage( &vision->imageDepthNormalized);
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
        if(RESULT_OK != camera.setup(cvSize(w,h))){
            trace("-FAILED");
        }else{
            trace("+OK");
            on_pushButtonLoad_clicked();
            cvNamedWindow( "left",CV_WINDOW_FREERATIO);
            cvNamedWindow( "right",CV_WINDOW_FREERATIO);

            ui->pushButtonCalibrate->setEnabled(true);
        };
    }else{
        if(RESULT_OK == camera.capture()){
            cvShowImage("left",camera.frames[0]);
            cvShowImage("right",camera.frames[1]);
            //displayOutput();
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

    vision->stereoProcess(camera.getFramesGray(0), camera.getFramesGray(1),BMset);


    CvMat part;
    cvGetCols( imageRectifiedPair, &part, 0, imageSize.width );
    cvCvtColor( vision->imagesRectified[0], &part, CV_GRAY2BGR );
    cvGetCols( imageRectifiedPair, &part, imageSize.width,imageSize.width*2 );
    cvCvtColor( vision->imagesRectified[1], &part, CV_GRAY2BGR );
    for(int j = 0; j < imageSize.height; j += 16 )
        cvLine( imageRectifiedPair, cvPoint(0,j),cvPoint(imageSize.width*2,j),CV_RGB((j%3)?0:255,((j+1)%3)?0:255,((j+2)%3)?0:255));
    cvNamedWindow( "rectified",CV_WINDOW_AUTOSIZE);
    cvNamedWindow( "depth",CV_WINDOW_AUTOSIZE);
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

//On Capture Button clicked
void MainWindow::on_CaptureButton_clicked()
{
    timer.start(50); //run program normally , using 2 USB cammeras
}
//On Close Button clicked
void MainWindow::on_CloseButton_clicked()
{
    timer.stop();
    cvDestroyAllWindows();
    cvReleaseImage( &camera.frames[0] );
    cvReleaseImage( &camera.frames[1] );
    this->~MainWindow();
}

//Callback for adjustment preFilterSize
void MainWindow::on_horizontalSlider_valueChanged(int value)
{

    if (value == NULL) {
        trace(tr("WARNING: data is null\n"));
        return;
    }

    //set the parameter,
    //data->BMState->preFilterSize = value;
    //vision->stereoProcess();
}

//Callback for adjustment preFilterCap
void MainWindow::on_horizontalSlider_2_valueChanged(int value)
{
    if (value == NULL) {
        trace(tr("WARNING: data is null\n"));
        return;
    }

    //data->BMState->preFilterCap = value;
}
