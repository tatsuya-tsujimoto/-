#ifndef STAGE_H
#define STAGE_H
#include"Definition.h"

class Stage
{
public:
	Stage();
	~Stage();

	void Exec();
	void Draw();
	bool IsClear() const;

private:



	void Reset();

	void Move(DirType dir_);

	void Move_Input();

private:
	int m_StageData[STAGE_HEIGHT][STAGE_WIDTH];
	int m_PlayerX;		// îzóÒè„ÇÃX
	int m_PlayerY;		// îzóÒè„ÇÃY

};





#endif