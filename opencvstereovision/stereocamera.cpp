#include "stereocamera.h"

StereoCamera::StereoCamera()
{
    for(int lr=0;lr<3;lr++){
        captures[lr] = 0;
        frames[lr] = 0;
        framesGray[lr] = 0;
    }
    ready = false;
}

StereoCamera::~StereoCamera()
{
    for(int lr=0;lr<2;lr++){
        cvReleaseImage(&frames[lr]);
        cvReleaseImage(&framesGray[lr]);
        cvReleaseCapture(&captures[lr]);
    }

}

int StereoCamera::setup(CvSize imageSize){
    this->imageSize = imageSize;

        captures[1] = cvCaptureFromCAM(CV_CAP_DSHOW + 1);
        captures[2] = cvCaptureFromCAM(CV_CAP_DSHOW + 2);

    if( captures[1] && captures[2]){

        for(int i=0;i<3;i++){
                cvSetCaptureProperty(captures[i] ,CV_CAP_PROP_FRAME_WIDTH,imageSize.width);
                cvSetCaptureProperty(captures[i] ,CV_CAP_PROP_FRAME_HEIGHT,imageSize.height);
        }


        ready = true;
        return RESULT_OK;
    }else{
        ready = false;
        return RESULT_FAIL;
    }

}

int StereoCamera::capture(){
    frames[1] = cvQueryFrame(captures[1]);
    frames[2] = cvQueryFrame(captures[2]);
    return (captures[1] && captures[2]) ? RESULT_OK : RESULT_FAIL;
}

IplImage*  StereoCamera::getFramesGray(int lr){
    if(!frames[lr]) return 0;
    if(frames[lr]->depth == 1){
        framesGray[lr] = frames[lr];
        return frames[lr];
    }else{
        if(0 == framesGray[lr]) framesGray[lr] = cvCreateImage(cvGetSize(frames[lr]),IPL_DEPTH_8U,1);
        cvCvtColor(frames[lr],framesGray[lr],CV_BGR2GRAY);
        return framesGray[lr];
    }
}
