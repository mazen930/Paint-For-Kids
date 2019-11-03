#include "Cut.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Cut::Cut(ApplicationManager*pApp):Action(pApp)
{}

bool Cut::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	vector<CFigure*>&selectedfigs=pManager->Get_Selected_Figs();

	if(selectedfigs.size()!=0)		//if there are selected figures
	{
		return true;
	}

	pOut->PrintMessage("Cut Action: No selected figure. select figures first, then cut them");
	return false;
}

void Cut::Execute()
{
	Output* pOut = pManager->GetOutput();
	Input*pIn=pManager->GetInput();
	ActionType ActType;

	if(ReadActionParameters())
	{
		pManager->clearClipboard();
		pManager->copytoclipboard();		//takes a copy from the selected figures
		pManager->Delete_selected_figs();
		pOut->PrintMessage("Selected figure(s) is cut");
	}
}
