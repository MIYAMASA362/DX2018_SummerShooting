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
//	�N���X�FAnimetion	
//***********************************************
/*
�A�j���[�V�������
public :
->Patern
->Waitframe
->Createframe
*/
class Animetion :virtual public Texture
{
public:
	Transform transform;
	PATERN Patern;		//�Eint AnimePatern, int MaxPatern, int YMaxPatern
	int Waitframe;		//�E�A�j���[�V�������x
	int Createframe;	//�E�������ꂽ���̃t���[��

	bool Anime(int type);		//�A�j���[�V�����֐�
								//void Anime(int type, bool Keep);	//�A�j���[�V�����p�^�[����ێ�
};

#endif // !ANIMETIONCLASS_H

