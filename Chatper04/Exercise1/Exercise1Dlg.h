
// Exercise1Dlg.h : ��� ����
//

#pragma once
#include "afxwin.h"


// CExercise1Dlg ��ȭ ����
class CExercise1Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CExercise1Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXERCISE1_DIALOG };
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
	CListBox m_listRight;
	CListBox m_listLeft;
	CString m_strResult;
	CComboBox m_cbMove;
	afx_msg void OnClickedButtonPurchase();
	afx_msg void OnSelchangeComboMove();
};
