// Fcs_Composite.h : main header file for the FCS_COMPOSITE application
//

#if !defined(AFX_FCS_COMPOSITE_H__C8A935A4_46E2_4F5A_AB4E_ED4726F2B4CD__INCLUDED_)
#define AFX_FCS_COMPOSITE_H__C8A935A4_46E2_4F5A_AB4E_ED4726F2B4CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFcs_CompositeApp:
// See Fcs_Composite.cpp for the implementation of this class
//

class CFcs_CompositeApp : public CWinApp
{
public:
	CFcs_CompositeApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFcs_CompositeApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFcs_CompositeApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FCS_COMPOSITE_H__C8A935A4_46E2_4F5A_AB4E_ED4726F2B4CD__INCLUDED_)
