
#include "stdafx.h"
#include <math.h>
#ifndef SHARED_HANDLERS
#include "NCB_MFCex.h"
#endif

#include "NCB_MFCexDoc.h"
#include "NCB_MFCexView.h"
#include "NCB_AnotherView4.h"

# define PI 3.141592

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE( NCB_AnotherView4, NCB_MFCexView )

BEGIN_MESSAGE_MAP( NCB_AnotherView4, NCB_MFCexView )

	ON_COMMAND( ID_FILE_PRINT, &NCB_MFCexView::OnFilePrint )
	ON_COMMAND( ID_FILE_PRINT_DIRECT, &NCB_MFCexView::OnFilePrint )
	ON_COMMAND( ID_FILE_PRINT_PREVIEW, &NCB_MFCexView::OnFilePrintPreview )
END_MESSAGE_MAP()


NCB_AnotherView4::NCB_AnotherView4()
{
}

NCB_AnotherView4::~NCB_AnotherView4()
{
}

/**
* @brief : View에 형상전달 함수
* @date  : 2017-3-22 15:05
* @return:   void
*/
void NCB_AnotherView4::GLRenderScene()
{
	//glLoadIdentity();

	glClearColor( 0, 0, 0, 0 );
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glEnable( GL_DEPTH_TEST );
	glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );

	NCB_vDrawCylinder();
	
}

/**
* @brief : 원그리기 GL_POINNT사용 함수
* @date  : 2017-3-22 14:44
* @return:   void
*/
void NCB_AnotherView4::NCB_vDrawCirclePOINT()
{
	GLfloat r = 8;
	GLfloat x = 0.0f;
	GLfloat y = 0.0f;
	glPointSize( 2 );
	glBegin( GL_POINTS );
	glColor3f( 1.0f, 0.0f, 0.0f );
	for( GLfloat i = 0; i < 360; i += 15 )
	{

		GLfloat degree = i*PI / 180; // degree변환
		x = r*cos( degree );
		y = r*sin( degree );
		glVertex3f( x, y, 0.0f );
	}
	glEnd();
	glFlush();
}

/**
* @brief : 원그리기 GL_LINES사용 함수
* @date  : 2017-3-22 15:12
* @return:   void
*/
void NCB_AnotherView4::NCB_vDrawCircleLINES()
{
	GLfloat r = 30;
	GLfloat x = 0.0f;
	GLfloat y = 0.0f;
	glPointSize( 2 );
	glBegin( GL_LINES );
	glColor3f( 1.0f, 0.0f, 0.0f );
	for( GLfloat i = 0; i < 360; i += 15 )
	{

		GLfloat degree = i*PI / 180; // degree변환
		x = r*cos( degree );
		y = r*sin( degree );
		glVertex3f( x, y, 0.0f );
	}
	glEnd();
	glFlush();
}
/**
* @brief : 원그리기 GL_LINE_STRIP사용 함수
* @date  : 2017-3-22 15:12
* @return:   void
*/
void NCB_AnotherView4::NCB_vDrawCircleLINEST()
{
	GLfloat r = 30;
	GLfloat x = 0.0f;
	GLfloat y = 0.0f;
	glPointSize( 2 );
	glBegin( GL_LINE_STRIP );
	glColor3f( 1.0f, 0.0f, 0.0f );
	glVertex3f( 0.0f, 0.0f, 0.0f );
	for( GLfloat i = 1; i <= 360; i += 15 )
	{

		GLfloat degree = i*PI / 180; // degree변환
		x = r*cos( degree );
		y = r*sin( degree );
		glVertex3f( x, y, 0.0f );
	}
	glEnd();
	glFlush();
}
/**
* @brief : 원그리기 GL_LINE_LOOP사용 함수
* @date  : 2017-3-22 15:12
* @return:   void
*/
void NCB_AnotherView4::NCB_vDrawCircleLINELO()
{
	GLfloat r = 30;
	GLfloat x = 0.0f;
	GLfloat y = 0.0f;
	glPointSize( 2 );
	glBegin( GL_LINE_LOOP );
	glColor3f( 1.0f, 0.0f, 0.0f );

	for( GLfloat i = 0; i <= 360; i += 15 )
	{

		GLfloat degree = i*PI / 180; // degree변환
		x = r*cos( degree );
		y = r*sin( degree );
		glVertex3f( x, y, 0.0f );
	}
	glEnd();
	glFlush();
}

