//============================================================
//
//	ゲームマネージャー処理 [gameManager.cpp]
//	Author：藤田勇一
//
//============================================================
//************************************************************
//	インクルードファイル
//************************************************************
#include "gameManager.h"
#include "manager.h"
#include "fade.h"
#include "scene.h"
#include "sceneGame.h"
#include "cinemaScope.h"
#include "timerUI.h"
#include "retentionManager.h"
#include "gridManager.h"

//************************************************************
//	定数宣言
//************************************************************
namespace
{
	const int GAMEEND_WAIT_FRAME = 180;	// リザルト画面への遷移余韻フレーム
}

//************************************************************
//	静的メンバ変数宣言
//************************************************************
CGridManager *CGameManager::m_pGridManager = nullptr;	// グリッドマネージャー

//************************************************************
//	親クラス [CGameManager] のメンバ関数
//************************************************************
//============================================================
//	コンストラクタ
//============================================================
CGameManager::CGameManager() :
	m_state	(STATE_NONE)	// 状態
{

}

//============================================================
//	デストラクタ
//============================================================
CGameManager::~CGameManager()
{

}

//============================================================
//	初期化処理
//============================================================
HRESULT CGameManager::Init(void)
{
	// メンバ変数を初期化
	m_state = STATE_NORMAL;	// 状態

	// グリッドマネージャーの生成
	m_pGridManager = CGridManager::Create();
	if (m_pGridManager == nullptr)
	{ // 生成に失敗した場合

		// 失敗を返す
		assert(false);
		return E_FAIL;
	}

	// 成功を返す
	return S_OK;
}

//============================================================
//	終了処理
//============================================================
void CGameManager::Uninit(void)
{
	// グリッドマネージャーの破棄
	SAFE_REF_RELEASE(m_pGridManager);
}

//============================================================
//	更新処理
//============================================================
void CGameManager::Update(const float fDeltaTime)
{
	switch (m_state)
	{ // 状態ごとの処理
	case STATE_NONE:
	case STATE_NORMAL:
		break;

	default:	// 例外処理
		assert(false);
		break;
	}

	// グリッドマネージャーの更新
	assert(m_pGridManager != nullptr);
	m_pGridManager->Update(fDeltaTime);
}

//============================================================
//	状態設定処理
//============================================================
void CGameManager::SetState(const EState state)
{
	// 状態を設定
	m_state = state;
}

//============================================================
//	状態取得処理
//============================================================
CGameManager::EState CGameManager::GetState(void) const
{
	// 状態を返す
	return m_state;
}

//============================================================
//	リザルト画面遷移処理
//============================================================
void CGameManager::TransitionResult(const CRetentionManager::EWin win)
{
	// フェード中の場合抜ける
	if (GET_MANAGER->GetFade()->GetState() != CFade::FADE_NONE) { return; }

	// リザルト情報を保存
	GET_RETENTION->SetResult(win, 0.0f);

	// リザルト画面に遷移
	GET_MANAGER->SetFadeScene(CScene::MODE_RESULT, GAMEEND_WAIT_FRAME);
}

//============================================================
//	生成処理
//============================================================
CGameManager *CGameManager::Create(void)
{
	// ゲームマネージャーの生成
	CGameManager *pGameManager = new CGameManager;
	if (pGameManager == nullptr)
	{ // 生成に失敗した場合

		return nullptr;
	}
	else
	{ // 生成に成功した場合

		// ゲームマネージャーの初期化
		if (FAILED(pGameManager->Init()))
		{ // 初期化に失敗した場合

			// ゲームマネージャーの破棄
			SAFE_DELETE(pGameManager);
			return nullptr;
		}

		// 確保したアドレスを返す
		return pGameManager;
	}
}

//============================================================
//	破棄処理
//============================================================
void CGameManager::Release(CGameManager *&prGameManager)
{
	// ゲームマネージャーの終了
	assert(prGameManager != nullptr);
	prGameManager->Uninit();

	// メモリ開放
	SAFE_DELETE(prGameManager);
}

//============================================================
//	グリッドマネージャー取得処理
//============================================================
CGridManager *CGameManager::GetGridManager(void)
{
	// インスタンス未使用
	assert(m_pGridManager != nullptr);

	// グリッドマネージャーのポインタを返す
	return m_pGridManager;
}
