// InfoChangeDlg.cpp: 实现文件
//

#include "pch.h"
#include "EduAdministraionSys.h"
#include "InfoChangeDlg.h"
#include "afxdialogex.h"


// CInfoChangeDlg 对话框

IMPLEMENT_DYNAMIC(CInfoChangeDlg, CDialogEx)

CInfoChangeDlg::CInfoChangeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INFOCHANGE_DIALOG, pParent)
{

}

CInfoChangeDlg::~CInfoChangeDlg()
{
}

void CInfoChangeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CInfoChangeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CInfoChangeDlg::OnBnClickedButtonReset)
	ON_BN_CLICKED(IDC_BUTTON_SUBMMIT, &CInfoChangeDlg::OnBnClickedButtonSubmmit)
END_MESSAGE_MAP()


// CInfoChangeDlg 消息处理程序

//YXY:重置数据
void CInfoChangeDlg::OnBnClickedButtonReset()
{
	GetDlgItem(IDC_EDIT_CALL)->SetWindowTextW((LPCTSTR)"");
	GetDlgItem(IDC_EDIT_ENGNAME)->SetWindowTextW((LPCTSTR)"");
	GetDlgItem(IDC_EDIT_EMAIL)->SetWindowTextW((LPCTSTR)"");
}

//yxy：提交信息
void CInfoChangeDlg::OnBnClickedButtonSubmmit()
{
	CString s1 ;
	GetDlgItem(IDC_EDIT_CALL)->GetWindowTextW(s1);//yxy:接受电话号码数据，可以利用cstring"+"把所有数据连起来或得到char

}
