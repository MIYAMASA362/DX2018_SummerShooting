//=============================================================================
//
// 入力処理 [input.cpp]
//
//=============================================================================
#include <Windows.h>
#define DIRECTINPUT_VERSION (0x0800)
#include <dinput.h>
#include"common.h"
#include"System.h"

//*****************************************************************************
// マクロ定義
//*****************************************************************************
#define	NUM_KEY_MAX			(256)	// キーの最大数


//*****************************************************************************
// プロトタイプ宣言
//*****************************************************************************
static bool initialize(HINSTANCE hInstance);


//*****************************************************************************
// グローバル変数
//*****************************************************************************
LPDIRECTINPUT8			g_pInput = NULL;					// DirectInputオブジェクトへのポインタ

LPDIRECTINPUTDEVICE8	g_pDevKeyboard = NULL;				// 入力デバイス(キーボード)へのポインタ
BYTE					g_aKeyState[NUM_KEY_MAX];			// キーボードの入力情報ワーク
BYTE					g_aKeyStateTrigger[NUM_KEY_MAX];	// キーボードのトリガー情報ワーク
BYTE					g_aKeyStateRelease[NUM_KEY_MAX];	// キーボードのリリース情報ワーク

LPDIRECTINPUTDEVICE8	g_pDevMouse = NULL;					// 入力デバイス(マウス)
DIMOUSESTATE2			g_MouseState2;

POINT					g_MousePos = {NULL};

//=============================================================================
// 入力処理の初期化
//=============================================================================
bool initialize(HINSTANCE hInstance)
{
	if(g_pInput == NULL) {

		// DirectInputオブジェクトの作成
		if(FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&g_pInput, NULL))) {

			return false;
		}
	}

	return true;
}

//=============================================================================
// キーボードの初期化
//=============================================================================
bool Keyboard_Initialize()
{
	// 入力処理の初期化
	if (!initialize(*System_GethInstance())) {

		MessageBox(*System_GethWnd(), "DirectInputオブジェクトが作れねぇ！", "警告！", MB_ICONWARNING);
		return false;
	}

	// デバイスの作成
	if (FAILED(g_pInput->CreateDevice(GUID_SysKeyboard, &g_pDevKeyboard, NULL)))
	{
		MessageBox(*System_GethWnd(), "キーボードがねぇ！", "警告！", MB_ICONWARNING);
		return false;
	}

	// データフォーマットを設定
	if (FAILED(g_pDevKeyboard->SetDataFormat(&c_dfDIKeyboard)))
	{
		MessageBox(*System_GethWnd(), "キーボードのデータフォーマットを設定できませんでした。", "警告！", MB_ICONWARNING);
		return false;
	}

	// 協調モードを設定（フォアグラウンド＆非排他モード）
	if (FAILED(g_pDevKeyboard->SetCooperativeLevel(*System_GethWnd(), (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		MessageBox(*System_GethWnd(), "キーボードの協調モードを設定できませんでした。", "警告！", MB_ICONWARNING);
		return false;
	}

	// キーボードへのアクセス権を獲得(入力制御開始)
	g_pDevKeyboard->Acquire();

	//マウスデバイス取得
	if (FAILED(g_pInput->CreateDevice(GUID_SysMouse, &g_pDevMouse, NULL)))
	{
		MessageBox(*System_GethWnd(), "マウスがねぇ！", "警告！", MB_ICONWARNING);
		return false;
	}

	//マウスのデータフォーマット
	if (FAILED(g_pDevMouse->SetDataFormat(&c_dfDIMouse2)))
	{
		MessageBox(*System_GethWnd(), "マウスのデータフォーマットを設定できませんでした。", "警告！", MB_ICONWARNING);
		return false;
	}

	//マウスの協調モード
	if (FAILED(g_pDevMouse->SetCooperativeLevel(*System_GethWnd(), (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)))) 
	{
		MessageBox(*System_GethWnd(), "マウスの協調モードを設定できませんでした。", "警告！", MB_ICONWARNING);
		return false;
	}

	g_pDevMouse->Acquire();

	return true;
}

//=============================================================================
// キーボードの更新処理
//=============================================================================
void Keyboard_Update(void)
{
	GetCursorPos(&g_MousePos);
	ScreenToClient(*System_GethWnd(),&g_MousePos);

	BYTE aKeyState[NUM_KEY_MAX];

	// デバイスからデータを取得
	if(SUCCEEDED(g_pDevKeyboard->GetDeviceState(sizeof(aKeyState), aKeyState)))
	{
		// aKeyState[DIK_SPACE] & 0x80

		for(int nCnKey = 0; nCnKey < NUM_KEY_MAX; nCnKey++)
		{
			// キートリガー・リリース情報を生成
			g_aKeyStateTrigger[nCnKey] = (g_aKeyState[nCnKey] ^ aKeyState[nCnKey]) & aKeyState[nCnKey];
			g_aKeyStateRelease[nCnKey] = (g_aKeyState[nCnKey] ^ aKeyState[nCnKey]) & g_aKeyState[nCnKey];


			// キープレス情報を保存
			g_aKeyState[nCnKey] = aKeyState[nCnKey];
		}
	}
	else
	{
		// キーボードへのアクセス権を取得
		g_pDevKeyboard->Acquire();
	}

	if(SUCCEEDED(g_pDevMouse->GetDeviceState(sizeof(DIMOUSESTATE2),&g_MouseState2)))
	{
	}
	else
	{
		g_pDevMouse->Acquire();
	}

}

//=============================================================================
// キーボードの終了処理
//=============================================================================
void Keyboard_Finalize(void)
{
	//マウスデバイスの開放
	if(g_pDevMouse != NULL)
	{
		g_pDevMouse->Release();
		g_pDevMouse = NULL;
	}

	if (g_pDevKeyboard != NULL)
	{// 入力デバイス(キーボード)の開放
	 // キーボードへのアクセス権を開放(入力制御終了)
		g_pDevKeyboard->Unacquire();

		g_pDevKeyboard->Release();
		g_pDevKeyboard = NULL;
	}

	// 入力処理の終了処理
	if (g_pInput != NULL) {

		// DirectInputオブジェクトの開放
		g_pInput->Release();
		g_pInput = NULL;
	}
}

//=============================================================================
// キーボードのプレス状態を取得
//=============================================================================
bool Keyboard_IsPress(int nKey)
{
	return (g_aKeyState[nKey] & 0x80) ? true : false;
}

//=============================================================================
// キーボードのトリガー状態を取得
//=============================================================================
bool Keyboard_IsTrigger(int nKey)
{
	return (g_aKeyStateTrigger[nKey] & 0x80) ? true: false;
}

//=============================================================================
// キーボードのリリ－ス状態を取得
//=============================================================================
bool Keyboard_IsRelease(int nKey)
{
	return (g_aKeyStateRelease[nKey] & 0x80) ? true: false;
}

//=============================================================================
//
//=============================================================================
bool Mouse_IsLeftDown()
{
	return (g_MouseState2.rgbButtons[0] & 0x80) ? true : false;
}

bool Mouse_IsRightDown() 
{
	return (g_MouseState2.rgbButtons[1] & 0x80) ? true : false;
}

LONG Mouse_IsMouseX()
{
	return g_MousePos.x;
}

LONG Mouse_IsMouseY()
{
	return g_MousePos.y;
}
