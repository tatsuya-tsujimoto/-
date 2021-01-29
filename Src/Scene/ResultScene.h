#ifndef RESULTSCENE_H
#define RESULTSCENE_H

#include"SceneBase.h"

class ResultScene :public SceneBase
{
public:
	ResultScene();
	~ResultScene();

	// 処理内容は派生クラス毎に違うので
	// 純粋仮想関数として宣言しておく
	virtual void Exec() ;
	virtual void Draw() ;


	virtual bool IsEnd()const;
private:
	void step_Input();

};







#endif