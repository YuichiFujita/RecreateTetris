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
//	�C���N���[�h�t�@�C��
//************************************************************
#include "object.h"

//************************************************************
//	�N���X��`
//************************************************************
// �u���b�N�N���X
class CBlock : public CObject
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
	CBlock(const EType type);

	// �f�X�g���N�^
	~CBlock();

	// �I�[�o�[���C�h�֐�
	HRESULT Init(void) override;	// ������
	void Uninit(void) override;		// �I��
	void Update(const float fDeltaTime) override;	// �X�V
	void Draw(CShader *pShader = nullptr) override;	// �`��

	// �ÓI�����o�֐�
	static CBlock *Create(const EType type);	// ����

private:
	// �I�[�o�[���C�h�֐�
	void Release(void) override { CObject::Release(); }	// �j��

	// �����o�֐�
	void SwapBlock(const POSGRID2& rOldPos, const POSGRID2& rCurPos);	// �u���b�N����
	void SetColBlock(const POSGRID2& rPos, const EType type);			// �u���b�N�F���f

	// �����o�ϐ�
	const EType m_type;	// ���
	POSGRID2 m_pos;		// ���_�ʒu
	float m_fCurTime;	// ���݂̑ҋ@����
};

#endif	// _BLOCK_H_
