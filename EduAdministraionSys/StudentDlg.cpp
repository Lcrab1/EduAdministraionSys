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

    DDX_Control(pDX, IDC_TREE1, m_TreeCtrl);
}


BEGIN_MESSAGE_MAP(StudentDlg, CDialogEx)

    ON_WM_CTLCOLOR()
    //ON_WM_PAINT()
    ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &StudentDlg::OnTvnSelchangedTree1)
    ON_BN_CLICKED(IDC_BUTTON_INFOCHANGE, &StudentDlg::OnBnClickedButtonInfochange)
END_MESSAGE_MAP()


// StudentDlg 消息处理程序


BOOL StudentDlg::OnInitDialog()
{
    CDialogEx::OnInitDialog();


    OnInitInfoTable();

    // 创建字体，120 表示 12 磅字体大小
    m_font1.CreatePointFont(180, _T("华文新魏"));

    // 获取静态文本控件，并设置新字体
    CStatic* pStaticText = (CStatic*)GetDlgItem(IDC_STATIC_TITLE);
    if (pStaticText != nullptr)
    {
        pStaticText->SetFont(&m_font1);
    }

    InitTreeButton();

    InitSonDialog();



    return TRUE;

}


// yxy:初始化 List Control
//注意List Control控件的使用方法：使用for循环按列set数据
void StudentDlg::OnInitInfoTable()
{

    m_StuInfoList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    // 添加列标题
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

//YXY：初始化功能子窗口
void StudentDlg::InitSonDialog()
{
    m_TermScoreDlg = new CTermScoreDlg();
    m_TermScoreDlg->Create(IDD_TERMSCORE_DIALOG, GetDlgItem(IDC_LIST_STUINFO));

    m_EditInfoDlg = new CEditInfoDlg();
    m_EditInfoDlg->Create(IDD_EDITINFO_DIALOG, GetDlgItem(IDC_LIST_STUINFO));

    m_CourseScoreDlg = new CCourseScoreDlg();
    m_CourseScoreDlg->Create(IDD_COURSESCORE_DIALOG, GetDlgItem(IDC_LIST_STUINFO));
}

//yxy：添加树形控件数据
void StudentDlg::InitTreeButton()
{

    
    // 添加根节点
    HTREEITEM hRoot = m_TreeCtrl.InsertItem(_T("成绩查询"));

    // 添加子节点
    HTREEITEM hChild1 = m_TreeCtrl.InsertItem(_T("查询课程成绩"), hRoot);
    HTREEITEM hChild2 = m_TreeCtrl.InsertItem(_T("查询学期成绩"), hRoot);

    // 展开根节点
    m_TreeCtrl.Expand(hRoot, TVE_EXPAND);
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


    //YXY:绘制顶部条幅
//void StudentDlg::OnPaint()
//{
//    {
//        CPaintDC dc(this); // device context for painting
//
//            // 获取对话框的客户区矩形
//        CRect rect;
//        GetClientRect(&rect);
//
//        // 设置蓝色条幅的矩形区域
//        CRect bannerRect(rect.left, rect.top, rect.right, rect.top + 50); // 高度为50像素的蓝色条幅
//
//        // 设置蓝色画刷
//        CBrush blueBrush(RGB(0, 128, 255)); // 蓝色画刷
//
//        // 填充蓝色条幅区域
//        dc.FillRect(bannerRect, &blueBrush);
//    }
//}


//YXY:选择功能
void StudentDlg::OnTvnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
    
    // 获取点击位置
    CPoint pt;
    GetCursorPos(&pt);
    m_TreeCtrl.ScreenToClient(&pt);

    // 获取点击的节点
    UINT uFlag;
    HTREEITEM hItem = m_TreeCtrl.HitTest(pt, &uFlag);

    if (hItem != NULL && (uFlag & TVHT_ONITEM))
    {
        CString strItemText = m_TreeCtrl.GetItemText(hItem);

        // 根据节点执行相应操作
        if (strItemText == _T("查询课程成绩"))
        {
            m_CourseScoreDlg->ShowWindow(SW_SHOW);
        }
        else if (strItemText == _T("查询学期成绩"))
        {
            m_TermScoreDlg->ShowWindow(SW_SHOW);
        }
        // 可以添加更多节点的处理逻辑
    }

    *pResult = 0;
}


void StudentDlg::OnBnClickedButtonInfochange()
{
    m_EditInfoDlg->ShowWindow(SW_SHOW);
}
