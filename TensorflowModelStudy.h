#pragma once


// TensorflowModelStudy �Ի���

class TensorflowModelStudy : public CDialogEx
{
	DECLARE_DYNAMIC(TensorflowModelStudy)

public:
	TensorflowModelStudy(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TensorflowModelStudy();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1TensorflowModel };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
