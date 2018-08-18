//
//	Sprite.cpp
//		USER:HIROMASA IKEDA		DATE:2018/06/20
//===============================================
#include"common.h"
#include"myDirect3d.h"
#include"Texture.h"
#include"Sprite.h"

//***********************************************
//	描画：ポリゴン
//***********************************************
void Draw_Porigon(D3DXVECTOR2 Position, SCALE Scale, D3DCOLOR Color)
{
	float width  = Scale.width  * 0.5f;
	float height = Scale.height * 0.5f;

	Porigon2D Porigon[4] = 
	{
		{ D3DXVECTOR4(Position.x - width,Position.y - height,1.0f,1.0f), Color },
		{ D3DXVECTOR4(Position.x + width,Position.y - height,1.0f,1.0f), Color },
		{ D3DXVECTOR4(Position.x - width,Position.y + height,1.0f,1.0f), Color },
		{ D3DXVECTOR4(Position.x + width,Position.y + height,1.0f,1.0f), Color }
	};

	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();
	pD3DDevice->SetFVF(FVF_VERTEX2D);
	pD3DDevice->SetTexture(0,NULL);
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, &Porigon, sizeof(Porigon[0]));

}

void Draw_Porigon(D3DXVECTOR2 *pPosition, SCALE *pScale, D3DCOLOR *pColor) 
{
	float width  = pScale->width  * 0.5f;
	float height = pScale->height * 0.5f;

	Porigon2D Porigon[4] = 
	{
		{ D3DXVECTOR4(pPosition->x - width,pPosition->y - height,1.0f,1.0f),*pColor },
		{ D3DXVECTOR4(pPosition->x + width,pPosition->y - height,1.0f,1.0f),*pColor },
		{ D3DXVECTOR4(pPosition->x - width,pPosition->y + height,1.0f,1.0f),*pColor },
		{ D3DXVECTOR4(pPosition->x + width,pPosition->y + height,1.0f,1.0f),*pColor }
	};
	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();
	pD3DDevice->SetFVF(FVF_VERTEX2D);
	pD3DDevice->SetTexture(0, NULL);
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, &Porigon, sizeof(Porigon[0]));
}

//***********************************************
//	画像サイズ描画
//***********************************************
void Draw_TextureSize(int Texture_index, D3DXVECTOR2 Position, D3DCOLOR Color) 
{
	float width  = Texture_GetWidth(Texture_index)	*0.5f;
	float height = Texture_GetHeight(Texture_index) *0.5f;

	Sprite2D Sprite[4] = 
	{
		{ D3DXVECTOR4(Position.x - width - 0.5f, Position.y - height - 0.5f, 1.0f,1.0f),Color,D3DXVECTOR2(0.0f,0.0f) },
		{ D3DXVECTOR4(Position.x + width - 0.5f, Position.y - height - 0.5f, 1.0f,1.0f),Color,D3DXVECTOR2(1.0f,0.0f) },
		{ D3DXVECTOR4(Position.x - width - 0.5f, Position.y + height - 0.5f, 1.0f,1.0f),Color,D3DXVECTOR2(0.0f,1.0f) },
		{ D3DXVECTOR4(Position.x + width - 0.5f, Position.y + height - 0.5f, 1.0f,1.0f),Color,D3DXVECTOR2(1.0f,1.0f) }
	};

	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();
	pD3DDevice->SetFVF(FVF_VERTEX2DTEX);
	pD3DDevice->SetTexture(0, Texture_GetTexture(Texture_index));
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, &Sprite, sizeof(Sprite[0]));

}

void Draw_TextureSize(int *pTexture_index, D3DXVECTOR2 *pPosition, D3DCOLOR *pColor) 
{
	float width = Texture_GetWidth(*pTexture_index)	*0.5f;
	float height = Texture_GetHeight(*pTexture_index) *0.5f;

	Sprite2D Sprite[4] =
	{
		{ D3DXVECTOR4(pPosition->x - width - 0.5f, pPosition->y - height - 0.5f, 1.0f,1.0f),*pColor,D3DXVECTOR2(0.0f,0.0f) },
		{ D3DXVECTOR4(pPosition->x + width - 0.5f, pPosition->y - height - 0.5f, 1.0f,1.0f),*pColor,D3DXVECTOR2(1.0f,0.0f) },
		{ D3DXVECTOR4(pPosition->x - width - 0.5f, pPosition->y + height - 0.5f, 1.0f,1.0f),*pColor,D3DXVECTOR2(0.0f,1.0f) },
		{ D3DXVECTOR4(pPosition->x + width - 0.5f, pPosition->y + height - 0.5f, 1.0f,1.0f),*pColor,D3DXVECTOR2(1.0f,1.0f) }
	};											   

	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();
	pD3DDevice->SetFVF(FVF_VERTEX2DTEX);
	pD3DDevice->SetTexture(0, Texture_GetTexture(*pTexture_index));
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, &Sprite, sizeof(Sprite[0]));

}

