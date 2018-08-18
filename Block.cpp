//
//	Block.cpp
//		USER:HIROMASA IKEDA		DATE2018/07/13
//===============================================
#include"common.h"
#include"Block.h"
#include"SpriteClass.h"
#include"TransformClass.h"
#include"TextureClass.h"
#include"Texture.h"

//-----------------------------------------------
//	ÉOÉçÅ[ÉoÉãïœêî
//-----------------------------------------------
static BLOCK Block = {};
static BLOCK Block2 = {};
static Sprite BackGround = {};
static Collision collision = {};

//***********************************************
//	èâä˙âª
//***********************************************
void Block_Initialize() 
{
	Block.transform.Scale = { SCREEN_WIDTH,124 };
	Block.transform.Position = {SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT - Block.transform.Scale.height * 0.5f};
	Block.transform.Color = D3DCOLOR_RGBA(255,255,255,255);
	Block.Box_Collision.Scale = Block.transform.Scale;
	collision.BoxIndex.push_back(&Block.Box_Collision);

	Block2.transform.Scale = { 200,100 };
	Block2.transform.Position = { SCREEN_WIDTH * 0.5f,Block.transform.Position.y - Block.transform.Scale.height *0.5f - 120.0f};
	Block2.transform.Color = D3DCOLOR_RGBA(255, 0, 255, 255);
	Block2.Box_Collision.Scale = Block2.transform.Scale;
	collision.BoxIndex.push_back(&Block2.Box_Collision);

	BackGround.transform.Position = {SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f};
	BackGround.Texture_index = TitleTex;
}

void Block_Update() 
{
	Block.Box_Collision.Center = Block.transform.Position;
	Block2.Box_Collision.Center = Block2.transform.Position;
}

void Block_Render() 
{
	//BackGround.Draw(TEXTURE_SIZE);
	Block.Draw(PORIGON_DRAW);
	Block2.Draw(PORIGON_DRAW);
}

Collision* Block_Collision()
{
	return  &collision;
}

Box* Block_Box()
{
	return &Block.Box_Collision;
}

Box* Block2_Box()
{
	return &Block2.Box_Collision;
}