/**
* @brief : 원그리기 GL_POLTGON 사용 함수
* @date  : 2017-3-23 08:42
* @return:   void
*/
void NCB_AnotherView4::NCB_vDrawCirclePOLY()
{
	GLfloat r = 30;
	GLfloat x = 0.0f;
	GLfloat y = 0.0f;
	glPointSize( 2 );
	glBegin( GL_POLYGON );


	for( GLfloat i = 0; i <= 360; i += 15 )
	{

		GLfloat degree = i*PI / 180; // degree변환
		x = r*cos( degree );
		y = r*sin( degree );
		glColor3f( x, 0.0f, 0.0f );
		glVertex3f( x, y, 0.0f );
	}
	glEnd();
	glFlush();

}
/**
* @brief : 정육면체 그리기 GL_LINES 사용 함수
* @date  : 2017-3-22 15:06
* @return:   void
*/
void NCB_AnotherView4::NCB_vDrawCube()
{
	glBegin( GL_LINE_STRIP );

	glColor3f( 0.0f, 0.0f, 1.0f ); //BLUE 
	glVertex3f( 0.0f, 0.0f, 0.0f );

	glColor3f( 0.0f, 1.0f, 1.0f ); //BLUE 
	glVertex3f( 20.0f, 0.0f, 0.0f );

	glColor3f( 1.0f, 0.0f, 0.0f ); //RED
	glVertex3f( 20.0f, -20.0f, 0.0f );

	glColor3f( 0.0f, 1.0f, 0.0f );
	glVertex3f( 0.0f, -20.0f, 0.0f );

	glColor3f( 0.0f, 0.0f, 1.0f ); //BLUE 
	glVertex3f( 0.0f, 0.0f, 0.0f );


	glColor3f( 0.0f, 0.0f, 1.0f ); //BLUE 
	glVertex3f( 0.0f, 0.0f, -20.0f );

	glColor3f( 0.0f, 1.0f, 1.0f ); //BLUE 
	glVertex3f( 20.0f, 0.0f, -20.0f );

	glColor3f( 1.0f, 0.0f, 0.0f ); //RED
	glVertex3f( 20.0f, -20.0f, -20.0f );

	glColor3f( 0.0f, 1.0f, 0.0f );
	glVertex3f( 0.0f, -20.0f, -20.0f );

	glColor3f( 0.0f, 0.0f, 1.0f ); //BLUE 
	glVertex3f( 0.0f, 0.0f, -20.0f );

	glEnd();

	glBegin( GL_LINES );
	glColor3f( 1.0f, 0.0f, 0.0f ); //RED
	glVertex3f( 20.0f, 0.0f, 0.0f );
	glVertex3f( 20.0f, 0.0f, -20.0f );
	glEnd();

	glBegin( GL_LINES );
	glColor3f( 1.0f, 0.0f, 0.0f ); //RED
	glVertex3f( 20.0f, -20.0f, 0.0f );
	glVertex3f( 20.0f, -20.0f, -20.0f );
	glEnd();

	glBegin( GL_LINES );
	glColor3f( 1.0f, 0.0f, 0.0f ); //RED
	glVertex3f( 0.0f, -20.0f, 0.0f );
	glVertex3f( 0.0f, -20.0f, -20.0f );
	glEnd();
}
/**
* @brief : 원기둥 함수
* @date  : 2017-3-22 15:06
* @return:   void
*/
//void NCB_AnotherView4::NCB_vDrawCylinder()
//{
//	glRotatef(90, 0, 1, 0);
//	float degree = 3.1415 / 180;
//	
//	 float x, y, x0, y0, r, theta, h0;
//	 x0 = 0.f; y0 = 0.f; r = 10.f, h0 = 30.f;
//	 glRotatef(90.f, 0.f, 0.f, 1.f);
//	 glBegin( GL_TRIANGLE_STRIP );
//	 glBegin( GL_LINES );
//	
//	 glColor3f( 1.0f, 0.0f, 0.0f );
//	
//	 for (int j = 0; j <= 360; j += 20)
//	 {
//	  theta = j * degree;
//	
//	  x = x0 + r * cos( theta );
//	  y = y0 + r * sin( theta );
//	
//	  glVertex3f( x, y, h0 );
//	  glVertex3f( x, y, 0 );
//	 }
//	 glEnd();
//}



