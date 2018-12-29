
// objectRecoStudyDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "objectRecoStudy.h"
#include "objectRecoStudyDlg.h"
#include "afxdialogex.h"



#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

#include<string>

using namespace std;
using namespace cv;





#ifdef _DEBUG
#define new DEBUG_NEW
#endif


#define    OPENCV2_NOT3

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CobjectRecoStudyDlg 对话框



CobjectRecoStudyDlg::CobjectRecoStudyDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_OBJECTRECOSTUDY_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CobjectRecoStudyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CobjectRecoStudyDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CobjectRecoStudyDlg::OnBnClickedButton1_maskRcnn_image_locate)
	ON_BN_CLICKED(IDC_BUTTON2, &CobjectRecoStudyDlg::OnBnClickedButton2_locPts4)
	ON_BN_CLICKED(IDC_BUTTON3, &CobjectRecoStudyDlg::OnBnClickedButton3_objectLocateCamera)
	ON_BN_CLICKED(IDC_BUTTON4, &CobjectRecoStudyDlg::OnBnClickedButton4_localObjMobileCamera)
	ON_BN_CLICKED(IDC_BUTTON5, &CobjectRecoStudyDlg::OnBnClickedButton5_objectMaskRcnnVideo)
	ON_BN_CLICKED(IDC_BUTTON6, &CobjectRecoStudyDlg::OnBnClickedButton6_rectangleFineMobile)
	ON_BN_CLICKED(IDC_BUTTON7, &CobjectRecoStudyDlg::OnBnClickedButton7_grabcutStudy)
	ON_BN_CLICKED(IDC_BUTTON8, &CobjectRecoStudyDlg::OnBnClickedButton8_setIdCamera)
	ON_BN_CLICKED(IDC_BUTTON9, &CobjectRecoStudyDlg::OnBnClickedButton9_caffeModel)
	ON_BN_CLICKED(IDC_BUTTON10, &CobjectRecoStudyDlg::OnBnClickedButton10_tensorflowModel)
	ON_BN_CLICKED(IDC_BUTTON11, &CobjectRecoStudyDlg::OnBnClickedButton11TorchStudy)
	ON_BN_CLICKED(IDC_BUTTON12, &CobjectRecoStudyDlg::OnBnClickedButton12ClassicalStudy)
	ON_BN_CLICKED(IDC_BUTTON13, &CobjectRecoStudyDlg::OnBnClickedButton13SSD_Study)
	ON_BN_CLICKED(IDC_BUTTON14, &CobjectRecoStudyDlg::OnBnClickedButton14_oneKeyRunAll)
END_MESSAGE_MAP()


// CobjectRecoStudyDlg 消息处理程序

BOOL CobjectRecoStudyDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

#ifdef  OPENCV2_NOT3
	if (1)
	{
		namedWindow("IDC_PIC_STATIC", WINDOW_AUTOSIZE);
		HWND hWnd = (HWND)cvGetWindowHandle("IDC_PIC_STATIC");
		HWND hParent = ::GetParent(hWnd);
		::SetParent(hWnd, GetDlgItem(IDC_PIC_STATIC)->m_hWnd);
		::ShowWindow(hParent, SW_HIDE);
	}
#endif 

	id_camera = 0;



	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CobjectRecoStudyDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CobjectRecoStudyDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CobjectRecoStudyDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


int   locat4pt2fFromScene_maskRcnn_image_locate(Mat inputImage, Point2f*   ptf4)
{
	if (!inputImage.data)
	{
		cout << "!inputImage.data" << endl;
		return  -1;
	}


	int  res = recoImageSingle_maskRcnn_image_locate(inputImage);
	cout << "res = " << res << endl;

	return 0;
}

//maskRcnn-image 
void CobjectRecoStudyDlg::OnBnClickedButton1_maskRcnn_image_locate()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);



	string  str = "d:/images/book.jpg";
	fetchFileName(str);

	ifstream ifile(str);
	if (!ifile)
	{
		cout << "文件不存在， str =  " << str << endl;
		throw("error");
		return;
	}
	ifile.close();

	Mat inputImage = imread(str, 1);

	FileStorage fs__inputImage("inputImage.xml", FileStorage::WRITE);
	fs__inputImage << "inputImage" << inputImage;
	fs__inputImage.release();


	Point2f   ptf4[4];
	locat4pt2fFromScene_maskRcnn_image_locate(inputImage, ptf4);

	FreeConsole();
}







