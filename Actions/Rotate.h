#pragma once
#include"..\Actions\Action.h"
class Rotate:public Action
{
public:
	Rotate(ApplicationManager* pApp);
	//Reads parameters required for action to execute (code depends on action type)
	 bool ReadActionParameters();

	//Execute action (code depends on action type)
	 void Execute();
};

