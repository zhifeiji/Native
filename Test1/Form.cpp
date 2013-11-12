// Form.cpp : implementation file
//

#include "stdafx.h"
#include "Test1.h"
#include "Form.h"
#include "DatabaseInfo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CForm

IMPLEMENT_DYNCREATE(CForm, CFormView)

CForm::CForm()
	: CFormView(CForm::IDD)
{
	//{{AFX_DATA_INIT(CForm)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CForm::~CForm()
{
}

void CForm::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CForm)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CForm, CFormView)
	//{{AFX_MSG_MAP(CForm)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CForm diagnostics

#ifdef _DEBUG
void CForm::AssertValid() const
{
	CFormView::AssertValid();
}

void CForm::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif //_DBUG

/////////////////////////////////////////////////////////////////////////////
// CForm message handlers

int CForm::ReFreshTree(const string &strUser, const string &strPasswd)
{
	CDatabaseInfo dbinfo;
	
	vector<string> vecDB;
	vector<string> vecTbl;
	
	dbinfo.GetDatabases(vecDB);

	CRect rect;
	GetClientRect(&rect);
	m_tree.MoveWindow(rect);
	
	HTREEITEM root = m_tree.GetRootItem();
	for (vector<string>::iterator iter = vecDB.begin();
	iter != vecDB.end();++iter)
	{
		vecTbl.clear();
		dbinfo.GetTables(*iter,vecTbl);
		
		HTREEITEM item = root->InsertItem(*iter);
		
		for (vector<string>::iterator iterTbl = vecTbl.begin();
		iterTbl != vecTbl.end();++iterTbl)
		{
			item->InsertItem(*iterTbl);
		}
	}
}
