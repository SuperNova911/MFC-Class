
// Exercise01Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "Exercise01.h"
#include "Exercise01Dlg.h"
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


// CExercise01Dlg 대화 상자



CExercise01Dlg::CExercise01Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXERCISE01_DIALOG, pParent)
	, m_strYear(_T(""))
	, m_strTitle(_T(""))
	, m_strGrade(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nCount = 0;
	m_nSelectedItem = -1;
	m_strCategory = _T("");
	//  m_strSelectedItem = _T("");
}

void CExercise01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_DATA, m_listCtrl);
	DDX_Control(pDX, IDC_TREE_DATA, m_treeCtrl);
	DDX_Text(pDX, IDC_EDIT_YEAR, m_strYear);
	DDX_Text(pDX, IDC_EDIT_NAME, m_strTitle);
	DDX_Control(pDX, IDC_COMBO_GRADE, m_comboGrade);
	DDX_CBString(pDX, IDC_COMBO_GRADE, m_strGrade);
}

BEGIN_MESSAGE_MAP(CExercise01Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CExercise01Dlg::OnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CExercise01Dlg::OnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_MODIFY, &CExercise01Dlg::OnClickedButtonModify)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_DATA, &CExercise01Dlg::OnSelchangedTreeData)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_DATA, &CExercise01Dlg::OnItemchangedListData)
	ON_CBN_SELCHANGE(IDC_COMBO_GRADE, &CExercise01Dlg::OnSelchangeComboGrade)
END_MESSAGE_MAP()


// CExercise01Dlg 메시지 처리기

BOOL CExercise01Dlg::OnInitDialog()
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
	
	// TreeControl 초기화
	m_hRoot = m_treeCtrl.InsertItem(TEXT("영상물"), 0, TVI_LAST);
	m_hMovie = m_treeCtrl.InsertItem(TEXT("영화"), m_hRoot, TVI_LAST);
	m_hDrama = m_treeCtrl.InsertItem(TEXT("드라마"), m_hRoot, TVI_LAST);
	m_treeCtrl.Expand(m_hRoot, TVE_EXPAND);

	// ListControl 초기화
	CString list[3] = { TEXT("작품명"), TEXT("제작년도"), TEXT("등급") };
	int nWidth[3] = { 150, 80, 100 };
	for (int i = 0; i < 3; i++)
		m_listCtrl.InsertColumn(i, list[i], LVCFMT_CENTER, nWidth[i]);
	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);



	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CExercise01Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExercise01Dlg::OnPaint()
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
HCURSOR CExercise01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



// Add 버튼 클릭 이벤트
void CExercise01Dlg::OnClickedButtonAdd()
{
	// 장르를 선택하지 않으면 취소
	if (m_hSelectedNode != m_hMovie && m_hSelectedNode != m_hDrama)
	{
		AfxMessageBox(TEXT("작품 장르를 선택해 주세요."));
		return;
	}

	UpdateData(true);

	// Edit Control과 Combo Box가 비어있는지 확인
	if (!m_strTitle.IsEmpty() && !m_strYear.IsEmpty() && !m_strGrade.IsEmpty())
	{
		// 중복된 작품명이 있으면 추가하지 않음
		for (int i = 0; i < m_nCount; i++)
		{
			if (m_productInfo[i].strTitle == m_strTitle)
			{
				AfxMessageBox(TEXT("중복된 작품이 있습니다."));
				return;
			}
		}

		// Product 값 추가
		m_productInfo[m_nCount].strCategory = m_strCategory;
		m_productInfo[m_nCount].strTitle = m_strTitle;
		m_productInfo[m_nCount].strYear = m_strYear;
		m_productInfo[m_nCount].strGrade = m_strGrade;

		// 문자열 초기화
		m_strTitle.Empty();
		m_strYear.Empty();
		m_strGrade.Empty();

		// 콤보박스 초기화
		m_comboGrade.SetCurSel(CB_ERR);

		// Product 개수 증가
		m_nCount++;

		// 리스트 컨트롤 업데이트
		UpdateList();

		UpdateData(false);
	}
	else
	{
		AfxMessageBox(TEXT("모든 항목을 입력해주세요."));
		return;
	}
}


// Delete 버튼 클릭 이벤트
void CExercise01Dlg::OnClickedButtonDelete()
{
	// 장르를 선택하지 않으면 취소
	if (m_hSelectedNode != m_hMovie && m_hSelectedNode != m_hDrama)
	{
		AfxMessageBox(TEXT("작품 장르를 선택해 주세요."));
		return;
	}

	// 아이템을 선택하지 않으면 취소
	if (m_nSelectedItem == -1)
	{
		AfxMessageBox(TEXT("삭제할 아이템을 선택해 주세요."));
		return;
	}

	if (AfxMessageBox(TEXT("정말로 삭제하시겠습니까?"), MB_YESNO) == IDYES)
	{
		// 현재 선택한 아이템의 Product상의 인덱스
		int index = getIndex(m_listCtrl.GetItemText(m_nSelectedItem, 0));

		// 리스트 아이템 한칸씩 당겨서 지우기
		for (int i = index; i < m_nCount - 1; i++)
		{
			m_productInfo[i].strCategory = m_productInfo[i + 1].strCategory;
			m_productInfo[i].strTitle = m_productInfo[i + 1].strTitle;
			m_productInfo[i].strYear = m_productInfo[i + 1].strYear;
			m_productInfo[i].strGrade = m_productInfo[i + 1].strGrade;
		}

		// Product 개수 감소
		m_nCount--;

		// m_nSelectedItem 초기화
		m_nSelectedItem = -1;

		// 리스트 업데이트
		UpdateList();
	}
}


