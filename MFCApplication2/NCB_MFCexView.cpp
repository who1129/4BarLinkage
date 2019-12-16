#include "stdafx.h"
#include <gl/GL.h>
#include <gl/GLU.h>
#include "gl/glut.h"

#include <math.h>
#ifndef SHARED_HANDLERS
#include "NCB_MFCex.h"
#endif

#include "NCB_MFCexDOc.h"
#include "NCB_MFCexView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE( NCB_MFCexView, CView )

BEGIN_MESSAGE_MAP( NCB_MFCexView, CView )
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_WM_PAINT()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_MOUSEWHEEL()

END_MESSAGE_MAP()

// NCB_MFCexView 생성/소멸

NCB_MFCexView::NCB_MFCexView()
{
	m_bMoveR = false;
	m_bMoveT = false;

	m_fSize = 150.f;

	m_fX = m_fY = m_fPremoveX = m_fMoveX = m_fPremoveY = m_fMoveY = 0.0;
	m_fXAngle = 0.0;
	m_fYAngle = 0.0;
	m_fXRot = m_fYRot = m_fXPos = m_fYPos = 0.0;

	m_fRight = m_fLeft = m_fTop = m_fBottom = 0.0;

	m_fAmR= m_fAmG= m_fAmB= 5;
	m_fDiR= m_fDiG= m_fDiB= 5;
	m_fSpR= m_fSpG= m_fSpB= 5;
	m_fAm = 10;
	m_fDi = 10;
	m_fSp = 10;
}

NCB_MFCexView::~NCB_MFCexView()
{
}

BOOL NCB_MFCexView::PreCreateWindow( CREATESTRUCT& cs )
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow( cs );
}

// NCB_MFCexView 그리기
int NCB_MFCexView::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	if( CView::OnCreate( lpCreateStruct ) == -1 )
		return -1;

	// TODO: Add your specialized creation code here
	int nPixelFormat;
	m_hDC = ::GetDC( m_hWnd );
	glClearColor( 0.0, 0.0, 0.0, 0.0 );
	glClear( GL_COLOR_BUFFER_BIT );
	glColor3f( 1.0, 1.0, 1.0 );
	//glOrtho( 0.0, 1.0, 0.0, 1.0, -1.0, 1.0 );
	static PIXELFORMATDESCRIPTOR pfd =
	{
		sizeof( PIXELFORMATDESCRIPTOR ),
		1,
		PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL |
		PFD_DOUBLEBUFFER,
		PFD_TYPE_RGBA,
		24,
		0, 0, 0, 0, 0, 0,
		0, 0,
		0, 0, 0, 0, 0,
		32,
		0,
		0,
		PFD_MAIN_PLANE,
		0,
		0, 0, 0
	};

	nPixelFormat = ChoosePixelFormat( m_hDC, &pfd );
	VERIFY( SetPixelFormat( m_hDC, nPixelFormat, &pfd ) );
	m_hRC = wglCreateContext( m_hDC );
	
	return 0;
}

void NCB_MFCexView::OnDestroy()
{
	wglDeleteContext( m_hRC );
	::ReleaseDC( m_hWnd, m_hDC );

	CView::OnDestroy();
}

void NCB_MFCexView::OnSize( UINT nType, int cx, int cy )
{
	CView::OnSize( nType, cx, cy );

	// TODO: Add your message handler code here
	VERIFY( wglMakeCurrent( m_hDC, m_hRC ) );

	VERIFY( wglMakeCurrent( NULL, NULL ) );
}

void NCB_MFCexView::OnDraw( CDC* pDC )
{
}

BOOL NCB_MFCexView::OnPreparePrinting( CPrintInfo* pInfo )
{
	return DoPreparePrinting( pInfo );
}

void NCB_MFCexView::OnBeginPrinting( CDC* /*pDC*/, CPrintInfo* /*pInfo*/ )
{
}

void NCB_MFCexView::OnEndPrinting( CDC* /*pDC*/, CPrintInfo* /*pInfo*/ )
{
}

BOOL NCB_MFCexView::OnEraseBkgnd( CDC* pDC )
{
	return TRUE;
}

