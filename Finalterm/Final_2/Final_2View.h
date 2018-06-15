
// Final_2View.h : CFinal_2View 클래스의 인터페이스
//

#pragma once


class CFinal_2View : public CView
{
protected: // serialization에서만 만들어집니다.
	CFinal_2View();
	DECLARE_DYNCREATE(CFinal_2View)

// 특성입니다.
public:
	CFinal_2Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 구현입니다.
public:
	virtual ~CFinal_2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // Final_2View.cpp의 디버그 버전
inline CFinal_2Doc* CFinal_2View::GetDocument() const
   { return reinterpret_cast<CFinal_2Doc*>(m_pDocument); }
#endif

