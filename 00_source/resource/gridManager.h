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
//	�萔�錾
//************************************************************
namespace grid
{
	const int WIDTH	 = 10;	// �O���b�h����
	const int HEIGHT = 20;	// �O���b�h�c��
}

//************************************************************
//	�O���錾
//************************************************************
class CObject3D;	// �I�u�W�F�N�g3D�N���X

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

	// �ÓI�����o�֐�
	static CGridManager *Create(void);	// ����
	static void Release(CGridManager *&prGridManager);	// �j��

private:
	// �����o�ϐ�
	CObject3D *m_apGrid[grid::WIDTH][grid::HEIGHT];	// �O���b�h���
};

#endif	// _GRID_MANAGER_H_