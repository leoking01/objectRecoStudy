#pragma once


// TensorflowModelStudy 对话框

class TensorflowModelStudy : public CDialogEx
{
	DECLARE_DYNAMIC(TensorflowModelStudy)

public:
	TensorflowModelStudy(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~TensorflowModelStudy();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1TensorflowModel };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
