
// Test1View.h : CTest1View Ŭ������ �������̽�
//

#pragma once


class CTest1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CTest1View();
	DECLARE_DYNCREATE(CTest1View)

// Ư���Դϴ�.
public:
	CTest1Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CTest1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	void Sum(void);
	CString m_strArray;
//	int m_nSum;
//	int m_nAvg;
	CString m_strSum;
	CString m_strAvg;
};

#ifndef _DEBUG  // Test1View.cpp�� ����� ����
inline CTest1Doc* CTest1View::GetDocument() const
   { return reinterpret_cast<CTest1Doc*>(m_pDocument); }
#endif

