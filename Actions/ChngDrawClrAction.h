#ifndef CHNG_DRAW_CLR_ACTION_H
#define CHNG_DRAW_CLR_ACTION_H

#include"Action.h"

class ChngDrawClrAction: public Action
{
	color DrawColor;
public:
	ChngDrawClrAction(ApplicationManager* pApp);

	virtual bool ReadActionParameters();

	virtual void Execute();
};

#endif