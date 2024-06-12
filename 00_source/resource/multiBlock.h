#if 1
//============================================================
//
//	マルチブロックヘッダー [multiMultiBlock.h]
//	Author：藤田勇一
//
//============================================================
//************************************************************
//	二重インクルード防止
//************************************************************
#ifndef _MULTI_BLOCK_H_
#define _MULTI_BLOCK_H_

//************************************************************
//	インクルードファイル
//************************************************************
#include "object.h"

//************************************************************
//	前方宣言
//************************************************************
class CBlock;	// ブロッククラス

//************************************************************
//	クラス定義
//************************************************************
// マルチブロッククラス
class CMultiBlock : public CObject
{
public:
	// 種類列挙
	enum EType
	{
		TYPE_NONE = 0,	// ブロック無し
		TYPE_T,			// T型
		TYPE_MAX		// この列挙型の総数
	};

	// コンストラクタ
	CMultiBlock(const EType type);

	// デストラクタ
	~CMultiBlock();

	// オーバーライド関数
	HRESULT Init(void) override;	// 初期化
	void Uninit(void) override;		// 終了
	void Update(const float fDeltaTime) override;	// 更新
	void Draw(CShader *pShader = nullptr) override;	// 描画

	// 静的メンバ関数
	static CMultiBlock *Create(const EType type);	// 生成

private:
	// オーバーライド関数
	void Release(void) override { CObject::Release(); }	// 破棄

	// メンバ関数
	HRESULT CreateBlock(const EType type);	// ブロック生成
	bool IsMove(const POSGRID2& rPos);		// 移動が可能かの取得
	void SwapBlock(const POSGRID2& rOldPos, const POSGRID2& rCurPos);	// ブロック入替
	void SetColBlock(const POSGRID2& rPos, const EType type);			// ブロック色反映

	// メンバ変数
	std::vector<CBlock*> m_vecBlock;	// ブロック情報の動的配列
	const EType m_type;	// 種類
	POSGRID2 m_pos;		// 原点位置
	float m_fCurTime;	// 現在の待機時間
};

#endif	// _MULTI_BLOCK_H_
#endif
