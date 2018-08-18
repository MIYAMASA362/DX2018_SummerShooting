//
//	myDirect3d.h
//			USER:HIROMASA IKEDA		DATE:2018/05/30
//======================================================
#include"myDirect3d.h"
#include"common.h"
#include"System.h"
#include"myDirect3d.h"

#define TEXTURE_FILE "Texture/witch3.png"
//-----------------------------------------------
//	�O���[�o���ϐ�
//-----------------------------------------------
static LPDIRECT3D9			g_pd3d9 = NULL;				//�|�C���^
static LPDIRECT3DDEVICE9	g_pD3DDevice = NULL;		//�f�o�C�X��IDirect3Device9�C���^�[�t�F�C�X
static LPDIRECT3DTEXTURE9	g_pTexture = NULL;

//===============================================
//	Direct3D�̏�����
//===============================================
bool MyDirect3D_Initialize()
{
	g_pd3d9 = Direct3DCreate9(D3D_SDK_VERSION);

	if (g_pd3d9 == NULL) {
		return false;
	}

	D3DPRESENT_PARAMETERS	d3dpp = {};							//�f�o�C�X�̓����ݒ肷��\����
	d3dpp.BackBufferWidth = SCREEN_WIDTH;
	d3dpp.BackBufferHeight = SCREEN_HEIGHT;
	d3dpp.BackBufferCount = 1;									//�o�b�N�o�b�t�@�[�̖���
	d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;					//�g����J���[�̐ݒ�
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;					//�\�Ɨ��̉�ʐ؂�ւ����s�������̎d���ݒ�
	d3dpp.Windowed = TRUE;										//�E�B���h�E:TRUE	�t���X�N���[��:FALSE 
	d3dpp.EnableAutoDepthStencil = TRUE;						//�X�e���V���o�b�t�@�̗L��	FALSE�ɂ���ƕ\��ʂƗ���ʂ���������
	d3dpp.AutoDepthStencilFormat = D3DFMT_D16;					//�X�e���V���o�b�t�@�̃f�[�^��
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_DEFAULT;	//����������҂^�C�~���O

	HRESULT hr = g_pd3d9->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, *System_GethWnd(), D3DCREATE_HARDWARE_VERTEXPROCESSING, &d3dpp, &g_pD3DDevice);

	if (FAILED(hr)) {
		MessageBox(*System_GethWnd(), "�f�o�C�X�̎擾�Ɏ��s���܂����B", "�G���[", MB_OK);
		DestroyWindow(*System_GethWnd());
		return false;
	}

	//�`�揈��
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, TRUE);				//������������ON
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);	//�w�iDSET�̃u�����h�ݒ�
	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND,  D3DBLEND_SRCALPHA);

	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);	//�e�N�X�`���|���S�����ߏ���

	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MINFILTER, D3DTEXF_LINEAR);
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MIPFILTER, D3DTEXF_LINEAR);
	g_pD3DDevice->SetSamplerState(0, D3DSAMP_MAGFILTER, D3DTEXF_LINEAR);

	return true;
}

//==============================================
//	Dirext3D�̏I������
//==============================================
void MyDirect3D_Finalize(void) 
{
	if (g_pD3DDevice != NULL)
	{
		g_pD3DDevice->Release();
		g_pD3DDevice = NULL;
	}
	if (g_pd3d9 != NULL)
	{
		g_pd3d9->Release();
		g_pd3d9 = NULL;
	}
}

//===============================================
//	Direct3D�f�o�C�X�|�C���^�̎擾
//===============================================
LPDIRECT3DDEVICE9 MyDirect3D_GetDevice(void) 
{
	return g_pD3DDevice;
}
