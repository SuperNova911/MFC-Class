
// Practice5_4View.h : CPractice5_4View Ŭ������ �������̽�
//

#pragma once


class CPractice5_4View : public CView
{
protected: // serialization������ ��������ϴ�.
	CPractice5_4View();
	DECLARE_DYNCREATE(CPractice5_4View)

// Ư���Դϴ�.
public:
	CPractice5_4Doc* GetDocument() const;

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
	virtual ~CPractice5_4View();
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
};

#ifndef _DEBUG  // Practice5_4View.cpp�� ����� ����
inline CPractice5_4Doc* CPractice5_4View::GetDocument() const
   { return reinterpret_cast<CPractice5_4Doc*>(m_pDocument); }
#endif

