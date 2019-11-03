#include "AddRectAction.h"
#include "..\Figures\CRectangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddRectAction::AddRectAction(ApplicationManager * pApp):Action(pApp)
{}

bool AddRectAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ActionType ActType;

	pOut->PrintMessage("New Rectangle: Click at first corner");

	//Read 1st corner and store in point P1	and recognize where the user clicks
	ActType=pIn->GetUserAction(P1.x, P1.y);
	if(ActType==DRAWING_AREA)		//if the user clicked on the drawing area
	{
		pOut->PrintMessage("New Rectangle: Click at second corner");

		//Read 2nd corner and store in point P2	and recognize where the user clicks
		ActType=pIn->GetUserAction(P2.x, P2.y);
		if(ActType==DRAWING_AREA)		//if the user clicked on the drawing area
		{
			if( pOut->CrntIsFilled() )	//if the user chose a filling color to draw the figures with
			{
				RectGfxInfo.isFilled=true;
				RectGfxInfo.FillClr = pOut->getCrntFillColor();
			}
			else
				RectGfxInfo.isFilled = false;	
			//get drawing, filling colors and pen width from the interface
			RectGfxInfo.DrawClr = pOut->getCrntDrawColor();
			RectGfxInfo.BorderWdth = pOut->getCrntPenWidth();

			return true;
		}
	}
	pManager->ExecuteAction(ActType);	//if the user didin't click on the drawing area, then execute what the user clicked on 
	return false;
}

//Execute the action
void AddRectAction::Execute() 
{
	Output* pOut = pManager->GetOutput();

	//This action needs to read some parameters first
	if( ReadActionParameters() )
	{
		//Create a rectangle with the parameters read from the user
		CRectangle *R=new CRectangle(P1, P2, RectGfxInfo);

		//Add the rectangle to the list of figures
		pManager->AddFigure(R);

		pOut->FlushCrntMsg();	//to clear the message in the status bar
	}
}
