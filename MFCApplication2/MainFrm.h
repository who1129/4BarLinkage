
#pragma once

class NCB_MFCexView;
class NCB_SetDialog;
class NCB_CSplitterWnd : public CSplitterWnd
{
	DECLARE_DYNAMIC( NCB_CSplitterWnd );

public:
	NCB_CSplitterWnd() {};
	
	afx_msg void OnSize( UINT nType, int cx, int cy );
	afx_msg BOOL OnEraseBkgnd( CDC* pDC );
	
	DECLARE_MESSAGE_MAP()
};

class CMainFrame : public CFrameWnd
{

protected:
	CMainFrame();
	DECLARE_DYNCREATE( CMainFrame )

protected:
	NCB_CSplitterWnd m_wndSplitter;
	NCB_CSplitterWnd CreateStatic;
public:
	int	m_nNum;
	NCB_SetDialog *m_setdlg;

public:
	virtual BOOL OnCreateClient( LPCREATESTRUCT lpcs, CCreateContext* pContext );
	virtual BOOL PreCreateWindow( CREATESTRUCT& cs );
	afx_msg void OnSize( UINT nType, int cx, int cy );
	BOOL OnEraseBkgnd( CDC* /*pDC*/ );
	void Invalidate();			// Invalidate window so entire client area is redrawn when UpdateWindow is called.
	void UpdateWindow();		// Update Window to cause View to redraw.
	afx_msg void OnPopSetting( );

public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump( CDumpContext& dc ) const;
#endif

protected:
	CToolBar          m_wndToolBar;
	CStatusBar        m_wndStatusBar;

	NCB_MFCexView* m_pViews[4];

protected:
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
	afx_msg void OnDestroy( );
	DECLARE_MESSAGE_MAP()

};


