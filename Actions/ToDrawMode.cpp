#include"ToDrawMode.h"
#include"Action.h"
#include"..\ApplicationManager.h"

TO_DRAW_MODE::TO_DRAW_MODE(ApplicationManager*pApp) :Action(pApp)
{}

bool TO_DRAW_MODE::ReadActionParameters()//avoid abstarct class
{
	return true;
}

void TO_DRAW_MODE::Execute()
{
	Output*pOut = pManager->GetOutput();
	pOut->CreateDrawToolBar();
	pManager->Load_play();//to load figures
	pOut->PrintMessage("Back to draw mode");
}
