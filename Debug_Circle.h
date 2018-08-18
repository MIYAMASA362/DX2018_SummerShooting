//
//	Debug_Circle.h
//		USER:HIROMASA IKEDA		DATE:2018/07/09
//===============================================
#pragma once
#ifndef DEBUG_CIRCLE_H
#define DEBUG_CIRCLE_H

#include"common.h"

void DebugPrimitive_Initialize();
void DebugPrimitive_Finalize();
void DebugPrimitive_BatchBegin();
void DebugPrimitive_BatchDrawCircle(float x, float y, float radius);
void DebugPrimitive_BatchRun();


#endif // !DEBUG_CIRCLE_H

