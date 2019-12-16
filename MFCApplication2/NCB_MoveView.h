
#pragma once

#include <gl/GL.h>
#include <gl/GLU.h>
#include <atltypes.h>
#include <windows.h>
class NCB_CMoveView
{
	NCB_CMoveView();
	~NCB_CMoveView();
public:
	
	void NCB_vRotMatrix(GLfloat angle, GLfloat x, GLfloat y, GLfloat z);
	void OnLButtonDown(UINT nFlags, CPoint point);
	void OnLButtonUp(UINT nFlags, CPoint point);
	void OnMouseMove(UINT nFlags, CPoint point);
	void LookVec();
	void LeftVec();

protected:
	GLfloat pos[3];
	GLfloat lookAt[3];
	GLfloat upVec[3];
	GLfloat g_aRotating[3][3];
	GLfloat m_x;
	GLfloat m_y;
	GLfloat m_on;
	GLfloat lookVec[3];
	GLfloat leftVec[3];


};