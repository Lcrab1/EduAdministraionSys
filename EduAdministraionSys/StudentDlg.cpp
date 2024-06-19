// StudentDlg.cpp: 实现文件
//

#include "pch.h"
#include "EduAdministraionSys.h"
#include "StudentDlg.h"
#include "afxdialogex.h"


// StudentDlg 对话框

IMPLEMENT_DYNAMIC(StudentDlg, CDialogEx)

StudentDlg::StudentDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_STUDENT_DIALOG, pParent)
{

}

StudentDlg::~StudentDlg()
{
}

void StudentDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LIST_STUINFO, m_StuInfoList);
    DDX_Control(pDX, IDC_COMBO_SCORE, m_ComboxScore);
}


BEGIN_MESSAGE_MAP(StudentDlg, CDialogEx)

    ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// StudentDlg 消息处理程序


BOOL StudentDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();


    // 初始化 List Control
    m_StuInfoList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    {
        // 添加列
        m_StuInfoList.InsertColumn(0, _T("属性"), LVCFMT_LEFT, 75);
        m_StuInfoList.InsertColumn(1, _T("值"), LVCFMT_LEFT, 125);
        m_StuInfoList.InsertColumn(2, _T("属性"), LVCFMT_LEFT, 75);
        m_StuInfoList.InsertColumn(3, _T("值"), LVCFMT_LEFT, 125);
        // 添加数据行
        m_StuInfoList.InsertItem(0, _T("学号"));
        m_StuInfoList.SetItemText(0, 1, _T("202290000"));
        m_StuInfoList.SetItemText(0, 2, _T("姓名"));
        m_StuInfoList.SetItemText(0, 3, _T("fuck u"));

        m_StuInfoList.InsertItem(1, _T("英文名"));
        m_StuInfoList.SetItemText(1, 1, _T("shabi"));
        m_StuInfoList.SetItemText(1, 2, _T("民族"));
        m_StuInfoList.SetItemText(1, 3, _T("汉"));

        m_StuInfoList.InsertItem(2, _T("所在年级"));
        m_StuInfoList.SetItemText(2, 1, _T("2022"));
        m_StuInfoList.SetItemText(1, 2, _T("性别"));
        m_StuInfoList.SetItemText(1, 3, _T("男"));

        m_StuInfoList.InsertItem(3, _T("行政学院"));
        m_StuInfoList.SetItemText(3, 1, _T("信息工程学院"));
        m_StuInfoList.SetItemText(1, 2, _T("专业"));
        m_StuInfoList.SetItemText(1, 3, _T("计算机科学与技术"));

        m_StuInfoList.InsertItem(4, _T("学生类别"));
        m_StuInfoList.SetItemText(4, 1, _T("行政班级"));
        m_StuInfoList.SetItemText(1, 2, _T("学制"));
        m_StuInfoList.SetItemText(1, 3, _T("预毕业时间"));

        m_StuInfoList.InsertItem(5, _T("生源地"));
        m_StuInfoList.SetItemText(5, 1, _T("陕西省"));
        m_StuInfoList.SetItemText(5, 2, _T("学习形式"));
        m_StuInfoList.SetItemText(5, 3, _T("非全日制本科"));

        m_StuInfoList.InsertItem(6, _T("电子邮箱"));
        m_StuInfoList.SetItemText(6, 1, _T("123@chd.edu.cn"));
        m_StuInfoList.SetItemText(6, 2, _T("联系电话"));
        m_StuInfoList.SetItemText(6, 3, _T("123456"));

    }

    // 创建字体，120 表示 12 磅字体大小
    m_font1.CreatePointFont(180, _T("华文新魏"));

    // 获取静态文本控件，并设置新字体
    CStatic* pStaticText = (CStatic*)GetDlgItem(IDC_STATIC_TITLE);
    if (pStaticText != nullptr)
    {
        pStaticText->SetFont(&m_font1);
    }

    m_ComboxScore.SetWindowText(_T("我的成绩"));




    return TRUE;

}





HBRUSH StudentDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

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

    return hbr;
}
