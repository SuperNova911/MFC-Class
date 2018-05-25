// ObjectDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Exercise.h"
#include "ObjectDlg.h"
#include "afxdialogex.h"
#include "ExerciseDlg.h"


// CObjectDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CObjectDlg, CDialogEx)

CObjectDlg::CObjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_OBJECT, pParent)
{

	m_nSelObject = 0;
}

CObjectDlg::~CObjectDlg()
{
}

void CObjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CObjectDlg, CDialogEx)
	ON_COMMAND(IDC_RADIO_RECT, &CObjectDlg::OnRadioRect)
	ON_COMMAND(IDC_RADIO_CIRCLE, &CObjectDlg::OnRadioCircle)
END_MESSAGE_MAP()


// CObjectDlg 메시지 처리기입니다.


BOOL CObjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// 1: 사각형, 2:원
	// 기본값: 2
	m_nSelObject = 2;
	((CButton*)GetDlgItem(IDC_RADIO_CIRCLE))->SetCheck(true);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


// 사각형 선택
void CObjectDlg::OnRadioRect()
{
	CExerciseDlg* pMainDlg = (CExerciseDlg*)AfxGetMainWnd();

	m_nSelObject = 1;

	// 그리기 업데이트
	pMainDlg->UpdateDrawing();
}

// 원 선택
void CObjectDlg::OnRadioCircle()
{
	CExerciseDlg* pMainDlg = (CExerciseDlg*)AfxGetMainWnd();

	m_nSelObject = 2;
	
	// 그리기 업데이트
	pMainDlg->UpdateDrawing();
}
