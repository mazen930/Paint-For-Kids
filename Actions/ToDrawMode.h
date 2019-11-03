#pragma once
#include"Action.h"
#include"..\ApplicationManager.h"

class TO_DRAW_MODE:public Action

{	
public:
	TO_DRAW_MODE(ApplicationManager*pApp);
	//Reads parameters required for action to execute (code depends on action type)
	virtual bool ReadActionParameters();

	//Execute action (code depends on action type)
	virtual void Execute();
};
