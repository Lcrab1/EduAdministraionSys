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
}


BEGIN_MESSAGE_MAP(CCourseScoreDlg, CDialogEx)
END_MESSAGE_MAP()


// CCourseScoreDlg 消息处理程序
