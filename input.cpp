//=============================================================================
//
// ���͏��� [input.cpp]
//
//=============================================================================
#include <Windows.h>
#define DIRECTINPUT_VERSION (0x0800)
#include <dinput.h>
#include"common.h"
#include"System.h"

//*****************************************************************************
// �}�N����`
//*****************************************************************************
#define	NUM_KEY_MAX			(256)	// �L�[�̍ő吔


//*****************************************************************************
// �v���g�^�C�v�錾
//*****************************************************************************
static bool initialize(HINSTANCE hInstance);


//*****************************************************************************
// �O���[�o���ϐ�
//*****************************************************************************
LPDIRECTINPUT8			g_pInput = NULL;					// DirectInput�I�u�W�F�N�g�ւ̃|�C���^

LPDIRECTINPUTDEVICE8	g_pDevKeyboard = NULL;				// ���̓f�o�C�X(�L�[�{�[�h)�ւ̃|�C���^
BYTE					g_aKeyState[NUM_KEY_MAX];			// �L�[�{�[�h�̓��͏�񃏁[�N
BYTE					g_aKeyStateTrigger[NUM_KEY_MAX];	// �L�[�{�[�h�̃g���K�[��񃏁[�N
BYTE					g_aKeyStateRelease[NUM_KEY_MAX];	// �L�[�{�[�h�̃����[�X��񃏁[�N

LPDIRECTINPUTDEVICE8	g_pDevMouse = NULL;					// ���̓f�o�C�X(�}�E�X)
DIMOUSESTATE2			g_MouseState2;

POINT					g_MousePos = {NULL};

//=============================================================================
// ���͏����̏�����
//=============================================================================
bool initialize(HINSTANCE hInstance)
{
	if(g_pInput == NULL) {

		// DirectInput�I�u�W�F�N�g�̍쐬
		if(FAILED(DirectInput8Create(hInstance, DIRECTINPUT_VERSION, IID_IDirectInput8, (void**)&g_pInput, NULL))) {

			return false;
		}
	}

	return true;
}