//***********************************************
//	ポリゴンサイズに描画
//***********************************************
void Draw_TextureFill(int Texture_index, D3DXVECTOR2 Position, SCALE Scale, D3DCOLOR Color) 
{
	float width  = Scale.width *0.5f;
	float height = Scale.height *0.5f;

	Sprite2D Sprite[4] =
	{
		{ D3DXVECTOR4(Position.x - width - 0.5f, Position.y - height - 0.5f, 1.0f,1.0f),Color,D3DXVECTOR2(0.0f,0.0f) },
		{ D3DXVECTOR4(Position.x + width - 0.5f, Position.y - height - 0.5f, 1.0f,1.0f),Color,D3DXVECTOR2(1.0f,0.0f) },
		{ D3DXVECTOR4(Position.x - width - 0.5f, Position.y + height - 0.5f, 1.0f,1.0f),Color,D3DXVECTOR2(0.0f,1.0f) },
		{ D3DXVECTOR4(Position.x + width - 0.5f, Position.y + height - 0.5f, 1.0f,1.0f),Color,D3DXVECTOR2(1.0f,1.0f) }
	};

	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();
	pD3DDevice->SetFVF(FVF_VERTEX2DTEX);
	pD3DDevice->SetTexture(0, Texture_GetTexture(Texture_index));
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, &Sprite, sizeof(Sprite[0]));

}

void Draw_TextureFill(int *pTexture_index, D3DXVECTOR2 *pPosition, SCALE *pScale, D3DCOLOR *pColor) 
{
	float width  = pScale->width	*0.5f;
	float height = pScale->height	*0.5f;

	Sprite2D Sprite[4] =
	{
		{ D3DXVECTOR4(pPosition->x - width - 0.5f, pPosition->y - height - 0.5f, 1.0f,1.0f),*pColor,D3DXVECTOR2(0.0f,0.0f) },
		{ D3DXVECTOR4(pPosition->x + width - 0.5f, pPosition->y - height - 0.5f, 1.0f,1.0f),*pColor,D3DXVECTOR2(1.0f,0.0f) },
		{ D3DXVECTOR4(pPosition->x - width - 0.5f, pPosition->y + height - 0.5f, 1.0f,1.0f),*pColor,D3DXVECTOR2(0.0f,1.0f) },
		{ D3DXVECTOR4(pPosition->x + width - 0.5f, pPosition->y + height - 0.5f, 1.0f,1.0f),*pColor,D3DXVECTOR2(1.0f,1.0f) }
	};

	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();
	pD3DDevice->SetFVF(FVF_VERTEX2DTEX);
	pD3DDevice->SetTexture(0, Texture_GetTexture(*pTexture_index));
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, &Sprite, sizeof(Sprite[0]));

}

//***********************************************
//	テクスチャの切り抜きサイズ
//***********************************************
void Draw_TextureClip(int Texture_index, D3DXVECTOR2 Position, D3DCOLOR Color, TEXCOORD TexCoord, TEXSCALE TexScale) 
{
	float width  = Texture_GetWidth(Texture_index);
	float height = Texture_GetHeight(Texture_index);

	float u0 = (float)TexCoord.x / width;
	float v0 = (float)TexCoord.y / height;
	float u1 = u0 + (float)TexScale.width / width;
	float v1 = v0 + (float)TexScale.height / height;

	width  = TexScale.width  * 0.5;
	height = TexScale.height * 0.5;

	Sprite2D Sprite[4] =
	{
		{ D3DXVECTOR4(Position.x - width - 0.5f, Position.y - height - 0.5f, 1.0f,1.0f), Color, D3DXVECTOR2(u0,v0) },
		{ D3DXVECTOR4(Position.x + width - 0.5f, Position.y - height - 0.5f, 1.0f,1.0f), Color, D3DXVECTOR2(u1,v0) },
		{ D3DXVECTOR4(Position.x - width - 0.5f, Position.y + height - 0.5f, 1.0f,1.0f), Color, D3DXVECTOR2(u0,v1) },
		{ D3DXVECTOR4(Position.x + width - 0.5f, Position.y + height - 0.5f, 1.0f,1.0f), Color, D3DXVECTOR2(u1,v1) }
	};

	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();
	pD3DDevice->SetFVF(FVF_VERTEX2DTEX);
	pD3DDevice->SetTexture(0, Texture_GetTexture(Texture_index));
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, &Sprite, sizeof(Sprite[0]));

}

