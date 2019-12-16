
#include "stdafx.h"
#include <gl/GL.h>
#include <gl/GLU.h>

#ifndef SHARED_HANDLERS
#endif

#include "NCB_MFCexDoc.h"
#include "NCB_MFCexView.h"
#include "NCB_AnotherView1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define  RADIAN(x) (x*(3.1415/180))
#define  DEGREE(x) (x*(180/3.1415))
#define  ODEGPLUS 1
#define  PI 3.141592

IMPLEMENT_DYNCREATE( NCB_AnotherView1, NCB_MFCexView )

BEGIN_MESSAGE_MAP( NCB_AnotherView1, NCB_MFCexView )
	ON_WM_TIMER( )
	ON_WM_DESTROY( )
END_MESSAGE_MAP( )

NCB_AnotherView1::NCB_AnotherView1()
{
	m_hWnd = NULL;
	m_hDC = NULL;
	m_hRC = NULL;

	//길이
	m_fFrame = 50;
	m_fCrank = 30;
	m_fCoupler = 50;
	m_fRocker = 40;
	m_fDiagonal = 0;

	//원점
	m_fO[0] = 0.0f;
	m_fO[1] = 0.0f;
	m_fO[2] = 0.0f;

	//각
	m_fOdeg = 1;
	}

	NCB_AnotherView1::~NCB_AnotherView1()
	{

	}

	void NCB_AnotherView1::GLRenderScene()
	{
		//glPolygonMode( GL_FRONT_AND_BACK, GL_LINE );
		//glLoadIdentity( );

		glClearColor( 0, 0, 0, 0 );//배경색
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

		glEnable( GL_DEPTH_TEST );
		glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );

		NCB_Coord();
		//gluLookAt( 0.0f, 0.0f, 100.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f );
		//glOrtho( m_fLeft, m_fRight, m_fBottom, m_fTop, m_fSize, -m_fSize );
		NCB_vDraw4BarLinkCylinder();

	
	}
	void NCB_AnotherView1::NCB_Coord()
	{
		glBegin( GL_LINES );

		// X
		glColor3f( 0, 0, 1 );
		glVertex3f( 0, 0, 0 );
		glVertex3f( 50, 0, 0 );

		// Y
		glColor3f( 0, 1, 0 );
		glVertex3f( 0, 0, 0 );
		glVertex3f( 0, 50, 0 );
		
		// Z
		glColor3f( 1, 0, 0 );
		glVertex3f( 0, 0, 0 );
		glVertex3f( 0, 0, 50 );

		glEnd();
	}
	/**
	* @brief :4절링크 그릴 때 필요한 대각선, 알파, 베타 계산
	* @date  : 2017-4-18 16:31
	* @return:   void
	*/
	void NCB_AnotherView1::NCB_vCalc4BarLink()
	{
		//diagonal 계산
		float m_fDiagonalPara;
		m_fDiagonalPara = pow( m_fFrame, 2 ) + pow( m_fCrank, 2 ) - ( 2 * m_fFrame * m_fCrank * cos( RADIAN( m_fOdeg ) ) );
		m_fDiagonal = sqrt( m_fDiagonalPara );

		//알파값, 베타값 계산
		float m_fAldegPara = ( pow( m_fCrank, 2 ) - pow( m_fDiagonal, 2 ) - pow( m_fFrame, 2 ) ) / ( ( -2 ) * m_fDiagonal * m_fFrame );
		m_fAldeg = acosf( m_fAldegPara );
		//m_fAldeg = DEGREE(m_fAldeg);

		float m_fBedegPara = ( pow( m_fCoupler, 2 ) - pow( m_fDiagonal, 2 ) - pow( m_fRocker, 2 ) ) / ( ( -2 ) * m_fDiagonal * m_fRocker );
		m_fBedeg = acosf( ( m_fBedegPara ) );
		//m_fBedeg = DEGREE(m_fBedeg);

	}

	/**
	* @brief : 각 변 사이에 끼인 각 구함. rotate할 때 씀.
	* @date  : 2017-4-26 10:59
	* @return:   float
	* @param[in]: float * s
	* @param[in]: float * e
	*/
	float NCB_AnotherView1::NCB_fGetAngle( float* p1, float* p2 )
	{
		float diff[3];
		float angle;

		diff[0] = p1[0] - p2[0];//x
		diff[1] = p1[1] - p2[1];//y

		angle = atan2f( diff[1], diff[0] );//radian

		return angle * 180.f / 3.1415;//degree로 리턴

	}

	//* @brief :원기둥을 기울이는 함수
	void NCB_AnotherView1::NCB_vRotateBar( float* point, float angle )
	{
		glTranslatef( point[0], point[1], point[2] );
		glRotatef( angle, 0, 0, 1 );
		glRotatef( 90, 0, 1, 0 );
		/*
			중심점이 좌표계 원점에 일치하도록 물체를 이동한다.
			물체를 원점 중심으로 회전한다.
			회전된 물체를 다시 원래의 위치로 이동한다.
			*/
	}

	/**
	* @brief : 끼인각 계산함수 호출하여 저장.
	* @date  : 2017-4-26 13:35
	* @return:   void
	*/
	void NCB_AnotherView1::NCB_vIncludedAngle()
	{
		m_fAngleA = NCB_fGetAngle( m_fO, m_fA );
		m_fAngleB = NCB_fGetAngle( m_fA, m_fB );
		m_fAngleC = NCB_fGetAngle( m_fB, m_fC );
	}
	/**
	* @brief : 4절링크 a,b,c점 정보 계산
	* @date  : 2017-4-30 16:31
	* @return:   void
	*/
	void NCB_AnotherView1::NCB_v4BarPoint()
	{
		NCB_vCalc4BarLink();

		//a점
		m_fA[0] = m_fCrank * cos( RADIAN( m_fOdeg ) );
		m_fA[1] = m_fCrank * sin( RADIAN( m_fOdeg ) );
		m_fA[2] = 0.0f;

		//b점
		if( m_fOdeg < 180 )
		{
			float m_fBxPara = 3.14 - ( m_fAldeg + m_fBedeg );
			m_fB[0] = m_fC[0] + m_fRocker * cos( m_fBxPara );
			float m_fByPara = 3.14 - ( m_fAldeg + m_fBedeg );
			m_fB[1] = m_fC[1] + m_fRocker * sin( m_fByPara );
			m_fB[2] = 0.0f;
		}
		else
		{
			float m_fBxPara = 3.14 + ( m_fAldeg - m_fBedeg );
			m_fB[0] = m_fC[0] + m_fRocker * cos( m_fBxPara );
			float m_fByPara = 3.14 + ( m_fAldeg - m_fBedeg );
			m_fB[1] = m_fC[1] + m_fRocker * sin( m_fByPara );
			m_fB[2] = 0.0f;
		}

		//c점
		m_fC[0] = m_fFrame;
		m_fC[1] = 0.0f;
		m_fC[2] = 0.0f;

		NCB_vIncludedAngle();
	}

	/**
	* @brief : 4절링크 점 정보에 따라서 선으로 그리는 부분
	* @date  : 2017-3-30 10:31
	* @return:   void
	*/
	void NCB_AnotherView1::NCB_vDraw4BarLink()
	{
		glColor3f( 1.0, 1.0, 1.0 );

		glBegin( GL_LINES );
		glVertex3f( m_fO[0], m_fO[1], m_fO[2] );//o
		glVertex3f( m_fA[0], m_fA[1], m_fA[2] );

		glColor3f( 1.0, 0.0, 1.0 );
		glVertex3f( m_fA[0], m_fA[1], m_fA[2] );//a
		glVertex3f( m_fB[0], m_fB[1], m_fB[2] );

		glColor3f( 1.0, 1.0, 0.0 );
		glVertex3f( m_fB[0], m_fB[1], m_fB[2] );//b
		glVertex3f( m_fC[0], m_fC[1], m_fC[2] );

		glColor3f( 0.0, 0.5, 1.0 );
		glVertex3f( m_fC[0], m_fC[1], m_fC[2] );//c
		glVertex3f( m_fO[0], m_fO[1], m_fO[2] );

		glEnd();
	}

	/**
	* @brief : 4절링크 점 정보를 가지고 그리는부분
	* @date  : 2017-4-21 16:32
	* @return:   void
	*/
	void NCB_AnotherView1::NCB_vDraw4BarLinkCylinder()
	{

		//frame
		glPushMatrix();
		glColor3f( 1.0, 1.0, 1.0 );
		glRotatef( 90, 0, 1, 0 );
		//NCB_vMakeCylinder( m_fO, m_fA, m_fFrame );
		NCB_vMakeCylinderGLU( m_fFrame );
		NCB_vMakeSphereGLU();
		glPopMatrix();

		//crank
		glPushMatrix();
		glColor3f( 1.0, 0.0, 1.0 );
		glTranslatef( 0, 0, -4 );
		NCB_vRotateBar( m_fA, m_fAngleA );
		//NCB_vMakeCylinder( m_fA, m_fB, m_fCrank );
		NCB_vMakeCylinderGLU( m_fCrank );
		NCB_vMakeSphereGLU();
		glPopMatrix();

		//coupler
		glPushMatrix();
		glColor3f( 1.0, 1.0, 0.0 );
		glTranslatef( 0, 0, -8 );
		NCB_vRotateBar( m_fB, m_fAngleB );
		//NCB_vMakeCylinder( m_fB, m_fC, m_fCoupler );
		NCB_vMakeCylinderGLU( m_fCoupler );
		NCB_vMakeSphereGLU();
		glPopMatrix();

		//rocker
		glPushMatrix();
		glColor3f( 0.0, 0.5, 1.0 );
		glTranslatef( 0, 0, -4 );
		NCB_vRotateBar( m_fC, m_fAngleC );
		//NCB_vMakeCylinder( m_fC, m_fO, m_fRocker );
		NCB_vMakeCylinderGLU( m_fRocker );
		NCB_vMakeSphereGLU();
		glPopMatrix();
	}

	/**
	* @brief : 원기둥을 그려주는 곳.
	* @date  : 2017-4-21 17:33
	* @return:   void
	* @param[in]: float m_getStart[]
	* @param[in]: float m_getEnd[]
	* @param[in]: float m_height
	*/
	void NCB_AnotherView1::NCB_vMakeCylinder( float* ps, float* pe, float m_height )
	{

		float radius = 2.0f;
		float x, y, angle;
		////////////////////////////////////////////////////////////////////
		//glBegin( GL_TRIANGLE_STRIP );           //원기둥의 윗면
		//
		//glNormal3f( 0.0f, 0.0f, -1.0f );
		//glColor3ub( 255, 100, 255 );
		//glVertex3f( ps[0], ps[1], ps[2] );
		// 
		//for( angle = 0.0f; angle < ( 2.0f*PI ); angle += ( PI / 8.0f ) )
		//{
		//	x = ps[0] + radius*sin( angle );
		//	y = ps[1] + radius*cos( angle );
		//	glNormal3f( 0.0f, 0.0f, -1.0f );
		//	glVertex3f( x, y, ps[2] );
		//}
		//glEnd();
		////////////////////////////////////////////////////////////////

		glBegin( GL_TRIANGLE_STRIP ); //원기둥의 옆면
		for( angle = 0.0f; angle < ( 2.0f*PI ); angle += ( PI / 8.0f ) )
		{
			x = ps[0] + radius*sin( angle );
			y = ps[1] + radius*cos( angle );
			glNormal3f( sin( angle ), cos( angle ), 0.0f );
			glVertex3f( x, y, ps[2] );
			glVertex3f( x, y, ps[2] + m_height );
		}
		glEnd();

		////////////////////////////////////////////////////////////////////
		//glBegin( GL_TRIANGLE_FAN );//원기둥의 밑면
		//glColor3ub( 153, 204, 140 );
		//glNormal3f( 0.0f, 0.0f, 1.0f );
		//glVertex3f( ps[0], ps[1], ps[2] + m_height );
		//for( angle = ( 2.0f*PI ); angle > 0.0f; angle -= ( PI / 8.0f ) )
		//{
		//	x = ps[0] + radius*sin( angle );
		//	y = ps[1] + radius*cos(  angle );
		//	glNormal3f( 0.0f, 0.0f, 1.0f );
		//	glVertex3f( x, y, ps[2] + m_height );
		//}
		//glEnd();
		////////////////////////////////////////////////////////////////////

		glFlush();

	}

	/**
	* @brief : GLU함수를 이용해 원기둥을 그려주는 곳
	* @date  : 2017-5-4 10:39
	* @return:   void
	* @param[in]: float height
	*/

	void NCB_AnotherView1::NCB_vMakeCylinderGLU( float height )
	{
		GLUquadric* quad;
		quad = gluNewQuadric();

		gluQuadricDrawStyle( quad, GLU_FILL );
		gluCylinder( quad, 2, 2, height, 10, 10 );
	}

	/**
	* @brief : GLU함수를 이용해 구체를 그려주는 곳
	* @date  : 2017-5-4 10:42
	* @return:   void
	*/
	void NCB_AnotherView1::NCB_vMakeSphereGLU()
	{
		GLUquadric* quad;
		quad = gluNewQuadric();

		glColor3f( 0.5f, 0.5f, 0.5f );
		gluQuadricDrawStyle( quad, GLU_FILL );
		gluSphere( quad, 4, 10, 10 );
	}

	/**
	* @brief : 4절링크 돌리기 위한 타이머 함수
	* @date  : 2017-4-26 10:50
	* @return:   void
	* @param[in]: UINT nIDEvent
	*/
	void NCB_AnotherView1::OnTimer( UINT nIDEvent )
	{
		switch( nIDEvent )
		{
		case ODEGPLUS:
			if( m_fOdeg >= 360 )
			{
				m_fOdeg = 0;
			}

			m_fOdeg++;

			NCB_v4BarPoint();

			break;
		default:
			break;
		}

		NCB_ReDraw();
	}

	void NCB_AnotherView1::NCB_vStartTimer( void )
	{
		SetTimer( ODEGPLUS, 100, NULL );
	}

	void NCB_AnotherView1::OnDestroy()
	{
		NCB_MFCexView::OnDestroy();
		KillTimer( ODEGPLUS );
	}


