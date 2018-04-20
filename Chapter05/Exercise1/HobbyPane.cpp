// HobbyPane.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "Exercise1.h"
#include "HobbyPane.h"


// CHobbyPane

IMPLEMENT_DYNAMIC(CHobbyPane, CDockablePane)

CHobbyPane::CHobbyPane()
{

}

CHobbyPane::~CHobbyPane()
{
}


BEGIN_MESSAGE_MAP(CHobbyPane, CDockablePane)
	ON_WM_CREATE()
	ON_WM_SIZE()
END_MESSAGE_MAP()



// CHobbyPane 메시지 처리기입니다.




int CHobbyPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  여기에 특수화된 작성 코드를 추가합니다.
	if (!m_ctrlHobby.Create(IDD_DIALOG_ADD, this))
	{
		TRACE0("IDD_DIALOG_ADD 윈도우를 만들지 못했습니다.\n");
		return -1;
	}

	m_ctrlHobby.ShowWindow(SW_SHOW);

	return 0;
}


void CHobbyPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
	if (m_ctrlHobby.GetSafeHwnd())
	{
		m_ctrlHobby.MoveWindow(0, 0, cx, cy);
		m_ctrlHobby.SetFocus();
	}
}
