#include "..\ApplicationManager.h"
#include "ToPlay.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"
#include "Action.h"

ToPlay::ToPlay(ApplicationManager*pApp):Action(pApp)
{}

bool ToPlay::ReadActionParameters()//avoid abstract class
{
	return true;
}

void ToPlay::Execute()
{
	Output*pOut=pManager->GetOutput();
	pOut->CreatePlayToolBar();
	pOut->PrintMessage("Switch to play mode");

	ofstream savefile;
	savefile.open("temp/temp.txt");
	pManager->SaveAll(savefile);		//saving information to find it when returning 
	savefile.close();
}