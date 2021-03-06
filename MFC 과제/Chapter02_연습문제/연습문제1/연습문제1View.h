
// 연습문제1View.h: C연습문제1View 클래스의 인터페이스
//

#pragma once


class C연습문제1View : public CView
{
protected: // serialization에서만 만들어집니다.
	C연습문제1View();
	DECLARE_DYNCREATE(C연습문제1View)

// 특성입니다.
public:
	C연습문제1Doc* GetDocument() const;

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
	virtual ~C연습문제1View();
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
	bool m_bDrag;	// true: 마우스 왼쪽 버튼이 눌림, false: 떼어짐
	CString m_strWindowSize;	// 윈도우 클라이언트의 크기
	CString m_strOutput;		// 텍스트 출력용 문자열
	CString m_strPointText;		// 마우스 좌표 값 (문자열)
	CPoint m_ptMouseMove;		// 마우스 좌표 값
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // 연습문제1View.cpp의 디버그 버전
inline C연습문제1Doc* C연습문제1View::GetDocument() const
   { return reinterpret_cast<C연습문제1Doc*>(m_pDocument); }
#endif

