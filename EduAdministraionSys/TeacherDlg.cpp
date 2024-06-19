// TeacherDlg.cpp: 实现文件
//

#include "pch.h"
#include "EduAdministraionSys.h"
#include "TeacherDlg.h"
#include "afxdialogex.h"


// TeacherDlg 对话框

IMPLEMENT_DYNAMIC(TeacherDlg, CDialogEx)

TeacherDlg::TeacherDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEACHER_DIALOG, pParent)
{

}

TeacherDlg::~TeacherDlg()
{
}

void TeacherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TEACHER_TITLE_STATIC, m_TeacherTitleStatic);
}


BEGIN_MESSAGE_MAP(TeacherDlg, CDialogEx)
END_MESSAGE_MAP()


// TeacherDlg 消息处理程序


BOOL TeacherDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_TeacherTitleFont.CreatePointFont(250, _T("华文新魏"));  //设置登录界面标题的字体和大小
	m_TeacherTitleStatic.SetFont(&m_TeacherTitleFont);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}
