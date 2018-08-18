//
//	Enemy.h
//		USER: HIROMASA IKEDA	DATE:2018/08/16
//===============================================
#pragma once

#ifndef ENEMY_H
#define ENEMY_H

#include<d3dx9.h>
#include"GameObject.h"

//===============================================
//	Enemy ƒNƒ‰ƒX
//===============================================
class Enemy :public GameObject
{
private:

public:
	bool Use;
	Box Box_Collision;
	void Update();
	Enemy();
	~Enemy();
};

void Enemy_Initialize();
void Enemy_Update();
void Enemy_Render();
void Enemy_Create(D3DXVECTOR2 Position);
void Enemy_Destroy(int index);
void Enemy_Finalize();

#endif // !ENEMY_H

