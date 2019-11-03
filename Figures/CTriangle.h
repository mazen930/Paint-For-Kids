#ifndef CTRIANGLE_H
#define CTRIANGLE_H

#include "CFigure.h"

class CTriangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;
	Point Corner3;
public:
	CTriangle(Point, Point, Point, GfxInfo FigureGfxInfo );
	CTriangle(GfxInfo FigureGfxInfo );	//this constructor is used in load operation
	virtual void Draw(Output* pOut) const;
	virtual bool InsideMe(int a,int b) const;	//check whether triangle is selected
	virtual void PrintInfo(Output* pOut);
	virtual CFigure*copy();
	void Rotates();
	void Transfer(Point,Point);
	virtual void Save(ofstream &OutFile);
	virtual bool Load(ifstream &Infile);
};

#endif