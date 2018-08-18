//
//	myDirect3d.h
//		USER:HIROMASA IKEDA		DATE:2018/05/30
//===============================================
#pragma once

#ifndef MYDIRECT3D_H
#define MYDIRECT3D_H

#include<windows.h>
#include<d3dx9.h>


bool MyDirect3D_Initialize();		//Direct3Dの初期化
void MyDirect3D_Finalize(void);		//Dirext3Dの終了処理
LPDIRECT3DDEVICE9 MyDirect3D_GetDevice(void);//Direct3Dデバイスポインタの取得


#endif