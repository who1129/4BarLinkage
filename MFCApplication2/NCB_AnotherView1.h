#pragma once

#include "NCB_MFCexView.h"
#include "FVector.h"

class NCB_CFVector;

struct Points
{
	float fx = 0;
	float fy = 0;
	float fz = 0;
};
class NCB_AnotherView1 : public NCB_MFCexView
{
protected:
	NCB_AnotherView1();
	afx_msg void OnRButtonDown( UINT nFlags, CPoint point );
	afx_msg void OnRButtonUp( UINT nFlags, CPoint point );
	afx_msg void OnLButtonDown( UINT nFlags, CPoint point );
	afx_msg void OnLButtonUp( UINT nFlags, CPoint point );
	afx_msg void OnMouseMove( UINT nFlags, CPoint point );
	afx_msg BOOL OnMouseWheel( UINT nFlags, short zDelta, CPoint pt );
	//afx_msg BOOL DoMouseWheel( nFlags, zDelta, pt );

DECLARE_DYNCREATE( NCB_AnotherView1 );
public:
	NCB_MFCexDoc* GetDocument() const;

	virtual void GLRenderScene();

	//4����ũ �׸� �� �ʿ��� �밢��, ����, ��Ÿ ���
	void NCB_vCalc4BarLink();
	
	//�� �� ���̿� ���� �� ����. rotate�� �� ��.
	float NCB_fGetAngle( float* p1, float* p2 );
	
	//������� ����̴� �Լ�
	void NCB_vRotateBar( float* point, float angle );
	
	// ���ΰ� ����Լ� ȣ���Ͽ� ����.
	void NCB_vIncludedAngle();
	
	//4����ũ a,b,c�� ���� ���
	void NCB_v4BarPoint();
	
	//4����ũ �� ������ ���� ������ �׸��� �κ� 
	void NCB_vDraw4BarLink( void );
	
	//4����ũ �� ������ ������ �׸��ºκ�
	void NCB_vDraw4BarLinkCylinder( void );
	
	//������� �׷��ִ� ��.
	void NCB_vMakeCylinder( float* ps, float* pe, float m_height );

	//GLU�Լ��� �̿��� ������� �׷��ִ� ��
	void NCB_vMakeCylinderGLU( float m_height );

	//GLU�Լ��� �̿��� ��ü�� �׷��ִ� ��
	void NCB_vMakeSphereGLU();

	// Timer ����
	void NCB_vStartTimer();

	// ��ǥ �׸���
	void NCB_Coord( );

protected:
	//����
	float m_fFrame;
	float m_fCrank;
	float m_fCoupler;
	float m_fRocker;
	float m_fDiagonal;

	//�� 
	float m_fO[3];
	float m_fA[3];
	float m_fB[3];
	float m_fC[3];

	//��  
	float m_fOdeg;
	float m_fAldeg;
	float m_fBedeg;

	//���� ��
	float m_fAngleA;
	float m_fAngleB;
	float m_fAngleC;


protected:
	afx_msg void OnTimer( UINT nIDEvent );
	afx_msg void OnDestroy();
	virtual ~NCB_AnotherView1();

	DECLARE_MESSAGE_MAP()
};
