//
//	Fade.cpp
//		USER:HIROMASA IKEDA		DATE:2018/07/11
//===============================================
#include"common.h"
#include"myDirect3d.h"
#include"Fade.h"

typedef struct DebugVertex_tag
{
	D3DXVECTOR4 Position;
	D3DCOLOR	Color;

}FadeVertex;

#define FVF_FADE_VERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

static D3DXCOLOR g_FadeColor(1.0f, 1.0f, 1.0f, 1.0f);
static float	g_Alpha = 1.0f;
static float	g_AddAlpha = 0.0f;		
static bool		g_bOut = false;			//false フェードアウト　ture フェードイン
static bool		g_bIsFade = false;

void Fade_Initialize() 
{
	g_bOut = false;
	g_bIsFade = false;
	g_AddAlpha = 0;
	g_Alpha = 0;
	g_FadeColor.a = g_Alpha;
}

void Fade_Update() 
{
	if (!g_bIsFade) return;

	g_Alpha += g_AddAlpha;

	if (g_bOut)
	//フェードイン
	{
		if (g_Alpha >= 1.0f) 
		{
			g_bIsFade = false;
			g_Alpha = 1.0f;

		}
	}
	//フェードアウト
	else
	{
		if (g_Alpha <= 0.0f) 
		{
			g_bIsFade = false;
			g_Alpha = 0.0f;
		}
	}
}

void Fade_Render() 
{
	
	if (g_Alpha <= 0.0f) 
	{
		return;
	}

	g_FadeColor.a = g_Alpha;

	FadeVertex Vertex[4] =
	{
		{ D3DXVECTOR4(0.0f,			0.0f,			1.0f,1.0f), g_FadeColor },
		{ D3DXVECTOR4(SCREEN_WIDTH,	0.0f,			1.0f,1.0f), g_FadeColor },
		{ D3DXVECTOR4(0.0f,			SCREEN_HEIGHT,	1.0f,1.0f), g_FadeColor },
		{ D3DXVECTOR4(SCREEN_WIDTH,	SCREEN_HEIGHT,	1.0f,1.0f), g_FadeColor }
	};

	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	pDevice->SetFVF(FVF_FADE_VERTEX);
	pDevice->SetTexture(0, NULL);
	pDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP,2,&Vertex,sizeof(Vertex[0]));

}

void Fade_Triger(bool bOut,int frame,D3DCOLOR Color) 
{
	g_bOut = bOut;

	g_AddAlpha = 1.0f / frame;
	g_FadeColor = Color;
	g_bIsFade = true;

	//フェードイン
	if (g_bOut)	
	{
		g_Alpha = 0.0f;
	}
	//フェードアウト
	else 
	{
		g_Alpha = 1.0f;
		g_AddAlpha = -g_AddAlpha;
	}
}

bool Fade_IsFade() 
{
	return g_bIsFade;
}

//フェードインしているか
bool Fade_Alpha()
{
	return (g_Alpha >= 1.0f) ? true : false;
}
