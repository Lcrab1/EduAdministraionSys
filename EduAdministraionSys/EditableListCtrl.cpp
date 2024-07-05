#include "EditableListCtrl.h"
#include "Resource.h"
#include"ScoreRegistDialog.h"



BEGIN_MESSAGE_MAP(CEditableListCtrl, CListCtrl)
    ON_WM_LBUTTONDBLCLK()
    ON_EN_KILLFOCUS(IDC_EDIT_TRAVEL, OnEditKillFocus)
END_MESSAGE_MAP()

CEditableListCtrl::CEditableListCtrl(CWnd* pParent /*=nullptr*/)
    :CListCtrl(), m_pParentWnd(pParent)
{

}

CEditableListCtrl::~CEditableListCtrl()
{
}

void CEditableListCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{   

    //无法实现得到双击的框，nitem始终执行失败
    //LVHITTESTINFO hitTestInfo;
    //hitTestInfo.pt = point;
    //int nItem = HitTest(&hitTestInfo);

    //if (nItem != -1 && hitTestInfo.iSubItem != -1)
    //{
    //    ShowEdit(nItem, hitTestInfo.iSubItem);
    //}
    int NumofStudent = 4;

    if (m_nCol!=-1)
    {
        if(m_nRow!= NumofStudent)
        {
            if (m_nCol != 4)
            {
                m_nCol++;
            }
            else
            {
                m_nRow++;
                m_nCol = 2;
            }
            ShowEdit(m_nRow, m_nCol);
        }
    }
    else
    {
        ShowEdit(0, 2);
    }

    CListCtrl::OnLButtonDblClk(nFlags, point);
}

void CEditableListCtrl::ShowEdit(int nRow, int nCol)
{
    CRect rect;
    GetSubItemRect(nRow, nCol, LVIR_BOUNDS, rect);
    rect.DeflateRect(1, 1);  // Optional: Deflate the rect to add some padding

    // Create edit control if not created
    if (!m_Edit.GetSafeHwnd())
    {
        m_Edit.Create(WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL, rect, this, IDC_EDIT_TRAVEL);
    }
    else
    {
        m_Edit.MoveWindow(&rect);
    }
    
    //(*GetDlgItem(IDC_EDIT_TRAVEL)).SetWindowText(GetItemText(nRow, nCol));
    m_Edit.ShowWindow(SW_SHOW);
    m_Edit.SetFocus();
    m_nRow = nRow;
    m_nCol = nCol;
}

void CEditableListCtrl::OnEditKillFocus()
{
    CString str;
    m_Edit.GetWindowText(str);
    SendMessage(UM_UPADATE_DATA);
    m_Edit.SetWindowText(_T(""));
    SetItemText(m_nRow, m_nCol, str);
    CString s1= GetItemText(m_nRow, m_nCol);
}

