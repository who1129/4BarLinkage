
#include "stdafx.h"

#ifndef SHARED_HANDLERS
#include "NCB_MFCex.h"
#endif
#include "gl/GL.h"
#include "gl/GLU.h"
#include "gl/glut.h"
#include <math.h>

#include "NCB_MFCexDoc.h"
#include "NCB_MFCexView.h"
#include "NCB_AnotherView2.h"
#include "FVector.h"

# define PI 3.141592
#define M 100
#define N 100


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE( NCB_AnotherView2, NCB_MFCexView )

BEGIN_MESSAGE_MAP( NCB_AnotherView2, NCB_MFCexView )

	ON_COMMAND( ID_FILE_PRINT, &NCB_MFCexView::OnFilePrint )
	ON_COMMAND( ID_FILE_PRINT_DIRECT, &NCB_MFCexView::OnFilePrint )
	ON_COMMAND( ID_FILE_PRINT_PREVIEW, &NCB_MFCexView::OnFilePrintPreview )
END_MESSAGE_MAP()

NCB_AnotherView2::NCB_AnotherView2()
{
	m_fradius = 25.f;
	m_fSize = 150.f;
}


NCB_AnotherView2::~NCB_AnotherView2()
{
}

void NCB_AnotherView2::GLRenderScene()
{
	//glLoadIdentity();

	//glClearColor( 0, 0, 0, 0 );//배경색
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glEnable( GL_DEPTH_TEST );
	//glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );

	NCB_vDrawSphere();
	//NCB_vDrawSphereGLU();
}

/**
* @brief : 구 GL_LINE_STRIP그리기 함수
* @date  : 2017-3-29 12:46
* @return:   void
*/
void NCB_AnotherView2::NCB_vDrawSphere()
{
	//glPushMatrix( );

	glBegin( GL_LINE_STRIP );  // X, Y, Z 선 표시  
	glColor3f( 1.0, 0.0, 0.0 ); // X축   
	glVertex3f( 0.0, 0.0, 0.0 );
	glVertex3f( 50.0, 0.0, 0.0 );

	glColor3f( 0.0, 1.0, 0.0 ); // Y축   
	glVertex3f( 0.0, 0.0, 0.0 );
	glVertex3f( 0.0, 50.0, 0.0 );

	glColor3f( 0.0, 0.0, 1.0 ); // Z축   
	glVertex3f( 0.0, 0.0, 0.0 );
	glVertex3f( 0.0, 0.0, 50.0 );
	glEnd();


	m_fdelta_theta = 2.f * PI / M;
	m_fdelta_phi = PI / N;

	NCB_CFVector vertex[( M + 1 ) * ( N + 1 )];
	NCB_CFVector normal[( M + 1 ) * ( N + 1 )];

	for( int j = 0; j <= N; j++ )
	{
		for( int i = 0; i <= M; i++ )
		{
			m_ftheta = i * m_fdelta_theta;
			m_fphi = j * m_fdelta_phi - ( PI / 2 );

			float fdata[3];

			fdata[0] = m_fradius * cos( m_ftheta ) * cos( m_fphi );
			fdata[1] = m_fradius * sin( m_ftheta ) * cos( m_fphi );
			fdata[2] = m_fradius * sin( m_fphi );

			vertex[( M + 1 ) *j + i].NCB_vSet( fdata[0], fdata[1], fdata[2] );
			normal[( M + 1 ) *j + i].NCB_vSet( fdata[0], fdata[1], fdata[2] );
		}
	}

//glColor3f( 1.0, 0.0, 0.0 );
	for( int j = 0; j < N; j++ )
	{
		
		glBegin( GL_TRIANGLE_STRIP );
		
		for( int i = 0; i <= M; i++ )
		{
			int nindex, nnextindex, nleft;
			nindex = ( M + 1 ) * j + i;
			nleft = nindex + 1;
			nnextindex = ( M + 1 ) *( j + 1 ) + i;
			glColor3f( i*0.01, j*0.01, 1-i+j*0.01 );
			glNormal3fv( vertex[nindex].NCB_oGetNormal() );
			glVertex3fv( vertex[nindex].NCB_oGetData() );
			glNormal3fv( vertex[nnextindex].NCB_oGetNormal( ) );
			glVertex3fv( vertex[nnextindex].NCB_oGetData() );

		}
		glEnd();
	}

}

void NCB_AnotherView2::NCB_vDrawSphereGLU()
{

	GLUquadric* quad;
	quad = gluNewQuadric();

	glColor3f( 0.3f, 0.3f, 0.3f );
	gluQuadricDrawStyle( quad, GLU_FILL );
	gluSphere( quad, 4, 40, 10 );
}