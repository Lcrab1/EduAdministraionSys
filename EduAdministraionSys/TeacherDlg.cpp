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
	DDX_Control(pDX, IDC_TEACHER_LIST_INFO, m_InfoList);
}


BEGIN_MESSAGE_MAP(TeacherDlg, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON_MAINWND, &TeacherDlg::OnBnClickedButtonMainwnd)
    ON_BN_CLICKED(IDC_BUTTON_COURSE, &TeacherDlg::OnBnClickedButtonCourse)
    ON_BN_CLICKED(IDC_BUTTON_SCORE, &TeacherDlg::OnBnClickedButtonScore)
END_MESSAGE_MAP()


// TeacherDlg 消息处理程序


BOOL TeacherDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_TeacherTitleFont.CreatePointFont(250, _T("华文新魏"));  //设置登录界面标题的字体和大小
	m_TeacherTitleStatic.SetFont(&m_TeacherTitleFont);

    OnInitInfoTable();

    InitSonDialog();

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}

void TeacherDlg::OnInitInfoTable()
{
    m_InfoList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // 添加列标题
    m_InfoList.InsertColumn(0, _T("信息"), LVCFMT_LEFT, 75);
    m_InfoList.InsertColumn(1, _T(""), LVCFMT_LEFT, 125);
    m_InfoList.InsertColumn(2, _T("信息"), LVCFMT_LEFT, 75);
    m_InfoList.InsertColumn(3, _T(""), LVCFMT_LEFT, 125);
    // 添加数据行
    m_InfoList.InsertItem(0, _T("工号"));

    m_InfoList.SetItemText(0, 2, _T("姓名"));


    m_InfoList.InsertItem(1, _T("英文名"));

    m_InfoList.SetItemText(1, 2, _T("民族"));


    m_InfoList.InsertItem(2, _T("行政学院"));

    m_InfoList.SetItemText(2, 2, _T("性别"));


    m_InfoList.InsertItem(3, _T("入职年份"));

    m_InfoList.SetItemText(3, 2, _T("职称"));


    m_InfoList.InsertItem(4, _T("电子邮箱"));

    m_InfoList.SetItemText(4, 2, _T("联系电话"));
}

//YXY：初始化功能子窗口
void TeacherDlg::InitSonDialog()
{
    m_CourseDlg = new CTeachCourseDialog();
    m_CourseDlg->Create(IDD_TEACHCOURSE_DIALOG, GetDlgItem(IDC_TEACHER_LIST_INFO));

    m_RegistDlg = new CScoreRegistDialog();
    m_RegistDlg->Create(IDD_SCOREREGIST_DIALOG, GetDlgItem(IDC_TEACHER_LIST_INFO));

}

void TeacherDlg::OnBnClickedButtonMainwnd()
{

}


void TeacherDlg::OnBnClickedButtonCourse()
{
    m_CourseDlg->ShowWindow(SW_SHOW);
}


void TeacherDlg::OnBnClickedButtonScore()
{
    m_RegistDlg->ShowWindow(SW_SHOW);
}
