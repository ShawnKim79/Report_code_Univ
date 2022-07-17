#include <windows.h>
#include <commctrl.h>
#include "resource.h"

#define ID_TOOLBAR		99
#define ID_BTN_RECT		100
#define ID_BTN_CIRCLE	101
#define ID_BTN_ELLIP	102

TBBUTTON ToolBtn[3];
int Shape = ID_BTN_RECT;
HWND hToolBar;

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
HINSTANCE g_hInst;
LPSTR lpszClass = "api_bridge"

int APIENTRT WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow)
{
	HWND hWnd;
	MSG Message;
	WNDCLASS WndClass;
	g_hInst = hInstance;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hInstance = hInstance;
	WndClass.lpfnWndProc = (WNDPROC)WndProc;
	WndClass.lpszClassName = lpszClass;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);

	hWnd = CreateWindow(lpszClass, lpszClass, WS_OVERLAPPEDWINDOW, 
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, 
		NULL, (HMENU)NULL, hInstance, NULL);
	ShowWindow(hWnd, nCmdShow);

	while(GetMessage(&Message, 0, 0, 0))
	{
		TranslateMessage(&Message);
		DispatchMessage(&Message);
	}
	return Message.wParam;	
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	int i;

	switch(iMessage) 
	{
	case WM_CREATE:
		InitCommonControls();

		for(i=0 ; i<3 ; i++)
		{
			ToolBtn[i].iBitmap = i;
			ToolBtn[i].idCommand = ID_BTN_RECT+i;
			ToolBtn[i].fsState = TBSTATE_ENABLE;
			ToolBtn[i].fsStyle = TBSTYLE_CHECKGROUP;
			ToolBtn[i].dwData = 0;
			ToolBtn[i].iString = 0;
		}
		hToolBar = CreateToolbarEx(hWnd, WS_CHILD | WS_VISIBLE | WS_BORDER | TBSTYLE_TOOLTIPS, 
			ID_TOOLBAR, 3, g_hInst, RESTOOLBMP, ToolBtn, 3, 18, 18, 30, 30, sizeof(TBBUTTON));
		return 0;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_BTN_RECT:
		case ID_BTN_CIRCLE:
		case ID_BTN_ELLIP:
			Shape = LOWORD(wParam);
			InvalidateRect(hWnd, NULL, TRUE);
		}
		return 0;

	case WM_NOTIFY:
		switch(((LPNMHDR)lParam)->code)
		{
		case TTN_NEEDTEXT:
			switch (wParam)
			{
			case ID_BTN_RECT:
				((LPTOOLTIPTEXT)lParam)->lpszText = "RECTANGLE";
				break;
			case ID_BTN_CIRCLE:
				((LPTOOLTIPTEXT)lParam)->lpszText = "CIRCLE";
				break;
			case ID_BTN_ELLIP:
				((LPTOOLTIPTEXT)lParam)->lpszText = "ELLIPSE";
				break;
			}
		}
		return 0;

	case WM_PAINT:
		hdc = BeingPaint(hWnd, &ps);
		switch(Shape)
		{
		case ID_BTN_RECT:
			Rectangle(hdc, 10, 50, 200, 240);
			break;
		case ID_BTN_CIRCLE:
			Circle(hdc, 10, 50, 200, 240);
			break;
		case ID_BTN_ELLIP:
			Ellipse(hdc, 10, 50, 200, 240);
			break;
		}
		EndPaint(hWnd, &ps);
		return 0;

	case WM_SIZE:
		SendMessage(hToolBar, WM_SIZE, 0,0);
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, lParam);
}