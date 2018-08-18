//
//	Sprite.h
//		USER:HIROMASA IEDA		DATE:2018/06/20
//===============================================
#pragma once
#ifndef SPRITE_H
#define SPRITE_H

#include"common.h"

//***********************************************
//	�v���g�^�C�v�錾
//***********************************************
//�|���S���`��
void Draw_Porigon(D3DXVECTOR2 Position,SCALE Scale,D3DCOLOR Color);
void Draw_Porigon(D3DXVECTOR2 *pPosition, SCALE *pScale, D3DCOLOR *pColor);

//�摜�T�C�Y�`��
void Draw_TextureSize(int Texture_index,D3DXVECTOR2 Position,D3DCOLOR Color);
void Draw_TextureSize(int *pTexture_index, D3DXVECTOR2 *pPosition, D3DCOLOR *pColor);

//�|���S���T�C�Y�ɕ`��
void Draw_TextureFill(int Texture_index,D3DXVECTOR2 Position,SCALE Scale,D3DCOLOR Color);
void Draw_TextureFill(int *pTexture_index, D3DXVECTOR2 *pPosition, SCALE *pScale, D3DCOLOR *pColor);

//�e�N�X�`���؂蔲���T�C�Y�`��
void Draw_TextureClip(int Texture_index,D3DXVECTOR2 Position,D3DCOLOR Color,TEXCOORD TexCoord,TEXSCALE TexScale);
void Draw_TextureClip(int *pTexture_index,D3DXVECTOR2 *pPosition,D3DCOLOR *pColor,TEXCOORD *pTexCoord,TEXSCALE *pTexScale);

//�X�v���C�g�`��
void Draw_Sprite(int Texture_index,D3DXVECTOR2 Position,SCALE Scale,D3DCOLOR Color,TEXCOORD TexCoord,TEXSCALE TexScale);
void Draw_Sprite(int *pTexture_index, D3DXVECTOR2 *pPosition, SCALE *pScale, D3DCOLOR *pColor, TEXCOORD *pTexCoord, TEXSCALE *pTexScale);

//��
void Draw_Rotate(int Texture_index, D3DXVECTOR2 Position, SCALE Scale, D3DCOLOR Color, TEXCOORD TexCoord, TEXSCALE TexScale, float Rotation);
void Draw_LoopRotation(int Texture_index, D3DXVECTOR2 Position, SCALE Scale, D3DCOLOR Color, TEXSCALE TexScale, PATERN Patern, int Waitframe, int Createframe, float Rotation);
#endif

