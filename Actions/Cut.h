#ifndef CUT_H
#define CUT_H
#include"..\Figures\CFigure.h"
#include "..\Actions\Action.h"
#include "..\Actions\Select.h"

class Cut:public Action
{
public:
	
	Cut(ApplicationManager* pApp);
	
	virtual bool ReadActionParameters();
	
	virtual void Execute() ;
	~Cut();
};
#endif
