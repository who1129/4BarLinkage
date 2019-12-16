// NCB_TestSlider.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "NCB_MFCex.h"
#include "NCB_TestSlider.h"
#include "afxdialogex.h"


// NCB_TestSlider 대화 상자입니다.

IMPLEMENT_DYNAMIC(NCB_TestSlider, CDialogEx)

NCB_TestSlider::NCB_TestSlider(CWnd* pParent /*=NULL*/)
	: CDialogEx(NCB_TestSlider::IDD, pParent)
{

}

NCB_TestSlider::~NCB_TestSlider()
{
}

void NCB_TestSlider::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange( pDX );
	DDX_Control( pDX, IDC_SLIDER1, m_Slider );
	DDX_Control( pDX, IDC_EDIT1, m_edit );
}


BEGIN_MESSAGE_MAP(NCB_TestSlider, CDialogEx)
	ON_NOTIFY( NM_CUSTOMDRAW, IDC_SLIDER1, &NCB_TestSlider::OnNMCustomdrawSlider1 )
	ON_WM_HSCROLL()
END_MESSAGE_MAP()


// NCB_TestSlider 메시지 처리기입니다.


BOOL NCB_TestSlider::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	m_Slider.SetRange( 0, 255 );
	m_Slider.SetPos( 255 );
	return TRUE;
}


void NCB_TestSlider::OnNMCustomdrawSlider1( NMHDR *pNMHDR, LRESULT *pResult )
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast< LPNMCUSTOMDRAW >( pNMHDR );
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}


void NCB_TestSlider::OnHScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar )
{
	if( pScrollBar != NULL && pScrollBar->m_hWnd == m_Slider.m_hWnd ){
		// 슬라이더 컨트롤의 현재값은 GetPos() 함수를 사용하여 알아낼수있다.
		// IDC_MY_EDIT 에디트에 현재값을 출력한다.
		SetDlgItemInt( IDC_EDIT1, m_Slider.GetPos() );
	}

	CDialogEx::OnHScroll( nSBCode, nPos, pScrollBar );
}
