
// Exercise.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CExerciseApp:
// �� Ŭ������ ������ ���ؼ��� Exercise.cpp�� �����Ͻʽÿ�.
//

class CExerciseApp : public CWinApp
{
public:
	CExerciseApp();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CExerciseApp theApp;