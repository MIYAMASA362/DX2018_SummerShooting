//
//	Scene.cpp
//		USER:HIROMASA IKEDA		DATE:2018/07/11
//===============================================
#include"common.h"
#include"Title.h"
#include"game.h"
#include"Result.h"
#include"Fade.h"
#include"Scene.h"
//***********************************************
//	グローバル変数
//***********************************************
static SCENE_INDEX g_SceneIndex;
static SCENE_INDEX g_SceneNextIndex;

/*
typedef void(*SceneFunc)();

static const SceneFunc cInit[] =
{
	Title_Initialize,
	Game_Initialize,
	Result_Initialize
};
*/

//***********************************************
//	初期化処理
//***********************************************
void Scene_Initialize(SCENE_INDEX Scene_Index) 
{
	g_SceneNextIndex = g_SceneIndex = Scene_Index;

	switch (g_SceneIndex) 
	{
	case SCENE_TITLE:
		Title_Initialize();
		break;
	case SCENE_GAME:
		Game_Initialize();
		break;
	case SCENE_RESULT:
		Result_Initialize();
		break;
	}

	//Fade_Triger(false, 10, D3DCOLOR_RGBA(0, 0, 0, 255));
}

//***********************************************
//	更新処理
//***********************************************
void Scene_Update() 
{
	if (Fade_IsFade())
	{
		Fade_Update();
		return;
	}

	switch (g_SceneIndex) 
	{
	case SCENE_TITLE:
		Title_Update();
		break;
	case SCENE_GAME:
		Game_Update();
		break;
	case SCENE_RESULT:
		Result_Update();
		break;
	}

}

//***********************************************
//	描画処理
//***********************************************
void Scene_Render()
{
	switch (g_SceneIndex)
	{
	case SCENE_TITLE:
		Title_Render();
		break;
	case SCENE_GAME:
		Game_Render();
		break;
	case SCENE_RESULT:
		Result_Render();
		break;
	}
	Fade_Render();
}

//***********************************************
//	終了処理
//***********************************************
void Scene_Finalize() 
{
	switch (g_SceneIndex)
	{
	case SCENE_TITLE:
		Title_Finalize();
		break;
	case SCENE_GAME:
		Game_Finalize();
		break;
	case SCENE_RESULT:
		Result_Finalize();
		break;
	}

}

//***********************************************
//	切り替え処理
//***********************************************
void Scene_Change(SCENE_INDEX Scene_Index)
{
	g_SceneNextIndex = Scene_Index;
}

//***********************************************
//	チェック
//***********************************************
void Scene_Check() 
{
	//フェードインしていたら
	if(Fade_IsFade())
	{
		return;
	}
	else
	{
		if(Fade_Alpha())
		{
			Scene_Finalize();
			Scene_Initialize(g_SceneNextIndex);
			Fade_Triger(false, 60, D3DCOLOR_RGBA(0, 0, 0, 255));
		}
	}

	if (g_SceneIndex != g_SceneNextIndex)
	{
		Fade_Triger(true,60,D3DCOLOR_RGBA(0,0,0,255));
		
	}

}
