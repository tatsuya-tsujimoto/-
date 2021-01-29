#ifndef DEFINITION_H
#define DEFINITION_H


// シーンID
enum SceneID
{
	SceneID_Title,
	SceneID_InGame,
	SceneID_Result,

	SceneID_Max,
	SceneID_Invalid,


};


// 倉庫番用の定義
//ステージ情報
const int STAGE_WIDTH = 11;
const int STAGE_HEIGHT = 13;

//マップチップの縦横サイズ
const int CHIP_WIDTH = 32;
const int CHIP_HEIGHT = 32;

//オブジェクト種類
//	0	地面
//	1	壁
//	2	プレイヤーの初期位置
//	3	クレートの配置位置
//	4	未配置のクレート
//	7	配置済みのクレート
//		（配置場所＋未配置クレート＝７）
enum ObjectType
{
	ObjectType_Ground,
	ObjectType_Wall,
	ObjectType_Player,
	ObjectType_Target,
	ObjectType_UnsetCrate,
	ObjectType_SetCrate=7
};

enum DirType
{
	DirType_Up,			// ↑
	DirType_Down,		// ↓
	DirType_Left,		// ←
	DirType_Right,		// →

	DirType_Max,		// 画像読み込みで使用する
};



#endif