void NCB_MFCexView::OnPaint( void )
{
	CWnd::OnPaint();

	CPaintDC dc( this );
	if( !m_hDC || !m_hRC )
		return;

	CRect rc;
	GetClientRect( rc );
	wglMakeCurrent( m_hDC, m_hRC ); 
	glViewport( 0, 0, rc.Width(), rc.Height() );

	m_fWidth = rc.Width();
	m_fHeight = rc.Height();

	
	//double dsize = 50.f;
	float fa;

	fa = m_fHeight / m_fWidth;

	m_fLeft = -0.5*m_fSize;
	m_fRight = 0.5*m_fSize;

	m_fBottom = -0.5*fa*m_fSize;
	m_fTop = 0.5*fa*m_fSize;

	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	
	glOrtho( m_fLeft, m_fRight, m_fBottom, m_fTop, m_fSize*2, -m_fSize*2 );
	
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	NCB_vTrans();
	NCB_InitLights( );
	
	NCB_ReDraw();
	

	wglMakeCurrent(NULL, NULL );
} 

/**
* @brief :
* @date  : 2017-4-21 16:17
* @return:   void
* @param[in]: void
*/
void NCB_MFCexView::NCB_ReDraw( void )
{
	wglMakeCurrent( m_hDC, m_hRC );
	GLRenderScene();
	glFlush();
	SwapBuffers( m_hDC );
	wglMakeCurrent( m_hDC, NULL );
}

#ifdef _DEBUG
void NCB_MFCexView::AssertValid() const
{
	CView::AssertValid();
}

void NCB_MFCexView::Dump( CDumpContext& dc ) const
{
	CView::Dump( dc );
}

NCB_MFCexDoc* NCB_MFCexView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT( m_pDocument->IsKindOf( RUNTIME_CLASS( NCB_MFCexDoc ) ) );
	return ( NCB_MFCexDoc* )m_pDocument;
}
#endif



/**
* @brief : 마우스 오른쪽 버튼 누름
* @date  : 2017-1-25 18:04
* @return:   void
* @param[in]: UINT nFlags
* @param[in]: CPoint point
*/
void NCB_MFCexView::OnRButtonDown( UINT nFlags, CPoint point )
{
	m_pMouseDPoint = point;
	SetCapture( ); // 마우스가 현재 윈도우에서 벗어나더라도 메시지를 계속 수신
	m_bMoveR = true;
	CWnd::OnRButtonDown( nFlags, point );

}

/**
* @brief : 마우스 오른쪽 버튼 뗌
* @date  : 2017-1-25 18:07
* @return:   void
* @param[in]: UINT nFlags
* @param[in]: CPoint point
*/
void NCB_MFCexView::OnRButtonUp( UINT nFlags, CPoint point )
{
	m_pMouseDPoint = CPoint( 0, 0 );
	ReleaseCapture( ); //메시지 수신 종료
	m_bMoveR = false;
	CWnd::OnRButtonUp( nFlags, point );

}

/**
* @brief : 마우스 왼쪽 버튼을 누름
* @date  : 2017-1-25 18:10
* @return:   void
* @param[in]: UINT nFlags
* @param[in]: CPoint point
*/
void NCB_MFCexView::OnLButtonDown( UINT nFlags, CPoint point )
{
	GLfloat x, y;

	x = point.x / m_fWidth * ( m_fRight - m_fLeft ) + m_fLeft;
	y = ( m_fHeight - point.y ) / m_fHeight * ( m_fTop - m_fBottom ) + m_fBottom;

	m_fX = x;
	m_fY = y;
	m_bMoveT = true;
	Invalidate( );
	SetCapture( );
	CWnd::OnLButtonDown( nFlags, point );
}

/**
* @brief : 마우스 왼쪽 버튼 뗌
* @date  : 2017-1-25 18:13
* @return:   void
* @param[in]: UINT nFlags
* @param[in]: CPoint point
*/
void NCB_MFCexView::OnLButtonUp( UINT nFlags, CPoint point )
{
	m_fPremoveX += m_fMoveX;
	m_fPremoveY += m_fMoveY;

	m_fMoveX = 0;
	m_fMoveY = 0;
	m_bMoveT = false;
	SetFocus( );
	ReleaseCapture( );
	CWnd::OnLButtonUp( nFlags, point );
}

