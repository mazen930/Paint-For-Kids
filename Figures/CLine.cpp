#include "CLine.h"

CLine::CLine(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Start = P1;
	End = P2;
	length=int(sqrt(pow((Start.x-End.x),2)+pow((Start.y-End.y),2))+0.5);	
	centre.x=(Start.x+End.x)/2;
	centre.y=(Start.y+End.y)/2;
}

CLine::CLine(GfxInfo FigureGfxInfo ):CFigure(FigureGfxInfo)
{
}

bool CLine::InsideMe(int a,int b)const
 {
	 double d1,d2,d;
	 d1=sqrt(pow(Start.x-a,2)+pow(Start.y-b,2));	//distance between start point and the selected point
	 d2=sqrt(pow(End.x-a,2)+pow(End.y-b,2));		//distance between end point and the selected point
	 d=sqrt(pow(Start.x-End.x,2)+pow(Start.y-End.y,2));		//length of the line
	 if(d==d1+d2||((d1+d2)-d>0.0&&(d1+d2)-d<1.0))	//approximation
		 return true;
	 return false;
 }

void CLine::Draw(Output* pOut) const
{
	//Call Output::DrawLn to draw a Line on the screen	
	pOut->DrawLn(Start, End, FigGfxInfo, Selected);
}

CFigure*CLine::copy()
{
	 CFigure*c=new CLine(Start,End,FigGfxInfo);
	 return c;
}

void CLine::Transfer(Point To,Point Major)
{
	//coordinates diffrences
	int xdiff_start=centre.x-Start.x;
	int ydiff_start=centre.y-Start.y;
	int xdiff_end=centre.x-End.x;
	int ydiff_end=centre.y-End.y;
	int X_diff=Major.x-centre.x;
	int Y_diff=Major.y-centre.y;
	centre.x=To.x-X_diff;	centre.y=To.y-Y_diff;
	//moving with same diffrences
	Start.x=centre.x-xdiff_start;
	Start.y=centre.y-ydiff_start;
	End.x=centre.x-xdiff_end;
	End.y=centre.y-ydiff_end;
}

void CLine::PrintInfo(Output*pOut)
{
	int length=(int)sqrt(pow(Start.x-End.x,2)+pow(Start.y-End.y,2));
	pOut->PrintMessage("Line->ID="+to_string(ID)+",Start:("+to_string(Start.x)+','+to_string(Start.y)+')'+','+",End"+'('+to_string(End.x)+','+to_string(End.y)+')'+" length="+to_string(length));
}

void CLine::Rotates()
{
	double center_x= (double)(Start.x + End.x)/2.0000;
	double center_y = (double)(Start.y + End.y)/2.0000;
	Start.x = (double)Start.x-center_x;
	Start.y = (double)Start.y- center_y;
	End.x = (double)End.x- center_x;
	End.y = (double)End.y - center_y;
	int x_temp = Start.x;
	int y_temp = Start.y;
	Start.x = -y_temp;
	Start.y = x_temp;
	x_temp = End.x;
	y_temp = End.y;
	End.x = -y_temp;
	End.y = x_temp;
	Start.x = (double)Start.x+ center_x;
	Start.y = (double)Start.y+ center_y;
	End.x = (double)End.x+ center_x;
	End.y = (double)End.y+ center_y;
	
}

void CLine::Save(ofstream &OutFile)
{
	OutFile<<LINE<<'\t'<<ID<<'\t'<<Start.x<<'\t'<<Start.y<<'\t'<<End.x<<'\t'<<End.y<<'\t'
		<<to_number(FigGfxInfo.DrawClr)<<'\n';
}

bool CLine::Load(ifstream &Infile)
{
	int dc;
	Infile>>ID>>Start.x>>Start.y>>End.x>>End.y>>dc;

	if(!(dc>=0 && dc<ColorsNum))
		return false;

	FigGfxInfo.DrawClr = colors[dc];
	
	return true;
}