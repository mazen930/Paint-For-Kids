#ifndef FIGURE_TYPE_H
#define FIGURE_TYPE_H
#include "Action.h"
#include"Select.h"
class Figure_Type:public Action
{
protected:
	Select *s1;
public:
	Figure_Type(ApplicationManager *pApp);
	virtual bool ReadActionParameters();
	virtual void Execute();
};
#endif