#pragma once

#include <afxwin.h>
#include <afxcmn.h>
#include "pch.h"




class CEditableListCtrl : public CListCtrl
{
public:
    CEditableListCtrl(CWnd* pParent /*=nullptr*/);
    virtual ~CEditableListCtrl();

protected:
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnEditKillFocus();
    afx_msg void OnLvnItemClick(NMHDR* pNMHDR, LRESULT* pResult);
    DECLARE_MESSAGE_MAP()
    void ShowEdit(int nRow, int nCol);

public:
    CEdit m_Edit;
    CWnd* m_pParentWnd;
    CString str;
    int m_nRow = -1;
    int m_nCol = -1;

    afx_msg void OnNMRClick(NMHDR* pNMHDR, LRESULT* pResult);

    
};
DWORD WINAPI RefreshListThread(LPVOID ParameterData);