/**
* @brief : 마우스 휠
* @date  : 2017-6-1 9:33
* @return:   BOOL
* @param[in]: UINT nFlags
* @param[in]: short zDelta
* @param[in]: CPoint pt
*/
BOOL NCB_MFCexView::OnMouseWheel( UINT nFlags, short zDelta, CPoint pt )
{
	if( zDelta > 0 && m_fRight > 9 )
	{
		m_fSize -= 10;
	}
	else if( zDelta < 0 && m_fRight < 200 )
	{
		m_fSize += 10;
	}

	Invalidate( );

	return CWnd::OnMouseWheel( nFlags, zDelta, pt );
}

/**
* @brief : 마우스 오른쪽 왼쪽 움직이기
* @date  : 2017-1-25 18:56
* @return:   void
* @param[in]: UINT nFlags
* @param[in]: CPoint point
*/
void NCB_MFCexView::OnMouseMove( UINT nFlags, CPoint point )
{
	//왼쪽 버튼 동작
	if( m_bMoveT )
	{
		GLfloat x, y;

		x = point.x / m_fWidth * ( m_fRight - m_fLeft ) + m_fLeft;
		y = ( m_fHeight - point.y ) / m_fHeight * ( m_fTop - m_fBottom ) + m_fBottom;

		m_fMoveX = x - m_fX;
		m_fMoveY = y - m_fY;

		Invalidate( );
	}
	//오른쪽 버튼 동작
	if( m_bMoveR )
	{
		m_fXAngle -= ( point.y - m_pMouseDPoint.y ) / 10.f;// 3.6f; 
		m_fYAngle -= ( point.x - m_pMouseDPoint.x ) / 10.f;// 3.6f;

		InvalidateRect( NULL, FALSE );

		m_pMouseDPoint = point;
	}
	CWnd::OnMouseMove( nFlags, point );
}

/**
* @brief : 마우스 회전
* @date  : 2017-2-16 15:22
* @return:   void
* @param[in]: void
*/
void NCB_MFCexView::NCB_vTrans( void )
{
	glTranslatef( m_fPremoveX + m_fMoveX, m_fPremoveY + m_fMoveY, 0.0f );

	glRotatef( m_fXAngle, 1.0f, 0.0f, 0.0f ); // X방향 회전
	glRotatef( m_fYAngle, 0.0f, 1.0f, 0.0f ); // Y방향 회전
}

void NCB_MFCexView::NCB_InitLights()
{
	switch( (int)m_flit ){
	case 0:
		NCB_Light1(); break;
	case 1:
		NCB_Light2(); break;
	case 2:
		NCB_Light3(); break;
	case 3:
		NCB_Light4(); break;

	default:NCB_Light1();	break;
	}
}

void NCB_MFCexView::NCB_Light1()
{
	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat lit_amb1[] = { m_fAmR*0.1*( m_fAm*0.1 ),
						   m_fAmG*0.1*( m_fAm*0.1 ),
						   m_fAmB*0.1*( m_fAm*0.1 ),
						   1 };// 주변광의 강도
	GLfloat lit_dif1[] = { m_fDiR*0.1*( m_fDi*0.1 ),
						   m_fDiG*0.1*( m_fDi*0.1 ),
						   m_fDiB*0.1*( m_fDi*0.1 ),
						   1 }; // 분산광의 강도
	GLfloat lit_spc1[] = { m_fSpR*0.1*( m_fSp*0.1 ),
						   m_fSpG*0.1*( m_fSp*0.1 ),
						   m_fSpB*0.1*( m_fSp*0.1 ),
						   1 };	// 반사광의 강도
	GLfloat lit_pos1[] = { 0.0, 100.0, 0.0, 0.0 };// 광원의 위치/    
	
	glLightfv( GL_LIGHT1, GL_AMBIENT, lit_amb1 );
	glLightfv( GL_LIGHT1, GL_DIFFUSE, lit_dif1 );
	glLightfv( GL_LIGHT1, GL_SPECULAR, lit_spc1 );
	glLightfv( GL_LIGHT1, GL_POSITION, lit_pos1 );

	glEnable( GL_COLOR_MATERIAL );					// 현재 색상을 재질로 설정
	glMaterialf( GL_BACK, GL_SHININESS, 120.0f );	// 빛나는 정도
	glMaterialfv( GL_BACK, GL_SPECULAR, specref );	//반사
	glColorMaterial( GL_FRONT, GL_SPECULAR);
	glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT1 );
 	//glDisable( GL_CULL_FACE );
 	glEnable( GL_DEPTH_TEST );
 	glFrontFace( GL_CCW );
 	glShadeModel( GL_SMOOTH);
}