void Draw_TextureClip(int *pTexture_index, D3DXVECTOR2 *pPosition, D3DCOLOR *pColor, TEXCOORD *pTexCoord, TEXSCALE *pTexScale) 
{
	float width  = Texture_GetWidth(*pTexture_index);
	float height = Texture_GetHeight(*pTexture_index);

	float u0 = (float)pTexCoord->x / width;
	float v0 = (float)pTexCoord->y / height;
	float u1 = u0 + (float)pTexScale->width / width;
	float v1 = v0 + (float)pTexScale->height / height;

	width  = pTexScale->width  * 0.5;
	height = pTexScale->height * 0.5;

	Sprite2D Sprite[4] =
	{
		{ D3DXVECTOR4(pPosition->x - width - 0.5f, pPosition->y - height - 0.5f, 1.0f,1.0f), *pColor, D3DXVECTOR2(u0,v0) },
		{ D3DXVECTOR4(pPosition->x + width - 0.5f, pPosition->y - height - 0.5f, 1.0f,1.0f), *pColor, D3DXVECTOR2(u1,v0) },
		{ D3DXVECTOR4(pPosition->x - width - 0.5f, pPosition->y + height - 0.5f, 1.0f,1.0f), *pColor, D3DXVECTOR2(u0,v1) },
		{ D3DXVECTOR4(pPosition->x + width - 0.5f, pPosition->y + height - 0.5f, 1.0f,1.0f), *pColor, D3DXVECTOR2(u1,v1) }
	};

	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();
	pD3DDevice->SetFVF(FVF_VERTEX2DTEX);
	pD3DDevice->SetTexture(0, Texture_GetTexture(*pTexture_index));
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, &Sprite, sizeof(Sprite[0]));

}

//***********************************************
//	スプライト描画
//***********************************************
void Draw_Sprite(int Texture_index, D3DXVECTOR2 Position, SCALE Scale, D3DCOLOR Color, TEXCOORD TexCoord, TEXSCALE TexScale)
{
	float width  = Texture_GetWidth(Texture_index);
	float height = Texture_GetHeight(Texture_index);

	float u0 = (float)TexCoord.x / width;
	float v0 = (float)TexCoord.y / height;
	float u1 = u0 + (float)TexScale.width / width;
	float v1 = v0 + (float)TexScale.height / height;

	width  = Scale.width  * 0.5;
	height = Scale.height * 0.5;

	Sprite2D Sprite[4] =
	{
		{ D3DXVECTOR4(Position.x - width - 0.5f, Position.y - height - 0.5f, 1.0f,1.0f), Color, D3DXVECTOR2(u0,v0) },
		{ D3DXVECTOR4(Position.x + width - 0.5f, Position.y - height - 0.5f, 1.0f,1.0f), Color, D3DXVECTOR2(u1,v0) },
		{ D3DXVECTOR4(Position.x - width - 0.5f, Position.y + height - 0.5f, 1.0f,1.0f), Color, D3DXVECTOR2(u0,v1) },
		{ D3DXVECTOR4(Position.x + width - 0.5f, Position.y + height - 0.5f, 1.0f,1.0f), Color, D3DXVECTOR2(u1,v1) }
	};

	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();
	pD3DDevice->SetFVF(FVF_VERTEX2DTEX);
	pD3DDevice->SetTexture(0, Texture_GetTexture(Texture_index));
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, &Sprite, sizeof(Sprite[0]));

}

