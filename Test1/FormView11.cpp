// FormView11.cpp : implementation file
//

#include "stdafx.h"
#include "Test1.h"
#include "FormView11.h"
#include <vector>
#include "DatabaseInfo.h"

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

	HTREEITEM root = m_tree.GetRootItem();

	vector<CString> vecDB;
	vector<CString> vecTbl;
	CDatabaseInfo dbinfo;

	dbinfo.GetDatabases(vecDB);

	for (vector<CString>::iterator iterDB = vecDB.begin();
		iterDB != vecDB.end();++iterDB)
	{
			HTREEITEM item = m_tree.InsertItem(*iterDB,root);

			dbinfo.GetTables(*iterDB,vecTbl);
			for (vector<CString>::iterator iterTbl = vecTbl.begin();
			iterTbl != vecTbl.end();++iterTbl)
			{
				m_tree.InsertItem(*iterTbl,item);
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
