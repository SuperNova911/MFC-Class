
// Practice10_1View.cpp : CPractice10_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Practice10_1.h"
#endif

#include "Practice10_1Doc.h"
#include "Practice10_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice10_1View

IMPLEMENT_DYNCREATE(CPractice10_1View, CFormView)

BEGIN_MESSAGE_MAP(CPractice10_1View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_BN_CLICKED(IDC_BUTTON_OUTPUT, &CPractice10_1View::OnClickedButtonOutput)
	ON_BN_CLICKED(IDC_BUTTON_COLOR, &CPractice10_1View::OnClickedButtonColor)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CPractice10_1View::OnClickedButtonReset)
	ON_WM_HSCROLL()
	ON_EN_CHANGE(IDC_EDIT_RED, &CPractice10_1View::OnChangeEditRed)
	ON_EN_CHANGE(IDC_EDIT_GREEN, &CPractice10_1View::OnChangeEditGreen)
	ON_EN_CHANGE(IDC_EDIT_BLUE, &CPractice10_1View::OnChangeEditBlue)
	ON_EN_CHANGE(IDC_EDIT_TEXT, &CPractice10_1View::OnChangeEditText)
END_MESSAGE_MAP()

// CPractice10_1View ����/�Ҹ�

CPractice10_1View::CPractice10_1View()
	: CFormView(IDD_PRACTICE10_1_FORM)
	, m_strText(_T(""))
	, m_nRed(0)
	, m_nGreen(0)
	, m_nBlue(0)
	, m_nX(0)
	, m_nY(0)
{
	m_colorText = RGB(0, 0, 0);
	m_nX = 30;
	m_nY = 270;
}

CPractice10_1View::~CPractice10_1View()
{
}

void CPractice10_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strText);
	DDX_Text(pDX, IDC_EDIT_RED, m_nRed);
	DDV_MinMaxInt(pDX, m_nRed, 0, 255);
	DDX_Text(pDX, IDC_EDIT_GREEN, m_nGreen);
	DDV_MinMaxInt(pDX, m_nGreen, 0, 255);
	DDX_Text(pDX, IDC_EDIT_BLUE, m_nBlue);
	DDV_MinMaxInt(pDX, m_nBlue, 0, 255);
	DDX_Text(pDX, IDC_EDIT_X, m_nX);
	DDX_Text(pDX, IDC_EDIT_Y, m_nY);
	DDX_Control(pDX, IDC_SLIDER_X, m_sliderX);
	DDX_Control(pDX, IDC_SLIDER_Y, m_sliderY);
}

BOOL CPractice10_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CPractice10_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	m_sliderX.SetRange(20, 300);
	m_sliderY.SetRange(260, 500);
	m_sliderX.SetPos(30);
	m_sliderX.SetPos(270);
}

void CPractice10_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice10_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice10_1View ����

#ifdef _DEBUG
void CPractice10_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CPractice10_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPractice10_1Doc* CPractice10_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice10_1Doc)));
	return (CPractice10_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice10_1View �޽��� ó����


void CPractice10_1View::OnClickedButtonOutput()
{
	UpdateData(true);

	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);

	if (m_nRed > 255 || m_nRed < 0 ||
		m_nGreen > 255 || m_nGreen < 0 ||
		m_nBlue > 255 || m_nBlue < 0)
	{
		AfxMessageBox(TEXT("�߸��� �����Դϴ�."));
	}
	else
		Invalidate();
}


void CPractice10_1View::OnClickedButtonColor()
{
	CColorDialog colorDlg;

	if (colorDlg.DoModal() == IDOK)
		m_colorText = colorDlg.GetColor();

	m_nRed = GetRValue(m_colorText);
	m_nGreen = GetGValue(m_colorText);
	m_nBlue = GetBValue(m_colorText);

	UpdateData(false);

	Invalidate();
	
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnClickedButtonReset()
{
	m_strText.Empty();
	m_nRed = m_nGreen = m_nBlue = 0;
	m_nX = 30;
	m_nY = 270;
	m_sliderX.SetPos(30);
	m_sliderY.SetPos(270);

	UpdateData(false);

	Invalidate();

	GetDocument()->OnNewDocument();
}


void CPractice10_1View::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	int nX = m_sliderX.GetPos();
	int nY = m_sliderY.GetPos();

	if (pScrollBar->GetSafeHwnd() == m_sliderX.m_hWnd)
		m_nX = nX;
	else if (pScrollBar->GetSafeHwnd() == m_sliderY.m_hWnd)
		m_nY = nY;
	else
		return;

	UpdateData(false);

	Invalidate();

	CFormView::OnHScroll(nSBCode, nPos, pScrollBar);
}


void CPractice10_1View::OnChangeEditRed()
{
	UpdateData(true);

	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnChangeEditGreen()
{
	UpdateData(true);

	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnChangeEditBlue()
{
	UpdateData(true);

	m_colorText = RGB(m_nRed, m_nGreen, m_nBlue);
	Invalidate();
	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnChangeEditText()
{
	UpdateData(true);

	GetDocument()->SetModifiedFlag();
}


void CPractice10_1View::OnDraw(CDC* pDC)
{
	pDC->SetTextColor(m_colorText);
	pDC->TextOutW(m_nX, m_nY, m_strText);

	m_sliderX.SetPos(m_nX);
	m_sliderY.SetPos(m_nY);
}
