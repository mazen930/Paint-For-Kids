#ifndef SENDTOBACK_H
#define SENDTOBACK_H
#include"..\Figures\CFigure.h"
#include "..\Actions\Action.h"
#include "..\Actions\Select.h"
class SendToBack:public Action
{
public:
	SendToBack(ApplicationManager*pApp);

	virtual bool ReadActionParameters();

	virtual void Execute();
};
#endif