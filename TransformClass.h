//
//	Transform.h
//		USER:HIROMASA IKEDA		DATE:2018/07/04
//===============================================
#pragma once
#ifndef TRANSFORM_H
#define TRANSFORM_H

#include"common.h"

//***********************************************
//	Transform クラス
//***********************************************
/*
 オブジェクト基本情報
 public :
 -> Position
 -> Scale
 -> Color
*/
class Transform 
{
public :
	D3DXVECTOR2 Position;
	SCALE Scale;
	D3DCOLOR Color;
	float Rotation;

	Transform();
};

#endif
