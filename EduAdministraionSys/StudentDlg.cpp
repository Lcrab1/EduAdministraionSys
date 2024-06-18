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
    DDX_Control(pDX, IDC_STATIC_SCHOOL, m_pcsch);
    DDX_Control(pDX, IDC_LIST_STU_INFO, m_StuInfoList);
    DDX_Control(pDX, IDC_COMBO_SCORE, m_ComboxScore);
}


BEGIN_MESSAGE_MAP(StudentDlg, CDialogEx)
	ON_WM_PAINT()
    ON_NOTIFY(NM_CUSTOMDRAW, IDC_LIST_STU_INFO, &StudentDlg::OnNMCustomdrawListStuInfo)
    ON_BN_CLICKED(IDC_BUTTON_CHANGEINFO, &StudentDlg::OnBnClickedButtonChangeinfo)
    ON_CBN_SELCHANGE(IDC_COMBO1, &StudentDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// StudentDlg 消息处理程序


void StudentDlg::OnPaint()
{
    CPaintDC dc(this); // 用于绘制的设备上下文

}


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


void StudentDlg::OnNMCustomdrawListStuInfo(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
    

      LPNMLVCUSTOMDRAW pLVCD = reinterpret_cast<LPNMLVCUSTOMDRAW>(pNMHDR);
    
    switch (pLVCD->nmcd.dwDrawStage)
    {
    case CDDS_PREPAINT:
        *pResult = CDRF_NOTIFYITEMDRAW;
        break;

    case CDDS_ITEMPREPAINT:
        *pResult = CDRF_NOTIFYSUBITEMDRAW;
        break;

    case CDDS_SUBITEM | CDDS_ITEMPREPAINT:
        // 在这里设置列颜色
        if (pLVCD->iSubItem == 0) // 第一列
        {
            pLVCD->clrTextBk = RGB(255, 255, 0); // 设置背景颜色为黄色
            pLVCD->clrText = RGB(255, 0, 0);       // 设置文本颜色为黑色
        }
        else if (pLVCD->iSubItem == 1) // 第二列
        {
            pLVCD->clrTextBk = RGB(0, 255, 255); // 设置背景颜色为青色
            pLVCD->clrText = RGB(0, 0, 0);       // 设置文本颜色为黑色
        }
        *pResult = CDRF_DODEFAULT;
        break;

    default:
        *pResult = CDRF_DODEFAULT;
        break;
    }




    *pResult = 0;
}


void StudentDlg::OnBnClickedButtonChangeinfo()
{
    // TODO: 在此添加控件通知处理程序代码
}


void StudentDlg::OnCbnSelchangeCombo1()
{
    // TODO: 在此添加控件通知处理程序代码
}
