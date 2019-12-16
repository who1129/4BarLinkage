
#pragma once

#include "NCB_MFCexView.h"

class NCB_AnotherView2 : public NCB_MFCexView
{
protected:
	NCB_AnotherView2();
	DECLARE_DYNCREATE(NCB_AnotherView2)

public:
	NCB_MFCexDoc* GetDocument() const;
	virtual void GLRenderScene();
	//구 GL_TRIANGLE_STRIP 그리기 함수
	void NCB_vDrawSphere();
	void NCB_vDrawSphereGLU();
public:
 	virtual ~NCB_AnotherView2();
#ifdef _DEBUG
#endif

protected:
	float m_fradius ;
	float m_ftheta;
	float m_fphi;
	float m_fdelta_theta;
	float m_fdelta_phi;


protected:
	DECLARE_MESSAGE_MAP()
};
