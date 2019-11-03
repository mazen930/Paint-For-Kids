#ifndef CLINE_H
#define CLINE_H

#include "CFigure.h"

class CLine : public CFigure
{
private:
	Point Start;	
	Point End;
	int length;
public:
	CLine(Point, Point, GfxInfo FigureGfxInfo );
	CLine(GfxInfo FigureGfxInfo );	//this constructor is used in load operation
	virtual void Draw(Output* pOut) const;
	virtual bool InsideMe(int a,int b) const;	//check whether line is selected
	virtual void PrintInfo(Output* pOut);
	void Rotates();
	virtual CFigure*copy();
	void Transfer(Point,Point);
	virtual void Save(ofstream &OutFile);
	virtual bool Load(ifstream &Infile);
};

#endif