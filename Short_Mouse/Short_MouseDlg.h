// Short_MouseDlg.h : header file
//

#if !defined(AFX_SHORT_MOUSEDLG_H__05B91BF4_38B3_44AC_8926_DCC3A9E03039__INCLUDED_)
#define AFX_SHORT_MOUSEDLG_H__05B91BF4_38B3_44AC_8926_DCC3A9E03039__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AI_Robot.h"

/////////////////////////////////////////////////////////////////////////////
// CShort_MouseDlg dialog

//##ModelId=40DB3A5E034F
class CShort_MouseDlg : public CDialog
{
// Construction
public:

	//##ModelId=40DB3A5E0363
	CAI_Robot* m_CAI;
//	m_CAI = CAI_Robot::Instance();

	//##ModelId=40DB3A5E036C
	void DrawMap(CDC* pDC);
	
	//##ModelId=40DB3A5E0376
	CShort_MouseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShort_MouseDlg)
	enum { IDD = IDD_SHORT_MOUSE_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShort_MouseDlg)
	protected:
	//##ModelId=40DB3A5E0378
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//##ModelId=40DB3A5E038A
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CShort_MouseDlg)
	//##ModelId=40DB3A5E03D0
	virtual BOOL OnInitDialog();
	//##ModelId=40DB3A5E03DB
	afx_msg void OnPaint();
	//##ModelId=40DB3A5E03E4
	afx_msg HCURSOR OnQueryDragIcon();
	//##ModelId=40DB3A5F0006
	afx_msg void OnMapviewerClicked();
	//##ModelId=40DB3A5F0008
	afx_msg void OnButtonMove();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHORT_MOUSEDLG_H__05B91BF4_38B3_44AC_8926_DCC3A9E03039__INCLUDED_)