void Draw_Sprite(int *pTexture_index, D3DXVECTOR2 *pPosition, SCALE *pScale, D3DCOLOR *pColor, TEXCOORD *pTexCoord, TEXSCALE *pTexScale) 
{
	float width = Texture_GetWidth(*pTexture_index);
	float height = Texture_GetHeight(*pTexture_index);

	float u0 = (float)pTexCoord->x / width;
	float v0 = (float)pTexCoord->y / height;
	float u1 = u0 + (float)pTexScale->width / width;
	float v1 = v0 + (float)pTexScale->height / height;

	width  = pScale->width  * 0.5;
	height = pScale->height * 0.5;

	Sprite2D Sprite[4] =
	{
		{ D3DXVECTOR4(pPosition->x - width - 0.5f, pPosition->y - height - 0.5f, 1.0f,1.0f), *pColor, D3DXVECTOR2(u0,v0) },
		{ D3DXVECTOR4(pPosition->x + width - 0.5f, pPosition->y - height - 0.5f, 1.0f,1.0f), *pColor, D3DXVECTOR2(u1,v0) },
		{ D3DXVECTOR4(pPosition->x - width - 0.5f, pPosition->y + height - 0.5f, 1.0f,1.0f), *pColor, D3DXVECTOR2(u0,v1) },
		{ D3DXVECTOR4(pPosition->x + width - 0.5f, pPosition->y + height - 0.5f, 1.0f,1.0f), *pColor, D3DXVECTOR2(u1,v1) }
	};

	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();
	pD3DDevice->SetFVF(FVF_VERTEX2DTEX);
	pD3DDevice->SetTexture(0, Texture_GetTexture(*pTexture_index));
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, &Sprite, sizeof(Sprite[0]));
	
}

//***********************************************
//	スプライト回転
//***********************************************
void Draw_Rotate(int Texture_index, D3DXVECTOR2 Position, SCALE Scale, D3DCOLOR Color, TEXCOORD TexCoord, TEXSCALE TexScale, float Rotation) 
{
	float width  = Scale.width  * 0.5;
	float height = Scale.height * 0.5;

	Rotation = Rotation * M_PI / 180.0f;

	float px[4] = { 0 };
	float py[4] = { 0 };

	px[0] = (-width)*cos(Rotation) - (-height)*sin(Rotation);
	py[0] = (-width)*sin(Rotation) + (-height)*cos(Rotation);

	px[1] = width*cos(Rotation) - (-height)*sin(Rotation);
	py[1] = width*sin(Rotation) + (-height)*cos(Rotation);

	px[2] = (-width) *cos(Rotation) - height*sin(Rotation);
	py[2] = (-width) *sin(Rotation) + height*cos(Rotation);

	px[3] = width*cos(Rotation) - height*sin(Rotation);
	py[3] = width*sin(Rotation) + height*cos(Rotation);

	width  = Texture_GetWidth(Texture_index);
	height = Texture_GetHeight(Texture_index);

	float u0 = TexCoord.x / width;
	float v0 = TexCoord.y / height;
	float u1 = u0 + TexScale.width / width;
	float v1 = v0 + TexScale.height / height;

	width  = Scale.width  * 0.5f;
	height = Scale.height * 0.5f;

	Sprite2D Sprite[4] =
	{
		{ D3DXVECTOR4(px[0] + Position.x + width - 0.5f, py[0] + Position.y + height - 0.5f,	1.0f,1.0f),	Color,	D3DXVECTOR2(u0,v0) },
		{ D3DXVECTOR4(px[1] + Position.x + width - 0.5f, py[1] + Position.y + height - 0.5f,	1.0f,1.0f),	Color,	D3DXVECTOR2(u1,v0) },
		{ D3DXVECTOR4(px[2] + Position.x + width - 0.5f, py[2] + Position.y + height - 0.5f,	1.0f,1.0f),	Color,	D3DXVECTOR2(u0,v1) },
		{ D3DXVECTOR4(px[3] + Position.x + width - 0.5f, py[3] + Position.y + height - 0.5f,	1.0f,1.0f),	Color,	D3DXVECTOR2(u1,v1) }
	};

	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();
	pD3DDevice->SetFVF(FVF_VERTEX2DTEX);
	pD3DDevice->SetTexture(0, Texture_GetTexture(Texture_index));
	pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLESTRIP, 2, &Sprite, sizeof(Sprite[0]));

}

/*
//***********************************************
//	描画：切り抜きテクスチャ
//***********************************************
void TexSprite_DrawClip(int texture_index,D3DXVECTOR2 position,Scale scale,D3DCOLOR color,TexCord texCord,TexSize texSize,int AnimePatern,int YMaxPatern)
{
texCord.x = texSize.width * (AnimePatern %  YMaxPatern);
texCord.y = texSize.height * (AnimePatern / YMaxPatern);

Texture_DrawClip(texture_index,position,color,texCord,texSize);
}

*/