//=============================================================================
// �L�[�{�[�h�̏�����
//=============================================================================
bool Keyboard_Initialize()
{
	// ���͏����̏�����
	if (!initialize(*System_GethInstance())) {

		MessageBox(*System_GethWnd(), "DirectInput�I�u�W�F�N�g�����˂��I", "�x���I", MB_ICONWARNING);
		return false;
	}

	// �f�o�C�X�̍쐬
	if (FAILED(g_pInput->CreateDevice(GUID_SysKeyboard, &g_pDevKeyboard, NULL)))
	{
		MessageBox(*System_GethWnd(), "�L�[�{�[�h���˂��I", "�x���I", MB_ICONWARNING);
		return false;
	}

	// �f�[�^�t�H�[�}�b�g��ݒ�
	if (FAILED(g_pDevKeyboard->SetDataFormat(&c_dfDIKeyboard)))
	{
		MessageBox(*System_GethWnd(), "�L�[�{�[�h�̃f�[�^�t�H�[�}�b�g��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		return false;
	}

	// �������[�h��ݒ�i�t�H�A�O���E���h����r�����[�h�j
	if (FAILED(g_pDevKeyboard->SetCooperativeLevel(*System_GethWnd(), (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE))))
	{
		MessageBox(*System_GethWnd(), "�L�[�{�[�h�̋������[�h��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		return false;
	}

	// �L�[�{�[�h�ւ̃A�N�Z�X�����l��(���͐���J�n)
	g_pDevKeyboard->Acquire();

	//�}�E�X�f�o�C�X�擾
	if (FAILED(g_pInput->CreateDevice(GUID_SysMouse, &g_pDevMouse, NULL)))
	{
		MessageBox(*System_GethWnd(), "�}�E�X���˂��I", "�x���I", MB_ICONWARNING);
		return false;
	}

	//�}�E�X�̃f�[�^�t�H�[�}�b�g
	if (FAILED(g_pDevMouse->SetDataFormat(&c_dfDIMouse2)))
	{
		MessageBox(*System_GethWnd(), "�}�E�X�̃f�[�^�t�H�[�}�b�g��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		return false;
	}

	//�}�E�X�̋������[�h
	if (FAILED(g_pDevMouse->SetCooperativeLevel(*System_GethWnd(), (DISCL_FOREGROUND | DISCL_NONEXCLUSIVE)))) 
	{
		MessageBox(*System_GethWnd(), "�}�E�X�̋������[�h��ݒ�ł��܂���ł����B", "�x���I", MB_ICONWARNING);
		return false;
	}

	g_pDevMouse->Acquire();

	return true;
}

//=============================================================================
// �L�[�{�[�h�̍X�V����
//=============================================================================
void Keyboard_Update(void)
{
	GetCursorPos(&g_MousePos);
	ScreenToClient(*System_GethWnd(),&g_MousePos);

	BYTE aKeyState[NUM_KEY_MAX];

	// �f�o�C�X����f�[�^���擾
	if(SUCCEEDED(g_pDevKeyboard->GetDeviceState(sizeof(aKeyState), aKeyState)))
	{
		// aKeyState[DIK_SPACE] & 0x80

		for(int nCnKey = 0; nCnKey < NUM_KEY_MAX; nCnKey++)
		{
			// �L�[�g���K�[�E�����[�X���𐶐�
			g_aKeyStateTrigger[nCnKey] = (g_aKeyState[nCnKey] ^ aKeyState[nCnKey]) & aKeyState[nCnKey];
			g_aKeyStateRelease[nCnKey] = (g_aKeyState[nCnKey] ^ aKeyState[nCnKey]) & g_aKeyState[nCnKey];


			// �L�[�v���X����ۑ�
			g_aKeyState[nCnKey] = aKeyState[nCnKey];
		}
	}
	else
	{
		// �L�[�{�[�h�ւ̃A�N�Z�X�����擾
		g_pDevKeyboard->Acquire();
	}

	if(SUCCEEDED(g_pDevMouse->GetDeviceState(sizeof(DIMOUSESTATE2),&g_MouseState2)))
	{
	}
	else
	{
		g_pDevMouse->Acquire();
	}

}

//=============================================================================
// �L�[�{�[�h�̏I������
//=============================================================================
void Keyboard_Finalize(void)
{
	//�}�E�X�f�o�C�X�̊J��
	if(g_pDevMouse != NULL)
	{
		g_pDevMouse->Release();
		g_pDevMouse = NULL;
	}

	if (g_pDevKeyboard != NULL)
	{// ���̓f�o�C�X(�L�[�{�[�h)�̊J��
	 // �L�[�{�[�h�ւ̃A�N�Z�X�����J��(���͐���I��)
		g_pDevKeyboard->Unacquire();

		g_pDevKeyboard->Release();
		g_pDevKeyboard = NULL;
	}

	// ���͏����̏I������
	if (g_pInput != NULL) {

		// DirectInput�I�u�W�F�N�g�̊J��
		g_pInput->Release();
		g_pInput = NULL;
	}
}

//=============================================================================
// �L�[�{�[�h�̃v���X��Ԃ��擾
//=============================================================================
bool Keyboard_IsPress(int nKey)
{
	return (g_aKeyState[nKey] & 0x80) ? true : false;
}

//=============================================================================
// �L�[�{�[�h�̃g���K�[��Ԃ��擾
//=============================================================================
bool Keyboard_IsTrigger(int nKey)
{
	return (g_aKeyStateTrigger[nKey] & 0x80) ? true: false;
}

//=============================================================================
// �L�[�{�[�h�̃����|�X��Ԃ��擾
//=============================================================================
bool Keyboard_IsRelease(int nKey)
{
	return (g_aKeyStateRelease[nKey] & 0x80) ? true: false;
}

//=============================================================================
//
//=============================================================================
bool Mouse_IsLeftDown()
{
	return (g_MouseState2.rgbButtons[0] & 0x80) ? true : false;
}

bool Mouse_IsRightDown() 
{
	return (g_MouseState2.rgbButtons[1] & 0x80) ? true : false;
}

LONG Mouse_IsMouseX()
{
	return g_MousePos.x;
}

LONG Mouse_IsMouseY()
{
	return g_MousePos.y;
}
