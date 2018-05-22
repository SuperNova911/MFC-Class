
// Exercise01Dlg.h : ��� ����
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"

typedef struct Product
{
	CString strCategory;
	CString strTitle;
	CString strYear;
	CString strGrade;
} Product;

// CExercise01Dlg ��ȭ ����
class CExercise01Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CExercise01Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXERCISE01_DIALOG };
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
	CListCtrl m_listCtrl;
	CTreeCtrl m_treeCtrl;
	CString m_strYear;
	CString m_strTitle;
	afx_msg void OnClickedButtonAdd();
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnClickedButtonModify();
	HTREEITEM m_hRoot;
	HTREEITEM m_hMovie;
	HTREEITEM m_hDrama;
	Product m_productInfo[50];
	int m_nCount;
	int m_nSelectedItem;
	HTREEITEM m_hSelectedNode;
	afx_msg void OnSelchangedTreeData(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnItemchangedListData(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnSelchangeComboGrade();
	CComboBox m_comboGrade;
	CString m_strGrade;
	void UpdateList();
	CString m_strCategory;
	int getIndex(CString title);
};
