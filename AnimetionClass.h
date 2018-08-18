//
//	AnimetionClass.h
//		USER:HIROMASA IKEDA		DATE:2018/07/05
//===============================================
#pragma once
#ifndef ANIMETIONCLASS_H
#define ANIMETIONCLASS_H

#include"common.h"
#include"TextureClass.h"
#include"TransformClass.h"

//***********************************************
//	クラス：Animetion	
//***********************************************
/*
アニメーション情報
public :
->Patern
->Waitframe
->Createframe
*/
class Animetion :virtual public Texture
{
public:
	Transform transform;
	PATERN Patern;		//・int AnimePatern, int MaxPatern, int YMaxPatern
	int Waitframe;		//・アニメーション速度
	int Createframe;	//・生成された時のフレーム

	bool Anime(int type);		//アニメーション関数
								//void Anime(int type, bool Keep);	//アニメーションパターンを保持
};

#endif // !ANIMETIONCLASS_H

