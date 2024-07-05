#pragma once


// CCourseScoreDlg 对话框

class CCourseScoreDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CCourseScoreDlg)

public:
	CCourseScoreDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CCourseScoreDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_COURSESCORE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnCbnSelchangeCombo1();
	virtual BOOL OnInitDialog();
	void InitCourseComBox();
	void InitCourseScoreList();



	CComboBox m_Course;//YXY：下拉框选择课程的变量
	CListCtrl m_CourseScoreList;//YXY：成绩表格对应的变量
};

struct CourseGrade
{
	CString CourseName;//课程名称
	CString Semester;//学期名称
	CString Creidt;//学分
	CString MidExam;//期中成绩
	CString DailyPerformance;//平时分
	CString FinalExam;//期末成绩
	CString GeneralScore;//总评成绩
	CString StudyForm;//修读类别
};