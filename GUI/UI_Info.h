#ifndef UI_INFO_H
#define UI_INFO_H

#include "..\CMUgraphicsLib\CMUgraphics.h"

//User Interface information file.
//This file contains info that is needed by Input and Output classes to
//handle the user interface

enum GUI_MODE	//Graphical user interface mode
{
	MODE_DRAW,	//Drawing mode (startup mode)
	MODE_PLAY	//Playing mode
};

enum DrawMenuItem //The items of the Draw menu (you should add more items)
{
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	ITM_LINE,
	ITM_RECT,		//Recangle item in menu
	ITM_CIRC,       //Circle item in menu
	ITM_TRI,
	ITM_SELECT,
	ITM_COPY,
	ITM_CUT,
	ITM_PASTE,
	ITM_ROTAE,
	ITM_DEL,
	ITM_FILLCOLOR,
	ITM_DRAWCOLOR,
	ITM_SEND_TO_BACK,
	ITM_BRING_TO_FRONT,
	ITM_SAVE,
	ITM_LOAD,
	ITM_PLAY_MODE,


	ITM_EXIT,		//Exit item
	
	DRAW_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};


enum PlayMenuItem //The items of the Play menu 
{
	
	ITM_Figure_Type,
	ITM_Figure_Fill_Color,
	ITM_Figure_Type_and_Fill_Color,//game
	ITM_DRAWMODE,	//draw mode item
	ITM_EXIT_2,
	//Note: Items are ordered here as they appear in menu
	//If you want to change the menu items order, change the order here
	
	PLAY_ITM_COUNT		//no. of menu items ==> This should be the last line in this enum
	
};


const int ColorsNum=20;
const color colors[ColorsNum]={BLACK,WHITE,RED,GREEN,BLUE,YELLOW,BROWN,ORANGE,HOTPINK,PURPLE,
		DARKGREEN,DARKGRAY,DARKORANGE,VIOLET,NAVY,DARKGOLDENROD,DARKTURQUOISE,GOLD,DARKSALMON,DARKCYAN};

__declspec(selectany) //This line to prevent "redefinition error"

struct UI_Info	//User Interface Info.
{
	GUI_MODE InterfaceMode;
	
	int	width, height,	    //Window width and height
		wx , wy,			//Window starting coordinates
		StatusBarHeight,	//Status Bar Height
		ToolBarHeight,		//Tool Bar Height (distance from top of window to bottom line of toolbar)
		MenuItemWidth;		//Width of each item in toolbar menu
	

	color DrawColor;		//Drawing color
	color FillColor;		//Filling color
	color HighlightColor;	//Highlighting color
	color MsgColor;			//Messages color
	color BkGrndColor;		//Background color
	color StatusBarColor;	//Status bar color
	int PenWidth;			//width of the pen that draws shapes
	bool IsFilled;
	/// Add more members if needed
	
}UI;	//create a global object UI

#endif