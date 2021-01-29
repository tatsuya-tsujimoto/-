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
	SetMainWindowText("My�q�ɔ�");


	if (DxLib_Init() == -1)
	{ return -1; }

	// �`���𗠂̉�ʂɐݒ�
	SetDrawScreen(DX_SCREEN_BACK);


	// �Ǘ��N���X�̍쐬
	GameManager::CreateInstance();
	InputManager::CreateInstance();
	SceneManager::CreateInstance();
	TextureManager::CreateInstance();
	SoundManager::CreateInstance();
	
	
	while (true)
	{
		// Windows�̃��b�Z�[�W�����Ɏ��s�������A����ꂽ��I��
		if (ProcessMessage() != 0)
		{ break; }

		// DxLib�̂��񑩁F��ʃN���A
		ClearDrawScreen();
		clsDx();


		// ����
		InputManager::GetInstance()->Update();
		SceneManager::GetInstance()->Exec();
		



		// �`��
		SceneManager::GetInstance()->Draw();


		// DxLib�̂��񑩁F��ʍX�V
		ScreenFlip();		// �t�����g�o�b�t�@�ƃo�b�N�o�b�t�@�̓���ւ�
	}

	// �Ǘ��N���X�̌�n��
	SoundManager::DestroyInstance();
	TextureManager::DestroyInstance();
	SceneManager::DestroyInstance();
	InputManager::DestroyInstance();
	GameManager::DestroyInstance();

	// DX���C�u�����g�p�ɏI������
	DxLib_End();

	return 0;


}
















