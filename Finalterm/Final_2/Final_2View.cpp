
// Final_2View.cpp : CFinal_2View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Final_2.h"
#endif

#include "Final_2Doc.h"
#include "Final_2View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFinal_2View

IMPLEMENT_DYNCREATE(CFinal_2View, CView)

BEGIN_MESSAGE_MAP(CFinal_2View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CFinal_2View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_LINE, &CFinal_2View::OnLine)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// CFinal_2View ����/�Ҹ�

CFinal_2View::CFinal_2View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	m_bDrawing = false;
	m_bDrawMode = false;
	m_nCount = 0;
}

CFinal_2View::~CFinal_2View()
{
}

BOOL CFinal_2View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CFinal_2View �׸���

void CFinal_2View::OnDraw(CDC* /*pDC*/)
{
	CFinal_2Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CFinal_2View �μ�


void CFinal_2View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CFinal_2View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CFinal_2View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CFinal_2View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CFinal_2View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CFinal_2View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CFinal_2View ����

#ifdef _DEBUG
void CFinal_2View::AssertValid() const
{
	CView::AssertValid();
}

void CFinal_2View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CFinal_2Doc* CFinal_2View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CFinal_2Doc)));
	return (CFinal_2Doc*)m_pDocument;
}
#endif //_DEBUG


// CFinal_2View �޽��� ó����


void CFinal_2View::OnLine()
{
	m_bDrawMode = true;
	m_bDrawing = true;
}


void CFinal_2View::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_bDrawing == true)
	{
		m_ptPrev = point;
		m_bDrawing = false;
	}
	else
	{
		m_bDrawing = false;

		if (m_bDrawMode)
		{
			m_ptList[m_nCount][0] = m_ptPrev;
			m_ptList[m_nCount][1] = point;
			m_nCount++;

			CClientDC dc(this);
			Graphics graphics(dc);

			Pen pen(Color(0,0,0), 2);
			graphics.DrawLine(&pen, m_ptPrev.x, m_ptPrev.y, point.x, point.y);
		}
		m_bDrawMode = false;

	}

	CView::OnLButtonDown(nFlags, point);
}
