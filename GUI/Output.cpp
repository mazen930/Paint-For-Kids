#include "Output.h"

Output::Output()
{
	//Initialize user interface parameters
	UI.InterfaceMode = MODE_DRAW;
	
	UI.width = 1250;
	UI.height = 650;
	UI.wx = 5;
	UI.wy = 5;

	
	UI.StatusBarHeight = 50;
	UI.ToolBarHeight = 50;
	UI.MenuItemWidth = 60;
	
	UI.DrawColor = BLACK;	//Drawing color
	UI.FillColor = GREEN;	//Filling color
	UI.MsgColor = RED;		//Messages color
	UI.BkGrndColor = LIGHTGOLDENRODYELLOW;	//Background color
	UI.HighlightColor = MAGENTA;	//This color should NOT be used to draw figures. use if for highlight only
	UI.StatusBarColor = TURQUOISE;
	UI.PenWidth = 5;	//width of the figures frames
	UI.IsFilled=false;	//defualt is not filled
	
	//Create the output window
	pWind = CreateWind(UI.width, UI.height, UI.wx, UI.wy);
	//Change the title
	pWind->ChangeTitle("Paint for Kids - Programming Techniques Project");
	
	CreateDrawToolBar();
	
	CreateStatusBar();
}


Input* Output::CreateInput() const
{
	Input* pIn = new Input(pWind);
	return pIn;
}

//======================================================================================//
//								Interface Functions										//
//======================================================================================//

