#ifndef SCENEBASE_H
#define SCENEBASE_H


class SceneBase
{
public:
	SceneBase();
	virtual ~SceneBase();

	// 処理内容は派生クラス毎に違うので
	// 純粋仮想関数として宣言しておく
	virtual void Exec() = 0;
	virtual void Draw() = 0;


	virtual bool IsEnd()const = 0;	// シーンが終了したかどうかを返す		行為は共通だが中身が違う

protected:
	int m_Step;		// 処理内容を管理する変数


};







#endif