//
//	Player.cpp
//		USER:HIROMASA IKEDA		DATE:2018/06/20
//===============================================
#include"common.h"
#include"Texture.h"
#include"GameObject.h"
#include"Block.h"
#include"input.h"
#include"Bullet.h"
#include"Player.h"

//-----------------------------------------------
//	�}�N����`
//-----------------------------------------------
#define PLAYER_SPEED	(1.0f)		//�v���C���[���x
#define JUMP_SPEED		(20.0f)		//�W�����v���x

//***********************************************
//	�R���X�g���N�^
//***********************************************
PLAYER::PLAYER()
{
	bJump = false;
	bJump2 = false;
	Burst = 0;

	transform.Position = { 100.0f, 100.0f };
	transform.Scale = { 50.0f, 50.0f };
	transform.Color = D3DCOLOR_RGBA(0, 0, 0, 255);
	
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

//***********************************************
//	�ړ�����
//***********************************************
void PLAYER::Update() 
{

	//�E
	if (Keyboard_IsPress(DIK_D)) physics.Force.x += 1;

	//��
	if (Keyboard_IsPress(DIK_A))  physics.Force.x -= 1;

	//��
	if (Keyboard_IsTrigger(DIK_W))
	{
		//��i�W�����v
		if (bJump)
		{
			physics.velocity.y = -(20 * GRAVITY);
			bJump = false;
		}
		else
		{
			//��i�W�����v
			if(bJump2)
			{
				physics.velocity.y = -(20 * GRAVITY);
				bJump2 = false;
			}
		}
	}

	//����
	if(Mouse_IsLeftDown() && Burst >= PLAYER_ROF)
	{
		Bullet_Create(transform.Position,PLAYER_BULLET);
		Burst = 0;
	}

	physics.Update(PLAYER_SPEED);
																																																	
	Box_Collision.Center = transform.Position;

	//�u���b�N
	if(physics.Collision_Hit(Block_Collision()) == TOP)
	{
		bJump = true;
		bJump2 = true;
	}

	//����
	transform.Position.x = max(transform.Position.x, 0.0f + transform.Scale.width  * 0.5f);
	transform.Position.x = min(transform.Position.x, SCREEN_WIDTH - transform.Scale.width  * 0.5f);
	transform.Position.y = max(transform.Position.y, 0.0f + transform.Scale.height * 0.5f);
	transform.Position.y = min(transform.Position.y, SCREEN_HEIGHT - transform.Scale.height * 0.5f);

	Burst++;
}

//-----------------------------------------------
//	�O���[�o���ϐ�
//-----------------------------------------------
static PLAYER *Player;

//***********************************************
//	����������
//***********************************************
void Player_Initialize() 
{
	Player = new PLAYER;
}

//***********************************************
//	�X�V����
//***********************************************
void Player_Update() 
{
	Player->Update();
}

//***********************************************
//	�`�揈��
//***********************************************
void Player_Render()
{
	Player->render.Draw(PORIGON_DRAW);
	//DebugPrimitive_BatchDrawCircle(Player->Circle_Collision.Center.x, Player->Circle_Collision.Center.y, Player->Circle_Collision.radius);

}

//***********************************************
//	�I������
//***********************************************
void Player_Finalaize() 
{
	delete Player;
}

//***********************************************
//	�ʒu
//***********************************************
D3DXVECTOR2 *Player_GetPosition()
{
	return &Player->transform.Position;
}
