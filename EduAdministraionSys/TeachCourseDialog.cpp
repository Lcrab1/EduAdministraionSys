// TeachCourseDialog.cpp: 实现文件
//

#include "pch.h"
#include "EduAdministraionSys.h"
#include "TeachCourseDialog.h"
#include "afxdialogex.h"

// CTeachCourseDialog 对话框

IMPLEMENT_DYNAMIC(CTeachCourseDialog, CDialogEx)

CTeachCourseDialog::CTeachCourseDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEACHCOURSE_DIALOG, pParent)
{

}

CTeachCourseDialog::~CTeachCourseDialog()
{
}

void CTeachCourseDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_YEAR2, m_ComboYear);
    DDX_Control(pDX, IDC_COMBO_TERM2, m_ComboTerm);
    DDX_Control(pDX, IDC_TEACHCOURSE_LIST, m_CourseList);
}


BEGIN_MESSAGE_MAP(CTeachCourseDialog, CDialogEx)
    ON_CBN_SELCHANGE(IDC_COMBO_YEAR2, &CTeachCourseDialog::OnCbnSelchangeComboYear)
    ON_CBN_SELCHANGE(IDC_COMBO_TERM2, &CTeachCourseDialog::OnCbnSelchangeComboTerm)
END_MESSAGE_MAP()


// CTeachCourseDialog 消息处理程序



BOOL CTeachCourseDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

    InitializeComboBoxes();

    InitializeScoreList();

	return TRUE;  
}

//YXY:初始化学期选择控件
void CTeachCourseDialog::InitializeComboBoxes()
{


    // 添加学年选项
    m_ComboYear.AddString(_T("2019-2020"));
    m_ComboYear.AddString(_T("2020-2021"));
    m_ComboYear.AddString(_T("2021-2022"));
    m_ComboYear.AddString(_T("2022-2023"));
    m_ComboYear.AddString(_T("2023-2024"));
    m_ComboYear.AddString(_T("2024-2025"));

    // 添加学期选项
    m_ComboTerm.AddString(_T("学期1"));
    m_ComboTerm.AddString(_T("学期2"));
    m_ComboTerm.ShowWindow(SW_HIDE);
}

//YXY:学年控件
void CTeachCourseDialog::OnCbnSelchangeComboYear()
{
    m_ComboTerm.ShowWindow(SW_SHOW);
    HWND hComboBox = m_ComboTerm.GetSafeHwnd();

    // 展开组合框下拉列表
    ::SendMessage(hComboBox, CB_SHOWDROPDOWN, TRUE, 0);
}

//YXY:学期控件
void CTeachCourseDialog::OnCbnSelchangeComboTerm()
{
    // 处理学年选择变化
    int SelYear = m_ComboYear.GetCurSel();
    if (SelYear != CB_ERR)
    {
        CString strYear;
        m_ComboYear.GetLBText(SelYear, strYear);
        // TODO: 根据选择的学年执行相应的操作
        std::vector<ClassOfTeacher> classOfTeacher;
       classOfTeacher = TeacherInterface::get().getClassOfTeacher();
        //Teacher teacher;
       // teacher = TeacherInterface::get().getTeacher();
        for (int i = 0; i < classOfTeacher.size(); i++)
        {
            if (classOfTeacher[i].year == strYear)
            {

            }
        }

        MessageBox(strYear, 0, 0);//测试





    }


    // 处理学期选择变化
    int SelTerm = m_ComboTerm.GetCurSel();
    if (SelTerm != CB_ERR)
    {
        CString strTerm;
        m_ComboTerm.GetLBText(SelTerm, strTerm);
        // TODO: 根据选择的学期执行相应的操作










    }
}

//YXY：初始化课程列表
void CTeachCourseDialog::InitializeScoreList()
{
    m_CourseList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // 添加列标题
    m_CourseList.InsertColumn(0, _T("课程代号"), LVCFMT_LEFT, 90);
    m_CourseList.InsertColumn(1, _T("课程名称"), LVCFMT_LEFT, 150);
    m_CourseList.InsertColumn(2, _T("课程人数"), LVCFMT_LEFT, 60);
    m_CourseList.InsertColumn(3, _T("学分"), LVCFMT_LEFT, 50);
    m_CourseList.InsertColumn(4, _T("教室"), LVCFMT_LEFT, 90);
    m_CourseList.InsertColumn(5, _T("教学周"), LVCFMT_LEFT, 90);

    //添加数据的示例，直接crud
    m_CourseList.InsertItem(0, _T("xk110011"));
    m_CourseList.SetItemText(0, 2, _T("导管原理"));
}