void CobjectRecoStudyDlg::OnBnClickedButton2_locPts4()
{
	// TODO: 在此添加控件通知处理程序代码


#ifdef  OPENCV2_NOT3
	if (1)
	{
		CString picPath;   //定义图片路径变量  
		CFileDialog dlg(TRUE, NULL, NULL,
			OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_ALLOWMULTISELECT, NULL, this);   //选择文件对话框  

		if (dlg.DoModal() == IDOK)
		{
			picPath = dlg.GetPathName();  //获取图片路径  
		}
		else
		{
			return;
		}
		if (picPath.IsEmpty())
			return;
		////CString to string  使用这个方法记得字符集选用“使用多字节字符”，不然会报错  
		//string picpath = picPath.GetBuffer(0);

		//从这里开始进行转化，这是一个宏定义
		USES_CONVERSION;
		//进行转换
		char* keyChar = T2A(picPath.GetBuffer(0));
		picPath.ReleaseBuffer();
		string picpath(keyChar);
		//string   picpath = string(keyChar);


		Mat image = imread(picpath);
		Mat imagedst;
		//以下操作获取图形控件尺寸并以此改变图片尺寸  
		CRect rect;
		GetDlgItem(IDC_PIC_STATIC)->GetClientRect(&rect);
		Rect dst(rect.left, rect.top, rect.right, rect.bottom);
		resize(image, imagedst, cv::Size(rect.Width(), rect.Height()));
		imshow("IDC_PIC_STATIC", imagedst);
	}
#endif


}

// maskrcnn--vieo  
void  videoProc_maskRcnn(int  opt, Net  net, int  idx_camera, string   nameOfVideo)
{
	VideoCapture  vc;
	if (opt == 0)
		vc.open(idx_camera);
	else if (opt < 0)
		vc.open(nameOfVideo);
	else
	{
		cout << "videoProc() ::  video open-mode wrong , please check. " << endl;
		return;
	}

	Mat  frame;
	vc >> frame;
	int  id = 0;
	while (1)
	{
		if (id % 36 == 0)
		{
			clock_t start, end;
			start = clock();
			procImage__maskRcnn(frame, net, id);
			end = clock();
			printf("用时：第%d帧， time=%f\n", id, ((double)end - start) / CLK_TCKCLOCKS_PER_SEC);
		}
		vc >> frame;
		id++;
		if (frame.data)
		{
			imshow("frame", frame);
			waitKey(10);
		}
		if (waitKey(10) > 0)
		{
			cout << "usr allert  a key-event .  program   exit .  " << endl;
			break;
		}

	}
	vc.release();
	return;
}

//maskrcnn  --camera 
void CobjectRecoStudyDlg::OnBnClickedButton3_objectLocateCamera()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	clock_t start, end;
	start = clock();
	//…calculating…

	Net  net;
	int  res_net = net_init__maskRcnn(net);
	if (res_net < 0)
		return;

	end = clock();
	printf("初始化网络用时间： time=%f\n", ((double)end - start) / CLK_TCKCLOCKS_PER_SEC);

	string  nameOfVideo = "D:\\video/7f741afd5fc83b507f64ed09c70da81e.mp4";
	int  id_cam = this->id_camera;

	cout << "id_camera = " << this->id_camera << endl;

	videoProc_maskRcnn(0, net, id_cam, nameOfVideo);

	FreeConsole();
	return;
}

// 使用mobilenet--video
void CobjectRecoStudyDlg::OnBnClickedButton4_localObjMobileCamera()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	string  videoName;
	fetchFileName(videoName);

	clock_t start, end;
	start = clock();
	//…calculating…

	Net  net;
	int  res_net = net_prepare(net);
	if (res_net < 0)
		return;
	end = clock();
