
// Practice12_1View.cpp : CPractice12_1View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Practice12_1.h"
#endif

#include "Practice12_1Doc.h"
#include "Practice12_1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CPractice12_1View

IMPLEMENT_DYNCREATE(CPractice12_1View, CFormView)

BEGIN_MESSAGE_MAP(CPractice12_1View, CFormView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_FIRST_RECORD, &CPractice12_1View::OnFirstRecord)
	ON_COMMAND(ID_PREV_RECORD, &CPractice12_1View::OnPrevRecord)
	ON_COMMAND(ID_NEXT_RECORD, &CPractice12_1View::OnNextRecord)
	ON_COMMAND(ID_LAST_RECORD, &CPractice12_1View::OnLastRecord)
END_MESSAGE_MAP()

// CPractice12_1View ����/�Ҹ�

CPractice12_1View::CPractice12_1View()
	: CFormView(IDD_PRACTICE12_1_FORM)
	, m_strBook(_T(""))
	, m_strCheckOut(_T(""))
	, m_strHakbun(_T(""))
	, m_strMajor(_T(""))
	, m_strName(_T(""))
	, m_strReturn(_T(""))
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

	m_nTotal = 0;
	m_nMoveCount = 0;
}

CPractice12_1View::~CPractice12_1View()
{
}

void CPractice12_1View::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_BOOK, m_strBook);
	DDX_Text(pDX, IDC_EDIT_CHECKOUT, m_strCheckOut);
	DDX_Text(pDX, IDC_EDIT_HAKBUN, m_strHakbun);
	DDX_Text(pDX, IDC_EDIT_MAJOR, m_strMajor);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Text(pDX, IDC_EDIT_RETURN, m_strReturn);
}

BOOL CPractice12_1View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CFormView::PreCreateWindow(cs);
}

void CPractice12_1View::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	GetParentFrame()->RecalcLayout();
	ResizeParentToFit();

	CString strQuery;
	strQuery.Format(TEXT("SELECT * FROM card"));
	m_command.Close();

	if (m_dbSet.Query(strQuery, &m_command))
	{
		m_nTotal = 0;

		while (m_command.MoveNext() == S_OK)
		{
			m_nTotal++;
		}

		m_nMoveCount = 1;
		GetDataFromDb(MOVE_FIRST_RECORD);
		m_bMoveRecord = true;
	}
}

void CPractice12_1View::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CPractice12_1View::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CPractice12_1View ����

#ifdef _DEBUG
void CPractice12_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CPractice12_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPractice12_1Doc* CPractice12_1View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice12_1Doc)));
	return (CPractice12_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice12_1View �޽��� ó����


void CPractice12_1View::OnFirstRecord()
{
	CString strQuery;
	strQuery.Format(TEXT("SELECT * FROM card"));
	m_command.Close();

	if (m_dbSet.Query(strQuery, &m_command))
	{
		m_nTotal = 0;

		while (m_command.MoveNext() == S_OK)
		{
			m_nTotal++;
		}

		m_nMoveCount = 1;
		GetDataFromDb(MOVE_FIRST_RECORD);
	}
	m_bMoveRecord = true;

	UpdateData(false);
}


void CPractice12_1View::OnPrevRecord()
{
	if (!m_bMoveRecord)
		return;
	else
	{
		if (m_nMoveCount == 1)
			return;

		m_nMoveCount--;
		GetDataFromDb(MOVE_PREV_RECORD);
	}

	UpdateData(false);
}


void CPractice12_1View::OnNextRecord()
{
	if (!m_bMoveRecord)
		return;
	else
	{
		if (m_nMoveCount == m_nTotal)
			return;

		m_nMoveCount++;
		GetDataFromDb(MOVE_NEXT_RECORD);
	}

	UpdateData(false);
}


void CPractice12_1View::OnLastRecord()
{
	CString strQuery;
	strQuery.Format(TEXT("SELECT * FROM card"));
	m_command.Close();

	if (m_dbSet.Query(strQuery, &m_command))
	{
		m_nTotal = 0;

		while (m_command.MoveNext() == S_OK)
		{
			m_nTotal++;
		}

		m_nMoveCount = m_nTotal;
		GetDataFromDb(MOVE_LAST_RECORD);
	}
	m_bMoveRecord = true;

	UpdateData(false);
}


void CPractice12_1View::GetDataFromDb(int nMoveRecord)
{
	switch (nMoveRecord)
	{
	case MOVE_FIRST_RECORD:
		m_command.MoveFirst();
		break;

	case MOVE_PREV_RECORD:
		m_command.MovePrev();
		break;

	case MOVE_NEXT_RECORD:
		m_command.MoveNext();
		break;

	case MOVE_LAST_RECORD:
		m_command.MoveLast();
		break;
	}

	m_strMajor = m_command.GetString(2);
	m_strHakbun = m_command.GetString(3);
	m_strName = m_command.GetString(4);
	m_strBook = m_command.GetString(5);
	m_strCheckOut = m_command.GetString(6);
	m_strReturn = m_command.GetString(7);

	UpdateData(false);
}
