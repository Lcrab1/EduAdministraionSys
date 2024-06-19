
// EduAdministraionSysDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "EduAdministraionSys.h"
#include "EduAdministraionSysDlg.h"
#include "afxdialogex.h"
#include "StudentDlg.h"
#include"TeacherDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CEduAdministraionSysDlg 对话框



CEduAdministraionSysDlg::CEduAdministraionSysDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EDUADMINISTRAIONSYS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CEduAdministraionSysDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LOGIN_TITLE_STATIC, m_LoginTitle);
	DDX_Control(pDX, IDC_ACCOUNT_EDIT, m_AccountEdit);
	DDX_Control(pDX, IDC_PASSWORD_EDIT, m_PasswordEdit);
	DDX_Control(pDX, IDC_ACCOUNT_ICON, m_AccountIcon);
	DDX_Control(pDX, IDC_PASSWORD_ICON, m_PasswordIcon);
	DDX_Control(pDX, IDC_LOGIN_MFCBUTTON, m_LoginButton);
}

BEGIN_MESSAGE_MAP(CEduAdministraionSysDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_EN_SETFOCUS(IDC_ACCOUNT_EDIT, &CEduAdministraionSysDlg::OnEnSetfocusAccountEdit)
	ON_EN_KILLFOCUS(IDC_ACCOUNT_EDIT, &CEduAdministraionSysDlg::OnEnKillfocusAccountEdit)
	ON_EN_SETFOCUS(IDC_PASSWORD_EDIT, &CEduAdministraionSysDlg::OnEnSetfocusPasswordEdit)
	ON_EN_KILLFOCUS(IDC_PASSWORD_EDIT, &CEduAdministraionSysDlg::OnEnKillfocusPasswordEdit)
	ON_BN_CLICKED(IDC_VISIBLE_CHECK, &CEduAdministraionSysDlg::OnBnClickedVisibleCheck)
	ON_BN_CLICKED(IDC_LOGIN_MFCBUTTON, &CEduAdministraionSysDlg::OnBnClickedLoginMfcbutton)
END_MESSAGE_MAP()


// CEduAdministraionSysDlg 消息处理程序

BOOL CEduAdministraionSysDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	/*TestDatabase();*/
	InitiateDataBase();

	/*StudentDlg stu;
	stu.DoModal();*/
	TeacherDlg  teacher;
	teacher.DoModal();

	//XK:设置登录界面标题样式
	m_LoginTitleFont.CreatePointFont(500, _T("华文新魏"));  //设置登录界面标题的字体和大小
	m_LoginTitle.SetFont(&m_LoginTitleFont);

	//XK:设置登录界面账号密码输入框样式
	m_LoginEditFont.CreatePointFont(220, _T("Times New Roman"));
	m_AccountEdit.SetFont(&m_LoginEditFont);
	m_PasswordEdit.SetFont(&m_LoginEditFont);

	//XK:Edit默认显示文字
	CString accountStr = _T("请输入学号/工号"); // 默认显示内容
	GetDlgItem(IDC_ACCOUNT_EDIT)->SetWindowText(accountStr); // 改变ID为IDC_EDIT1的编辑框
	
	CString passwordtStr = _T("请输入密码"); // 默认显示内容
	GetDlgItem(IDC_PASSWORD_EDIT)->SetWindowText(passwordtStr); // 改变ID为IDC_EDIT1的编辑框

	//XK:设置密码是否可见的位图图标
	CButton* pButton = (CButton*)GetDlgItem(IDC_VISIBLE_CHECK); // 获取复选框控件
	HICON hIcon = AfxGetApp()->LoadIcon(IDI_INVISIBLE_ICON); // 加载图标资源
	pButton->SetIcon(hIcon); // 设置位图

	//XK:设置登录按钮为蓝色,修改文字格式
	m_LoginButton.m_bTransparent = FALSE;
	m_LoginButton.m_bDontUseWinXPTheme = TRUE;
	m_LoginButton.SetFaceColor(RGB(91, 156, 214));
	m_LoginButtonFont.CreatePointFont(170, _T("微软雅黑"));
	m_LoginButton.SetFont(&m_LoginButtonFont);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CEduAdministraionSysDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CEduAdministraionSysDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CEduAdministraionSysDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//XK:测试数据库连接
//void CEduAdministraionSysDlg::TestDatabase()
//{
//	MYSQL mysql; // 数 据 库 句 柄
//	MYSQL_RES* res; // 查 询 结 果 集
//	MYSQL_ROW row; // 记 录 结 构 体
//	// 初 始 化 数 据 库
//	mysql_init(&mysql);
//	// 设 置 字 符 编 码
//	mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");
//	if (mysql_real_connect(&mysql, "8.130.140.31", "user_test", "Lyf18995837471", "stuAdminSYS", 3306, NULL, 0) == NULL)
//	{
//		MessageBox(L"连接失败", L"失败");
//	}
//	else
//	{
//		MessageBox(L"连接成功", L"成功");
//	}
//}

void CEduAdministraionSysDlg::InitiateDataBase()
{
	// 初 始 化 数 据 库
	mysql_init(&Database::getDatabase().m_mysql);
	// 设 置 字 符 编 码
	mysql_options(&Database::getDatabase(). m_mysql, MYSQL_SET_CHARSET_NAME, "gbk");
	if (mysql_real_connect(&Database::getDatabase().m_mysql, "8.130.140.31", "user_test", "Lyf18995837471", "stuAdminSYS", 3306, NULL, 0) == NULL)
	{
		MessageBox(L"连接失败", L"失败");
	}
	else
	{
		//MessageBox(L"连接成功", L"成功");
	}
}


//XK:修改主窗口背景颜色的函数
HBRUSH CEduAdministraionSysDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO:  在此更改 DC 的任何特性
	
	//XK:修改文本框背景为白色
	if (pWnd->GetDlgCtrlID() == IDC_LOGIN_TITLE_STATIC)// IDC_LOGIN_TITLE_STATIC为所选文本框ID    
	{

		//pDC->SetTextColor(RGB(255, 0, 0));//设置字体颜色

		pDC->SetBkColor(RGB(255, 255, 255));//设置背景颜色

		//pDC->SetBkMode(TRANSPARENT);//设置背景透明

		return (HBRUSH)(m_Brush.GetSafeHandle());
	}

	//XK:修改用户icon背景为白色
	if (pWnd->GetDlgCtrlID() == IDC_ACCOUNT_ICON)   
	{
		pDC->SetBkColor(RGB(255, 255, 255));//设置背景颜色
		return (HBRUSH)(m_Brush.GetSafeHandle());
	}

	//XK:修改密码icon背景为白色
	if (pWnd->GetDlgCtrlID() == IDC_PASSWORD_ICON)
	{
		pDC->SetBkColor(RGB(255, 255, 255));//设置背景颜色
		return (HBRUSH)(m_Brush.GetSafeHandle());
	}

	//XK:修改可见icon背景为白色
	if (pWnd->GetDlgCtrlID() == IDC_VISIBLE_CHECK)
	{
		pDC->SetBkColor(RGB(255, 255, 255));//设置背景颜色
		return (HBRUSH)(m_Brush.GetSafeHandle());
	}


	//XK:修改主对话框背景为白色
	switch (nCtlColor)
	{
	case CTLCOLOR_DLG:
		HBRUSH aBrush;
		aBrush = CreateSolidBrush(RGB(255, 255, 255));
		hbr = aBrush;
		break;
	}


	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

//XK:AccountEdit控件获得焦点时清空内容
void CEduAdministraionSysDlg::OnEnSetfocusAccountEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_AccountEdit.GetWindowText(str);
	if (str == _T("请输入学号/工号"))
	{
		m_AccountEdit.SetWindowText(_T(""));
	}

}

