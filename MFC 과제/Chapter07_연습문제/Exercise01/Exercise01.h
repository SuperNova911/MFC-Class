
// Exercise01.h : PROJECT_NAME ���� ���α׷��� ���� �� ��� �����Դϴ�.
//

#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"		// �� ��ȣ�Դϴ�.


// CExercise01App:
// �� Ŭ������ ������ ���ؼ��� Exercise01.cpp�� �����Ͻʽÿ�.
//

class CExercise01App : public CWinApp
{
public:
	CExercise01App();

// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};

extern CExercise01App theApp;