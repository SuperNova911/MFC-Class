
// Test1View.cpp : CTest1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "Test1.h"
#endif

#include "Test1Doc.h"
#include "Test1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTest1View

IMPLEMENT_DYNCREATE(CTest1View, CView)

BEGIN_MESSAGE_MAP(CTest1View, CView)
	// 표준 인쇄 명령입니다.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTest1View 생성/소멸

CTest1View::CTest1View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

	m_strArray = _T("");
	//  m_nSum = 0;
	//  m_nAvg = 0;

	Sum();

	m_strSum = _T("");
	m_strAvg = _T("");
}

CTest1View::~CTest1View()
{
}

BOOL CTest1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// CTest1View 그리기

void CTest1View::OnDraw(CDC* pDC)
{
	CTest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
	pDC->TextOut(0, 0, m_strArray);
	pDC->TextOut(0, 15, m_strSum);
	pDC->TextOut(0, 30, m_strAvg);
}


// CTest1View 인쇄

BOOL CTest1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 기본적인 준비
	return DoPreparePrinting(pInfo);
}

void CTest1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄하기 전에 추가 초기화 작업을 추가합니다.
}

void CTest1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 인쇄 후 정리 작업을 추가합니다.
}


// CTest1View 진단

#ifdef _DEBUG
void CTest1View::AssertValid() const
{
	CView::AssertValid();
}

void CTest1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest1Doc* CTest1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest1Doc)));
	return (CTest1Doc*)m_pDocument;
}
#endif //_DEBUG


// CTest1View 메시지 처리기


void CTest1View::Sum(void)
{
	int count = 0;
	int sum = 0;
	int avg = 0;
	CString str;
	
	for (int i = 1; i <= 100; i++)
	{
		str.Format(TEXT("%d "), i);
		m_strArray += str;
		count ++;
		sum += i;
	}

	avg = sum / count;
	
	m_strSum.Format(TEXT("합:%d"), sum);
	m_strAvg.Format(TEXT("평균:%d"), avg);

	Invalidate();
}
