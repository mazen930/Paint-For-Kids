#include"ChngFillClrAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChngFillClrAction::ChngFillClrAction(ApplicationManager* pApp):Action(pApp)
{}

bool ChngFillClrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	int x,y;

	pOut->CreateColorPallet();
	pOut->PrintMessage("Change fill color Action: Pick a color");

	pIn->GetPointClicked(x,y);

	if ( y >= 0 && y < UI.ToolBarHeight) //If user clicks on the Toolbar
	{
		FillColor=pIn->GetColorClicked(x,y);
		pOut->PrintMessage("You picked "+ to_string(FillColor)+" color");
		return true;
	}

	return false;
}

void ChngFillClrAction::Execute()
{
	Output* pOut = pManager->GetOutput();

	vector<CFigure*>& SelectedFig = pManager->Get_Selected_Figs();
	int temp=SelectedFig.size();
	if( ReadActionParameters() )
	{
		if( temp == 0 )		//if there is no selected figure, change current color
			pOut->setCrntFillColor(FillColor);
		else							//if there is a selected figure, change its color
		{
			for(int i=0;i<temp;i++)
			SelectedFig[i]->ChngFillClr(FillColor);
			pManager->UnSelectAll();	//remove selection after changing color
		}

		pOut->CreateDrawToolBar();		//back to draw mode after changing the color
	}
	else
		Execute();		//if the user didin't click on a color, then read repeate the process again
}