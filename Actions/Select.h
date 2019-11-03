#ifndef SELECT_H
#define SELECT_H
#include"..\Figures\CFigure.h"
#include "Action.h"

class Select :public Action
{
	CFigure* Selected;
public:
	
	Select(ApplicationManager* pApp);
	
	virtual bool ReadActionParameters();
	void select_play(double &z1, double &z2);
	virtual void Execute() ;
};
#endif
