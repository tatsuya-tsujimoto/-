#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include"SceneBase.h"

class ResultScene :public SceneBase
{
public:
	ResultScene();
	~ResultScene();

	// �������e�͔h���N���X���ɈႤ�̂�
	// �������z�֐��Ƃ��Đ錾���Ă���
	virtual void Exec() ;
	virtual void Draw() ;


	virtual bool IsEnd()const;
private:
	void step_Input();

};







#endif