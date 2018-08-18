//
//	ReadStruct.h
//		USER:HIROMASA IKEDA		DATE:2018/07/05
//===============================================
/*
	���L�����ׂ��\����
*/
#pragma once
#ifndef READSTRUCT_H
#define READSTRUCT_H

//***********************************************
//	�`��^�C�v
//***********************************************
const enum DRAW_TYPE
{
	PORIGON_DRAW,
	TEXTURE_SIZE,
	TEXTURE_FILL,
	TEXTURE_CLIP,
	SPRITE_DRAW,
	SPRITE_ROTATION
};

//***********************************************
//	�A�j���[�V�����^�C�v
//***********************************************
const enum ANIMETION_TYPE
{
	ANIMETION_NOLOOP,
	ANIMETION_LOOP
};

//***********************************************
//	�\���̐錾
//***********************************************
typedef struct
{
	float width;
	float height;
}SCALE, TEXSCALE;

typedef struct
{
	float* width;
	float* height;
}lpSCALE;

typedef struct TEXCOORD
{
	float x;
	float y;
};

typedef struct PATERN
{
	int AnimePatern;
	int MaxPatern;
	int YMaxPatern;
};

//***********************************************
//	�`��\����
//***********************************************
typedef struct Porigon2D
{
	D3DXVECTOR4 position;
	D3DCOLOR color;
};

typedef struct Sprite2D
{
	D3DXVECTOR4 Position;
	D3DCOLOR Color;
	D3DXVECTOR2 TexCord;
};

#endif // !READSTRUCT_H

