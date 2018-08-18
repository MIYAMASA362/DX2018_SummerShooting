//
//	TextureClass.h
//		USER:HIROMASA IKEDA		DATE:2018/07/05
//===============================================
#pragma once
#ifndef TEXTURECLASS_H
#define TEXTURECLASS_H

#include"common.h"

//***********************************************
//	Texture �N���X
//***********************************************
/*
�e�N�X�`�����
public :
-> Texture_index
-> TexCoord
-> TexScale
*/
class Texture
{
public:
	int Texture_index;
	TEXCOORD TexCoord;
	TEXSCALE TexScale;
};


#endif
