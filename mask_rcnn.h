#ifndef   MASK_RCNN_H_
#define  MASK_RCNN_H_

#include <fstream>
#include <sstream>
#include <iostream>
#include <string.h>

#include <opencv2/dnn.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>

//const char* keys =
//"{help h usage ? | | Usage examples: \n\t\t./mask-rcnn.out --image=traffic.jpg \n\t\t./mask-rcnn.out --video=sample.mp4}"
//"{image i        |<none>| input image   }"
//"{video v       |<none>| input video   }"
//;
using namespace cv;
using namespace dnn;
using namespace std;


//int recoImageSingle_maskRcnn_image_locate(Mat  imageInput);

int recoImageSingle_maskRcnn_image_locate(Mat  imageInput);
int   procImage__maskRcnn(Mat   frame, Net  net,int  id);

int  net_init__maskRcnn(Net &  net  );

//enum   typeOfModel { YOLO3_maskRcnn, ssd_mobilenet };



#endif 

