
// ExerciseDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Exercise.h"
#include "ExerciseDlg.h"
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


// CExerciseDlg ��ȭ ����



CExerciseDlg::CExerciseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXERCISE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CExerciseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB_SELECTION, m_tabSelection);
}

BEGIN_MESSAGE_MAP(CExerciseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB_SELECTION, &CExerciseDlg::OnSelchangeTabSelection)
END_MESSAGE_MAP()


// CExerciseDlg �޽��� ó����

BOOL CExerciseDlg::OnInitDialog()
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

	// �� �ʱ�ȭ �� ������ ���
	m_tabSelection.DeleteAllItems();
	m_tabSelection.InsertItem(0, TEXT("���� ����"));
	m_tabSelection.InsertItem(1, TEXT("���� ����"));
	m_tabSelection.InsertItem(2, TEXT("���� ����"));

	// CObjectDlg, CColorDlg, CRatioDlg �ʱ�ȭ
	CRect rect;
	m_dlgObject.Create(IDD_DIALOG_OBJECT, &m_tabSelection);
	m_dlgObject.GetWindowRect(&rect);
	m_dlgObject.MoveWindow(5, 25, rect.Width(), rect.Height());
	m_dlgObject.ShowWindow(SW_SHOW);

	m_dlgColor.Create(IDD_DIALOG_COLOR, &m_tabSelection);
	m_dlgColor.GetWindowRect(&rect);
	m_dlgColor.MoveWindow(5, 25, rect.Width(), rect.Height());
	m_dlgColor.ShowWindow(SW_HIDE);

	m_dlgRatio.Create(IDD_DIALOG_RATIO, &m_tabSelection);
	m_dlgRatio.GetWindowRect(&rect);
	m_dlgRatio.MoveWindow(5, 25, rect.Width(), rect.Height());
	m_dlgRatio.ShowWindow(SW_HIDE);

	UpdateData(false);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CExerciseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CExerciseDlg::OnPaint()
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

	// �׸��� ���� ����
	CRect rectView, rectFigure;
	GetDlgItem(IDC_STATIC_VIEW)->GetWindowRect(&rectView);
	
	CPoint ptCenter = rectView.CenterPoint();
	ScreenToClient(&ptCenter);

	// CRatioDlg�� �����̴��� ũ�� ����
	rectFigure.left = ptCenter.x - (int)(rectView.Width() / 2.0f * (float)m_dlgRatio.m_nCurHScale / 100.0f);
	rectFigure.right = ptCenter.x + (int)(rectView.Width() / 2.0f * (float)m_dlgRatio.m_nCurHScale / 100.0f);
	rectFigure.top = ptCenter.y - (int)(rectView.Height() / 2.0f * (float)m_dlgRatio.m_nCurVScale / 100.0f);
	rectFigure.bottom = ptCenter.y + (int)(rectView.Height() / 2.0f * (float)m_dlgRatio.m_nCurVScale / 100.0f);

	// dc�� �귯�� ����
	CClientDC dc(this);
	CBrush newBrush, *oldBrush;

	newBrush.CreateSolidBrush(m_dlgColor.m_colorObject);
	oldBrush = dc.SelectObject(&newBrush);

	// ���� �׸���
	switch (m_dlgObject.m_nSelObject)
	{
	case 1:
		dc.Rectangle(&rectFigure);
		break;

	case 2:
		dc.Ellipse(&rectFigure);
		break;
	}

	dc.SelectObject(oldBrush);
	newBrush.DeleteObject();
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CExerciseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


// ���� �׸���
void CExerciseDlg::UpdateDrawing()
{
	CRect rectView;
	GetDlgItem(IDC_STATIC_VIEW)->GetWindowRect(&rectView);
	ScreenToClient(&rectView);
	rectView.DeflateRect(1, 1, 1, 1);

	InvalidateRect(&rectView);
}


// ������ �ǿ� �ش��ϴ� ��ȭ���� �����ֱ�
void CExerciseDlg::OnSelchangeTabSelection(NMHDR *pNMHDR, LRESULT *pResult)
{
	int nSelection = m_tabSelection.GetCurSel();

	// CASE
	// 0: CObjectDlg, 1: CColorDlg, 2: CRatioDlg
	switch (nSelection)
	{
	case 0:
		m_dlgObject.ShowWindow(SW_SHOW);
		m_dlgColor.ShowWindow(SW_HIDE);
		m_dlgRatio.ShowWindow(SW_HIDE);
		break;

	case 1:
		m_dlgObject.ShowWindow(SW_HIDE);
		m_dlgColor.ShowWindow(SW_SHOW);
		m_dlgRatio.ShowWindow(SW_HIDE);
		break;

	case 2:
		m_dlgObject.ShowWindow(SW_HIDE);
		m_dlgColor.ShowWindow(SW_HIDE);
		m_dlgRatio.ShowWindow(SW_SHOW);
		break;
	}

	*pResult = 0;
}
