// FormView22.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Test1.h"
#include "FormView22.h"


// CFormView22

IMPLEMENT_DYNCREATE(CFormView22, CFormView)

CFormView22::CFormView22()
	: CFormView(CFormView22::IDD)
{

}

CFormView22::~CFormView22()
{
}

void CFormView22::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
}

BEGIN_MESSAGE_MAP(CFormView22, CFormView)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// CFormView22 ���

#ifdef _DEBUG
void CFormView22::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CFormView22::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CFormView22 ��Ϣ�������

void CFormView22::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO: �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CFormView::OnPaint()
	CRect rect;
	this->GetClientRect(&rect);

	m_list.MoveWindow(rect);
}

void CFormView22::OnDraw(CDC* /*pDC*/)
{
	// TODO: �ڴ����ר�ô����/����û���
	
	
}
