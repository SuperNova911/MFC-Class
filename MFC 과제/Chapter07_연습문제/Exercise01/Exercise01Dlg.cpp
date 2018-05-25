
// Exercise01Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Exercise01.h"
#include "Exercise01Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
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


// CExercise01Dlg ��ȭ ����



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


// CExercise01Dlg �޽��� ó����

BOOL CExercise01Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
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

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	// TreeControl �ʱ�ȭ
	m_hRoot = m_treeCtrl.InsertItem(TEXT("����"), 0, TVI_LAST);
	m_hMovie = m_treeCtrl.InsertItem(TEXT("��ȭ"), m_hRoot, TVI_LAST);
	m_hDrama = m_treeCtrl.InsertItem(TEXT("���"), m_hRoot, TVI_LAST);
	m_treeCtrl.Expand(m_hRoot, TVE_EXPAND);

	// ListControl �ʱ�ȭ
	CString list[3] = { TEXT("��ǰ��"), TEXT("���۳⵵"), TEXT("���") };
	int nWidth[3] = { 150, 80, 100 };
	for (int i = 0; i < 3; i++)
		m_listCtrl.InsertColumn(i, list[i], LVCFMT_CENTER, nWidth[i]);
	m_listCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);



	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CExercise01Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CExercise01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



// Add ��ư Ŭ�� �̺�Ʈ
void CExercise01Dlg::OnClickedButtonAdd()
{
	// �帣�� �������� ������ ���
	if (m_hSelectedNode != m_hMovie && m_hSelectedNode != m_hDrama)
	{
		AfxMessageBox(TEXT("��ǰ �帣�� ������ �ּ���."));
		return;
	}

	UpdateData(true);

	// Edit Control�� Combo Box�� ����ִ��� Ȯ��
	if (!m_strTitle.IsEmpty() && !m_strYear.IsEmpty() && !m_strGrade.IsEmpty())
	{
		// �ߺ��� ��ǰ���� ������ �߰����� ����
		for (int i = 0; i < m_nCount; i++)
		{
			if (m_productInfo[i].strTitle == m_strTitle)
			{
				AfxMessageBox(TEXT("�ߺ��� ��ǰ�� �ֽ��ϴ�."));
				return;
			}
		}

		// Product �� �߰�
		m_productInfo[m_nCount].strCategory = m_strCategory;
		m_productInfo[m_nCount].strTitle = m_strTitle;
		m_productInfo[m_nCount].strYear = m_strYear;
		m_productInfo[m_nCount].strGrade = m_strGrade;

		// ���ڿ� �ʱ�ȭ
		m_strTitle.Empty();
		m_strYear.Empty();
		m_strGrade.Empty();

		// �޺��ڽ� �ʱ�ȭ
		m_comboGrade.SetCurSel(CB_ERR);

		// Product ���� ����
		m_nCount++;

		// ����Ʈ ��Ʈ�� ������Ʈ
		UpdateList();

		UpdateData(false);
	}
	else
	{
		AfxMessageBox(TEXT("��� �׸��� �Է����ּ���."));
		return;
	}
}


// Delete ��ư Ŭ�� �̺�Ʈ
void CExercise01Dlg::OnClickedButtonDelete()
{
	// �帣�� �������� ������ ���
	if (m_hSelectedNode != m_hMovie && m_hSelectedNode != m_hDrama)
	{
		AfxMessageBox(TEXT("��ǰ �帣�� ������ �ּ���."));
		return;
	}

	// �������� �������� ������ ���
	if (m_nSelectedItem == -1)
	{
		AfxMessageBox(TEXT("������ �������� ������ �ּ���."));
		return;
	}

	if (AfxMessageBox(TEXT("������ �����Ͻðڽ��ϱ�?"), MB_YESNO) == IDYES)
	{
		// ���� ������ �������� Product���� �ε���
		int index = getIndex(m_listCtrl.GetItemText(m_nSelectedItem, 0));

		// ����Ʈ ������ ��ĭ�� ��ܼ� �����
		for (int i = index; i < m_nCount - 1; i++)
		{
			m_productInfo[i].strCategory = m_productInfo[i + 1].strCategory;
			m_productInfo[i].strTitle = m_productInfo[i + 1].strTitle;
			m_productInfo[i].strYear = m_productInfo[i + 1].strYear;
			m_productInfo[i].strGrade = m_productInfo[i + 1].strGrade;
		}

		// Product ���� ����
		m_nCount--;

		// m_nSelectedItem �ʱ�ȭ
		m_nSelectedItem = -1;

		// ����Ʈ ������Ʈ
		UpdateList();
	}
}


