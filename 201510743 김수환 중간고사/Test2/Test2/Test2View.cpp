
// Test2View.cpp : CTest2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Test2.h"
#endif

#include "Test2Doc.h"
#include "Test2View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTest2View

IMPLEMENT_DYNCREATE(CTest2View, CView)

BEGIN_MESSAGE_MAP(CTest2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CTest2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_CIRCLE, &CTest2View::OnCircle)
	ON_COMMAND(ID_RECTANGLE, &CTest2View::OnRectangle)
	ON_UPDATE_COMMAND_UI(ID_CIRCLE, &CTest2View::OnUpdateCircle)
	ON_UPDATE_COMMAND_UI(ID_RECTANGLE, &CTest2View::OnUpdateRectangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CTest2View 생성/소멸

CTest2View::CTest2View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_nDrawmode = 0;
	m_bFirst = true;
	m_bLButtonDown = false;
	m_strPoint = _T("");
}

CTest2View::~CTest2View()
{
}

BOOL CTest2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTest2View 그리기

void CTest2View::OnDraw(CDC* pDC)
{
	CTest2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CPen pen(PS_SOLID, 1, RGB(0,0,0));
	CPen *oldpen = pDC->SelectObject(&pen);
	pDC->SetROP2(R2_COPYPEN);
	
	switch (m_nDrawmode)
	{
	case CIRCLE_MODE:
		pDC->Ellipse(m_ptStart.x, m_ptStart.y, m_ptPrev.x, m_ptPrev.y);
		m_strPoint.Format(TEXT("[%d,%d]"), m_ptPrev.x, m_ptPrev.y);
		pDC->TextOut(m_ptPrev.x, m_ptPrev.y, m_strPoint);
		break;

	case RECTANGLE_MODE:
		pDC->Rectangle(m_ptStart.x, m_ptStart.y, m_ptPrev.x, m_ptPrev.y);
		m_strPoint.Format(TEXT("[%d,%d]"), m_ptPrev.x, m_ptPrev.y);
		pDC->TextOut(m_ptPrev.x, m_ptPrev.y, m_strPoint);
		break;
	}
}


// CTest2View 인쇄


void CTest2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CTest2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTest2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTest2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CTest2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTest2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CTest2View 진단

#ifdef _DEBUG
void CTest2View::AssertValid() const
{
	CView::AssertValid();
}

void CTest2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest2Doc* CTest2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest2Doc)));
	return (CTest2Doc*)m_pDocument;
}
#endif //_DEBUG


// CTest2View 메시지 처리기


void CTest2View::OnMouseMove(UINT nFlags, CPoint point)
{
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();

	CString strPoint;
	strPoint.Format(TEXT("마우스 위치 x : %d, y : %d"), point.x, point.y);

	pFrame->m_wndStatusBar.SetPaneText(1, strPoint);


	CClientDC dc(this);
	

	CPen pen(PS_SOLID, 1, RGB(0,0,0));
	CPen *oldpen = dc.SelectObject(&pen);

	dc.SetROP2(R2_NOTXORPEN);

	switch (m_nDrawmode)
	{
	case CIRCLE_MODE:
		if (m_bLButtonDown)
		{
			dc.Ellipse(m_ptStart.x, m_ptStart.y, m_ptPrev.x, m_ptPrev.y);
			dc.Ellipse(m_ptStart.x, m_ptStart.y, point.x, point.y);
			m_ptPrev = point;
			break;
		}

	case RECTANGLE_MODE:
		if (m_bLButtonDown)
		{
			dc.Rectangle(m_ptStart.x, m_ptStart.y, m_ptPrev.x, m_ptPrev.y);
			dc.Rectangle(m_ptStart.x, m_ptStart.y, point.x, point.y);
			m_ptPrev = point;
			break;
		}
	}

	CView::OnMouseMove(nFlags, point);
}


void CTest2View::OnCircle()
{
	m_nDrawmode = CIRCLE_MODE;

	
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	pFrame->m_wndStatusBar.SetWindowText(TEXT("원을 그립니다."));
}


void CTest2View::OnRectangle()
{
	m_nDrawmode = RECTANGLE_MODE;

	
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	pFrame->m_wndStatusBar.SetWindowText(TEXT("사각형을 그립니다."));
}


void CTest2View::OnUpdateCircle(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_nDrawmode == CIRCLE_MODE ? 1 : 0);
}


void CTest2View::OnUpdateRectangle(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_nDrawmode == RECTANGLE_MODE ? 1 : 0);
}


void CTest2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_bFirst)
	{
		m_ptStart = m_ptPrev = 0;
		m_bLButtonDown = false;
		m_bFirst = true;

		Invalidate();
	}

	switch (m_nDrawmode)
	{
	case CIRCLE_MODE:
	case RECTANGLE_MODE:
		m_bLButtonDown = true;
		m_ptStart = m_ptPrev = point;
		m_bFirst = false;
		break;
	}
/*
	RECT rectClient;
	SetCapture();
	GetClientRect(&rectClient);
	ClientToScreen(&rectClient);
	::ClipCursor(&rectClient);*/


	CView::OnLButtonDown(nFlags, point);
}


void CTest2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_bLButtonDown)
		if (m_nDrawmode == CIRCLE_MODE || m_nDrawmode == RECTANGLE_MODE)
		{
			m_bLButtonDown = false;
			m_bFirst = true;
			ReleaseCapture();
			::ClipCursor(NULL);

			Invalidate();
		}

	CView::OnLButtonUp(nFlags, point);
}
