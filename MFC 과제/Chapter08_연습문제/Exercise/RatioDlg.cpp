// RatioDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Exercise.h"
#include "RatioDlg.h"
#include "afxdialogex.h"
#include "ExerciseDlg.h"


// CRatioDlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(CRatioDlg, CDialogEx)

CRatioDlg::CRatioDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_RATIO, pParent)
	, m_nCurHScale(0)
	, m_nCurVScale(0)
	, m_bSameRatio(false)
{

}

CRatioDlg::~CRatioDlg()
{
}

void CRatioDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_SLIDER_HORIZONTAL, m_sliderHorizon);
	DDX_Control(pDX, IDC_SLIDER_VERTICAL, m_sliderVertical);
	DDX_Text(pDX, IDC_EDIT_HORIZONTAL, m_nCurHScale);
	DDX_Text(pDX, IDC_EDIT_VERTICAL, m_nCurVScale);
	DDX_Check(pDX, IDC_CHECK_SAME_RATIO, m_bSameRatio);
}


BEGIN_MESSAGE_MAP(CRatioDlg, CDialogEx)
	ON_WM_HSCROLL()
	ON_BN_CLICKED(IDC_CHECK_SAME_RATIO, &CRatioDlg::OnClickedCheckSameRatio)
END_MESSAGE_MAP()


// CRatioDlg 메시지 처리기입니다.


BOOL CRatioDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 초기화 작업
	// 슬라이더 범위 지정
	m_sliderHorizon.SetRange(0, 100);
	m_sliderVertical.SetRange(0, 100);

	// 슬라이더 초기값 지정
	m_sliderHorizon.SetPos(50);
	m_sliderVertical.SetPos(50);

	// 에디트박스, 체크박스 초기값 지정
	m_nCurHScale = 50;
	m_nCurVScale = 50;

	m_bSameRatio = true;

	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


// 슬라이더 이벤트
void CRatioDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CExerciseDlg* pMainDlg = (CExerciseDlg*)AfxGetMainWnd();

	// 슬라이더 값 얻기
	int nHorzion = m_sliderHorizon.GetPos();
	int nVertical = m_sliderVertical.GetPos();

	// 수평 슬라이더
	if (pScrollBar->GetSafeHwnd() == m_sliderHorizon.m_hWnd)
	{
		m_nCurHScale = nHorzion;

		// 정 비율이면 수직 슬라이더도 같이 움직임
		if (m_bSameRatio)
		{
			m_nCurVScale = nHorzion;
			m_sliderVertical.SetPos(nHorzion);
		}
	}
	// 수직 슬라이더
	else if (pScrollBar->GetSafeHwnd() == m_sliderVertical.m_hWnd)
	{
		m_nCurVScale = nVertical;

		// 정 비율이면 수평 슬라이더도 같이 움직임
		if (m_bSameRatio)
		{
			m_nCurHScale = nVertical;
			m_sliderHorizon.SetPos(nVertical);
		}
	}
	else
		return;

	UpdateData(false);

	// 그리기 업데이트
	pMainDlg->UpdateDrawing();

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


// 정 비율 체크박스 클릭 이벤트
void CRatioDlg::OnClickedCheckSameRatio()
{
	CExerciseDlg* pMainDlg = (CExerciseDlg*)AfxGetMainWnd();

	m_bSameRatio = !m_bSameRatio;

	// 체크박스 값이 TRUE로 변할 때
	// 작은 값의 슬라이더를 큰 값의 슬라이더와 같게 맞춤
	if (m_bSameRatio == false)
		return;

	if (m_nCurHScale > m_nCurVScale)
	{
		m_sliderVertical.SetPos(m_nCurHScale);
		m_nCurVScale = m_nCurHScale;
	}
	else
	{
		m_sliderHorizon.SetPos(m_nCurVScale);
		m_nCurHScale = m_nCurVScale;
	}

	UpdateData(false);

	// 그리기 업데이트
	pMainDlg->UpdateDrawing();
}
