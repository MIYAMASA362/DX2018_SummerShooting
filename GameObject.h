//
//	GameObject.h
//		USER:HIROMASA IKEDA		DATE:2018/08/14
//===============================================
#pragma once
#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include<d3dx9.h>
#include"Texture.h"
#include"TextureClass.h"
#include"Collision.h"
#include"TransformClass.h"
#include"Block.h"

class GameObject
{
private:

public:
	Transform transform;
	Texture texture;		//�e�N�X�`��
	Render render;			//�`��
	Physics physics;		//�͊֌W
	Collision collision;
};


#endif // !GAMEOBJECT_H


