#include"InGameScene.h"

#include"DxLib.h"
#include"../Manager/SceneManager.h"
#include"../Manager/TextureManager.h"
#include"../Manager/SoundManager.h"

enum
{
	STEP_JINGLE,
	STEP_INPUT,
	STEP_CLEAR_JINGLE,
	STEP_END,
};



InGameScene::InGameScene()
	:pInputMng{ InputManager::GetInstance() }
	,stage{Stage()}
{
	// ステージデータ初期化
	/*
	g_SampleStageの中身を
	m_Stageへコピー（読み込み）する
	この時、配列中身がObjectType_Player だったら
	その時のx,yをm_PlayerX(Y)へ代入し、m_StageDataへは ObjectType_Groundを代入する
	*/



}


InGameScene::~InGameScene()
{




}

void InGameScene::Exec()
{
	switch (m_Step)
	{
	case STEP_JINGLE:step_StartJingle(); break;
	case STEP_INPUT:
		stage.Exec();
		step_Input();
		/*play_Input();
		play_Carry();*/
		break;
	case STEP_CLEAR_JINGLE:step_ClearJingle(); break;
	default:break;
	}


}

void InGameScene::Draw()
{


	stage.Draw();
	DrawString(20, 20, "InGameScene", GetColor(0, 0, 0));

}


bool InGameScene::IsEnd()const
{
	return (m_Step == STEP_END);
}

void InGameScene::step_StartJingle()
{
	//if (pInputMng->IsPush(KeyType_ENTER))
	//{
		m_Step = STEP_INPUT;
	//}
}

void InGameScene::step_ClearJingle()
{
	if (pInputMng->IsPush(KeyType_ENTER))
	{
		m_Step = STEP_END;
		SceneManager::GetInstance()->SetNextScene(SceneID_Result);
	}
}

void InGameScene::step_Input()
{
	if (stage.IsClear())
	{
		SoundManager* pSoundMng = SoundManager::GetInstance();
		pSoundMng->Sound("Src/Data/Sound/win.mp3");
		m_Step = STEP_CLEAR_JINGLE;
	}



}

/*

void InGameScene::play_Input()
{
	if (pInputMng->IsPush(KeyType_UP))
	{
		if (m_StageData[m_PlayerY - 1][m_PlayerX] == ObjectType_Wall|| m_StageData[m_PlayerY - 1][m_PlayerX] == ObjectType_Target|| m_StageData[m_PlayerY - 1][m_PlayerX] == ObjectType_SetCrate)
			return;
		else if (m_StageData[m_PlayerY - 2][m_PlayerX] == ObjectType_Wall && m_StageData[m_PlayerY - 1][m_PlayerX] == ObjectType_UnsetCrate)
			return;
		else if (m_StageData[m_PlayerY - 2][m_PlayerX] == ObjectType_UnsetCrate && m_StageData[m_PlayerY - 1][m_PlayerX] == ObjectType_UnsetCrate)
			return;
		else if (m_StageData[m_PlayerY - 2][m_PlayerX] == ObjectType_SetCrate && m_StageData[m_PlayerY - 1][m_PlayerX] == ObjectType_UnsetCrate)
			return;
		m_PlayerY--;
	}
	else if (pInputMng->IsPush(KeyType_DOWN))
	{
		if (m_StageData[m_PlayerY + 1][m_PlayerX] == ObjectType_Wall|| m_StageData[m_PlayerY + 1][m_PlayerX] == ObjectType_Target || m_StageData[m_PlayerY + 1][m_PlayerX] == ObjectType_SetCrate)
			return;
		else if (m_StageData[m_PlayerY + 2][m_PlayerX] == ObjectType_Wall && m_StageData[m_PlayerY + 1][m_PlayerX] == ObjectType_UnsetCrate)
			return;
		else if (m_StageData[m_PlayerY + 2][m_PlayerX] == ObjectType_UnsetCrate && m_StageData[m_PlayerY + 1][m_PlayerX] == ObjectType_UnsetCrate)
			return;
		m_PlayerY++;
	}
	else if (pInputMng->IsPush(KeyType_LEFT))
	{
		if (m_StageData[m_PlayerY][m_PlayerX - 1] == ObjectType_Wall|| m_StageData[m_PlayerY][m_PlayerX - 1] == ObjectType_Target || m_StageData[m_PlayerY][m_PlayerX - 1] == ObjectType_SetCrate)
			return;
		else if (m_StageData[m_PlayerY][m_PlayerX - 2] == ObjectType_Wall && m_StageData[m_PlayerY][m_PlayerX - 1] == ObjectType_UnsetCrate)
			return;
		else if (m_StageData[m_PlayerY][m_PlayerX - 2] == ObjectType_UnsetCrate && m_StageData[m_PlayerY][m_PlayerX - 1] == ObjectType_UnsetCrate)
			return;
		m_PlayerX--;
	}
	else if (pInputMng->IsPush(KeyType_RIGHT))
	{
		if (m_StageData[m_PlayerY][m_PlayerX + 1] == ObjectType_Wall|| m_StageData[m_PlayerY][m_PlayerX + 1] == ObjectType_Target || m_StageData[m_PlayerY][m_PlayerX + 1] == ObjectType_SetCrate)
			return;
		else if (m_StageData[m_PlayerY][m_PlayerX + 2] == ObjectType_Wall && m_StageData[m_PlayerY][m_PlayerX + 1] == ObjectType_UnsetCrate)
			return;
		else if (m_StageData[m_PlayerY][m_PlayerX + 2] == ObjectType_UnsetCrate && m_StageData[m_PlayerY][m_PlayerX + 1] == ObjectType_UnsetCrate)
			return;
		m_PlayerX++;
	}
}

void InGameScene::play_Carry()
{
	if (pInputMng->IsPush(KeyType_UP))
	{
		if (m_StageData[m_PlayerY][m_PlayerX] == ObjectType_UnsetCrate)
		{
			if(m_StageData[m_PlayerY - 1][m_PlayerX] == ObjectType_Target)
			{
				m_StageData[m_PlayerY - 1][m_PlayerX] = ObjectType_SetCrate;
				m_StageData[m_PlayerY][m_PlayerX] = ObjectType_Ground;
			}
			else {
				m_StageData[m_PlayerY - 1][m_PlayerX] = ObjectType_UnsetCrate;
				m_StageData[m_PlayerY][m_PlayerX] = ObjectType_Ground;
			}
		}
	}
	else if (pInputMng->IsPush(KeyType_DOWN))
	{
		if (m_StageData[m_PlayerY][m_PlayerX] == ObjectType_UnsetCrate)
		{
			m_StageData[m_PlayerY + 1][m_PlayerX] = ObjectType_UnsetCrate;
			m_StageData[m_PlayerY][m_PlayerX] = ObjectType_Ground;
		}
	}
	else if (pInputMng->IsPush(KeyType_LEFT))
	{
		if (m_StageData[m_PlayerY][m_PlayerX] == ObjectType_UnsetCrate)
		{
			m_StageData[m_PlayerY][m_PlayerX - 1] = ObjectType_UnsetCrate;
			m_StageData[m_PlayerY][m_PlayerX] = ObjectType_Ground;
		}
	}
	else if(pInputMng->IsPush(KeyType_RIGHT))
	{
		if (m_StageData[m_PlayerY][m_PlayerX] == ObjectType_UnsetCrate)
		{
			m_StageData[m_PlayerY][m_PlayerX + 1] = ObjectType_UnsetCrate;
			m_StageData[m_PlayerY][m_PlayerX] = ObjectType_Ground;
		}
	}
}

*/



