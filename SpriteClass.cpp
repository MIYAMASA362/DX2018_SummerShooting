//
//	SpriteClass.cpp
//		USER:HIROMASA IKEDA		DATE:2018/07/06
//===============================================
#include"common.h"
#include"TextureClass.h"
#include"TransformClass.h"
#include"Sprite.h"
#include"SpriteClass.h"
//***********************************************
//	コンストラクタ
//***********************************************
Sprite::Sprite() 
{
	Rotation = 0;
}


//***********************************************
//	Sprite::Draw	描画関数
//***********************************************
/*
・描画
PORIGON_DRAW		//ポリゴン
TEXTURE_SIZE		//元画像サイズ
TEXTURE_FILL		//画像全張り
TEXTURE_CLIP		//画像切り抜き
SPRITE_DRAW			//スプライト
SPRITE_ROTATION		//回転プライト
*/
void Sprite::Draw(int type)
{
	switch (type)
	{
	case PORIGON_DRAW:
		Draw_Porigon(transform.Position, transform.Scale, transform.Color);
		return;
	case TEXTURE_SIZE:
		Draw_TextureSize(Texture_index, transform.Position, transform.Color);
		return;
	case TEXTURE_FILL:
		Draw_TextureFill(Texture_index, transform.Position, transform.Scale, transform.Color);
		return;
	case TEXTURE_CLIP:
		Draw_TextureClip(Texture_index, transform.Position, transform.Color, TexCoord, transform.Scale);
		return;
	case SPRITE_DRAW:
		Draw_Sprite(Texture_index, transform.Position, transform.Scale, transform.Color, TexCoord, TexScale);
		return;
	case SPRITE_ROTATION:
		Draw_Rotate(Texture_index, transform.Position, transform.Scale, transform.Color, TexCoord, TexScale, Rotation);
		return;
	}
}


//===============================================
//	Render コンストラクタ
//===============================================

//-------------------------------------
//	Render()
//-------------------------------------
Render::Render()
{

}

//-------------------------------------
//	Render(Transform* transform, Texture* texture)
//-------------------------------------
Render::Render(Transform* transform,Texture* texture)
{
	pTransform = transform;
	pTexture = texture;
}

//===============================================
//	Redner Draw(int type)
//===============================================
void Render::Draw(DRAW_TYPE type)
{
	switch (type)
	{
	case PORIGON_DRAW:
		Draw_Porigon(pTransform->Position, pTransform->Scale, pTransform->Color);
		return;
	case TEXTURE_SIZE:
		Draw_TextureSize(pTexture->Texture_index, pTransform->Position, pTransform->Color);
		return;
	case TEXTURE_FILL:
		Draw_TextureFill(pTexture->Texture_index, pTransform->Position, pTransform->Scale, pTransform->Color);
		return;
	case TEXTURE_CLIP:
		Draw_TextureClip(pTexture->Texture_index, pTransform->Position, pTransform->Color, pTexture->TexCoord, pTransform->Scale);
		return;
	case SPRITE_DRAW:
		Draw_Sprite(pTexture->Texture_index, pTransform->Position, pTransform->Scale, pTransform->Color, pTexture->TexCoord, pTexture->TexScale);
		return;
	case SPRITE_ROTATION:
		Draw_Rotate(pTexture->Texture_index, pTransform->Position, pTransform->Scale, pTransform->Color, pTexture->TexCoord, pTexture->TexScale, pTransform->Rotation);
		return;
	}
}