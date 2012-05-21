#include "mainwindow.h"
#include "stereovision.h"

void MainWindow::stereoVisionTest(QString image_path,int cornersX,int cornersY){
    trace("stereoVisionTest ... ");
    StereoVision* sv = new StereoVision(640,480);

    IplImage* images[2];

    //perform calibration based on sets of 2 images (chessboard)
    sv->calibrationStart(cornersX,cornersY);
    // READ IN THE LIST OF CHESSBOARDS:
    QString file_name;
    for(int i=0;;i++){
        for(int lr=0;lr<2;lr++){
            file_name = tr("%1%2%3.jpg").arg(image_path).arg(i).arg(lr ? 'L' : 'R');
            trace(file_name);
            images[lr] = cvLoadImage( file_name.toAscii(), 0 );
        }
        if(images[0] && images[1]){
            trace(file_name);
            sv->calibrationAddSample(images[0],images[1]);
            for(int lr=0;lr<2;lr++)
                cvReleaseImage(&images[lr]);
        }else{
            break;
        }
    }
    sv->calibrationEnd();
    sv->calibrationSave("stereovisiontest.dat");

    //Once saved calibartion data can be loaded later with:
    //sv->calibrationLoad("stereovisiontest.dat");

   //test our calibartion with first image set:
    CvSize imageSize = sv->getImageSize();
   for(int lr=0;lr<2;lr++){
        QString file_name = tr("%1%2%3.jpg").arg(image_path).arg(0).arg(lr ? 'L' : 'R');
        images[lr] = cvLoadImage( file_name.toAscii(), 0 );
    }


    //this method will compute  sv->imagesRectified[0],sv->imagesRectified[1],sv->imageDepth,sv->imageDepthNormalized
    sv->stereoProcess(images[0],images[1]);


    //merge 2 rectified images in one image (pair) and display horizontal lines
    //to evaluate rectification.
    CvMat* pair = cvCreateMat( imageSize.height, imageSize.width*2,CV_8UC3 );
    CvMat part;
    cvGetCols( pair, &part, 0, imageSize.width );
    cvCvtColor( sv->imagesRectified[0], &part, CV_GRAY2BGR );
    cvGetCols( pair, &part, imageSize.width,imageSize.width*2 );
    cvCvtColor( sv->imagesRectified[1], &part, CV_GRAY2BGR );
    for(int j = 0; j < imageSize.height; j += 16 )
        cvLine( pair, cvPoint(0,j),cvPoint(imageSize.width*2,j),CV_RGB(0,255,0));


    //display the results
    cvNamedWindow( "rectified", 1 );
    cvShowImage( "rectified", pair );

    cvNamedWindow( "depth", 1 );
    cvShowImage( "depth", sv->imageDepthNormalized);

    //free up memory
    cvReleaseImage(&images[0]);
    cvReleaseImage(&images[1]);
    cvReleaseMat(&pair);

}
