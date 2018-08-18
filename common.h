//
//	common.h
//		USER:HIROMASA IKEDA		DATE:2018/07/04
//====================================================
//�w�b�_�[�ɋL�����Ă�������
//	�萔
//	�֐��̃v���g�^�C�v�錾
//	�\���̂̐錾
//	enum
//	typedef
//	inline�֐�
//	�}�N����`
//----------------------------------------------------
#pragma once

#ifndef COMMON_H
#define COMMON_H

#include<windows.h>
#include<d3dx9.h>
#define INIGUID
#include<dinput.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<time.h>

//�\���̂�񋓌^�͂������
#include"ReadStruct.h"

#define FVF_VERTEX2D (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)
#define FVF_VERTEX2DTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

//	��ʐݒ�
//----------------------------------------------------
//��ʃT�C�Y
#define SCREEN_WIDTH (1024)
#define SCREEN_HEIGHT (576)

//�N���X��
#define CLASS_NAME		"GameWindow"

//��ʃ^�C�g��
#define WINDOW_CAPTION "�V���[�e�B���O�Q�[��"

//��ʃX�^�C��
#define WINDOW_STYLE	(WS_OVERLAPPEDWINDOW ^ (WS_MAXIMIZEBOX  | WS_THICKFRAME))

//��ʔw�i�F
#define BLACK (D3DCOLOR_RGBA(255, 255, 255, 255))

#define CLEAR_SCORE	(100)

#define GRAVITY			(0.98f)		//�d��

#define ENEMY_MAX		(100)
#define ENEMY_SPEED		(1.0f)
#define ENEMY_SCALE_WIDTH	(60)
#define ENEMY_SCALE_HEIGHT	(60)

#endif // !COMMON_H
