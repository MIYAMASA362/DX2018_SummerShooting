//
//	Title.h
//		USER:HIROMASA IKEDA		DATE:2018/07/11
//===============================================
#pragma once

#ifndef TITLE_H
#define TITLE_H

#include<d3dx9.h>
#include"TransformClass.h"
#include"TextureClass.h"
#include"SpriteClass.h"

#define STAGE_NUM (5)
#define SELECT_WIDTH (500)
#define SELECT_FONT_WIDTH (10)

//===============================================
//	enum
//===============================================

//-------------------------------------
//	�Z���N�g
//-------------------------------------
enum SELECT_STAGE
{
	STAGE_01,
	STAGE_02,
	STAGE_03,
	STAGE_04,
	STAGE_05
};

//===============================================
//	Select Block �N���X
//===============================================
class SelectBlock
{
private:

public:
	Transform transform;
	Texture texture;
	Render render;
	SELECT_STAGE SelectStage;

	bool Select;

	void Click();	//�N���b�N��
	void Hover();	//�z�o�[��
	void Update();	//�X�V����
	bool IsInable();//�}�E�X���͈͓�

	SelectBlock();
};


void Title_Initialize();
void Title_Update();
void Title_Render();
void Title_Finalize();

#endif // !TITLE_H

