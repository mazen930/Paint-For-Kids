#include "Paste.h"
#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"


Paste::Paste(ApplicationManager*pApp):Action(pApp)
{
	Mcentre.x=0;
	Mcentre.y=0;
}

bool Paste::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();

	vector<CFigure*>&Clipboard=pManager->GetClipboard();
	int size=Clipboard.size();

	if(size==0)
	{
		pOut->PrintMessage("Paste Action: copy or cut figures first, then paste them");
		return false;
	}

	Input*pIn=pManager->GetInput();
	ActionType ActType;

	pOut->PrintMessage("Click to paste");
	ActType=pIn->GetUserAction(pp.x, pp.y);

	if (ActType==DRAWING_AREA)
	{
		for(int i=0;i<size;i++)
		{
			Mcentre.x+=Clipboard[i]->getcentre_X();
			Mcentre.y+=Clipboard[i]->getcentre_Y();
		}
		Mcentre.x/=size;
		Mcentre.y/=size;
		return true;
	}

	pManager->ExecuteAction(ActType);	//if the user didin't click on the drawing area, then execute what the user clicked on 
	return false;
}

void Paste::Execute()
{
	Output* pOut = pManager->GetOutput();

	if(ReadActionParameters())
	{	
		pManager->AddPastedFigure(pp,Mcentre);  //adds the figures of the clipboard to the figures list
		pOut->PrintMessage("Selected figure(s) is pasted");
	}
}
