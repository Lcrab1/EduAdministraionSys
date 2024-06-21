#pragma once


// CCourseScoreDlg 对话框

class CCourseScoreDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCourseScoreDlg)

public:
	CCourseScoreDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCourseScoreDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COURSESCORE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
