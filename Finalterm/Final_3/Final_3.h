
// Final_3.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CFinal_3App:
// �� Ŭ������ ������ ���ؼ��� Final_3.cpp�� �����Ͻʽÿ�.
//

class CFinal_3App : public CWinApp
{
public:
	CFinal_3App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CFinal_3App theApp;