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
//	前方宣言
//************************************************************
class CMultiBlock;	// マルチブロッククラス

//************************************************************
//	クラス定義
//************************************************************
// ブロッククラス
class CBlock
{
public:
	// コンストラクタ
	CBlock();

	// デストラクタ
	~CBlock();

	// メンバ関数
	HRESULT Init(void);	// 初期化
	void Uninit(void);	// 終了
	void Update(const float fDeltaTime);	// 更新

	void SetPosition(const POSGRID2& rPos)		{ m_pos = rPos; }		// 位置設定
	void SetOldPosition(const POSGRID2& rPos)	{ m_posOld = rPos; }	// 過去位置設定
	void SetOffset(const POSGRID2& rOffset)		{ m_offset = rOffset; }	// オフセット設定
	POSGRID2 GetPosition(void) const			{ return m_pos; }		// 位置取得
	POSGRID2 GetOldPosition(void) const			{ return m_posOld; }	// 過去位置取得
	POSGRID2 GetOffset(void) const				{ return m_offset; }	// オフセット取得

	// 静的メンバ関数
	static CBlock *Create(CMultiBlock* pParent);	// 生成

private:
	// メンバ変数
	CMultiBlock* m_pParent;	// 自身の統括クラス
	POSGRID2 m_pos;			// 現在位置
	POSGRID2 m_posOld;		// 過去位置
	POSGRID2 m_offset;		// オフセット位置
};

#endif	// _BLOCK_H_
