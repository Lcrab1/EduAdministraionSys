// CourseScoreDlg.cpp: 实现文件
//

#include "pch.h"
#include "EduAdministraionSys.h"
#include "CourseScoreDlg.h"
#include "afxdialogex.h"


// CCourseScoreDlg 对话框

IMPLEMENT_DYNAMIC(CCourseScoreDlg, CDialogEx)

CCourseScoreDlg::CCourseScoreDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_COURSESCORE_DIALOG, pParent)
{

}

CCourseScoreDlg::~CCourseScoreDlg()
{
}

void CCourseScoreDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_Course);
	DDX_Control(pDX, IDC_COURSESCORE_LIST, m_CourseScoreList);
}


BEGIN_MESSAGE_MAP(CCourseScoreDlg, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CCourseScoreDlg::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()



// CCourseScoreDlg 消息处理程序
//YXY:得到选择的课程
void CCourseScoreDlg::OnCbnSelchangeCombo1()
{
	int SelCourse = m_Course.GetCurSel();
	if (SelCourse != CB_ERR)
	{
		
		CString strCourse;
		m_Course.GetLBText(SelCourse, strCourse);


	}
}


BOOL CCourseScoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	InitCourseComBox();

	InitCourseScoreList();

	return TRUE;
				  
}

//YXY：在此添加查到的课程
void CCourseScoreDlg::InitCourseComBox()
{
	m_Course.AddString(_T("示例课程"));



}

//YXY：在此添加成绩数据，示例已给出
void CCourseScoreDlg::InitCourseScoreList()
{
	m_CourseScoreList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// 添加列标题
	m_CourseScoreList.InsertColumn(0, _T("课程名称"), LVCFMT_LEFT, 70);
	m_CourseScoreList.InsertColumn(1, _T("学期名称"), LVCFMT_LEFT, 70);
	m_CourseScoreList.InsertColumn(2, _T("学分"), LVCFMT_LEFT, 45);
	m_CourseScoreList.InsertColumn(3, _T("期中成绩"), LVCFMT_LEFT, 70);
	m_CourseScoreList.InsertColumn(4, _T("平时成绩"), LVCFMT_LEFT, 70);
	m_CourseScoreList.InsertColumn(5, _T("期末成绩"), LVCFMT_LEFT, 70);
	m_CourseScoreList.InsertColumn(6, _T("总评成绩"), LVCFMT_LEFT, 70);
	m_CourseScoreList.InsertColumn(7, _T("修读类别"), LVCFMT_LEFT, 70);

	//示例
	m_CourseScoreList.SetItemText(0, 1, _T(""));
}
