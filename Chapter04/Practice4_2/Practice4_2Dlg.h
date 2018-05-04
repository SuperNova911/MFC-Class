
// Practice4_2Dlg.h : ��� ����
//

#pragma once
#include "ClockHelpDlg.h"


// CPractice4_2Dlg ��ȭ ����
class CPractice4_2Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CPractice4_2Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACTICE4_2_DIALOG };
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
	CString m_strAMPM;
	CString m_strDay;
	CString m_strHour;
	CString m_strMin;
	CString m_strMonth;
	CString m_strSec;
	CString m_strYear;
	afx_msg void OnRadio12();
	afx_msg void OnRadio24();
	afx_msg void OnClickedCheckHour();
	afx_msg void OnClickedCheckYear();
//	afx_msg void OnClickedButtonHelp();
//	bool m_bRadioClockType;
	bool m_bCheckYear;
	bool m_bCheckHour;
	bool m_bRadioClock24;
	afx_msg void OnClickedButtonHelp();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	bool m_bViewHelp;
	CClockHelpDlg m_dlgClockHelp;
};
