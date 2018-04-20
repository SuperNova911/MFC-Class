
// Practice5_4View.h : CPractice5_4View 클래스의 인터페이스
//

#pragma once


class CPractice5_4View : public CView
{
protected: // serialization에서만 만들어집니다.
	CPractice5_4View();
	DECLARE_DYNCREATE(CPractice5_4View)

// 특성입니다.
public:
	CPractice5_4Doc* GetDocument() const;

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
	virtual ~CPractice5_4View();
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
};

#ifndef _DEBUG  // Practice5_4View.cpp의 디버그 버전
inline CPractice5_4Doc* CPractice5_4View::GetDocument() const
   { return reinterpret_cast<CPractice5_4Doc*>(m_pDocument); }
#endif

