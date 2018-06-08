
// Practice12_1View.cpp : CPractice12_1View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CPractice12_1View 생성/소멸

CPractice12_1View::CPractice12_1View()
	: CFormView(IDD_PRACTICE12_1_FORM)
	, m_strBook(_T(""))
	, m_strCheckOut(_T(""))
	, m_strHakbun(_T(""))
	, m_strMajor(_T(""))
	, m_strName(_T(""))
	, m_strReturn(_T(""))
{
	// TODO: 여기에 생성 코드를 추가합니다.

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
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

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


// CPractice12_1View 진단

#ifdef _DEBUG
void CPractice12_1View::AssertValid() const
{
	CFormView::AssertValid();
}

void CPractice12_1View::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}

CPractice12_1Doc* CPractice12_1View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPractice12_1Doc)));
	return (CPractice12_1Doc*)m_pDocument;
}
#endif //_DEBUG


// CPractice12_1View 메시지 처리기


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
