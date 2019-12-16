#include "stdafx.h"
#include "NCB_MFCex.h"

#include "MainFrm.h"
#include "NCB_AnotherView1.h"
#include "NCB_AnotherView2.h"
#include "NCB_AnotherView3.h"
#include "NCB_AnotherView4.h"
#include "NCB_MFCexView.h"
#include "NCB_SetDialog.h"
#include "NCB_TestSlider.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
	ON_COMMAND( ID_SETTING, &CMainFrame::OnPopSetting )
	ON_WM_DESTROY()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // 상태 줄 표시기
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

//////////////////////////////////////////////////////////////////////////

IMPLEMENT_DYNAMIC(NCB_CSplitterWnd, CSplitterWnd)

BEGIN_MESSAGE_MAP(NCB_CSplitterWnd, CSplitterWnd)
	ON_WM_SIZE()
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()

void NCB_CSplitterWnd::OnSize(UINT nType, int cx, int cy)
{
	CSplitterWnd::OnSize(nType, cx, cy);
}

BOOL NCB_CSplitterWnd::OnEraseBkgnd(CDC* pDC)
{
	return TRUE;
}
//////////////////////////////////////////////////////////////////////////

CMainFrame::CMainFrame()
{
	m_pViews[0] = NULL;
	m_pViews[1] = NULL;
	m_pViews[2] = NULL;
	m_pViews[3] = NULL;
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP | CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("도구 모음을 만들지 못했습니다.\n");
		return -1;    
	}

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("상태 표시줄을 만들지 못했습니다.\n");
		return -1;    
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);

	m_nNum = 1;
	
	return 0;
}

BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs,
	CCreateContext* pContext)
{
	m_wndSplitter.CreateStatic(this, 2, 2);
	m_wndSplitter.CreateView( 0, 0, RUNTIME_CLASS( NCB_AnotherView1 ), CSize( 950, 510 ), pContext );
	m_wndSplitter.CreateView( 0, 1, RUNTIME_CLASS( NCB_AnotherView2 ), CSize( 950, 510 ), pContext );
	m_wndSplitter.CreateView( 1, 0, RUNTIME_CLASS( NCB_AnotherView3 ), CSize( 950, 510 ), pContext );
	m_wndSplitter.CreateView( 1, 1, RUNTIME_CLASS( NCB_AnotherView4 ), CSize( 950, 510 ), pContext );

	m_pViews[0] = (NCB_MFCexView*)m_wndSplitter.GetPane(0, 0);
	m_pViews[1] = (NCB_MFCexView*)m_wndSplitter.GetPane(0, 1);
	m_pViews[2] = (NCB_MFCexView*)m_wndSplitter.GetPane(1, 0);
	m_pViews[3] = (NCB_MFCexView*)m_wndSplitter.GetPane(1, 1);

	NCB_AnotherView1* view1;

	view1 = (NCB_AnotherView1*)m_pViews[0];

	if( !view1 )
		return TRUE;

	view1->NCB_vStartTimer();


	return TRUE;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	return TRUE;
}

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif 

BOOL CMainFrame::OnEraseBkgnd(CDC* /*pDC*/)
{
	return FALSE;
}

void CMainFrame::OnSize(UINT nType, int cx, int cy)
{
	CFrameWnd::OnSize(nType, cx, cy);

	for (int i = 0; i < 4; ++i)
	{
		if (m_pViews[i])
			m_pViews[i]->UpdateWindow();
	}

}
void CMainFrame::OnPopSetting()
{
	m_setdlg = new NCB_SetDialog(m_pViews);
	m_setdlg->Create( IDD_DIALOG1, this );
	m_setdlg->ShowWindow( SW_SHOW );

}
void CMainFrame::OnDestroy()
{
	m_setdlg->DestroyWindow();
	delete m_setdlg;
}