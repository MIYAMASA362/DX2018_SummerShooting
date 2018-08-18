//
//	Enemy.cpp
//		USER:HIROMASA IKEDA		DATE:2018/08/16
//===============================================
#include<d3dx9.h>
#include"common.h"
#include"Texture.h"
#include"GameObject.h"
#include"Animetion.h"
#include"Enemy.h"
#include"Block.h"
#include"Bullet.h"

//===============================================
//	Enemy クラス
//===============================================

//-------------------------------------
//	Enemy()
//-------------------------------------
Enemy::Enemy()
{
	Use = false;

	transform.Position = { 100.0f, 100.0f };
	transform.Scale = { 50.0f, 50.0f };
	transform.Color = D3DCOLOR_RGBA(255, 0, 0, 255);

	texture.Texture_index = GumMan;
	texture.TexCoord = { 0,0 };
	texture.TexScale = { 180,222 };

	Box_Collision.Center = transform.Position;
	Box_Collision.Scale = transform.Scale;

	render.pTransform = &transform;
	render.pTexture = &texture;

	collision.BoxIndex.push_back(&Box_Collision);

	physics.pTransform = &transform;
	physics.pCollision = &collision;
}

//-------------------------------------
//	Update()
//-------------------------------------
void Enemy::Update()
{
	physics.Force.x -= 1.0f;

	physics.Update(ENEMY_SPEED);

	Box_Collision.Center = transform.Position;	//コリジョン更新

	physics.Collision_Hit(Block_Collision());	//あたり判定

	for(int i =0; i < PLAYER_BULLET_MAX; i++)
	{
		if(Bullet_IsInable(PLAYER_BULLET,i) == true)
		{
			if (physics.Collision_Hit(Bullet_GetCollision(PLAYER_BULLET, i)) != NONE)
			{
				Bullet_Destroy(PLAYER_BULLET, i);
				Use = false;
			}
		}
	}

	if(Animetion_GetFrame() % 15 == 0)
	{
		Bullet_Create(transform.Position,ENEMY_BULLET);
	}

}

//-------------------------------------
//	~Enemy();
//-------------------------------------
Enemy::~Enemy()
{
	
}

static Enemy* pEnemy;

//===============================================
//	Enemy_Initialize()
//===============================================
void Enemy_Initialize()
{
	pEnemy = new Enemy[ENEMY_MAX];
}

//===============================================
//	Enemy_Update()
//===============================================
void Enemy_Update()
{
	
	for(int i= 0; i< ENEMY_MAX; i++)
	{
		if(pEnemy[i].Use)
		{
			pEnemy[i].Update();

			if(pEnemy[i].transform.Position.x <= 0)
			{
				Enemy_Destroy(i);
			}
		}
	}

	if(Animetion_GetFrame() % 10 == 0)
	{
		Enemy_Create(D3DXVECTOR2(SCREEN_WIDTH, 0));
	}

}

//===============================================
//	Enemy_Render()
//===============================================
void Enemy_Render()
{
	
	for(int i=0; i< ENEMY_MAX; i++)
	{
		if(pEnemy[i].Use)
		{
			pEnemy[i].render.Draw(PORIGON_DRAW);
		}
	}
}

//===============================================
//	Enemy_Create(D3DXVECTOR Position)
//===============================================
void Enemy_Create(D3DXVECTOR2 Position)
{
	for(int i = 0; i < ENEMY_MAX; i++)
	{
		if(!pEnemy[i].Use)
		{
			pEnemy[i].Use = true;
			pEnemy[i].transform.Position = Position;
			return;
		}
	}
}

//===============================================
//	Enemy_Destroy(int index)
//===============================================
void Enemy_Destroy(int index)
{
	pEnemy[index].Use = false;
}

//===============================================
//	Enemy_Finalize()
//===============================================
void Enemy_Finalize()
{
	delete[] pEnemy;
}

