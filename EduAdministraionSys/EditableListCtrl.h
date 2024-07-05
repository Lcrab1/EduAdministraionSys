#pragma once

#include <afxwin.h>
#include <afxcmn.h>
#include "pch.h"


extern CString str;
extern int m_nRow;
extern int m_nCol;

#define UM_UPADATE_DATA					WM_USER+1000

class CEditableListCtrl : public CListCtrl
{
public:
    CEditableListCtrl();
    virtual ~CEditableListCtrl();

protected:
    afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
    afx_msg void OnEditKillFocus();

    DECLARE_MESSAGE_MAP()

public:
    CEdit m_Edit;

    CWnd* m_Parent;
    void ShowEdit(int nRow, int nCol);
};
