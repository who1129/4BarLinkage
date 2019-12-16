#pragma once


// NCB_TESTDlg 대화 상자입니다.

class NCB_TESTDlg : public CDialogEx
{
	DECLARE_DYNAMIC(NCB_TESTDlg)

public:
	NCB_TESTDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~NCB_TESTDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_DIALOG1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
