#pragma once
#include <gl/GL.h>
#include <gl/GLU.h>

class NCB_MFCexDoc;

class NCB_MFCexView : public CView
{
protected: // serialization에서만 만들어집니다.
	NCB_MFCexView();
	afx_msg void OnRButtonDown( UINT nFlags, CPoint point );
	afx_msg void OnRButtonUp( UINT nFlags, CPoint point );
	afx_msg void OnLButtonDown( UINT nFlags, CPoint point );
	afx_msg void OnLButtonUp( UINT nFlags, CPoint point );
	afx_msg void OnMouseMove( UINT nFlags, CPoint point );
	afx_msg BOOL OnMouseWheel( UINT nFlags, short zDelta, CPoint pt );
	//afx_msg BOOL DoMouseWheel( nFlags, zDelta, pt );
	DECLARE_DYNCREATE(NCB_MFCexView)

// 특성입니다.
public:
	NCB_MFCexDoc* GetDocument() const;
	virtual void GLRenderScene(){};
	void NCB_vTrans( );
	virtual void NCB_InitLights();
	void NCB_Light1( );
	void NCB_Light2( );
	void NCB_Light3( );
	void NCB_Light4( );

	//OnPaint함수에서 새로 그리는 부분만 분리해옴
	void NCB_MFCexView::NCB_ReDraw(void);

private:
	//비율 반영된 XY값
	float m_fX, m_fY;
	//마우스 클릭 위치에따른 T/F
	float m_bMoveT;
	float m_bMoveR;
	//L Button~~
	float m_fPremoveX, m_fMoveX, m_fPremoveY, m_fMoveY;
	//회전
	float m_fXAngle, m_fYAngle;
	float m_fXRot, m_fYRot;
	//이동
	float m_fXPos, m_fYPos;

protected:

	HDC m_hDC;
	HGLRC m_hRC;

	//ortho
	float m_fWidth, m_fRight, m_fLeft, m_fTop;
	//frame
	float m_fHeight, m_fBottom;
	float m_fSize;
	BOOL m_bDrawPoints;
	//마우스 클릭을 저장하는 변수
	CPoint m_pMouseDPoint;
	
	//빛 변수
	GLfloat m_fAm;
	GLfloat m_fAmR;
	GLfloat m_fAmG;
	GLfloat m_fAmB;

	GLfloat m_fDi;
	GLfloat m_fDiR;
	GLfloat m_fDiG;
	GLfloat m_fDiB;

	GLfloat m_fSp;
	GLfloat m_fSpR;
	GLfloat m_fSpG;
	GLfloat m_fSpB;

	float m_flit;
public:
	void NCB_vSetAm( float fValue );
	float NCB_fGetAm();
	void NCB_vSetAmR( float fValue);
	float NCB_fGetAmR();
	void NCB_vSetAmG( float fValue );
	float NCB_fGetAmG();
	void NCB_vSetAmB( float fValue );
	float NCB_fGetAmB();

	void NCB_vSetDi( float fValue );
	float NCB_fGetDi( );
	void NCB_vSetDiR( float fValue );
	float NCB_fGetDiR( );
	void NCB_vSetDiG( float fValue );
	float NCB_fGetDiG( );
	void NCB_vSetDiB( float fValue );
	float NCB_fGetDiB( );

	void NCB_vSetSp( float fValue );
	float NCB_fGetSp( );
	void NCB_vSetSpR( float fValue );
	float NCB_fGetSpR( );
	void NCB_vSetSpG( float fValue );
	float NCB_fGetSpG( );
	void NCB_vSetSpB( float fValue );
	float NCB_fGetSpB( );

	void NCB_vSetLit( float fValue );
	float NCB_fGetLit();

	virtual void OnDraw(CDC* pDC);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

public:
	virtual ~NCB_MFCexView();
	
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy( void );
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint(void);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	
	DECLARE_MESSAGE_MAP()
};
