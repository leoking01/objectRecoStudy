#pragma once


// ClassicalStudy 对话框

class ClassicalStudy : public CDialogEx
{
	DECLARE_DYNAMIC(ClassicalStudy)

public:
	ClassicalStudy(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ClassicalStudy();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2ClassicalStudy };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1_classical_Bayessian();
	afx_msg void OnBnClickedButton2_classical_Linear();
	afx_msg void OnBnClickedButton3_classical_Non_linear();
};
