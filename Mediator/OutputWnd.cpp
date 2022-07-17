// OutputWnd.cpp : implementation file
//

#include "stdafx.h"
#include "Mediator.h"
#include "OutputWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// COutputWnd

IMPLEMENT_DYNCREATE(COutputWnd, CEditView)

COutputWnd::COutputWnd()
{
}

COutputWnd::~COutputWnd()
{
}


BEGIN_MESSAGE_MAP(COutputWnd, CEditView)
	//{{AFX_MSG_MAP(COutputWnd)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COutputWnd drawing

void COutputWnd::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO: add draw code here
}

/////////////////////////////////////////////////////////////////////////////
// COutputWnd diagnostics

#ifdef _DEBUG
void COutputWnd::AssertValid() const
{
	CEditView::AssertValid();
}

void COutputWnd::Dump(CDumpContext& dc) const
{
	CEditView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// COutputWnd message handlers

void COutputWnd::OutputText()
{
	this->SetWindowText((LPCTSTR)strOutput_text);
}
