#pragma once


// ClassicalLinearDlg 对话框

class ClassicalLinearDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ClassicalLinearDlg)

public:
	ClassicalLinearDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ClassicalLinearDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2ClassicalLinear };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
