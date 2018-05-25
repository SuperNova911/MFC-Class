// RatioDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Exercise.h"
#include "RatioDlg.h"
#include "afxdialogex.h"
#include "ExerciseDlg.h"


// CRatioDlg ��ȭ �����Դϴ�.

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


// CRatioDlg �޽��� ó�����Դϴ�.


BOOL CRatioDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ʱ�ȭ �۾�
	// �����̴� ���� ����
	m_sliderHorizon.SetRange(0, 100);
	m_sliderVertical.SetRange(0, 100);

	// �����̴� �ʱⰪ ����
	m_sliderHorizon.SetPos(50);
	m_sliderVertical.SetPos(50);

	// ����Ʈ�ڽ�, üũ�ڽ� �ʱⰪ ����
	m_nCurHScale = 50;
	m_nCurVScale = 50;

	m_bSameRatio = true;

	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


// �����̴� �̺�Ʈ
void CRatioDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	CExerciseDlg* pMainDlg = (CExerciseDlg*)AfxGetMainWnd();

	// �����̴� �� ���
	int nHorzion = m_sliderHorizon.GetPos();
	int nVertical = m_sliderVertical.GetPos();

	// ���� �����̴�
	if (pScrollBar->GetSafeHwnd() == m_sliderHorizon.m_hWnd)
	{
		m_nCurHScale = nHorzion;

		// �� �����̸� ���� �����̴��� ���� ������
		if (m_bSameRatio)
		{
			m_nCurVScale = nHorzion;
			m_sliderVertical.SetPos(nHorzion);
		}
	}
	// ���� �����̴�
	else if (pScrollBar->GetSafeHwnd() == m_sliderVertical.m_hWnd)
	{
		m_nCurVScale = nVertical;

		// �� �����̸� ���� �����̴��� ���� ������
		if (m_bSameRatio)
		{
			m_nCurHScale = nVertical;
			m_sliderHorizon.SetPos(nVertical);
		}
	}
	else
		return;

	UpdateData(false);

	// �׸��� ������Ʈ
	pMainDlg->UpdateDrawing();

	CDialogEx::OnHScroll(nSBCode, nPos, pScrollBar);
}


// �� ���� üũ�ڽ� Ŭ�� �̺�Ʈ
void CRatioDlg::OnClickedCheckSameRatio()
{
	CExerciseDlg* pMainDlg = (CExerciseDlg*)AfxGetMainWnd();

	m_bSameRatio = !m_bSameRatio;

	// üũ�ڽ� ���� TRUE�� ���� ��
	// ���� ���� �����̴��� ū ���� �����̴��� ���� ����
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

	// �׸��� ������Ʈ
	pMainDlg->UpdateDrawing();
}
