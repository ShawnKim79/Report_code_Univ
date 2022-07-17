// Fcs_CompositeDlg.h : header file
//
//#include "comp.h"

#if !defined(AFX_FCS_COMPOSITEDLG_H__8AAD7628_F2F9_49D8_9CC8_770C8E47C30E__INCLUDED_)
#define AFX_FCS_COMPOSITEDLG_H__8AAD7628_F2F9_49D8_9CC8_770C8E47C30E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


/////////////////////////////////////////////////////////////////////////////
// CFcs_CompositeDlg dialog

class CFcs_CompositeDlg : public CDialog
{
// Construction
public:
	CFcs_CompositeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFcs_CompositeDlg)
	enum { IDD = IDD_FCS_COMPOSITE_DIALOG };
	CTreeCtrl	m_ctrlFcsTree;
	CString	m_strSelected;
	//CImageList m_ImageFcsTree;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFcs_CompositeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CFcs_CompositeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FCS_COMPOSITEDLG_H__8AAD7628_F2F9_49D8_9CC8_770C8E47C30E__INCLUDED_)
