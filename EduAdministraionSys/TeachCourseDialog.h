#pragma once
#include"Database.h"
#include"TeacherInterface.h"
// CTeachCourseDialog 对话框

class CTeachCourseDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CTeachCourseDialog)

public:
	CTeachCourseDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTeachCourseDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEACHCOURSE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	/* YXY：控件处理、消息映射函数       */
	virtual BOOL OnInitDialog();
	void InitializeComboBoxes();
	void InitializeScoreList();
	afx_msg void OnCbnSelchangeComboYear();
	afx_msg void OnCbnSelchangeComboTerm();



	CComboBox m_ComboYear;
	CComboBox m_ComboTerm;
	CListCtrl m_CourseList;
};
