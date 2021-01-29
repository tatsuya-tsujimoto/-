#ifndef SCENEBASE_H
#define SCENEBASE_H


class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();

	// �������e�͔h���N���X���ɈႤ�̂�
	// �������z�֐��Ƃ��Đ錾���Ă���
	virtual void Exec() = 0;
	virtual void Draw() = 0;


	virtual bool IsEnd()const = 0;	// �V�[�����I���������ǂ�����Ԃ�		�s�ׂ͋��ʂ������g���Ⴄ

protected:
	int m_Step;		// �������e���Ǘ�����ϐ�


};







#endif