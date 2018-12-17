#include "stdafx.h"


#include  "dnn_02_caffe_example_mobilenet.h"


#include <opencv2/dnn.hpp>
#include <opencv2/dnn/shape_utils.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>

using namespace cv;
using namespace std;
using namespace cv::dnn;

const size_t inWidth = 300;
const size_t inHeight = 300;
const float inScaleFactor = 0.007843f;
const float meanVal = 127.5;


// bad label  original .not   good.  old  flag 
string  classNames_str[] = { "background", "person", "bicycle",        //3     1-3
                             "car", "motorcycle", "airplane", "bus",    //4    7
                             "train",   "truck",   "boat",   "traffic light",   "fire hydrant",  //5      12
                             "stop sign",   "parking meter",   "bench",   "bird",   "cat", //  5    17
                             "dog",   "horse",   "sheep",   "cow",   "elephant",   "bear", //6     23
                             "zebra",   "giraffe",   "backpack",   "umbrella",   "handbag", //5    28
                             "tie",   "suitcase",   "frisbee",   "skis",   "snowboard", //5   33
                             "sports ball",   "kite",   "baseball bat",   "baseball glove", //4    37
                             "skateboard",   "surfboard",   "tennis racket",   "bottle", //4     41
                             "wine glass",   "cup",   "fork",   "knife",   "spoon", //5     46
                             "bowl",   "banana",   "apple",   "sandwich",   "orange", //5      51
                             "broccoli",   "carrot",   "hot dog",   "pizza",   "donut", //5     56
                             "cake",   "chair",   "couch",   "potted plant",   "bed", //5     61
                             "dining table",   "toilet",   "tv",   "laptop",   "mouse", //5     66
                             "remote",   "keyboard",   "cell phone",   "microwave",   "oven", //5     71
                             "toaster",   "sink",   "refrigerator",   "book",   "clock", //5    76
                             "vase",   "scissors",   "teddy bear",   "hair drier",   "toothbrush" }; //5     81

//  good  label
const char* classNames[] = { "background", "person", "bicycle",
                             "car", "motorcycle", "airplane", "bus",
                             "train",   "truck",   "boat",   "traffic light",   "fire hydrant", "12" ,
                             "stop sign",   "parking meter",   "bench",   "bird",   "cat",
                             "dog",   "horse",   "sheep",   "cow",   "elephant",   "bear",
                             "zebra",   "giraffe", "26",  "backpack",   "umbrella", "29", "30",  "handbag",
                             "tie",   "suitcase",   "frisbee",   "skis",   "snowboard",
                             "sports ball",   "kite",   "baseball bat",   "baseball glove",
                             "skateboard",   "surfboard",   "tennis racket",   "bottle","45",
                             "wine glass",   "cup",   "fork",   "knife",   "spoon",
                             "bowl",   "banana",   "apple",   "sandwich",   "orange",
                             "broccoli",   "carrot",   "hot dog",   "pizza",   "donut",
                             "cake",   "chair",   "couch",   "potted plant",   "bed","66",
                             "dining table",  "68","69",  "toilet", "71",  "tv",   "laptop",   "mouse",
                             "remote",   "keyboard",   "cell phone",   "microwave",   "oven",
                             "toaster",   "sink",   "refrigerator",  "83",   "book",   "clock",
                             "vase",   "scissors",   "teddy bear",   "hair drier",   "toothbrush"
                           };


const String keys
= "{ help           | false | print usage         }"
  "{ proto          | ssd_mobilenet_v1_coco.pbtxt   | model configuration }"
  "{ model          | frozen_inference_graph.pb | model weights }"
  "{ camera_device  | 0     | camera device number }"
  "{ camera_width   | 640   | camera device width  }"
  "{ camera_height  | 480   | camera device height }"
  "{ video          |       | video or image for detection}"
  "{ out            |       | path to output video file}"
  "{ min_confidence | 0.2   | min confidence      }"
  "{ opencl         | false | enable OpenCL }"
        ;

