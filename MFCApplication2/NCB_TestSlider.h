#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// NCB_TestSlider ��ȭ �����Դϴ�.

class NCB_TestSlider : public CDialogEx
{
	DECLARE_DYNAMIC(NCB_TestSlider)

public:
	NCB_TestSlider(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~NCB_TestSlider();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl m_Slider;
	CEdit m_edit;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMCustomdrawSlider1( NMHDR *pNMHDR, LRESULT *pResult );
	afx_msg void OnHScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar );
};
