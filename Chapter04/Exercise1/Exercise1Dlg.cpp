
// Exercise1Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Exercise1.h"
#include "Exercise1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CExercise1Dlg 대화 상자



CExercise1Dlg::CExercise1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXERCISE1_DIALOG, pParent)
	, m_strResult(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExercise1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_RIGHT, m_listRight);
	DDX_Control(pDX, IDC_LIST_LEFT, m_listLeft);
	DDX_Text(pDX, IDC_EDIT_RESULT, m_strResult);
	DDX_Control(pDX, IDC_COMBO_MOVE, m_cbMove);
}

BEGIN_MESSAGE_MAP(CExercise1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_PURCHASE, &CExercise1Dlg::OnClickedButtonPurchase)
	ON_CBN_SELCHANGE(IDC_COMBO_MOVE, &CExercise1Dlg::OnSelchangeComboMove)
END_MESSAGE_MAP()


// CExercise1Dlg 메시지 처리기

BOOL CExercise1Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	m_listLeft.AddString(TEXT("복숭아"));
	m_listLeft.AddString(TEXT("딸기"));
	m_listLeft.AddString(TEXT("사과"));
	m_listLeft.AddString(TEXT("바나나"));
	m_listLeft.AddString(TEXT("수박"));
	m_listLeft.AddString(TEXT("삼겹살"));
	m_listLeft.AddString(TEXT("참기름"));
	m_listLeft.AddString(TEXT("양파"));
	m_listLeft.AddString(TEXT("계란"));

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CExercise1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CExercise1Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CExercise1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CExercise1Dlg::OnClickedButtonPurchase()
{
	int count = m_listRight.GetCount();
	CString list, purchaseList;

	if (count > 0)
	{
		for (int i = 0; i < count; i++)
		{
			m_listRight.GetText(i, list);
			purchaseList += list + TEXT("\r\n");
		}

		m_strResult = purchaseList;

		UpdateData(false);
	}
	else
		AfxMessageBox(TEXT("구매목록이 비어있음"));
}


void CExercise1Dlg::OnSelchangeComboMove()
{
	int indexCombo, indexList;
	CString strCombo, strList;

	indexCombo = m_cbMove.GetCurSel();

	if (indexCombo != CB_ERR)
	{
		m_cbMove.GetLBText(indexCombo, strCombo);

		if (strCombo == "----->")
		{
			indexList = m_listLeft.GetCurSel();

			if (indexList == CB_ERR)
			{
				AfxMessageBox(TEXT("왼쪽 리스트 박스에서 값을 선택하세요"));
				return;
			}

			m_listLeft.GetText(indexList, strList);
			m_listRight.AddString(strList);
			m_listLeft.DeleteString(indexList);
			
			if (m_listLeft.SetCurSel(indexList) == LB_ERR)
				m_listLeft.SetCurSel(indexList - 1);
			else
				m_listLeft.SetCurSel(indexList);
		}
		else if (strCombo == "<-----")
		{
			indexList = m_listRight.GetCurSel();

			if (indexList == CB_ERR)
			{
				AfxMessageBox(TEXT("오른쪽 리스트 박스에서 값을 선택하세요"));
				return;
			}

			m_listRight.GetText(indexList, strList);
			m_listLeft.AddString(strList);
			m_listRight.DeleteString(indexList);

			if (m_listRight.SetCurSel(indexList) == LB_ERR)
				m_listRight.SetCurSel(indexList - 1);
			else
				m_listRight.SetCurSel(indexList);
		}
		else
		{
			AfxMessageBox(TEXT("콤보박스 값 오류: " + strCombo));
		}
	}
	else
		AfxMessageBox(TEXT("콤보박스에서 값을 선택하세요"));
}
