
// Practice8_2Dlg.h : 헤더 파일
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "afxdtctl.h"


// CPractice8_2Dlg 대화 상자
class CPractice8_2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CPractice8_2Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRACTICE8_2_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
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
