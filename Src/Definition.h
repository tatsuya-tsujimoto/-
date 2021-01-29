#ifndef DEFINITION_H
#define DEFINITION_H


// �V�[��ID
enum SceneID
{
	SceneID_Title,
	SceneID_InGame,
	SceneID_Result,

	SceneID_Max,
	SceneID_Invalid,


};


// �q�ɔԗp�̒�`
//�X�e�[�W���
const int STAGE_WIDTH = 11;
const int STAGE_HEIGHT = 13;

//�}�b�v�`�b�v�̏c���T�C�Y
const int CHIP_WIDTH = 32;
const int CHIP_HEIGHT = 32;

//�I�u�W�F�N�g���
//	0	�n��
//	1	��
//	2	�v���C���[�̏����ʒu
//	3	�N���[�g�̔z�u�ʒu
//	4	���z�u�̃N���[�g
//	7	�z�u�ς݂̃N���[�g
//		�i�z�u�ꏊ�{���z�u�N���[�g���V�j
enum ObjectType
{
	ObjectType_Ground,
	ObjectType_Wall,
	ObjectType_Player,
	ObjectType_Target,
	ObjectType_UnsetCrate,
	ObjectType_SetCrate=7
};

enum DirType
{
	DirType_Up,			// ��
	DirType_Down,		// ��
	DirType_Left,		// ��
	DirType_Right,		// ��

	DirType_Max,		// �摜�ǂݍ��݂Ŏg�p����
};



#endif