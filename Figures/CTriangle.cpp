#include "CTriangle.h"

CTriangle::CTriangle(Point P1, Point P2, Point P3, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	Corner3 = P3;
	centre.x=(Corner1.x+Corner2.x+Corner3.x)/3;
	centre.y=(Corner1.y+Corner2.y+Corner3.y)/3;
}

CTriangle::CTriangle(GfxInfo FigureGfxInfo ):CFigure(FigureGfxInfo)
{
}
 
 bool CTriangle::InsideMe(int a,int b)const
 {
	double A1,A2,A3,A;	//seperating the triangle into 3 triangles 
	A=abs((Corner1.x*(Corner2.y-Corner3.y)+Corner2.x*(Corner3.y-Corner1.y)+Corner3.x*(Corner1.y-Corner2.y))/2.0);	//Area of the original triangle
	A1=abs((Corner1.x*(Corner2.y-b)+Corner2.x*(b-Corner1.y)+a*(Corner1.y-Corner2.y))/2.0);	//Area of the first  traingle
	A2=abs((a*(Corner2.y-Corner3.y)+Corner2.x*(Corner3.y-b)+Corner3.x*(b-Corner2.y))/2.0);	//Area of the second  traingle
	A3=abs((Corner1.x*(b-Corner3.y)+a*(Corner3.y-Corner1.y)+Corner3.x*(Corner1.y-b))/2.0);	//Area of the third  traingle
	if(A==A1+A2+A3)
		return true;
	 return false;
 }

void CTriangle::Draw(Output* pOut) const
{
	//Call Output::DrawTri to draw a Triangle on the screen	
	pOut->DrawTri(Corner1, Corner2, Corner3, FigGfxInfo, Selected);
}

CFigure*CTriangle::copy()
{
	 CFigure*c=new CTriangle(Corner1 ,Corner2, Corner3 ,FigGfxInfo);
	 return c;
}
void CTriangle::Rotates()
{
	double center_x = (double)(Corner1.x + Corner2.x+Corner3.x) / 3.0000;
	double center_y = (double)(Corner1.y + Corner2.y+Corner3.y) / 3.0000;
	Corner1.x = (double)Corner1.x- center_x;
	Corner1.y = (double)Corner1.y- center_y;
	Corner2.x = (double)Corner2.x- center_x;
	Corner2.y = (double)Corner2.y- center_y;
	Corner3.x = (double)Corner3.x- center_x;
	Corner3.y = (double)Corner3.y- center_y;
	int x_temp = Corner1.x;
	int y_temp = Corner1.y;
	Corner1.x = -y_temp;
	Corner1.y = x_temp;
	x_temp = Corner2.x;
	y_temp = Corner2.y;
	Corner2.x = -y_temp;
	Corner2.y = x_temp;
	x_temp = Corner3.x;
	y_temp = Corner3.y;
	Corner3.x = -y_temp;
	Corner3.y = x_temp;
	Corner1.x = (double)Corner1.x+ center_x;
	Corner1.y = (double)Corner1.y+ center_y;
	Corner2.x = (double)Corner2.x+ center_x;
	Corner2.y = (double)Corner2.y+center_y;
	Corner3.x = (double)Corner3.x+ center_x;
	Corner3.y = (double)Corner3.y+ center_y;

}
void CTriangle::Transfer(Point To,Point Major)
{
	int X_diff=Major.x-centre.x;
	int Y_diff=Major.y-centre.y;
	centre.x=To.x-X_diff;	centre.y=To.y-Y_diff;
	int xdiff=Major.x-To.x;
	int ydiff=Major.y-To.y;
	Corner1.x -= xdiff;		Corner1.y -= ydiff;
	Corner2.x -= xdiff;		Corner2.y -= ydiff;
	Corner3.x -= xdiff;		Corner3.y -= ydiff;
}
void CTriangle::PrintInfo(Output*pOut)
{
	pOut->PrintMessage("Triangle->ID="+to_string(ID)+",Corner 1("+to_string(Corner1.x)+','+to_string(Corner1.y)+"),Corner 2("+to_string(Corner2.x)+','+to_string(Corner2.y)+"),Corner 3("+to_string(Corner3.x)+','+to_string(Corner3.y)+')');
}

void CTriangle::Save(ofstream &OutFile)
{
	OutFile<<TRIANGLE<<'\t'<<ID<<'\t'<<Corner1.x<<'\t'<<Corner1.y<<'\t'<<Corner2.x<<'\t'<<Corner2.y<<'\t'<<Corner3.x<<'\t'<<Corner3.y<<'\t'
		<<to_number(FigGfxInfo.DrawClr)<<'\t';

	if( FigGfxInfo.isFilled == false )
		OutFile<<-1;
	else
		OutFile<<to_number(FigGfxInfo.FillClr);
	OutFile<<'\n';
}

bool CTriangle::Load(ifstream &Infile)
{
	Infile>>ID>>Corner1.x>>Corner1.y>>Corner2.x>>Corner2.y>>Corner3.x>>Corner3.y;

	if( CFigure::Load(Infile) )	//to load draw & fill color
		return true;
	else
		return false;
}
