// InputWnd.cpp : implementation file
//

#include "stdafx.h"
#include "Mediator.h"
#include "InputWnd.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CInputWnd

CInputWnd::CInputWnd()
{
}

CInputWnd::~CInputWnd()
{
}


BEGIN_MESSAGE_MAP(CInputWnd, CEdit)
	//{{AFX_MSG_MAP(CInputWnd)
	ON_WM_KEYDOWN()
	ON_CONTROL_REFLECT(EN_UPDATE, OnUpdate)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInputWnd message handlers

void CInputWnd::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	if(nChar == VK_RETURN)
	{
		this->GetWindowText(strInput_text);
	}

	CEdit::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CInputWnd::OnUpdate() 
{
	// TODO: If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CEdit::OnInitDialog()
	// function to send the EM_SETEVENTMASK message to the control
	// with the ENM_UPDATE flag ORed into the lParam mask.
	
	// TODO: Add your control notification handler code here
	
	this->GetWindowText(strInput_text);
	
}
