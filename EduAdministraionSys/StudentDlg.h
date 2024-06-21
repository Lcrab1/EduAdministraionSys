﻿#pragma once
#include "TermScoreDlg.h"
#include "EditInfoDlg.h"
#include "CourseScoreDlg.h"

// StudentDlg 对话框

class StudentDlg : public CDialogEx
{
	DECLARE_DYNAMIC(StudentDlg)

public:
	StudentDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~StudentDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_STUDENT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL	OnInitDialog();
	afx_msg HBRUSH	OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	//afx_msg void	OnPaint();
	afx_msg void	OnTvnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
	void			OnInitInfoTable();
	void			InitSonDialog();
	void			InitTreeButton();


	/***********************************************/
	CStatic				m_pcsch;//yxy：picturecontrol控件变量
	CFont				m_font1;//yxy:标题的字体
	CListCtrl			m_StuInfoList;//yxy：listcontrol控件变量
	CBrush				m_Brush;
	CTreeCtrl			m_TreeCtrl;
	CTermScoreDlg*		m_TermScoreDlg;
	CEditInfoDlg*		m_EditInfoDlg;
	CCourseScoreDlg*	m_CourseScoreDlg;


	afx_msg void OnBnClickedButtonInfochange();
};
