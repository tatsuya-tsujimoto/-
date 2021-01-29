#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include"../Definition.h"
#include"Singleton.h"

class SceneManager:public Singleton<SceneManager>
{
public:
	SceneManager();
	~SceneManager();

public:
	void Exec();
	void Draw();

	void SetNextScene(SceneID IDnext_);

	//// ���̃V�[����ݒ肷��֐���static�֐��ɂ��邱�Ƃ�
	//// ���̂��ǂ��ɂ����Ă�������Ԃ����
	//static void SetNextScene(SceneID IDnext_);		// ���̃V�[���ݒ�

private:
	class SceneBase* create_NextScene();		// ���̃V�[�����쐬

private:
	class SceneBase* m_pScene;
	static SceneID m_NextSceneID;
};

#if 0
	//----[[�V���O���g���f�U�C��(�N���X�ɒ��ڏ����Ă����ꍇ)]]----//
private:
	// �������g�̃|�C���^�ϐ�(�������g�̗B��̎���)
	static SceneManager* m_pInstance;			// *�͊O���Ȃ�

public:
	// ���̂����֐�
	static void CreateInstance()
	{
		// ���łɍ���Ă���Ȃ�V�������Ȃ����Ƃ�ۏ�
		if (m_pInstance == nullptr)
		{
			m_pInstance = new SceneManager();
		}
	}
	// ���̂�j������֐�
	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

	// ���̂��擾����֐�
	static SceneManager* GetInstance()
	{
		return m_pInstance;
	}

	// ���̂����݂��Ȃ����m�F����
	static bool IsNull()
	{
		return (m_pInstance == nullptr);
	}

};
// static �����o�ϐ���������
SceneManager* SceneManager::m_pInstance = nullptr;


#endif  //#if0

#endif