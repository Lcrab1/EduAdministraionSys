#pragma once


// CScoreRegistDialog 对话框

class CScoreRegistDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CScoreRegistDialog)

public:
	CScoreRegistDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CScoreRegistDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SCOREREGIST_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	virtual BOOL OnInitDialog();
	void InitInfoList();
	void InitializeComboBoxes();


	CComboBox m_CourseCombox;
	CListCtrl m_ScoreRegistList;
	afx_msg void OnCbnSelchangeComboCourse();
};
