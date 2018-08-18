//
//	Texture.cpp
//		USER:HIROMASA IKEDA		DATE:2018/06/21
//===============================================
#include"common.h"
#include"myDirect3d.h"
#include"Texture.h"

//***********************************************
//	グローバル変数
//***********************************************
static const int TEXTURE_MAX = sizeof(TEXTURE_FILELIST) / sizeof(TEXTURE_FILELIST[0]);
static LPDIRECT3DTEXTURE9 g_pTextures[TEXTURE_MAX];

//***********************************************-
//	テクスチャ初期化
//***********************************************
void Texture_Initialize(HWND *hWnd) 
{
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	HRESULT hr;
	char ErrorText[256] = {};
	int failded_Count = 0;

	for (int i = 0; i < TEXTURE_MAX; i++)
	{
		//読み込みが失敗した時にはg_pTexture[i]にnullが置かれる
		hr = D3DXCreateTextureFromFile(pDevice, TEXTURE_FILELIST[i].FileName, &g_pTextures[i]);
		if (FAILED(hr))
		{
			strcat(ErrorText, TEXTURE_FILELIST[i].FileName);
			strcat(ErrorText, "\n");
			failded_Count++;
		}
	}

	if (failded_Count > 0)
	{
		MessageBox(*hWnd, ErrorText, "読み込み失敗", MB_OK);
		DestroyWindow(*hWnd);
	}
}

//***********************************************
//	終了処理
//***********************************************
void Texture_Finalize() 
{
	for (int i = 0; i < TEXTURE_MAX; i++)
	{
		if (g_pTextures[i] != NULL)
		{
			g_pTextures[i]->Release();
			g_pTextures[i] = NULL;
		}
	}
}

//***********************************************
//	テクスチャポインタの取得
//***********************************************
LPDIRECT3DTEXTURE9 Texture_GetTexture(int index) 
{
	return g_pTextures[index];
}

//***********************************************
//	テクスチャ幅の取得
//***********************************************
int Texture_GetWidth(int index) 
{
	return TEXTURE_FILELIST[index].width;
}

//***********************************************
//	テクスチャ縦の取得
//***********************************************
int Texture_GetHeight(int index) 
{
	return TEXTURE_FILELIST[index].height;
}
