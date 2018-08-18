//
//	Scene.h
//		USER:HIROMASA IKEDA		DATE:2018/07/11
//===============================================
#pragma once
#ifndef SCENE_H
#define SCENE_H

//ÉVÅ[Éì
typedef enum SCENE_INDEX 
{
	SCENE_TITLE,
	SCENE_GAME,
	SCENE_RESULT,
	SCENE_MAX		//è„å¿
};

void Scene_Initialize(SCENE_INDEX Scene_Index);
void Scene_Update();
void Scene_Render();
void Scene_Finalize();
void Scene_Change(SCENE_INDEX Scene_Index);
void Scene_Check();

#endif // !SCENE_H

