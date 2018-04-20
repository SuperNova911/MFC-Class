
// Test2View.h : CTest2View Ŭ������ �������̽�
//

#pragma once
enum DRAW_MODE {CIRCLE_MODE, RECTANGLE_MODE};

class CTest2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CTest2View();
	DECLARE_DYNCREATE(CTest2View)

// Ư���Դϴ�.
public:
	CTest2Doc* GetDocument() const;

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
	virtual ~CTest2View();
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
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnCircle();
	afx_msg void OnRectangle();
	int m_nDrawmode;
	afx_msg void OnUpdateCircle(CCmdUI *pCmdUI);
	afx_msg void OnUpdateRectangle(CCmdUI *pCmdUI);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	CPoint m_ptStart;
	CPoint m_ptPrev;
//	bool m_bLBDown;
	bool m_bLButtonDown;
	bool m_bFirst;
	CString m_strPoint;
};

#ifndef _DEBUG  // Test2View.cpp�� ����� ����
inline CTest2Doc* CTest2View::GetDocument() const
   { return reinterpret_cast<CTest2Doc*>(m_pDocument); }
#endif

