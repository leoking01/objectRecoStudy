#pragma once


// TorchModelStudy �Ի���

class TorchModelStudy : public CDialogEx
{
	DECLARE_DYNAMIC(TorchModelStudy)

public:
	TorchModelStudy(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~TorchModelStudy();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1TorchStudy };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
