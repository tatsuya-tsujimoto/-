#include"TextureManager.h"



TextureManager::TextureManager()
	:Handle_Ground{0}
	, Handle_Wall{ 0 }
	, Handle_Player{ 0 }
	, Handle_Target{ 0 }
	, Handle_UnsetCrate{ 0 }
	, Handle_SetCrate{ 0 }
	, Handle_Congratulation{ 0 }
{
	LoadTexture();
}

TextureManager::~TextureManager()
{
	DeleteTexture();
}

void TextureManager::LoadTexture()
{
	Handle_Ground = LoadGraph("Src/Data/Ground/ground.png");
	Handle_Wall = LoadGraph("Src/Data/Ground/block.png");
	Handle_Player = LoadGraph("Src/Data/Player/player_00.png");
	Handle_Target = LoadGraph("Src/Data/Crate/crate_00.png");
	Handle_UnsetCrate = LoadGraph("Src/Data/Crate/crate_02.png");
	Handle_SetCrate = LoadGraph("Src/Data/Crate/crate_01.png");
	Handle_Congratulation = LoadGraph("Src/Data/Clear.png");

}



void TextureManager::DeleteTexture()
{
	DeleteGraph(Handle_Congratulation);
	DeleteGraph(Handle_SetCrate);
	DeleteGraph(Handle_UnsetCrate);
	DeleteGraph(Handle_Target);
	DeleteGraph(Handle_Player);
	DeleteGraph(Handle_Wall);
	DeleteGraph(Handle_Ground);
}

int TextureManager::PassHandle(ObjectType object)
{
	switch (object)
	{
	case ObjectType::ObjectType_Ground:
	{
		return Handle_Ground;
	}break;
	case ObjectType::ObjectType_Player:
	{
		return Handle_Player;
	}break;
	case ObjectType::ObjectType_SetCrate:
	{
		return Handle_SetCrate;
	}break;
	case ObjectType::ObjectType_Target:
	{
		return Handle_Target;
	}break;
	case ObjectType::ObjectType_UnsetCrate:
	{
		return Handle_UnsetCrate;
	}break;
	case ObjectType::ObjectType_Wall:
	{
		return Handle_Wall;
	}break;

	default:return 0;
		break;
	}
}

int TextureManager::PassHandle(const char* file)
{

	if (file == "Src/Data/Clear.png")
		return Handle_Congratulation;

}