//int main_dnn_02_caffe_example_mobilenet(int argc, char** argv)
int main_dnn_02_caffe_example_mobilenet___video(  )
{
    //    CommandLineParser parser(argc, argv, keys);
    //    parser.about("This sample uses MobileNet Single-Shot Detector "
    //                 "(https://arxiv.org/abs/1704.04861) "
    //                 "to detect objects on camera/video/image.\n"
    //                 ".caffemodel model's file is available here: "
    //                 "https://github.com/chuanqi305/MobileNet-SSD\n"
    //                 "Default network is 300x300 and 90-classes COCO.\n");

    //    if (parser.get<bool>("help"))
    //    {
    //        parser.printMessage();
    //        return 0;
    //    }

    String modelConfiguration ;//= parser.get<String>("proto");
    String modelBinary ;// = parser.get<String>("model");

    modelConfiguration =
            "../dnn_02_caffe_example_mobilenet/models/ssd_mobilenet_v1_coco.pbtxt";
    modelBinary =
            "../dnn_02_caffe_example_mobilenet/models/ssd_mobilenet_v1_coco_11_06_2017/frozen_inference_graph.pb";

    CV_Assert(!modelConfiguration.empty() && !modelBinary.empty());



    cout<<"modelConfiguration proto= "<< modelConfiguration <<  endl;
    cout<<"modelBinary = "<< modelBinary <<  endl;


    //! [Initialize network]
    dnn::Net net = readNetFromTensorflow(modelBinary, modelConfiguration);
    //! [Initialize network]

    //    if (parser.get<bool>("opencl"))
    //    {
    //        net.setPreferableTarget(DNN_TARGET_OPENCL);
    //    }
    net.setPreferableTarget(DNN_TARGET_OPENCL);

    if (net.empty())
    {
        cerr << "Can't load network by using the following files: " << endl;
        cerr << "prototxt:   " << modelConfiguration << endl;
        cerr << "model: " << modelBinary << endl;
        cerr << "Models can be downloaded here:" << endl;
        cerr << "http://download.tensorflow.org/models/object_detection/ssd_mobilenet_v1_coco_11_06_2017.tar.gz" << endl;
        exit(-1);
    }

    VideoCapture cap;


    string videoInput = "/media/wkr/diskHgst/video/yk/zyz4.mp4";
    videoInput = "D:/video/yk/jixianpaoku.mp4";

    //    cap.open(parser.get<String>("video"));
    cap.open(videoInput);
    if(!cap.isOpened())
    {
        cout << "Couldn't open image or video: " << videoInput << endl;
        return -1;
    }


    //Acquire input size
    Size inVideoSize((int) cap.get(CAP_PROP_FRAME_WIDTH),
                     (int) cap.get(CAP_PROP_FRAME_HEIGHT));

    double fps = cap.get(CAP_PROP_FPS);
    int fourcc = static_cast<int>(cap.get(CAP_PROP_FOURCC));
    VideoWriter outputVideo;


    string videoOutput = "/media/wkr/diskHgst/video/yk/zyz4_out_201807241956.avi";
    videoOutput = "d:/video/yk/zyz4_out_2018072419560001.avi";
    outputVideo.open( videoOutput,CV_FOURCC('M','J','P','G'),10,inVideoSize ,1  );

    for(;;)
    {
        Mat frame;
        cap >> frame; // get a new frame from camera/video or read image

        if (frame.empty())
        {
            waitKey();
            break;
        }

        if (frame.channels() == 4)
            cvtColor(frame, frame, COLOR_BGRA2BGR);

        //! [Prepare blob]
        Mat inputBlob = blobFromImage(frame, inScaleFactor,
                                      Size(inWidth, inHeight),
                                      Scalar(meanVal, meanVal, meanVal),
                                      false, false); //Convert Mat to batch of images
        //! [Prepare blob]

        //! [Set input blob]
        net.setInput(inputBlob); //set the network input
        //! [Set input blob]

        //! [Make forward pass]
        Mat detection = net.forward(); //compute output
        //! [Make forward pass]

        vector<double> layersTimings;
        double freq = getTickFrequency() / 1000;
        double time = net.getPerfProfile(layersTimings) / freq;

        Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

        if (!outputVideo.isOpened())
        {
            putText(frame, format("FPS: %.2f ; time: %.2f ms", 1000.f/time, time),
                    Point(20,20), 0, 0.5, Scalar(0,0,255));
        }
        else
            cout << "Inference time, ms: " << time << endl;

        //        float confidenceThreshold = parser.get<float>("min_confidence");
        float confidenceThreshold = 0.10;//parser.get<float>("min_confidence");
        for(int i = 0; i < detectionMat.rows; i++)
        {
            float confidence = detectionMat.at<float>(i, 2);

            if(confidence > confidenceThreshold)
            {
                size_t objectClass = (size_t)(detectionMat.at<float>(i, 1));

                int left = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
                int top = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
                int right = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
                int bottom = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);

                rectangle(frame, Point(left, top), Point(right, bottom), Scalar(0, 255, 0));
                String label = format("%s: %.2f", classNames[objectClass], confidence);
                int baseLine = 0;
                Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
                top = max(top, labelSize.height);
                rectangle(frame, Point(left, top - labelSize.height),
                          Point(left + labelSize.width, top + baseLine),
                          Scalar(255, 255, 255), FILLED);
                putText(frame, label, Point(left, top),
                        FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0,0,0));
            }
        }

        if (outputVideo.isOpened())
        {
            //            outputVideo.write(frame );
            outputVideo << frame;
        }

        imshow("detections", frame);
        if (waitKey(1) >= 0)
        {
            break;
            outputVideo.release();
        }
    }

    return 0;
} // main






