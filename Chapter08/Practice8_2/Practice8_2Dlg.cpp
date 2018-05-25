
// Practice8_2Dlg.cpp : ���� ����
//

#include "stdafx.h"
#include "Practice8_2.h"
#include "Practice8_2Dlg.h"
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


// CPractice8_2Dlg ��ȭ ����




CPractice8_2Dlg::CPractice8_2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPractice8_2Dlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nTransmitRate = 0;
	m_nData = 0;
}

void CPractice8_2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_IPADDRESS_SENDER, m_addrSenderIP);
	DDX_Control(pDX, IDC_IPADDRESS_RECEIVER, m_addrReceiverIP);
	DDX_Control(pDX, IDC_DATETIMEPICKER_DATE, m_timeTransmit);
	DDX_Text(pDX, IDC_EDIT_DATA, m_nData);
	DDX_Control(pDX, IDC_EDIT_SUMMARY, m_edSummary);
	DDX_Control(pDX, IDC_PROGRESS_TRANSMIT, m_prgsTransmit);
	DDX_Control(pDX, IDC_SPIN_DATA, m_spinData);
}

BEGIN_MESSAGE_MAP(CPractice8_2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_TRANSMIT, &CPractice8_2Dlg::OnClickedButtonTransmit)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CPractice8_2Dlg �޽��� ó����

BOOL CPractice8_2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ���� ������ �־�� �մϴ�.
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
	m_prgsTransmit.SetRange(0, 100);
	m_prgsTransmit.SetPos(0);
	m_spinData.SetRange(-100, 100);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CPractice8_2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPractice8_2Dlg::OnPaint()
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
HCURSOR CPractice8_2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPractice8_2Dlg::OnClickedButtonTransmit()
{
	m_nTransmitRate = 0;

	SetTimer(1, 30, NULL);

	GetDlgItem(IDC_BUTTON_TRANSMIT)->EnableWindow(false);
}


void CPractice8_2Dlg::OnTimer(UINT_PTR nIDEvent)
{
	CString strSummary;

	if (m_nTransmitRate != 100)
	{
		m_nTransmitRate++;
		m_prgsTransmit.SetPos(m_nTransmitRate);
		strSummary.Format(TEXT("������ ���� ���Դϴ� - %d �ۼ�Ʈ \r\n\r\n ��� ��ٷ� �ֽʽÿ�....."), m_nTransmitRate);
		m_edSummary.SetWindowText(strSummary);
	}
	else
	{
		KillTimer(1);
		GetDlgItem(IDC_BUTTON_TRANSMIT)->EnableWindow(true);
		UpdateData(true);

		CString strTrans, strDataDesc;
		m_prgsTransmit.SetPos(m_nTransmitRate);
		strTrans.Format(TEXT("������ ������ �Ϸ��߽��ϴ�. - %d �ۼ�Ʈ \r\n\r\n"), m_nTransmitRate);

		BYTE b1, b2, b3, b4;
		
		CString strSender, strReceiver;
		m_addrSenderIP.GetAddress(b1, b2, b3, b4);
		strSender.Format(TEXT("�۽��� �ּ� : %d.%d.%d.%d\t\t"), b1, b2, b3, b4);
		
		m_addrReceiverIP.GetAddress(b1, b2, b3, b4);
		strReceiver.Format(TEXT("������ �ּ� : %d.%d.%d.%d\t\t"), b1, b2, b3, b4);

		CTime timeTime;
		DWORD dwResult = m_timeTransmit.GetTime(timeTime);

		CString strDate;
		strDate.Format(TEXT("���۳�¥ : %s\r\n\r\n"), timeTime.Format("%A, %B, %d, %y"));

		CString strData;
		strData.Format(TEXT("���� ������ ���� : %d"), m_nData);

		strSummary = strTrans + strSender + strReceiver + strDate + strData;
		m_edSummary.SetWindowText(strSummary);
	}

	CDialogEx::OnTimer(nIDEvent);
}