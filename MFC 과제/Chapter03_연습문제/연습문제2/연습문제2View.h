
// 연습문제2View.h: C연습문제2View 클래스의 인터페이스
//

#pragma once


class C연습문제2View : public CView
{
protected: // serialization에서만 만들어집니다.
	C연습문제2View();
	DECLARE_DYNCREATE(C연습문제2View)

// 특성입니다.
public:
	C연습문제2Doc* GetDocument() const;

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
	virtual ~C연습문제2View();
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
	bool m_bDrag;	// true: 드래그중, false: 드래그 끝
	CString m_strOutput;	// 출력될 문자열
	CPoint m_ptLocation;	// 문자열을 출력할 좌표
	CPoint m_ptClientSize;	// 윈도우 클라이언트 크기
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 연습문제2View.cpp의 디버그 버전
inline C연습문제2Doc* C연습문제2View::GetDocument() const
   { return reinterpret_cast<C연습문제2Doc*>(m_pDocument); }
#endif

