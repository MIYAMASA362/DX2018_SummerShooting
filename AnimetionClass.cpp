//
//	AnimetionClass.cpp
//		USER:HIROMASA IKEDA		DATE:2018/07/06
//===============================================
#include"common.h"
#include"TextureClass.h"
#include"TransformClass.h"
#include"Animetion.h"
#include"AnimetionClass.h"
//***********************************************
//	Animetion::Anime	アニメーション描画関数
//***********************************************
/*
・描画
ANIMETION_NOLOOP		//ループしないアニメーション
ANIMETION_LOOP		//ループするアニメーション
*/
bool Animetion::Anime(int type)
{
	switch (type)
	{
	case ANIMETION_NOLOOP:
		return Animetion_NoLoop(Texture_index, transform.Position, transform.Scale, transform.Color, TexScale, Patern, Waitframe, Createframe);
	case ANIMETION_LOOP:
		Animetion_Loop(Texture_index, transform.Position,transform.Scale,transform.Color, TexScale, Patern, Waitframe,Createframe);
		return false;
	}
}
