// CalenderDLL.h : CalenderDLL DLL�� �⺻ ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CCalenderDLLApp
// �� Ŭ������ ������ ������ CalenderDLL.cpp�� �����Ͻʽÿ�.
//

class CCalenderDLLApp : public CWinApp
{
public:
	CCalenderDLLApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

	DECLARE_MESSAGE_MAP()
};
