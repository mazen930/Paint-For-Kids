#include "Input.h"
#include "Output.h"


Input::Input(window* pW) 
{
	pWind = pW; //point to the passed window
}

void Input::GetPointClicked(int &x, int &y) const
{
	pWind->FlushMouseQueue();
	pWind->WaitMouseClick(x, y);	//Wait for mouse click
}

string Input::GetSrting(Output *pO) const 
{
	pWind->FlushKeyQueue();		//before doing anything, flush the key queue first
	string Label;
	char Key;
	keytype kt;
	unsigned int i=0;
	while(1)
	{
		kt=pWind->WaitKeyPress(Key);
		if(kt == ESCAPE )	//ESCAPE key is pressed
			return "";	//returns nothing as user has cancelled label
		
		if(kt == ARROW)
		{
			if(Key == 4)	//left arrow key is pressed
				if( i>0 )
					i--;
			if(Key == 6)	//right arrow key is pressed
				if ( i<Label.size() )
					i++;
		}

		if(kt == ASCII)
		{
			if(Key == 13 )	//ENTER key is pressed
				return Label;

			if((Key == 8) && (i >= 1))	//BackSpace is pressed
				Label.erase( Label.begin() + (--i) );
			else if(Key == 8)	//if BackSpace is pressed and there is nothing to delete,just do not do anything
				continue;
			else
				Label.insert( Label.begin()+(i++) , Key );
		}

		if (pO)
			pO->PrintMessage(Label);
	}
}

color Input::GetColorClicked(int x, int y)const
{
	return pWind->GetColor(x,y);
}


//This function reads the position where the user clicks to determine the desired action
ActionType Input::GetUserAction(int& X, int& Y) const
{
	pWind->FlushMouseQueue();		//Empty the mouse queue
	pWind->WaitMouseClick(X, Y);	//Get the coordinates of the user click

	//[1] User clicks on the drawing area
	if (Y >= UI.ToolBarHeight && Y < UI.height - UI.StatusBarHeight)
		return DRAWING_AREA;

	//[2] User clicks on the status bar
	else if (Y >= UI.height - UI.StatusBarHeight && Y < UI.height)
		return STATUS;

	//[3] If user clicks on the Toolbar
	else
	{
		if (UI.InterfaceMode == MODE_DRAW)	//GUI in the DRAW mode
		{
			//Check which Menu item was clicked
			//==> This assumes that menu items are lined up horizontally <==
			int ClickedItemOrder = (X / UI.MenuItemWidth);
			//Divide x coord of the point clicked by the menu item width (int division)
			//if division result is 0 ==> first item is clicked, if 1 ==> 2nd item and so on

			switch (ClickedItemOrder)
			{
			case ITM_LINE: return DRAW_LINE;
			case ITM_RECT: return DRAW_RECT;
			case ITM_CIRC: return DRAW_CIRC;
			case ITM_TRI: return DRAW_TRI;
			case ITM_SELECT: return SELECT;
			case ITM_COPY: return COPY;
			case ITM_CUT: return CUT;
			case ITM_PASTE: return PASTE;
			case ITM_ROTAE:return ROTATE;
			case ITM_DEL: return DEL;
			case ITM_SEND_TO_BACK: return SEND_TO_BACK;
			case ITM_BRING_TO_FRONT: return BRING_TO_FRONT;
			case ITM_FILLCOLOR: return CHNG_FILL_CLR;
			case ITM_DRAWCOLOR: return CHNG_DRAW_CLR;
			case ITM_SAVE: return SAVE;
			case ITM_LOAD: return LOAD;
			case ITM_PLAY_MODE: return TO_PLAY;
			case ITM_EXIT: return EXIT;

			default: return EMPTY;	//A click on empty place in desgin toolbar
			}
		}

		else if (UI.InterfaceMode == MODE_PLAY)	//GUI is in PLAY mode
		{

			int ClickedItemOrder = (X / UI.MenuItemWidth);
			switch (ClickedItemOrder)
			{
			case ITM_DRAWMODE: return TO_DRAW;
			case ITM_Figure_Fill_Color: return Figure_Fill_color;
			case ITM_Figure_Type:return Figure_type;
			case ITM_Figure_Type_and_Fill_Color: return Figure_type_and_Fill_Color;
			case ITM_EXIT_2:return EXIT;

			default:return EMPTY;
			}
		}

	}
}
/////////////////////////////////
	
Input::~Input()
{
}