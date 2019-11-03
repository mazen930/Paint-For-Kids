#include"Delete.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"
Delete::Delete(ApplicationManager*pApp):Action(pApp)
{}

bool Delete::ReadActionParameters()
{
	vector<CFigure*>& vec=pManager->Get_Selected_Figs();
	if(vec.size()!=0)	//if there are selected figures
		return true;

	Output* pOut = pManager->GetOutput();
	pOut->PrintMessage("Delete Action: Please select figures first, then delete them");
	return false;
}

void Delete::Execute()
{
	Output* pOut = pManager->GetOutput();
	if(ReadActionParameters())
	{
		pManager->Delete_selected_figs();
		pOut->FlushCrntMsg();
	}
}