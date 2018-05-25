
// Practice8_2Dlg.h : 헤더 파일
//

#pragma once


// CPractice8_2Dlg 대화 상자
class CPractice8_2Dlg : public CDialogEx
{
// 생성입니다.
public:
	CPractice8_2Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PRACTICE8_2_DIALOG };

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
	CIPAddressCtrl m_addrReceiverIP;
	CDateTimeCtrl m_timeTransmit;
	int m_nData;
	CEdit m_edSummary;
	CProgressCtrl m_prgsTransmit;
	CSpinButtonCtrl m_spinData;
	afx_msg void OnClickedButtonTransmit();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
