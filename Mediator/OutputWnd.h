#if !defined(AFX_OUTPUTWND_H__1C3CC1BE_B61B_45F4_8DE0_D7962405CC94__INCLUDED_)
#define AFX_OUTPUTWND_H__1C3CC1BE_B61B_45F4_8DE0_D7962405CC94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// OutputWnd.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COutputWnd view

class COutputWnd : public CEditView
{
protected:
	COutputWnd();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(COutputWnd)

// Attributes
public:

// Operations
public:
	void OutputText();
	CString strOutput_text;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COutputWnd)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~COutputWnd();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(COutputWnd)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTPUTWND_H__1C3CC1BE_B61B_45F4_8DE0_D7962405CC94__INCLUDED_)
