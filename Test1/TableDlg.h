#pragma once


// CTableDlg �Ի���

class CTableDlg : public CDialog
{
	DECLARE_DYNAMIC(CTableDlg)

public:
	CTableDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTableDlg();

// �Ի�������
	enum { IDD = IDD_TABLE_DLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