// Modify ��ư Ŭ�� �̺�Ʈ
void CExercise01Dlg::OnClickedButtonModify()
{
	// �帣�� �������� ������ ���
	if (m_hSelectedNode != m_hMovie && m_hSelectedNode != m_hDrama)
	{
		AfxMessageBox(TEXT("��ǰ �帣�� ������ �ּ���."));
		return;
	}

	// �������� �������� ������ ���
	if (m_nSelectedItem == -1)
	{
		AfxMessageBox(TEXT("������ �������� ������ �ּ���."));
		return;
	}

	UpdateData(true);

	// Edit Control�� Combo Box�� ����ִ��� Ȯ��
	if (!m_strTitle.IsEmpty() && !m_strYear.IsEmpty() && !m_strGrade.IsEmpty())
	{
		// ���� ������ �������� Product���� �ε���
		CString selectedItemTitle = m_listCtrl.GetItemText(m_nSelectedItem, 0);
		int index = getIndex(selectedItemTitle);

		// �ߺ��� ��ǰ���� ������ �������� ����
		for (int i = 0; i < m_nCount; i++)
		{
			// �ڱ��ڽŰ� �ߺ��� ���
			if (index == i)
				continue;

			if (m_productInfo[i].strTitle == m_strTitle)
			{
				AfxMessageBox(TEXT("�ߺ��� ��ǰ�� �ֽ��ϴ�."));
				return;
			}
		}

		// Product �� �߰�
		m_productInfo[index].strCategory = m_strCategory;
		m_productInfo[index].strTitle = m_strTitle;
		m_productInfo[index].strYear = m_strYear;
		m_productInfo[index].strGrade = m_strGrade;

		// ���ڿ� �ʱ�ȭ
		m_strTitle.Empty();
		m_strYear.Empty();
		m_strGrade.Empty();

		// �޺��ڽ� �ʱ�ȭ
		m_comboGrade.SetCurSel(CB_ERR);

		// m_nSelectedItem �ʱ�ȭ
		m_nSelectedItem = -1;

		// ����Ʈ ������Ʈ
		UpdateList();

		UpdateData(false);
	}
	else
	{
		AfxMessageBox(TEXT("��� �׸��� �Է����ּ���."));
		return;
	}
	
}


// �޺��ڽ� ���� �̺�Ʈ
void CExercise01Dlg::OnSelchangeComboGrade()
{
	// ������ �޺��ڽ����� ���ڿ� �о����
	m_comboGrade.GetLBText(m_comboGrade.GetCurSel(), m_strGrade);
}


// Ʈ�� ���� �̺�Ʈ
void CExercise01Dlg::OnSelchangedTreeData(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	// ���� ������ Ʈ�� �������� ������ ����
	m_hSelectedNode = pNMTreeView->itemNew.hItem;

	// ��Ʈ ��带 ���������� �ƹ��͵� ����
	// ���� ������ Ʈ�� ������ �� ���
	if (m_hSelectedNode != m_hRoot)
		m_strCategory = m_treeCtrl.GetItemText(m_hSelectedNode);

	// ����Ʈ ������Ʈ
	UpdateList();

	*pResult = 0;
}


// ����Ʈ ������ ���� �̺�Ʈ
void CExercise01Dlg::OnItemchangedListData(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	// ���� ������ ����Ʈ �������� ������ ����
	m_nSelectedItem = pNMLV->iItem;

	*pResult = 0;
}


// ����Ʈ ������Ʈ
void CExercise01Dlg::UpdateList()
{
	// ����Ʈ ��Ʈ�� �ʱ�ȭ
	m_listCtrl.DeleteAllItems();

	// ����Ʈ ������ �߰�
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


// Product�迭���� strTitle�� ���� �Է°��� ���� �迭�� �ε��� ��ȯ
int CExercise01Dlg::getIndex(CString title)
{
	for (int i = 0; i < m_nCount; i++)
	{
		if (m_productInfo[i].strTitle == title)
			return i;
	}

	// ���� ã�� ����
	return -1;
}