#ifndef CLK_TCKCLOCKS_PER_SEC 
#define CLK_TCKCLOCKS_PER_SEC   1000  
#endif 
	printf("初始化网络用时间： time=%f\n", ((double)end - start) / CLK_TCKCLOCKS_PER_SEC);

	VideoCapture   vc(videoName);
	Mat  frame;
	vc >> frame;
	int  id = 0;
	string  nameShow = "frame";
	namedWindow(nameShow);
	while (1)
	{
		if (frame.data)
		{
			Mat  res_detectionMat;
			imageProc(frame, net, res_detectionMat);
			imshow("frame", frame);
		}
		if (waitKey(10) > 0)
			break;
		vc >> frame;
		id++;
	}
	destroyWindow(nameShow);
	vc.release();
	FreeConsole();
}



void CobjectRecoStudyDlg::fetchFileName(string & nameOut)
{
	CString picPath;   //定义图片路径变量  
	CFileDialog dlg(TRUE, NULL, NULL,
		OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_ALLOWMULTISELECT, NULL, this);   //选择文件对话框  

	if (dlg.DoModal() == IDOK)
	{
		picPath = dlg.GetPathName();  //获取图片路径  
	}
	else
	{
		return;
	}
	if (picPath.IsEmpty())
		return;
	////CString to string  使用这个方法记得字符集选用“使用多字节字符”，不然会报错  
	//string picpath = picPath.GetBuffer(0);

	//从这里开始进行转化，这是一个宏定义
	USES_CONVERSION;
	//进行转换
	char* keyChar = T2A(picPath.GetBuffer(0));
	picPath.ReleaseBuffer();
	string picpath(keyChar);
	nameOut = picpath;
}

//maskrcnn  -- video  
void CobjectRecoStudyDlg::OnBnClickedButton5_objectMaskRcnnVideo()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	string  videoName;
	fetchFileName(videoName);

	clock_t start, end;
	start = clock();
	//…calculating…
 
	Net  net;
	int  res_net = net_init__maskRcnn(net);
	if (res_net < 0)
		return;

	end = clock();
#ifndef CLK_TCKCLOCKS_PER_SEC 
#define CLK_TCKCLOCKS_PER_SEC   1000  
#endif
	printf("初始化网络用时间： time=%f\n", ((double)end - start) / CLK_TCKCLOCKS_PER_SEC);


	string  nameOfVideo = videoName;

	cout << "nameOfVideo = " << nameOfVideo << endl;

	int  id_cam = -1;
	videoProc_maskRcnn(id_cam, net, 0, nameOfVideo);

	FreeConsole();
}


void  approxPolyDP_app_fit_4p(int  thresh, Mat  srcImage, vector<Point2f> & pts4, int  epsilon, int  numsRef)
{
	//float  residure = 0;
	pts4.clear();

	Mat grayImage;
	if (srcImage.channels() > 1)
	{
		cvtColor(srcImage, grayImage, COLOR_BGR2GRAY);
	}
	else
	{
		grayImage = srcImage;
	}
	const int threshMaxValue = 255;
	RNG rng(12345);

	Mat threshold_output;
	vector< vector< Point> > contours;
	vector<Vec4i > hierarchy;

	// 
	threshold(grayImage, threshold_output, thresh, 255, THRESH_BINARY);
	//寻找图像轮廓   
	findContours(threshold_output, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point(0, 0));
	cout << "contours.size() = " << contours.size() << endl;

	// 
	vector<vector<Point>>contours_poly(contours.size());
	for (int i = 0; i < contours.size(); i++)
	{
		approxPolyDP(Mat(contours[i]), contours_poly[i], epsilon, true);
	}

	cout << "contours_poly[0].size() = " << contours_poly[0].size() << endl;
	for (int i = 0; i < contours_poly[0].size(); i++)
	{
		pts4.push_back(Point2f(contours_poly[0][i].x, contours_poly[0][i].y));
	}

	//  
	Mat drawing = Mat::zeros(threshold_output.size(), CV_8UC3);
	char  carNmae[300];
	for (int i = 0; i < contours.size(); i++)
	{
		Scalar color = Scalar(rng.uniform(0, 255), rng.uniform(0, 255), rng.uniform(0, 255));
		drawContours(drawing, contours_poly, i, color, 1, 8, vector<Vec4i>(), 0, Point());
		for (int j = 0; j < contours_poly[0].size(); j++)
		{
			sprintf(carNmae, "%d", j);
			putText(drawing, carNmae, contours_poly[0][j], 1, 1, Scalar(255, 0, 255));
		}
	}

	imwrite((string("contour_") + to_string(numsRef) + string(".jpg")).c_str(), drawing);
	if (pts4.size() == 4)
	{
		namedWindow(string("contour_") + to_string(numsRef), WINDOW_AUTOSIZE);
		imshow(string("contour_") + to_string(numsRef), drawing);
		waitKey(200);
		//destroyWindow(string("contour_") + to_string(numsRef));
	}

	return;
}


