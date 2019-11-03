#include "CCircle.h"

CCircle::CCircle(Point P1, Point P2, GfxInfo FigureGfxInfo):CFigure(FigureGfxInfo)
{
	Start = P1;
	End = P2;
	centre.x=(P1.x+P2.x)/2;
	centre.y=(P1.y+P2.y)/2;
	radius=int(sqrt(pow((Start.x-End.x),2)+pow((Start.y-End.y),2))/2+0.5);		//half the distance between the two points 

}

void CCircle::Rotates()			//to avoid abstract classes 
{
	return;
}

CCircle::CCircle(GfxInfo FigureGfxInfo ):CFigure(FigureGfxInfo)
{
}
 
 bool CCircle::InsideMe(int a,int b)const
 {
	 
     int radius=int(sqrt(pow((Start.x-End.x),2)+pow((Start.y-End.y),2))/2+0.5);		//half the distance between the two points 
							       											        //(the 0.5 is for approximation)
	 int z=(int)(sqrt(pow((a-centre.x),2)+pow((b-centre.y),2))+0.5);	// z is the distance from the center to the point 
	 if(z<=radius)
		 return true;
	 return false;
 }

 void CCircle::PrintInfo(Output*pOut)
 {
	 int radius=(int)sqrt(pow((End.x-Start.x),2)+pow((End.y-Start.y),2))/2;
	 pOut->PrintMessage("Cirlce->ID="+to_string(ID)+",Center:("+to_string(centre.x)+','+to_string(centre.y)+"),Radius="+to_string(radius)+'.');

 }

void CCircle::Draw(Output* pOut) const
{
	//Call Output::DrawCirc to draw a Circle on the screen	
	pOut->DrawCirc(Start, End, FigGfxInfo, Selected);
}

 CFigure*CCircle::copy()
 {
	 CFigure*c=new CCircle(Start,End,FigGfxInfo);
	 return c;
 }

void CCircle::Transfer(Point To,Point Major)
{
	int X_diff=Major.x-centre.x;						//x coor. difference between major centre and the needed centre
	int Y_diff=Major.y-centre.y;						//y coor. difference between major centre and the needed centre
	centre.x=To.x-X_diff;	centre.y=To.y-Y_diff;		//moving the center of the figure with same coors. difference
	Start.x=centre.x-radius;							//locating Start,end points to draw 
	End.x=centre.x+radius;
	Start.y=centre.y;
	End.y=centre.y;
}
void CCircle::Save(ofstream &OutFile)
{
	OutFile<<CIRCLE<<'\t'<<ID<<'\t'<<Start.x<<'\t'<<Start.y<<'\t'<<End.x<<'\t'<<End.y<<'\t'
		<<to_number(FigGfxInfo.DrawClr)<<'\t';

	if( FigGfxInfo.isFilled == false )
		OutFile<<-1;
	else
		OutFile<<to_number(FigGfxInfo.FillClr);
	OutFile<<'\n';
}

bool CCircle::Load(ifstream &Infile)
{
	Infile>>ID>>Start.x>>Start.y>>End.x>>End.y;
	//calculate the center of the circle
	centre.x=(Start.x+End.x)/2;
	centre.y=(Start.y+End.y)/2;

	if( CFigure::Load(Infile) )	//to load draw & fill color
		return true;
	else
		return false;
}
