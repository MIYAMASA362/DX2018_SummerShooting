//
//	Animetion.h
//		USER:HIROMASA IKEDA		DATE:2018/07/05
//===============================================
#pragma once
#ifndef ANIMETION_H
#define ANIMETION_H

#include"common.h"

//***********************************************
//	プロトタイプ宣言	
//***********************************************

void Animetion_Initialize();
void Animetion_Update();
int Animetion_GetFrame();

bool Animetion_NoLoop(int Texture_index, D3DXVECTOR2 Position, SCALE Scale,D3DCOLOR Color, TEXSCALE TexScale, int YMaxPatern, int MaxPatern, int Waitframe);
bool Animetion_NoLoop(int Texture_index, D3DXVECTOR2 Position, SCALE Scale,D3DCOLOR Color, TEXSCALE TexScale, PATERN Patern, int Waitframe);
bool Animetion_NoLoop(int Texture_index, D3DXVECTOR2 Position, SCALE Scale, D3DCOLOR Color, TEXSCALE TexScale, PATERN Patern, int Waitframe, int Createframe);
void Animetion_Loop(int Texture_index, D3DXVECTOR2 Position, SCALE Scale,D3DCOLOR Color, TEXSCALE TexScale, int YMaxPatern, int MaxPatern, int Waitframe);
void Animetion_Loop(int Texture_index, D3DXVECTOR2 Position, SCALE Scale, D3DCOLOR Color, TEXSCALE TexScale, PATERN Patern, int Waitframe);
void Animetion_Loop(int Texture_index, D3DXVECTOR2 Position, SCALE Scale, D3DCOLOR Color, TEXSCALE TexScale, PATERN Patern, int Waitframe, int Createframe);
void Animetion_Score(int texture_index, D3DXVECTOR2 position, D3DCOLOR color, TEXSCALE TexScale, int YMaxPatern, int MaxPatern, int Score, bool bLeft, bool bZero, int digitNum);

#endif

