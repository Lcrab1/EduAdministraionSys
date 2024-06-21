#pragma once


// CTermScoreDlg 对话框

class CTermScoreDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTermScoreDlg)

public:
	CTermScoreDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CTermScoreDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TERMSCORE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持
	afx_msg void OnCbnSelchangeComboYear();
	void InitializeComboBoxes();
	DECLARE_MESSAGE_MAP()
public:

	CComboBox m_ComboYear;
	CComboBox m_ComboTerm;

	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboTerm();
	afx_msg void OnLvnItemchangedTermscoreList(NMHDR* pNMHDR, LRESULT* pResult);
};
