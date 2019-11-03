#include "SendToBack.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
SendToBack::SendToBack(ApplicationManager*pApp):Action(pApp)
{
}
bool SendToBack::ReadActionParameters()
{
	vector<CFigure*>&selectedFigs=pManager->Get_Selected_Figs();
	
	if(selectedFigs.size()==1)		//this actions requires only one figure
	{
		return true;
	}

	Output* pOut = pManager->GetOutput();
	if(selectedFigs.size()==0)
	{
		pOut->PrintMessage("Send-to-back Action: No selected figure. select a figure first, then send it to back");
		return false;
	}

	pOut->PrintMessage("Send-to-back Action: there is more than one figure selected. select only one figure, then send it to back");
	return false;
}
void SendToBack::Execute()
{
	Output* pOut = pManager->GetOutput();
	if(ReadActionParameters())
	{
		pManager->send_to_back();
		pOut->PrintMessage("The figure is sent to back");
		pManager->UnSelectAll();		
	}
}