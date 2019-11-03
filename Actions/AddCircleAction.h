#ifndef ADD_CIRCLE_ACTION_H
#define ADD_CIRCLE_ACTION_H

#include "Action.h"

//Add Circle Action class
class AddCircleAction: public Action
{
private:
	Point P1, P2; //Circle start & end points
	GfxInfo CircleGfxInfo;
public:
	AddCircleAction(ApplicationManager *pApp);

	//Reads Circle parameters
	virtual bool ReadActionParameters();
	
	//Add Circle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif