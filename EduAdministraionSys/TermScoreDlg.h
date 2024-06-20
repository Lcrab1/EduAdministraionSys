#pragma once


// CTermScoreDlg 对话框

class CTermScoreDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTermScoreDlg)

public:
	CTermScoreDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTermScoreDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TERMSCORE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
