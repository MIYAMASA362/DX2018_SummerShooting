//
//	Animetion.cpp
//		USER:HIROMASA IKEDA		DATE:2018/06/22
//===============================================
#include"common.h"
#include"Texture.h"
#include"Sprite.h"
#include"Animetion.h"


static int g_FrameCounter;	//・フレームカウンタ

//***********************************************
//	フレーム設定
//***********************************************
void Animetion_Initialize()
{
	g_FrameCounter = 0;
}

//***********************************************
//	フレーム取得	
//***********************************************
int Animetion_GetFrame()
{
	return g_FrameCounter;
}

//***********************************************
//	フレーム更新
//***********************************************
void Animetion_Update()
{
	g_FrameCounter++;
}

//***********************************************
//	アニメーション NOLOOP
//***********************************************
bool Animetion_NoLoop(int Texture_index, D3DXVECTOR2 Position, SCALE Scale,D3DCOLOR Color, TEXSCALE TexScale, int YMaxPatern, int MaxPatern,int Waitframe) 
{
	float width = Texture_GetWidth(Texture_index);
	float height = Texture_GetHeight(Texture_index);

	int AnimePatern = min((g_FrameCounter / Waitframe),MaxPatern);

	TEXCOORD AnimeTex = { TexScale.width * (AnimePatern % YMaxPatern),TexScale.height * (AnimePatern / YMaxPatern)};
	Draw_TextureClip(Texture_index,Position,Color,AnimeTex,TexScale);

	return AnimePatern >= MaxPatern;
}

bool Animetion_NoLoop(int Texture_index, D3DXVECTOR2 Position, SCALE Scale,D3DCOLOR Color, TEXSCALE TexScale, PATERN Patern, int Waitframe)
{
	float width = Texture_GetWidth(Texture_index);
	float height = Texture_GetHeight(Texture_index);

	Patern.AnimePatern = min((g_FrameCounter / Waitframe), Patern.MaxPatern);

	TEXCOORD AnimeTex = { TexScale.width * (Patern.AnimePatern % Patern.YMaxPatern),TexScale.height * (Patern.AnimePatern / Patern.YMaxPatern) };
	Draw_TextureClip(Texture_index, Position, Color, AnimeTex, TexScale);

	return Patern.AnimePatern >= Patern.MaxPatern;
}

bool Animetion_NoLoop(int Texture_index, D3DXVECTOR2 Position, SCALE Scale, D3DCOLOR Color, TEXSCALE TexScale, PATERN Patern, int Waitframe,int Createframe)
{
	float width = Texture_GetWidth(Texture_index);
	float height = Texture_GetHeight(Texture_index);

	int AnimePatern = min(((g_FrameCounter - Createframe)/ Waitframe), Patern.MaxPatern);

	TEXCOORD AnimeTex = { TexScale.width * (AnimePatern % Patern.YMaxPatern),TexScale.height * (AnimePatern / Patern.YMaxPatern) };
	
	Draw_Sprite(Texture_index,Position,Scale,Color,AnimeTex,TexScale);
	return AnimePatern >= Patern.MaxPatern;
}

//***********************************************
//	アニメーション LOOP
//***********************************************
void Animetion_Loop(int Texture_index, D3DXVECTOR2 Position, SCALE Scale,D3DCOLOR Color, TEXSCALE TexScale, int YMaxPatern, int MaxPatern, int Waitframe) 
{
	float width = Texture_GetWidth(Texture_index);
	float height = Texture_GetHeight(Texture_index);

	int AnimePatern = (g_FrameCounter / Waitframe) % MaxPatern;

	TEXCOORD AnimeTex = { TexScale.width * (AnimePatern % YMaxPatern),TexScale.height * (AnimePatern / YMaxPatern) };
	Draw_TextureClip(Texture_index, Position, Color, AnimeTex, TexScale);

}

