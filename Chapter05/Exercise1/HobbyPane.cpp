// HobbyPane.cpp : ���� �����Դϴ�.
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



// CHobbyPane �޽��� ó�����Դϴ�.




int CHobbyPane::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CDockablePane::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  ���⿡ Ư��ȭ�� �ۼ� �ڵ带 �߰��մϴ�.
	if (!m_ctrlHobby.Create(IDD_DIALOG_ADD, this))
	{
		TRACE0("IDD_DIALOG_ADD �����츦 ������ ���߽��ϴ�.\n");
		return -1;
	}

	m_ctrlHobby.ShowWindow(SW_SHOW);

	return 0;
}


void CHobbyPane::OnSize(UINT nType, int cx, int cy)
{
	CDockablePane::OnSize(nType, cx, cy);

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.
	if (m_ctrlHobby.GetSafeHwnd())
	{
		m_ctrlHobby.MoveWindow(0, 0, cx, cy);
		m_ctrlHobby.SetFocus();
	}
}
