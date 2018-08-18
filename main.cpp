//
//	Main.cpp
//		USER:HIROMASA IKEDA		DATE:2018/05/30
//================================================
#include"common.h"
#include"System.h"
#include"Debug_Circle.h"
#include"myDirect3d.h"
#include"Scene.h"
#include"input.h"
#include"Texture.h"
#include"Fade.h"

void Main_Initialize(void);		//�Q�[���̏������֐�
void Main_Update(void);		//�Q�[���̍X�V
void Main_Render(void);		//�Q�[���̕`��
void Main_Finalize(void);	//�Q�[���̏I��

//---------------------------------
//	Main
//---------------------------------
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	System_Initialize(&hInstance,&hPrevInstance,&lpCmdLine,&nCmdShow);
	Main_Initialize();
	DebugPrimitive_Initialize();

	MSG msg = {};
	//�Q�[���p���C�����[�v
	do 
	{
		//���b�Z�[�W���͂�������
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		else
		{
			//�Q�[���X�V
			Main_Update();

			//�Q�[���`��
			Main_Render();

			Scene_Check();
		}
	} while (msg.message != WM_QUIT);

	//�Q�[���̏I������
	Main_Finalize();

	return (int)msg.wParam;

}

//=============================================================
//	����������
//=============================================================
void Main_Initialize(void)
{
	if (!MyDirect3D_Initialize()) return;
	if (!Keyboard_Initialize())return;
	Texture_Initialize(System_GethWnd());

	Fade_Initialize();
	Scene_Initialize(SCENE_TITLE);

}

//=============================================================
//	�X�V����
//=============================================================
void Main_Update(void)
{
	Keyboard_Update();
	Scene_Update();
}

//=============================================================
//	�`�揈��
//=============================================================
void Main_Render(void)
{
	LPDIRECT3DDEVICE9 pD3DDevice = MyDirect3D_GetDevice();

	if (!pD3DDevice) return;

	//�f�o�C�X�ɑ΂��āA��ʂ̃N���A�����肢����
	pD3DDevice->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_RGBA(100, 80, 200, 255), 1.0f, 0);

	pD3DDevice->BeginScene();

	Scene_Render();

	pD3DDevice->EndScene();

	//�t���b�v����
	pD3DDevice->Present(NULL, NULL, NULL, NULL);
}

//=============================================================
//	�I������
//=============================================================
void Main_Finalize(void)
{
	Scene_Finalize();
	DebugPrimitive_Finalize();

	Texture_Finalize();
	Keyboard_Finalize();
	MyDirect3D_Finalize();
}