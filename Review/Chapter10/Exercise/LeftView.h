#pragma once
#include "afxwin.h"



// CLeftView 폼 뷰입니다.

class CLeftView : public CFormView
{
	DECLARE_DYNCREATE(CLeftView)

protected:
	CLeftView();           // 동적 만들기에 사용되는 protected 생성자입니다.
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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