float calc_residure_4p(Mat gray_threshold, vector<Point2f> pts4_01)
{
	if (!gray_threshold.data)
		return -1;
	float   residure = 0;

	int  numsNonZero = countNonZero(gray_threshold);

	vector<vector< Point   > >    points;
	vector< Point   >   pts_0;
	for (vector<Point2f>::iterator it = pts4_01.begin(); it != pts4_01.end(); it++)
	{
		pts_0.push_back(Point(it->x, it->y));
	}
	points.push_back(pts_0);
	Mat dr(gray_threshold.size(), CV_8UC1, Scalar(0));
	drawContours(dr, points, 0, Scalar(255), -1);
	int  numsFetch = countNonZero(dr);

	residure = abs(numsFetch - numsNonZero) / (float)(gray_threshold.rows* gray_threshold.cols);

	return residure;
}


int  rect_modifier(Rect & output, int  stepLen)
{
	//Rect  tmp = input;
	output.x = output.x + stepLen;
	output.y = output.y + stepLen;
	output.width = output.width - stepLen * 2;
	output.height = output.height - stepLen * 2;
	if (output.x < 0 || output.y < 0)
		return  -2;

	if (output.width <= 0 || output.height <= 0)
		return  -1;
	return 0;
}

int  get_right_type_and_conf_and_pts(Mat & detectionMat, int  id_type, float&  conf, float*   ft4, int&  id_line)
{
	// 检测矩阵由很多行组成，每一行表示一个实例，以及其详情，包括类别，一个结果
	cout << "g:detectionMat.size() = " << detectionMat.size() << endl;
	float confidenceThreshold = 0.10;
	float  val_conf = 0;
	for (int i = 0; i < detectionMat.rows; i++)
	{
		float confidence = detectionMat.at<float>(i, 2);

		if (confidence > confidenceThreshold)
		{
			size_t objectClass = (size_t)(detectionMat.at<float>(i, 1));
			cout << "g:objectClass = " << objectClass << endl;
			if (fabs(objectClass - id_type) < 1.0)
			{
				float  conf_cur = detectionMat.at<float>(i, 2);
				if (val_conf < conf_cur)
				{
					val_conf = conf_cur;
					cout << "g:val_conf = " << val_conf << endl;

					//static_cast<int>
					float left = (detectionMat.at<float>(i, 3));
					float top = (detectionMat.at<float>(i, 4));
					float right = (detectionMat.at<float>(i, 5));
					float bottom = (detectionMat.at<float>(i, 6));

					cout << "g:(left, top, right, bottom) = " << left << " , " << top << " , " << right << " , " << bottom << endl;


					ft4[0] = left;
					ft4[1] = top;
					ft4[2] = right;
					ft4[3] = bottom;
					cout << "g:ft4[0],ft4[1],ft4[2],ft4[3] = " << ft4[0] << ", " << ft4[1] << " , " << ft4[2] << " , " << ft4[3] << endl;

					id_line = i;
					conf = val_conf;
				}
			}
		}
	}
	cout << "g:ft4[0],ft4[1],ft4[2],ft4[3] = " << ft4[0] << ", " << ft4[1] << " , " << ft4[2] << " , " << ft4[3] << endl;
	return 0;
}

