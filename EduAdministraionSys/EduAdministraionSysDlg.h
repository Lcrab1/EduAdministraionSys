
// EduAdministraionSysDlg.h: 头文件
//

#pragma once
#include"Database.h"
#include<cstring>
#include"resource.h"
// CEduAdministraionSysDlg 对话框
class CEduAdministraionSysDlg : public CDialogEx
{
// 构造
public:
	CEduAdministraionSysDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDUADMINISTRAIONSYS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);//XK:更改主对话框背景颜色

private:
	CStatic		m_LoginTitle;					//XK:登录界面标题“教务管理系统”变量
	CFont		m_LoginTitleFont;				//XK:格式刷
	CBrush		m_Brush;						//XK:修改背景颜色的画笔
	CFont		m_LoginEditFont;				//XK:登录输入框格式
	CEdit		m_AccountEdit;					//XK:账号输入框
	CEdit		m_PasswordEdit;					//XK:密码输入框
	CStatic		m_AccountIcon;					//XK:账号图标
	CStatic		m_PasswordIcon;					//XK:密码图标
	CMFCButton	m_LoginButton;					//XK:登录按钮
	CFont		m_LoginButtonFont;				//XK:登录按钮格式
public:
	//void TestDatabase();						//XK:测试数据库的连接
	afx_msg void OnEnSetfocusAccountEdit();		//XK:账号输入框得到焦点
	afx_msg void OnEnKillfocusAccountEdit();	//XK:账号输入框失去焦点
	afx_msg void OnEnSetfocusPasswordEdit();	//XK:密码输入框得到焦点
	afx_msg void OnEnKillfocusPasswordEdit();	//XK:密码输入框失去焦点
	afx_msg void OnBnClickedVisibleCheck();		//XK:密码可见性icon切换
	afx_msg void OnBnClickedLoginMfcbutton();	//XK:登录按钮执行的操作
};
