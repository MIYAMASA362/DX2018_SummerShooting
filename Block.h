//
//	Block.h
//		USER:HIROMASA IKEDA		DATE:2018/07/13
//===============================================
#pragma once
#ifndef BLOCK_H
#define BLOCK_H

#include"common.h"
#include"SpriteClass.h"
#include"Collision.h"

class BLOCK :public Sprite 
{
public:
	Box Box_Collision;
};

void Block_Initialize();
void Block_Update();
void Block_Render();
Collision* Block_Collision();
Box* Block2_Box();
Box* Block_Box();

#endif


