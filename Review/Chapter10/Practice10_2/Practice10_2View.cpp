
// Practice10_2View.cpp : CPractice10_2View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Practice10_2.h"
#endif

#include "Practice10_2Doc.h"
#include "Practice10_2View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice10_2View

IMPLEMENT_DYNCREATE(CPractice10_2View, CView)

BEGIN_MESSAGE_MAP(CPractice10_2View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice10_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
//	ON_WM_MOUSEHOVER()
ON_WM_MOUSEMOVE()
ON_WM_LBUTTONDOWN()
ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CPractice10_2View 생성/소멸

CPractice10_2View::CPractice10_2View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_nCount = 0;
}

CPractice10_2View::~CPractice10_2View()
{
}

BOOL CPractice10_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPractice10_2View 그리기

void CPractice10_2View::OnDraw(CDC* pDC)
{
	CPractice10_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	if (m_nCount < 5)
	{
		pDC->TextOutW(m_ptFollow.x + 10, m_ptFollow.y + 10, pDoc->m_strDept);
		pDC->TextOutW(m_ptFollow.x + 10, m_ptFollow.y + 30, pDoc->m_strName);
		pDC->TextOutW(m_ptFollow.x + 10, m_ptFollow.y + 50, pDoc->m_strSex);
		pDC->TextOutW(m_ptFollow.x + 10, m_ptFollow.y + 70, pDoc->m_strHobby);
	}

	for (int i = 0; i < m_nCount; i++)
	{
		pDC->TextOutW(m_ptFixate[i].x + 10, m_ptFixate[i].y + 10, pDoc->m_strDept);
		pDC->TextOutW(m_ptFixate[i].x + 10, m_ptFixate[i].y + 30, pDoc->m_strName);
		pDC->TextOutW(m_ptFixate[i].x + 10, m_ptFixate[i].y + 50, pDoc->m_strSex);
		pDC->TextOutW(m_ptFixate[i].x + 10, m_ptFixate[i].y + 70, pDoc->m_strHobby);
	}
}


// CPractice10_2View 인쇄


void CPractice10_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice10_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPractice10_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPractice10_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}

void CPractice10_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice10_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	//theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice10_2View 진단

#ifdef _DEBUG
void CPractice10_2View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice10_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice10_2Doc* CPractice10_2View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice10_2Doc)));
	return (CPractice10_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice10_2View 메시지 처리기


void CPractice10_2View::OnMouseMove(UINT nFlags, CPoint point)
{
	m_ptFollow = point;

	Invalidate();

	CView::OnMouseMove(nFlags, point);
}


void CPractice10_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CPractice10_2Doc *pDoc = (CPractice10_2Doc*)pFrame->GetActiveDocument();

	if (!pDoc->m_strHobby.IsEmpty())
	{
		if (m_nCount < 5)
		{
			m_ptFixate[m_nCount] = point;
			m_nCount++;
		}
		else
			AfxMessageBox(TEXT("글자는 다섯 번 까지만 출력할 수 있습니다."));
	}
	
	Invalidate();

	CView::OnLButtonDown(nFlags, point);
}


void CPractice10_2View::OnRButtonDown(UINT nFlags, CPoint point)
{
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CPractice10_2Doc *pDoc = (CPractice10_2Doc*)pFrame->GetActiveDocument();

	if (!pDoc->m_strName.IsEmpty())
	{
		if (m_nCount > 0)
			m_nCount--;
		else
			if (AfxMessageBox(TEXT("출력 내용을 삭제하겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
			{
				pDoc->m_strName.Empty();
				pDoc->m_strDept.Empty();
				pDoc->m_strSex.Empty();
				pDoc->m_strHobby.Empty();
			}
	}
	else
		MessageBox(TEXT("삭제할 내용이 없습니다."));

	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}
