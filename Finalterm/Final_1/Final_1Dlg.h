
// Final_1Dlg.h : ��� ����
//

#pragma once


// CFinal_1Dlg ��ȭ ����
class CFinal_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CFinal_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FINAL_1_DIALOG };

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
	afx_msg void OnClickedButtonAuto();
	afx_msg void OnClickedButtonStep();
	afx_msg void OnClickedButtonReset();
	CProgressCtrl m_Progress;
//	void SetStep(void);
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int SetStep(void);
	void StepIt(int step);
};
