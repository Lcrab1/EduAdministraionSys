// CourseScoreDlg.cpp: 实现文件
//

#include "pch.h"
#include "EduAdministraionSys.h"
#include "CourseScoreDlg.h"
#include "afxdialogex.h"


// CCourseScoreDlg 对话框

IMPLEMENT_DYNAMIC(CCourseScoreDlg, CDialogEx)

CCourseScoreDlg::CCourseScoreDlg(const CString& StudentID, CWnd* pParent /*=nullptr*/)
	: m_StudentID(StudentID),CDialogEx(IDD_COURSESCORE_DIALOG, pParent)
{
	m_CourseInfo.reserve(15);

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
		CourseGrade courseGrade;
		Database::getDatabase().searchStudentCourseScore(m_StudentID, strCourse, courseGrade);
		
		m_CourseScoreList.DeleteAllItems();
		//InitCourseScoreList();
		m_CourseScoreList.InsertItem(0, courseGrade.courseName);
		m_CourseScoreList.SetItemText(0, 1, courseGrade.year);
		m_CourseScoreList.SetItemText(0, 2, courseGrade.semester);
		m_CourseScoreList.SetItemText(0, 3, courseGrade.credit);
		m_CourseScoreList.SetItemText(0, 4, courseGrade.midScore);
		m_CourseScoreList.SetItemText(0, 5, courseGrade.usualScore);
		m_CourseScoreList.SetItemText(0, 6, courseGrade.finalScore);
		m_CourseScoreList.SetItemText(0, 7, courseGrade.totalScore);
	}
}


BOOL CCourseScoreDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	Database::getDatabase().searchAllCourse(m_StudentID,m_CourseInfo);

	InitCourseComBox();

	InitCourseScoreList();

	return TRUE;
				  
}

//YXY：在此添加查到的课程
void CCourseScoreDlg::InitCourseComBox()
{
	//m_Course.AddString(_T("示例课程"));

	for (int i = 0; i < m_CourseInfo.size(); i++)
	{
		m_Course.AddString(m_CourseInfo[i]);
	}

}

//YXY：在此添加成绩数据，示例已给出
void CCourseScoreDlg::InitCourseScoreList()
{
	m_CourseScoreList.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	// 添加列标题
	m_CourseScoreList.InsertColumn(0, _T("课程名称"), LVCFMT_LEFT, 120);
	m_CourseScoreList.InsertColumn(1, _T("学年"), LVCFMT_LEFT, 70);
	m_CourseScoreList.InsertColumn(2, _T("学期"), LVCFMT_LEFT, 50);
	m_CourseScoreList.InsertColumn(3, _T("学分"), LVCFMT_LEFT, 45);
	m_CourseScoreList.InsertColumn(4, _T("期中成绩"), LVCFMT_LEFT, 60);
	m_CourseScoreList.InsertColumn(5, _T("平时成绩"), LVCFMT_LEFT, 60);
	m_CourseScoreList.InsertColumn(6, _T("期末成绩"), LVCFMT_LEFT, 60);
	m_CourseScoreList.InsertColumn(7, _T("总评成绩"), LVCFMT_LEFT, 60);
	
		
	//示例
	//m_CourseScoreList.SetItemText(0, 1, _T(""));
}

