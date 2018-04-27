// PenSizeDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Practice6_2.h"
#include "PenSizeDlg.h"
#include "afxdialogex.h"

#include "MainFrm.h"
#include "Practice6_2Doc.h"
#include "Practice6_2View.h"


// CPenSizeDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CPenSizeDlg, CDialogEx)

CPenSizeDlg::CPenSizeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_PEN, pParent)
	, m_nPenSize(0)
{

}

CPenSizeDlg::~CPenSizeDlg()
{
}

void CPenSizeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_PEN, m_nPenSize);
	DDX_Control(pDX, IDC_SPIN_PEN, m_spinPen);
}


BEGIN_MESSAGE_MAP(CPenSizeDlg, CDialogEx)
END_MESSAGE_MAP()


// CPenSizeDlg �޽��� ó�����Դϴ�.


BOOL CPenSizeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CPractice6_2View *pView = (CPractice6_2View*)pFrame->GetActiveWindow();

	m_spinPen.SetRange(1, 10);
	m_nPenSize = pView->m_nPenSize;
	UpdateData(false);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}