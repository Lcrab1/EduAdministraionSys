// ScoreRegistDialog.cpp: 实现文件
//

#include "pch.h"
#include "EduAdministraionSys.h"
#include "ScoreRegistDialog.h"
#include "afxdialogex.h"


// CScoreRegistDialog 对话框

IMPLEMENT_DYNAMIC(CScoreRegistDialog, CDialogEx)

CScoreRegistDialog::CScoreRegistDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCOREREGIST_DIALOG, pParent)
{

}

CScoreRegistDialog::~CScoreRegistDialog()
{
}

void CScoreRegistDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_COURSE, m_CourseCombox);
    DDX_Control(pDX, IDC_SCOREREGISTER_LIST, m_ScoreRegistList);
    DDX_Control(pDX, IDC_COMBO_YEAR3, m_ComboYear);
    DDX_Control(pDX, IDC_COMBO_TERM3, m_ComboTerm);
    DDX_Control(pDX, IDC_EDIT_TRAVEL, m_EditTravel);
}


BEGIN_MESSAGE_MAP(CScoreRegistDialog, CDialogEx)
    ON_CBN_SELCHANGE(IDC_COMBO_COURSE, &CScoreRegistDialog::OnCbnSelchangeComboCourse)
    ON_CBN_SELCHANGE(IDC_COMBO_YEAR3, &CScoreRegistDialog::OnCbnSelchangeComboYear3)
    ON_CBN_SELCHANGE(IDC_COMBO_TERM3, &CScoreRegistDialog::OnCbnSelchangeComboTerm3)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_SCOREREGISTER_LIST, &CScoreRegistDialog::OnLvnItemchangedScoreregisterList)
    ON_BN_CLICKED(IDC_BUTTON_COMPOSE, &CScoreRegistDialog::OnBnClickedButtonCompose)
    ON_MESSAGE(UM_UPADATE_DATA, OnUpdateList)
END_MESSAGE_MAP()


// CScoreRegistDialog 消息处理程序


BOOL CScoreRegistDialog::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    InitInfoList();

    InitializeComboBoxes();

    InitializeTermComboBoxes();

    return TRUE;
}

//YXY： 初始化列表控件
void CScoreRegistDialog::InitInfoList()
{
    // Set the extended style for full row selection and grid lines
    m_ScoreRegistList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    // Insert columns
    m_ScoreRegistList.InsertColumn(0, _T("学号"), LVCFMT_LEFT, 50);
    m_ScoreRegistList.InsertColumn(1, _T("学生姓名"), LVCFMT_LEFT, 75);
    m_ScoreRegistList.InsertColumn(2, _T("平时成绩"), LVCFMT_LEFT, 50);
    m_ScoreRegistList.InsertColumn(3, _T("期中成绩"), LVCFMT_LEFT, 50);
    m_ScoreRegistList.InsertColumn(4, _T("期末成绩"), LVCFMT_LEFT, 50);
    m_ScoreRegistList.InsertColumn(5, _T("总评成绩"), LVCFMT_LEFT, 50);

    // Optionally, add some sample data
    // m_ScoreRegistList.InsertItem(0, _T("20180101"));
    // m_ScoreRegistList.SetItemText(0, 1, _T("张三"));
    // m_ScoreRegistList.SetItemText(0, 2, _T("85"));
    // m_ScoreRegistList.SetItemText(0, 3, _T("80"));
    // m_ScoreRegistList.SetItemText(0, 4, _T("90"));
    // m_ScoreRegistList.SetItemText(0, 5, _T("85"));

}

//YXY:初始化课程选择控件
//添加数据示例已给出
void CScoreRegistDialog::InitializeComboBoxes()
{

    // 添加查到的课程
    m_CourseCombox.AddString(_T(""));

}


//YXY：选择指定课程后的操作
void CScoreRegistDialog::OnCbnSelchangeComboCourse()
{
    int SelCourse = m_CourseCombox.GetCurSel();
    if (SelCourse != CB_ERR)
    {
        CString CourseName;
        m_CourseCombox.GetLBText(SelCourse, CourseName);
        //使用CourseName查询信息


    }
}


