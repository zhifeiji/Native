#pragma once
#include "afxcmn.h"



// CFormView22 ������ͼ

class CFormView22 : public CFormView
{
	DECLARE_DYNCREATE(CFormView22)

protected:
	CFormView22();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CFormView22();

public:
	enum { IDD = IDD_FORMVIEW2 };
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CListCtrl m_list;
protected:
	virtual void OnDraw(CDC* /*pDC*/);
};


