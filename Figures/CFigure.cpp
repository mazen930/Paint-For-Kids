#include "CFigure.h"
#include"CLine.h"
CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
	ID=0;
}

void CFigure::SetSelected(bool s)
{
	Selected=s;
}

void CFigure::set_ID(int x)
{
	ID=x;
}

int CFigure::Get_ID()const
{
	return ID;
}
int CFigure::getcentre_X(){return centre.x;}
int CFigure::getcentre_Y(){return centre.y;}
bool CFigure::IsSelected()const
{return Selected;}

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

color CFigure::get_color()
{
	if (!FigGfxInfo.isFilled)
	{
		FigGfxInfo.FillClr = UI.BkGrndColor;
		return LIGHTGOLDENRODYELLOW;
	}
	else if (dynamic_cast<CLine*>(this))
		return FigGfxInfo.DrawClr;
	else
		return FigGfxInfo.FillClr;
}

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

bool CFigure::Load(ifstream &Infile)
{
	int dc;
	int fc;
	Infile>>dc>>fc;

	if(!(dc>=0 && dc<ColorsNum))
		return false;

	FigGfxInfo.DrawClr = colors[dc];

	if(!(fc>=-1 && fc<ColorsNum))
		return false;
	if(fc==-1)
		FigGfxInfo.isFilled = false;
	else
		ChngFillClr( colors[fc] );

	return true;
}

CFigure::~CFigure()
{
}
