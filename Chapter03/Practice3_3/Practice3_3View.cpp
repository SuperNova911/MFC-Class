
// Practice3_3View.cpp: CPractice33View 클래스의 구현
//

#include "stdafx.h"
#include <cmath>
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Practice3_3.h"
#endif

#include "Practice3_3Doc.h"
#include "Practice3_3View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice33View

IMPLEMENT_DYNCREATE(CPractice33View, CView)

BEGIN_MESSAGE_MAP(CPractice33View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_SIZE()
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CPractice33View 생성/소멸

CPractice33View::CPractice33View()
	:m_strOutput(TEXT(""))
	, m_ptPos(0)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPractice33View::~CPractice33View()
{
}

BOOL CPractice33View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPractice33View 그리기

void CPractice33View::OnDraw(CDC* pDC)
{
	CPractice33Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->TextOutW(m_ptPos.x, m_ptPos.y, m_strOutput);
}


// CPractice33View 인쇄

BOOL CPractice33View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPractice33View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPractice33View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPractice33View 진단

#ifdef _DEBUG
void CPractice33View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice33View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice33Doc* CPractice33View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice33Doc)));
	return (CPractice33Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice33View 메시지 처리기


void CPractice33View::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int nCharIndex;
	nCharIndex = m_strOutput.GetLength();

	if (nChar == VK_BACK)
		m_strOutput.Delete(nCharIndex - 1, 1);
	else
		m_strOutput += (WCHAR)nChar;

	Invalidate();

	CView::OnChar(nChar, nRepCnt, nFlags);
}


void CPractice33View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	switch (nChar)
	{
	case VK_UP:
		m_ptPos.y--;
		break;
	case VK_DOWN:
		m_ptPos.y++;
		break;
	case VK_LEFT:
		m_ptPos.x--;
		break;
	case VK_RIGHT:
		m_ptPos.x++;
		break;
	case VK_PRIOR:
		m_ptPos.y -= 50;
		break;
	case VK_NEXT:
		m_ptPos.y += 50;
		break;
	case VK_HOME:
		m_ptPos = CPoint(0, 0);
		break;
	}

	if (m_ptPos.x < 0)
	{
		m_ptPos.x = 0;
		AfxMessageBox(TEXT("왼쪽으로 더 이상 이동할 수 없습니다."), MB_OK);
	}
	if (m_ptPos.y < 0)
	{
		m_ptPos.y = 0;
		AfxMessageBox(TEXT("위으로 더 이상 이동할 수 없습니다."), MB_OK);
	}
	if (m_ptClientSize.x < m_ptPos.x)
	{
		m_ptPos.x = m_ptClientSize.x;
		AfxMessageBox(TEXT("오른쪽으로 더 이상 이동할 수 없습니다."), MB_OK);
	}
	if (m_ptClientSize.y < m_ptPos.y)
	{
		m_ptPos.y = m_ptClientSize.y;
		AfxMessageBox(TEXT("아래쪽으로 더 이상 이동할 수 없습니다."), MB_OK);
	}

	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CPractice33View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	m_ptClientSize.x = cx;
	m_ptClientSize.y = cy;

	Invalidate();
}


void CPractice33View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (sqrt(pow(point.x - m_ptPos.x, 2) + pow(point.y - m_ptPos.y, 2)) <= 30)
	{
		m_bDrag = true;
		m_ptPos = point;
	}
	
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CPractice33View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_strOutput.IsEmpty())
		AfxMessageBox(TEXT("문자열을 입력하시오."));
	else
		if (AfxMessageBox(TEXT("문자를 모두 지우시겠습니까?"), MB_YESNO) == IDYES)
			m_strOutput.Empty();

	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


void CPractice33View::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_bDrag = false;

	CView::OnLButtonUp(nFlags, point);
}


void CPractice33View::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bDrag)
	{
		m_ptPos = point;
	}

	Invalidate();

	CView::OnMouseMove(nFlags, point);
}
