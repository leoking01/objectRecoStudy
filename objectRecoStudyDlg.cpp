
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
	ON_BN_CLICKED(IDC_BUTTON1, &CobjectRecoStudyDlg::OnBnClickedButton1_objectLocate)
	ON_BN_CLICKED(IDC_BUTTON2, &CobjectRecoStudyDlg::OnBnClickedButton2_locPts4)
	ON_BN_CLICKED(IDC_BUTTON3, &CobjectRecoStudyDlg::OnBnClickedButton3_objectLocateCamera)
	ON_BN_CLICKED(IDC_BUTTON4, &CobjectRecoStudyDlg::OnBnClickedButton4_localObjMobileCamera)
	ON_BN_CLICKED(IDC_BUTTON5, &CobjectRecoStudyDlg::OnBnClickedButton5_objectMaskRcnnVideo)
	ON_BN_CLICKED(IDC_BUTTON6, &CobjectRecoStudyDlg::OnBnClickedButton6_rectangleFineMobile)
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
		namedWindow("view", WINDOW_AUTOSIZE);
		HWND hWnd = (HWND)cvGetWindowHandle("view");
		HWND hParent = ::GetParent(hWnd);
		::SetParent(hWnd, GetDlgItem(IDC_PIC_STATIC)->m_hWnd);
		::ShowWindow(hParent, SW_HIDE);
	}
#endif 





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


int   locat4pt2fFromScene(Mat inputImage, Point2f*   ptf4)
{
	if (!inputImage.data)
	{
		cout << "!inputImage.data" << endl;
		return  -1;
	}


	int  res = recoImageSingle(inputImage);
	cout << "res = " << res << endl;

	return 0;
}

void CobjectRecoStudyDlg::OnBnClickedButton1_objectLocate()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	string  str = "d:/images/book.jpg";
	ifstream ifile(str);
	if (!ifile)
	{
		cout << "文件不存在， str =  " << str << endl;
		throw("error");
		return;
	}
	ifile.close();

	Mat inputImage = imread(str, 1);
	Point2f   ptf4[4];
	locat4pt2fFromScene(inputImage, ptf4);

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
			OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT | OFN_ALLOWMULTISELECT,  NULL, this);   //选择文件对话框  

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
		imshow("view009", imagedst);
	}
#endif


}


void  videoProc_maskRcnn(int  opt, Net  net, int  idx_camera, string   nameOfVideo)
{
	VideoCapture  vc;
	if (opt == 0)
		vc.open(idx_camera);
	else if (opt == 1)
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
			procImage(frame, net, id);
			end = clock();
			printf("用时：第%d帧， time=%f\n",id ,  ((double)end - start) / CLK_TCKCLOCKS_PER_SEC);
		}
		vc >> frame;
		id++;
		if (frame.data)
		{
			imshow("frame", frame);
			waitKey( 10  );
		}
		if (waitKey(10) > 0)
		{
			cout << "usr allert  a key-event .  program   exit .  " << endl;
			break;
		}

	}
	vc.release();
	//waitKey(0);
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
	int  res_net = net_init(net   );
	if (res_net < 0)
		return;

	end = clock();

	printf("初始化网络用时间： time=%f\n", ((double)end - start) / CLK_TCKCLOCKS_PER_SEC);

	string  nameOfVideo = "D:\\video/7f741afd5fc83b507f64ed09c70da81e.mp4";
	int  id_cam = 0;
	videoProc_maskRcnn(    id_cam,   net,  0, nameOfVideo);

	FreeConsole();
	return;
}





// 使用mobilenet
void CobjectRecoStudyDlg::OnBnClickedButton4_localObjMobileCamera()
{
	// TODO: 在此添加控件通知处理程序代码
	AllocConsole();
	freopen("CONOUT$", "w", stdout);

	string  videoName ;
	fetchFileName(videoName  );

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
			//imageProc(src, net, res_detectionMat);
			imageProc(frame, net , res_detectionMat );
			imshow( "frame", frame);
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



void CobjectRecoStudyDlg::    fetchFileName( string & nameOut  )
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
	int  res_net = net_init(net);
	if (  res_net < 0  )
		return;

	end = clock();
#ifndef CLK_TCKCLOCKS_PER_SEC 
#define CLK_TCKCLOCKS_PER_SEC   1000  
#endif
	printf("初始化网络用时间： time=%f\n", ((double)end - start) / CLK_TCKCLOCKS_PER_SEC);


	string  nameOfVideo = videoName;
	int  id_cam = 1;
	videoProc_maskRcnn(id_cam, net, 0, nameOfVideo);

	FreeConsole();
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
	Mat  src = imread(videoName );
	if (!src.data)
	{
		FreeConsole();
		return;
	}
		
	Mat  res_detectionMat;
	imageProc(src, net , res_detectionMat   );
	imshow( "src",  src );
	waitKey( 10 );

	if (!res_detectionMat.data)
	{
		FreeConsole();
		return;
	}

	int  id_max_conf = 79;
	int left = static_cast<int>(res_detectionMat.at<float>(id_max_conf, 3) * src.cols);
	int top = static_cast<int>(res_detectionMat.at<float>(id_max_conf, 4) * src.rows);
	int right = static_cast<int>(res_detectionMat.at<float>(id_max_conf, 5) * src.cols);
	int bottom = static_cast<int>(res_detectionMat.at<float>(id_max_conf, 6) * src.rows);


	if (1)
	{
		Mat  frame_01 = src.clone();
		if (frame_01.channels() == 3)
		{
			Mat tmp;
			cvtColor(frame_01,tmp,  CV_BGR2GRAY   );
			tmp.copyTo(frame_01);
		}

		cout << "grab cut processing..." << endl;
		Mat bgModel, fgModel;
		cout << "OnBnClickedButton6_rectangleFineMobile-(left, top, right, bottom) = " << left << " , " << top << " , " << right << " , " << bottom << endl;
		
		return;
		
		Rect grabcutRect = Rect(left, top, right-left , bottom-top   );    //566   360   
		imshow("frame(grabcutRect)", frame_01(grabcutRect));

		//waitKey(  0);
		//exit( 0 );

		Mat  grabcutResult;
		grabCut(frame_01, grabcutResult, grabcutRect, bgModel, fgModel, 3, cv::GC_INIT_WITH_RECT);
		cout << "finish grab cut process ." << endl;
		imshow( "grabcutResult", grabcutResult);
		waitKey( 20  );
	}

	FreeConsole();
}
