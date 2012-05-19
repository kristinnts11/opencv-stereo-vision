#include "stereocamera.h"

StereoCamera::StereoCamera()
{
    for(int lr=0;lr<2;lr++){
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

    captures[0] = cvCaptureFromCAM(1);
    captures[1] = cvCaptureFromCAM(2);


    if( captures[0] && captures[1]){
      /*  double f = cvGetCaptureProperty(
        captures[0],
        CV_CAP_PROP_FOURCC
        );

        printf("fourcc = %s\r\n",fourcc);
*/
        //char* fourcc = "BGR3";
        system("uvcdynctrl -d video1 --set=\"Focus, Auto\" 0");
        system("uvcdynctrl -d video2 --set=\"Focus, Auto\" 0");
        system("uvcdynctrl -d video1 \"Focus (absolute)\" 5");
        system("uvcdynctrl -d video2 \"Focus (absolute)\" 5");
       // system("uvcdynctrl -d video1 --set=\"Frame Rate\" 30/1");
       // system("uvcdynctrl -d video2 --set=\"Frame Rate\" 10/1");

        for(int i=0;i<2;i++){
                cvSetCaptureProperty(captures[i] ,CV_CAP_PROP_FRAME_WIDTH,imageSize.width);
                cvSetCaptureProperty(captures[i] ,CV_CAP_PROP_FRAME_HEIGHT,imageSize.height);
                cvSetCaptureProperty(captures[i],CV_CAP_PROP_FOURCC,CV_PROP('Y','U','Y','V'));
                //captures[i].set(CV_CAP_PROP_FPS);
                // cvSetCaptureProperty(captures[i],CV_CAP_PROP_FPS,10);

        }


        ready = true;
        return RESULT_OK;
    }else{
        ready = false;
        return RESULT_FAIL;
    }

}

int StereoCamera::capture(){
    frames[0] = cvQueryFrame(captures[0]);
    frames[1] = cvQueryFrame(captures[1]);
    return (captures[0] && captures[1]) ? RESULT_OK : RESULT_FAIL;
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
