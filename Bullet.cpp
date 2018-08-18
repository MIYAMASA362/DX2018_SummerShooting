//
//	Bullet.cpp
//		USER:HIROMASA IKEDA		DATE:2018/08/16
//===============================================
#include<d3dx9.h>
#include"common.h"
#include"Texture.h"
#include"Bullet.h"
#include"input.h"
#include"Player.h"

//===============================================
//	Bullet クラス
//===============================================

//-------------------------------------
//	Bullet()
//-------------------------------------	
Bullet::Bullet()
{
	Use = false;

	transform.Color = D3DCOLOR_RGBA(255,255,0,255);
	transform.Scale = {10,10};

	texture.Texture_index = Player_Bullet;
	texture.TexCoord = {0,0};
	texture.TexScale = {64,64};

	render.pTransform = &transform;
	render.pTexture = &texture;

	Box_Collision.Center = transform.Position;
	Box_Collision.Scale = transform.Scale;

	collision.trigger = true;
	collision.BoxIndex.push_back(&Box_Collision);
}

//-------------------------------------
//	Update()
//-------------------------------------
void Bullet::Update()
{
	transform.Position += Speed;
	Box_Collision.Center = transform.Position;

	if (transform.Position.x < 0) Use = false;
	if (transform.Position.x > SCREEN_WIDTH) Use = false;
	if (transform.Position.y < 0) Use = false;
	if (transform.Position.y > SCREEN_HEIGHT) Use = false;
}

//===============================================
//	グローバル
//===============================================
static Bullet* pEBullet;
static Bullet* pPBullet;

//===============================================
//	Bullet_Initilaize()
//===============================================
void Bullet_Initialize()
{
	pPBullet = new Bullet[PLAYER_BULLET_MAX];
	pEBullet = new Bullet[ENEMY_BULLET_MAX];
}

//===============================================
//	Bullet_Update()
//===============================================
void Bullet_Update()
{
	for(int i = 0; i<ENEMY_BULLET_MAX; i++)
	{
		if(pEBullet[i].Use)
		{
			pEBullet[i].Update();
		}
	}

	for (int i = 0; i< PLAYER_BULLET_MAX; i++)
	{
		if (pPBullet[i].Use)
		{
			pPBullet[i].Update();
		}
	}
}

//===============================================
//	Bullet_Render()
//===============================================
void Bullet_Render()
{
	for(int i= 0; i< ENEMY_BULLET_MAX; i++)
	{
		if(pEBullet[i].Use)
		{
			pEBullet[i].render.Draw(PORIGON_DRAW);
		}
	}

	for(int i= 0; i< PLAYER_BULLET_MAX; i++)
	{
		if(pPBullet[i].Use)
		{
			pPBullet[i].render.Draw(PORIGON_DRAW);
		}
	}
}

//===============================================
//	Bullet_Create(D3DXVECTOR2 Position)
//===============================================
void Bullet_Create(D3DXVECTOR2 Position,BULLET_TYPE type)
{
	switch (type)
	{
	case PLAYER_BULLET:
		for(int i = 0; i<PLAYER_BULLET_MAX; i++)
		{
			if(pPBullet[i].Use == false)
			{
				pPBullet[i].Use = true;
				pPBullet[i].transform.Color = D3DCOLOR_RGBA(255,255,0,255);
				pPBullet[i].transform.Position = Position;
				pPBullet[i].Box_Collision.Center = Position;
				pPBullet[i].Speed.y = cos(atan2(Mouse_IsMouseX() - Position.x, Mouse_IsMouseY() - Position.y));
				pPBullet[i].Speed.x = sin(atan2(Mouse_IsMouseX() - Position.x, Mouse_IsMouseY() - Position.y));
				D3DXVec2Normalize(&pPBullet[i].Speed,&pPBullet[i].Speed);
				pPBullet[i].Speed *= PLAYER_BULLET_SPEED;
				return;
			}
		}

		break;
	case ENEMY_BULLET:
		for (int i = 0; i<ENEMY_BULLET_MAX; i++)
		{
			if (pEBullet[i].Use == false)
			{
				pEBullet[i].Use = true;
				pEBullet[i].transform.Color = D3DCOLOR_RGBA(255,155,155,255);
				pEBullet[i].transform.Position = Position;
				pEBullet[i].Box_Collision.Center = Position;
				D3DXVECTOR2 Target(Player_GetPosition()->x + ((rand() % 200) - 100) - Position.x, Player_GetPosition()->y + ((rand() % 200) - 100) - Position.y);
				pEBullet[i].Speed.y = cos(atan2(Target.x, Target.y));
				pEBullet[i].Speed.x = sin(atan2(Target.x, Target.y));
				D3DXVec2Normalize(&pEBullet[i].Speed, &pEBullet[i].Speed);
				pEBullet[i].Speed *= ENEMY_BULLET_SPEED;
				return;
			}
		}
		break;
	
	default:
		break;
	}
}

//===============================================
//	Bullet_Destroy(int index)
//===============================================
void Bullet_Destroy(BULLET_TYPE type,int index)
{
	switch (type)
	{
	case PLAYER_BULLET:
		pPBullet[index].Use = false;
		break;
	
	case ENEMY_BULLET:
		pEBullet[index].Use = false;
		break;

	default:
		break;
	}
}

//===============================================
//	Bullet_Finalize()
//===============================================
void Bullet_Finalize()
{
	delete[] pEBullet;
	delete[] pPBullet;
}

//===============================================
//	Bullet_GetCollision(BULLET_TYPE type, int index)
//===============================================
Collision* Bullet_GetCollision(BULLET_TYPE type,int index)
{
	switch (type)
	{
	case PLAYER_BULLET:
		return &pPBullet[index].collision;
		break;

	case ENEMY_BULLET:
		return &pEBullet[index].collision;
		break;
	
	default:
		break;
	}
}

//===============================================
//	Bullet_IsInable(BULLET_TYPE type, int index)
//===============================================
bool Bullet_IsInable(BULLET_TYPE type, int index)
{
	switch (type)
	{
	case PLAYER_BULLET:
		return pPBullet[index].Use;
		break;
	case ENEMY_BULLET:
		return pEBullet[index].Use;
		break;
	default:
		break;
	}
}
