
// Final_1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CFinal_1App:
// �� Ŭ������ ������ ���ؼ��� Final_1.cpp�� �����Ͻʽÿ�.
//

class CFinal_1App : public CWinApp
{
public:
	CFinal_1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CFinal_1App theApp;