// TextOutCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Practice5_4.h"
#include "TextOutCtrl.h"
#include "afxdialogex.h"


// CTextOutCtrl ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CTextOutCtrl, CDialogEx)

CTextOutCtrl::CTextOutCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_TEXTOUT, pParent)
{

}

CTextOutCtrl::~CTextOutCtrl()
{
}

void CTextOutCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTextOutCtrl, CDialogEx)
END_MESSAGE_MAP()


// CTextOutCtrl �޽��� ó�����Դϴ�.


BOOL CTextOutCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	SetDlgItemText(IDC_EDIT_COLOR, TEXT("000000"));
	SetDlgItemText(IDC_EDIT_FONT, TEXT("system"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}
