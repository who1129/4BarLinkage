
// MFCApplication2.h : MFCApplication2 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CMFCApplication2App:
// �� Ŭ������ ������ ���ؼ��� MFCApplication2.cpp�� �����Ͻʽÿ�.
//

class NCB_MFCex : public CWinApp
{
public:
	NCB_MFCex();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();

	DECLARE_MESSAGE_MAP()
};

extern NCB_MFCex theApp;
