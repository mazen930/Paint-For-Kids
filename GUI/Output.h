#ifndef OUPTUT_H
#define OUPTUT_H
#include "Input.h"

class Output	//The application manager should have a pointer to this class
{
private:	
	window* pWind;	//Pointer to the Graphics Window
	image ToolbarImage;	//An image to store the toolbar in it
	string CrntMsg;		//a string to store current message in
	
public:
	Output();		

	window* CreateWind(int, int, int , int) const; //creates the application window
	void CreateDrawToolBar();	//creates Draw mode toolbar & menu
	void CreatePlayToolBar();	//creates Play mode toolbar & menu
	void CreateColorPallet() const; //creates Color node toolbar
	void CreateStatusBar() const;	//create the status bar

	Input* CreateInput() const; //creates a pointer to the Input object	
	void ClearStatusBar() const;	//Clears the status bar
	void ClearDrawArea() const;	//Clears the drawing area
	void ClearToolBar() const; //Clears Draw toolbar
	
	// -- Figures Drawing functions

	//Draws a rectangle
	void DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected=false) const;
	//Draws a Line from P1 to P2
	void DrawLn(Point P1,Point P2,GfxInfo LineGfxInfo,bool selected=false)const;
	//Draws a triangle with virtices P1 & P2 & P3
	void DrawTri(Point P1,Point P2,Point P3,GfxInfo TriGfxInfo,bool selected=false)const;
	//Draws a circle between P1 & P2
	void DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected=false) const;  

	void PrintMessage(const string& msg);	//Print a message on Status bar

	void setCrntDrawColor(const color& )const;
	color getCrntDrawColor() const;	//get current drwawing color

	void setCrntFillColor(const color& )const;
	color getCrntFillColor() const;	//get current filling color

	int getCrntPenWidth() const;		//get current pen width

	void setCrntFilled(bool f)const;
	bool CrntIsFilled()const;	//check if the current figures will be filled or not

	void FlushCrntMsg();
	string getCrntMsg()const;
	
	~Output();
};

#endif