void NCB_MFCexView::NCB_Light2()
{
	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat lit_amb1[] = { m_fAmR*0.1*( m_fAm*0.1 ),
		m_fAmG*0.1*( m_fAm*0.1 ),
		m_fAmB*0.1*( m_fAm*0.1 ),
		1 };// 주변광의 강도
	GLfloat lit_dif1[] = { m_fDiR*0.1*( m_fDi*0.1 ),
		m_fDiG*0.1*( m_fDi*0.1 ),
		m_fDiB*0.1*( m_fDi*0.1 ),
		1 }; // 분산광의 강도
	GLfloat lit_spc1[] = { m_fSpR*0.1*( m_fSp*0.1 ),
		m_fSpG*0.1*( m_fSp*0.1 ),
		m_fSpB*0.1*( m_fSp*0.1 ),
		1 };	// 반사광의 강도
	GLfloat lit_pos1[] = { 0.0, 100.0, 0.0, 0.0 };// 광원의 위치/    

	glLightfv( GL_LIGHT1, GL_AMBIENT, lit_amb1 );
	glLightfv( GL_LIGHT1, GL_DIFFUSE, lit_dif1 );
	glLightfv( GL_LIGHT1, GL_SPECULAR, lit_spc1 );
	glLightfv( GL_LIGHT1, GL_POSITION, lit_pos1 );

	glEnable( GL_COLOR_MATERIAL );					// 현재 색상을 재질로 설정
	glMaterialf( GL_BACK, GL_SHININESS, 0.0f );	// 빛나는 정도
	glMaterialfv( GL_BACK, GL_SPECULAR, specref );	//반사
	glColorMaterial( GL_FRONT, GL_SPECULAR );
	glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT2 );
	//glDisable( GL_CULL_FACE );
	glEnable( GL_DEPTH_TEST );
	glFrontFace( GL_CCW );
	glShadeModel( GL_FLAT );
}

void NCB_MFCexView::NCB_Light3()
{
	GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
	GLfloat lit_amb1[] = { m_fAmR*0.1*( m_fAm*0.1 ),
		m_fAmG*0.1*( m_fAm*0.1 ),
		m_fAmB*0.1*( m_fAm*0.1 ),
		1 };// 주변광의 강도
	GLfloat lit_dif1[] = { m_fDiR*0.1*( m_fDi*0.1 ),
		m_fDiG*0.1*( m_fDi*0.1 ),
		m_fDiB*0.1*( m_fDi*0.1 ),
		1 }; // 분산광의 강도
	GLfloat lit_spc1[] = { m_fSpR*0.1*( m_fSp*0.1 ),
		m_fSpG*0.1*( m_fSp*0.1 ),
		m_fSpB*0.1*( m_fSp*0.1 ),
		1 };	// 반사광의 강도
	GLfloat lit_pos1[] = { 100.0, 100.0, 100.0, 0.0 };// 광원의 위치/    

	glLightfv( GL_LIGHT1, GL_AMBIENT, lit_amb1 );
	glLightfv( GL_LIGHT1, GL_DIFFUSE, lit_dif1 );
	glLightfv( GL_LIGHT1, GL_SPECULAR, lit_spc1 );
	glLightfv( GL_LIGHT1, GL_POSITION, lit_pos1 );

	glEnable( GL_COLOR_MATERIAL );					// 현재 색상을 재질로 설정
	glMaterialf( GL_BACK, GL_SHININESS, 0.0f );	// 빛나는 정도
	glMaterialfv( GL_BACK, GL_SPECULAR, specref );	//반사
	glColorMaterial( GL_FRONT, GL_SPECULAR );
	glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT3 );
	//glDisable( GL_CULL_FACE );
	glEnable( GL_DEPTH_TEST );
	glFrontFace( GL_CCW );
	glShadeModel( GL_FLAT );
}

