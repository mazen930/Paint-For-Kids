#ifndef PASTE_H
#define PASTE_H
#include"..\Figures\CFigure.h"
#include "..\Actions\Action.h"
#include "..\Actions\Select.h"

class Paste:public Action
{
	Point pp;
	Point Mcentre;
public:
	
	Paste(ApplicationManager* pApp);
	
	virtual bool ReadActionParameters();

	virtual void Execute();
	
};

#endif
