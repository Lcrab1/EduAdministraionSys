#pragma once


// CInfoChangeDlg 对话框

class CInfoChangeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CInfoChangeDlg)

public:
	CInfoChangeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CInfoChangeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INFOCHANGE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonReset();
	afx_msg void OnBnClickedButtonSubmmit();
};