void NCB_MFCexView::NCB_Light4()
{
	GLfloat specref[] = { 1.0f, 0.0f, 0.0f, 1.0f };
	GLfloat lit_amb1[] = { m_fAmR*0.1*( m_fAm*0.1 ),
		m_fAmG*0.1*( m_fAm*0.1 ),
		m_fAmB*0.1*( m_fAm*0.1 ),
		1 };// 주변광의 강도
	GLfloat lit_dif1[] = { m_fDiR*0.1*( m_fDi*0.1 ),
		m_fDiG*0.1*( m_fDi*0.1 ),
		m_fDiB*0.1*( m_fDi*0.1 ),
		1 }; // 분산광의 강도
	GLfloat lit_spc1[] = { m_fSpR*0.1*( m_fSp*0.1 ),
		m_fSpG*0.1*( m_fSp*0.1 ),
		m_fSpB*0.1*( m_fSp*0.1 ),
		1 };	// 반사광의 강도
	GLfloat lit_pos1[] = { -100.0, 100.0, -10.0, 0.0 };// 광원의 위치/    

	glLightfv( GL_LIGHT1, GL_AMBIENT, lit_amb1 );
	glLightfv( GL_LIGHT1, GL_DIFFUSE, lit_dif1 );
	glLightfv( GL_LIGHT1, GL_SPECULAR, lit_spc1 );
	glLightfv( GL_LIGHT1, GL_POSITION, lit_pos1 );

	glEnable( GL_COLOR_MATERIAL );					// 현재 색상을 재질로 설정
	glMaterialf( GL_BACK, GL_SHININESS, 120.0f );	// 빛나는 정도
	glMaterialfv( GL_BACK, GL_SPECULAR, specref );	//반사
	glColorMaterial( GL_FRONT, GL_SPECULAR );
	glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
	glEnable( GL_LIGHTING );
	glEnable( GL_LIGHT4 );
	//glDisable( GL_CULL_FACE );
	glEnable( GL_DEPTH_TEST );
	glFrontFace( GL_CCW );
	glShadeModel( GL_SMOOTH );
}
void NCB_MFCexView::NCB_vSetAm( float fValue )
{
	m_fAm = fValue;
}

float NCB_MFCexView::NCB_fGetAm()
{
	return m_fAm;   
}
void NCB_MFCexView::NCB_vSetAmR( float fValue )
{
	m_fAmR = fValue;
}

float NCB_MFCexView::NCB_fGetAmR( )
{
	return m_fAmR;
}
void NCB_MFCexView::NCB_vSetAmG( float fValue )
{
	m_fAmG = fValue;
}

float NCB_MFCexView::NCB_fGetAmG()
{
	return m_fAmG;
}
void NCB_MFCexView::NCB_vSetAmB( float fValue )
{
	m_fAmB = fValue;
}

float NCB_MFCexView::NCB_fGetAmB()
{
	return m_fAmB;
}
/////////////////////////////////////////

void NCB_MFCexView::NCB_vSetDi( float fValue )
{
	m_fDi = fValue;
}

float NCB_MFCexView::NCB_fGetDi()
{
	return m_fDi;
}
void NCB_MFCexView::NCB_vSetDiR( float fValue )
{
	m_fDiR = fValue;
}

float NCB_MFCexView::NCB_fGetDiR()
{
	return m_fDiR;
}
void NCB_MFCexView::NCB_vSetDiG( float fValue )
{
	m_fDiG = fValue;
}

float NCB_MFCexView::NCB_fGetDiG()
{
	return m_fDiG;
}
void NCB_MFCexView::NCB_vSetDiB( float fValue )
{
	m_fDiB = fValue;
}

float NCB_MFCexView::NCB_fGetDiB()
{
	return m_fDiB;
}
////////////////////////////////////////
void NCB_MFCexView::NCB_vSetSp( float fValue )
{
	m_fSp = fValue;
}

float NCB_MFCexView::NCB_fGetSp()
{
	return m_fSp;
}
void NCB_MFCexView::NCB_vSetSpR( float fValue )
{
	m_fSpR = fValue;
}

float NCB_MFCexView::NCB_fGetSpR()
{
	return m_fSpR;
}void NCB_MFCexView::NCB_vSetSpG( float fValue )
{
	m_fSpG = fValue;
}

float NCB_MFCexView::NCB_fGetSpG()
{
	return m_fSpG;
}

void NCB_MFCexView::NCB_vSetSpB( float fValue )
{
	m_fSpB = fValue;
}

float NCB_MFCexView::NCB_fGetSpB()
{
	return m_fSpB;
}
//////////////////////////////////////////////

void NCB_MFCexView::NCB_vSetLit( float fValue )
{
	m_flit = fValue;
}

float NCB_MFCexView::NCB_fGetLit()
{

	return m_flit;
}
