
// ExerciseView.cpp : CExerciseView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CExerciseView 생성/소멸

CExerciseView::CExerciseView()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

CExerciseView::~CExerciseView()
{
}

BOOL CExerciseView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CTreeView::PreCreateWindow(cs);
}

void CExerciseView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();
	CTreeCtrl& TreeCtrl = GetTreeCtrl();

	TreeCtrl.ModifyStyle(0, TVS_HASLINES | TVS_HASBUTTONS | TVS_LINESATROOT | TVS_SHOWSELALWAYS);
	

	m_hRoot = TreeCtrl.InsertItem(TEXT("루트 노드"), 0, TVI_LAST);
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


// CExerciseView 진단

#ifdef _DEBUG
void CExerciseView::AssertValid() const
{
	CTreeView::AssertValid();
}

void CExerciseView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}

CExerciseDoc* CExerciseView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CExerciseDoc)));
	return (CExerciseDoc*)m_pDocument;
}
#endif //_DEBUG


// CExerciseView 메시지 처리기


void CExerciseView::OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);

	CLeftView* pView = (CLeftView*)this->GetNextWindow(GW_HWNDPREV);

	m_hSelectedNode = pNMTreeView->itemNew.hItem;

	pView->SetDlgItemTextW(IDC_EDIT_SELECTED_NODE, GetTreeCtrl().GetItemText(m_hSelectedNode));

	UpdateData(false);

	*pResult = 0;
}
