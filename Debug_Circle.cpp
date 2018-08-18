//
//	Source.cpp
//		USER:HIROMASA IKEDA		DATE:2018/07/06
//===============================================
#include"common.h"
#include"myDirect3d.h"
#include"Debug_Circle.h"

#define CIRCLE_VERTEX_COUNT (8)		//頂点数
#define CIRCLE_DRAW_MAX		(200)	//円の最大描画数

typedef struct DebugVertex_tag
{
	D3DXVECTOR4 Position;
	D3DCOLOR	Color;

}DebugVertex;

#define FVF_DEBUG_VERTEX (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

static LPDIRECT3DVERTEXBUFFER9	g_pVertexBuffer = NULL;
static LPDIRECT3DINDEXBUFFER9	g_pIndexBuffer	= NULL;

static int g_CircleCounter	= 0;		//描画された円のカウント
static DebugVertex *g_pDebugVertex	= NULL;
static WORD *g_pDebugVertexIndex	= NULL;

void DebugPrimitive_Initialize()
{
	g_CircleCounter = 0;

	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	pDevice->CreateVertexBuffer(
		sizeof(DebugVertex) * CIRCLE_VERTEX_COUNT *CIRCLE_DRAW_MAX,	//データサイズ
		D3DUSAGE_WRITEONLY,	//頂点バッファへの書き込み専用
		FVF_DEBUG_VERTEX,	//FVF
		D3DPOOL_MANAGED,	
		&g_pVertexBuffer,
		NULL
	);

	pDevice->CreateIndexBuffer(
		sizeof(WORD) * CIRCLE_VERTEX_COUNT * 2 * CIRCLE_DRAW_MAX,
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&g_pIndexBuffer,
		NULL
	);
}

void DebugPrimitive_BatchBegin()
{
	g_CircleCounter = 0;
	g_pVertexBuffer->Lock(0, 0, (void**)&g_pDebugVertex, 0);
	g_pIndexBuffer->Lock(0, 0, (void**)&g_pDebugVertexIndex, 0);
}

void DebugPrimitive_BatchDrawCircle(float x, float y, float radius)
{
	//順
	int n = g_CircleCounter * CIRCLE_VERTEX_COUNT * 2;

	//角度差
	const float s = (D3DX_PI * 2) / CIRCLE_VERTEX_COUNT;

	//頂点追加
	for (int i = 0; i< CIRCLE_VERTEX_COUNT; i++)
	{
		g_pDebugVertex[n + i].Position.x = cos(i * s) * radius + x;
		g_pDebugVertex[n + i].Position.y = sin(i * s) * radius + y;
		g_pDebugVertex[n + i].Position.z = 1.0f;
		g_pDebugVertex[n + i].Position.w = 1.0f;
		g_pDebugVertex[n + i].Color = D3DCOLOR_RGBA(0, 255, 0, 255);
		g_pDebugVertexIndex[n * 2 + i * 2] = n + i;
		g_pDebugVertexIndex[n * 2 + i * 2 + 1] = n + (i + 1) % CIRCLE_VERTEX_COUNT;
	}
	g_CircleCounter++;
}

void DebugPrimitive_BatchRun()
{
	LPDIRECT3DDEVICE9 pDevice = MyDirect3D_GetDevice();
	g_pVertexBuffer->Unlock();
	g_pIndexBuffer->Unlock();

	pDevice->SetStreamSource(0, g_pVertexBuffer, 0, sizeof(DebugVertex));
	pDevice->SetIndices(g_pIndexBuffer);
	pDevice->SetFVF(FVF_DEBUG_VERTEX);
	pDevice->SetTexture(0, NULL);
	pDevice->DrawIndexedPrimitive(D3DPT_LINELIST, 0, 0, CIRCLE_VERTEX_COUNT * CIRCLE_DRAW_MAX, 0, g_CircleCounter * CIRCLE_VERTEX_COUNT);
}

void DebugPrimitive_Finalize()
{
	if (g_pIndexBuffer)
	{
		g_pIndexBuffer->Release();
		g_pIndexBuffer = NULL;
	}

	if (g_pVertexBuffer)
	{
		g_pVertexBuffer->Release();
		g_pVertexBuffer = NULL;
	}
}