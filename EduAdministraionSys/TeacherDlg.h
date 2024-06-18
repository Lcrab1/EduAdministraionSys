#pragma once


// TeacherDlg 对话框

class TeacherDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TeacherDlg)

public:
	TeacherDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TeacherDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEACHER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
