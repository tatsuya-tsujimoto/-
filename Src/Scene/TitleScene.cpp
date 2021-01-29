#include"TitleScene.h"
#include"DxLib.h"
#include"../Manager/SceneManager.h"
#include"../Manager/InputManager.h"
enum
{
	STEP_LOGO_IN,
	STEP_INPUT,
	STEP_END,
};

TitleScene::TitleScene()
{



}


TitleScene::~TitleScene()
{




}

void TitleScene::Exec()
{
	switch (m_Step)
	{
	case STEP_LOGO_IN:step_LogoIn(); break;
	case STEP_INPUT:step_Input(); break;
	default:break;
	}


}

void TitleScene::Draw()
{
	DrawString(20, 20, "TitleScene", GetColor(0, 0, 0));
	DrawString(20, 40, "↑ ↓ ← → ：移動", GetColor(0, 0, 0));
	DrawString(20, 60, "Enter ：シーン切り替え", GetColor(0, 0, 0));
	DrawString(20, 80, "R ：リセット", GetColor(0, 0, 0));

}


bool TitleScene::IsEnd()const
{
	// @@
	return (m_Step==STEP_END);


}

void TitleScene::step_LogoIn()
{
	m_Step = STEP_INPUT;
}

void TitleScene::step_Input()
{
	InputManager* pInputMng = InputManager::GetInstance();
	if (pInputMng->IsPush(KeyType_ENTER))
	{
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene(SceneID_InGame);
	}


}