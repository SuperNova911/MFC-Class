
// Practice5_4View.cpp : CPractice5_4View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Practice5_4.h"
#endif

#include "Practice5_4Doc.h"
#include "Practice5_4View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice5_4View

IMPLEMENT_DYNCREATE(CPractice5_4View, CView)

BEGIN_MESSAGE_MAP(CPractice5_4View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice5_4View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CPractice5_4View 생성/소멸

CPractice5_4View::CPractice5_4View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPractice5_4View::~CPractice5_4View()
{
}

BOOL CPractice5_4View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPractice5_4View 그리기

void CPractice5_4View::OnDraw(CDC* /*pDC*/)
{
	CPractice5_4Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// CPractice5_4View 인쇄


void CPractice5_4View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice5_4View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPractice5_4View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPractice5_4View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CPractice5_4View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice5_4View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice5_4View 진단

#ifdef _DEBUG
void CPractice5_4View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice5_4View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice5_4Doc* CPractice5_4View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice5_4Doc)));
	return (CPractice5_4Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice5_4View 메시지 처리기
