#include "Rotate.h"
#include"..\ApplicationManager.h"
#include"..\Figures\CLine.h"
Rotate::Rotate(ApplicationManager* pApp)
	:Action(pApp)
{
}

bool Rotate::ReadActionParameters()
{
	vector<CFigure*>&selectedFigs = pManager->Get_Selected_Figs();
	if (selectedFigs.size() != 0)		//if there are selected figures
	{
		return true;
	}

	return false;
}


void Rotate::Execute()
{
	Output*pOut=pManager->GetOutput();
	vector<CFigure*>&fig = pManager->Get_Selected_Figs();
	if(ReadActionParameters())
	for (int i = 0; i < fig.size(); i++)
	{
		fig[i]->Rotates();
	}
	else
		pOut->PrintMessage("Rotate Action: No selected figure. select a figure first, then rotate it");
}
