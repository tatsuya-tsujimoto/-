#ifndef INGAMESCENE_H
#define INGAMESCENE_H
#include"../Definition.h"
#include"SceneBase.h"
#include"../Manager/InputManager.h"
#include"../Stage.h"

class InGameScene:public SceneBase
{
public:
	InGameScene();
	~InGameScene();

	// �������e�͔h���N���X���ɈႤ�̂�
	// �������z�֐��Ƃ��Đ錾���Ă���
	virtual void Exec() ;
	virtual void Draw() ;


	virtual bool IsEnd()const;

private:
	bool IsClear() const;

	void Reset();

	void Move(DirType dir_);

private:
	void step_StartJingle();
	void step_Input();
	void step_ClearJingle();/*
	void play_Input();
	void play_Carry();*/

	InputManager* pInputMng;
	Stage stage;

};







#endif