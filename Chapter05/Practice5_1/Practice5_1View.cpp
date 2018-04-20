
// Practice5_1View.cpp : CPractice5_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Practice5_1.h"
#endif

#include "Practice5_1Doc.h"
#include "Practice5_1View.h"
#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice5_1View

IMPLEMENT_DYNCREATE(CPractice5_1View, CView)

BEGIN_MESSAGE_MAP(CPractice5_1View, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CPractice5_1View::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_LINE, &CPractice5_1View::OnLine)
	ON_COMMAND(ID_ELLIPSE, &CPractice5_1View::OnEllipse)
	ON_COMMAND(ID_POLYGON, &CPractice5_1View::OnPolygon)
	ON_COMMAND(ID_LINE_COLOR, &CPractice5_1View::OnLineColor)
	ON_COMMAND(ID_FACE_COLOR, &CPractice5_1View::OnFaceColor)
	ON_COMMAND(ID_BDIAGONAL, &CPractice5_1View::OnBdiagonal)
	ON_COMMAND(ID_CROSS, &CPractice5_1View::OnCross)
	ON_COMMAND(ID_VERTICAL, &CPractice5_1View::OnVertical)
	ON_UPDATE_COMMAND_UI(ID_LINE, &CPractice5_1View::OnUpdateLine)
	ON_UPDATE_COMMAND_UI(ID_ELLIPSE, &CPractice5_1View::OnUpdateEllipse)
	ON_UPDATE_COMMAND_UI(ID_POLYGON, &CPractice5_1View::OnUpdatePolygon)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONDOWN()
	ON_COMMAND(ID_BEZIER, &CPractice5_1View::OnBezier)
	ON_UPDATE_COMMAND_UI(ID_BEZIER, &CPractice5_1View::OnUpdateBezier)
END_MESSAGE_MAP()

// CPractice5_1View ����/�Ҹ�

CPractice5_1View::CPractice5_1View()
	: m_nDrawMode(0)
	, m_nHatchStyle(0)
	, m_ptStart(0)
	, m_ptPrev(0)
	, m_bFirst(false)
	, m_bLButtonDown(false)
	, m_bContextMenu(false)
	, m_bHatch(false)
	, m_nCount(0)
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_nDrawMode = LINE_MODE;
	m_bContextMenu = true;
	m_bFirst = true;
	m_bLButtonDown = false;
	m_nCount = 0;
	for (int i = 0; i < 50; i++)
		m_ptData[i] = 0;
	m_bHatch = false;
	m_nHatchStyle = HS_CROSS;
	m_colorPen = RGB(0, 0, 0);
	m_colorBrush = RGB(255, 255, 255);
}

CPractice5_1View::~CPractice5_1View()
{
}

BOOL CPractice5_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CPractice5_1View �׸���

void CPractice5_1View::OnDraw(CDC* pDC)
{
	CPractice5_1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	CPen pen(PS_SOLID, 1, m_colorPen);
	CPen *oldpen = pDC->SelectObject(&pen);
	pDC->SetROP2(R2_COPYPEN);

	CClientDC dcBezier(this);
	CPen penBezier(PS_SOLID, 1, RGB(255, 0, 0));
	CPen *oldpenBezier = dcBezier.SelectObject(&penBezier);
	dcBezier.SetROP2(R2_COPYPEN);

	CBrush brush;
	if (m_nHatchStyle)
		brush.CreateHatchBrush(m_nHatchStyle, m_colorBrush);
	else
		brush.CreateSolidBrush(m_colorBrush);
	CBrush *oldbrush = pDC->SelectObject(&brush);

	switch (m_nDrawMode)
	{
	case LINE_MODE:
		pDC->MoveTo(m_ptStart);
		pDC->LineTo(m_ptPrev);
		break;

	case ELLIPSE_MODE:
		pDC->Ellipse(m_ptStart.x, m_ptStart.y, m_ptPrev.x, m_ptPrev.y);
		break;

	case POLYGON_MODE:
		pDC->Polygon(m_ptData, m_nCount);
		break;

	case BEZIER_MODE:
		pDC->Polyline(m_ptData, m_nCount);
		dcBezier.PolyBezier(m_ptData, m_nCount);
		
		pDC->SelectObject(GetStockObject(GRAY_BRUSH));
		for (int i = 0; i < m_nCount; i++)
		{
			pDC->Ellipse(m_ptData[i].x - 3, m_ptData[i].y - 3, m_ptData[i].x + 3, m_ptData[i].y + 3);
		}
	}

	pDC->SelectObject(oldpen);
	pDC->SelectObject(oldbrush);
	pen.DeleteObject();
	brush.DeleteObject();
}


