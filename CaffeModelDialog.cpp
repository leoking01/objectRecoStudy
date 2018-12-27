// CaffeModelDialog.cpp : 实现文件
//

#include "stdafx.h"
#include "objectRecoStudy.h"
#include "CaffeModelDialog.h"
#include "afxdialogex.h"


// CaffeModelDialog 对话框

IMPLEMENT_DYNAMIC(CaffeModelDialog, CDialogEx)

CaffeModelDialog::CaffeModelDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1CaffeModel, pParent)
{

}

CaffeModelDialog::~CaffeModelDialog()
{
}

void CaffeModelDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CaffeModelDialog, CDialogEx)
END_MESSAGE_MAP()


// CaffeModelDialog 消息处理程序
