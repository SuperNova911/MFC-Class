// LeftView.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Exercise.h"
#include "LeftView.h"
#include "MainFrm.h"
#include "ExerciseDoc.h"
#include "ExerciseView.h"


// CLeftView

IMPLEMENT_DYNCREATE(CLeftView, CFormView)

CLeftView::CLeftView()
	: CFormView(IDD_FORMVIEW)
	, m_strNode(_T(""))
	, m_strSelectedNode(_T(""))
{
	m_bChecked = true;
}

CLeftView::~CLeftView()
{
}

void CLeftView::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//  DDX_Text(pDX, IDC_EDIT_NODE, m_strNode);
	//  DDX_Control(pDX, IDC_EDIT_SELECTED_NODE, m_edSelectedNode);
	DDX_Text(pDX, IDC_EDIT_NODE, m_strNode);
	DDX_Text(pDX, IDC_EDIT_SELECTED_NODE, m_strSelectedNode);
}

BEGIN_MESSAGE_MAP(CLeftView, CFormView)
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CLeftView::OnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CLeftView::OnClickedButtonModify)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CLeftView::OnClickedButtonDelete)
	ON_BN_CLICKED(IDC_CHECK_EXPAND, &CLeftView::OnClickedCheckExpand)
END_MESSAGE_MAP()


// CLeftView �����Դϴ�.

#ifdef _DEBUG
void CLeftView::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftView::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftView �޽��� ó�����Դϴ�.


void CLeftView::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();
	((CButton*)GetDlgItem(IDC_CHECK_EXPAND))->SetCheck(true);
	m_strSelectedNode = TEXT("��Ʈ ���");
}


void CLeftView::OnClickedButtonInsert()
{
	CExerciseView* pView = (CExerciseView*)this->GetNextWindow();

	UpdateData(true);

	if (m_strNode.IsEmpty())
		AfxMessageBox(TEXT("�Է� ����� �ؽ�Ʈ�� �Է��ϼ���."));
	else
	{
		pView->GetTreeCtrl().InsertItem(m_strNode, pView->m_hSelectedNode, TVI_LAST);
		pView->GetTreeCtrl().Expand(pView->m_hSelectedNode, TVE_EXPAND);

		m_bChecked = true;
		((CButton*)GetDlgItem(IDC_CHECK_EXPAND))->SetCheck(true);
	}
	
	m_strNode.Empty();

	UpdateData(false);
}


void CLeftView::OnClickedButtonModify()
{
	CExerciseView* pView = (CExerciseView*)this->GetNextWindow();

	UpdateData(true);

	if (m_strNode.IsEmpty())
		AfxMessageBox(TEXT("���� ����� �ؽ�Ʈ�� �Է��ϼ���."));
	else
	{
		if (pView->m_hSelectedNode == pView->m_hRoot)
			AfxMessageBox(TEXT("��Ʈ ���� �����ؼ��� �� �˴ϴ�."));
		else
		{
			pView->GetTreeCtrl().SetItemText(pView->m_hSelectedNode, m_strNode);
			m_strSelectedNode = m_strNode;
		}
	}

	m_strNode.Empty();

	UpdateData(false);
}


void CLeftView::OnClickedButtonDelete()
{
	CExerciseView* pView = (CExerciseView*)this->GetNextWindow();

	if (pView->m_hSelectedNode == pView->m_hRoot)
		AfxMessageBox(TEXT("��Ʈ ���� �����ؼ��� �� �˴ϴ�."));
	else
	{
		if (AfxMessageBox(TEXT("���� �����Ͻðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			pView->GetTreeCtrl().DeleteItem(pView->m_hSelectedNode);
		}
	}
}


void CLeftView::OnClickedCheckExpand()
{
	CExerciseView* pView = (CExerciseView*)this->GetNextWindow();

	m_bChecked = !m_bChecked;

	if (m_bChecked)
		pView->GetTreeCtrl().Expand(pView->m_hSelectedNode, TVE_EXPAND);
	else
		pView->GetTreeCtrl().Expand(pView->m_hSelectedNode, TVE_COLLAPSE);
}
