#include"Figure_Type_and_Fill_Color.h"
#include"..\ApplicationManager.h"
#include"..\GUI\Output.h"
#include"..\GUI\Input.h"
#include"Select.h"
#include<time.h>
#include"..\Figures\CCircle.h"
#include"..\Figures\CFigure.h"
#include"..\Figures\CLine.h"
#include"..\Figures\CRectangle.h"
#include"..\Figures\CTriangle.h"

Figure_Type_and_Fill_Color::Figure_Type_and_Fill_Color(ApplicationManager * pApp)
	:Action(pApp)
{
	pManager->Load_play();
	pManager->UpdateInterface();
}

bool Figure_Type_and_Fill_Color::ReadActionParameters()
{
	return true;
}

void Figure_Type_and_Fill_Color::Execute()
{
	Output* pOut = pManager->GetOutput();
	if (pManager->Get_figcount() == 0)
	{
		pOut->PrintMessage("Draw some figures first to play with them");
		return;
	}
	pManager->UnSelectAll();
	struct Index *index = new struct Index[pManager->Get_figcount()];
	string	*ftype = new string[pManager->Get_figcount()];
	color	*fcolor = new color[pManager->Get_figcount()];
	pManager->Get_fcolor(fcolor);
	pManager->Get_ftypes(ftype);
	string scolor;
	Select *s1 = new Select(pManager);
	CFigure *fig; 
	bool check_2nd[4] = { 0,0,0,0 };
	bool *check = new bool[pManager->Get_figcount()];
	for (int i = 0; i < pManager->Get_figcount(); i++)check[i] = false;
	for (int i = 0; i < pManager->Get_figcount(); i++)
	{
		index[i].type = ftype[i];
		index[i].fcolor = fcolor[i];
	}	
	int x=rand();
	srand(time(0) + x);
	int w = (rand() % pManager->Get_figcount());
	int j;
	for ( j = 0; j < pManager->Get_figcount(); j++)
	{
		if (j == w)
		{

			if (index[j].type == "Circle") check_2nd [0]= true;
			else if (index[j].type == "Line") check_2nd[1] = true;
			else if (index[j].type == "Triangle") check_2nd[2] = true;
			else if (index[j].type == "Rectangle") check_2nd[3] = true;

			if (index[j].fcolor == LIGHTGOLDENRODYELLOW) scolor = "Unfilled";
			else
				scolor = to_string(fcolor[j]);

			pOut->PrintMessage("Pick all "+scolor +' '+ index[j].type+'s');
			break;
		}
	}
	int right = 0;
	for (int i = 0; i < pManager->Get_figcount(); i++)//check repeated
	{
		if ((index[j].fcolor == index[i].fcolor) && (index[j].type == index[i].type))
			right++;
	}
	int Correct = 0; int Incorrect = 0;
	int count = pManager->Get_figcount();
	bool true_type = false, true_color = false;
	for (int i = 0; (i <count) && (Correct<right); i++)
	{
		double z1, z2;
		s1->select_play(z1, z2);
		fig = pManager->Get_Selected_Fig();
		if (fig == NULL&&z2 < UI.ToolBarHeight&&z1 <5 * UI.MenuItemWidth)
		{
			return;
		}
		else if (fig == NULL&&z2 >= 0 && z1 >= 0)
		{					
			i--;
			continue;
		}

		if (dynamic_cast<CCircle*>(fig))
		{if(check_2nd[0]) true_type = true;}
		else if (dynamic_cast<CLine*>(fig))
		{if (check_2nd[1]) true_type = true;}
		else if (dynamic_cast<CTriangle*>(fig))
		{if (check_2nd[2]) true_type = true;}
		else if (dynamic_cast<CRectangle*>(fig))
		{if (check_2nd[3]) true_type = true;}

		if (fig->get_color() == index[j].fcolor)
			true_color = true;
		if (true_type&&true_color)
			Correct++;
		else 
			Incorrect++;
		true_type = false;
		true_color = false;
		pManager->Delete_selected_figs();
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
		pOut->PrintMessage("Correct : "+to_string(Correct)+"  Incorrect : "+to_string(Incorrect));
	}
	pOut->PrintMessage("Game Over \\ Correct : " + to_string(Correct) + "  Incorrect : " + to_string(Incorrect) );
	delete[]index;
	delete[]ftype;
	delete[]fcolor;
	delete s1;
	delete[]check;
}
