//============================================================
//
//	グリッドマネージャーヘッダー [gridManager.h]
//	Author：藤田勇一
//
//============================================================
//************************************************************
//	二重インクルード防止
//************************************************************
#ifndef _GRID_MANAGER_H_
#define _GRID_MANAGER_H_

//************************************************************
//	インクルードファイル
//************************************************************
#include "multiBlock.h"

//************************************************************
//	前方宣言
//************************************************************
class CObject3D;	// オブジェクト3Dクラス

//************************************************************
//	定数宣言
//************************************************************
namespace grid
{
	const int WIDTH	 = 10;	// グリッド横幅
	const int HEIGHT = 22;	// グリッド縦幅
}

//************************************************************
//	クラス定義
//************************************************************
// グリッドマネージャークラス
class CGridManager
{
public:
	// コンストラクタ
	CGridManager();

	// デストラクタ
	~CGridManager();

	// メンバ関数
	HRESULT Init(void);	// 初期化
	void Uninit(void);	// 終了
	void Update(const float fDeltaTime);	// 更新
	bool IsBlock(const POSGRID2& rPos);		// ブロック判定取得
	void SetColBlock(const POSGRID2& rCurPos, const CMultiBlock::EType type);		// ブロック色反映

	// 静的メンバ関数
	static CGridManager *Create(void);	// 生成
	static void Release(CGridManager *&prGridManager);	// 破棄

private:
	// グリッド構造体
	struct SGrid
	{
		CObject3D *pVisual;	// 見た目ポリゴン
		bool bBlock;		// ブロックがあるか
	};

	// メンバ変数
	SGrid m_aGrid[grid::WIDTH][grid::HEIGHT];	// グリッド情報
};

#endif	// _GRID_MANAGER_H_
