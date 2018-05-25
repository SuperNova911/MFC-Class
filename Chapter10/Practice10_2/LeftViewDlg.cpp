// LeftViewDlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Practice10_2.h"
#include "LeftViewDlg.h"
#include "MainFrm.h"
#include "Practice10_2Doc.h"


// CLeftViewDlg

IMPLEMENT_DYNCREATE(CLeftViewDlg, CFormView)

CLeftViewDlg::CLeftViewDlg()
	: CFormView(IDD_FORMVIEW)
	, m_strDept(_T(""))
	, m_strName(_T(""))
{

	m_nSex = 0;
}

CLeftViewDlg::~CLeftViewDlg()
{
}

void CLeftViewDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_CBString(pDX, IDC_COMBO_DEPT, m_strDept);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strName);
}

BEGIN_MESSAGE_MAP(CLeftViewDlg, CFormView)
	ON_COMMAND(IDC_RADIO_MALE, &CLeftViewDlg::OnRadioMale)
	ON_COMMAND(IDC_RADIO_FEMALE, &CLeftViewDlg::OnRadioFemale)
	ON_BN_CLICKED(IDC_CHECK_READING, &CLeftViewDlg::OnClickedCheckReading)
	ON_BN_CLICKED(IDC_CHECK_SPORTS, &CLeftViewDlg::OnClickedCheckSports)
	ON_BN_CLICKED(IDC_CHECK_FISHING, &CLeftViewDlg::OnClickedCheckFishing)
	ON_BN_CLICKED(IDC_BUTTON_OK, &CLeftViewDlg::OnClickedButtonOk)
END_MESSAGE_MAP()


// CLeftViewDlg 진단입니다.

#ifdef _DEBUG
void CLeftViewDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CLeftViewDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CLeftViewDlg 메시지 처리기입니다.


void CLeftViewDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	((CComboBox*)GetDlgItem(IDC_COMBO_DEPT))->SetCurSel(2);
	((CButton*)GetDlgItem(IDC_RADIO_MALE))->SetCheck(1);

	m_nSex = 0;
	m_bHobby[0] = m_bHobby[1] = m_bHobby[2] = false;
}


void CLeftViewDlg::OnRadioMale()
{
	m_nSex = 0;
}


void CLeftViewDlg::OnRadioFemale()
{
	m_nSex = 1;
}


void CLeftViewDlg::OnClickedCheckReading()
{
	m_bHobby[0] = !m_bHobby[0];
}


void CLeftViewDlg::OnClickedCheckSports()
{
	m_bHobby[1] = !m_bHobby[1];
}


void CLeftViewDlg::OnClickedCheckFishing()
{
	m_bHobby[2] = !m_bHobby[2];
}


void CLeftViewDlg::OnClickedButtonOk()
{
	UpdateData(true);

	CMainFrame *pFrame = (CMainFrame*)AfxGetMainWnd();
	CPractice10_2Doc *pDoc = (CPractice10_2Doc*)pFrame->GetActiveDocument();

	pDoc->m_strHobby.Empty();

	if (m_strName.IsEmpty())
		AfxMessageBox(TEXT("이름을 입력하세요."));
	else
	{
		pDoc->m_strDept = m_strDept;
		pDoc->m_strName = m_strName;

		if (m_nSex == 0)
			pDoc->m_strSex = TEXT("남자");
		else
			pDoc->m_strSex = TEXT("여자");

		if (m_bHobby[0])
			pDoc->m_strHobby += TEXT("독서 ");
		if (m_bHobby[1])
			pDoc->m_strHobby += TEXT("운동 ");
		if (m_bHobby[2])
			pDoc->m_strHobby += TEXT("낚시");
	}

	UpdateData(false);
}