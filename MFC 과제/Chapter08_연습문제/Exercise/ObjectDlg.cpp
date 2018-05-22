// ObjectDlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Exercise.h"
#include "ObjectDlg.h"
#include "afxdialogex.h"
#include "ExerciseDlg.h"


// CObjectDlg ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CObjectDlg, CDialogEx)

CObjectDlg::CObjectDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_OBJECT, pParent)
{

	m_nSelObject = 0;
}

CObjectDlg::~CObjectDlg()
{
}

void CObjectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CObjectDlg, CDialogEx)
	ON_COMMAND(IDC_RADIO_RECT, &CObjectDlg::OnRadioRect)
	ON_COMMAND(IDC_RADIO_CIRCLE, &CObjectDlg::OnRadioCircle)
END_MESSAGE_MAP()


// CObjectDlg �޽��� ó�����Դϴ�.


BOOL CObjectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	
	// 1: �簢��, 2:��
	// �⺻��: 2
	m_nSelObject = 2;
	((CButton*)GetDlgItem(IDC_RADIO_CIRCLE))->SetCheck(true);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


// �簢�� ����
void CObjectDlg::OnRadioRect()
{
	CExerciseDlg* pMainDlg = (CExerciseDlg*)AfxGetMainWnd();

	m_nSelObject = 1;

	// �׸��� ������Ʈ
	pMainDlg->UpdateDrawing();
}

// �� ����
void CObjectDlg::OnRadioCircle()
{
	CExerciseDlg* pMainDlg = (CExerciseDlg*)AfxGetMainWnd();

	m_nSelObject = 2;
	
	// �׸��� ������Ʈ
	pMainDlg->UpdateDrawing();
}
