//
//	myDirect3d.h
//			USER:HIROMASA IKEDA		DATE:2018/05/30
//======================================================
#include"myDirect3d.h"
#include"common.h"
#include"System.h"
#include"myDirect3d.h"

#define TEXTURE_FILE "Texture/witch3.png"
//-----------------------------------------------
//	グローバル変数
//-----------------------------------------------
static LPDIRECT3D9			g_pd3d9 = NULL;				//ポインタ
static LPDIRECT3DDEVICE9	g_pD3DDevice = NULL;		//デバイスのIDirect3Device9インターフェイス
static LPDIRECT3DTEXTURE9	g_pTexture = NULL;

//===============================================
//	Direct3Dの初期化
//===============================================
bool MyDirect3D_Initialize()
{
	g_pd3d9 = Direct3DCreate9(D3D_SDK_VERSION);

	if (g_pd3d9 == NULL) {
		return false;
	}

	D3DPRESENT_PARAMETERS	d3dpp = {};							//デバイスの動作を設定する構造体
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;
	d3dpp.BackBufferCount = 1;									//バックバッファーの枚数
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;					//使えるカラーの設定
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;					//表と裏の画面切り替えを行う処理の仕方設定
	d3dpp.Windowed = TRUE;										//ウィンドウ:TRUE	フルスクリーン:FALSE 
	d3dpp.EnableAutoDepthStencil = TRUE;						//ステンシルバッファの有無	FALSEにすると表画面と裏画面が混合する
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;					//ステンシルバッファのデータ量
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;	//垂直同期を待つタイミング

	HRESULT hr = g_pd3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, *System_GethWnd(), D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pD3DDevice);

	if (FAILED(hr)) {
		MessageBox(*System_GethWnd(), "デバイスの取得に失敗しました。", "エラー", MB_OK);
		DestroyWindow(*System_GethWnd());
		return false;
	}

	//描画処理
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);				//半透明処理をON
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);	//背景DSETのブレンド設定
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA);

	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);	//テクスチャポリゴン透過処理

	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);

	return true;
}

//==============================================
//	Dirext3Dの終了処理
//==============================================
void MyDirect3D_Finalize(void) 
{
	if (g_pD3DDevice != NULL)
	{
		g_pD3DDevice->Release();
		g_pD3DDevice = NULL;
	}
	if (g_pd3d9 != NULL)
	{
		g_pd3d9->Release();
		g_pd3d9 = NULL;
	}
}

//===============================================
//	Direct3Dデバイスポインタの取得
//===============================================
LPDIRECT3DDEVICE9 MyDirect3D_GetDevice(void) 
{
	return g_pD3DDevice;
}
