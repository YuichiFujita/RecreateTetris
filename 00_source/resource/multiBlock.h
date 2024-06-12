#if 1
//============================================================
//
//	�}���`�u���b�N�w�b�_�[ [multiMultiBlock.h]
//	Author�F���c�E��
//
//============================================================
//************************************************************
//	��d�C���N���[�h�h�~
//************************************************************
#ifndef _MULTI_BLOCK_H_
#define _MULTI_BLOCK_H_

//************************************************************
//	�C���N���[�h�t�@�C��
//************************************************************
#include "object.h"

//************************************************************
//	�O���錾
//************************************************************
class CBlock;	// �u���b�N�N���X

//************************************************************
//	�N���X��`
//************************************************************
// �}���`�u���b�N�N���X
class CMultiBlock : public CObject
{
public:
	// ��ޗ�
	enum EType
	{
		TYPE_NONE = 0,	// �u���b�N����
		TYPE_T,			// T�^
		TYPE_MAX		// ���̗񋓌^�̑���
	};

	// �R���X�g���N�^
	CMultiBlock(const EType type);

	// �f�X�g���N�^
	~CMultiBlock();

	// �I�[�o�[���C�h�֐�
	HRESULT Init(void) override;	// ������
	void Uninit(void) override;		// �I��
	void Update(const float fDeltaTime) override;	// �X�V
	void Draw(CShader *pShader = nullptr) override;	// �`��

	// �ÓI�����o�֐�
	static CMultiBlock *Create(const EType type);	// ����

private:
	// �I�[�o�[���C�h�֐�
	void Release(void) override { CObject::Release(); }	// �j��

	// �����o�֐�
	HRESULT CreateBlock(const EType type);	// �u���b�N����
	bool IsMove(const POSGRID2& rPos);		// �ړ����\���̎擾
	void SwapBlock(const POSGRID2& rOldPos, const POSGRID2& rCurPos);	// �u���b�N����
	void SetColBlock(const POSGRID2& rPos, const EType type);			// �u���b�N�F���f

	// �����o�ϐ�
	std::vector<CBlock*> m_vecBlock;	// �u���b�N���̓��I�z��
	const EType m_type;	// ���
	POSGRID2 m_pos;		// ���_�ʒu
	float m_fCurTime;	// ���݂̑ҋ@����
};

#endif	// _MULTI_BLOCK_H_
#endif
