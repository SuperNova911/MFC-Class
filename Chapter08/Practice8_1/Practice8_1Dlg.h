
// Practice8_1Dlg.h : 헤더 파일
//

#pragma once
#include "objectdlg.h"
#include "colordlg.h"


// CPractice8_1Dlg 대화 상자
class CPractice8_1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CPractice8_1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_PRACTICE8_1_DIALOG };

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
	CTabCtrl m_tabSelection;
	CSpinButtonCtrl m_spinSize;
	int m_nSize;
	void UpdateDrawing(void);
	afx_msg void OnSelchangeTabSelection(NMHDR *pNMHDR, LRESULT *pResult);
	CObjectDlg m_dlgObject;
	CColorDlg m_dlgColor;
	afx_msg void OnDeltaposSpinSize(NMHDR *pNMHDR, LRESULT *pResult);
};
