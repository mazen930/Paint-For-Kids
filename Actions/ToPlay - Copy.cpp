#include "..\ApplicationManager.h"
#include "ToPlay.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "Action.h"
ToPlay::ToPlay(ApplicationManager*pApp):Action(pApp)
{

}

bool ToPlay::ReadActionParameters()
{
	return true;
}

void ToPlay::Execute()
{
	Output*pOut=pManager->GetOutput();
	if(ReadActionParameters())
	{
		pOut->CreatePlayToolBar();
		pOut->PrintMessage("Switch to play mode");
	}
}