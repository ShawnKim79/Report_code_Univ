// MediatorDlg.h : header file
//

#if !defined(AFX_MEDIATORDLG_H__41BF8825_7542_44B3_82BC_4E220926D34F__INCLUDED_)
#define AFX_MEDIATORDLG_H__41BF8825_7542_44B3_82BC_4E220926D34F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "InputWnd.h"
#include "OutputWnd.h"
/////////////////////////////////////////////////////////////////////////////
// CMediatorDlg dialog

class CMediatorDlg : public CDialog
{
// Construction
public:
	void OnOK();
	CMediatorDlg(CWnd* pParent = NULL);	// standard constructor

	CInputWnd *pInwnd;
	COutputWnd *pOutwnd;
	//CEdit *pInwnd;
	//CEditView *pOutwnd;
	CString strTemp;

// Dialog Data
	//{{AFX_DATA(CMediatorDlg)
	enum { IDD = IDD_MEDIATOR_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMediatorDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMediatorDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButtontrans();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDIATORDLG_H__41BF8825_7542_44B3_82BC_4E220926D34F__INCLUDED_)
