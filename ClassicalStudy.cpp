// ClassicalStudy.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "objectRecoStudy.h"
#include "ClassicalStudy.h"
#include "afxdialogex.h"


// ClassicalStudy �Ի���

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


// ClassicalStudy ��Ϣ�������


void ClassicalStudy::OnBnClickedButton1_classical_Bayessian()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void ClassicalStudy::OnBnClickedButton2_classical_Linear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}


void ClassicalStudy::OnBnClickedButton3_classical_Non_linear()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
