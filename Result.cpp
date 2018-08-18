//
//	Result.cpp
//		USER:HIROMASA IKEDA		DATE:2018/07/11
//===============================================
#include"common.h"
#include"TransformClass.h"
#include"TextureClass.h"
#include"Texture.h"
#include"SpriteClass.h"
#include"input.h"
#include"Scene.h"
#include"Result.h"

static Sprite Result_Text;
static Sprite ResultImage;

void Result_Initialize() 
{
	Result_Text.transform.Position = { SCREEN_WIDTH* 0.5f,SCREEN_HEIGHT * 0.5f };
	Result_Text.transform.Scale = {200,180};
	Result_Text.Texture_index = ResultText;

	ResultImage.transform.Position = { SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f };
	ResultImage.transform.Scale = { SCREEN_WIDTH,SCREEN_HEIGHT };
	ResultImage.transform.Color = D3DCOLOR_RGBA(255, 255, 255, 255);
	ResultImage.Texture_index = TitleImage;
}

void Result_Update() 
{
	if(Keyboard_IsRelease(DIK_SPACE))
	{
		Scene_Change(SCENE_TITLE);
	}
}

void Result_Render() 
{
	ResultImage.Draw(TEXTURE_FILL);
	Result_Text.Draw(TEXTURE_FILL);
}

void Result_Finalize()
{

}
