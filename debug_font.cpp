//
//	Debug_font.cpp
//
//===============================================
#include"common.h"
#include"myDirect3d.h"
#include"debug_font.h"

static LPD3DXFONT g_pD3DXFont = NULL;

void DebugFont_Initialize(void) 
{
	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();
	D3DXCreateFont(
		pD3DDevice,
		18,
		0,
		0,
		0,
		FALSE,
		SHIFTJIS_CHARSET,	//日本語使うならこれ
		OUT_DEFAULT_PRECIS,	
		DEFAULT_QUALITY,
		DEFAULT_PITCH,	//文字間
		"Terminal",	//フォント
		&g_pD3DXFont
	);
}

void DebugFont_Finalize(void) 
{
	if (g_pD3DXFont) 
	{
		g_pD3DXFont->Release();
		g_pD3DXFont = NULL;
	}
}

void DebugFont_Draw(void) 
{
#if defined(_DEBUG) || defined(DEBUG)
	//この矩形にフォントポリゴン貼っている感じ
	RECT rect = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
	g_pD3DXFont->DrawTextA(
		NULL,
		"HELLO!!",
		-1,	//指定した文字数を表示(-1だと全部)
		&rect,
		DT_LEFT,
		D3DCOLOR_RGBA(0,255,0,255)	//文字色
		);
#endif
}