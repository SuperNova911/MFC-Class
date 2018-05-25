#pragma once


// CColorDlg ��ȭ �����Դϴ�.

class CColorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CColorDlg)

public:
	CColorDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CColorDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG_COLOR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	int m_nBlue;
	int m_nGreen;
	int m_nRed;
	CSliderCtrl m_sliderBlue;
	CSliderCtrl m_sliderGreen;
	CSliderCtrl m_sliderRed;
	COLORREF m_colorObject;
	virtual BOOL OnInitDialog();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
};