// mobile-net,   框框优化
void CobjectRecoStudyDlg::OnBnClickedButton6_rectangleFineMobile()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	string  videoName;
	fetchFileName(videoName);

	Net  net;
	net_prepare(net);
	Mat  src_store = imread(videoName, 1);
	if (!src_store.data)
	{
		FreeConsole();
		return;
	}

	Mat  gray = src_store.clone();
	if (src_store.channels() == 3)
	{
		cvtColor(src_store, gray, CV_BGR2GRAY);
	}
	imwrite((videoName + ".gray.jpg").c_str(), gray);



	Mat  frame_tr = src_store.clone();
	imshow("frame_tr", frame_tr);


	Mat  res_detectionMat;
	imageProc(frame_tr, net, res_detectionMat);
	imshow("frame_tr", frame_tr);
	waitKey(10);


	if (!res_detectionMat.data)
	{
		FreeConsole();
		return;
	}

	int  id_max_conf = 78;
	//id_max_conf =  getMax
	int  id_type = 84;
	float ft4[4];
	float  conf = 0;
	int  id_line = 0;
	get_right_type_and_conf_and_pts(res_detectionMat, id_type, conf, ft4, id_line);
	cout << "id_type, conf,   id_line = " << id_type << "," << conf << "," << id_line << endl;


	int left;
	int top;//= static_cast<int>(res_detectionMat.at<float>(id_max_conf, 4) * frame_tr.rows);
	int right; 
	int bottom; 


	left = ft4[0] * frame_tr.cols;
	top = ft4[1] * frame_tr.rows;
	right = ft4[2] * frame_tr.cols;
	bottom = ft4[3] * frame_tr.rows;


	// get  intresting field 
	Mat  frame_post = src_store.clone();
	if (1)
	{
		if (frame_post.channels() == 1)
		{
			Mat tmp;
			cvtColor(frame_post, tmp, CV_GRAY2BGR);
			tmp.copyTo(frame_post);
		}

		cout << "grab cut processing..." << endl;
		cout << "OnBnClickedButton6_rectangleFineMobile-(left, top, right, bottom) = " << left << " , " << top << " , " << right << " , " << bottom << endl;

		//return;
		Mat   imgGray = frame_post.clone();

		//int  stepLenthOfRectExpend = 0;
		float  residure = 10.0;

		//  adapt-grabcut  
		for (int j = -30; j < 30; j += 4)
		{
			Mat  frame_01 = imgGray.clone();
			cout << "________________________________________________________________" << endl;
			cout << "框框调整： j = " << j << endl;
			Rect grabcutRect = Rect(left, top, right - left, bottom - top);

			int  res_rect = rect_modifier(grabcutRect, j);
			if (res_rect < 0)
			{
				cout << "矩形调整失败，跳过。  res_rect < 0 " << endl;
				continue;
			}

			Mat show_rect = frame_post.clone();
			rectangle(show_rect, grabcutRect, Scalar(0, 255, 0));
			//Mat  rect_check = frame_post(grabcutRect);
			imshow("show_rect", show_rect);
			waitKey(10);
			//return;
			cout << "grabcutRect = " << grabcutRect << endl;
			cout << " frame_post.size() = " << frame_post.size() << endl;

			//grabcut 
			Mat  grabcutResult;
			Mat bgModel, fgModel;
			int  nums_iter = 3;// 8;// 5;//3  
			grabCut(frame_post, grabcutResult, grabcutRect, bgModel, fgModel, nums_iter, cv::GC_INIT_WITH_RECT);
			cout << "finish grab cut process ." << endl;

			//show 
			imwrite("3.jpg", (grabcutResult - 2) * 255);
			imwrite("2.jpg", 255 - (5 - (grabcutResult + 2)) * 255);
			imshow("3.jpg", (grabcutResult - 2) * 255);
			imshow("2.jpg", 255 - (5 - (grabcutResult + 2)) * 255);
			waitKey(10);

			// storage 
			FileStorage fs__grabcutResult("grabcutResult.xml", FileStorage::WRITE);
			fs__grabcutResult << "grabcutResult" << grabcutResult;
			fs__grabcutResult.release();

			//compare 
			compare(grabcutResult, GC_PR_FGD, grabcutResult, CMP_EQ);
			//得到前景mask 
			Mat foreground(frame_post.size(), CV_8UC3, Scalar::all(255));
			frame_post.copyTo(foreground, grabcutResult);
			//imshow("grabcut", foreground);
			imwrite("foreground.jpg", foreground);
			imshow("foreground", foreground);
			waitKey(20);

			//gray 
			Mat  gray;
			cvtColor(foreground, gray, CV_BGR2GRAY);
			gray = 255 - gray;
			imwrite("gray.jpg", gray);
			imshow("gray", gray);
			waitKey(20);

			gray = gray * 255;

			//threshold 
			if (0)
			{
				Mat gray_threshold;
				adaptiveThreshold(gray, gray_threshold, 255, ADAPTIVE_THRESH_MEAN_C, THRESH_BINARY, 5, 0);
				imwrite("gray_threshold.jpg", gray_threshold);
				imshow("gray_threshold", gray_threshold);
				waitKey(20);
			}
			//threshold 
			Mat gray_threshold;
			threshold(gray, gray_threshold, 5, 255, 0);  //第一次必须要小
			GaussianBlur(gray_threshold, gray_threshold, Size(3, 3), 3, 3);
			threshold(gray, gray_threshold, 128, 255, 0);//后面必须128
			GaussianBlur(gray_threshold, gray_threshold, Size(3, 3), 3, 3);
			imshow("gray_threshold", gray_threshold);
			waitKey(20);


			int  thresh = 128;
			vector<Point2f>   pts4_01;
			int  ind = 0;
			for (int k = 1; k < 1000; k += 100)
			{
				cout << "四边形逼近调整： k = " << k << endl;
				pts4_01.clear();
				approxPolyDP_app_fit_4p(thresh, gray_threshold, pts4_01, k, k);
				residure = calc_residure_4p(gray_threshold, pts4_01);
				cout << "k, len,  residure = " << k << "," << pts4_01.size() << "," << residure << endl;
				if (pts4_01.size() == 4)
				{
					ind = 1;
					cout << "经过了多少步终于达到四边形 : " << endl;
					cout << "k, len,  residure = " << k << "," << pts4_01.size() << "," << residure << endl;

					//show  
					Mat src_show_4p = src_store.clone();
					for (int n = 0; n < 4; n++)
					{
						circle(src_show_4p, pts4_01[n], 3 + 3 * n, Scalar(255, 0, 255), 2, 8, 0);
						putText(src_show_4p, to_string(n), pts4_01[n], 1, 1, Scalar(0, 0, 255), 1, 8, false);
					}
					imshow("src_show_4p.jpg", src_show_4p);


					break;
				}
			}
			if (ind != 1)
			{
				cout << endl;
				cout << "定框失败。4点失败。" << endl;
			}
			char key = waitKey(0);
			if (key > 0)
				continue;
		}
	}

	FreeConsole();
}





