#include "AddTriAction.h"
#include "..\Figures\CTriangle.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

AddTriAction::AddTriAction(ApplicationManager * pApp):Action(pApp)
{}

bool AddTriAction::ReadActionParameters() 
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	ActionType ActType;

	pOut->PrintMessage("New Triangle: Click at first corner");

	//Read 1st corner and store in point P1	and recognize where the user clicks
	ActType=pIn->GetUserAction(P1.x, P1.y);
	if(ActType==DRAWING_AREA)		//if the user clicked on the drawing area
	{
		pOut->PrintMessage("New Triangle: Click at second corner");

		//Read 2nd corner and store in point P2	and recognize where the user clicks
		ActType=pIn->GetUserAction(P2.x, P2.y);
		if(ActType==DRAWING_AREA)		//if the user clicked on the drawing area
		{
			pOut->PrintMessage("New Triangle: Click at third corner");

			//Read 3rd corner and store in point P3	and recognize where the user clicks
			ActType=pIn->GetUserAction(P3.x, P3.y);
			if(ActType==DRAWING_AREA)		//if the user clicked on the drawing area
			{
				if( pOut->CrntIsFilled() )	//if the user chose a filling color to draw the figures with
				{
					TriGfxInfo.isFilled=true;
					TriGfxInfo.FillClr = pOut->getCrntFillColor();
				}
				else
					TriGfxInfo.isFilled = false;	
				//get drawing, filling colors and pen width from the interface
				TriGfxInfo.DrawClr = pOut->getCrntDrawColor();
				TriGfxInfo.BorderWdth = pOut->getCrntPenWidth();

				return true;
			}
		}
	}
	pManager->ExecuteAction(ActType);	//if the user didin't click on the drawing area, then execute what the user clicked on 
	return false;
}

//Execute the action
void AddTriAction::Execute() 
{
	Output* pOut = pManager->GetOutput();
	//This action needs to read some parameters first
	if( ReadActionParameters() )
	{
		//Create a Triangle with the parameters read from the user
		CTriangle *T=new CTriangle(P1, P2, P3, TriGfxInfo);

		//Add the Triangle to the list of figures
		pManager->AddFigure(T);

		pOut->FlushCrntMsg();	//to clear the message in the status bar
	}
}
