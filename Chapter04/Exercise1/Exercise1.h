
// Exercise1.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CExercise1App:
// �� Ŭ������ ������ ���ؼ��� Exercise1.cpp�� �����Ͻʽÿ�.
//

class CExercise1App : public CWinApp
{
public:
	CExercise1App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CExercise1App theApp;