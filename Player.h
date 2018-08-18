//
//	Player.h
//		USER:HIROMASA IEKDA		DATE:2018/06/20
//===============================================
#pragma once

#ifndef PLAYER_H
#define PLAYER_H

#include"common.h"
#include"Collision.h"
#include"GameObject.h"

#define PLAYER_ROF (10) //連射速度

//-----------------------------------------------
//	Player クラス
//-----------------------------------------------
class PLAYER :public GameObject
{
private:
public:
	bool bJump;		//一段ジャンプ
	bool bJump2;	//二段ジャンプ
	int Burst;		//連射速度		

	Box Box_Collision;

	PLAYER();
	void Update();
};


void Player_Initialize();
void Player_Update();
void Player_Render();
void Player_Finalaize();
D3DXVECTOR2 *Player_GetPosition();

#endif
