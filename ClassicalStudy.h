#pragma once


// ClassicalStudy �Ի���

class ClassicalStudy : public CDialogEx
{
	DECLARE_DYNAMIC(ClassicalStudy)

public:
	ClassicalStudy(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ClassicalStudy();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2ClassicalStudy };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
