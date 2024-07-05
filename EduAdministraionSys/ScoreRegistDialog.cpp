// ScoreRegistDialog.cpp: 实现文件
//

#include "pch.h"
#include "EduAdministraionSys.h"
#include "ScoreRegistDialog.h"
#include "afxdialogex.h"


// CScoreRegistDialog 对话框

IMPLEMENT_DYNAMIC(CScoreRegistDialog, CDialogEx)

CScoreRegistDialog::CScoreRegistDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCOREREGIST_DIALOG, pParent), m_ScoreRegistList(this)
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

    m_ScoreRegistList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    // Insert columns
    m_ScoreRegistList.InsertColumn(0, _T("学号"), LVCFMT_LEFT, 75);
    m_ScoreRegistList.InsertColumn(1, _T("学生姓名"), LVCFMT_LEFT, 75);
    m_ScoreRegistList.InsertColumn(2, _T("平时成绩"), LVCFMT_LEFT, 75);
    m_ScoreRegistList.InsertColumn(3, _T("期中成绩"), LVCFMT_LEFT, 75);
    m_ScoreRegistList.InsertColumn(4, _T("期末成绩"), LVCFMT_LEFT, 75);
    m_ScoreRegistList.InsertColumn(5, _T("总评成绩"), LVCFMT_LEFT, 75);


    int nItem = m_ScoreRegistList.InsertItem(0, _T("123456"));

}

//YXY:初始化课程选择控件
//添加数据示例已给出
void CScoreRegistDialog::InitializeComboBoxes()
{
    m_CourseCombox.ShowWindow(SW_HIDE);
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
    m_CourseCombox.ShowWindow(SW_SHOW);
    HWND hComboBox = m_CourseCombox.GetSafeHwnd();

    // 展开组合框下拉列表
    ::SendMessage(hComboBox, CB_SHOWDROPDOWN, TRUE, 0);
}


//YXY：选择指定课程后的操作
void CScoreRegistDialog::OnCbnSelchangeComboCourse()
{



    //处理选择的课程名
    int SelCourse = m_CourseCombox.GetCurSel();
    if (SelCourse != CB_ERR)
    {
        CString CourseName;
        m_CourseCombox.GetLBText(SelCourse, CourseName);
        //使用CourseName查询信息
        std::vector<ClassOfStudentScore>* classOfStudentScore = NULL;
        classOfStudentScore = &TeacherInterface::get().getClassOfStudentScore();
        classOfStudentScore->reserve(10);
        Database::getDatabase().GetClassOfSC(CourseName, *classOfStudentScore);

        RefreshCourseCombox(*classOfStudentScore);
    }





    //处理学年选择变化
    std::vector<ClassOfStudentScore> classOfStudentScore;
    std::vector<ClassOfStudentScore> classOfStudentScoreWithYear;
    std::vector<ClassOfStudentScore> classOfStudentScoreWithSemester;
    std::vector<ClassOfStudentScore> classOfStudentScoreWithCourseName;

    classOfStudentScore.reserve(500);
    classOfStudentScoreWithYear.reserve(200);
    classOfStudentScoreWithSemester.reserve(100);
    classOfStudentScoreWithCourseName.reserve(50);
    classOfStudentScore = TeacherInterface::get().getClassOfStudentScore();

    int SelYear = m_ComboYear.GetCurSel();
    if (SelYear != CB_ERR)
    {
        CString strYear;
        m_ComboYear.GetLBText(SelYear, strYear);

        for (int i = 0; i < classOfStudentScore.size(); i++)
        {
            if (classOfStudentScore[i].year == strYear)
            {
                classOfStudentScoreWithYear.emplace_back(classOfStudentScore[i]);
            }
        }
        //刷新课程列表
       // RefreshCourseList(classOfStudentScoreWithYear);
    }

    // 处理学期选择变化
    int SelTerm = m_ComboTerm.GetCurSel();
    if (SelTerm != CB_ERR)
    {
        CString strSemester;
        m_ComboTerm.GetLBText(SelTerm, strSemester);

        for (int i = 0; i < classOfStudentScoreWithYear.size(); i++)
        {
            if (classOfStudentScoreWithYear[i].semester == strSemester)
            {
                classOfStudentScoreWithSemester.emplace_back(classOfStudentScoreWithYear[i]);
            }
        }

        //RefreshCourseList(classOfStudentScoreWithSemester);
    }


    CString CourseName;
    m_CourseCombox.GetLBText(SelCourse, CourseName);
        for (int i = 0; i < classOfStudentScoreWithSemester.size(); i++)
        {
            if (classOfStudentScoreWithSemester[i].CourseName == CourseName)
            {
                classOfStudentScoreWithCourseName.emplace_back(classOfStudentScoreWithSemester[i]);
            }
        }
        RefreshCourseList(classOfStudentScoreWithSemester);
    
}

void CScoreRegistDialog::RefreshCourseCombox(IN const std::vector<ClassOfStudentScore>& classOfStudentScore)
{
    m_ScoreRegistList.DeleteAllItems();
    const std::vector<ClassOfStudentScore>* SCInfo = &classOfStudentScore;
    if (SCInfo->size() == 0)
    {
        return;
    }

    for (int i = 0; i < SCInfo->size(); i++)
    {
        m_CourseCombox.AddString((*SCInfo)[i].CourseName);
    }
}


void CScoreRegistDialog::RefreshCourseList(IN const std::vector<ClassOfStudentScore>& classOfStudentScore)
{
    m_ScoreRegistList.DeleteAllItems();
        const std::vector<ClassOfStudentScore>* SCInfo = &classOfStudentScore;
        if (SCInfo->size() == 0)
        {
            return;
        }
        int column = 0;
        NumOfStudent = SCInfo->size();
        for (int i = 0; i < NumOfStudent; i++)
        {
            m_ScoreRegistList.InsertItem(column, (*SCInfo)[i].studentID);
            m_ScoreRegistList.SetItemText(column, 1, (*SCInfo)[i].studentName);
            column++;
        }

}




void CScoreRegistDialog::OnBnClickedButtonCompose()
{
    
    (*GetDlgItem(IDC_EDIT_SCOREREGULAR)).GetWindowText(MidtermCompo);
    (*GetDlgItem(IDC_EDIT_SCOREMID)).GetWindowText(UsualCompo);
    (*GetDlgItem(IDC_EDIT_SCOREFINAL)).GetWindowText(FinalCompo);
}


void CScoreRegistDialog::OnLvnItemchangedScoreregisterList(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

    for (int i = 0; i < NumOfStudent; i++)
    {
        CString strMidterm = m_ScoreRegistList.GetItemText(i, 2);
        CString strUsual = m_ScoreRegistList.GetItemText(i, 3);
        CString strFinal = m_ScoreRegistList.GetItemText(i, 4);
        if (strMidterm.IsEmpty())
        {
            return;
        }
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