// Modify 버튼 클릭 이벤트
void CExercise01Dlg::OnClickedButtonModify()
{
	// 장르를 선택하지 않으면 취소
	if (m_hSelectedNode != m_hMovie && m_hSelectedNode != m_hDrama)
	{
		AfxMessageBox(TEXT("작품 장르를 선택해 주세요."));
		return;
	}

	// 아이템을 선택하지 않으면 취소
	if (m_nSelectedItem == -1)
	{
		AfxMessageBox(TEXT("수정할 아이템을 선택해 주세요."));
		return;
	}

	UpdateData(true);

	// Edit Control과 Combo Box가 비어있는지 확인
	if (!m_strTitle.IsEmpty() && !m_strYear.IsEmpty() && !m_strGrade.IsEmpty())
	{
		// 현재 선택한 아이템의 Product상의 인덱스
		CString selectedItemTitle = m_listCtrl.GetItemText(m_nSelectedItem, 0);
		int index = getIndex(selectedItemTitle);

		// 중복된 작품명이 있으면 수정하지 않음
		for (int i = 0; i < m_nCount; i++)
		{
			// 자기자신과 중복은 허용
			if (index == i)
				continue;

			if (m_productInfo[i].strTitle == m_strTitle)
			{
				AfxMessageBox(TEXT("중복된 작품이 있습니다."));
				return;
			}
		}

		// Product 값 추가
		m_productInfo[index].strCategory = m_strCategory;
		m_productInfo[index].strTitle = m_strTitle;
		m_productInfo[index].strYear = m_strYear;
		m_productInfo[index].strGrade = m_strGrade;

		// 문자열 초기화
		m_strTitle.Empty();
		m_strYear.Empty();
		m_strGrade.Empty();

		// 콤보박스 초기화
		m_comboGrade.SetCurSel(CB_ERR);

		// m_nSelectedItem 초기화
		m_nSelectedItem = -1;

		// 리스트 업데이트
		UpdateList();

		UpdateData(false);
	}
	else
	{
		AfxMessageBox(TEXT("모든 항목을 입력해주세요."));
		return;
	}
	
}


// 콤보박스 선택 이벤트
void CExercise01Dlg::OnSelchangeComboGrade()
{
	// 선택한 콤보박스에서 문자열 읽어오기
	m_comboGrade.GetLBText(m_comboGrade.GetCurSel(), m_strGrade);
}


// 트리 선택 이벤트
void CExercise01Dlg::OnSelchangedTreeData(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	// 현재 선택한 트리 아이템을 변수에 저장
	m_hSelectedNode = pNMTreeView->itemNew.hItem;

	// 루트 노드를 선택했으면 아무것도 안함
	// 현재 선택한 트리 아이템 값 얻기
	if (m_hSelectedNode != m_hRoot)
		m_strCategory = m_treeCtrl.GetItemText(m_hSelectedNode);

	// 리스트 업데이트
	UpdateList();

	*pResult = 0;
}


// 리스트 아이템 선택 이벤트
void CExercise01Dlg::OnItemchangedListData(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	// 현재 선택한 리스트 아이템을 변수에 저장
	m_nSelectedItem = pNMLV->iItem;

	*pResult = 0;
}


// 리스트 업데이트
void CExercise01Dlg::UpdateList()
{
	// 리스트 컨트롤 초기화
	m_listCtrl.DeleteAllItems();

	// 리스트 아이템 추가
	int index = 0;
	for (int i = 0; i < m_nCount; i++)
	{
		if (m_hSelectedNode == m_hRoot || m_strCategory == m_productInfo[i].strCategory)
		{
			m_listCtrl.InsertItem(index, m_productInfo[i].strTitle);
			m_listCtrl.SetItem(index, 1, LVIF_TEXT, m_productInfo[i].strYear, 0, 0, 0, NULL);
			m_listCtrl.SetItem(index, 2, LVIF_TEXT, m_productInfo[i].strGrade, 0, 0, 0, NULL);

			index++;
		}
	}
}


// Product배열에서 strTitle의 값이 입력값과 같은 배열의 인덱스 반환
int CExercise01Dlg::getIndex(CString title)
{
	for (int i = 0; i < m_nCount; i++)
	{
		if (m_productInfo[i].strTitle == title)
			return i;
	}

	// 값을 찾지 못함
	return -1;
}
