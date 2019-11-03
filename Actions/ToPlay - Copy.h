#ifndef TOPLAY_H
#define TOPLAY_H
#include "Action.h"
class ToPlay:public Action
{
public:
	ToPlay(ApplicationManager*pApp);
	//Reads parameters required for action to execute (code depends on action type)
	virtual bool ReadActionParameters();
	
	//Execute action (code depends on action type)
	virtual void Execute();

};
#endif