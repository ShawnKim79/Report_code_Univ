// Short_MouseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Short_Mouse.h"
#include "Short_MouseDlg.h"
#include "AI_Robot.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//CAI_Robot* m_CAI;
//m_CAI = CAI_Robot::Instance();

int aMap_Array[12][12] = {1,1,1,1,1,1,1,1,1,1,1,1,
 					      1,0,0,0,1,1,0,0,0,0,3,1,
						  1,0,0,0,0,0,0,0,0,0,0,1,
						  1,0,0,0,0,0,0,1,0,0,0,1,
						  1,1,0,0,1,1,1,1,1,0,0,1,
						  1,0,0,0,0,0,1,0,1,0,0,1,
						  1,0,0,1,0,0,1,0,0,0,0,1,
						  1,0,0,1,0,0,1,0,0,0,0,1,
						  1,0,0,1,0,0,1,0,0,0,0,1,
						  1,0,1,1,0,0,0,1,1,1,0,1,
						  1,4,0,0,1,0,0,0,0,1,0,1,
						  1,1,1,1,1,1,1,1,1,1,1,1};

/////////////////////////////////////////////////////////////////////////////
// CShort_MouseDlg dialog

//##ModelId=40DB3A5E0376
CShort_MouseDlg::CShort_MouseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CShort_MouseDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShort_MouseDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	//m_CAI = CAI_Robot::Instance();
}

//##ModelId=40DB3A5E0378
void CShort_MouseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShort_MouseDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CShort_MouseDlg, CDialog)
	//{{AFX_MSG_MAP(CShort_MouseDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_MAPVIEWER, OnMapviewerClicked)
	ON_BN_CLICKED(IDC_BUTTON_MOVE, OnButtonMove)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShort_MouseDlg message handlers

//##ModelId=40DB3A5E03D0
BOOL CShort_MouseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	m_CAI = CAI_Robot::Instance();
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

// ???????????????? OnPaint()?? ????.
// OnDraw()?? ????!!
//##ModelId=40DB3A5E03DB
void CShort_MouseDlg::OnPaint() 
{
	int temp_x = m_CAI->m_Position.x_pos;
	int temp_y = m_CAI->m_Position.y_pos;
	
	aMap_Array[temp_x][temp_y] = 3;

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

	// Frame ?????? DC?? ???? ??????.
	CDC *pDC=GetDlgItem(IDC_MAPVIEWER)->GetDC();
	
	DrawMap(pDC);
	ReleaseDC(pDC);
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
//##ModelId=40DB3A5E03E4
HCURSOR CShort_MouseDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

//##ModelId=40DB3A5E036C
void CShort_MouseDlg::DrawMap(CDC *pDC)
{
	static int nTileNumber = 0;
		
	// ?????? ???????? DC
	CDC BufferDC;
	BufferDC.CreateCompatibleDC(pDC);

	// ???? DC?? ???????? ?????? DC
	CDC DataDC;
	DataDC.CreateCompatibleDC(pDC);

	// ?????? ???? ?????? ??????
	CBitmap bmpBuffer1;
	bmpBuffer1.LoadBitmap(IDB_MAPDATA);
	
	// ???? bitmap ????.
	CBitmap bmpBuffer2;
	bmpBuffer2.CreateCompatibleBitmap(pDC, 500, 500);
	
	// ?????? ?????? ????.
	CBitmap *pOldBitmap1 = (CBitmap *)DataDC.SelectObject(&bmpBuffer1);
	CBitmap *pOldBitmap2 = (CBitmap *)BufferDC.SelectObject(&bmpBuffer2);

	for(int y=0 ; y<12 ; y++)
	{
		for(int x=0 ; x<12 ; x++)
		{
			nTileNumber = aMap_Array[y][x];
			BufferDC.BitBlt(y*20, x*20, 20, 20, &DataDC, nTileNumber*20, 0, SRCCOPY);
		}
	}

	pDC->BitBlt(0, 0, 240, 240, &BufferDC, 0, 0, SRCCOPY);
	DataDC.SelectObject(pOldBitmap2);
	BufferDC.SelectObject(pOldBitmap1);
	
	DeleteDC(DataDC);
	DeleteDC(BufferDC);
}


//##ModelId=40DB3A5F0006
void CShort_MouseDlg::OnMapviewerClicked() 
{
	// TODO: Add your control notification handler code here
	// ?????????? ??????.
	
}

//##ModelId=40DB3A5F0008
void CShort_MouseDlg::OnButtonMove() 
{
	// TODO: Add your control notification handler code here

	aMap_Array[m_CAI->m_Position.x_pos][m_CAI->m_Position.y_pos] = 0;
	m_CAI->_state->Move(m_CAI);
	aMap_Array[m_CAI->m_Position.x_pos][m_CAI->m_Position.y_pos] = 2;
	
	m_CAI->_state->Scan_condition(m_CAI);

	if(aMap_Array[m_CAI->m_Position.x_pos][m_CAI->m_Position.y_pos] == 4)
	{
		MessageBox("???? ????", NULL, MB_OK);
		m_CAI->m_Position.x_pos = 1;
		m_CAI->m_Position.y_pos = 10;
	}

	OnPaint();
}
