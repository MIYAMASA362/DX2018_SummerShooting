//
//	Acter.h
//		USER:HIROMASA IKEDA		DATE:2018/07/05
//***********************************************
#pragma once
#ifndef ACTER_H
#define ACTER_H
#include"common.h"
#include"AnimetionClass.h"
#include"SpriteClass.h"

//***********************************************
//	Acter �N���X
//***********************************************
/*
 +�p���Fpublic Sprite,Animetion
 ->bUse
 ->bRender
 ->Speed
 ->Postion
 ->Scale
 ->Color
 ->Texture_index
 ->TexCoord
 ->TexScale
 ->Rotation
 ->Patern
 ->Waitframe
 ->Createframe
 +�֐�
 ->Draw(int type)
 ->Create(D3DXVECTOR2 *pPosition)
 ->Destroy()
 ->Physics()
*/
class Acter :public Animetion, public Sprite
{
public :
	bool bUse;			//�g�p����
	bool bRender;		//�`�悷�邩

	Acter();
	void LoopRotation();
	void Create(D3DXVECTOR2 *pPosition);
	void Destroy();
	void Physics();
};

#endif
