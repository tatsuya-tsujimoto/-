#include"Stage.h"
#include"Manager/TextureManager.h"
#include"Manager/InputManager.h"
#include"Manager/SoundManager.h"

const int g_SanmpleStage[STAGE_HEIGHT][STAGE_WIDTH] =
{
	0,0,0,1,1,1,1,1,0,0,0,
	0,0,0,1,3,3,3,1,0,0,0,
	0,0,0,1,0,0,0,1,0,0,0,
	0,0,0,1,0,0,0,1,0,0,0,
	1,1,1,1,1,0,1,1,1,1,1,
	1,0,0,4,0,0,1,0,0,0,1,
	1,0,1,0,0,4,0,4,0,0,1,
	1,0,0,0,1,1,1,0,0,0,1,
	1,1,1,0,1,0,1,0,1,1,1,
	0,0,1,0,1,0,1,0,1,0,0,
	0,0,1,0,0,0,0,0,1,0,0,
	0,0,1,0,0,2,0,0,1,0,0,
	0,0,1,1,1,0,1,1,1,0,0,
};

Stage::Stage()
	:m_PlayerX{0}
	,m_PlayerY{0}
{
	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		for (int j = 0; j < STAGE_WIDTH; j++)
		{
			m_StageData[i][j] = g_SanmpleStage[i][j];
			if (g_SanmpleStage[i][j] == ObjectType_Player)
			{
				m_PlayerX = j;
				m_PlayerY = i;
				m_StageData[i][j] = ObjectType_Ground;
			}
		}
	}
	SoundManager* pSoundMng = SoundManager::GetInstance();
	pSoundMng->Sound("BGM");
}

Stage::~Stage()
{
	SoundManager* pSoundMng = SoundManager::GetInstance();
	pSoundMng->StopMP3();

}


void Stage::Exec()
{
	Move_Input();

}


void Stage::Draw()
{

	TextureManager* pTextureMng = TextureManager::GetInstance();
	DrawGraph(m_PlayerX * CHIP_WIDTH, m_PlayerY * CHIP_HEIGHT, pTextureMng->PassHandle(ObjectType::ObjectType_Player), true);

	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		for (int j = 0; j < STAGE_WIDTH; j++)
		{
			switch (m_StageData[i][j])
			{
			case ObjectType_Ground:break;
			case ObjectType_Wall:
				DrawGraph(j * CHIP_WIDTH, i * CHIP_HEIGHT, pTextureMng->PassHandle(ObjectType::ObjectType_Wall), true);
				break;
			case ObjectType_Target:
				DrawGraph(j * CHIP_WIDTH, i * CHIP_HEIGHT, pTextureMng->PassHandle(ObjectType::ObjectType_Target), true);
				break;
			case ObjectType_UnsetCrate:
				DrawGraph(j * CHIP_WIDTH, i * CHIP_HEIGHT, pTextureMng->PassHandle(ObjectType::ObjectType_UnsetCrate), true);
				break;
			case ObjectType_SetCrate:
				DrawGraph(j * CHIP_WIDTH, i * CHIP_HEIGHT, pTextureMng->PassHandle(ObjectType::ObjectType_SetCrate), true);
				break;
			}
		}
	}

	if (IsClear())
	{
		DrawGraph(100, 100, pTextureMng->PassHandle("Src/Data/Clear.png"), true);
	}
}



bool Stage::IsClear() const
{

	for (int y = 0; y < 13; y++)
	{
		for (int x = 0; x < 11; x++)
		{
			if (m_StageData[y][x] == ObjectType_UnsetCrate)
				return false;
		}
	}


	return true;


}

void Stage::Reset()
{
	for (int i = 0; i < STAGE_HEIGHT; i++)
	{
		for (int j = 0; j < STAGE_WIDTH; j++)
		{
			m_StageData[i][j] = g_SanmpleStage[i][j];
			if (g_SanmpleStage[i][j] == ObjectType_Player)
			{
				m_PlayerX = j;
				m_PlayerY = i;
				m_StageData[i][j] = ObjectType_Ground;
			}
		}
	}


}



