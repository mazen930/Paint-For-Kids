#include<iostream>
#include"Figure_Type.h"
#include "Action.h"
#include"Select.h"
#include<cstdio>
#include<time.h>
#include"..\ApplicationManager.h"
#include"..\GUI\Input.h"
#include"..\GUI\Output.h"
#include"..\Figures\CCircle.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\CTriangle.h"
#include"..\Figures\CFigure.h"
#include<string.h>

using namespace std;
Figure_Type::Figure_Type(ApplicationManager * pApp) : Action(pApp)
{
	s1 = NULL;
	pManager->Load_play();
	pManager->UpdateInterface();
}

bool Figure_Type::ReadActionParameters()	//to avoid ABSTARCT CLASS
{
	return false;
}

void Figure_Type::Execute()
{

	Output* pOut = pManager->GetOutput();
	s1 = new Select(pManager);
	if (pManager->Get_figcount() == 0)
	{
		pOut->PrintMessage("Draw some figures first to play with them");
		return;
	}
	pManager->UnSelectAll();
	string *type = new string[pManager->Get_figcount()];
	bool flag[4] = { 0,0,0,0 };
	pManager->Get_ftypes(type);
	srand(time(0));
	int x = (rand() % pManager->Get_figcount()), w=0;
	int j;
	for ( j = 0; j < pManager->Get_figcount(); j++)//get random figure
	{
		if (j == x)
		{
			if (type[j] == "Circle")flag[0] = 1;
			else if (type[j] == "Line")flag[1] = 1;
			else if (type[j] == "Triangle")flag[2] = 1;
			else if (type[j] == "Rectangle")flag[3] = 1;

			pOut->PrintMessage("Pick all "+type[j]+'s');
			break;
		}

	}
	for (int i = 0; i < pManager->Get_figcount(); i++)// number of corrected figures
	{
		if (type[j] == type[i])
			w++;
	}
	CFigure *fig; 
	int Correct = 0; int Incorrect = 0; 
	int count = pManager->Get_figcount();
	for (int i = 0; (i <count)&&(Correct<w); i++)
	{
		double z1, z2;
		s1->select_play(z1,z2);
		fig = pManager->Get_Selected_Fig();
		if (fig == NULL&&z2 < UI.ToolBarHeight&&z1 <5 * UI.MenuItemWidth)
		{
			return;
		}
		else if (fig == NULL&&z2>= 0&&z1>=0)
		{
			i--;
			continue;
		}
		if (dynamic_cast<CCircle*>(fig)) if (flag[0])Correct++; else Incorrect++;
		else if (dynamic_cast<CLine*>(fig)) if (flag[1])Correct++; else Incorrect++;
		else if (dynamic_cast<CTriangle*>(fig))if (flag[2])Correct++; else Incorrect++;
		else if (dynamic_cast<CRectangle*>(fig))if (flag[3])Correct++; else Incorrect++;
		pManager->Delete_selected_figs();
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
		pOut->PrintMessage("Correct : "+to_string(Correct)+"  Incorrect : "+to_string(Incorrect));
	}		
	pOut->PrintMessage("Game Over \\ Correct : " + to_string(Correct) + "  Incorrect : " + to_string(Incorrect) );
	delete[]type;
}

