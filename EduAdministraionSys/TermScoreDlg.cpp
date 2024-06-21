// TermScoreDlg.cpp: 实现文件
//

#include "pch.h"
#include "EduAdministraionSys.h"
#include "TermScoreDlg.h"
#include "afxdialogex.h"


// CTermScoreDlg 对话框

IMPLEMENT_DYNAMIC(CTermScoreDlg, CDialogEx)

CTermScoreDlg::CTermScoreDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TERMSCORE_DIALOG, pParent)
{

}

CTermScoreDlg::~CTermScoreDlg()
{
}

void CTermScoreDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_COMBO_YEAR, m_ComboYear);
    DDX_Control(pDX, IDC_COMBO_TERM, m_ComboTerm);
    DDX_Control(pDX, IDC_TERMSCORE_LIST, m_ScoreList);
}


BEGIN_MESSAGE_MAP(CTermScoreDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_YEAR, &CTermScoreDlg::OnCbnSelchangeComboYear)
    ON_CBN_SELCHANGE(IDC_COMBO_TERM, &CTermScoreDlg::OnCbnSelchangeComboTerm)
END_MESSAGE_MAP()




BOOL CTermScoreDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();


    InitializeComboBoxes();

    InitializeScoreList();



    return TRUE;
}

//YXY:组合两个下拉框
void CTermScoreDlg::OnCbnSelchangeComboYear()
{
	m_ComboTerm.ShowWindow(SW_SHOW);
    HWND hComboBox = m_ComboTerm.GetSafeHwnd();

    // 展开组合框下拉列表
    ::SendMessage(hComboBox, CB_SHOWDROPDOWN, TRUE, 0);
}

//YXY:初始化学期选择控件
void CTermScoreDlg::InitializeComboBoxes()
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

void CTermScoreDlg::InitializeScoreList()
{
    m_ScoreList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // 添加列标题
    m_ScoreList.InsertColumn(0, _T("学期ID"), LVCFMT_LEFT, 70);
    m_ScoreList.InsertColumn(1, _T("学期名称"), LVCFMT_LEFT, 70);
    m_ScoreList.InsertColumn(2, _T("课程"), LVCFMT_LEFT, 70);
    m_ScoreList.InsertColumn(3, _T("学分"), LVCFMT_LEFT, 50);
    m_ScoreList.InsertColumn(4, _T("期中成绩"), LVCFMT_LEFT, 70);
    m_ScoreList.InsertColumn(5, _T("平时成绩"), LVCFMT_LEFT, 70);
    m_ScoreList.InsertColumn(6, _T("期末成绩"), LVCFMT_LEFT, 70);
    m_ScoreList.InsertColumn(7, _T("总评成绩"), LVCFMT_LEFT, 70);

    //添加数据的示例，直接crud
    m_ScoreList.InsertItem(0, _T("23-24-1"));
    m_ScoreList.SetItemText(0, 2, _T("导管原理"));
}




//YXY：选择学期完毕，处理数据
void CTermScoreDlg::OnCbnSelchangeComboTerm()
{
    // 处理学年选择变化
    int SelYear = m_ComboYear.GetCurSel();
    if (SelYear != CB_ERR)
    {
        CString strYear;
        m_ComboYear.GetLBText(SelYear, strYear);
        // TODO: 根据选择的学年执行相应的操作



        MessageBox(strYear, 0, 0);





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



