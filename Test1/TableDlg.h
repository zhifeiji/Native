#pragma once


// CTableDlg 对话框

class CTableDlg : public CDialog
{
	DECLARE_DYNAMIC(CTableDlg)

public:
	CTableDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTableDlg();

// 对话框数据
	enum { IDD = IDD_TABLE_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
