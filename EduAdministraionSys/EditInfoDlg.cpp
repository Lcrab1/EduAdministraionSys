// EditInfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "EduAdministraionSys.h"
#include "EditInfoDlg.h"
#include "afxdialogex.h"


// CEditInfoDlg 对话框

IMPLEMENT_DYNAMIC(CEditInfoDlg, CDialogEx)

CEditInfoDlg::CEditInfoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_EDITINFO_DIALOG, pParent)
{

}

CEditInfoDlg::~CEditInfoDlg()
{
}

void CEditInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CEditInfoDlg, CDialogEx)
END_MESSAGE_MAP()


// CEditInfoDlg 消息处理程序
