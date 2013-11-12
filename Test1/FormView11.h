#if !defined(AFX_FORMVIEW11_H__F4C9692F_0556_454C_967B_3A0F2DF8F145__INCLUDED_)
#define AFX_FORMVIEW11_H__F4C9692F_0556_454C_967B_3A0F2DF8F145__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FormView11.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFormView11 form view

#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CFormView11 : public CFormView
{
protected:
	CFormView11();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CFormView11)

// Form Data
public:
	//{{AFX_DATA(CFormView11)
	enum { IDD = IDD_FORMVIEW1 };
	CTreeCtrl	m_tree;
	//}}AFX_DATA

// Attributes
public:
// 	CTreeCtrl m_tree;

// Operations
public:
	int ReFreshTree(const CString &strUser,const CString &strPasswd);

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFormView11)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnDraw(CDC* pDC);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CFormView11();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CFormView11)
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FORMVIEW11_H__F4C9692F_0556_454C_967B_3A0F2DF8F145__INCLUDED_)
