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
}


BEGIN_MESSAGE_MAP(CTermScoreDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO_YEAR, &CTermScoreDlg::OnCbnSelchangeComboYear)
    ON_CBN_SELCHANGE(IDC_COMBO_TERM, &CTermScoreDlg::OnCbnSelchangeComboTerm)
    ON_NOTIFY(LVN_ITEMCHANGED, IDC_TERMSCORE_LIST, &CTermScoreDlg::OnLvnItemchangedTermscoreList)
END_MESSAGE_MAP()


// CTermScoreDlg 消息处理程序


//YXY:组合两个下拉框
void CTermScoreDlg::OnCbnSelchangeComboYear()
{
	m_ComboTerm.ShowWindow(SW_SHOW);
    HWND hComboBox = m_ComboTerm.GetSafeHwnd();

    // 展开组合框下拉列表
    ::SendMessage(hComboBox, CB_SHOWDROPDOWN, TRUE, 0);
}

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


BOOL CTermScoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


    InitializeComboBoxes();

	return TRUE;
}


void CTermScoreDlg::OnCbnSelchangeComboTerm()
{

}


void CTermScoreDlg::OnLvnItemchangedTermscoreList(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
    // TODO: 在此添加控件通知处理程序代码
    *pResult = 0;
}
