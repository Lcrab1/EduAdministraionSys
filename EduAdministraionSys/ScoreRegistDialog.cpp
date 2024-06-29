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
}


BEGIN_MESSAGE_MAP(CScoreRegistDialog, CDialogEx)
    ON_CBN_SELCHANGE(IDC_COMBO_COURSE, &CScoreRegistDialog::OnCbnSelchangeComboCourse)
END_MESSAGE_MAP()


// CScoreRegistDialog 消息处理程序


BOOL CScoreRegistDialog::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    InitInfoList();

    InitializeComboBoxes();

    return TRUE;
}

//YXY： 初始化列表控件
void CScoreRegistDialog::InitInfoList()
{


    m_ScoreRegistList.InsertColumn(0, _T("分数构成"), LVCFMT_LEFT, 100);
    m_ScoreRegistList.InsertColumn(1, _T("占比"), LVCFMT_LEFT, 100);

    m_ScoreRegistList.InsertItem(0, _T("期中成绩"));
    m_ScoreRegistList.SetItemText(0, 1, _T("0.1"));

    m_ScoreRegistList.InsertItem(1, _T("期末成绩"));
    m_ScoreRegistList.SetItemText(1, 1, _T("0.6"));

    m_ScoreRegistList.InsertItem(2, _T("平时成绩"));
    m_ScoreRegistList.SetItemText(2, 1, _T("0.3"));

}

//YXY:初始化课程选择控件
//添加数据示例已给出
void CScoreRegistDialog::InitializeComboBoxes()
{

    // 添加查到的课程
    m_CourseCombox.AddString(_T("导管原理"));

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