//XK:AccountEdit控件失去焦点时填充内容
void CEduAdministraionSysDlg::OnEnKillfocusAccountEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_AccountEdit.GetWindowText(str);
	if (str == _T(""))
	{
		m_AccountEdit.SetWindowText(_T("请输入学号/工号"));
	}

}

//XK:PasswordEdit控件获得焦点时清空内容
void CEduAdministraionSysDlg::OnEnSetfocusPasswordEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_PasswordEdit.GetWindowText(str);
	if (str == _T("请输入密码"))
	{
		m_PasswordEdit.SetWindowText(_T(""));
		m_PasswordEdit.SetPasswordChar('*'); // 设置密码字符
	}
	CButton* pButton = (CButton*)GetDlgItem(IDC_VISIBLE_CHECK);
	if (pButton->GetCheck() == FALSE)
	{
		m_PasswordEdit.SetPasswordChar('*'); // 设置密码字符
	}
	else
	{
		m_PasswordEdit.SetPasswordChar(NULL); // 设置密码字符
	}
}

//XK:PasswordEdit控件失去焦点时内容
void CEduAdministraionSysDlg::OnEnKillfocusPasswordEdit()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_PasswordEdit.GetWindowText(str);
	if (str == _T(""))
	{
		m_PasswordEdit.SetWindowText(_T("请输入密码"));
		m_PasswordEdit.SetPasswordChar(NULL); // 取消密码字符
		return;
	}
	CButton* pButton = (CButton*)GetDlgItem(IDC_VISIBLE_CHECK);
	if (pButton->GetCheck() == FALSE)
	{
		m_PasswordEdit.SetPasswordChar('*'); // 设置密码字符
	}
	else
	{
		m_PasswordEdit.SetPasswordChar(NULL); // 设置密码字符
	}

}


//XK:密码可见性icon图标切换
void CEduAdministraionSysDlg::OnBnClickedVisibleCheck()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	m_PasswordEdit.GetWindowText(str);
	CButton* pButton = (CButton*)GetDlgItem(IDC_VISIBLE_CHECK); // 获取复选框控件
	if (pButton->GetCheck() == FALSE)
	{
		//密码不可见
		HICON hIcon = AfxGetApp()->LoadIcon(IDI_INVISIBLE_ICON); // 加载图标资源
		pButton->SetIcon(hIcon); // 设置位图
		if (str != _T("请输入密码"))
		{
			m_PasswordEdit.SetPasswordChar('*'); // 设置密码字符
		}

	}
	else
	{
		//密码可见
		HICON hIcon = AfxGetApp()->LoadIcon(IDI_VISIBLE_ICON); // 加载图标资源
		pButton->SetIcon(hIcon); // 设置位图
		m_PasswordEdit.SetPasswordChar(NULL); // 取消密码字符
	}
}

//XK:登录按钮,登录的操作在这里实现
void CEduAdministraionSysDlg::OnBnClickedLoginMfcbutton()
{
	// TODO: 在此添加控件通知处理程序代码
	CString account;
	CString password;
	int privilege=0;
	m_AccountEdit.GetWindowTextW(account);
	m_PasswordEdit.GetWindowTextW(password);
	privilege = Database::getDatabase().login(account, password);
	if (privilege == UNKNOW)
	{
		MessageBox(L"账号或密码错误", L"登录失败");
	}
	else if (privilege == STUDENT)
	{ 
		StudentDlg studentDlg;
		studentDlg.DoModal();
	}
	else if (privilege == TEACHER)
	{
		MessageBox(L"跳转到教师界面", L"教师账号");
	}
}
