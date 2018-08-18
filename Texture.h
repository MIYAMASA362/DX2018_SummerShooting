//
//	Texture.h
//		USER:HIROMASA IKEDA		DATE:2018/06/21
//===============================================
#pragma once
#ifndef TEXTURE_H
#define TEXTURE_H

#include"common.h"

//***********************************************
//	テクスチャ名リスト
//***********************************************
#define TEXTURE_FILENAME_MAX (64)

static enum TEXTURE_NAMELIST
{
	animetion01,
	witch3,
	Animetion02,
	TitleTex,
	Player_Bullet,
	number,
	GumMan,
	GameStart,
	TitleImage,
	ResultText
};

//***********************************************
//	テクスチャデータ
//***********************************************
typedef struct TextureFile_tag
{
	char FileName[TEXTURE_FILENAME_MAX];
	int width;
	int height;
}TextureFileData;

static const TextureFileData TEXTURE_FILELIST[] = {
	{ "Texture/animetion01.png",960,384 },
	{ "Texture/witch3.png",128,128 },
	{ "Texture/Animetion02.png",960,576},
	{ "Texture/DX_Title.png",1024,576},
	{ "Texture/BULLET.png",64,64},
	{ "Texture/Number.png",640,64},
	{ "Texture/GunMan.png",180,222},
	{ "Texture/GameStart.png",291,173},
	{ "Texture/Title_Top.jpg",615,409},
	{ "Texture/Result_Text.png",524,120}
};

//***********************************************
//	プロトタイプ宣言
//***********************************************
void Texture_Initialize(HWND *hWnd);
void Texture_Finalize();

LPDIRECT3DTEXTURE9 Texture_GetTexture(int index);
int Texture_GetWidth(int index);
int Texture_GetHeight(int index);
#endif