//   ----------------------------------------------- s - g -----------------------------------------    
Rect selection;
Mat img, img0;
Point prePt(-1, -1);

void onMouse(int event, int x, int y, int flags, void* param)
{
	if (event == CV_EVENT_LBUTTONDOWN)
	{
		prePt = Point(x, y);
	}
	else if (event == CV_EVENT_MOUSEMOVE && (flags && CV_EVENT_FLAG_LBUTTON))
	{
		img = img0.clone();
		rectangle(img, Rect(prePt.x, prePt.y, abs(x - prePt.x), abs(y - prePt.y)),
			Scalar(0, 0, 255), 3);
		selection = Rect(prePt.x, prePt.y, abs(x - prePt.x), abs(y - prePt.y));
	}
	else if (event == CV_EVENT_LBUTTONUP || !(flags & CV_EVENT_FLAG_LBUTTON))
	{
		prePt = Point(-1, -1);
	}
	imshow("原图", img);
}

int main_studyGrabcut(string nameOfImage)
{
	//img = imread("D:\\images/3.jpg", 1);
	img = imread(nameOfImage, 1);
	if (!img.data)
		return -1;

	img0 = img.clone();
	namedWindow("原图", 1);
	imshow("原图", img);

	setMouseCallback("原图", onMouse);


	Mat result;
	// 4种可能结果 
	Mat bgModel, fgModel; // 背景/前景 

	for (int i = 0; i < 15; i += 3)
	{
		while (1)
		{
			int c = waitKey(10);
			if ((char)c == 'p')
			{
				grabCut(img0, result, selection, bgModel, fgModel, i, GC_INIT_WITH_RECT); //  i=3;
				compare(result, GC_PR_FGD, result, CMP_EQ);
				//得到前景mask 
				Mat foreground(img.size(), CV_8UC3, Scalar::all(255));
				img0.copyTo(foreground, result);

				putText(foreground, to_string(i), Point(10, 10), 1, 2, Scalar(255, 255, 128), 2);

				imshow("grabcut", foreground);
				waitKey(10);
			}
			if (char(c) == 'q')
				break;

			if (char(c) > 0 && (char)c != 'p')
				break;
		}

	}
	destroyWindow("原图");
	return 0;
}

