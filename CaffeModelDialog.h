#pragma once


// CaffeModelDialog 对话框

class CaffeModelDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CaffeModelDialog)

public:
	CaffeModelDialog(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CaffeModelDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1CaffeModel };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
