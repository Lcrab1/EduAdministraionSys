#pragma once
#include"Database.h"

// CEditInfoDlg 对话框

class CEditInfoDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CEditInfoDlg)

public:
	CEditInfoDlg(const CString& studentID,CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CEditInfoDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EDITINFO_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_EnglishNameEdit;
	CEdit m_TelephoneEdit;
	CEdit m_EmailEdit;
	afx_msg void OnBnClickedButtonCommit();
	afx_msg void OnBnClickedButtonReset();


private:
	CString m_StudentID;
};
