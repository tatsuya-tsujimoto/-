#include"InputManager.h"




InputManager::InputManager()
{


}

InputManager::~InputManager()
{


}

//�L�[���͍X�V
void InputManager::Update()
{
	for (int i = 0; i < KeyType_MAX; i++)
	{
		// ���݂̃L�[�̓��͏�Ԃ��擾
		const bool now = (CheckHitKey(KEY_ASSIGN[i]) == 1);


		// �O��̃L�[���Ɣ�r���Č��݂̏�Ԃ��X�V
		m_State[i].on = now;
		/*m_State[i].push = (now==true)&&(m_State[i].old==false);
		m_State[i].pull = (now==false)&&(m_State[i].old==true);*/
		m_State[i].push = now  & !m_State[i].old ;
		m_State[i].pull = !now & m_State[i].old;


		// ���݂̒l��old�֑��
		m_State[i].old = now;
	}

}

//�L�[�������ꂽ��
bool InputManager::IsPush(KeyType key)const
{
	if (key == KeyType_MAX) { return false; }
	return m_State[key].push;

}

//�L�[����������Ă��邩
bool InputManager::IsOn(KeyType key)const
{

	if (key == KeyType_MAX) { return false; }
	return m_State[key].on;

}

//�L�[�������ꂽ��
bool InputManager::IsPull(KeyType key)const
{

	if (key == KeyType_MAX) { return false; }
	return m_State[key].pull;


}























