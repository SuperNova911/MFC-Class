
// Practice8_1Dlg.h : ��� ����
//

#pragma once
#include "objectdlg.h"
#include "colordlg.h"


// CPractice8_1Dlg ��ȭ ����
class CPractice8_1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CPractice8_1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_PRACTICE8_1_DIALOG };

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
	CTabCtrl m_tabSelection;
	CSpinButtonCtrl m_spinSize;
	int m_nSize;
	void UpdateDrawing(void);
	afx_msg void OnSelchangeTabSelection(NMHDR *pNMHDR, LRESULT *pResult);
	CObjectDlg m_dlgObject;
	CColorDlg m_dlgColor;
	afx_msg void OnDeltaposSpinSize(NMHDR *pNMHDR, LRESULT *pResult);
};
