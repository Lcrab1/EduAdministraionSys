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
    ON_WM_PAINT()
END_MESSAGE_MAP()


// StudentDlg 消息处理程序


BOOL StudentDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();


    // yxy:初始化 List Control
    //注意List Control控件的使用方法：使用for循环按列set数据
    m_StuInfoList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    {
        // 添加列
        m_StuInfoList.InsertColumn(0, _T("信息"), LVCFMT_LEFT, 75);
        m_StuInfoList.InsertColumn(1, _T(""), LVCFMT_LEFT, 125);
        m_StuInfoList.InsertColumn(2, _T("信息"), LVCFMT_LEFT, 75);
        m_StuInfoList.InsertColumn(3, _T(""), LVCFMT_LEFT, 125);
        // 添加数据行
        m_StuInfoList.InsertItem(0, _T("学号"));
        
        m_StuInfoList.SetItemText(0, 2, _T("姓名"));
       

        m_StuInfoList.InsertItem(1, _T("英文名"));
       
        m_StuInfoList.SetItemText(1, 2, _T("民族"));
     

        m_StuInfoList.InsertItem(2, _T("所在年级"));

        m_StuInfoList.SetItemText(2, 2, _T("性别"));
   

        m_StuInfoList.InsertItem(3, _T("行政学院"));
 
        m_StuInfoList.SetItemText(3, 2, _T("专业"));
     

        m_StuInfoList.InsertItem(4, _T("学生类别"));
    
        m_StuInfoList.SetItemText(4, 2, _T("学制"));
  

        m_StuInfoList.InsertItem(5, _T("生源地"));
   
        m_StuInfoList.SetItemText(5, 2, _T("学习形式"));
     

        m_StuInfoList.InsertItem(6, _T("电子邮箱"));
   
        m_StuInfoList.SetItemText(6, 2, _T("联系电话"));
 

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




//修改主窗口控件颜色
HBRUSH StudentDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
    HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

    //yxy:修改文本框背景为白色
    if (pWnd->GetDlgCtrlID() == IDC_STATIC_TITLE)
    {

        //pDC->SetTextColor(RGB(255, 0, 0));//设置字体颜色

        //pDC->SetBkColor(RGB(255, 255, 255));//设置背景颜色

        pDC->SetBkMode(TRANSPARENT);//设置背景透明

        return (HBRUSH)(m_Brush.GetSafeHandle());
    }

    //YXY:修改顶部信息条背景
    if (pWnd->GetDlgCtrlID() == IDC_STATIC_TOPINFO)
    {
        //pDC->SetTextColor(RGB(255, 0, 0));//设置字体颜色

        //pDC->SetBkColor(RGB(255, 255, 255));//设置背景颜色

        pDC->SetBkMode(TRANSPARENT);//设置背景透明

        return (HBRUSH)(m_Brush.GetSafeHandle());
    }

    //YXY:修改主对话框背景为白色
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



void StudentDlg::OnPaint()
{
    //YXY:绘制顶部条幅
    {
        CPaintDC dc(this); // device context for painting

            // 获取对话框的客户区矩形
        CRect rect;
        GetClientRect(&rect);

        // 设置蓝色条幅的矩形区域
        CRect bannerRect(rect.left, rect.top, rect.right, rect.top + 50); // 高度为50像素的蓝色条幅

        // 设置蓝色画刷
        CBrush blueBrush(RGB(0, 128, 255)); // 蓝色画刷

        // 填充蓝色条幅区域
        dc.FillRect(bannerRect, &blueBrush);
    }


}
