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
//	Acter クラス
//***********************************************
/*
 +継承：public Sprite,Animetion
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
 +関数
 ->Draw(int type)
 ->Create(D3DXVECTOR2 *pPosition)
 ->Destroy()
 ->Physics()
*/
class Acter :public Animetion, public Sprite
{
public :
	bool bUse;			//使用中か
	bool bRender;		//描画するか

	Acter();
	void LoopRotation();
	void Create(D3DXVECTOR2 *pPosition);
	void Destroy();
	void Physics();
};

#endif
