//
//	System.cpp
//		USER:HIROMASA IKEDA		DATE:2018/07/11
//===============================================
#include"common.h"
#include"System.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

static HWND	g_hWnd = {};		//ハンドルの設定
static HINSTANCE g_hInstance = {};

//***********************************************
//	初期化処理
//***********************************************
void System_Initialize(HINSTANCE *hInstance, HINSTANCE *hPrevInstance, LPSTR *lpCmdLine, int *nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	WNDCLASS	MyWindow_01 = {};
	MyWindow_01.lpfnWndProc = WndProc;
	MyWindow_01.lpszClassName = CLASS_NAME;
	MyWindow_01.hInstance = *hInstance;
	MyWindow_01.hCursor = LoadCursor(NULL, IDC_ARROW);
	MyWindow_01.hbrBackground = (HBRUSH)(COLOR_BACKGROUND + 1);

	//システムへの登録
	RegisterClass(&MyWindow_01);

	//ウィンドウサイズ
	RECT Window_Rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };

	AdjustWindowRect(&Window_Rect, WINDOW_STYLE, FALSE);

	int WinWidth = Window_Rect.right - Window_Rect.left;
	int WinHeight = Window_Rect.bottom - Window_Rect.top;

	//max(a,b);	a,bを比較して、大きい方を返す。
	int WinPosX = max((GetSystemMetrics(SM_CXSCREEN) - WinWidth) / 2, 0);
	int WinPosY = max((GetSystemMetrics(SM_CYSCREEN) - WinHeight) / 2, 0);

	g_hWnd = CreateWindow(CLASS_NAME, WINDOW_CAPTION, WINDOW_STYLE, WinPosX, WinPosY, WinWidth, WinHeight, NULL, NULL, *hInstance, NULL);

	ShowWindow(g_hWnd, *nCmdShow);
	UpdateWindow(g_hWnd);

	g_hInstance = *hInstance;
}

//=============================================================
//	プロシージャー処理
//=============================================================
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg) {
	case WM_KEYDOWN:
		if (wParam == VK_ESCAPE) {
			SendMessage(hWnd, WM_CLOSE, 0, 0);
		}
		break;

	case WM_CLOSE:
		if (MessageBox(hWnd, "本当に終了してもよろしいですか？", "確認", MB_OKCANCEL || MB_DEFBUTTON2) == IDOK) {
			DestroyWindow(hWnd);
		}

		return 0;

	case WM_DESTROY:
		//WM_QUIT　というメッセージを送る
		PostQuitMessage(0);
		return 0;
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

HWND *System_GethWnd()
{
	return &g_hWnd;
}

HINSTANCE *System_GethInstance() 
{
	return &g_hInstance;
}
