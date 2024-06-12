#if 1
//============================================================
//
//	マルチブロック処理 [multiBlock.cpp]
//	Author：藤田勇一
//
//============================================================
//************************************************************
//	インクルードファイル
//************************************************************
#include "multiBlock.h"
#include "block.h"
#include "sceneGame.h"
#include "gameManager.h"
#include "gridManager.h"

//************************************************************
//	定数宣言
//************************************************************
namespace
{
	const POSGRID2 OFFSET[] =
	{
		POSGRID2( 0, 1),
		POSGRID2( 0, 2),
		POSGRID2( 1, 1),
		POSGRID2(-1, 1),
	};
}

//************************************************************
//	親クラス [CMultiBlock] のメンバ関数
//************************************************************
//============================================================
//	コンストラクタ
//============================================================
CMultiBlock::CMultiBlock(const EType type) : CObject(CObject::LABEL_BLOCK, CObject::DIM_2D, 0),
	m_type		(type),			// 種類
	m_pos		(GRID2_ZERO),	// 原点位置
	m_fCurTime	(0.0f)			// 現在の待機時間
{
	// ブロック情報の動的配列をクリア
	m_vecBlock.clear();
}

//============================================================
//	デストラクタ
//============================================================
CMultiBlock::~CMultiBlock()
{

}

//============================================================
//	初期化処理
//============================================================
HRESULT CMultiBlock::Init(void)
{
	// メンバ変数を初期化
	m_pos = POSGRID2(4, 19);	// 原点位置
	m_fCurTime = 0.0f;			// 現在の待機時間

	// ブロック情報の動的配列を初期化
	m_vecBlock.clear();

	// ブロックの生成
	CreateBlock(m_type);

	// ブロック色の反映
	SetColBlock(m_pos, m_type);

	// 成功を返す
	return S_OK;
}

//============================================================
//	終了処理
//============================================================
void CMultiBlock::Uninit(void)
{
	for (auto& rBlock : m_vecBlock)
	{ // ブロックの総数分繰り返す

		// ブロックの終了
		SAFE_UNINIT(rBlock);
	}

	// ブロック情報の動的配列をクリア
	m_vecBlock.clear();

	// オブジェクトを破棄
	Release();
}

//============================================================
//	更新処理
//============================================================
void CMultiBlock::Update(const float fDeltaTime)
{
	// 待機時間を加算
	m_fCurTime += fDeltaTime;
	while (m_fCurTime >= 0.5f)
	{ // 待機し終わった場合

		// 現在の待機時間から減算
		m_fCurTime -= 0.5f;

		// 前回の位置を保存
		POSGRID2 posOld = m_pos;

		// 原点位置に重力を与える
		m_pos.y--;

		// ブロックを入れ替え
		SwapBlock(posOld, m_pos);
	}
}

//============================================================
//	描画処理
//============================================================
void CMultiBlock::Draw(CShader * /*pShader*/)
{

}

//============================================================
//	生成処理
//============================================================
CMultiBlock *CMultiBlock::Create(const EType type)
{
	// マルチブロックの生成
	CMultiBlock *pMultiBlock = new CMultiBlock(type);
	if (pMultiBlock == nullptr)
	{ // 生成に失敗した場合

		return nullptr;
	}
	else
	{ // 生成に成功した場合

		// マルチブロックの初期化
		if (FAILED(pMultiBlock->Init()))
		{ // 初期化に失敗した場合

			// マルチブロックの破棄
			SAFE_DELETE(pMultiBlock);
			return nullptr;
		}

		// 確保したアドレスを返す
		return pMultiBlock;
	}
}

//============================================================
//	ブロックの生成処理
//============================================================
HRESULT CMultiBlock::CreateBlock(const EType type)
{
	// TODO：今だけTミノ固定
	for (int i = 0; i < 4; i++)
	{
		// ブロックの生成
		CBlock *pBlock = CBlock::Create(this);
		if (pBlock == nullptr)
		{ // 生成に失敗した場合

			return E_FAIL;
		}

		// ブロックを原点位置からずらす
		pBlock->SetPosition(m_pos + OFFSET[i]);

		// ブロックにオフセットを設定
		pBlock->SetOffset(OFFSET[i]);

		// ブロックを最後尾に設定
		m_vecBlock.push_back(pBlock);
	}

	return S_OK;
}

//============================================================
//	移動が可能かの取得処理
//============================================================
bool CMultiBlock::IsMove(const POSGRID2& rPos)
{
	CGridManager *pGrid = CSceneGame::GetGameManager()->GetGridManager();	// グリッド情報
	for (auto& rBlock : m_vecBlock)
	{ // ブロックの総数分繰り返す

		// ブロック色の反映
		if (pGrid->IsBlock(rPos + rBlock->GetOffset()))
		{ // 移動先にブロックがあった場合

			return false;
		}
	}

	return true;
}

//============================================================
//	ブロックの入替処理
//============================================================
void CMultiBlock::SwapBlock(const POSGRID2& rOldPos, const POSGRID2& rCurPos)
{
	// 前回位置のブロック色の反映
	SetColBlock(rOldPos, TYPE_NONE);

	if (IsMove(rCurPos))
	{ // 移動ができる場合

		// 現在位置のブロック色の反映
		SetColBlock(rCurPos, m_type);
	}
}

//============================================================
//	ブロック色の反映処理
//============================================================
void CMultiBlock::SetColBlock(const POSGRID2& rPos, const EType type)
{
	CGridManager *pGrid = CSceneGame::GetGameManager()->GetGridManager();	// グリッド情報
	for (auto& rBlock : m_vecBlock)
	{ // ブロックの総数分繰り返す

		// ブロック色の反映
		pGrid->SetColBlock(rPos + rBlock->GetOffset(), type);
	}
}
#endif
