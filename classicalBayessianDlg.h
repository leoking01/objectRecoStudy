#pragma once


// classicalBayessianDlg �Ի���

class classicalBayessianDlg : public CDialogEx
{
	DECLARE_DYNAMIC(classicalBayessianDlg)

public:
	classicalBayessianDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~classicalBayessianDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1ClassicalBayessian };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
