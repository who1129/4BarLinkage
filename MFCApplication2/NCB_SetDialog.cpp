// NCB_SetDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "NCB_MFCex.h"
#include "NCB_SetDialog.h"
#include "afxdialogex.h"
#include "NCB_MFCexView.h"

// NCB_SetDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC( NCB_SetDialog, CDialogEx )

NCB_SetDialog::NCB_SetDialog( NCB_MFCexView** pViews, CWnd* pParent /*=NULL*/ )
: CDialogEx( NCB_SetDialog::IDD, pParent )
{
	m_pViews = NULL;

	if( pViews != NULL )
	{
		m_pViews = pViews;
	}
	///////////////////////////////////////////////////
	/*for( int i = 0; i < 4; ++i )
	{
		if( m_pViews[i] == NULL )
			continue;

		m_pViews[i]->m_fAmR = 10;

		m_pViews[i]->NCB_vSetAmbR( 0, GetPos???? );
		m_pViews[i]->NCB_vSetLightG( 0 );
		m_pViews[i]->NCB_vSetLightB( 0 );
	}*/
}

NCB_SetDialog::~NCB_SetDialog()
{
}

void NCB_SetDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control( pDX, IDC_AM_SLIDER, m_amSlider );
	DDX_Control( pDX, IDC_AM_R_SLIDER, m_amSliderR );
	DDX_Control( pDX, IDC_AM_G_SLIDER, m_amSliderG );
	DDX_Control( pDX, IDC_AM_B_SLIDER, m_amSliderB );

	DDX_Control( pDX, IDC_DI_SLIDER, m_diSlider );
	DDX_Control( pDX, IDC_DiR_SLIDER, m_diSliderR );
	DDX_Control( pDX, IDC_DiG_SLIDER, m_diSliderG );
	DDX_Control( pDX, IDC_DiB_SLIDER, m_diSliderB );

	DDX_Control( pDX, IDC_SP_SLIDER, m_spSlider );
	DDX_Control( pDX, IDC_SPR_SLIDER, m_spSliderR );
	DDX_Control( pDX, IDC_SPG_SLIDER, m_spSliderG );
	DDX_Control( pDX, IDC_SPB_SLIDER, m_spSliderB );

	DDX_Radio( pDX, IDC_Light1_RADIO, ( int& )m_litRadio );
}


BEGIN_MESSAGE_MAP( NCB_SetDialog, CDialogEx )
	ON_WM_HSCROLL( )
	ON_NOTIFY( NM_CUSTOMDRAW, IDC_AM_SLIDER, &NCB_SetDialog::OnNMCustomdrawAmSlider )
	ON_NOTIFY( NM_CUSTOMDRAW, IDC_AM_R_SLIDER, &NCB_SetDialog::OnNMCustomdrawAmRSlider )
	ON_NOTIFY( NM_CUSTOMDRAW, IDC_AM_G_SLIDER, &NCB_SetDialog::OnNMCustomdrawAmGSlider )
	ON_NOTIFY( NM_CUSTOMDRAW, IDC_AM_B_SLIDER, &NCB_SetDialog::OnNMCustomdrawAmBSlider )
	
	ON_NOTIFY( NM_CUSTOMDRAW, IDC_DI_SLIDER, &NCB_SetDialog::OnNMCustomdrawDiSlider )
	ON_NOTIFY( NM_CUSTOMDRAW, IDC_DiR_SLIDER, &NCB_SetDialog::OnNMCustomdrawDirSlider )
	ON_NOTIFY( NM_CUSTOMDRAW, IDC_DiG_SLIDER, &NCB_SetDialog::OnNMCustomdrawDigSlider )
	ON_NOTIFY( NM_CUSTOMDRAW, IDC_DiB_SLIDER, &NCB_SetDialog::OnNMCustomdrawDibSlider )
	
	ON_NOTIFY( NM_CUSTOMDRAW, IDC_SP_SLIDER, &NCB_SetDialog::OnNMCustomdrawSpSlider )
	ON_NOTIFY( NM_CUSTOMDRAW, IDC_SPR_SLIDER, &NCB_SetDialog::OnNMCustomdrawSprSlider )
	ON_NOTIFY( NM_CUSTOMDRAW, IDC_SPG_SLIDER, &NCB_SetDialog::OnNMCustomdrawSpgSlider )
	ON_NOTIFY( NM_CUSTOMDRAW, IDC_SPB_SLIDER, &NCB_SetDialog::OnNMCustomdrawSpbSlider )
	
	ON_CONTROL_RANGE( BN_CLICKED, IDC_Light1_RADIO, IDC_Light4_RADIO,OnBnClickedLight1Radio )
END_MESSAGE_MAP()


// NCB_SetDialog 메시지 처리기입니다.

