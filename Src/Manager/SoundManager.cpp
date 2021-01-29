#include"../Manager/SoundManager.h"
#include"DxLib.h"

SoundManager::SoundManager()
	:SHandle0{ 0 }
	, SHandle1{ 0 }
	, SHandle2{ 0 }
	, SHandle3{ 0 }
	, SHandle4{ 0 }
	, SHandleBGM{ 0 }
{

	LoadSound();

}

SoundManager::~SoundManager()
{
	DeleteSound();

}



void SoundManager::Sound(const char* filename)
{
	if (filename == "Src/Data/Sound/win.mp3")
	{
		PlaySoundMem(SHandle0, DX_PLAYTYPE_BACK);
	}
	if (filename == "Src/Data/Sound/push.mp3")
	{
		PlaySoundMem(SHandle1, DX_PLAYTYPE_BACK);
	}
	if (filename == "Src/Data/Sound/set.mp3")
	{
		PlaySoundMem(SHandle2, DX_PLAYTYPE_BACK);
	}
	if (filename == "Src/Data/Sound/walk.mp3")
	{
		PlaySoundMem(SHandle3, DX_PLAYTYPE_BACK);
	}
	if (filename == "Src/Data/Sound/reset.mp3")
	{
		PlaySoundMem(SHandle4, DX_PLAYTYPE_BACK);
	}
	if (filename == "BGM")
	{
		PlayMusic("Src/Data/Sound/bgm_maoudamashii_8bit17.mp3", DX_PLAYTYPE_LOOP);
		SetVolumeMusic(63);
	}
}

void SoundManager::StopMP3()
{
	StopMusic();
}

void SoundManager::LoadSound()
{
	SHandle0 = LoadSoundMem("Src/Data/Sound/win.mp3");
	SHandle1 = LoadSoundMem("Src/Data/Sound/push.mp3");
	SHandle2 = LoadSoundMem("Src/Data/Sound/set.mp3");
	SHandle3 = LoadSoundMem("Src/Data/Sound/walk.mp3");
	SHandle4 = LoadSoundMem("Src/Data/Sound/reset.mp3");
	SHandleBGM = LoadSoundMem("Src/Data/Sound/bgm_maoudamashii_8bit17.mp3");
}

void SoundManager::DeleteSound()
{
	DeleteSoundMem(SHandleBGM);
	DeleteSoundMem(SHandle4);
	DeleteSoundMem(SHandle3);
	DeleteSoundMem(SHandle2);
	DeleteSoundMem(SHandle1);
	DeleteSoundMem(SHandle0);

}