window* Output::CreateWind(int w, int h, int x, int y) const
{ 
	window* pW = new window(w, h, x, y);
	pW->SetBrush(UI.BkGrndColor);
	pW->SetPen(UI.BkGrndColor, 1);
	pW->DrawRectangle(0, UI.ToolBarHeight, w, h);	
	return pW;
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateStatusBar() const
{
	pWind->SetPen(UI.StatusBarColor);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::ClearStatusBar()const
{
	//Clear Status bar by drawing a filled rectangle with status bar color
	pWind->SetPen(UI.StatusBarColor);
	pWind->SetBrush(UI.StatusBarColor);
	pWind->DrawRectangle(0, UI.height - UI.StatusBarHeight, UI.width, UI.height);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::CreateDrawToolBar()
{
	UI.InterfaceMode = MODE_DRAW;

	//Draw a White rectangle to clear the toolbar
	pWind->SetPen(WHITE);
	pWind->SetBrush(WHITE);
	pWind->DrawRectangle(0,0,UI.width,UI.ToolBarHeight);


	//You can draw the tool bar icons in any way you want.
	//Below is one possible way
	
	//First prepare List of images for each menu item
	//To control the order of these images in the menu, 
	//reoder them in UI_Info.h ==> enum DrawMenuItem
	string MenuItemImages[DRAW_ITM_COUNT];
	MenuItemImages[ITM_LINE] = "images\\MenuItems\\line.jpg";
	MenuItemImages[ITM_RECT] = "images\\MenuItems\\rectangle.jpg";
	MenuItemImages[ITM_CIRC] = "images\\MenuItems\\circle.jpg";
	MenuItemImages[ITM_TRI] = "images\\MenuItems\\triangle.jpg";
	MenuItemImages[ITM_SELECT] = "images\\MenuItems\\select.jpg";
	MenuItemImages[ITM_COPY] = "images\\MenuItems\\copy.jpg";
	MenuItemImages[ITM_CUT] = "images\\MenuItems\\cut.jpg";
	MenuItemImages[ITM_PASTE] = "images\\MenuItems\\paste.jpg";
	MenuItemImages[ITM_ROTAE] = "images\\MenuItems\\rotate.jpg";
	MenuItemImages[ITM_DEL] = "images\\MenuItems\\delete.jpg";
	MenuItemImages[ITM_FILLCOLOR] = "images\\MenuItems\\Menu_fillcolor.jpg";
	MenuItemImages[ITM_DRAWCOLOR] = "images\\MenuItems\\Menu_drawcolor.jpg";
	MenuItemImages[ITM_SEND_TO_BACK] = "images\\MenuItems\\send_to_back.jpg";
	MenuItemImages[ITM_BRING_TO_FRONT] = "images\\MenuItems\\bring_to_front.jpg";
    MenuItemImages[ITM_SAVE] = "images\\MenuItems\\save.jpg";
	MenuItemImages[ITM_LOAD] = "images\\MenuItems\\load.jpg";
	MenuItemImages[ITM_PLAY_MODE] = "images\\MenuItems\\playmode.jpg";
	MenuItemImages[ITM_EXIT] = "images\\MenuItems\\Exit.jpg";

	//Draw menu item one image at a time
	for(int i=0; i<DRAW_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImages[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);



	//Draw a line under the toolbar
	pWind->SetPen(RED, 3);
	pWind->DrawLine(0, UI.ToolBarHeight+1, UI.width, UI.ToolBarHeight+1);

	//store the toolbar and the line under it in an image
	pWind->StoreImage(ToolbarImage, 0, 0, (unsigned short)(UI.width), (unsigned short)(UI.ToolBarHeight+3) );
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::CreateColorPallet() const
{
	int ColorItemWidth=UI.width/ColorsNum;
	pWind->SetPen(LIGHTGRAY);
	for(int i=0; i<ColorsNum; i++)
	{
		pWind->SetBrush(colors[i]);
		pWind->DrawRectangle(i*ColorItemWidth, 0, ColorItemWidth+i*ColorItemWidth, UI.ToolBarHeight);
	}

}

void Output::CreatePlayToolBar()
{
	UI.InterfaceMode = MODE_PLAY;

	//Draw a white rectangle to clear the toolbar
	pWind->SetBrush(WHITE);
	pWind->SetPen(WHITE);
	pWind->DrawRectangle(0, 0, UI.width, UI.ToolBarHeight, FILLED);

	string MenuItemImage[PLAY_ITM_COUNT];
	MenuItemImage[ITM_DRAWMODE] = "images\\MenuItems\\drawmode.jpg";
	MenuItemImage[ITM_EXIT_2] = "images\\MenuItems\\Exit.jpg";
	MenuItemImage[ITM_Figure_Type] = "images\\MenuItems\\figure_type.jpg";
	MenuItemImage[ITM_Figure_Fill_Color] = "images\\MenuItems\\figure_color.jpg";
	MenuItemImage[ITM_Figure_Type_and_Fill_Color] = "images\\MenuItems\\figure_T&C.jpg";

	//Draw menu item one image at a time
	for (int i = 0; i<PLAY_ITM_COUNT; i++)
		pWind->DrawImage(MenuItemImage[i], i*UI.MenuItemWidth, 0, UI.MenuItemWidth, UI.ToolBarHeight);

	//store the toolbar and the line under it in an image
	pWind->StoreImage(ToolbarImage, 0, 0, (unsigned short)(UI.width), (unsigned short)(UI.ToolBarHeight+3) );
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearDrawArea() const
{
	//Draw a rectangle with the background color under the line of the toolbar and before the status bar
	pWind->SetPen(UI.BkGrndColor, 1);
	pWind->SetBrush(UI.BkGrndColor);
	pWind->DrawRectangle(0, UI.ToolBarHeight+3 , UI.width, UI.height - UI.StatusBarHeight);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::ClearToolBar() const
{
	//Draw the toolbar image stored in the beginning of the program to clear the Draw toolbar area
	pWind->DrawImage(ToolbarImage, 0, 0);
}
//////////////////////////////////////////////////////////////////////////////////////////

void Output::PrintMessage(const string& msg)	//Prints a message on status bar
{
	ClearStatusBar();	//First clear the status bar
	CrntMsg.clear();
	CrntMsg = msg;

	pWind->SetPen(UI.MsgColor, 50);
	pWind->SetFont(20, BOLD , BY_NAME, "Arial");   
	pWind->DrawString(10, UI.height - (int)(UI.StatusBarHeight/1.5), msg);
}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::setCrntDrawColor(const color& c)const
{	UI.DrawColor = c;	}

color Output::getCrntDrawColor() const	//get current drwawing color
{	return UI.DrawColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
void Output::setCrntFillColor(const color& c)const
{
	UI.IsFilled=true;
	UI.FillColor = c;	
}

color Output::getCrntFillColor() const	//get current filling color
{	return UI.FillColor;	}
//////////////////////////////////////////////////////////////////////////////////////////
	
int Output::getCrntPenWidth() const		//get current pen width
{	return UI.PenWidth;	 }
//////////////////////////////////////////////////////////////////////////////////////////
void Output::setCrntFilled(bool f)const
{	UI.IsFilled=f; }

bool Output::CrntIsFilled()const
{	return UI.IsFilled;	 }

void Output::FlushCrntMsg()
{ CrntMsg.clear();	}

string Output::getCrntMsg()const
{	return CrntMsg;	}

//======================================================================================//
//								Figures Drawing Functions								//
//======================================================================================//

void Output::DrawLn(Point p1,Point p2,GfxInfo LineGfxInfo,bool selected)const
{
	color DrawingClr;
	if(selected)
		DrawingClr=UI.HighlightColor;
	else
		DrawingClr=LineGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr,LineGfxInfo.BorderWdth);

	pWind->DrawLine(p1.x, p1.y, p2.x, p2.y);
}


void Output::DrawTri(Point p1,Point p2,Point p3,GfxInfo TriGfxInfo,bool selected)const//Draw a triangle
{
	color DrawingClr;
	if(selected)
		DrawingClr=UI.HighlightColor;
	else
		DrawingClr=TriGfxInfo.DrawClr;
	pWind->SetPen(DrawingClr,TriGfxInfo.BorderWdth);
	drawstyle style;
	if(TriGfxInfo.isFilled)
		{
			style=FILLED;
			pWind->SetBrush(TriGfxInfo.FillClr);
		}
	else
		style=FRAME;
		
	pWind->DrawTriangle(p1.x,p1.y,p2.x,p2.y,p3.x,p3.y,style);
}

void Output::DrawRect(Point P1, Point P2, GfxInfo RectGfxInfo, bool selected) const
{
	color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = RectGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,RectGfxInfo.BorderWdth);
	drawstyle style;
	if (RectGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(RectGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	
	pWind->DrawRectangle(P1.x, P1.y, P2.x, P2.y, style);

}

void Output::DrawCirc(Point P1, Point P2, GfxInfo CircGfxInfo, bool selected) const		//Draws a circle between P1 & P2
{
		color DrawingClr;
	if(selected)	
		DrawingClr = UI.HighlightColor; //Figure should be drawn highlighted
	else			
		DrawingClr = CircGfxInfo.DrawClr;
	
	pWind->SetPen(DrawingClr,CircGfxInfo.BorderWdth);
	drawstyle style;
	if (CircGfxInfo.isFilled)	
	{
		style = FILLED;		
		pWind->SetBrush(CircGfxInfo.FillClr);
	}
	else	
		style = FRAME;

	int radius=int(sqrt(pow((P2.x-P1.x),2)+pow((P2.y-P1.y),2))/2+0.5);		//half the distance between the two points 
																			//(the 0.5 is for approximation)
	Point center;
	center.x=(P1.x+P2.x)/2;
	center.y=(P1.y+P2.y)/2;

	pWind->DrawCircle(center.x, center.y, radius, style);
}
//////////////////////////////////////////////////////////////////////////////////////////

Output::~Output()
{
	delete pWind;
}