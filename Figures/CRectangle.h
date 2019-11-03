#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;	
	Point Corner2;
	int length;
	int width;
public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo );
	void Rotates();
	CRectangle(GfxInfo FigureGfxInfo );	//this constructor is used in load operation
	virtual void Draw(Output* pOut) const;
	virtual bool InsideMe(int a,int b) const;	//check whether rectangle is selected
	virtual void PrintInfo(Output* pOut);
	virtual CFigure*copy();
	void Transfer(Point,Point);
	virtual void Save(ofstream &OutFile);
	virtual bool Load(ifstream &Infile);
};

#endif