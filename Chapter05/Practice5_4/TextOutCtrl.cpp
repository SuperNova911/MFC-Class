// TextOutCtrl.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Practice5_4.h"
#include "TextOutCtrl.h"
#include "afxdialogex.h"


// CTextOutCtrl 대화 상자입니다.

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


// CTextOutCtrl 메시지 처리기입니다.


BOOL CTextOutCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	SetDlgItemText(IDC_EDIT_COLOR, TEXT("000000"));
	SetDlgItemText(IDC_EDIT_FONT, TEXT("system"));

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}
