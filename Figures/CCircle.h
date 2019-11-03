#ifndef CCIRCLE_H
#define CCIRCLE_H

#include "CFigure.h"

class CCircle : public CFigure
{
private:
	Point Start;	
	Point End;
	int radius;
public:
	CCircle(Point, Point, GfxInfo FigureGfxInfo );
	void Rotates();
	CCircle(GfxInfo FigureGfxInfo );			//this constructor is used in load operation
	virtual void Draw(Output* pOut) const;	
	virtual bool InsideMe(int a,int b) const;	//check whether circle is selected
	virtual void PrintInfo(Output* pOut);
	virtual void Save(ofstream &OutFile);
	virtual bool Load(ifstream &Infile);
	virtual CFigure*copy();
	void Transfer(Point,Point);
};

#endif