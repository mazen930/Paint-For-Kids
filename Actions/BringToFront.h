#ifndef BRINGTOFRONT_H
#define BRINGTOFRONT_H
#include"..\Figures\CFigure.h"
#include "..\Actions\Action.h"
#include "..\Actions\Select.h"
class BringToFront:public Action
{
public:
	BringToFront(ApplicationManager*pApp);

	virtual bool ReadActionParameters();

	virtual void Execute();
};
#endif