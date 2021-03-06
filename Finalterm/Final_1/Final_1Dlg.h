
// Final_1Dlg.h : 헤더 파일
//

#pragma once


// CFinal_1Dlg 대화 상자
class CFinal_1Dlg : public CDialogEx
{
// 생성입니다.
public:
	CFinal_1Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FINAL_1_DIALOG };

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
	afx_msg void OnClickedButtonAuto();
	afx_msg void OnClickedButtonStep();
	afx_msg void OnClickedButtonReset();
	CProgressCtrl m_Progress;
//	void SetStep(void);
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int SetStep(void);
	void StepIt(int step);
};