void Stage::Move(DirType dir_)
{
	SoundManager* pSoundMng = SoundManager::GetInstance();
	if (dir_ < DirType_Up && dir_ >= DirType_Max)
	{
		return;
	}
	int next_x = m_PlayerX;
	int next_y = m_PlayerY;
	int next_x2 = m_PlayerX;
	int next_y2 = m_PlayerY;

	switch (dir_)
	{
	case DirType_Up:
		next_y -= 1;
		next_y2 -= 2;
		break;
	case DirType_Down:
		next_y += 1;
		next_y2 += 2;
		break;
	case DirType_Left:
		next_x -= 1;
		next_x2 -= 2;
		break;
	case DirType_Right:
		next_x += 1;
		next_x2 += 2;
		break;


	}
	// ここに到達した時、next_x(y),next_x(y)2には
	// 上下左右それぞれの移動先が入っているが
	// 処理的には同じ変数名を使うことが出来る

	// 移動先が画面外なら関数を抜ける
	if (next_x<0 ||
		next_y<0 ||
		next_x>(STAGE_WIDTH - 1) ||
		next_y>(STAGE_HEIGHT - 1))
	{
		return;
	}

	// 通常移動
	// 移動先がプレイヤーの乗れるマップチップだったらm_PlayerX(Y)をnext_x(y)で上書き
	if (m_StageData[next_y][next_x] == ObjectType_Ground ||
		m_StageData[next_y][next_x] == ObjectType_Target)
	{
		m_PlayerX = next_x;
		m_PlayerY = next_y;
		pSoundMng->Sound("Src/Data/Sound/walk.mp3");
	}

	// 移動先にクレートがある場合
	else if (m_StageData[next_y][next_x] == ObjectType_UnsetCrate)
	{
		// 2つ先が画面外かチェック
		if (next_x2<0 ||
			next_y2<0 ||
			next_x2>(STAGE_WIDTH - 1) ||
			next_y2>(STAGE_HEIGHT - 1))
		{
			return;
		}
		// ２つ先が移動できない物かチェック
		// 移動できるマップチップでない場合という判定
		if (!((m_StageData[next_y2][next_x2] == ObjectType_Ground) ||
			(m_StageData[next_y2][next_x2] == ObjectType_Target)))
		{
			return;
		}

		// ここに到達した場合、必ず動かせる状態になっている

		// 隣の位置を変更する
		if (m_StageData[next_y][next_x] == ObjectType_UnsetCrate)
		{
			m_StageData[next_y][next_x] = ObjectType_Ground;
			pSoundMng->Sound("Src/Data/Sound/push.mp3");
		}
		else
		{
			m_StageData[next_y][next_x] = ObjectType_Target;
		}
		// ２つ先に箱を配置する
		if (m_StageData[next_y2][next_x2] == ObjectType_Ground)
		{
			m_StageData[next_y2][next_x2] = ObjectType_UnsetCrate;
		}
		else
		{
			m_StageData[next_y2][next_x2] = ObjectType_SetCrate;
		}
		// プレイヤーを移動させる
		m_PlayerX = next_x;
		m_PlayerY = next_y;

	}


}



void Stage::Move_Input()
{
	InputManager* exInputMng = InputManager::GetInstance();
	SoundManager* pSoundMng = SoundManager::GetInstance();
	if (exInputMng->IsPush(KeyType_RESET))
	{
		pSoundMng->Sound("Src/Data/Sound/reset.mp3");
		Reset();
	}
	else if (exInputMng->IsPush(KeyType_UP))
	{
		Move(DirType_Up);
	}
	else if (exInputMng->IsPush(KeyType_DOWN))
	{
		Move(DirType_Down);
	}
	else if (exInputMng->IsPush(KeyType_LEFT))
	{
		Move(DirType_Left);
	}
	else if (exInputMng->IsPush(KeyType_RIGHT))
	{
		Move(DirType_Right);
	}

}