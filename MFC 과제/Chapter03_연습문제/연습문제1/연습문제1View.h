
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
	CString m_strStopWatch;		// 출력되는 스톱워치 문자열을 저장할 변수
	CString m_strRecord[40];	// 기록된 내용을 저장하는 문자열 배열
	int m_nCount;	// 기록된 내용의 개수
	int m_nMinute;	// 분을 나타내는 변수
	int m_nSecond;	// 초를 나타내는 변수
	int m_nMSec;	// 1/100초를 나타내는 변수
	bool m_bStopWatchRun;		// 스톱워치가 작동되는지를 저장하는 변수
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};

#ifndef _DEBUG  // 연습문제1View.cpp의 디버그 버전
inline C연습문제1Doc* C연습문제1View::GetDocument() const
   { return reinterpret_cast<C연습문제1Doc*>(m_pDocument); }
#endif