int   net_prepare(    dnn::Net  & net    )
{
    String modelConfiguration ;//= parser.get<String>("proto");
    String modelBinary ;// = parser.get<String>("model");

    modelConfiguration =
            "D:\\show_gui_qtOpencv\\dnn_02_caffe_example_mobilenet/models/ssd_mobilenet_v1_coco.pbtxt";
    modelBinary =
            "D:\\show_gui_qtOpencv\\dnn_02_caffe_example_mobilenet\\models/ssd_mobilenet_v1_coco_11_06_2017/frozen_inference_graph.pb";

    CV_Assert(!modelConfiguration.empty() && !modelBinary.empty());

    cout<<"modelConfiguration proto= "<< modelConfiguration <<  endl;
    cout<<"modelBinary = "<< modelBinary <<  endl;


    //! [Initialize network]
    //    dnn::Net net = readNetFromTensorflow(modelBinary, modelConfiguration);
    net = readNetFromTensorflow(modelBinary, modelConfiguration);
    //! [Initialize network]

    net.setPreferableTarget(DNN_TARGET_OPENCL);

    if (net.empty())
    {
        cerr << "Can't load network by using the following files: " << endl;
        cerr << "prototxt:   " << modelConfiguration << endl;
        cerr << "model: " << modelBinary << endl;
        cerr << "Models can be downloaded here:" << endl;
        cerr << "http://download.tensorflow.org/models/object_detection/ssd_mobilenet_v1_coco_11_06_2017.tar.gz" << endl;
        //exit(-1);
		return  -1;
    }
	return  0;
}


void imageProc( Mat  &  src ,  dnn::Net    net  )
{
    Mat frame = src;
    // cap >> frame; // get a new frame from camera/video or read image

    if (frame.empty())
    {
        waitKey(1);
        cout << "void imageProc() : frame.empty()" <<   endl;
        return  ;
        //            break;
    }

    if (frame.channels() == 4)
        cvtColor(frame, frame, COLOR_BGRA2BGR);

    //! [Prepare blob]
    Mat inputBlob = blobFromImage(frame, inScaleFactor,
                                  Size(inWidth, inHeight),
                                  Scalar(meanVal, meanVal, meanVal),
                                  false, false); //  Convert Mat to batch of images
    //! [Prepare blob]

    //! [Set input blob]
    net.setInput(inputBlob); //set the network input
    //! [Set input blob]

    //! [Make forward pass]
    Mat detection = net.forward(); //compute output
    //! [Make forward pass]

    vector<double> layersTimings;
    double freq = getTickFrequency() / 1000;
    double time = net.getPerfProfile(layersTimings) / freq;

    Mat detectionMat(detection.size[2], detection.size[3], CV_32F, detection.ptr<float>());

    if (1)
    {
        putText(frame, format("FPS: %.2f ; time: %.2f ms", 1000.f/time, time),
                Point(20,20), 0, 0.5, Scalar(0,0,255));
        cout << "Inference time, ms: " << time << endl;
    }
    else
    {
        cout << "Inference time, ms: " << time << endl;
    }

    //  float confidenceThreshold = parser.get<float>("min_confidence");
    float confidenceThreshold = 0.10;   //parser.get<float>("min_confidence");
    for(int i = 0; i < detectionMat.rows; i++)
    {
        float confidence = detectionMat.at<float>(i, 2);

        if(confidence > confidenceThreshold)
        {
            size_t objectClass = (size_t)(detectionMat.at<float>(i, 1));

            int left = static_cast<int>(detectionMat.at<float>(i, 3) * frame.cols);
            int top = static_cast<int>(detectionMat.at<float>(i, 4) * frame.rows);
            int right = static_cast<int>(detectionMat.at<float>(i, 5) * frame.cols);
            int bottom = static_cast<int>(detectionMat.at<float>(i, 6) * frame.rows);

            rectangle(frame, Point(left, top), Point(right, bottom), Scalar(0, 255, 0));
            String label = format("%s: %.2f", classNames[objectClass], confidence);
            cout<<"classNames[objectClass],objectClass,confidence  = "<<   string(classNames [objectClass]) << ","<<objectClass<<","<< confidence<< endl;
            int baseLine = 0;
            Size labelSize = getTextSize(label, FONT_HERSHEY_SIMPLEX, 0.5, 1, &baseLine);
            top = max(top, labelSize.height);
            rectangle(frame, Point(left, top - labelSize.height),
                      Point(left + labelSize.width, top + baseLine),
                      Scalar(255, 255, 255), FILLED);
            putText(frame, label, Point(left, top),
                    FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0,0,0));
        }
    }

//    src = frame;
}


int main_dnn_02_caffe_example_mobilenet___mat( Mat &src    )
{
    dnn::Net   net ;
    net_prepare(     net    ) ;

    imageProc(  src  , net );

    return 0;
}

