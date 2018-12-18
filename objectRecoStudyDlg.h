
// objectRecoStudyDlg.h : ͷ�ļ�
//

#pragma once


// CobjectRecoStudyDlg �Ի���
class CobjectRecoStudyDlg : public CDialogEx
{
// ����
public:
	CobjectRecoStudyDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_OBJECTRECOSTUDY_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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



