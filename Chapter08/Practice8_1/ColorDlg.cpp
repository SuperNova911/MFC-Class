// ColorDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Practice8_1.h"
#include "ColorDlg.h"
#include "afxdialogex.h"
#include "Practice8_1Dlg.h"


// CColorDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CColorDlg, CDialogEx)

CColorDlg::CColorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CColorDlg::IDD, pParent)
{

	m_nBlue = 0;
	m_nGreen = 0;
	m_nRed = 0;
}

CColorDlg::~CColorDlg()
{
}

void CColorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BLUE, m_nBlue);
	DDX_Text(pDX, IDC_EDIT_GREEN, m_nGreen);
	DDX_Text(pDX, IDC_EDIT_RED, m_nRed);
	DDX_Control(pDX, IDC_SLIDER_BLUE, m_sliderBlue);
	DDX_Control(pDX, IDC_SLIDER_GREEN, m_sliderGreen);
	DDX_Control(pDX, IDC_SLIDER_RED, m_sliderRed);
}


BEGIN_MESSAGE_MAP(CColorDlg, CDialogEx)
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// CColorDlg 메시지 처리기입니다.


BOOL CColorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	m_colorObject = RGB(0, 0, 0);
	m_sliderRed.SetRange(0, 255);
	m_sliderGreen.SetRange(0, 255);
	m_sliderBlue.SetRange(0, 255);

	return TRUE;  // return TRUE unless you set the focus to a control
	// 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CColorDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CPractice8_1Dlg* pMainDlg = (CPractice8_1Dlg*) AfxGetMainWnd();
	
	int nRed = m_sliderRed.GetPos();
	int nGreen = m_sliderGreen.GetPos();
	int nBlue = m_sliderBlue.GetPos();

	if (pScrollBar->GetSafeHwnd() == m_sliderRed.m_hWnd)
		m_nRed = nRed;
	else if (pScrollBar->GetSafeHwnd() == m_sliderGreen.m_hWnd)
		m_nGreen = nGreen;
	else if (pScrollBar->GetSafeHwnd() == m_sliderBlue.m_hWnd)
		m_nBlue = nBlue;
	else
		return;

	m_colorObject = RGB(nRed, nGreen, nBlue);

	UpdateData(false);

	pMainDlg->UpdateDrawing();


	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}
