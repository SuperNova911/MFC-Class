
// 연습문제2View.cpp: C연습문제2View 클래스의 구현
//

#include "stdafx.h"
#include <math.h>
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "연습문제2.h"
#endif

#include "연습문제2Doc.h"
#include "연습문제2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// C연습문제2View

IMPLEMENT_DYNCREATE(C연습문제2View, CView)

BEGIN_MESSAGE_MAP(C연습문제2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &C연습문제2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// C연습문제2View 생성/소멸

C연습문제2View::C연습문제2View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_strOutput = _T("");
	m_bDrag = false;
}

C연습문제2View::~C연습문제2View()
{
}

BOOL C연습문제2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// C연습문제2View 그리기

void C연습문제2View::OnDraw(CDC* pDC)
{
	C연습문제2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// m_ptLocation에 m_strOutput문자열 출력
	pDC->TextOut(m_ptLocation.x, m_ptLocation.y, m_strOutput);
}


// C연습문제2View 인쇄


void C연습문제2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL C연습문제2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void C연습문제2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void C연습문제2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void C연습문제2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void C연습문제2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// C연습문제2View 진단

#ifdef _DEBUG
void C연습문제2View::AssertValid() const
{
	CView::AssertValid();
}

void C연습문제2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

C연습문제2Doc* C연습문제2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(C연습문제2Doc)));
	return (C연습문제2Doc*)m_pDocument;
}
#endif //_DEBUG


// C연습문제2View 메시지 처리기


// 키보드 입력
void C연습문제2View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// m_strOutput의 길이 얻기
	int nCharIndex;
	nCharIndex = m_strOutput.GetLength();

	// 키입력이 백스페이스
	if (nChar == VK_BACK)
		// 문자열의 마지막 문자 1개 지움
		m_strOutput.Delete(nCharIndex - 1, 1);
	else
		// 입력된 문자를 문자열에 추가
		m_strOutput += (WCHAR)nChar;

	// 화면 갱신
	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}


// 시스템키 입력
void C연습문제2View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	switch (nChar)
	{
	case VK_LEFT:	//왼쪽
		m_ptLocation.x--;
		break;
	case VK_RIGHT:	// 오른쪽
		m_ptLocation.x++;
		break;
	case VK_UP:		// 위쪽
		m_ptLocation.y--;
		break;
	case VK_DOWN:	// 아래쪽
		m_ptLocation.y++;
		break;
	case VK_PRIOR:	// PageUp
		m_ptLocation.y -= 50;
		break;
	case VK_NEXT:	// PageDown
		m_ptLocation.y += 50;
		break;
	case VK_HOME:	// Home
		m_ptLocation = CPoint(0, 0);	// 0, 0으로 초기화
		break;
	}

	// x좌표가 0보다 작으면 0으로 초기화
	if (m_ptLocation.x < 0)
	{
		m_ptLocation.x = 0;
		AfxMessageBox(TEXT("왼쪽으로 더 이상 이동할 수 없습니다."));
	}
	// y좌표가 0보다 작으면 0으로 초기화
	if (m_ptLocation.y < 0)
	{
		m_ptLocation.y = 0;
		AfxMessageBox(TEXT("위쪽으로 더 이상 이동할 수 없습니다."));
	}
	// x좌표가 윈도우 사이즈 x값 보다 크면 윈도우 사이즈 x값으로 초기화
	if (m_ptLocation.x > m_ptClientSize.x)
	{
		m_ptLocation.x = m_ptClientSize.x;
		AfxMessageBox(TEXT("오른쪽으로 더 이상 이동할 수 없습니다."));
	}
	// x좌표가 윈도우 사이즈 y값 보다 크면 윈도우 사이즈 y값으로 초기화
	if (m_ptLocation.y > m_ptClientSize.y)
	{
		m_ptLocation.y = m_ptClientSize.y;
		AfxMessageBox(TEXT("아래쪽으로 더 이상 이동할 수 없습니다."));
	}

	// 화면 갱신
	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


// 윈도우 클라이언트 크기 변경
void C연습문제2View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// m_ptClientSize에 윈도우 크기 할당
	m_ptClientSize.x = cx;
	m_ptClientSize.y = cy;

	// 화면 갱신
	Invalidate();
}


// 왼쪽 마우스가 떼어졌을 때
void C연습문제2View::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_bDrag == true)
	{
		// 드래그 끝
		m_bDrag = false;

		// m_ptLocation에 마우스 좌표값 입력
		m_ptLocation.x = point.x;
		m_ptLocation.y = point.y;
	}

	// 화면 갱신
	Invalidate();

	CView::OnLButtonUp(nFlags, point);
}



// 왼쪽 마우스가 눌렸을 때
void C연습문제2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// 문자열 m_ptLocation과 마우스 사이 거리가 30이하이면 드래그 시작
	if (sqrt(pow(m_ptLocation.x - point.x, 2) + pow(m_ptLocation.y - point.y, 2)) <= 30)
		m_bDrag = true;

	// m_ptLocation에 마우스 좌표값 입력
	m_ptLocation.x = point.x;
	m_ptLocation.y = point.y;

	// 화면 갱신
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


// 오른쪽 마우스가 눌렸을 때
void C연습문제2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// m_strOutput문자열이 비어있지 않으면
	if (m_strOutput.IsEmpty() == false)
	{
		// YES선택시 문자열 비우기
		if (AfxMessageBox(TEXT("문자를 모두 지우시겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			m_strOutput.Empty();
		}
	}
	else
	{
		AfxMessageBox(TEXT("문자열을 입력하시오."));
	}

	// 화면 갱신
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


// 마우스가 움직일 때
void C연습문제2View::OnMouseMove(UINT nFlags, CPoint point)
{
	// 드래그중이면 m_ptLocation에 마우스 좌표값 입력
	if (m_bDrag)
	{
		m_ptLocation.x = point.x;
		m_ptLocation.y = point.y;
	}

	// 화면 갱신
	Invalidate();

	CView::OnMouseMove(nFlags, point);
}