
// Exercise1View.cpp : CExercise1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CExercise1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CExercise1View ����/�Ҹ�

CExercise1View::CExercise1View()
	: m_strOutput(_T(""))
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_strName = _T("");
	m_strSex = _T("");
	m_strHobby = _T("");
}

CExercise1View::~CExercise1View()
{
}

BOOL CExercise1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CExercise1View �׸���

void CExercise1View::OnDraw(CDC* pDC)
{
	CExercise1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	pDC->TextOut(20, 20, TEXT("�̸� : ") + m_strName);
	pDC->TextOut(20, 50, TEXT("���� : ") + m_strSex);
	pDC->TextOut(20, 80, TEXT("���� ������ ��� : ") + m_strHobby);
}


// CExercise1View �μ�


void CExercise1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CExercise1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CExercise1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CExercise1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CExercise1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExercise1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExercise1View ����

#ifdef _DEBUG
void CExercise1View::AssertValid() const
{
	CView::AssertValid();
}

void CExercise1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CExercise1Doc* CExercise1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExercise1Doc)));
	return (CExercise1Doc*)m_pDocument;
}
#endif //_DEBUG


// CExercise1View �޽��� ó����
