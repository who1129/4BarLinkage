#pragma once


// NCB_TESTDlg ��ȭ �����Դϴ�.

class NCB_TESTDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NCB_TESTDlg)

public:
	NCB_TESTDlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~NCB_TESTDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
};
