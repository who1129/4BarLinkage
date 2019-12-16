
#include "NCB_MFCexView.h"

// NCB_SetDialog 대화 상자입니다.

class NCB_SetDialog : public CDialogEx
{
	DECLARE_DYNAMIC(NCB_SetDialog)

public:
	NCB_SetDialog( NCB_MFCexView **pViews, CWnd* pParent = NULL );   // 표준 생성자입니다.
	virtual ~NCB_SetDialog();

	NCB_MFCexView** m_pViews;

	CSliderCtrl m_amSlider;
	CSliderCtrl m_amSliderR;
	CSliderCtrl m_amSliderG;
	CSliderCtrl m_amSliderB;

	CSliderCtrl m_diSlider;
	CSliderCtrl m_diSliderR;
	CSliderCtrl m_diSliderG;
	CSliderCtrl m_diSliderB;

	CSliderCtrl m_spSlider;
	CSliderCtrl m_spSliderR;
	CSliderCtrl m_spSliderG;
	CSliderCtrl m_spSliderB;

	int m_litRadio;
	



// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP() 
public:
	//void NCB_SetDialog::OnHScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar );
	virtual BOOL OnInitDialog( );
	afx_msg void OnHScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar );

	afx_msg void OnNMCustomdrawAmSlider( NMHDR *pNMHDR, LRESULT *pResult );
 	afx_msg void OnNMCustomdrawAmRSlider( NMHDR *pNMHDR, LRESULT *pResult ); 
	afx_msg void OnNMCustomdrawAmGSlider( NMHDR *pNMHDR, LRESULT *pResult );
	afx_msg void OnNMCustomdrawAmBSlider( NMHDR *pNMHDR, LRESULT *pResult );

	afx_msg void OnNMCustomdrawDiSlider( NMHDR *pNMHDR, LRESULT *pResult );
	afx_msg void OnNMCustomdrawDirSlider( NMHDR *pNMHDR, LRESULT *pResult );
	afx_msg void OnNMCustomdrawDigSlider( NMHDR *pNMHDR, LRESULT *pResult );
	afx_msg void OnNMCustomdrawDibSlider( NMHDR *pNMHDR, LRESULT *pResult );
	
	afx_msg void OnNMCustomdrawSpSlider( NMHDR *pNMHDR, LRESULT *pResult );
	afx_msg void OnNMCustomdrawSprSlider( NMHDR *pNMHDR, LRESULT *pResult );
	afx_msg void OnNMCustomdrawSpgSlider( NMHDR *pNMHDR, LRESULT *pResult );
	afx_msg void OnNMCustomdrawSpbSlider( NMHDR *pNMHDR, LRESULT *pResult );
	
	
	afx_msg void OnBnClickedLight1Radio(UINT id);
};
