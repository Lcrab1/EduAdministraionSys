#pragma once
#include"EditableListCtrl.h"
#include"Database.h"
#include"TeacherInterface.h"

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
	void		 InitInfoList();
	void		 InitializeComboBoxes();
	afx_msg void OnCbnSelchangeComboCourse();
	void		 InitializeTermComboBoxes();
	afx_msg void OnCbnSelchangeComboYear3();
	afx_msg void OnCbnSelchangeComboTerm3();
	afx_msg void OnLvnItemchangedScoreregisterList(NMHDR* pNMHDR, LRESULT* pResult);
	void			UpdateTotalScore(CString strMidterm, CString strUsual, CString strFinal);
	double			CalculateTotalScore(double midterm, double usual, double final);
	afx_msg void	OnBnClickedButtonCompose();
	void			RefreshCourseList(IN const std::vector<ClassOfStudentScore>& classOfStudentScore);



	CComboBox m_CourseCombox;
	CEditableListCtrl  m_ScoreRegistList;
	CComboBox m_ComboYear;
	CComboBox m_ComboTerm;
	CString MidtermCompo, UsualCompo, FinalCompo;

	CEdit m_EditTravel;
	
};