void Animetion_Loop(int Texture_index, D3DXVECTOR2 Position,SCALE Scale,D3DCOLOR Color, TEXSCALE TexScale, PATERN Patern, int Waitframe) 
{
	float width = Texture_GetWidth(Texture_index);
	float height = Texture_GetHeight(Texture_index);

	Patern.AnimePatern = (g_FrameCounter / Waitframe) % Patern.MaxPatern;

	TEXCOORD AnimeTex = { TexScale.width * (Patern.AnimePatern % Patern.YMaxPatern),TexScale.height * (Patern.AnimePatern / Patern.YMaxPatern) };

	Draw_Sprite(Texture_index,Position,Scale,Color,AnimeTex,TexScale);
}

void Animetion_Loop(int Texture_index, D3DXVECTOR2 Position, SCALE Scale, D3DCOLOR Color, TEXSCALE TexScale, PATERN Patern, int Waitframe,int Createframe)
{
	float width = Texture_GetWidth(Texture_index);
	float height = Texture_GetHeight(Texture_index);

	int AnimePatern = ((g_FrameCounter - Createframe) / Waitframe) % Patern.MaxPatern;

	TEXCOORD AnimeTex = { TexScale.width * (AnimePatern % Patern.YMaxPatern),TexScale.height * (AnimePatern / Patern.YMaxPatern) };

	Draw_Sprite(Texture_index, Position, Scale, Color, AnimeTex, TexScale);
}

void Draw_LoopRotation(int Texture_index, D3DXVECTOR2 Position, SCALE Scale, D3DCOLOR Color, TEXSCALE TexScale, PATERN Patern, int Waitframe, int Createframe, float Rotation)
{
	float width = Texture_GetWidth(Texture_index);
	float height = Texture_GetHeight(Texture_index);

	Patern.AnimePatern = ((g_FrameCounter - Createframe) / Waitframe) % Patern.MaxPatern;

	TEXCOORD AnimeTex = { TexScale.width * (Patern.AnimePatern % Patern.YMaxPatern),TexScale.height * (Patern.AnimePatern / Patern.YMaxPatern) };

	Draw_Rotate(Texture_index, Position, Scale, Color, AnimeTex, TexScale, Rotation);
}

//***********************************************
//	描画：スコアアニメーション
//***********************************************
void Animetion_Score(int texture_index, D3DXVECTOR2 position, D3DCOLOR color, TEXSCALE TexScale, int YMaxPatern, int MaxPatern, int Score, bool bLeft, bool bZero, int digitNum)
{
	int digit = 0, MaxScore = 1;
	TEXCOORD AnimeTex = {};

	//桁取得
	for (digit = 0; digit < digitNum; digit++)
	{
		MaxScore *= 10;
	}

	//カウントオーバー
	if (Score >= MaxScore)
	{
		Score = MaxScore - 1;
	}

	//左詰め
	if (bLeft)
	{
		//桁数取得
		digit = 0;
		for (int score = Score; score > 0; digit++)
		{
			score *= 0.1f;
		}

		//左詰め
		position = { position.x + (TexScale.width * 0.5f) * digit,position.y };
		while (digit > 0)
		{
			int AnimePatern = Score % 10;
			AnimeTex = { TexScale.width * (AnimePatern % YMaxPatern), TexScale.height *(AnimePatern / YMaxPatern) };
			position = { position.x - (TexScale.width * 0.5f),position.y };
			Draw_TextureClip(texture_index, position, color, AnimeTex, TexScale);
			Score *= 0.1f;
			digit--;
		}
	}
	else
	{
		//位置決め
		position = { position.x + (TexScale.width - 15) * digit,position.y };

		//0埋め
		if (!bZero) 
		{
			digit = 0;
			for (int score = Score; score > 0; digit++)
			{
				score *= 0.1f;
			}
		}

		//右詰め
		while (digit > 0)
		{
			int AnimePatern = Score % 10;
			AnimeTex = { TexScale.width * (AnimePatern % YMaxPatern),TexScale.height *(AnimePatern / YMaxPatern) };
			position = { position.x - (TexScale.width - 15),position.y };
			Draw_TextureClip(texture_index, position, color, AnimeTex, TexScale);
			Score *= 0.1f;
			digit--;
		}
	}
}