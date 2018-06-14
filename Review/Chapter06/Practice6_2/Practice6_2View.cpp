
// Practice6_2View.cpp : CPractice6_2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Practice6_2.h"
#endif

#include "Practice6_2Doc.h"
#include "Practice6_2View.h"

#include "PenSizeDlg.h"
#include "EraserSizeDlg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice6_2View

IMPLEMENT_DYNCREATE(CPractice6_2View, CView)

BEGIN_MESSAGE_MAP(CPractice6_2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice6_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_PEN_SIZE, &CPractice6_2View::OnPenSize)
	ON_COMMAND(ID_ERASER_SIZE, &CPractice6_2View::OnEraserSize)
	ON_COMMAND(ID_PEN_COLOR, &CPractice6_2View::OnPenColor)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CPractice6_2View 생성/소멸

CPractice6_2View::CPractice6_2View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_nPenSize = 2;
	m_nEraserSize = 4;
	m_colorPen = RGB(0, 0, 0);
}

CPractice6_2View::~CPractice6_2View()
{
	
}

BOOL CPractice6_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPractice6_2View 그리기

void CPractice6_2View::OnDraw(CDC* /*pDC*/)
{
	CPractice6_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPractice6_2View 인쇄


void CPractice6_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice6_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPractice6_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPractice6_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CPractice6_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice6_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice6_2View 진단

#ifdef _DEBUG
void CPractice6_2View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice6_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice6_2Doc* CPractice6_2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice6_2Doc)));
	return (CPractice6_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice6_2View 메시지 처리기


void CPractice6_2View::OnPenSize()
{
	CPenSizeDlg* pdlgPen = new CPenSizeDlg;

	if (pdlgPen->DoModal() == IDOK)
		m_nPenSize = pdlgPen->m_nPenSize;
}


void CPractice6_2View::OnEraserSize()
{
	CEraserSizeDlg* pdlgEraser = new CEraserSizeDlg;

	if (pdlgEraser->DoModal() == IDOK)
		m_nEraserSize = pdlgEraser->m_nEraserSize;
}


void CPractice6_2View::OnPenColor()
{
	CColorDialog colorDlg;

	if (colorDlg.DoModal() == IDOK)
		m_colorPen = colorDlg.GetColor();
}


void CPractice6_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	m_ptPrev = point;
	HCURSOR hCursor = AfxGetApp()->LoadCursorW(IDC_CURSOR_PEN);
	SetCursor(hCursor);

	CView::OnLButtonDown(nFlags, point);
}


void CPractice6_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	m_ptPrev = point;
	HCURSOR hCursor = AfxGetApp()->LoadCursorW(IDC_CURSOR_ERASER);
	SetCursor(hCursor);

	CView::OnRButtonDown(nFlags, point);
}


void CPractice6_2View::OnMouseMove(UINT nFlags, CPoint point)
{
	CClientDC dc(this);
	Graphics graphics(dc);

	Gdiplus::Color color;
	color.SetFromCOLORREF(m_colorPen);

	if (nFlags == MK_LBUTTON)
	{
		HCURSOR hCursor = AfxGetApp()->LoadCursorW(IDC_CURSOR_PEN);
		SetCursor(hCursor);
		Pen pen(Color(color), m_nPenSize);
		graphics.DrawLine(&pen, m_ptPrev.x, m_ptPrev.y, point.x, point.y);
		m_ptPrev = point;
	}

	if (nFlags == MK_RBUTTON)
	{
		HCURSOR hCursor = AfxGetApp()->LoadCursorW(IDC_CURSOR_ERASER);
		SetCursor(hCursor);
		Pen pen(Color(255, 255, 255), m_nEraserSize);
		graphics.DrawLine(&pen, m_ptPrev.x, m_ptPrev.y, point.x, point.y);
		m_ptPrev = point;
	}

	CView::OnMouseMove(nFlags, point);
}
