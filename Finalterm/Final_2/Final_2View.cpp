
// Final_2View.cpp : CFinal_2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Final_2.h"
#endif

#include "Final_2Doc.h"
#include "Final_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFinal_2View

IMPLEMENT_DYNCREATE(CFinal_2View, CView)

BEGIN_MESSAGE_MAP(CFinal_2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFinal_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_LINE, &CFinal_2View::OnLine)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CFinal_2View 생성/소멸

CFinal_2View::CFinal_2View()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_bDrawing = false;
	m_bDrawMode = false;
	m_nCount = 0;
}

CFinal_2View::~CFinal_2View()
{
}

BOOL CFinal_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CFinal_2View 그리기

void CFinal_2View::OnDraw(CDC* /*pDC*/)
{
	CFinal_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CFinal_2View 인쇄


void CFinal_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFinal_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CFinal_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CFinal_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CFinal_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFinal_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFinal_2View 진단

#ifdef _DEBUG
void CFinal_2View::AssertValid() const
{
	CView::AssertValid();
}

void CFinal_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFinal_2Doc* CFinal_2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFinal_2Doc)));
	return (CFinal_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CFinal_2View 메시지 처리기


void CFinal_2View::OnLine()
{
	m_bDrawMode = true;
	m_bDrawing = true;
}


void CFinal_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_bDrawing == true)
	{
		m_ptPrev = point;
		m_bDrawing = false;
	}
	else
	{
		m_bDrawing = false;

		if (m_bDrawMode)
		{
			m_ptList[m_nCount][0] = m_ptPrev;
			m_ptList[m_nCount][1] = point;
			m_nCount++;

			CClientDC dc(this);
			Graphics graphics(dc);

			Pen pen(Color(0,0,0), 2);
			graphics.DrawLine(&pen, m_ptPrev.x, m_ptPrev.y, point.x, point.y);
		}
		m_bDrawMode = false;

	}

	CView::OnLButtonDown(nFlags, point);
}
