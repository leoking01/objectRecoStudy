#pragma once


// CaffeModelDialog �Ի���

class CaffeModelDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CaffeModelDialog)

public:
	CaffeModelDialog(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CaffeModelDialog();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1CaffeModel };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
