#include "Select.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Select::Select(ApplicationManager* pApp):Action(pApp)
{
	Selected=NULL;
}

bool Select::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ActionType ActType;

	pOut->PrintMessage("Select a Shape");
	Point P;
	//Read  point and store in point P and recognize where the user clicks
	ActType=pIn->GetUserAction(P.x, P.y);
	pOut->FlushCrntMsg();	//to clear the message on status bar
	if(ActType==DRAWING_AREA)		//if the user clicked on the drawing area
	{
		Selected=pManager->GetFigure(P.x,P.y);
		if(Selected!=NULL)	//there is a figure selected
			return true;
		return false;
	}

	pManager->ExecuteAction(ActType);	//if the user didin't click on the drawing area, then execute what the user clicked on 
	return false;
}

void Select::Execute()
{
	Output* pOut = pManager->GetOutput();
	if(ReadActionParameters())	
	{
		if(!(Selected->IsSelected()))   //if the selected figure wasn't selected before, then select it
		{
			Selected->SetSelected(true);
			pManager->Set_Selected_Fig(Selected);
			Selected->PrintInfo(pOut);
			Selected=NULL;
		}
     	else                             	//if the selected figure was selected before, then unselect it
		{
			Selected->SetSelected(false);
			pManager->UnSelect(Selected->Get_ID());
			Selected=NULL;
	    }
	}
}

void Select::select_play(double &z1, double &z2)//diffrent version of select function to play mode
{
	Point P;
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	bool temp = false;
	ActionType ActType;
	//Read  point and store in point P and recognize where the user clicks
	ActType = pIn->GetUserAction(P.x, P.y);
	pOut->FlushCrntMsg();	//to clear the message on status bar
	if (ActType == DRAWING_AREA)		//if the user clicked on the drawing area
	{
		Selected = pManager->GetFigure(P.x, P.y);
		if (Selected != NULL)	//there is a figure selected
			temp = true;
	}

	if (temp && !(Selected->IsSelected()))	//if the selected figure wasn't selected before, then select it
	{
		pManager->UnSelectAll();
		Selected->SetSelected(true);
		pManager->Set_Selected_Fig(Selected);
		Selected = NULL;
	}
	z1 = P.x;
	z2 = P.y;

}
