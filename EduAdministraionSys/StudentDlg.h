﻿#pragma once


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
	afx_msg void OnPaint();
	virtual BOOL OnInitDialog();
	afx_msg void OnNMCustomdrawListStuInfo(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedButtonChangeinfo();
	afx_msg void OnCbnSelchangeCombo1();




	CStatic m_pcsch;//yxy：picturecontrol控件变量
	CFont m_font1;//yxy:标题的字体
	CListCtrl m_StuInfoList;//yxy：listcontrol控件变量
	CComboBox m_ComboxScore;//yxy：下拉框控件变量
};
