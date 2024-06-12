//============================================================
//
//	�u���b�N�w�b�_�[ [block.h]
//	Author�F���c�E��
//
//============================================================
//************************************************************
//	��d�C���N���[�h�h�~
//************************************************************
#ifndef _BLOCK_H_
#define _BLOCK_H_

//************************************************************
//	�O���錾
//************************************************************
class CMultiBlock;	// �}���`�u���b�N�N���X

//************************************************************
//	�N���X��`
//************************************************************
// �u���b�N�N���X
class CBlock
{
public:
	// �R���X�g���N�^
	CBlock();

	// �f�X�g���N�^
	~CBlock();

	// �����o�֐�
	HRESULT Init(void);	// ������
	void Uninit(void);	// �I��
	void Update(const float fDeltaTime);	// �X�V

	void SetPosition(const POSGRID2& rPos)		{ m_pos = rPos; }		// �ʒu�ݒ�
	void SetOldPosition(const POSGRID2& rPos)	{ m_posOld = rPos; }	// �ߋ��ʒu�ݒ�
	void SetOffset(const POSGRID2& rOffset)		{ m_offset = rOffset; }	// �I�t�Z�b�g�ݒ�
	POSGRID2 GetPosition(void) const			{ return m_pos; }		// �ʒu�擾
	POSGRID2 GetOldPosition(void) const			{ return m_posOld; }	// �ߋ��ʒu�擾
	POSGRID2 GetOffset(void) const				{ return m_offset; }	// �I�t�Z�b�g�擾

	// �ÓI�����o�֐�
	static CBlock *Create(CMultiBlock* pParent);	// ����

private:
	// �����o�ϐ�
	CMultiBlock* m_pParent;	// ���g�̓����N���X
	POSGRID2 m_pos;			// ���݈ʒu
	POSGRID2 m_posOld;		// �ߋ��ʒu
	POSGRID2 m_offset;		// �I�t�Z�b�g�ʒu
};

#endif	// _BLOCK_H_
