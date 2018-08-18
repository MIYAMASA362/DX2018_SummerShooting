//=============================================================================
//
// キーボード入力処理 [input.h]
//
//=============================================================================
#ifndef INPUT_H_
#define INPUT_H_

#include <Windows.h>
#define DIRECTINPUT_VERSION (0x0800)
#include <dinput.h>


bool Keyboard_Initialize();
void Keyboard_Finalize(void);
void Keyboard_Update(void);

// DIK_～
bool Keyboard_IsPress(int nKey);
bool Keyboard_IsTrigger(int nKey);
bool Keyboard_IsRelease(int nKey);

bool Mouse_IsLeftDown();
bool Mouse_IsRightDown();
LONG Mouse_IsMouseX();
LONG Mouse_IsMouseY();

#endif