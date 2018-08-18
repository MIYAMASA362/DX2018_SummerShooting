//
//	System.cpp
//		USER:HIROMASA IKEDA		DATE:2018/07/11
//===============================================
#include"common.h"
#include"System.h"

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

static HWND	g_hWnd = {};		//�n���h���̐ݒ�
static HINSTANCE g_hInstance = {};

//***********************************************
//	����������
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

	//�V�X�e���ւ̓o�^
	RegisterClass(&MyWindow_01);

	//�E�B���h�E�T�C�Y
	RECT Window_Rect = { 0,0,SCREEN_WIDTH,SCREEN_HEIGHT };

	AdjustWindowRect(&Window_Rect, WINDOW_STYLE, FALSE);

	int WinWidth = Window_Rect.right - Window_Rect.left;
	int WinHeight = Window_Rect.bottom - Window_Rect.top;

	//max(a,b);	a,b���r���āA�傫������Ԃ��B
	int WinPosX = max((GetSystemMetrics(SM_CXSCREEN) - WinWidth) / 2, 0);
	int WinPosY = max((GetSystemMetrics(SM_CYSCREEN) - WinHeight) / 2, 0);

	g_hWnd = CreateWindow(CLASS_NAME, WINDOW_CAPTION, WINDOW_STYLE, WinPosX, WinPosY, WinWidth, WinHeight, NULL, NULL, *hInstance, NULL);

	ShowWindow(g_hWnd, *nCmdShow);
	UpdateWindow(g_hWnd);

	g_hInstance = *hInstance;
}

//=============================================================
//	�v���V�[�W���[����
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
		if (MessageBox(hWnd, "�{���ɏI�����Ă���낵���ł����H", "�m�F", MB_OKCANCEL || MB_DEFBUTTON2) == IDOK) {
			DestroyWindow(hWnd);
		}

		return 0;

	case WM_DESTROY:
		//WM_QUIT�@�Ƃ������b�Z�[�W�𑗂�
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
