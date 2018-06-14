
// ExerciseView.cpp : CExerciseView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "Exercise.h"
#endif

#include "ExerciseDoc.h"
#include "ExerciseView.h"
#include "LeftView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CExerciseView

IMPLEMENT_DYNCREATE(CExerciseView, CTreeView)

BEGIN_MESSAGE_MAP(CExerciseView, CTreeView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_NOTIFY_REFLECT(TVN_SELCHANGED, &CExerciseView::OnTvnSelchanged)
END_MESSAGE_MAP()

// CExerciseView ����/�Ҹ�

CExerciseView::CExerciseView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CExerciseView::~CExerciseView()
{
}

BOOL CExerciseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CTreeView::PreCreateWindow(cs);
}

void CExerciseView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	CTreeCtrl& TreeCtrl = GetTreeCtrl();

	TreeCtrl.ModifyStyle(0, TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS);
	

	m_hRoot = TreeCtrl.InsertItem(TEXT("��Ʈ ���"), 0, TVI_LAST);
	m_hSelectedNode = m_hRoot;
}

void CExerciseView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CExerciseView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CExerciseView ����

#ifdef _DEBUG
void CExerciseView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CExerciseView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CExerciseDoc* CExerciseView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExerciseDoc)));
	return (CExerciseDoc*)m_pDocument;
}
#endif //_DEBUG


// CExerciseView �޽��� ó����


void CExerciseView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);

	CLeftView* pView = (CLeftView*)this->GetNextWindow(GW_HWNDPREV);

	m_hSelectedNode = pNMTreeView->itemNew.hItem;

	pView->SetDlgItemTextW(IDC_EDIT_SELECTED_NODE, GetTreeCtrl().GetItemText(m_hSelectedNode));

	UpdateData(false);

	*pResult = 0;
}
