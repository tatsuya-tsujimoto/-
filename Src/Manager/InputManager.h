#ifndef INPUT_MANAGER_H
#define INPUT_MANAGER_H

#include"../KeyDefinition.h"
#include"Singleton.h"

// ���͊Ǘ��N���X
class InputManager :public Singleton<InputManager>
{

private:
	// key�̏�Ԃ������\����
	struct KeyState
	{
		bool old;		// �O��`�F�b�N���̃t���O���
		bool push;		// �����ꂽ�u��
		bool on;		// ��������Ă���
		bool pull;		// �����ꂽ�u��

		KeyState()
			:old{false}
			,push{false}
			,on{false}
			,pull{false}
		{}
	};

public:
	InputManager();
	~InputManager();

	//�L�[���͍X�V
	void Update();
	//�L�[�������ꂽ��
	bool IsPush(KeyType key)const;
	//�L�[����������Ă��邩
	bool IsOn(KeyType key)const;
	//�L�[�������ꂽ��
	bool IsPull(KeyType key)const;

private:
	KeyState m_State[KeyType_MAX];
};









#endif