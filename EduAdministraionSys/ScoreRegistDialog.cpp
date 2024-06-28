// ScoreRegistDialog.cpp: 实现文件
//

#include "pch.h"
#include "EduAdministraionSys.h"
#include "ScoreRegistDialog.h"
#include "afxdialogex.h"


// CScoreRegistDialog 对话框

IMPLEMENT_DYNAMIC(CScoreRegistDialog, CDialogEx)

CScoreRegistDialog::CScoreRegistDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SCOREREGIST_DIALOG, pParent)
{

}

CScoreRegistDialog::~CScoreRegistDialog()
{
}

void CScoreRegistDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_COURSE, m_CourseCombox);
}


BEGIN_MESSAGE_MAP(CScoreRegistDialog, CDialogEx)
END_MESSAGE_MAP()


// CScoreRegistDialog 消息处理程序