// CPractice5_1View �μ�


void CPractice5_1View::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CPractice5_1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CPractice5_1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CPractice5_1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}

void CPractice5_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice5_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	if (m_bContextMenu)
		theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
	m_bContextMenu = true;
#endif
}


// CPractice5_1View ����

#ifdef _DEBUG
void CPractice5_1View::AssertValid() const
{
	CView::AssertValid();
}

void CPractice5_1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPractice5_1Doc* CPractice5_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice5_1Doc)));
	return (CPractice5_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice5_1View �޽��� ó����


void CPractice5_1View::OnLine()
{
	m_nDrawMode = LINE_MODE;

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	pFrame->m_wndStatusBar.SetWindowText(TEXT("���� �׸���"));
}


void CPractice5_1View::OnEllipse()
{
	m_nDrawMode = ELLIPSE_MODE;

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	pFrame->m_wndStatusBar.SetWindowText(TEXT("�� �׸���"));
}


void CPractice5_1View::OnPolygon()
{
	m_nDrawMode = POLYGON_MODE;

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	pFrame->m_wndStatusBar.SetWindowText(TEXT("�ٰ��� �׸���"));
}


void CPractice5_1View::OnBezier()
{
	m_nDrawMode = BEZIER_MODE;

	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	pFrame->m_wndStatusBar.SetWindowText(TEXT("������ � �׸���"));
}


void CPractice5_1View::OnLineColor()
{
	CColorDialog dlgColor;

	if (dlgColor.DoModal() == IDOK)
		m_colorPen = dlgColor.GetColor();

	Invalidate();
}


void CPractice5_1View::OnFaceColor()
{
	CColorDialog dlgColor;

	if (dlgColor.DoModal() == IDOK)
		m_colorBrush = dlgColor.GetColor();

	m_bHatch = false;

	Invalidate();
}


void CPractice5_1View::OnBdiagonal()
{
	m_nHatchStyle = HS_BDIAGONAL;
	m_bHatch = true;

	Invalidate();
}


void CPractice5_1View::OnCross()
{
	m_nHatchStyle = HS_CROSS;
	m_bHatch = true;

	Invalidate();
}


void CPractice5_1View::OnVertical()
{
	m_nHatchStyle = HS_VERTICAL;
	m_bHatch = true;

	Invalidate();
}


void CPractice5_1View::OnUpdateLine(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_nDrawMode == LINE_MODE ? 1 : 0);
}


void CPractice5_1View::OnUpdateEllipse(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_nDrawMode == ELLIPSE_MODE ? 1 : 0);
}


void CPractice5_1View::OnUpdatePolygon(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_nDrawMode == POLYGON_MODE ? 1 : 0);
}


void CPractice5_1View::OnUpdateBezier(CCmdUI *pCmdUI)
{
	pCmdUI->SetCheck(m_nDrawMode == BEZIER_MODE ? 1 : 0);
}


