// Mediator.h : main header file for the MEDIATOR application
//

#if !defined(AFX_MEDIATOR_H__ADD7C56D_E70D_4386_9C00_53A4357478A8__INCLUDED_)
#define AFX_MEDIATOR_H__ADD7C56D_E70D_4386_9C00_53A4357478A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMediatorApp:
// See Mediator.cpp for the implementation of this class
//

class CMediatorApp : public CWinApp
{
public:
	CMediatorApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMediatorApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMediatorApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDIATOR_H__ADD7C56D_E70D_4386_9C00_53A4357478A8__INCLUDED_)
