//
//	Texture.cpp
//		USER:HIROMASA IKEDA		DATE:2018/06/21
//===============================================
#include"common.h"
#include"myDirect3d.h"
#include"Texture.h"

//***********************************************
//	�O���[�o���ϐ�
//***********************************************
static const int TEXTURE_MAX = sizeof(TEXTURE_FILELIST) / sizeof(TEXTURE_FILELIST[0]);
static LPDIRECT3DTEXTURE9 g_pTextures[TEXTURE_MAX];

//***********************************************-
//	�e�N�X�`��������
//***********************************************
void Texture_Initialize(HWND *hWnd) 
{
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	HRESULT hr;
	char ErrorText[256] = {};
	int failded_Count = 0;

	for (int i = 0; i < TEXTURE_MAX; i++)
	{
		//�ǂݍ��݂����s�������ɂ�g_pTexture[i]��null���u�����
		hr = D3DXCreateTextureFromFile(pDevice, TEXTURE_FILELIST[i].FileName, &g_pTextures[i]);
		if (FAILED(hr))
		{
			strcat(ErrorText, TEXTURE_FILELIST[i].FileName);
			strcat(ErrorText, "\n");
			failded_Count++;
		}
	}

	if (failded_Count > 0)
	{
		MessageBox(*hWnd, ErrorText, "�ǂݍ��ݎ��s", MB_OK);
		DestroyWindow(*hWnd);
	}
}

//***********************************************
//	�I������
//***********************************************
void Texture_Finalize() 
{
	for (int i = 0; i < TEXTURE_MAX; i++)
	{
		if (g_pTextures[i] != NULL)
		{
			g_pTextures[i]->Release();
			g_pTextures[i] = NULL;
		}
	}
}

//***********************************************
//	�e�N�X�`���|�C���^�̎擾
//***********************************************
LPDIRECT3DTEXTURE9 Texture_GetTexture(int index) 
{
	return g_pTextures[index];
}

//***********************************************
//	�e�N�X�`�����̎擾
//***********************************************
int Texture_GetWidth(int index) 
{
	return TEXTURE_FILELIST[index].width;
}

//***********************************************
//	�e�N�X�`���c�̎擾
//***********************************************
int Texture_GetHeight(int index) 
{
	return TEXTURE_FILELIST[index].height;
}
