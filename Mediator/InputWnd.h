#if !defined(AFX_INPUTWND_H__8A31BBCA_F464_40F3_ACC8_3956A7238EFE__INCLUDED_)
#define AFX_INPUTWND_H__8A31BBCA_F464_40F3_ACC8_3956A7238EFE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// InputWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInputWnd window

class CInputWnd : public CEdit
{
// Construction
public:
	CInputWnd();

	CString strInput_text;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInputWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CInputWnd();

	// Generated message map functions
protected:
	//{{AFX_MSG(CInputWnd)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnUpdate();
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INPUTWND_H__8A31BBCA_F464_40F3_ACC8_3956A7238EFE__INCLUDED_)
