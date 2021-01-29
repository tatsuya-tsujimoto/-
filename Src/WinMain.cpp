#include "DxLib.h"
#include"Manager/SceneManager.h"
#include"Manager/InputManager.h"
#include"Manager/GameManager.h"
#include"Manager/TextureManager.h"
#include"Manager/SoundManager.h"
//@@
#include"..//Src/Manager/Singleton.h"

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
	SetOutApplicationLogValidFlag(false);
	ChangeWindowMode(true);
	SetGraphMode(640, 480, 32);
	SetBackgroundColor(125, 125, 125);
	SetMainWindowText("My倉庫番");


	if (DxLib_Init() == -1)
	{ return -1; }

	// 描画先を裏の画面に設定
	SetDrawScreen(DX_SCREEN_BACK);


	// 管理クラスの作成
	GameManager::CreateInstance();
	InputManager::CreateInstance();
	SceneManager::CreateInstance();
	TextureManager::CreateInstance();
	SoundManager::CreateInstance();
	
	
	while (true)
	{
		// Windowsのメッセージ処理に失敗したか、閉じられたら終了
		if (ProcessMessage() != 0)
		{ break; }

		// DxLibのお約束：画面クリア
		ClearDrawScreen();
		clsDx();


		// 処理
		InputManager::GetInstance()->Update();
		SceneManager::GetInstance()->Exec();
		



		// 描画
		SceneManager::GetInstance()->Draw();


		// DxLibのお約束：画面更新
		ScreenFlip();		// フロントバッファとバックバッファの入れ替え
	}

	// 管理クラスの後始末
	SoundManager::DestroyInstance();
	TextureManager::DestroyInstance();
	SceneManager::DestroyInstance();
	InputManager::DestroyInstance();
	GameManager::DestroyInstance();

	// DXライブラリ使用に終了処理
	DxLib_End();

	return 0;


}
















