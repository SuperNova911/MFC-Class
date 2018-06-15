
// Final_3Dlg.h : 헤더 파일
//

#pragma once


// CFinal_3Dlg 대화 상자
class CFinal_3Dlg : public CDialogEx
{
// 생성입니다.
public:
	CFinal_3Dlg(CWnd* pParent = NULL);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
	enum { IDD = IDD_FINAL_3_DIALOG };

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
