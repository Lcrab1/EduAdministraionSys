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
}


BEGIN_MESSAGE_MAP(StudentDlg, CDialogEx)
END_MESSAGE_MAP()


// StudentDlg 消息处理程序
