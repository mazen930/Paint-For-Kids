#include "BringToFront.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
BringToFront::BringToFront(ApplicationManager*pApp):Action(pApp)
{}

bool BringToFront::ReadActionParameters()
{
	vector<CFigure*>&selectedFigs=pManager->Get_Selected_Figs();		//Selected figs
	if(selectedFigs.size()==1)		//the actions requires one figure
	{
		return true;
	}

	Output* pOut = pManager->GetOutput();

	if(selectedFigs.size()==0)
	{
		pOut->PrintMessage("Bring-to-front Action: No selected figure. select a figure first, then bring it to front");
		return false;
	}

	pOut->PrintMessage("Bring-to-front Action: there is more than one figure selected. select only one figure, then bring it to front");
	return false;
}

void BringToFront::Execute()
{
	Output* pOut = pManager->GetOutput();
	if(ReadActionParameters())
	{
		pManager->bring_to_front();
		pOut->PrintMessage("The figure is brought to front");
		pManager->UnSelectAll();		//remove selection
	}
}