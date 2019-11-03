#ifndef ADD_TRI_ACTION_H
#define ADD_TRI_ACTION_H

#include "Action.h"

//Add Triangle Action class
class AddTriAction: public Action
{
private:
	Point P1, P2, P3; //Triangle Corners
	GfxInfo TriGfxInfo;
public:
	AddTriAction(ApplicationManager *pApp);

	//Reads Triangle parameters
	virtual bool ReadActionParameters();
	
	//Add Triangle to the ApplicationManager
	virtual void Execute() ;
	
};

#endif