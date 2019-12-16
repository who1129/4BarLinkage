#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// NCB_TestSlider 대화 상자입니다.

class NCB_TestSlider : public CDialogEx
{
	DECLARE_DYNAMIC(NCB_TestSlider)

public:
	NCB_TestSlider(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~NCB_TestSlider();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CSliderCtrl m_Slider;
	CEdit m_edit;
	virtual BOOL OnInitDialog();
	afx_msg void OnNMCustomdrawSlider1( NMHDR *pNMHDR, LRESULT *pResult );
	afx_msg void OnHScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar );
};