void CPractice5_1View::OnMouseMove(UINT nFlags, CPoint point)
{
	// ����ǥ����
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();

	CString strPoint;
	strPoint.Format(TEXT("���콺 ��ġ x : %d, y : %d"), point.x, point.y);

	pFrame->m_wndStatusBar.SetPaneText(1, strPoint);


	// �׸���
	CClientDC dc(this);
	
	// ��
	CPen pen(PS_SOLID, 1, m_colorPen);
	CPen *oldpen = dc.SelectObject(&pen);

	dc.SetROP2(R2_NOTXORPEN);

	// �귯��
	CBrush brush;
	if (m_bHatch)
		brush.CreateHatchBrush(m_nHatchStyle, m_colorBrush);
	else
		brush.CreateSolidBrush(m_colorBrush);
	CBrush *oldbrush = dc.SelectObject(&brush);

	
	switch (m_nDrawMode)
	{
	case LINE_MODE:
		if (m_bLButtonDown)
		{
			dc.MoveTo(m_ptStart);
			dc.LineTo(m_ptPrev);
			dc.MoveTo(m_ptStart);
			dc.LineTo(point);
			m_ptPrev = point;
		}
		break;
		
	case ELLIPSE_MODE:
		if (m_bLButtonDown)
		{
			dc.Ellipse(m_ptStart.x, m_ptStart.y, m_ptPrev.x, m_ptPrev.y);
			dc.Ellipse(m_ptStart.x, m_ptStart.y, point.x, point.y);
			m_ptPrev = point;
		}
		break;

	case POLYGON_MODE:
		if (m_bFirst == false)
		{
			dc.MoveTo(m_ptStart);
			dc.LineTo(m_ptPrev);
			dc.MoveTo(m_ptStart);
			dc.LineTo(point);
			m_ptPrev = point;
		}
		break;

	case BEZIER_MODE:
		if (m_bFirst == false)
		{
			dc.MoveTo(m_ptStart);
			dc.LineTo(m_ptPrev);
			dc.MoveTo(m_ptStart);
			dc.LineTo(point);
			m_ptPrev = point;

			dc.SelectObject(GetStockObject(GRAY_BRUSH));
			for (int i = 0; i < m_nCount; i++)
			{
				dc.Ellipse(m_ptData[i].x - 3, m_ptData[i].y - 3, m_ptData[i].x + 3, m_ptData[i].y + 3);
			}
		}
		break;
	}
	dc.SelectObject(oldpen);
	dc.SelectObject(oldbrush);
	pen.DeleteObject();
	brush.DeleteObject();


	CView::OnMouseMove(nFlags, point);
}


void CPractice5_1View::OnLButtonDown(UINT nFlags, CPoint point)
{
	if (m_bFirst)
	{
		m_ptStart = m_ptPrev = 0;
		m_bLButtonDown = false;
		m_bFirst = true;
		m_nCount = 0;
		for (int i = 0; i < 50; i++)
			m_ptData[i] = 0;

		Invalidate();
	}

	switch (m_nDrawMode)
	{
	case LINE_MODE:
	case ELLIPSE_MODE:
		m_bLButtonDown = true;
		m_ptStart = m_ptPrev = point;
		m_bFirst = false;
		break;
	case POLYGON_MODE:
		if (m_bFirst)
			m_bFirst = false;
		m_ptStart = m_ptPrev = point;
		m_ptData[m_nCount] = point;
		m_nCount++;
		break;
	case BEZIER_MODE:
		if (m_bFirst)
			m_bFirst = false;
		m_ptStart = m_ptPrev = point;
		m_ptData[m_nCount] = point;
		m_nCount++;
		break;
	}

	RECT rectClient;
	SetCapture();
	GetClientRect(&rectClient);
	ClientToScreen(&rectClient);
	::ClipCursor(&rectClient);


	CView::OnLButtonDown(nFlags, point);
}


void CPractice5_1View::OnLButtonUp(UINT nFlags, CPoint point)
{
	if (m_bLButtonDown)
		if (m_nDrawMode == LINE_MODE || m_nDrawMode == ELLIPSE_MODE)
		{
			m_bLButtonDown = false;
			m_bFirst = true;
			ReleaseCapture();
			::ClipCursor(NULL);

			Invalidate();
		}

	CView::OnLButtonUp(nFlags, point);
}


void CPractice5_1View::OnRButtonDown(UINT nFlags, CPoint point)
{
	if (m_nDrawMode == POLYGON_MODE)
		if (m_bFirst == false)
		{
			m_bContextMenu = false;
			m_ptData[m_nCount] = point;
			m_nCount++;
			m_bFirst = true;
			ReleaseCapture();
			::ClipCursor(NULL);

			Invalidate();
		}

	if (m_nDrawMode == BEZIER_MODE)
		if (m_bFirst == false)
		{
			m_bContextMenu = false;
			m_ptData[m_nCount] = point;
			m_nCount++;

			if ((m_nCount - 1) % 3 == 0 && (m_nCount - 1) / 3 > 0)
			{

				m_bFirst = true;
				ReleaseCapture();
				::ClipCursor(NULL);
				Invalidate();
			}
			else
				if (AfxMessageBox(TEXT("���� �� ���� <���� �� = ������ ���*3+1>"), MB_OK) == IDOK)
					m_ptStart = m_ptPrev = point;

		}

	CView::OnRButtonDown(nFlags, point);
}


