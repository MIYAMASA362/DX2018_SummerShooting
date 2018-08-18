//
//	common.h
//		USER:HIROMASA IKEDA		DATE:2018/07/04
//====================================================
//ヘッダーに記入していいもの
//	定数
//	関数のプロトタイプ宣言
//	構造体の宣言
//	enum
//	typedef
//	inline関数
//	マクロ定義
//----------------------------------------------------
#pragma once

#ifndef COMMON_H
#define COMMON_H

#include<windows.h>
#include<d3dx9.h>
#define INIGUID
#include<dinput.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<time.h>

//構造体や列挙型はこちらへ
#include"ReadStruct.h"

#define FVF_VERTEX2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
#define FVF_VERTEX2DTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

//	画面設定
//----------------------------------------------------
//画面サイズ
#define SCREEN_WIDTH (1024)
#define SCREEN_HEIGHT (576)

//クラス名
#define CLASS_NAME		"GameWindow"

//画面タイトル
#define WINDOW_CAPTION "シューティングゲーム"

//画面スタイル
#define WINDOW_STYLE	(WS_OVERLAPPEDWINDOW ^ (WS_MAXIMIZEBOX  | WS_THICKFRAME))

//画面背景色
#define BLACK (D3DCOLOR_RGBA(255, 255, 255, 255))

#define CLEAR_SCORE	(100)

#define GRAVITY			(0.98f)		//重力

#define ENEMY_MAX		(100)
#define ENEMY_SPEED		(1.0f)
#define ENEMY_SCALE_WIDTH	(60)
#define ENEMY_SCALE_HEIGHT	(60)

#endif // !COMMON_H
