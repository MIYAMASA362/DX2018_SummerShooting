//
//	Transform.cpp
//		USER:HIROMASA IKEDA		DATA:2018/07/13
//===============================================
#include"common.h"
#include"TransformClass.h"

Transform::Transform()
{
	Position = { 0,0 };
	Scale = { 0,0 };
	Color = D3DCOLOR_ARGB(255, 255, 255, 255);
	Rotation = 0.0f;
}
