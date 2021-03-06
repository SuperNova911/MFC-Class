
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
	ON_WM_LBUTTONDOWN()
	ON_WM_RBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// C연습문제1View 생성/소멸

C연습문제1View::C연습문제1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	// 변수값 초기화
	m_strStopWatch = TEXT("00: 00. 00");
	m_nCount = 0;
	m_nMinute = 0;
	m_nSecond = 0;
	m_nMSec = 0;
	m_bStopWatchRun = false;
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


	// 시간을 기록한 문자열들을 출력
	for (int i = 0; i < m_nCount; i++)
		pDC->TextOut(10, 10 + i * 20, m_strRecord[i]);

	// 굴림체, 크기가 100인 CFont객체 big_font 생성
	CFont big_font;
	big_font.CreateFontW(100, 0, 0, 0, FW_NORMAL, false, false, 0,
		DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH | FF_SWISS, TEXT("굴림체"));

	// 디바이스 컨텍스트 dc를 생성하고 big_font를 적용
	CClientDC dc(this);
	dc.SelectObject(big_font);

	// 윈도우 클라이언트의 크기를 얻기
	CRect rect;
	GetClientRect(&rect);

	// rect영역 중앙에 m_strStopWatch 문자열 출력
	dc.DrawText(m_strStopWatch, rect, DT_SINGLELINE | DT_CENTER | DT_VCENTER);
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
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
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



// 마우스 왼쪽 버튼이 눌렸을 때
void C연습문제1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_bStopWatchRun)
	{
		// 스톱워치 일시중지
		KillTimer(911);
		m_bStopWatchRun = false;
	}
	else
	{
		// 스톱워치 시작
		SetTimer(911, 10, NULL);
		m_bStopWatchRun = true; 
	}

	CView::OnLButtonDown(nFlags, point);
}


// 마우스 오른쪽 버튼이 눌렸을 때
void C연습문제1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	if (m_bStopWatchRun)
	{
		// 스톱워치 작동 중에는 초기화 불가
		AfxMessageBox(TEXT("작동 중에는 스톱워치를 초기화시킬수 없습니다."));
	}
	else
	{
		// 메시지 박스로 Y/N 선택
		if (AfxMessageBox(TEXT("스톱워치를 초기화 하시겠습니까?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			// 스톱워치 기록, 스톱워치 값 초기화
			m_nCount = 0;
			m_nMSec = m_nSecond = m_nMSec = 0;
			m_strStopWatch.Format(TEXT("%02d: %02d. %02d"), m_nMSec, m_nSecond, m_nMSec);
		}
	}

	// 화면 갱신
	Invalidate();

	CView::OnRButtonDown(nFlags, point);
}


// 시스템 키 이외의 키가 눌렸을 때
void C연습문제1View::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// 스톱워치가 작동중이면 함수 리턴
	if (m_bStopWatchRun == false)
		return;

	// 스페이스바가 눌렸는지 확인
	if (nChar == VK_SPACE)
	{
		// 스톱워치 기록 개수가 40이면 기록 초기화
		if (m_nCount >= 40)
			m_nCount = 0;

		// 현재 스톱워치 값을 기록하고 m_nCount증가
		m_strRecord[m_nCount] = m_strStopWatch;
		m_nCount++;
	}

	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


// 타이머의 지정한 시간이 경과했을 때
void C연습문제1View::OnTimer(UINT_PTR nIDEvent)
{
/*  10ms 단위로 호출 예상 (화면 갱신 딜레이 때문인지 실제로는 딜레이가 생기네요.)
	m_nMSec = 10ms
	m_nSecond = 1sec
	m_nMinute = 1min */

	// m_nMSec 1증가
	m_nMSec++;

	// m_nMSec값이 100이 되어 1초가 채워지면 m_nSecond값을 1증가, m_nMSec초기화
	if (m_nMSec >= 100)
	{
		m_nSecond++;
		m_nMSec -= 100;
	}

	// m_nSecond값이 60이 되어 1분이 채워지면 m_nMinute값을 1증가, m_nSecond초기화
	if (m_nSecond >= 60)
	{
		m_nMinute++;
		m_nSecond -= 60;
	}

	// 00: 00. 00 (분: 초. 밀리초)단위로 문자열 생성
	m_strStopWatch.Format(TEXT("%02d: %02d. %02d"), m_nMinute, m_nSecond, m_nMSec);

	// 화면 갱신
	Invalidate();

	CView::OnTimer(nIDEvent);
}
