
#pragma once
#include "NCB_MFCexView.h"

class NCB_AnotherView4 : public NCB_MFCexView
{
protected: 
	NCB_AnotherView4();
	DECLARE_DYNCREATE(NCB_AnotherView4)

public:
	NCB_MFCexDoc* GetDocument() const;
	//View�� �������� �Լ�
	virtual void GLRenderScene();
	//���׸��� GL_POINTS��� �Լ�
	void NCB_vDrawCirclePOINT();
	//���׸��� GL_LINES��� �Լ�
	void NCB_vDrawCircleLINES();
	//���׸��� GL_LINE_STRIP��� �Լ�
	void NCB_vDrawCircleLINEST();
	//���׸��� GL_LINE_LOOP��� �Լ�
	void NCB_vDrawCircleLINELO();
	//���׸��� GL_LINE_POLYGON��� �Լ�
	void NCB_vDrawCirclePOLY();
	//������ü �׸��� GL_LINES ��� �Լ�
	void NCB_vDrawCube();
	//����� �׸��� �Լ�
	void NCB_vDrawCylinder();
	
 public:
 	virtual ~NCB_AnotherView4();
#ifdef _DEBUG
#endif

protected:

protected:
	DECLARE_MESSAGE_MAP()
};
