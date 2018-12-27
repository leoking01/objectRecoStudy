#pragma once


// ssdModelStudy 对话框

class ssdModelStudy : public CDialogEx
{
	DECLARE_DYNAMIC(ssdModelStudy)

public:
	ssdModelStudy(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ssdModelStudy();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1SSD };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
