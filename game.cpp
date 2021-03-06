//
//	game.cpp
//		USER:HIROMASA IKEDA		DATE:2018/06/13
//====================================================
#include"common.h"
#include"Player.h"
#include"Block.h"
#include"Animetion.h"
#include"Debug_Circle.h"
#include"Enemy.h"
#include"Bullet.h"
#include"game.h"

//==========================================
//	初期化処理
//==========================================
void Game_Initialize() 
{
	srand(time(NULL));
	Player_Initialize();
	Block_Initialize();
	Enemy_Initialize();
	Bullet_Initialize();
}

//==========================================
//	更新処理
//==========================================
void Game_Update() 
{

	Block_Update();
	Animetion_Update();
	Player_Update();
	Enemy_Update();
	Bullet_Update();
}

//==========================================
//	描画処理
//==========================================
void Game_Render() 
{

	DebugPrimitive_BatchBegin();

	Block_Render();
	Bullet_Render();
	Enemy_Render();
	Player_Render();

	DebugPrimitive_BatchRun();
}

//=========================================
//	終了処理
//=========================================
void Game_Finalize() 
{
	Bullet_Finalize();
	Player_Finalaize();
	Enemy_Finalize();
}