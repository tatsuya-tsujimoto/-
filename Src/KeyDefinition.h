#ifndef KEY_DEFINITION_H
#define KEY_DEFINITION_H

#include"DxLib.h"

// key�̎��
enum KeyType
{
	KeyType_UP,			//��
	KeyType_DOWN,		//��
	KeyType_LEFT,		//��
	KeyType_RIGHT,		//��
	KeyType_ENTER,		//����
	KeyType_RESET,		//���Z�b�g

	KeyType_MAX,		//key�̎�ނ̐�

};

const int KEY_ASSIGN[KeyType_MAX] =
{
	KEY_INPUT_UP,
	KEY_INPUT_DOWN,
	KEY_INPUT_LEFT,
	KEY_INPUT_RIGHT,
	KEY_INPUT_RETURN,
	KEY_INPUT_R,
};






#endif