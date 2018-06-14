#pragma once
#include "afxwin.h"



// CLeftView �� ���Դϴ�.

class CLeftView : public CFormView
{
	DECLARE_DYNCREATE(CLeftView)

protected:
	CLeftView();           // ���� ����⿡ ���Ǵ� protected �������Դϴ�.
	virtual ~CLeftView();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FORMVIEW };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
//	CString m_strNode;
//	CEdit m_edSelectedNode;
	bool m_bChecked;
	virtual void OnInitialUpdate();
	CString m_strNode;
	CString m_strSelectedNode;
	afx_msg void OnClickedButtonInsert();
	afx_msg void OnClickedButtonModify();
	afx_msg void OnClickedButtonDelete();
	afx_msg void OnClickedCheckExpand();
};


