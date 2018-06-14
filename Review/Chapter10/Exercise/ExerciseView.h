
// ExerciseView.h : CExerciseView Ŭ������ �������̽�
//

#pragma once


class CExerciseView : public CTreeView
{
protected: // serialization������ ��������ϴ�.
	CExerciseView();
	DECLARE_DYNCREATE(CExerciseView)

// Ư���Դϴ�.
public:
	CExerciseDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual void OnInitialUpdate(); // ���� �� ó�� ȣ��Ǿ����ϴ�.

// �����Դϴ�.
public:
	virtual ~CExerciseView();
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
	HTREEITEM m_hRoot;
	HTREEITEM m_hSelectedNode;
	afx_msg void OnTvnSelchanged(NMHDR *pNMHDR, LRESULT *pResult);
};

#ifndef _DEBUG  // ExerciseView.cpp�� ����� ����
inline CExerciseDoc* CExerciseView::GetDocument() const
   { return reinterpret_cast<CExerciseDoc*>(m_pDocument); }
#endif

