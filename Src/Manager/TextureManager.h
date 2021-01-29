#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include "Singleton.h"
#include"../Definition.h"
#include"DxLib.h"

class TextureManager :public Singleton<TextureManager>
{
public:

	TextureManager();
	~TextureManager();

	int PassHandle(ObjectType object);
	int PassHandle(const char* file);

private:

	int Handle_Ground;
	int Handle_Wall;
	int Handle_Player;
	int Handle_Target;
	int Handle_UnsetCrate;
	int Handle_SetCrate;
	int Handle_Congratulation;

	void LoadTexture();
	void DeleteTexture();

};






#endif