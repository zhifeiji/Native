// TableDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Test1.h"
#include "TableDlg.h"


// CTableDlg �Ի���

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


// CTableDlg ��Ϣ�������

BOOL CTableDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��


// 	vector<vector<CString> > vecRes;





	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
}
