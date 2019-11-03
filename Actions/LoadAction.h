
#ifndef LOAD_ACTION_H
#define LOAD_ACTION_H

#include "SaveAction.h"	//for functions used in it

class LoadAction: public Action
{
	string path;
	ifstream InputFile;

public:
	LoadAction(ApplicationManager *pApp);

	virtual bool ReadActionParameters();

	virtual void Execute();
};


#endif