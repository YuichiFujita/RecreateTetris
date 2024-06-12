//============================================================
//
//	�O���b�h�}�l�[�W���[�w�b�_�[ [gridManager.h]
//	Author�F���c�E��
//
//============================================================
//************************************************************
//	��d�C���N���[�h�h�~
//************************************************************
#ifndef _GRID_MANAGER_H_
#define _GRID_MANAGER_H_

//************************************************************
//	�C���N���[�h�t�@�C��
//************************************************************
#include "multiBlock.h"

//************************************************************
//	�O���錾
//************************************************************
class CObject3D;	// �I�u�W�F�N�g3D�N���X

//************************************************************
//	�萔�錾
//************************************************************
namespace grid
{
	const int WIDTH	 = 10;	// �O���b�h����
	const int HEIGHT = 22;	// �O���b�h�c��
}

//************************************************************
//	�N���X��`
//************************************************************
// �O���b�h�}�l�[�W���[�N���X
class CGridManager
{
public:
	// �R���X�g���N�^
	CGridManager();

	// �f�X�g���N�^
	~CGridManager();

	// �����o�֐�
	HRESULT Init(void);	// ������
	void Uninit(void);	// �I��
	void Update(const float fDeltaTime);	// �X�V
	bool IsBlock(const POSGRID2& rPos);		// �u���b�N����擾
	void SetColBlock(const POSGRID2& rCurPos, const CMultiBlock::EType type);		// �u���b�N�F���f

	// �ÓI�����o�֐�
	static CGridManager *Create(void);	// ����
	static void Release(CGridManager *&prGridManager);	// �j��

private:
	// �O���b�h�\����
	struct SGrid
	{
		CObject3D *pVisual;	// �����ڃ|���S��
		bool bBlock;		// �u���b�N�����邩
	};

	// �����o�ϐ�
	SGrid m_aGrid[grid::WIDTH][grid::HEIGHT];	// �O���b�h���
};

#endif	// _GRID_MANAGER_H_
