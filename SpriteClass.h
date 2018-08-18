//
//	SpriteClass.h
//		USER:HIROMASA IKEDA		DATE:2018/07/05
//===============================================
#pragma once
#ifndef SPRITECLASS_H
#define SPRITECLASS_H

#include"common.h"
#include"TransformClass.h"
#include"TextureClass.h"

//***********************************************
//	Sprite �N���X
//***********************************************
/*
+�p���Fpublic Texture,public Transform
->Position		//�ʒu
->Scale			//�傫��
->Color			//�F
->Texture_index	//�e�N�X�`���ԍ�
->TexCoord		//�e�N�X�`��
->TexScale		//�e�N�X�`���T�C�Y
->Rotation		//��]�p�x
+�֐�
->Draw(int type) //�`��
->Rotate(int Rotation)	//��]������
*/
class Sprite :virtual public Texture
{
public:
	Transform transform;	//��{���
	float Rotation;		//�p�x

	Sprite();
	void Draw(int type);
};

//===============================================
//	Render �N���X
//===============================================
class Render
{
private:

public:
	Transform* pTransform;
	Texture* pTexture;
	void Draw(DRAW_TYPE type);

	Render();
	Render(Transform* transform,Texture* texture);
};

#endif