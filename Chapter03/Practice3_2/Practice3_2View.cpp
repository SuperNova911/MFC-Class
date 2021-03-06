
// Practice3_2View.cpp: CPractice32View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Practice3_2.h"
#endif

#include "Practice3_2Doc.h"
#include "Practice3_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice32View

IMPLEMENT_DYNCREATE(CPractice32View, CView)

BEGIN_MESSAGE_MAP(CPractice32View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CPractice32View 생성/소멸

CPractice32View::CPractice32View()
	:m_bTimerRun(false)
	,m_bTimerMode(true)
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CPractice32View::~CPractice32View()
{
}

BOOL CPractice32View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CPractice32View 그리기

void CPractice32View::OnDraw(CDC* pDC)
{
	CPractice32Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	CRect rect;
	GetClientRect(rect);

	pDC->DrawText(m_strTimer, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
}


// CPractice32View 인쇄

BOOL CPractice32View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CPractice32View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CPractice32View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CPractice32View 진단

#ifdef _DEBUG
void CPractice32View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice32View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice32Doc* CPractice32View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice32Doc)));
	return (CPractice32Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice32View 메시지 처리기


void CPractice32View::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bTimerMode)
	{
		if (AfxMessageBox(TEXT("시, 분, 초 형태로 표시하겠습니까?"), MB_YESNO, MB_ICONQUESTION) == IDYES)
			m_bTimerMode = false;
	}
	else
		if (AfxMessageBox(TEXT("년, 월, 일, 시, 분, 초 형태로 표시하겠습니까?"), MB_YESNO, MB_ICONQUESTION) == IDYES)
			m_bTimerMode = true;

	CView::OnLButtonDown(nFlags, point);
}


void CPractice32View::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_bTimerRun)
	{
		if (AfxMessageBox(TEXT("정말로 디지털시계 동작을 멈추시겠습니까?"), MB_YESNO, MB_ICONQUESTION) == IDYES)
		{
			m_bTimerRun = false;
			KillTimer(911);
		}
	}
	else
		if (AfxMessageBox(TEXT("디지털시계를 동작시키겠습니까?"), MB_YESNO, MB_ICONQUESTION) == IDYES)
		{
			m_bTimerRun = true;
			SetTimer(911, 1000, NULL);
		}

	CView::OnRButtonDown(nFlags, point);
}


int CPractice32View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	SetTimer(911, 1000, NULL);
	m_bTimerRun = true;

	return 0;
}


void CPractice32View::OnDestroy()
{
	CView::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_bTimerRun)
		KillTimer(911);
}


void CPractice32View::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	int hour;
	CString str;
	CTime timer;
	timer = CTime::GetCurrentTime();

	if (m_bTimerMode)
	{
		m_strTimer.Format(_T("현재는 %d년 %d월 %d일 %d시 %d분 %d초"),
			timer.GetYear(), timer.GetMonth(), timer.GetDay(), timer.GetHour(), timer.GetMinute(), timer.GetSecond());
	}
	else
	{
		hour = timer.GetHour();

		if (hour > 12)
		{
			hour -= 12;
			str = _T("PM");
		}
		else
		{
			str = _T("AM");
		}

		m_strTimer.Format(_T("지금은 %s %d시 %d분 %d초"),
			str, hour, timer.GetMinute(), timer.GetSecond());
	}

	Invalidate();

	CView::OnTimer(nIDEvent);
}
