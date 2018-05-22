#pragma once
#include "afxcmn.h"


// CRatioDlg 대화 상자입니다.

class CRatioDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRatioDlg)

public:
	CRatioDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CRatioDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnClickedCheckSameRatio();
	CSliderCtrl m_sliderHorizon;
	CSliderCtrl m_sliderVertical;
	int m_nCurHScale;
	int m_nCurVScale;
	BOOL m_bSameRatio;
};
