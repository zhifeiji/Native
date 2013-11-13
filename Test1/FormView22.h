#pragma once
#include "afxcmn.h"



// CFormView22 窗体视图

class CFormView22 : public CFormView
{
	DECLARE_DYNCREATE(CFormView22)

protected:
	CFormView22();           // 动态创建所使用的受保护的构造函数
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
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	CListCtrl m_list;
protected:
	virtual void OnDraw(CDC* /*pDC*/);
};