void CobjectRecoStudyDlg::OnBnClickedButton7_grabcutStudy()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	string nameOfImage;
	fetchFileName(nameOfImage);
	main_studyGrabcut(nameOfImage);

	FreeConsole();
}





void CobjectRecoStudyDlg::OnBnClickedButton8_setIdCamera()
{
	// TODO: 在此添加控件通知处理程序代码

	// TODO: 在此添加控件通知处理程序代码
	CString str2("0");
	GetDlgItemText(IDC_EDIT1, str2);
	//str2.
	int i = 0;
	LPTSTR lpsz;// = 20;
	lpsz = (LPTSTR)(LPCTSTR)str2;
	i = _ttoi(str2);
	//str2.Format(_T("%d"), i)   ;
	id_camera = i;

	//AfxMessageBox(_T("最大视频帧数设置完成，谢谢！ "));
	CString cstr;
	cstr.Format(_T("id_camera设置完成，谢谢！id_camera为： %d"), i);
	AfxMessageBox(cstr);

	//append_string_on_edit_controler(IDC_EDIT2, CString("id_camera设置完成，谢谢！id_camera为： ")
	//	+ CString(to_string(id_camera).c_str()));

	CString  cs = CString("id_camera设置完成，谢谢！id_camera为： ")
		+ CString(to_string(id_camera).c_str());// ("");
	CString str21;
	GetDlgItemText(IDC_EDIT2, str21);
	str21 = str21 + CString("\r\n");
	cs = str21 + cs;
	SetDlgItemText(IDC_EDIT2, cs);

}


void CobjectRecoStudyDlg::OnBnClickedButton9_caffeModel()
{
	// TODO: 在此添加控件通知处理程序代码
	//CaffeModelDlg    cm;
	//cm.DoModal();
	CaffeModelDialog   cmd;
	cmd.DoModal();
}


void CobjectRecoStudyDlg::OnBnClickedButton10_tensorflowModel()
{
	// TODO: 在此添加控件通知处理程序代码
	TensorflowModelStudy   sd;
	sd.DoModal();

}


void CobjectRecoStudyDlg::OnBnClickedButton11TorchStudy()
{
	// TODO: 在此添加控件通知处理程序代码
	TorchModelStudy   sd;
	sd.DoModal();
}


void CobjectRecoStudyDlg::OnBnClickedButton12ClassicalStudy()
{
	// TODO: 在此添加控件通知处理程序代码
	ClassicalStudy   sd;
	sd.DoModal();


}


void CobjectRecoStudyDlg::OnBnClickedButton13SSD_Study()
{
	// TODO: 在此添加控件通知处理程序代码
	ssdModelStudy   sd;
	sd.DoModal();
}







void CobjectRecoStudyDlg::OnBnClickedButton14_oneKeyRunAll()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);
	cout << "void CobjectRecoStudyDlg::OnBnClickedButton14_oneKeyRunAll() " << endl;


	FreeConsole();
}
