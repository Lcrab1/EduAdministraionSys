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
	void InitializeScoreList();
	DECLARE_MESSAGE_MAP()
	virtual BOOL OnInitDialog();
	afx_msg void OnCbnSelchangeComboTerm();


public:

	CComboBox m_ComboYear;//YXY：学年选择
	CComboBox m_ComboTerm;//YXY：学期选择



	CListCtrl m_ScoreList;
};
