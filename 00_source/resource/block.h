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
//	�N���X��`
//************************************************************
// �u���b�N�N���X
class CBlock : public CObject
{
public:
	// ��ޗ�
	enum EType
	{
		TYPE_T = 0,	// T�^
		TYPE_MAX	// ���̗񋓌^�̑���
	};

	// �R���X�g���N�^
	CBlock(const EType type);

	// �f�X�g���N�^
	~CBlock();

	// �����o�֐�
	HRESULT Init(void);	// ������
	void Uninit(void);	// �I��
	void Update(const float fDeltaTime);	// �X�V

	// �ÓI�����o�֐�
	static CBlock *Create(const EType type);	// ����

private:
	// �����o�֐�
	void SwapBlock(const POSGRID2& rOldPos, const POSGRID2& rCurPos);	// TODO�FBLOCK��������Ă��炱����������u���b�N�̔��f���������ď�����낤

	// �����o�ϐ�
	const EType m_type;	// ���
	POSGRID2 m_pos;		// ���_�ʒu
	float m_fCurTime;	// ���݂̑ҋ@����
};

#endif	// _BLOCK_H_
