#ifndef KEY_DEFINITION_H
#define KEY_DEFINITION_H

#include"DxLib.h"

// key‚Ìí—Ş
enum KeyType
{
	KeyType_UP,			//ã
	KeyType_DOWN,		//‰º
	KeyType_LEFT,		//©
	KeyType_RIGHT,		//¨
	KeyType_ENTER,		//Œˆ’è
	KeyType_RESET,		//ƒŠƒZƒbƒg

	KeyType_MAX,		//key‚Ìí—Ş‚Ì”

};

const int KEY_ASSIGN[KeyType_MAX] =
{
	KEY_INPUT_UP,
	KEY_INPUT_DOWN,
	KEY_INPUT_LEFT,
	KEY_INPUT_RIGHT,
	KEY_INPUT_RETURN,
	KEY_INPUT_R,
};






#endif