
// Final_2View.h : CFinal_2View Ŭ������ �������̽�
//

#pragma once


class CFinal_2View : public CView
{
protected: // serialization������ ��������ϴ�.
	CFinal_2View();
	DECLARE_DYNCREATE(CFinal_2View)

// Ư���Դϴ�.
public:
	CFinal_2Doc* GetDocument() const;

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
	virtual ~CFinal_2View();
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
	afx_msg void OnLine();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CPoint m_ptPrev;
	bool m_bDrawing;
	CPoint m_ptPos;
	bool m_bDrawMode;
//	CPoint m_ptList[100];
	int m_nCount;
	CPoint m_ptList[100][2];
};

#ifndef _DEBUG  // Final_2View.cpp�� ����� ����
inline CFinal_2Doc* CFinal_2View::GetDocument() const
   { return reinterpret_cast<CFinal_2Doc*>(m_pDocument); }
#endif

