
// Final_3Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Final_3.h"
#include "Final_3Dlg.h"
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
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFinal_3Dlg ��ȭ ����




CFinal_3Dlg::CFinal_3Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CFinal_3Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_strText = _T("");
	m_strSelectedNode = _T("");
}

void CFinal_3Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TREE_CONTROL, m_treeControl);
	DDX_Text(pDX, IDC_EDIT_TEXT, m_strText);
	DDX_Text(pDX, IDC_EDIT_SELECTED_NODE, m_strSelectedNode);
}

BEGIN_MESSAGE_MAP(CFinal_3Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_INSERT, &CFinal_3Dlg::OnClickedButtonInsert)
	ON_BN_CLICKED(IDC_BUTTON_DELETE, &CFinal_3Dlg::OnClickedButtonDelete)
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE_CONTROL, &CFinal_3Dlg::OnSelchangedTreeControl)
END_MESSAGE_MAP()


// CFinal_3Dlg �޽��� ó����

BOOL CFinal_3Dlg::OnInitDialog()
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

	// �� ��ȭ ������ �������� �����մϴ�. ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	m_hRoot = m_treeControl.InsertItem(TEXT("��ǻ�Ϳ� ���ͳ�"), 0, TVI_LAST);
	m_hKind[0] = m_treeControl.InsertItem(TEXT("IT ������"), m_hRoot, TVI_LAST);
	m_hKind[1] = m_treeControl.InsertItem(TEXT("�׷���/��Ƽ�̵��"), m_hRoot, TVI_LAST);
	m_hKind[2] = m_treeControl.InsertItem(TEXT("���ǽ�Ȱ�뵵��"), m_hRoot, TVI_LAST);
	m_hKind[3] = m_treeControl.InsertItem(TEXT("��/��ǻ�� �Թ�&Ȱ��"), m_hRoot, TVI_LAST);

	m_treeControl.Expand(m_hRoot, TVE_EXPAND);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CFinal_3Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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
//  �Ʒ� �ڵ尡 �ʿ��մϴ�. ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CFinal_3Dlg::OnPaint()
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
HCURSOR CFinal_3Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CFinal_3Dlg::OnClickedButtonInsert()
{
	UpdateData(true);

	if (m_strText.IsEmpty())
	{
		AfxMessageBox(TEXT("�������� �Է��ϼ���."));
	}
	else
	{
		if (AfxMessageBox(TEXT("�Է��Ͻðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			m_treeControl.InsertItem(m_strText, m_hSelectItem, TVI_LAST);
			m_treeControl.Expand(m_hSelectItem, TVE_EXPAND);

			m_strText.Empty();
		}
	}

	UpdateData(false);
}


void CFinal_3Dlg::OnClickedButtonDelete()
{
	if (m_hSelectItem == m_hRoot)
	{
		AfxMessageBox(TEXT("��Ʈ ���� �����ϸ� �ȵ˴ϴ�."));
	}
	else
	{
		if (AfxMessageBox(TEXT("�����Ͻðڽ��ϱ�?"), MB_YESNO | MB_ICONQUESTION) == IDYES)
		{
			m_treeControl.DeleteItem(m_hSelectItem);
		}
	}
}


void CFinal_3Dlg::OnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);

	m_hSelectItem = pNMTreeView->itemNew.hItem;

	m_strSelectedNode = m_treeControl.GetItemText(m_hSelectItem);

	UpdateData(false);

	*pResult = 0;
}
