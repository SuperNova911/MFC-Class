
// Final_3Dlg.h : ��� ����
//

#pragma once


// CFinal_3Dlg ��ȭ ����
class CFinal_3Dlg : public CDialogEx
{
// �����Դϴ�.
public:
	CFinal_3Dlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_FINAL_3_DIALOG };

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
	CTreeCtrl m_treeControl;
	CString m_strText;
	CString m_strSelectedNode;
	afx_msg void OnClickedButtonInsert();
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnSelchangedTreeControl(NMHDR *pNMHDR, LRESULT *pResult);
	HTREEITEM m_hRoot;
	HTREEITEM m_hKind[4];
	HTREEITEM m_hSelectItem;
};