BOOL NCB_SetDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	m_amSlider.SetRange( 0, 10 );
	m_amSlider.SetPos( 10 );
	m_amSlider.SetTicFreq( 1 );
	m_amSliderR.SetRange( 0, 10 );
	m_amSliderR.SetPos( 5 );
	m_amSliderR.SetTicFreq( 1 );
	m_amSliderG.SetRange( 0, 10 );
	m_amSliderG.SetPos( 5 );
	m_amSliderG.SetTicFreq( 1 );
	m_amSliderB.SetRange( 0, 10 );
	m_amSliderB.SetPos( 5 );
	m_amSliderB.SetTicFreq( 1 );

	m_diSlider.SetRange( 0, 10 );
	m_diSlider.SetPos( 10 );
	m_diSlider.SetTicFreq( 1 );
	m_diSliderR.SetRange( 0, 10 );
	m_diSliderR.SetPos( 5 );
	m_diSliderR.SetTicFreq( 1 );
	m_diSliderG.SetRange( 0, 10 );
	m_diSliderG.SetPos( 5 );
	m_diSliderG.SetTicFreq( 1 );
	m_diSliderB.SetRange( 0, 10 );
	m_diSliderB.SetPos( 5 );
	m_diSliderB.SetTicFreq( 1 );

	m_spSlider.SetRange( 0, 10 );
	m_spSlider.SetPos( 10 );
	m_spSlider.SetTicFreq( 1 );
	m_spSliderR.SetRange( 0, 10 );
	m_spSliderR.SetPos( 5 );
	m_spSliderR.SetTicFreq( 1 );
	m_spSliderG.SetRange( 0, 10 );
	m_spSliderG.SetPos( 5 );
	m_spSliderG.SetTicFreq( 1 );
	m_spSliderB.SetRange( 0, 10 );
	m_spSliderB.SetPos( 5 );
	m_spSliderB.SetTicFreq( 1 );

	return TRUE;  
}
void NCB_SetDialog::OnHScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar )
{
	CDialog::OnHScroll( nSBCode, nPos, pScrollBar );
}
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
 void NCB_SetDialog::OnNMCustomdrawAmSlider( NMHDR *pNMHDR, LRESULT *pResult )
 {
 	LPNMCUSTOMDRAW pNMCD = reinterpret_cast< LPNMCUSTOMDRAW >( pNMHDR );
	int Pos = m_amSlider.GetPos();
	for( int i = 0; i < 4; ++i )
	{
		m_pViews[i]->NCB_vSetAm( Pos );
		m_pViews[i]->Invalidate();

	}
 	*pResult = 0;
 }
 
 
 void NCB_SetDialog::OnNMCustomdrawAmRSlider( NMHDR *pNMHDR, LRESULT *pResult )
 {
	 LPNMCUSTOMDRAW pNMCD = reinterpret_cast< LPNMCUSTOMDRAW >( pNMHDR );
	 int Pos = m_amSliderR.GetPos();
	 for( int i = 0; i < 4; ++i )
	 {
		 m_pViews[i]->NCB_vSetAmR( Pos );
		 m_pViews[i]->Invalidate();

	 }
 }
	 void NCB_SetDialog::OnNMCustomdrawAmGSlider( NMHDR *pNMHDR, LRESULT *pResult )
	 {
		 LPNMCUSTOMDRAW pNMCD = reinterpret_cast< LPNMCUSTOMDRAW >( pNMHDR );
		 int Pos = m_amSliderG.GetPos();
		 for( int i = 0; i < 4; ++i )
		 {
			 m_pViews[i]->NCB_vSetAmG( Pos );
			 m_pViews[i]->Invalidate();

		 }
		 *pResult = 0;
	 }


	 void NCB_SetDialog::OnNMCustomdrawAmBSlider( NMHDR *pNMHDR, LRESULT *pResult )
	 {
		 LPNMCUSTOMDRAW pNMCD = reinterpret_cast< LPNMCUSTOMDRAW >( pNMHDR );
		 int Pos = m_amSliderB.GetPos();
		 for( int i = 0; i < 4; ++i )
		 {
			 m_pViews[i]->NCB_vSetAmB( Pos );
			 m_pViews[i]->Invalidate();

		 }
		 *pResult = 0;
	 }

	 ///////////////////////////////////////////////////////////////////////////////
	 ///////////////////////////////////////////////////////////////////////////////
	 ///////////////////////////////////////////////////////////////////////////////
	 void NCB_SetDialog::OnNMCustomdrawDiSlider( NMHDR *pNMHDR, LRESULT *pResult )
	 {
		 LPNMCUSTOMDRAW pNMCD = reinterpret_cast< LPNMCUSTOMDRAW >( pNMHDR );
		 int Pos = m_diSlider.GetPos();
		 for( int i = 0; i < 4; ++i )
		 {
			 m_pViews[i]->NCB_vSetDi( Pos );
			 m_pViews[i]->Invalidate();

		 }
		 *pResult = 0;
	 }


	 void NCB_SetDialog::OnNMCustomdrawDirSlider( NMHDR *pNMHDR, LRESULT *pResult )
	 {
		 LPNMCUSTOMDRAW pNMCD = reinterpret_cast< LPNMCUSTOMDRAW >( pNMHDR );
		 int Pos = m_diSliderR.GetPos();
		 for( int i = 0; i < 4; ++i )
		 {
			 m_pViews[i]->NCB_vSetDiR( Pos );
			 m_pViews[i]->Invalidate();

		 }
		 *pResult = 0;
	 }


	 void NCB_SetDialog::OnNMCustomdrawDigSlider( NMHDR *pNMHDR, LRESULT *pResult )
	 {
		 LPNMCUSTOMDRAW pNMCD = reinterpret_cast< LPNMCUSTOMDRAW >( pNMHDR );
		 int Pos = m_diSliderG.GetPos();
		 for( int i = 0; i < 4; ++i )
		 {
			 m_pViews[i]->NCB_vSetDiG( Pos );
			 m_pViews[i]->Invalidate();

		 }
		 *pResult = 0;
	 }


	 void NCB_SetDialog::OnNMCustomdrawDibSlider( NMHDR *pNMHDR, LRESULT *pResult )
	 {
		 LPNMCUSTOMDRAW pNMCD = reinterpret_cast< LPNMCUSTOMDRAW >( pNMHDR );
		 int Pos = m_diSliderB.GetPos();
		 for( int i = 0; i < 4; ++i )
		 {
			 m_pViews[i]->NCB_vSetDiB( Pos );
			 m_pViews[i]->Invalidate();

		 }
		 *pResult = 0;
	 }
	 ///////////////////////////////////////////////////////////////////////////////
	 ///////////////////////////////////////////////////////////////////////////////
	 ///////////////////////////////////////////////////////////////////////////////

	 void NCB_SetDialog::OnNMCustomdrawSpSlider( NMHDR *pNMHDR, LRESULT *pResult )
	 {
		 LPNMCUSTOMDRAW pNMCD = reinterpret_cast< LPNMCUSTOMDRAW >( pNMHDR );
		 int Pos = m_spSlider.GetPos();
		 for( int i = 0; i < 4; ++i )
		 {
			 m_pViews[i]->NCB_vSetSp( Pos );
			 m_pViews[i]->Invalidate();

		 }
		 *pResult = 0;
	 }


	 void NCB_SetDialog::OnNMCustomdrawSprSlider( NMHDR *pNMHDR, LRESULT *pResult )
	 {
		 LPNMCUSTOMDRAW pNMCD = reinterpret_cast< LPNMCUSTOMDRAW >( pNMHDR );
		 int Pos = m_spSliderR.GetPos();
		 for( int i = 0; i < 4; ++i )
		 {
			 m_pViews[i]->NCB_vSetSpR( Pos );
			 m_pViews[i]->Invalidate();

		 }
		 *pResult = 0;
	 }


	 void NCB_SetDialog::OnNMCustomdrawSpgSlider( NMHDR *pNMHDR, LRESULT *pResult )
	 {
		 LPNMCUSTOMDRAW pNMCD = reinterpret_cast< LPNMCUSTOMDRAW >( pNMHDR );
		 int Pos = m_spSliderG.GetPos();
		 for( int i = 0; i < 4; ++i )
		 {
			 m_pViews[i]->NCB_vSetSpG( Pos );
			 m_pViews[i]->Invalidate();

		 }
		 *pResult = 0;
	 }


	 void NCB_SetDialog::OnNMCustomdrawSpbSlider( NMHDR *pNMHDR, LRESULT *pResult )
	 {
		 LPNMCUSTOMDRAW pNMCD = reinterpret_cast< LPNMCUSTOMDRAW >( pNMHDR );
		 int Pos = m_spSliderB.GetPos();
		 for( int i = 0; i < 4; ++i )
		 {
			 m_pViews[i]->NCB_vSetSpB( Pos );
			 m_pViews[i]->Invalidate();

		 }
		 *pResult = 0;
	 }

	 void NCB_SetDialog::OnBnClickedLight1Radio(UINT id )
	 {
		 UpdateData( TRUE );
		 m_litRadio;
		 switch( m_litRadio )
		 {
		 case 0:
			
			 for( int i = 0; i < 4; ++i )
			 {
				 m_pViews[i]->NCB_vSetLit( 0 );
				 m_pViews[i]->Invalidate();

			 }break;
		 case 1:
			 for( int i = 0; i < 4; ++i )
			 {
				 m_pViews[i]->NCB_vSetLit( 1 );
				 m_pViews[i]->Invalidate();

			 }break;
		 case 2:

			 for( int i = 0; i < 4; ++i )
			 {
				 m_pViews[i]->NCB_vSetLit(2 );
				 m_pViews[i]->Invalidate();

			 }break;
		 case 3:
			 for( int i = 0; i < 4; ++i )
			 {
				 m_pViews[i]->NCB_vSetLit( 3 );
				 m_pViews[i]->Invalidate();

			 }break;
		 }
	 }
