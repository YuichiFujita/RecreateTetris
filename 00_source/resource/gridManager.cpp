//============================================================
//
//	グリッドマネージャー処理 [gridManager.cpp]
//	Author：藤田勇一
//
//============================================================
//************************************************************
//	インクルードファイル
//************************************************************
#include "gridManager.h"
#include "object3D.h"

//************************************************************
//	定数宣言
//************************************************************
namespace
{
	D3DXCOLOR COL_TYPE[] =	// ブロックごとの色
	{
		XCOL_WHITE,	// ブロックなし
		XCOL_BLUE,	// T型
	};

	const D3DXVECTOR3 SIZE_GRID = D3DXVECTOR3(36.0f, 36.0f, 0.0f);	// グリッドの大きさ
}

//************************************************************
//	スタティックアサート
//************************************************************
static_assert(NUM_ARRAY(COL_TYPE) == CBlock::TYPE_MAX, "ERROR : Type Count Mismatch");

//************************************************************
//	親クラス [CGridManager] のメンバ関数
//************************************************************
//============================================================
//	コンストラクタ
//============================================================
CGridManager::CGridManager()
{
	// メンバ変数をクリア
	memset(&m_aGrid[0][0], 0, sizeof(m_aGrid));	// グリッド情報
}

//============================================================
//	デストラクタ
//============================================================
CGridManager::~CGridManager()
{

}

//============================================================
//	初期化処理
//============================================================
HRESULT CGridManager::Init(void)
{
	// メンバ変数を初期化
	memset(&m_aGrid[0][0], 0, sizeof(m_aGrid));	// グリッド情報

	for (int i = 0; i < grid::HEIGHT; i++)
	{
		for (int j = 0; j < grid::WIDTH; j++)
		{
			// ブロックがない状態にする
			m_aGrid[j][i].bBlock = false;

			// グリッドの位置を求める
			D3DXVECTOR3 pos = D3DXVECTOR3
			(
				0.0f - (SIZE_GRID.x * grid::WIDTH * 0.5f) + (SIZE_GRID.x * j),
				SIZE_GRID.y * 0.5f + SIZE_GRID.y * i,
				0.0f
			);

			// グリッドの生成
			m_aGrid[j][i].pVisual = CObject3D::Create
			( // 引数
				pos,				// 位置
				SIZE_GRID * 0.9f,	// 大きさ
				VEC3_ZERO,			// 向き
				COL_TYPE[0]			// 色
			);
			if (m_aGrid[j][i].pVisual == nullptr)
			{ // 生成に失敗した場合

				// 失敗を返す
				assert(false);
				return E_FAIL;
			}

			// ラベルの設定
			m_aGrid[j][i].pVisual->SetLabel(CObject::LABEL_BLOCK);	// 自動更新・破棄が行われるようになる
		}
	}

	// 成功を返す
	return S_OK;
}

//============================================================
//	終了処理
//============================================================
void CGridManager::Uninit(void)
{

}

//============================================================
//	更新処理
//============================================================
void CGridManager::Update(const float fDeltaTime)
{

}

//============================================================
//	ブロック色の反映処理
//============================================================
void CGridManager::SetColBlock(const POSGRID2& rCurPos, const CBlock::EType type)
{
	// 種類に合わせた色を設定
	m_aGrid[rCurPos.x][rCurPos.y].pVisual->SetColor(COL_TYPE[type]);

	// ブロックがある場合判定をONにする
	m_aGrid[rCurPos.x][rCurPos.y].bBlock = (type == CBlock::TYPE_NONE) ? false : true;
}

//============================================================
//	生成処理
//============================================================
CGridManager *CGridManager::Create(void)
{
	// グリッドマネージャーの生成
	CGridManager *pGridManager = new CGridManager;
	if (pGridManager == nullptr)
	{ // 生成に失敗した場合

		return nullptr;
	}
	else
	{ // 生成に成功した場合

		// グリッドマネージャーの初期化
		if (FAILED(pGridManager->Init()))
		{ // 初期化に失敗した場合

			// グリッドマネージャーの破棄
			SAFE_DELETE(pGridManager);
			return nullptr;
		}

		// 確保したアドレスを返す
		return pGridManager;
	}
}

//============================================================
//	破棄処理
//============================================================
void CGridManager::Release(CGridManager *&prGridManager)
{
	// グリッドマネージャーの終了
	assert(prGridManager != nullptr);
	prGridManager->Uninit();

	// メモリ開放
	SAFE_DELETE(prGridManager);
}
