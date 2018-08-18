//
//	Bullet.h
//		USER:HIROMASA IKEDA		DATE:2018/08/16
//===============================================
#pragma once

#ifndef BULLET_H

#include<d3dx9.h>
#include"TransformClass.h"
#include"TextureClass.h"
#include"Collision.h"
#include"SpriteClass.h"

#define ENEMY_BULLET_MAX (50)
#define PLAYER_BULLET_MAX (50)
#define ENEMY_BULLET_SPEED (10.0f)
#define PLAYER_BULLET_SPEED (20.0f)

//===============================================
//	enum
//===============================================

//-------------------------------------
//	BULLET_TYPE 
//-------------------------------------
enum BULLET_TYPE
{
	PLAYER_BULLET,
	ENEMY_BULLET
};

//===============================================
//	Bullet ƒNƒ‰ƒX
//===============================================
class Bullet
{
private:

public:
	Transform transform;
	Texture texture;
	Collision collision;
	Render render;
	D3DXVECTOR2 Speed;

	Box Box_Collision;

	bool Use;

	void Update();
	Bullet();
};

void Bullet_Initialize();
void Bullet_Update();
void Bullet_Render();
void Bullet_Finalize();
void Bullet_Create(D3DXVECTOR2 Position,BULLET_TYPE type);
void Bullet_Destroy(BULLET_TYPE type, int index);
Collision* Bullet_GetCollision(BULLET_TYPE type, int index);
bool Bullet_IsInable(BULLET_TYPE type, int index);

#endif // !BULLET_H

