#pragma once


// ssdModelStudy �Ի���

class ssdModelStudy : public CDialogEx
{
	DECLARE_DYNAMIC(ssdModelStudy)

public:
	ssdModelStudy(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ssdModelStudy();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1SSD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
