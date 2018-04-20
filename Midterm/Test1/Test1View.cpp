
// Test1View.cpp : CTest1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CTest1View ����/�Ҹ�

CTest1View::CTest1View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

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
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CTest1View �׸���

void CTest1View::OnDraw(CDC* pDC)
{
	CTest1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOut(0, 0, m_strArray);
	pDC->TextOut(0, 15, m_strSum);
	pDC->TextOut(0, 30, m_strAvg);
}


// CTest1View �μ�

BOOL CTest1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CTest1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CTest1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CTest1View ����

#ifdef _DEBUG
void CTest1View::AssertValid() const
{
	CView::AssertValid();
}

void CTest1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest1Doc* CTest1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest1Doc)));
	return (CTest1Doc*)m_pDocument;
}
#endif //_DEBUG


// CTest1View �޽��� ó����


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
	
	m_strSum.Format(TEXT("��:%d"), sum);
	m_strAvg.Format(TEXT("���:%d"), avg);

	Invalidate();
}
