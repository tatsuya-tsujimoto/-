#include"ResultScene.h"
#include"DxLib.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"


ResultScene::ResultScene()
{



}


ResultScene::~ResultScene()
{




}

void ResultScene::Exec()
{
	step_Input();

}

void ResultScene::Draw()
{


	DrawString(20, 20, "ResultScene", GetColor(0, 0, 0));
	DrawString(20, 60, "ƒNƒŠƒA", GetColor(0, 0, 0));
}


bool ResultScene::IsEnd()const
{
	// @@
	return (m_Step == 2);


}



void ResultScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPush(KeyType_ENTER))
	{
		m_Step++;
		SceneManager::GetInstance()->SetNextScene(SceneID_Title);
	}


}