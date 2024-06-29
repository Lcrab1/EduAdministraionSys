#pragma once
#include "TeachCourseDialog.h"
#include "ScoreRegistDialog.h"
#include"Database.h"

// TeacherDlg 对话框

class TeacherDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TeacherDlg)

public:
	TeacherDlg(const CString teacherID,CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TeacherDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEACHER_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	/*  YXY：消息映射及初始化*/
	virtual BOOL OnInitDialog();
	void			OnInitInfoTable();
	void InitSonDialog();
	afx_msg void OnBnClickedButtonTeachcourse();
	afx_msg void OnBnClickedButtonScoreregist();
	afx_msg void OnBnClickedButtonMainwnd2();



	CListCtrl m_InfoList;
	CStatic m_TeacherTitleStatic;				//XK:教师窗口主题的文本框
	CFont		m_TeacherTitleFont;				//XK:格式刷
	CScoreRegistDialog* m_RegistDlg;			//YXY:录入成绩窗口
	CTeachCourseDialog* m_CourseDlg;			//YXY:查询课程窗口
	CString			m_TeacherID;				//XK:保存教师ID 


};
