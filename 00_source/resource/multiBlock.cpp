#if 1
//============================================================
//
//	�}���`�u���b�N���� [multiBlock.cpp]
//	Author�F���c�E��
//
//============================================================
//************************************************************
//	�C���N���[�h�t�@�C��
//************************************************************
#include "multiBlock.h"
#include "block.h"
#include "sceneGame.h"
#include "gameManager.h"
#include "gridManager.h"

//************************************************************
//	�萔�錾
//************************************************************
namespace
{
	const POSGRID2 OFFSET[] =
	{
		POSGRID2( 0, 1),
		POSGRID2( 0, 2),
		POSGRID2( 1, 1),
		POSGRID2(-1, 1),
	};
}

//************************************************************
//	�e�N���X [CMultiBlock] �̃����o�֐�
//************************************************************
//============================================================
//	�R���X�g���N�^
//============================================================
CMultiBlock::CMultiBlock(const EType type) : CObject(CObject::LABEL_BLOCK, CObject::DIM_2D, 0),
	m_type		(type),			// ���
	m_pos		(GRID2_ZERO),	// ���_�ʒu
	m_fCurTime	(0.0f)			// ���݂̑ҋ@����
{
	// �u���b�N���̓��I�z����N���A
	m_vecBlock.clear();
}

//============================================================
//	�f�X�g���N�^
//============================================================
CMultiBlock::~CMultiBlock()
{

}

//============================================================
//	����������
//============================================================
HRESULT CMultiBlock::Init(void)
{
	// �����o�ϐ���������
	m_pos = POSGRID2(4, 19);	// ���_�ʒu
	m_fCurTime = 0.0f;			// ���݂̑ҋ@����

	// �u���b�N���̓��I�z���������
	m_vecBlock.clear();

	// �u���b�N�̐���
	CreateBlock(m_type);

	// �u���b�N�F�̔��f
	SetColBlock(m_pos, m_type);

	// ������Ԃ�
	return S_OK;
}

//============================================================
//	�I������
//============================================================
void CMultiBlock::Uninit(void)
{
	for (auto& rBlock : m_vecBlock)
	{ // �u���b�N�̑������J��Ԃ�

		// �u���b�N�̏I��
		SAFE_UNINIT(rBlock);
	}

	// �u���b�N���̓��I�z����N���A
	m_vecBlock.clear();

	// �I�u�W�F�N�g��j��
	Release();
}

//============================================================
//	�X�V����
//============================================================
void CMultiBlock::Update(const float fDeltaTime)
{
	// �ҋ@���Ԃ����Z
	m_fCurTime += fDeltaTime;
	while (m_fCurTime >= 0.5f)
	{ // �ҋ@���I������ꍇ

		// ���݂̑ҋ@���Ԃ��猸�Z
		m_fCurTime -= 0.5f;

		// �O��̈ʒu��ۑ�
		POSGRID2 posOld = m_pos;

		// ���_�ʒu�ɏd�͂�^����
		m_pos.y--;

		// �u���b�N�����ւ�
		SwapBlock(posOld, m_pos);
	}
}

//============================================================
//	�`�揈��
//============================================================
void CMultiBlock::Draw(CShader * /*pShader*/)
{

}

//============================================================
//	��������
//============================================================
CMultiBlock *CMultiBlock::Create(const EType type)
{
	// �}���`�u���b�N�̐���
	CMultiBlock *pMultiBlock = new CMultiBlock(type);
	if (pMultiBlock == nullptr)
	{ // �����Ɏ��s�����ꍇ

		return nullptr;
	}
	else
	{ // �����ɐ��������ꍇ

		// �}���`�u���b�N�̏�����
		if (FAILED(pMultiBlock->Init()))
		{ // �������Ɏ��s�����ꍇ

			// �}���`�u���b�N�̔j��
			SAFE_DELETE(pMultiBlock);
			return nullptr;
		}

		// �m�ۂ����A�h���X��Ԃ�
		return pMultiBlock;
	}
}

//============================================================
//	�u���b�N�̐�������
//============================================================
HRESULT CMultiBlock::CreateBlock(const EType type)
{
	// TODO�F������T�~�m�Œ�
	for (int i = 0; i < 4; i++)
	{
		// �u���b�N�̐���
		CBlock *pBlock = CBlock::Create(this);
		if (pBlock == nullptr)
		{ // �����Ɏ��s�����ꍇ

			return E_FAIL;
		}

		// �u���b�N�����_�ʒu���炸�炷
		pBlock->SetPosition(m_pos + OFFSET[i]);

		// �u���b�N�ɃI�t�Z�b�g��ݒ�
		pBlock->SetOffset(OFFSET[i]);

		// �u���b�N���Ō���ɐݒ�
		m_vecBlock.push_back(pBlock);
	}

	return S_OK;
}

//============================================================
//	�ړ����\���̎擾����
//============================================================
bool CMultiBlock::IsMove(const POSGRID2& rPos)
{
	CGridManager *pGrid = CSceneGame::GetGameManager()->GetGridManager();	// �O���b�h���
	for (auto& rBlock : m_vecBlock)
	{ // �u���b�N�̑������J��Ԃ�

		// �u���b�N�F�̔��f
		if (pGrid->IsBlock(rPos + rBlock->GetOffset()))
		{ // �ړ���Ƀu���b�N���������ꍇ

			return false;
		}
	}

	return true;
}

//============================================================
//	�u���b�N�̓��֏���
//============================================================
void CMultiBlock::SwapBlock(const POSGRID2& rOldPos, const POSGRID2& rCurPos)
{
	// �O��ʒu�̃u���b�N�F�̔��f
	SetColBlock(rOldPos, TYPE_NONE);

	if (IsMove(rCurPos))
	{ // �ړ����ł���ꍇ

		// ���݈ʒu�̃u���b�N�F�̔��f
		SetColBlock(rCurPos, m_type);
	}
}

//============================================================
//	�u���b�N�F�̔��f����
//============================================================
void CMultiBlock::SetColBlock(const POSGRID2& rPos, const EType type)
{
	CGridManager *pGrid = CSceneGame::GetGameManager()->GetGridManager();	// �O���b�h���
	for (auto& rBlock : m_vecBlock)
	{ // �u���b�N�̑������J��Ԃ�

		// �u���b�N�F�̔��f
		pGrid->SetColBlock(rPos + rBlock->GetOffset(), type);
	}
}
#endif
