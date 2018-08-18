//
//	Title.cpp
//		USER:HIROMASA IKEDA		DATE:2018/07/11
//===============================================
#include"common.h"
#include"TransformClass.h"
#include"TextureClass.h"
#include"Texture.h"
#include"SpriteClass.h"
#include"input.h"
#include"Scene.h"
#include"Title.h"

//===============================================
//	SelectBlock クラス
//===============================================

//-------------------------------------
//	SelectBlock()
//-------------------------------------
SelectBlock::SelectBlock()
{
	transform.Color = D3DCOLOR_RGBA(0,0,0,255);

	render.pTexture = &texture;
	render.pTransform = &transform;

	Select = false;
}

//-------------------------------------
//	Click()
//-------------------------------------
void SelectBlock::Click()
{
	if(IsInable())
	{
		if(Mouse_IsLeftDown() || Mouse_IsRightDown())
		{
			Select = true;
		}
	}
	else
	{
		Select = false;
	}
}

//-------------------------------------
//	Hover()
//-------------------------------------
void SelectBlock::Hover()
{
	if(IsInable())
	{
			transform.Scale.width += 10.0f;
			transform.Scale.height += 10.0f;
	}
	else
	{
		transform.Scale.width -= 10.0f;
		transform.Scale.height -= 10.0f;
	}
}

//-------------------------------------
//	IsInable()
//-------------------------------------
bool SelectBlock::IsInable()
{
	if (transform.Position.x - transform.Scale.width * 0.5f <= Mouse_IsMouseX() && Mouse_IsMouseX() <= transform.Position.x + transform.Scale.width * 0.5f)
	{
		if(transform.Position.y - transform.Scale.height * 0.5f <= Mouse_IsMouseY() && Mouse_IsMouseY() <= transform.Position.y + transform.Scale.height * 0.5f)
		{
			return true;
		}
	}

	return false;
}

//-------------------------------------
//	Update()
//-------------------------------------
void SelectBlock::Update()
{
	//Hover();
	Click();
}

//===============================================
//	グローバル
//===============================================
static Sprite Title;
static Sprite TitleName;
static SelectBlock* pStageSelect;

void Title_Initialize() 
{
	TitleName.transform.Position = {SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT *0.5f};
	TitleName.transform.Scale = {540,180};
	TitleName.Texture_index = GameStart;

	Title.transform.Position = { SCREEN_WIDTH * 0.5f,SCREEN_HEIGHT * 0.5f };
	Title.transform.Scale = { SCREEN_WIDTH,SCREEN_HEIGHT};
	Title.transform.Color = D3DCOLOR_RGBA(255,255,255,255);
	Title.Texture_index = TitleImage;

	pStageSelect = new SelectBlock[STAGE_NUM];

	float SelectScale = (SELECT_WIDTH / STAGE_NUM) - (SELECT_FONT_WIDTH * 0.5f);

	for(int i= 0; i< STAGE_NUM; i++)
	{
		pStageSelect[i].transform.Scale = { SelectScale, SelectScale};
		pStageSelect[i].transform.Position.x = (SCREEN_WIDTH * 0.5) - (SELECT_WIDTH * 0.5f) + ((SELECT_FONT_WIDTH * 0.5f) + SelectScale);
		pStageSelect[i].transform.Position.y = SCREEN_HEIGHT * 0.75f;
	}
}

void Title_Update() 
{
	if (Mouse_IsMouseX() <= TitleName.transform.Position.x + TitleName.transform.Scale.width * 0.5f && Mouse_IsMouseX() >= TitleName.transform.Position.x - TitleName.transform.Scale.width * 0.5f)
	{
		if(Mouse_IsMouseY() <= TitleName.transform.Position.y + TitleName.transform.Scale.height * 0.5f && Mouse_IsMouseY() >= TitleName.transform.Position.y - TitleName.transform.Scale.height * 0.5f)
		{
			if (Mouse_IsLeftDown()) 
			{
				Scene_Change(SCENE_GAME);
			}
		}
	}

	for(int i = 0; i<STAGE_NUM; i++)
	{
		pStageSelect[i].Update();
	}

}

void Title_Render() 
{
	Title.Draw(TEXTURE_FILL);
	TitleName.Draw(TEXTURE_FILL);

	for(int i = 0; i< STAGE_NUM; i++)
	{
		pStageSelect[i].render.Draw(PORIGON_DRAW);
	}
}

void Title_Finalize() 
{
	delete[] pStageSelect;
}
