// TeacherDlg.cpp: 实现文件
//

#include "pch.h"
#include "EduAdministraionSys.h"
#include "TeacherDlg.h"
#include "afxdialogex.h"


// TeacherDlg 对话框

IMPLEMENT_DYNAMIC(TeacherDlg, CDialogEx)

TeacherDlg::TeacherDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TEACHER_DIALOG, pParent)
{

}

TeacherDlg::~TeacherDlg()
{
}

void TeacherDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(TeacherDlg, CDialogEx)
END_MESSAGE_MAP()


// TeacherDlg 消息处理程序
