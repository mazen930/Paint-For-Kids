#ifndef COPY_H
#define COPY_H
#include"..\Figures\CFigure.h"
#include "..\Actions\Action.h"
#include "..\Actions\Select.h"

class Copy:public Action
{
public:
	
	Copy(ApplicationManager* pApp);
	
	virtual bool ReadActionParameters();
	
	virtual void Execute() ;
	
};
#endif
