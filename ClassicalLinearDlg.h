#pragma once


// ClassicalLinearDlg �Ի���

class ClassicalLinearDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ClassicalLinearDlg)

public:
	ClassicalLinearDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ClassicalLinearDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2ClassicalLinear };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
