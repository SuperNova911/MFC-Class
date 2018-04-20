// HobbyCtrl.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "Exercise1.h"
#include "HobbyCtrl.h"
#include "afxdialogex.h"
#include "MainFrm.h"
#include "Exercise1View.h"


// CHobbyCtrl ��ȭ �����Դϴ�.

IMPLEMENT_DYNAMIC(CHobbyCtrl, CDialogEx)

CHobbyCtrl::CHobbyCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG_ADD, pParent)
	, m_strName(_T(""))
{

}

CHobbyCtrl::~CHobbyCtrl()
{
}

void CHobbyCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_HOBBY, m_listHobby);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
	DDX_Control(pDX, IDC_COMBO_SEX, m_cbSex);
}


BEGIN_MESSAGE_MAP(CHobbyCtrl, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK_FISHING, &CHobbyCtrl::OnClickedCheckFishing)
	ON_BN_CLICKED(IDC_CHECK_READING, &CHobbyCtrl::OnClickedCheckReading)
	ON_BN_CLICKED(IDC_CHECK_SPORTS, &CHobbyCtrl::OnClickedCheckSports)
	ON_COMMAND(IDC_RADIO_MALE, &CHobbyCtrl::OnRadioMale)
	ON_COMMAND(IDC_RADIO_FEMALE, &CHobbyCtrl::OnRadioFemale)
	ON_BN_CLICKED(IDC_BUTTON_RESULT, &CHobbyCtrl::OnClickedButtonResult)
	ON_CBN_SELCHANGE(IDC_COMBO_SEX, &CHobbyCtrl::OnSelchangeComboSex)
	ON_LBN_SELCHANGE(IDC_LIST_HOBBY, &CHobbyCtrl::OnSelchangeListHobby)
END_MESSAGE_MAP()


// CHobbyCtrl �޽��� ó�����Դϴ�.


BOOL CHobbyCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_listHobby.AddString(TEXT("����"));
	m_listHobby.AddString(TEXT("����"));
	m_listHobby.AddString(TEXT("�"));
	m_cbSex.SetCurSel(0);
	((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(true);
	((CButton*)GetDlgItem(IDC_RADIO_FEMALE))->SetCheck(false);

	m_bSex = true;
	for (int i = 0; i < m_listHobby.GetCount(); i++)
		m_bChecked[i] = false;

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CHobbyCtrl::OnClickedCheckReading()
{
	if (m_bChecked[0] == true)
	{
		m_bChecked[0] = false;
		m_listHobby.SetSel(0, false);
	}
	else
	{
		m_bChecked[0] = true;
		m_listHobby.SetSel(0, true);
	}
}


void CHobbyCtrl::OnClickedCheckFishing()
{
	if (m_bChecked[1] == true)
	{
		m_bChecked[1] = false;
		m_listHobby.SetSel(1, false);
	}
	else
	{
		m_bChecked[1] = true;
		m_listHobby.SetSel(1, true);
	}
}


void CHobbyCtrl::OnClickedCheckSports()
{
	if (m_bChecked[2] == true)
	{
		m_bChecked[2] = false;
		m_listHobby.SetSel(2, false);

	}
	else
	{
		m_bChecked[2] = true;
		m_listHobby.SetSel(2, true);
	}
}


void CHobbyCtrl::OnRadioMale()
{
	m_bSex = true;

	m_cbSex.SetCurSel(0);
}


void CHobbyCtrl::OnRadioFemale()
{
	m_bSex = false;

	m_cbSex.SetCurSel(1);
}


void CHobbyCtrl::OnSelchangeComboSex()
{
	int index;

	index = m_cbSex.GetCurSel();

	if (index != CB_ERR)
	{
		switch (index)
		{
		case 0:
			m_bChecked[0] = true;
			m_bChecked[1] = false;
			((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(true);
			((CButton*)GetDlgItem(IDC_RADIO_FEMALE))->SetCheck(false);
			break;

		case 1:
			m_bChecked[0] = false;
			m_bChecked[1] = true;
			((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(false);
			((CButton*)GetDlgItem(IDC_RADIO_FEMALE))->SetCheck(true);
			break;
		}
	}
	else
		AfxMessageBox(TEXT("�߸��� �޺��ڽ� �� ����"));
}


void CHobbyCtrl::OnSelchangeListHobby()
{
	int index;

	index = m_listHobby.GetCurSel();

	if (index != LB_ERR)
	{
		switch (index)
		{
		case 0:
			if (m_bChecked[0])
			{
				m_bChecked[0] = false;
				((CButton*)GetDlgItem(IDC_CHECK_READING))->SetCheck(false);
			}
			else
			{
				m_bChecked[0] = true;
				((CButton*)GetDlgItem(IDC_CHECK_READING))->SetCheck(true);
			}
			break;

		case 1:
			if (m_bChecked[1])
			{
				m_bChecked[1] = false;
				((CButton*)GetDlgItem(IDC_CHECK_FISHING))->SetCheck(false);
			}
			else
			{
				m_bChecked[1] = true;
				((CButton*)GetDlgItem(IDC_CHECK_FISHING))->SetCheck(true);
			}
			break;

		case 2:
			if (m_bChecked[2])
			{
				m_bChecked[2] = false;
				((CButton*)GetDlgItem(IDC_CHECK_SPORTS))->SetCheck(false);
			}
			else
			{
				m_bChecked[2] = true;
				((CButton*)GetDlgItem(IDC_CHECK_SPORTS))->SetCheck(true);
			}
			break;
		}
	}
	else
		AfxMessageBox(TEXT("�߸��� ����Ʈ�ڽ� �� ����"));
}


void CHobbyCtrl::OnClickedButtonResult()
{
	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CExercise1View* pView = (CExercise1View*)pFrame->GetActiveView();

	// �ʱ�ȭ
	pView->m_strName.Empty();
	pView->m_strSex.Empty();
	pView->m_strHobby.Empty();

	// �̸�
	GetDlgItemText(IDC_EDIT_NAME, pView->m_strName);
	if (pView->m_strName.IsEmpty())
	{
		AfxMessageBox(TEXT("�̸��� �Է��ϼ���"));
		return;
	}

	// ����
	int index = m_cbSex.GetCurSel();

	if (index != CB_ERR)
			m_cbSex.GetLBText(index, pView->m_strSex);
	else
	{
		AfxMessageBox(TEXT("�߸��� �޺��ڽ� �� ����"));
		return;
	}
	
	// ���
	if (m_bChecked[0])
		pView->m_strHobby += TEXT("���� ");
	if (m_bChecked[1])
		pView->m_strHobby += TEXT("���� ");
	if (m_bChecked[2])
		pView->m_strHobby += TEXT("� ");
	
	pView->Invalidate();
}
