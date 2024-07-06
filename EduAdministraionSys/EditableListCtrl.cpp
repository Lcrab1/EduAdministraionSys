#include "EditableListCtrl.h"
#include "Resource.h"
#include"ScoreRegistDialog.h"



BEGIN_MESSAGE_MAP(CEditableListCtrl, CListCtrl)
    ON_WM_LBUTTONDBLCLK()
    ON_EN_KILLFOCUS(IDC_EDIT_TRAVEL, OnEditKillFocus)

    ON_NOTIFY_REFLECT(NM_RCLICK, &CEditableListCtrl::OnNMRClick)
END_MESSAGE_MAP()

CEditableListCtrl::CEditableListCtrl(CWnd* pParent /*=nullptr*/)
    :CListCtrl(), m_pParentWnd(pParent)
{
    //HANDLE ThreadHandle =
    //    CreateThread
    //    (
    //        NULL,
    //        0,
    //        (LPTHREAD_START_ROUTINE)RefreshListThread,
    //        this,
    //        0,
    //        0
    //    );


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
    m_Edit.SetWindowText(_T(""));
    m_Edit.ShowWindow(SW_HIDE);
    SetItemText(m_nRow, m_nCol, str);
}

void CEditableListCtrl::OnLvnItemClick(NMHDR* pNMHDR, LRESULT* pResult)
{
}



void CEditableListCtrl::OnNMRClick(NMHDR* pNMHDR, LRESULT* pResult)
{
    LPNMITEMACTIVATE pNMItemActivate = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);



    if (m_nCol != -1)
    {
        if (m_nRow != NumOfStudent)
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


    *pResult = 0;
}



DWORD __stdcall RefreshListThread(LPVOID ParameterData)
{
    CEditableListCtrl* p1 = (CEditableListCtrl*)ParameterData;
    //while (1)
    //{
    //p1->UpdateData(FALSE);
    //(*p1).Invalidate();
    //(*p1).UpdateWindow();
    //Sleep(1000);
    //}

    return 0;
}
