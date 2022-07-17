// Fcs_CompositeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Fcs_Composite.h"
#include "Fcs_CompositeDlg.h"
//#include "afxmt.h"

#include "comp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


// 객체들의 생성 처리
// 1. 포함 개체
CCompositeEquipment cFcs("FCS", 100);
CCompositeEquipment cSenser("Senser", 100);
CCompositeEquipment cFirectrl("Fire Control", 100);

// 2. 기능 개체
CEquipment cRader("Rader", 300);
CEquipment cIrtv("IR_Tv", 250);
CEquipment cGunpc("Gun_PC", 200);
CEquipment cMslpc("Missle_PC", 250);
CEquipment cDatalnk("Data_Link", 300);

// 3. 각 기능 포함.
cFcs.Add(&cSenser);
cFcs.Add(&cFirectrl);
cFcs.Add(&cDatalnk);
cSenser.Add(&cRader);
cSenser.Add(&cIrtv);
cFirectrl.Add(&cGunpc);
cFirectrl.Add(&cMslpc);


char *pLevel0 = (char*)cFcs.Name();

char *pLevel01 = (char*)cSenser.Name();
char *pLevel02 = (char*)cFirectrl.Name();
char *pLevel03 = (char*)cDatalnk.Name();

char *pLevel10 = (char*)cRader.Name();
char *pLevel11 = (char*)cIrtv.Name();
char *pLevel20 = (char*)cGunpc.Name();
char *pLevel21 = (char*)cMslpc.Name();

/////////////////////////////////////////////////////////////////////////////
// CFcs_CompositeDlg dialog

CFcs_CompositeDlg::CFcs_CompositeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CFcs_CompositeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CFcs_CompositeDlg)
	m_strSelected = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFcs_CompositeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CFcs_CompositeDlg)
	DDX_Control(pDX, IDC_FCSTREE, m_ctrlFcsTree);
	DDX_Text(pDX, IDC_VIEWEDIT, m_strSelected);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CFcs_CompositeDlg, CDialog)
	//{{AFX_MSG_MAP(CFcs_CompositeDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFcs_CompositeDlg message handlers

BOOL CFcs_CompositeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here

	m_strSelected = pLevel0;
	CDialog::OnInitDialog();

	TV_INSERTSTRUCT tvinsert;
	tvinsert.hParent = NULL;
	tvinsert.hInsertAfter = TVI_LAST;
	tvinsert.item.mask = TVIF_TEXT;
	tvinsert.item.state = 0;
	tvinsert.item.cchTextMax = 60;
	tvinsert.item.iSelectedImage = 1;
	tvinsert.item.cChildren = 0;

	// level0의 노드 추가.
	tvinsert.item.pszText = pLevel0;
	HTREEITEM hRoot = m_ctrlFcsTree.InsertItem(&tvinsert);
	HTREEITEM hItem;
	
	// level1의 노드 추가.(level0의 자식으로 추가)
	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = pLevel01;
	hItem = m_ctrlFcsTree.InsertItem(&tvinsert);
	
	// level2의 노드 추가
	tvinsert.hParent = hItem;
	tvinsert.item.pszText = pLevel10;
	m_ctrlFcsTree.InsertItem(&tvinsert);
	tvinsert.item.pszText = pLevel11;
	m_ctrlFcsTree.InsertItem(&tvinsert);
	m_ctrlFcsTree.Expand(hItem,TVE_EXPAND);

	// level1의 노드 추가.
	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = pLevel02;
	hItem = m_ctrlFcsTree.InsertItem(&tvinsert);

	// level2의 노드 추가
	tvinsert.hParent = hItem;
	tvinsert.item.pszText = pLevel20;
	m_ctrlFcsTree.InsertItem(&tvinsert);
	tvinsert.item.pszText = pLevel21;
	m_ctrlFcsTree.InsertItem(&tvinsert);
	m_ctrlFcsTree.Expand(hItem,TVE_EXPAND);

	tvinsert.hParent = hRoot;
	tvinsert.item.pszText = pLevel03;
	hItem = m_ctrlFcsTree.InsertItem(&tvinsert);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFcs_CompositeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFcs_CompositeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
