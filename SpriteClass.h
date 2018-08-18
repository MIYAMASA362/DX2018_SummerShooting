//
//	SpriteClass.h
//		USER:HIROMASA IKEDA		DATE:2018/07/05
//===============================================
#pragma once
#ifndef SPRITECLASS_H
#define SPRITECLASS_H

#include"common.h"
#include"TransformClass.h"
#include"TextureClass.h"

//***********************************************
//	Sprite クラス
//***********************************************
/*
+継承：public Texture,public Transform
->Position		//位置
->Scale			//大きさ
->Color			//色
->Texture_index	//テクスチャ番号
->TexCoord		//テクスチャ
->TexScale		//テクスチャサイズ
->Rotation		//回転角度
+関数
->Draw(int type) //描画
->Rotate(int Rotation)	//回転させる
*/
class Sprite :virtual public Texture
{
public:
	Transform transform;	//基本情報
	float Rotation;		//角度

	Sprite();
	void Draw(int type);
};

//===============================================
//	Render クラス
//===============================================
class Render
{
private:

public:
	Transform* pTransform;
	Texture* pTexture;
	void Draw(DRAW_TYPE type);

	Render();
	Render(Transform* transform,Texture* texture);
};

#endif