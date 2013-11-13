// TableDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Test1.h"
#include "TableDlg.h"


// CTableDlg 对话框

IMPLEMENT_DYNAMIC(CTableDlg, CDialog)

CTableDlg::CTableDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CTableDlg::IDD, pParent)
{

}

CTableDlg::~CTableDlg()
{
}

void CTableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CTableDlg, CDialog)
END_MESSAGE_MAP()


// CTableDlg 消息处理程序

BOOL CTableDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化


// 	vector<vector<CString> > vecRes;





	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}
