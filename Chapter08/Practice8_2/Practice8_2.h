
// Practice8_2.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CPractice8_2App:
// �� Ŭ������ ������ ���ؼ��� Practice8_2.cpp�� �����Ͻʽÿ�.
//

class CPractice8_2App : public CWinApp
{
public:
	CPractice8_2App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CPractice8_2App theApp;