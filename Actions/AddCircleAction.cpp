#include "AddCircleAction.h"
#include "..\Figures\CCircle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddCircleAction::AddCircleAction(ApplicationManager * pApp):Action(pApp)
{}

bool AddCircleAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ActionType ActType;

	pOut->PrintMessage("New Circle: Click at start point of the circle diameter");

	//Read 1st point and store in point P1 and recognize where the user clicks
	ActType=pIn->GetUserAction(P1.x, P1.y);
	if(ActType==DRAWING_AREA)		//if the user clicked on the drawing area
	{
		pOut->PrintMessage("New Circle: Click at end point of the circle diameter");

		//Read 2nd point and store in point P2 and recognize where the user clicks
		ActType=pIn->GetUserAction(P2.x, P2.y);
		if(ActType==DRAWING_AREA)		//if the user clicked on the drawing area
		{
			if( pOut->CrntIsFilled() )	//if the user chose a filling color to draw the figures with
			{
				CircleGfxInfo.isFilled=true;
				CircleGfxInfo.FillClr = pOut->getCrntFillColor();
			}
			else
				CircleGfxInfo.isFilled = false;	
			//get drawing, filling colors and pen width from the interface
			CircleGfxInfo.DrawClr = pOut->getCrntDrawColor();
			CircleGfxInfo.BorderWdth = pOut->getCrntPenWidth();

			return true;
		}
	}
	pManager->ExecuteAction(ActType);	//if the user didin't click on the drawing area, then execute what the user clicked on 
	return false;
}

//Execute the action
void AddCircleAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	if( ReadActionParameters() )
	{
	
		//Create a Circle with the parameters read from the user
		CCircle *C=new CCircle(P1, P2, CircleGfxInfo);

		//Add the Circle to the list of figures
		pManager->AddFigure(C);

		pOut->FlushCrntMsg();	//to clear the message in the status bar
	}
}
