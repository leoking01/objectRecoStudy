// ClassicalStudy.cpp : 实现文件
//

#include "stdafx.h"
#include "objectRecoStudy.h"
#include "ClassicalStudy.h"
#include "afxdialogex.h"


// ClassicalStudy 对话框

IMPLEMENT_DYNAMIC(ClassicalStudy, CDialogEx)

ClassicalStudy::ClassicalStudy(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2ClassicalStudy, pParent)
{

}

ClassicalStudy::~ClassicalStudy()
{
}

void ClassicalStudy::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(ClassicalStudy, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ClassicalStudy::OnBnClickedButton1_classical_Bayessian)
	ON_BN_CLICKED(IDC_BUTTON2, &ClassicalStudy::OnBnClickedButton2_classical_Linear)
	ON_BN_CLICKED(IDC_BUTTON3, &ClassicalStudy::OnBnClickedButton3_classical_Non_linear)
END_MESSAGE_MAP()


// ClassicalStudy 消息处理程序


void ClassicalStudy::OnBnClickedButton1_classical_Bayessian()
{
	// TODO: 在此添加控件通知处理程序代码
}


void ClassicalStudy::OnBnClickedButton2_classical_Linear()
{
	// TODO: 在此添加控件通知处理程序代码
}


void ClassicalStudy::OnBnClickedButton3_classical_Non_linear()
{
	// TODO: 在此添加控件通知处理程序代码
}
