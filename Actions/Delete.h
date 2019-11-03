#ifndef DELETE_H
#define DELETE_H
#include"..\Figures\CFigure.h"
#include "Action.h"

class Delete :public Action
{
public:
	
	Delete(ApplicationManager* pApp);
	
	virtual bool ReadActionParameters();
	
	virtual void Execute() ;
	~Delete();
};
#endif
