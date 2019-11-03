#include "CRectangle.h"

CRectangle::CRectangle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Corner1 = P1;
	Corner2 = P2;
	length=Corner2.y-Corner1.y;
	width=Corner2.x-Corner1.x;
	centre.x=(Corner1.x+Corner2.x)/2;
	centre.y=(Corner1.y+Corner2.y)/2;
}

void CRectangle::Rotates()
{
	double center_x = (double)(Corner1.x + Corner2.x) / 2.00000;
	double center_y = (double)(Corner1.y + Corner2.y) / 2.00000;
	Corner1.x = (double)Corner1.x- center_x;
	Corner1.y = (double)Corner1.y- center_y;
	Corner2.x = (double)Corner2.x- center_x;
	Corner2.y = (double)Corner2.y- center_y;
	int x_temp = Corner1.x;
	int y_temp = Corner1.y;
	Corner1.x = -y_temp;
	Corner1.y = x_temp;
	x_temp = Corner2.x;
	y_temp = Corner2.y;
	Corner2.x = -y_temp;
	Corner2.y = x_temp;
	Corner1.x = (double)Corner1.x+ center_x;
	Corner1.y = (double)Corner1.y+ center_y;
	Corner2.x = (double)Corner2.x+ center_x;
	Corner2.y = (double)Corner2.y+ center_y;

}

CRectangle::CRectangle(GfxInfo FigureGfxInfo ):CFigure(FigureGfxInfo)
{
}

 bool CRectangle::InsideMe(int a,int b)const
 {
	 if(Corner1.x>Corner2.x&&Corner1.y>Corner2.y)
	 {
		 if(a>=Corner2.x&&a<=Corner1.x&&b>=Corner2.y&&b<=Corner1.y)
		 {
			 return true;
		 }
	 }
	 else if(Corner1.x>Corner2.x&&Corner1.y<=Corner2.y)
	 {
		 if(a>=Corner2.x&&a<=Corner1.x&&b<=Corner2.y&&b>=Corner1.y)
		 {
			 return true;
		 }
	 }
	 else if(Corner1.x<=Corner2.x&&Corner1.y>Corner2.y)
	 {
		 if(a<=Corner2.x&&a>=Corner1.x&&b>=Corner2.y&&b<=Corner1.y)
		 {
			 return true;
		 }
	 }
	 else if(Corner1.x<=Corner2.x&&Corner1.y<=Corner2.y)
	 {
		 if(a<=Corner2.x&&a>=Corner1.x&&b<=Corner2.y&&b>=Corner1.y)
		 {
			 return true;
		 }
	 }
	 
	 return false;
 }

void CRectangle::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawRect(Corner1, Corner2, FigGfxInfo, Selected);
}

CFigure*CRectangle::copy()
{
	 CFigure*c=new CRectangle(Corner1,Corner2,FigGfxInfo);
	 return c;
}

void CRectangle::Transfer(Point To,Point Major)
{
	//getting coordinates diffrences
	int X_diff=Major.x-centre.x;
	int Y_diff=Major.y-centre.y;
	centre.x=To.x-X_diff;	centre.y=To.y-Y_diff;
	//allocating the position of the 2 corners to each other
	if((Corner1.x>Corner2.x)&&(Corner1.y>Corner2.y))
	{
		Corner1.x=centre.x-width/2;
		Corner1.y=centre.y-length/2;
		Corner2.x=centre.x+width/2;
		Corner2.y=centre.y+length/2;
	}
	else
	{
		Corner1.x=centre.x+width/2;
		Corner1.y=centre.y-length/2;
		Corner2.x=centre.x-width/2;
		Corner2.y=centre.y+length/2;
	}
}
void CRectangle::PrintInfo(Output*pOut)
{
	int height=abs(Corner1.y-Corner2.y);
	int width=abs(Corner1.x-Corner2.x);
	pOut->PrintMessage("Rectangle->ID="+to_string(ID)+",Height="+to_string(height)+",Width="+to_string(width));
}

void CRectangle::Save(ofstream &OutFile)
{
	OutFile<<RECTANGLE<<'\t'<<ID<<'\t'<<Corner1.x<<'\t'<<Corner1.y<<'\t'<<Corner2.x<<'\t'<<Corner2.y<<'\t'
		<<to_number(FigGfxInfo.DrawClr)<<'\t';

	if( FigGfxInfo.isFilled == false )
		OutFile<<-1;
	else
		OutFile<<to_number(FigGfxInfo.FillClr);
	OutFile<<'\n';
}
bool CRectangle::Load(ifstream &Infile)
{
	Infile>>ID>>Corner1.x>>Corner1.y>>Corner2.x>>Corner2.y;

	if( CFigure::Load(Infile) )	//to load draw & fill color
		return true;
	else
		return false;
}
