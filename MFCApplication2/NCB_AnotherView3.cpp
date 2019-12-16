
#include "stdafx.h"
#include "gl/glut.h"

#ifndef SHARED_HANDLERS
#include "NCB_MFCex.h"
#endif

#include "NCB_MFCexDoc.h"
#include "NCB_MFCexView.h"
#include "NCB_AnotherView3.h"
#include "FVector.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define GL_PI 3.1415f

IMPLEMENT_DYNCREATE( NCB_AnotherView3, NCB_MFCexView )

BEGIN_MESSAGE_MAP( NCB_AnotherView3, NCB_MFCexView )

	ON_COMMAND( ID_FILE_PRINT, &NCB_MFCexView::OnFilePrint )
	ON_COMMAND( ID_FILE_PRINT_DIRECT, &NCB_MFCexView::OnFilePrint )
	ON_COMMAND( ID_FILE_PRINT_PREVIEW, &NCB_MFCexView::OnFilePrintPreview )
	//ON_WM_TIMER()
END_MESSAGE_MAP()


NCB_AnotherView3::NCB_AnotherView3()
{
	
}

NCB_AnotherView3::~NCB_AnotherView3()
{
}

void NCB_AnotherView3::GLRenderScene()
{
	//glLoadIdentity();

	glClearColor( 0, 0, 0, 0 );//¹è°æ»ö
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glEnable( GL_DEPTH_TEST );
	glColorMaterial( GL_FRONT, GL_AMBIENT_AND_DIFFUSE );
	NCB_DrawCube2( );
	
	
}
void NCB_AnotherView3::NCB_DrawCube2()
{

	NCB_CFVector m_vvertex[8];
	NCB_CFVector m_vnormal[8];
	
	m_vvertex[0].NCB_vSet( -10, -10, -10 );
	m_vvertex[1].NCB_vSet( -10, 10, -10 );
	m_vvertex[2].NCB_vSet( 10, 10, -10 );
	m_vvertex[3].NCB_vSet( 10, -10, -10 );
	m_vvertex[4].NCB_vSet( -10, -10, 10 );
	m_vvertex[5].NCB_vSet( -10, 10, 10 );
	m_vvertex[6].NCB_vSet( 10, 10, 10 );
	m_vvertex[7].NCB_vSet( 10, -10, 10 );

	m_vnormal[0].NCB_vSet( -10, -10, -10 );
	m_vnormal[1].NCB_vSet( -10, 10, -10 );
	m_vnormal[2].NCB_vSet( 10, 10, -10 );
	m_vnormal[3].NCB_vSet( 10, -10, -10 );
	m_vnormal[4].NCB_vSet( -10, -10, 10 );
	m_vnormal[5].NCB_vSet( -10, 10, 10 );
	m_vnormal[6].NCB_vSet( 10, 10, 10 );
	m_vnormal[7].NCB_vSet( 10, -10, 10 );


	glBegin(GL_TRIANGLE_STRIP);
	glNormal3fv( m_vvertex[0].NCB_oGetNormal( ) );
	glVertex3fv( m_vvertex[0].NCB_oGetData( ) );
	glVertex3fv( m_vvertex[2].NCB_oGetData( ) );
	glVertex3fv( m_vvertex[1].NCB_oGetData() ); 
	
	glEnd();
	glBegin( GL_TRIANGLE_STRIP );
	glNormal3fv( m_vvertex[0].NCB_oGetNormal() );
	glVertex3fv( m_vvertex[2].NCB_oGetData() );
	glVertex3fv( m_vvertex[0].NCB_oGetData() );
	glVertex3fv( m_vvertex[3].NCB_oGetData() );
	glEnd();
	glBegin( GL_TRIANGLE_STRIP );
	glNormal3fv( m_vvertex[4].NCB_oGetNormal() );
	glVertex3fv( m_vvertex[4].NCB_oGetData() );
	glVertex3fv( m_vvertex[6].NCB_oGetData() );
	glVertex3fv( m_vvertex[5].NCB_oGetData() );
	glEnd();
	glBegin( GL_TRIANGLE_STRIP );
	glNormal3fv( m_vvertex[4].NCB_oGetNormal() );
	glVertex3fv( m_vvertex[4].NCB_oGetData() );
	glVertex3fv( m_vvertex[7].NCB_oGetData() );
	glVertex3fv( m_vvertex[6].NCB_oGetData() );
	glEnd();
	glBegin( GL_TRIANGLE_STRIP );
	glNormal3fv( m_vvertex[0].NCB_oGetNormal() );
	glVertex3fv( m_vvertex[0].NCB_oGetData() );
	glVertex3fv( m_vvertex[4].NCB_oGetData() );
	glVertex3fv( m_vvertex[5].NCB_oGetData() );
	glEnd();
	glBegin( GL_TRIANGLE_STRIP );
	glNormal3fv( m_vvertex[0].NCB_oGetNormal() );
	glVertex3fv( m_vvertex[0].NCB_oGetData() );
	glVertex3fv( m_vvertex[5].NCB_oGetData() );
	glVertex3fv( m_vvertex[1].NCB_oGetData() );
	glEnd();
	glBegin( GL_TRIANGLE_STRIP );
	glNormal3fv( m_vvertex[1].NCB_oGetNormal() );
	glVertex3fv( m_vvertex[1].NCB_oGetData() );
	glVertex3fv( m_vvertex[5].NCB_oGetData() );
	glVertex3fv( m_vvertex[6].NCB_oGetData() );
	glEnd();
	glBegin( GL_TRIANGLE_STRIP );
	glNormal3fv( m_vvertex[1].NCB_oGetNormal() );
	glVertex3fv( m_vvertex[1].NCB_oGetData() );
	glVertex3fv( m_vvertex[6].NCB_oGetData() );
	glVertex3fv( m_vvertex[2].NCB_oGetData() );
	glEnd();
	glBegin( GL_TRIANGLE_STRIP );
	glNormal3fv( m_vvertex[2].NCB_oGetNormal() );
	glVertex3fv( m_vvertex[2].NCB_oGetData() );
	glVertex3fv( m_vvertex[6].NCB_oGetData() );
	glVertex3fv( m_vvertex[7].NCB_oGetData() );
	glEnd();
	glBegin( GL_TRIANGLE_STRIP );
	glNormal3fv( m_vvertex[2].NCB_oGetNormal() );
	glVertex3fv( m_vvertex[2].NCB_oGetData() );
	glVertex3fv( m_vvertex[7].NCB_oGetData() );
	glVertex3fv( m_vvertex[3].NCB_oGetData() );
	glEnd();
	glBegin( GL_TRIANGLE_STRIP );
	glNormal3fv( m_vvertex[3].NCB_oGetNormal() );
	glVertex3fv( m_vvertex[3].NCB_oGetData() );
	glVertex3fv( m_vvertex[7].NCB_oGetData() );
	glVertex3fv( m_vvertex[4].NCB_oGetData() );
	glEnd();
	glBegin( GL_TRIANGLE_STRIP );
	glNormal3fv( m_vvertex[3].NCB_oGetNormal() );
	glVertex3fv( m_vvertex[3].NCB_oGetData() );
	glVertex3fv( m_vvertex[4].NCB_oGetData() );
	glVertex3fv( m_vvertex[0].NCB_oGetData() );
	glEnd();
}
void NCB_AnotherView3::NCB_DrawCube()
{
	
}