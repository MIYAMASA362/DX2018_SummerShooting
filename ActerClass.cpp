//
//	Acter.h
//		USER:HIROMASA IKEDA		DATE:2018/07/06
//===============================================
#include"common.h"
#include"TransformClass.h"
#include"Sprite.h"
#include"TextureClass.h"
#include"AnimetionClass.h"
#include"SpriteClass.h"
#include"ActerClass.h"

//***********************************************
//	�R���X�g���N�^
//***********************************************
Acter::Acter() 
{
	bUse = false;
	bRender = false;
}

//***********************************************
//	��]�`��
//***********************************************
void Acter::LoopRotation() 
{
	Rotation +=2.0f;
	//Draw_LoopRotation(Texture_index, Position, Scale, Color, TexScale, Patern,Waitframe,Createframe,Rotation);
}

//***********************************************
//	�폜����
//***********************************************
void Acter::Destroy() 
{
	bUse = false;
	bRender = false;
}

//***********************************************
//	�쐬����
//***********************************************
void Acter::Create(D3DXVECTOR2 *pPosition) 
{
	bUse = true;
	bRender = true;
	//transform.Position = *pPosition;
}