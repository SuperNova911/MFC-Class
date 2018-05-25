
// ExerciseDlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "ColorDlg.h"
#include "ObjectDlg.h"
#include "RatioDlg.h"


// CExerciseDlg ��ȭ ����
class CExerciseDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CExerciseDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXERCISE_DIALOG };
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
	CTabCtrl m_tabSelection;
	CObjectDlg m_dlgObject;
	CColorDlg m_dlgColor;
	CRatioDlg m_dlgRatio;
	void UpdateDrawing();
	afx_msg void OnSelchangeTabSelection(NMHDR *pNMHDR, LRESULT *pResult);
};
