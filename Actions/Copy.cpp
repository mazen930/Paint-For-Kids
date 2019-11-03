#include "Copy.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"

Copy::Copy(ApplicationManager*pApp):Action(pApp)
{}

bool Copy::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	vector<CFigure*>&selectedFigs=pManager->Get_Selected_Figs();

	if(selectedFigs.size()==0)	//if there are no selected figures
	{
		pOut->PrintMessage("Copy Action: No selected figure, select a figure first then copy it");
		return false;
	}

	return true;
}

void Copy::Execute()
{
	Output* pOut = pManager->GetOutput();
	if(ReadActionParameters())
	{
		pManager->clearClipboard();
		pManager->copytoclipboard();		//takes a copy from the selected figures
		pManager->UnSelectAll();
		pOut->PrintMessage("Selected figure(s) are copied");
	}
}

