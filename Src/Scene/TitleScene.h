#ifndef TITLESCENE_H
#define TITLESCENE_H

#include"SceneBase.h"

class TitleScene:public SceneBase
{
public:
	TitleScene();
	virtual ~TitleScene();

	// 処理内容は派生クラス毎に違うので
	// 純粋仮想関数として宣言しておく
	virtual void Exec() ;
	virtual void Draw() ;

	virtual bool IsEnd()const;

private:
	// タイトルロゴ入場
	void step_LogoIn();
	// 入力受付
	void step_Input();



};







#endif