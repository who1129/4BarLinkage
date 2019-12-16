#pragma once

#include "NCB_MFCexView.h"

class NCB_AnotherView3 : public NCB_MFCexView
{
protected:
	NCB_AnotherView3();
	DECLARE_DYNCREATE( NCB_AnotherView3 )

public:
	NCB_MFCexDoc* GetDocument() const;
	virtual void GLRenderScene();
	void NCB_DrawCube( );
	void NCB_DrawCube2( );
public:
	virtual ~NCB_AnotherView3();
#ifdef _DEBUG
#endif

protected:
	GLfloat m_vertex[8][3];
protected:
	DECLARE_MESSAGE_MAP()
public:

};
