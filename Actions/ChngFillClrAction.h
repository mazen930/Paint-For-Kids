#ifndef CHNG_FILL_CLR_ACTION_H
#define CHNG_FILL_CLR_ACTION_H

#include"Action.h"

class ChngFillClrAction: public Action
{
	color FillColor;
public:
	ChngFillClrAction(ApplicationManager* pApp);

	virtual bool ReadActionParameters();

	virtual void Execute();
};

#endif