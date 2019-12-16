// NCB_TestSlider.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "NCB_MFCex.h"
#include "NCB_TestSlider.h"
#include "afxdialogex.h"


// NCB_TestSlider ��ȭ �����Դϴ�.

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


// NCB_TestSlider �޽��� ó�����Դϴ�.


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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	*pResult = 0;
}


void NCB_TestSlider::OnHScroll( UINT nSBCode, UINT nPos, CScrollBar* pScrollBar )
{
	if( pScrollBar != NULL && pScrollBar->m_hWnd == m_Slider.m_hWnd ){
		// �����̴� ��Ʈ���� ���簪�� GetPos() �Լ��� ����Ͽ� �˾Ƴ����ִ�.
		// IDC_MY_EDIT ����Ʈ�� ���簪�� ����Ѵ�.
		SetDlgItemInt( IDC_EDIT1, m_Slider.GetPos() );
	}

	CDialogEx::OnHScroll( nSBCode, nPos, pScrollBar );
}
