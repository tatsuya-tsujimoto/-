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

	//// 次のシーンを設定する関数をstatic関数にすることで
	//// 実体がどこにあってもいい状態を作る
	//static void SetNextScene(SceneID IDnext_);		// 次のシーン設定

private:
	class SceneBase* create_NextScene();		// 次のシーンを作成

private:
	class SceneBase* m_pScene;
	static SceneID m_NextSceneID;
};

#if 0
	//----[[シングルトンデザイン(クラスに直接書いていく場合)]]----//
private:
	// 自分自身のポインタ変数(自分自身の唯一の実態)
	static SceneManager* m_pInstance;			// *は外さない

public:
	// 実体を作る関数
	static void CreateInstance()
	{
		// すでに作られているなら新しく作らないことを保証
		if (m_pInstance == nullptr)
		{
			m_pInstance = new SceneManager();
		}
	}
	// 実体を破棄する関数
	static void DestroyInstance()
	{
		delete m_pInstance;
		m_pInstance = nullptr;
	}

	// 実体を取得する関数
	static SceneManager* GetInstance()
	{
		return m_pInstance;
	}

	// 実体が存在しないか確認する
	static bool IsNull()
	{
		return (m_pInstance == nullptr);
	}

};
// static メンバ変数を初期化
SceneManager* SceneManager::m_pInstance = nullptr;


#endif  //#if0

#endif