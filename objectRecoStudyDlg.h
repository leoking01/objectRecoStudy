
// objectRecoStudyDlg.h : 头文件
//

#pragma once


// CobjectRecoStudyDlg 对话框
class CobjectRecoStudyDlg : public CDialogEx
{
// 构造
public:
	CobjectRecoStudyDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OBJECTRECOSTUDY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1_maskRcnn_image_locate();
	afx_msg void OnBnClickedButton2_locPts4();
	afx_msg void OnBnClickedButton3_objectLocateCamera();
	afx_msg void OnBnClickedButton4_localObjMobileCamera();

	  void  fetchFileName(string & nameOut );
	  afx_msg void OnBnClickedButton5_objectMaskRcnnVideo();
	  afx_msg void OnBnClickedButton6_rectangleFineMobile();
	  afx_msg void OnBnClickedButton7_grabcutStudy();
	  afx_msg void OnBnClickedButton8_setIdCamera();

public:
	int  id_camera;
};



int main_studyGrabcut(string nameOfImage);



