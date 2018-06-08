
// Practice12_1View.h : CPractice12_1View Ŭ������ �������̽�
//

#pragma once
#include "DataSet.h"
#include "resource.h"

#define MOVE_FIRST_RECORD	1
#define MOVE_PREV_RECORD	2
#define MOVE_NEXT_RECORD	3
#define MOVE_LAST_RECORD	4


class CPractice12_1View : public CFormView
{
protected: // serialization������ ��������ϴ�.
	CPractice12_1View();
	DECLARE_DYNCREATE(CPractice12_1View)

public:
#ifdef AFX_DESIGN_TIME
	enum{ IDD = IDD_PRACTICE12_1_FORM };
#endif

// Ư���Դϴ�.
public:
	CPractice12_1Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CPractice12_1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	CString m_strBook;
	CString m_strCheckOut;
	CString m_strHakbun;
	CString m_strMajor;
	CString m_strName;
	CString m_strReturn;
	CDataSet m_dbSet;
	DbCommand m_command;
	bool m_bMoveRecord;
	int m_nTotal;
	int m_nMoveCount;
	afx_msg void OnFirstRecord();
	afx_msg void OnPrevRecord();
	afx_msg void OnNextRecord();
	afx_msg void OnLastRecord();
	void GetDataFromDb(int nMoveRecord);
};

#ifndef _DEBUG  // Practice12_1View.cpp�� ����� ����
inline CPractice12_1Doc* CPractice12_1View::GetDocument() const
   { return reinterpret_cast<CPractice12_1Doc*>(m_pDocument); }
#endif

