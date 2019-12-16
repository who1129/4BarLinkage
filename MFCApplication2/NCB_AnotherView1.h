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

	//4절링크 그릴 때 필요한 대각선, 알파, 베타 계산
	void NCB_vCalc4BarLink();
	
	//각 변 사이에 끼인 각 구함. rotate할 때 씀.
	float NCB_fGetAngle( float* p1, float* p2 );
	
	//원기둥을 기울이는 함수
	void NCB_vRotateBar( float* point, float angle );
	
	// 끼인각 계산함수 호출하여 저장.
	void NCB_vIncludedAngle();
	
	//4절링크 a,b,c점 정보 계산
	void NCB_v4BarPoint();
	
	//4절링크 점 정보에 따라서 선으로 그리는 부분 
	void NCB_vDraw4BarLink( void );
	
	//4절링크 점 정보를 가지고 그리는부분
	void NCB_vDraw4BarLinkCylinder( void );
	
	//원기둥을 그려주는 곳.
	void NCB_vMakeCylinder( float* ps, float* pe, float m_height );

	//GLU함수를 이용해 원기둥을 그려주는 곳
	void NCB_vMakeCylinderGLU( float m_height );

	//GLU함수를 이용해 구체를 그려주는 곳
	void NCB_vMakeSphereGLU();

	// Timer 시작
	void NCB_vStartTimer();

	// 좌표 그리기
	void NCB_Coord( );

protected:
	//길이
	float m_fFrame;
	float m_fCrank;
	float m_fCoupler;
	float m_fRocker;
	float m_fDiagonal;

	//점 
	float m_fO[3];
	float m_fA[3];
	float m_fB[3];
	float m_fC[3];

	//각  
	float m_fOdeg;
	float m_fAldeg;
	float m_fBedeg;

	//끼인 각
	float m_fAngleA;
	float m_fAngleB;
	float m_fAngleC;


protected:
	afx_msg void OnTimer( UINT nIDEvent );
	afx_msg void OnDestroy();
	virtual ~NCB_AnotherView1();

	DECLARE_MESSAGE_MAP()
};
