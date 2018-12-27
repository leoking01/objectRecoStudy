#pragma once


// TorchModelStudy 对话框

class TorchModelStudy : public CDialogEx
{
	DECLARE_DYNAMIC(TorchModelStudy)

public:
	TorchModelStudy(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TorchModelStudy();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1TorchStudy };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
