
// 연습문제1View.cpp: C연습문제1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "연습문제1.h"
#endif

#include "연습문제1Doc.h"
#include "연습문제1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C연습문제1View

IMPLEMENT_DYNCREATE(C연습문제1View, CView)

BEGIN_MESSAGE_MAP(C연습문제1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C연습문제1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C연습문제1View 생성/소멸

C연습문제1View::C연습문제1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_strWindowSize = _T("");
	m_strOutput = _T("");
	m_strPointText = _T("");
}

C연습문제1View::~C연습문제1View()
{
}

BOOL C연습문제1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// C연습문제1View 그리기

void C연습문제1View::OnDraw(CDC* pDC)
{
	C연습문제1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// (10, 10)에 m_strWindowSize 출력
	pDC->TextOut(10, 10, m_strWindowSize);

	// 윈도우 클라이언트의 크기를 얻기
	CRect rect;
	GetClientRect(&rect);
	// rect영역 중앙에 m_strOutput 문자열 출력
	pDC->DrawText(m_strOutput, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	// 마우스의 좌표에 마우스의 좌표 값을 출력
	pDC->TextOut(m_ptMouseMove.x, m_ptMouseMove.y, m_strPointText);
}


// C연습문제1View 인쇄


void C연습문제1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C연습문제1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void C연습문제1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void C연습문제1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void C연습문제1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C연습문제1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C연습문제1View 진단

#ifdef _DEBUG
void C연습문제1View::AssertValid() const
{
	CView::AssertValid();
}

void C연습문제1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C연습문제1Doc* C연습문제1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C연습문제1Doc)));
	return (C연습문제1Doc*)m_pDocument;
}
#endif //_DEBUG


// C연습문제1View 메시지 처리기


// 윈도우 크기가 변경될 때
void C연습문제1View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// 윈도우 크기를 나타내는 문자열 생성
	m_strWindowSize.Format(TEXT("윈도우 크기는 넓이 %d, 높이 %d입니다."), cx, cy);
	
	// 화면 갱신
	Invalidate();
}


// 왼쪽 마우스 버튼이 눌렸을 때
void C연습문제1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// 마우스 드래그 중
	m_bDrag = true;

	// 문자열 생성
	m_strOutput = TEXT("왼쪽 마우스 버튼을 눌렀습니다.");

	// 화면 갱신
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


// 오른쪽 마우스 버튼이 눌렸을 때
void C연습문제1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// 문자열 생성
	m_strOutput = TEXT("오른쪽 마우스 버튼을 눌렀습니다.");

	// 화면 갱신
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


// 키보드가 눌렸을 때
void C연습문제1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// 문자열 생성
	m_strOutput = TEXT("키보드가 눌렸습니다.");

	// 화면 갱신
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


// 마우스가 움직일 때
void C연습문제1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// 마우스의 좌표를 m_ptMouseMove 변수에 대입
	m_ptMouseMove = point;
	// 마우스 좌표를 나타내는 문자열 생성
	m_strPointText.Format(TEXT("X:%d Y:%d"), point.x, point.y);

	// m_bDrag값이 참일때 마우스를 드래그 하고있다는 문자열 출력
	if (m_bDrag == true)
	{
		m_strOutput = TEXT("마우스를 드래그 하고 있습니다.");
	}
	else
	{
		m_strOutput = TEXT("마우스를 이동 중 입니다.");
	}

	// 화면 갱신
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}


// 왼쪽 마우스 버튼이 떼어졌을때
void C연습문제1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// 마우스 드래그 끝
	m_bDrag = false;

	CView::OnLButtonUp(nFlags, point);
}
