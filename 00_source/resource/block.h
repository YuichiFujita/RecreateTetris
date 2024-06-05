//============================================================
//
//	ブロックヘッダー [block.h]
//	Author：藤田勇一
//
//============================================================
//************************************************************
//	二重インクルード防止
//************************************************************
#ifndef _BLOCK_H_
#define _BLOCK_H_

//************************************************************
//	インクルードファイル
//************************************************************
#include "object.h"

//************************************************************
//	クラス定義
//************************************************************
// ブロッククラス
class CBlock : public CObject
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
	CBlock(const EType type);

	// デストラクタ
	~CBlock();

	// オーバーライド関数
	HRESULT Init(void) override;	// 初期化
	void Uninit(void) override;		// 終了
	void Update(const float fDeltaTime) override;	// 更新
	void Draw(CShader *pShader = nullptr) override;	// 描画

	// 静的メンバ関数
	static CBlock *Create(const EType type);	// 生成

private:
	// オーバーライド関数
	void Release(void) override { CObject::Release(); }	// 破棄

	// メンバ関数
	void SwapBlock(const POSGRID2& rOldPos, const POSGRID2& rCurPos);	// ブロック入替
	void SetColBlock(const POSGRID2& rPos, const EType type);			// ブロック色反映

	// メンバ変数
	const EType m_type;	// 種類
	POSGRID2 m_pos;		// 原点位置
	float m_fCurTime;	// 現在の待機時間
};

#endif	// _BLOCK_H_
