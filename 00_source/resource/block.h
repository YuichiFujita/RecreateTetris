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
//	クラス定義
//************************************************************
// ブロッククラス
class CBlock : public CObject
{
public:
	// 種類列挙
	enum EType
	{
		TYPE_T = 0,	// T型
		TYPE_MAX	// この列挙型の総数
	};

	// コンストラクタ
	CBlock(const EType type);

	// デストラクタ
	~CBlock();

	// メンバ関数
	HRESULT Init(void);	// 初期化
	void Uninit(void);	// 終了
	void Update(const float fDeltaTime);	// 更新

	// 静的メンバ関数
	static CBlock *Create(const EType type);	// 生成

private:
	// メンバ関数
	void SwapBlock(const POSGRID2& rOldPos, const POSGRID2& rCurPos);	// TODO：BLOCK生成されてたらこっち側からブロックの反映をするよって処理作ろう

	// メンバ変数
	const EType m_type;	// 種類
	POSGRID2 m_pos;		// 原点位置
	float m_fCurTime;	// 現在の待機時間
};

#endif	// _BLOCK_H_
