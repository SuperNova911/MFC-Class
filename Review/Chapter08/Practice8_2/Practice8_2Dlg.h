
// Practice8_2Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "afxdtctl.h"


// CPractice8_2Dlg ��ȭ ����
class CPractice8_2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CPractice8_2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACTICE8_2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	int m_nTransmitRate;
	CIPAddressCtrl m_addrSenderIP;
//	CIPAddressCtrl addrReceiverIP;
	CEdit m_edSummary;
	int m_nData;
	CSpinButtonCtrl m_spinData;
	CDateTimeCtrl m_timeTransmit;
	CProgressCtrl m_prgsTransmit;
	afx_msg void OnClickedButtonTransmit();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CIPAddressCtrl m_addrReceiverIP;
};
