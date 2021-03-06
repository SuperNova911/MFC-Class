
// Exercise1View.cpp: CExercise1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Exercise1.h"
#endif

#include "Exercise1Doc.h"
#include "Exercise1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExercise1View

IMPLEMENT_DYNCREATE(CExercise1View, CView)

BEGIN_MESSAGE_MAP(CExercise1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CExercise1View 생성/소멸

CExercise1View::CExercise1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	m_strStopWatch = TEXT("00: 00. 00");
}

CExercise1View::~CExercise1View()
{
}

BOOL CExercise1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CExercise1View 그리기

void CExercise1View::OnDraw(CDC* pDC)
{
	CExercise1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CFont big_font;
	big_font.CreateFontW(100, 0, 0, 0, FW_NORMAL, false, false, 0, 
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("굴림체"));

	CClientDC dc(this);
	dc.SelectObject(big_font);

	CRect rect;
	GetClientRect(&rect);
	dc.DrawText(m_strStopWatch, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);

	for (int i = 0; i < m_nCount; i++)
	{
		pDC->TextOutW(0, i * 15, m_strRecord[i]);
	}
}


// CExercise1View 인쇄

BOOL CExercise1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CExercise1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CExercise1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CExercise1View 진단

#ifdef _DEBUG
void CExercise1View::AssertValid() const
{
	CView::AssertValid();
}

void CExercise1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExercise1Doc* CExercise1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExercise1Doc)));
	return (CExercise1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExercise1View 메시지 처리기


void CExercise1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bStopWatchRun)
	{
		KillTimer(911);
		m_bStopWatchRun = false;
	}
	else
	{
		SetTimer(911, 10, NULL);
		m_bStopWatchRun = true;
	}

	CView::OnLButtonDown(nFlags, point);
}


void CExercise1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bStopWatchRun)
	{
		AfxMessageBox(TEXT("작동 중에는 스톱워치를 초기화시킬수 없습니다."));
	}
	else
	{
		if (AfxMessageBox(TEXT("스톱워치를 초기화 하시겠습니까?"), MB_YESNO, MB_ICONQUESTION) == IDYES)
		{
			m_nMinute = m_nSecond = m_nMSec = 0;
			m_strStopWatch.Format(TEXT("%02d: %02d. %02d"), m_nMinute, m_nSecond, m_nMSec);
			m_nCount = 0;
		}
	}

	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


void CExercise1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nChar == VK_SPACE && m_bStopWatchRun)
	{
		if (m_nCount >= 40)
			m_nCount = 0;
		m_strRecord[m_nCount] = m_strStopWatch;
		m_nCount++;
	}

	Invalidate();

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void CExercise1View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_nMSec++;

	if (m_nMSec >= 100)
	{
		m_nSecond++;
		m_nMSec -= 100;
	}
	if (m_nSecond >= 60)
	{
		m_nMinute++;
		m_nSecond -= 60;
	}

	m_strStopWatch.Format(TEXT("%02d: %02d. %02d"), m_nMinute, m_nSecond, m_nMSec);

	Invalidate();

	CView::OnTimer(nIDEvent);
}
