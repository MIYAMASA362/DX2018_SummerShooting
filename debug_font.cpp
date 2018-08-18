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
		SHIFTJIS_CHARSET,	//���{��g���Ȃ炱��
		OUT_DEFAULT_PRECIS,	
		DEFAULT_QUALITY,
		DEFAULT_PITCH,	//������
		"Terminal",	//�t�H���g
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
	//���̋�`�Ƀt�H���g�|���S���\���Ă��銴��
	RECT rect = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};
	g_pD3DXFont->DrawTextA(
		NULL,
		"HELLO!!",
		-1,	//�w�肵����������\��(-1���ƑS��)
		&rect,
		DT_LEFT,
		D3DCOLOR_RGBA(0,255,0,255)	//�����F
		);
#endif
}