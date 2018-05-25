#pragma once
#include "afxcmn.h"


// CRatioDlg ��ȭ �����Դϴ�.

class CRatioDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CRatioDlg)

public:
	CRatioDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CRatioDlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

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
