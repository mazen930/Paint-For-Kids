#pragma once
#include"Action.h"
#include"Figure_Type.h"
#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
class Figure_Fill_Color:public Action
{

public:
	 Figure_Fill_Color(ApplicationManager *pApp);
	 bool ReadActionParameters();
	 void Execute();
};