//YXY:初始化学期选择控件
void CScoreRegistDialog::InitializeTermComboBoxes()
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
void CScoreRegistDialog::OnCbnSelchangeComboYear3()
{
    m_ComboTerm.ShowWindow(SW_SHOW);
    HWND hComboBox = m_ComboTerm.GetSafeHwnd();

    // 展开组合框下拉列表
    ::SendMessage(hComboBox, CB_SHOWDROPDOWN, TRUE, 0);
}



void CScoreRegistDialog::OnCbnSelchangeComboTerm3()
{
    // 处理学年选择变化
    //std::vector<ClassOfTeacher> classOfTeacher;
    //std::vector<ClassOfTeacher> classOfTeacherWithYear;
    //std::vector<ClassOfTeacher> classOfTeacherWithSemester;
    //classOfTeacher.reserve(30);
    //classOfTeacherWithYear.reserve(10);
    //classOfTeacherWithSemester.reserve(5);
    //classOfTeacher = TeacherInterface::get().getClassOfTeacher();

    int SelYear = m_ComboYear.GetCurSel();
    if (SelYear != CB_ERR)
    {
        CString strYear;
        m_ComboYear.GetLBText(SelYear, strYear);
        // TODO: 根据选择的学年执行相应的操作

        //for (int i = 0; i < classOfTeacher.size(); i++)
        //{
        //    if (classOfTeacher[i].year == strYear)
        //    {
        //        classOfTeacherWithYear.emplace_back(classOfTeacher[i]);
        //    }
        //}
        ////XK：刷新课程列表
        //RefreshCourseList(classOfTeacherWithYear);
    }

    // 处理学期选择变化
    int SelTerm = m_ComboTerm.GetCurSel();
    if (SelTerm != CB_ERR)
    {
        CString strSemester;
        m_ComboTerm.GetLBText(SelTerm, strSemester);
        // TODO: 根据选择的学期执行相应的操作
        //for (int i = 0; i < classOfTeacherWithYear.size(); i++)
        //{
        //    if (classOfTeacherWithYear[i].semester == strSemester)
        //    {
        //        classOfTeacherWithSemester.emplace_back(classOfTeacherWithYear[i]);
        //    }
        //}
        ////XK：刷新课程列表
        //RefreshCourseList(classOfTeacherWithSemester);
    }
}



void CScoreRegistDialog::OnLvnItemchangedScoreregisterList(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

    for (int i = 0; i < 1; i++)
    {
        CString strMidterm = m_ScoreRegistList.GetItemText(i, 2);
        CString strUsual = m_ScoreRegistList.GetItemText(i, 3);
        CString strFinal = m_ScoreRegistList.GetItemText(i, 4);
        UpdateTotalScore(strMidterm,strUsual,strFinal);
    }

    *pResult = 0;
}


// 更新总成绩函数
void CScoreRegistDialog::UpdateTotalScore(CString strMidterm, CString strUsual, CString strFinal)
{

    double midterm = _tstof(strMidterm);
    double usual = _tstof(strUsual);
    double final = _tstof(strFinal);

    double total = CalculateTotalScore(midterm, usual, final);
    CString strTotal;
    strTotal.Format(_T("%.2f"), total);
    m_ScoreRegistList.SetItemText(m_ScoreRegistList.GetSelectionMark(), 5, strTotal); // 更新选中项的总成绩
}

double CScoreRegistDialog::CalculateTotalScore(double midterm, double usual, double final)
{
    DOUBLE c1 = _tstof(MidtermCompo);
    DOUBLE c2 = _tstof(UsualCompo);
    DOUBLE c3 = _tstof(FinalCompo);
    return midterm * c1 + usual * c2 + final * c3;
}


void CScoreRegistDialog::OnBnClickedButtonCompose()
{
    
    (*GetDlgItem(IDC_EDIT_SCOREREGULAR)).GetWindowText(MidtermCompo);
    (*GetDlgItem(IDC_EDIT_SCOREMID)).GetWindowText(UsualCompo);
    (*GetDlgItem(IDC_EDIT_SCOREFINAL)).GetWindowText(FinalCompo);
}

LRESULT CScoreRegistDialog::OnUpdateList(WPARAM wParam, LPARAM lParam)
{
    m_ScoreRegistList.SetItemText(m_nRow, m_nCol, str);
    return 0;
}
