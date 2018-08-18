//
//	System.cpp
//		USER:HIROMASA IKEDA		DATE:2018/07/11
//===============================================
#pragma once
#ifndef SYSTEM_CPP
#define SYSTEM_CPP

#include"common.h"

void System_Initialize(HINSTANCE *hInstance, HINSTANCE *hPrevInstance, LPSTR *lpCmdLine, int *nCmdShow);
HWND *System_GethWnd();
HINSTANCE *System_GethInstance();

#endif // !SYSTEM_CPP

