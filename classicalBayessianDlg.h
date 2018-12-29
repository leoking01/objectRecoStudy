#pragma once


// classicalBayessianDlg 对话框

class classicalBayessianDlg : public CDialogEx
{
	DECLARE_DYNAMIC(classicalBayessianDlg)

public:
	classicalBayessianDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~classicalBayessianDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1ClassicalBayessian };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
