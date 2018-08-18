//
//	Main.cpp
//		USER:HIROMASA IKEDA		DATE:2018/05/30
//================================================
#include"common.h"
#include"System.h"
#include"Debug_Circle.h"
#include"myDirect3d.h"
#include"Scene.h"
#include"input.h"
#include"Texture.h"
#include"Fade.h"

void Main_Initialize(void);		//ゲームの初期化関数
void Main_Update(void);		//ゲームの更新
void Main_Render(void);		//ゲームの描画
void Main_Finalize(void);	//ゲームの終了

//---------------------------------
//	Main
//---------------------------------
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	System_Initialize(&hInstance,&hPrevInstance,&lpCmdLine,&nCmdShow);
	Main_Initialize();
	DebugPrimitive_Initialize();

	MSG msg = {};
	//ゲーム用メインループ
	do 
	{
		//メッセージが届いた処理
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//ゲーム更新
			Main_Update();

			//ゲーム描画
			Main_Render();

			Scene_Check();
		}
	} while (msg.message != WM_QUIT);

	//ゲームの終了処理
	Main_Finalize();

	return (int)msg.wParam;

}

//=============================================================
//	初期化処理
//=============================================================
void Main_Initialize(void)
{
	if (!MyDirect3D_Initialize()) return;
	if (!Keyboard_Initialize())return;
	Texture_Initialize(System_GethWnd());

	Fade_Initialize();
	Scene_Initialize(SCENE_TITLE);

}

//=============================================================
//	更新処理
//=============================================================
void Main_Update(void)
{
	Keyboard_Update();
	Scene_Update();
}

//=============================================================
//	描画処理
//=============================================================
void Main_Render(void)
{
	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();

	if (!pD3DDevice) return;

	//デバイスに対して、画面のクリアをお願いする
	pD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(100, 80, 200, 255), 1.0f, 0);

	pD3DDevice->BeginScene();

	Scene_Render();

	pD3DDevice->EndScene();

	//フリップ処理
	pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

//=============================================================
//	終了処理
//=============================================================
void Main_Finalize(void)
{
	Scene_Finalize();
	DebugPrimitive_Finalize();

	Texture_Finalize();
	Keyboard_Finalize();
	MyDirect3D_Finalize();
}