// FormView11.cpp : implementation file
//

#include "stdafx.h"
#include "Test1.h"
#include "FormView11.h"
#include "FormView22.h"
#include "MainFrm.h"
#include <vector>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFormView11

IMPLEMENT_DYNCREATE(CFormView11, CFormView)

CFormView11::CFormView11()
	: CFormView(CFormView11::IDD)
{
	//{{AFX_DATA_INIT(CFormView11)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT

// 	m_pDBinfo = new CDatabaseInfo();
}

CFormView11::~CFormView11()
{
}

void CFormView11::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFormView11)
	DDX_Control(pDX, IDC_TREE1, m_tree);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CFormView11, CFormView)
	//{{AFX_MSG_MAP(CFormView11)
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
	ON_NOTIFY(TVN_SELCHANGED, IDC_TREE1, &CFormView11::OnTvnSelchangedTree1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFormView11 diagnostics

#ifdef _DEBUG
void CFormView11::AssertValid() const
{
	CFormView::AssertValid();
}

void CFormView11::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFormView11 message handlers

int CFormView11::ReFreshTree(const CString &strUser, const CString &strPasswd)
{
	//DRAW TREE
	CRect rect;
	GetClientRect(&rect);
	this->GetClientRect(&rect);
	
	m_tree.MoveWindow(rect);
	m_tree.ShowWindow(SW_SHOW);

	m_tree.DeleteAllItems();

	HTREEITEM root = m_tree.GetRootItem();

	vector<CString> vecDB;
	vector<CString> vecTbl;
// 	CDatabaseInfo dbinfo;

	m_pDBinfo = CDatabaseInfo::GetInstance();

	m_pDBinfo->OpenScsdb();

	CString strSql;
	strSql.Format("show databases");
	vector<vector<CString> > vecRes;
	m_pDBinfo->ExecuteSql(strSql,vecRes);

// 	m_pDBinfo->GetDatabases(vecDB);

	for (vector<CString>::iterator iterDB = vecDB.begin();
		iterDB != vecDB.end();++iterDB)
	{
			HTREEITEM itemdatabase = m_tree.InsertItem(*iterDB,root);
			HTREEITEM itemTbl = m_tree.InsertItem("Table",itemdatabase);

			m_pDBinfo->GetTables(*iterDB,vecTbl);
			for (vector<CString>::iterator iterTbl = vecTbl.begin();
			iterTbl != vecTbl.end();++iterTbl)
			{
				m_tree.InsertItem(*iterTbl,itemTbl);
			}
	}

	//HTREEITEM item = m_tree.InsertItem("hello",root);

	//Invalidate(false);

	return ERROR_NO_ERROR;
}

void CFormView11::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CFormView::OnShowWindow(bShow, nStatus);
	
	// TODO: Add your message handler code here

}

void CFormView11::OnDraw(CDC* pDC) 
{
	// TODO: Add your specialized code here and/or call the base class
	ReFreshTree("SCS","123456");	
	
}

void CFormView11::OnTvnSelchangedTree1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMTREEVIEW pNMTreeView = reinterpret_cast<LPNMTREEVIEW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码

	HTREEITEM sel=m_tree.GetSelectedItem();
	CString strSelect=m_tree.GetItemText(sel);
	//short height = m_tree.getitem;
	HTREEITEM parent = m_tree.GetParentItem(sel);
	if (parent && strSelect == "Table")
	{
		CMainFrame * pMainFrm = (CMainFrame *)AfxGetMainWnd();
		CFormView22 *Hdview2 = (CFormView22 *)pMainFrm->m_splitter.GetPane(0,1);;
		Hdview2->m_list.DeleteAllItems();
		
		CString strDB = m_tree.GetItemText(parent);
		vector<CString> vecTbl;
		m_pDBinfo->GetTables(strDB,vecTbl);

		for (int n = 0;n < vecTbl.size();++n)
		{
			Hdview2->m_list.InsertItem(n,vecTbl[n],IDR_MAINFRAME);
		}
	}



	*pResult = 0;
}
