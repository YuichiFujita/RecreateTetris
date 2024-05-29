//============================================================
//
//	�Q�[���}�l�[�W���[���� [gameManager.cpp]
//	Author�F���c�E��
//
//============================================================
//************************************************************
//	�C���N���[�h�t�@�C��
//************************************************************
#include "gameManager.h"
#include "manager.h"
#include "fade.h"
#include "scene.h"
#include "sceneGame.h"
#include "cinemaScope.h"
#include "timerUI.h"
#include "retentionManager.h"
#include "gridManager.h"

//************************************************************
//	�萔�錾
//************************************************************
namespace
{
	const int GAMEEND_WAIT_FRAME = 180;	// ���U���g��ʂւ̑J�ڗ]�C�t���[��
}

//************************************************************
//	�ÓI�����o�ϐ��錾
//************************************************************
CGridManager *CGameManager::m_pGridManager = nullptr;	// �O���b�h�}�l�[�W���[

//************************************************************
//	�e�N���X [CGameManager] �̃����o�֐�
//************************************************************
//============================================================
//	�R���X�g���N�^
//============================================================
CGameManager::CGameManager() :
	m_state	(STATE_NONE)	// ���
{

}

//============================================================
//	�f�X�g���N�^
//============================================================
CGameManager::~CGameManager()
{

}

//============================================================
//	����������
//============================================================
HRESULT CGameManager::Init(void)
{
	// �����o�ϐ���������
	m_state = STATE_NORMAL;	// ���

	// �O���b�h�}�l�[�W���[�̐���
	m_pGridManager = CGridManager::Create();
	if (m_pGridManager == nullptr)
	{ // �����Ɏ��s�����ꍇ

		// ���s��Ԃ�
		assert(false);
		return E_FAIL;
	}

	// ������Ԃ�
	return S_OK;
}

//============================================================
//	�I������
//============================================================
void CGameManager::Uninit(void)
{
	// �O���b�h�}�l�[�W���[�̔j��
	SAFE_REF_RELEASE(m_pGridManager);
}

//============================================================
//	�X�V����
//============================================================
void CGameManager::Update(const float fDeltaTime)
{
	switch (m_state)
	{ // ��Ԃ��Ƃ̏���
	case STATE_NONE:
	case STATE_NORMAL:
		break;

	default:	// ��O����
		assert(false);
		break;
	}

	// �O���b�h�}�l�[�W���[�̍X�V
	assert(m_pGridManager != nullptr);
	m_pGridManager->Update(fDeltaTime);
}

//============================================================
//	��Ԑݒ菈��
//============================================================
void CGameManager::SetState(const EState state)
{
	// ��Ԃ�ݒ�
	m_state = state;
}

//============================================================
//	��Ԏ擾����
//============================================================
CGameManager::EState CGameManager::GetState(void) const
{
	// ��Ԃ�Ԃ�
	return m_state;
}

//============================================================
//	���U���g��ʑJ�ڏ���
//============================================================
void CGameManager::TransitionResult(const CRetentionManager::EWin win)
{
	// �t�F�[�h���̏ꍇ������
	if (GET_MANAGER->GetFade()->GetState() != CFade::FADE_NONE) { return; }

	// ���U���g����ۑ�
	GET_RETENTION->SetResult(win, 0.0f);

	// ���U���g��ʂɑJ��
	GET_MANAGER->SetFadeScene(CScene::MODE_RESULT, GAMEEND_WAIT_FRAME);
}

//============================================================
//	��������
//============================================================
CGameManager *CGameManager::Create(void)
{
	// �Q�[���}�l�[�W���[�̐���
	CGameManager *pGameManager = new CGameManager;
	if (pGameManager == nullptr)
	{ // �����Ɏ��s�����ꍇ

		return nullptr;
	}
	else
	{ // �����ɐ��������ꍇ

		// �Q�[���}�l�[�W���[�̏�����
		if (FAILED(pGameManager->Init()))
		{ // �������Ɏ��s�����ꍇ

			// �Q�[���}�l�[�W���[�̔j��
			SAFE_DELETE(pGameManager);
			return nullptr;
		}

		// �m�ۂ����A�h���X��Ԃ�
		return pGameManager;
	}
}

//============================================================
//	�j������
//============================================================
void CGameManager::Release(CGameManager *&prGameManager)
{
	// �Q�[���}�l�[�W���[�̏I��
	assert(prGameManager != nullptr);
	prGameManager->Uninit();

	// �������J��
	SAFE_DELETE(prGameManager);
}

//============================================================
//	�O���b�h�}�l�[�W���[�擾����
//============================================================
CGridManager *CGameManager::GetGridManager(void)
{
	// �C���X�^���X���g�p
	assert(m_pGridManager != nullptr);

	// �O���b�h�}�l�[�W���[�̃|�C���^��Ԃ�
	return m_pGridManager;
}
