#ifndef TITLESCENE_H
#define TITLESCENE_H

#include"SceneBase.h"

class TitleScene:public SceneBase
{
public:
	TitleScene();
	virtual ~TitleScene();

	// �������e�͔h���N���X���ɈႤ�̂�
	// �������z�֐��Ƃ��Đ錾���Ă���
	virtual void Exec() ;
	virtual void Draw() ;

	virtual bool IsEnd()const;

private:
	// �^�C�g�����S����
	void step_LogoIn();
	// ���͎�t
	void step_Input();



};







#endif