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

#define PLAYER_ROF (10) //�A�ˑ��x

//-----------------------------------------------
//	Player �N���X
//-----------------------------------------------
class PLAYER :public GameObject
{
private:
public:
	bool bJump;		//��i�W�����v
	bool bJump2;	//��i�W�����v
	int Burst;		//�A�ˑ��x		

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
