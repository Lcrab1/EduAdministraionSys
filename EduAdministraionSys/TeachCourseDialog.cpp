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

    InitializeCourseList();

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
    std::vector<ClassOfTeacher> classOfTeacher;
    std::vector<ClassOfTeacher> classOfTeacherWithYear;
    std::vector<ClassOfTeacher> classOfTeacherWithSemester;
    classOfTeacher.reserve(30);
    classOfTeacherWithYear.reserve(10);
    classOfTeacherWithSemester.reserve(5);
    classOfTeacher = TeacherInterface::get().getClassOfTeacher();

    int SelYear = m_ComboYear.GetCurSel();
    if (SelYear != CB_ERR)
    {
        CString strYear;
        m_ComboYear.GetLBText(SelYear, strYear);
        // TODO: 根据选择的学年执行相应的操作

        for (int i = 0; i < classOfTeacher.size(); i++)
        {
            if (classOfTeacher[i].year == strYear)
            {
                classOfTeacherWithYear.emplace_back(classOfTeacher[i]);
            }
        }
        //XK：刷新课程列表
        RefreshCourseList(classOfTeacherWithYear);
    }

    // 处理学期选择变化
    int SelTerm = m_ComboTerm.GetCurSel();
    if (SelTerm != CB_ERR)
    {
        CString strSemester;
        m_ComboTerm.GetLBText(SelTerm, strSemester);
        // TODO: 根据选择的学期执行相应的操作
        for (int i = 0; i < classOfTeacherWithYear.size(); i++)
        {
            if (classOfTeacherWithYear[i].semester == strSemester)
            {
                classOfTeacherWithSemester.emplace_back(classOfTeacherWithYear[i]);
            }
        }
        //XK：刷新课程列表
        RefreshCourseList(classOfTeacherWithSemester);
    }

    

}

//YXY：初始化课程列表
void CTeachCourseDialog::InitializeCourseList()
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
    //m_CourseList.InsertItem(0, _T("xk110011"));
    //m_CourseList.SetItemText(0, 2, _T("导管原理"));
}

void CTeachCourseDialog::RefreshCourseList(IN const std::vector<ClassOfTeacher>& classOfTeacher)
{
    m_CourseList.DeleteAllItems();
    const std::vector<ClassOfTeacher>* courseInfo = &classOfTeacher;
    if (courseInfo->size()==0)
    {
        return;
    }
    int column = 0;
    for (int i = 0; i < courseInfo->size(); i++)
    {
        m_CourseList.InsertItem(column, (*courseInfo)[i].id);
        m_CourseList.SetItemText(column, 1, (*courseInfo)[i].name);
        m_CourseList.SetItemText(column, 2, (*courseInfo)[i].studentCount);
        m_CourseList.SetItemText(column, 3, (*courseInfo)[i].credit);
        m_CourseList.SetItemText(column, 4, (*courseInfo)[i].classRoom);
        m_CourseList.SetItemText(column, 5, (*courseInfo)[i].week);
        column++;
    }
}
