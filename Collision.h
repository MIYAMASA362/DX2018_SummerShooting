//
//	Collision.h
//		USER:HIROMASA IKEDA		DATE:2018/06/26
//===============================================
#pragma once

#ifndef COLLISION_H
#define COLLISION_H

#include<d3dx9.h>
#include<vector>
#include"TransformClass.h"

using namespace std;

//===============================================
//	あたり判定構造体
//===============================================
typedef struct
{
	D3DXVECTOR2 Center;
	SCALE Scale;
}Box;

typedef struct
{
	D3DXVECTOR2* lpCenter;
	lpSCALE* lpScale;
}lpBox;

typedef struct Circle
{
	D3DXVECTOR2 Center;
	float radius;
};

enum HIT_PORTION
{
	NONE,
	TOP,
	BOTTOM,
	RIGHT,
	LEFT,
	HIT
};

//===============================================
//	Collision クラス
//===============================================
class Collision
{
private:
	
public :
	vector<Box*> BoxIndex;
	bool trigger;
	Collision();
};

//===============================================
//	Physics
//===============================================
class Physics
{
private:
	
public:
	Collision* pCollision;
	Transform* pTransform;	//親位置
	
	D3DXVECTOR2 Force;		//力
	D3DXVECTOR2 velocity;	//速度

	bool UseGravity;	//重力を使う
	void Update(float Speed);		//更新処理
	HIT_PORTION Collision_Hit(const Collision* pCollision);	//あたり判定


	Physics();
};

//***********************************************
//	プロトタイプ宣言
//***********************************************
bool Collision_Hit(const Circle *pCircle_A, const Circle *pCircle_B);
bool Collision_Hit(const Circle *pCircle_A, const Box *pBox_B);
bool Collision_Hit(const Box *pBox_A, const Box *pBox_B);

#endif

