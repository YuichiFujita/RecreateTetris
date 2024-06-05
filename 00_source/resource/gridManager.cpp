//============================================================
//
//	�O���b�h�}�l�[�W���[���� [gridManager.cpp]
//	Author�F���c�E��
//
//============================================================
//************************************************************
//	�C���N���[�h�t�@�C��
//************************************************************
#include "gridManager.h"
#include "object3D.h"

//************************************************************
//	�萔�錾
//************************************************************
namespace
{
	D3DXCOLOR COL_TYPE[] =	// �u���b�N���Ƃ̐F
	{
		XCOL_WHITE,	// �u���b�N�Ȃ�
		XCOL_BLUE,	// T�^
	};

	const D3DXVECTOR3 SIZE_GRID = D3DXVECTOR3(36.0f, 36.0f, 0.0f);	// �O���b�h�̑傫��
}

//************************************************************
//	�X�^�e�B�b�N�A�T�[�g
//************************************************************
static_assert(NUM_ARRAY(COL_TYPE) == CBlock::TYPE_MAX, "ERROR : Type Count Mismatch");

//************************************************************
//	�e�N���X [CGridManager] �̃����o�֐�
//************************************************************
//============================================================
//	�R���X�g���N�^
//============================================================
CGridManager::CGridManager()
{
	// �����o�ϐ����N���A
	memset(&m_aGrid[0][0], 0, sizeof(m_aGrid));	// �O���b�h���
}

//============================================================
//	�f�X�g���N�^
//============================================================
CGridManager::~CGridManager()
{

}

//============================================================
//	����������
//============================================================
HRESULT CGridManager::Init(void)
{
	// �����o�ϐ���������
	memset(&m_aGrid[0][0], 0, sizeof(m_aGrid));	// �O���b�h���

	for (int i = 0; i < grid::HEIGHT; i++)
	{
		for (int j = 0; j < grid::WIDTH; j++)
		{
			// �u���b�N���Ȃ���Ԃɂ���
			m_aGrid[j][i].bBlock = false;

			// �O���b�h�̈ʒu�����߂�
			D3DXVECTOR3 pos = D3DXVECTOR3
			(
				0.0f - (SIZE_GRID.x * grid::WIDTH * 0.5f) + (SIZE_GRID.x * j),
				SIZE_GRID.y * 0.5f + SIZE_GRID.y * i,
				0.0f
			);

			// �O���b�h�̐���
			m_aGrid[j][i].pVisual = CObject3D::Create
			( // ����
				pos,				// �ʒu
				SIZE_GRID * 0.9f,	// �傫��
				VEC3_ZERO,			// ����
				COL_TYPE[0]			// �F
			);
			if (m_aGrid[j][i].pVisual == nullptr)
			{ // �����Ɏ��s�����ꍇ

				// ���s��Ԃ�
				assert(false);
				return E_FAIL;
			}

			// ���x���̐ݒ�
			m_aGrid[j][i].pVisual->SetLabel(CObject::LABEL_BLOCK);	// �����X�V�E�j�����s����悤�ɂȂ�
		}
	}

	// ������Ԃ�
	return S_OK;
}

//============================================================
//	�I������
//============================================================
void CGridManager::Uninit(void)
{

}

//============================================================
//	�X�V����
//============================================================
void CGridManager::Update(const float fDeltaTime)
{

}

//============================================================
//	�u���b�N�F�̔��f����
//============================================================
void CGridManager::SetColBlock(const POSGRID2& rCurPos, const CBlock::EType type)
{
	// ��ނɍ��킹���F��ݒ�
	m_aGrid[rCurPos.x][rCurPos.y].pVisual->SetColor(COL_TYPE[type]);

	// �u���b�N������ꍇ�����ON�ɂ���
	m_aGrid[rCurPos.x][rCurPos.y].bBlock = (type == CBlock::TYPE_NONE) ? false : true;
}

//============================================================
//	��������
//============================================================
CGridManager *CGridManager::Create(void)
{
	// �O���b�h�}�l�[�W���[�̐���
	CGridManager *pGridManager = new CGridManager;
	if (pGridManager == nullptr)
	{ // �����Ɏ��s�����ꍇ

		return nullptr;
	}
	else
	{ // �����ɐ��������ꍇ

		// �O���b�h�}�l�[�W���[�̏�����
		if (FAILED(pGridManager->Init()))
		{ // �������Ɏ��s�����ꍇ

			// �O���b�h�}�l�[�W���[�̔j��
			SAFE_DELETE(pGridManager);
			return nullptr;
		}

		// �m�ۂ����A�h���X��Ԃ�
		return pGridManager;
	}
}

//============================================================
//	�j������
//============================================================
void CGridManager::Release(CGridManager *&prGridManager)
{
	// �O���b�h�}�l�[�W���[�̏I��
	assert(prGridManager != nullptr);
	prGridManager->Uninit();

	// �������J��
	SAFE_DELETE(prGridManager);
}
