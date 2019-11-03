#include"ChngDrawClrAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

ChngDrawClrAction::ChngDrawClrAction(ApplicationManager* pApp):Action(pApp)
{}

bool ChngDrawClrAction::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	int x,y;

	pOut->CreateColorPallet();
	pOut->PrintMessage("Change draw color Action: Pick a color");

	pIn->GetPointClicked(x,y);

	if ( y >= 0 && y < UI.ToolBarHeight) //If user clicks on the Toolbar
	{
		DrawColor=pIn->GetColorClicked(x,y);
		pOut->PrintMessage("You picked "+ to_string(DrawColor)+" color");
		return true;
	}

	return false;

}

void ChngDrawClrAction::Execute()
{
	Output* pOut = pManager->GetOutput();
	vector<CFigure*>& SelectedFigs = pManager->Get_Selected_Figs();
	int temp=SelectedFigs.size();
	if( ReadActionParameters() )
	{
		if( temp == 0 )		//if there is no selected figure, change current color
			pOut->setCrntDrawColor(DrawColor);
		else							//if there is a selected figure, change its color
		{
			for(int i=0;i<temp;i++)
			SelectedFigs[i]->ChngDrawClr(DrawColor);
			pManager->UnSelectAll();	//remove selection after changing color
		}

		pOut->CreateDrawToolBar();		//back to draw mode after changing the color
	}
	else
		Execute();		//if the user didin't click on a color, then read repeate the process again
}