#ifndef SOUND_MANAGER_H
#define SOUND_MANAGER_H
#include"../Definition.h"
#include"Singleton.h"

class SoundManager :public Singleton<SoundManager>
{
public:
	SoundManager();
	~SoundManager();
	void Sound(const char* filename);
	void StopMP3();

private:
	int SHandle0;
	int SHandle1;
	int SHandle2;
	int SHandle3;	
	int SHandle4;
	int SHandleBGM;
	void LoadSound();
	void DeleteSound();
};


#endif