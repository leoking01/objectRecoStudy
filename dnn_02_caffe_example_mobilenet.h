#ifndef   main_dnn_02_caffe_example_mobilenet_H
#define   main_dnn_02_caffe_example_mobilenet_H
#include <opencv2/dnn.hpp>
#include <opencv2/dnn/shape_utils.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;
using namespace cv::dnn;

//int main_dnn_02_caffe_example_mobilenet(  );
int main_dnn_02_caffe_example_mobilenet___video(  );
int main_dnn_02_caffe_example_mobilenet___mat( Mat &src    );

void imageProc(Mat  &  src, dnn::Net    net, Mat &  res_detectionMat);
int  net_prepare(    dnn::Net  & net    );


#endif
