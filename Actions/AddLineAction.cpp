#include "AddLineAction.h"
#include "..\Figures\CLine.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddLineAction::AddLineAction(ApplicationManager * pApp):Action(pApp)
{}

bool AddLineAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ActionType ActType;

	pOut->PrintMessage("New Line: Click at start point");

	//Read 1st point and store in point P1 and recognize where the user clicks
	ActType=pIn->GetUserAction(P1.x, P1.y);
	if(ActType==DRAWING_AREA)		//if the user clicked on the drawing area
	{
		pOut->PrintMessage("New Line: Click at end point");

		//Read 2nd point and store in point P2 and recognize where the user clicks
		ActType=pIn->GetUserAction(P2.x, P2.y);
		if(ActType==DRAWING_AREA)		//if the user clicked on the drawing area
		{
			//get drawing, filling colors and pen width from the interface
			LineGfxInfo.DrawClr = pOut->getCrntDrawColor();
			LineGfxInfo.BorderWdth = pOut->getCrntPenWidth();

			return true;
		}
	}
	pManager->ExecuteAction(ActType);	//if the user didin't click on the drawing area, then execute what the user clicked on 
	return false;
}

//Execute the action
void AddLineAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	if( ReadActionParameters() )
	{
		//Create a Line with the parameters read from the user
		CLine *L=new CLine(P1, P2, LineGfxInfo);

		//Add the Line to the list of figures
		pManager->AddFigure(L);

		pOut->FlushCrntMsg();	//to clear the message in the status bar
	}
}
