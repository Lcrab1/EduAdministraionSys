// EditInfoDlg.cpp: 实现文件
//

#include "pch.h"
#include "EduAdministraionSys.h"
#include "EditInfoDlg.h"
#include "afxdialogex.h"


// CEditInfoDlg 对话框

IMPLEMENT_DYNAMIC(CEditInfoDlg, CDialogEx)

CEditInfoDlg::CEditInfoDlg(const CString& studentID, CWnd* pParent /*=nullptr*/)
	: m_StudentID(studentID),CDialogEx(IDD_EDITINFO_DIALOG, pParent)
{

}

CEditInfoDlg::~CEditInfoDlg()
{
}

void CEditInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_ENGNAME, m_EnglishNameEdit);
	DDX_Control(pDX, IDC_EDIT_CALL, m_TelephoneEdit);
	DDX_Control(pDX, IDC_EDIT_EMAIL, m_EmailEdit);
}


BEGIN_MESSAGE_MAP(CEditInfoDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_COMMIT, &CEditInfoDlg::OnBnClickedButtonCommit)
	ON_BN_CLICKED(IDC_BUTTON_RESET, &CEditInfoDlg::OnBnClickedButtonReset)
END_MESSAGE_MAP()


// CEditInfoDlg 消息处理程序
CEdit m_EnglishNameEdit;
CEdit m_TelephoneEdit;
CEdit m_EmailEdit;

//XK：提交修改信息按钮
void CEditInfoDlg::OnBnClickedButtonCommit()
{
	// TODO: 在此添加控件通知处理程序代码
	CString englishName;
	CString telephone;
	CString email;
	m_EnglishNameEdit.GetWindowText(englishName);
	m_TelephoneEdit.GetWindowText(telephone);
	m_EmailEdit.GetWindowText(email);
	Database::getDatabase().ChangePersonalInfo(m_StudentID,englishName, telephone, email);
}

//XK：重置edit控件内容
void CEditInfoDlg::OnBnClickedButtonReset()
{
	// TODO: 在此添加控件通知处理程序代码
	m_EnglishNameEdit.SetWindowText(_T(""));
	m_TelephoneEdit.SetWindowText(_T(""));
	m_EmailEdit.SetWindowText(_T(""));
}
