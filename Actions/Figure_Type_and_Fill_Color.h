#pragma once
#include"Action.h"
#include"Figure_Type.h"
#include"Figure_Fill_Color.h"
#include"..\ApplicationManager.h"
class Figure_Type_and_Fill_Color:public Action
{	
	struct Index//to store each type with its own color
	{
		string type;
		color fcolor;
	};

	public:
		Figure_Type_and_Fill_Color(ApplicationManager *pApp);
		virtual bool ReadActionParameters();
		virtual void Execute();

};
