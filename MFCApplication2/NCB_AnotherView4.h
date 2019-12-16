
#pragma once
#include "NCB_MFCexView.h"

class NCB_AnotherView4 : public NCB_MFCexView
{
protected: 
	NCB_AnotherView4();
	DECLARE_DYNCREATE(NCB_AnotherView4)

public:
	NCB_MFCexDoc* GetDocument() const;
	//View에 형상전달 함수
	virtual void GLRenderScene();
	//원그리기 GL_POINTS사용 함수
	void NCB_vDrawCirclePOINT();
	//원그리기 GL_LINES사용 함수
	void NCB_vDrawCircleLINES();
	//원그리기 GL_LINE_STRIP사용 함수
	void NCB_vDrawCircleLINEST();
	//원그리기 GL_LINE_LOOP사용 함수
	void NCB_vDrawCircleLINELO();
	//원그리기 GL_LINE_POLYGON사용 함수
	void NCB_vDrawCirclePOLY();
	//정육면체 그리기 GL_LINES 사용 함수
	void NCB_vDrawCube();
	//원기둥 그리기 함수
	void NCB_vDrawCylinder();
	
 public:
 	virtual ~NCB_AnotherView4();
#ifdef _DEBUG
#endif

protected:

protected:
	DECLARE_MESSAGE_MAP()
};
