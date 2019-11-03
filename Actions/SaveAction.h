#ifndef SAVE_ACTION_H
#define SAVE_ACTION_H

#include "Action.h"

#include <iostream>
#include <fstream>
using namespace std;

class SaveAction: public Action
{
	string path;
	ofstream OutputFile;

public:
	SaveAction(ApplicationManager *pApp);

	virtual bool ReadActionParameters();

	virtual void Execute();
};

//enum and a function to simplify save & load operations
enum CFigureType
{
	LINE, RECTANGLE, CIRCLE, TRIANGLE
};

int to_number(const color&);	//to convert from color to int

#endif