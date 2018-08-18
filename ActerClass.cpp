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
//	コンストラクタ
//***********************************************
Acter::Acter() 
{
	bUse = false;
	bRender = false;
}

//***********************************************
//	回転描画
//***********************************************
void Acter::LoopRotation() 
{
	Rotation +=2.0f;
	//Draw_LoopRotation(Texture_index, Position, Scale, Color, TexScale, Patern,Waitframe,Createframe,Rotation);
}

//***********************************************
//	削除処理
//***********************************************
void Acter::Destroy() 
{
	bUse = false;
	bRender = false;
}

//***********************************************
//	作成処理
//***********************************************
void Acter::Create(D3DXVECTOR2 *pPosition) 
{
	bUse = true;
	bRender = true;
	//transform.Position = *pPosition;
}