void NCB_AnotherView4::NCB_vDrawCylinder()
{
	glBegin( GL_LINES );
	glColor3f( 1, 0, 0 );
	glVertex3f( 0, 0, 0 );
	glVertex3f( 0, 50, 0 );

	glColor3f( 0, 1, 0 );
	glVertex3f( 0, 0, 0 );
	glVertex3f( 50, 0, 0 );

	glColor3f( 0, 0, 1 );
	glVertex3f( 0, 0, 0 );
	glVertex3f( 0, 0, 50 );

	glEnd();
	/* function createCyliner()
	원기둥의 중심 x,y,z좌표, 반지름, 높이를 받아 원기둥을 생성하는 함수(+z방향으로 원에서 늘어남)
	centerx : 원기둥 원의 중심 x좌표
	centery : 원기둥 원의 중심 y좌표
	centerz : 원기둥 원의 중심 z좌표
	radius : 원기둥의 반지름
	h : 원기둥의 높이
	*/
	float centerx = 0.0f;
	float centery = 0.0f;
	float centerz = 0.0f;
	float radius = 5.0f; 
	float h = 20.0f;
	float x, y, angle;

	/*glBegin( GL_TRIANGLE_STRIP );//원기둥의 윗면

	glNormal3f( 0.0f, 0.0f, -1.0f );
	glColor3ub( 100, 100, 19 );
	glVertex3f( centerx, centery, centerz );

	for( angle = 0.0f; angle < ( 2.0f*PI ); angle += ( PI / 8.0f ) )
	{
		x = centerx + radius*sin( angle );
		y = centery + radius*cos( angle );
		glNormal3f( 0.0f, 0.0f, -1.0f );
		glVertex3f( x, y, centerz );
	}
	
	glEnd();
*/

	glBegin( GL_TRIANGLE_FAN );           //원기둥의 밑면
	glNormal3f( 0.0f, 0.0f, 1.0f );
	glVertex3f( centerx, centery, centerz + h );
	for( angle = ( 2.0f*PI ); angle >= 0.0f; angle -= ( PI / 8.0f ) )
	{
		x = centerx + radius*sin( angle );
		y = centery + radius*cos( angle );
		glNormal3f( 0.0f, 0.0f, 20.0f );
		glVertex3f( x, y, centerz + h );
	}
	glEnd();

	glBegin( GL_QUAD_STRIP ); //원기둥의 옆면
	glColor3ub( 100, 0, 0 );
	for( angle = 0.0f; angle < ( 2.0f*PI ); angle += ( PI / 8.0f ) )
	{
		x = centerx + radius*sin( angle );
		y = centery + radius*cos( angle );
		glNormal3f( sin( angle ), cos( angle ), 0.0f );
		glVertex3f( x, y, centerz );
		glVertex3f( x, y, centerz + h );
	}
	glEnd();

	glBegin( GL_TRIANGLE_FAN );           //원기둥의 밑면
	glNormal3f( 0.0f, 0.0f, 1.0f );
	glVertex3f( centerx, centery, centerz + h );
	for( angle = ( 2.0f*PI ); angle >= 0.0f; angle -= ( PI / 8.0f ) )
	{
		x = centerx + radius*sin( angle );
		y = centery + radius*cos( angle );
		glNormal3f( 0.0f, 0.0f, 1.0f );
		glVertex3f( x, y, centerz + h );
	}
	glEnd();
}
