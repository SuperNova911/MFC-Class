// CalendarDll.h : CalendarDll DLL�� �⺻ ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCalendarDllApp
// �� Ŭ������ ������ ������ CalendarDll.cpp�� �����Ͻʽÿ�.
//

class CCalendarDllApp : public CWinApp
{
public:
	CCalendarDllApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
