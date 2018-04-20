#pragma once
#include "HobbyCtrl.h"


// CHobbyPane

class CHobbyPane : public CDockablePane
{
	DECLARE_DYNAMIC(CHobbyPane)

public:
	CHobbyPane();
	virtual ~CHobbyPane();

protected:
	DECLARE_MESSAGE_MAP()
public:
	CHobbyCtrl m_ctrlHobby;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
};


