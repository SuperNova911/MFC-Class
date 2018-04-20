#pragma once
#include "TextOutCtrl.h"


// CTextOutPane

class CTextOutPane : public CWnd
{
	DECLARE_DYNAMIC(CTextOutPane)

public:
	CTextOutPane();
	virtual ~CTextOutPane();

protected:
	DECLARE_MESSAGE_MAP()
public:
//	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CTextOutCtrl m_ctrlTextOut;
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


