#include"..\Actions\Figure_Fill_Color.h"
#include"..\GUI\Output.h"
#include<time.h>
#include"..\ApplicationManager.h"
#include"Action.h"

Figure_Fill_Color::Figure_Fill_Color(ApplicationManager *pApp):Action(pApp)
{
	pManager->Load_play();	//load the figures drawn in draw mode
	pManager->UpdateInterface();
}

bool Figure_Fill_Color::ReadActionParameters()	//Empty function to avoid abstract class
{
	return true;
}

void Figure_Fill_Color::Execute()
{
	Output *pOut = pManager->GetOutput();
	Select* s1 = new Select(pManager);//to select
	CFigure *fig;
	if (pManager->Get_figcount() == 0)
	{
		pOut->PrintMessage("Draw some figures first to play with them");
		return;
	}
	pManager->UnSelectAll();
	color *fcolor = new color[pManager->Get_figcount()];

	pManager->Get_fcolor(fcolor);//function that puts color in array of colors
	int l =  pManager->Get_figcount();//put number of figures in figlist
	int x = (rand() % l );//x is for genrate random numbers & 
	bool *flag = new bool[l ];
	for (int i = 0; i < l ; i++)
		flag[i] = false;
	int j;
	for (j = 0; j <l; j++)
	{
		string color;
		if (j == x)
		{
			if (fcolor[j] == LIGHTGOLDENRODYELLOW)
			{
				color = "UNfilled";
				pOut->PrintMessage(color);
				flag[0] = 1;//for unfilled colors 
				break;

			}
			else
			{
				color = to_string(fcolor[j]);
				pOut->PrintMessage("Pick all "+color+" figures");
				flag[j + 1] = true;//start to count after unfilled color
				break;
			}
		}
	}
	int w = 0;//w is for corrected figures
	for (int i = 0; i < pManager->Get_figcount(); i++)//to get number of repeated colors
	{
		if (fcolor[j] == fcolor[i])
			w++;
	}

	int Correct = 0; int Incorrect = 0;
	int count = pManager->Get_figcount();
	for (int i = 0; (i <count) && (Correct<w); i++)
	{
		double z1, z2;
		s1->select_play(z1, z2);
		fig = pManager->Get_Selected_Fig();
		if (fig == NULL&&z2 < UI.ToolBarHeight&&z1 <5 * UI.MenuItemWidth)//check if he want to out
		{
			return;
		}
		else if (fig == NULL&&z2 >= 0 && z1 >= 0)//check if user select outsie figure
		{
			i--;
			continue;
		}

		if (fig->get_color() == fcolor[j])
			Correct++;
		else
			Incorrect++;

		pManager->Delete_selected_figs();
		pOut->ClearDrawArea();
		pManager->UpdateInterface();
		pOut->PrintMessage("Correct : "+to_string(Correct)+"  Incorrect : "+to_string(Incorrect));
	}

	pOut->PrintMessage("Game Over \\ Correct : " + to_string(Correct) + "  Incorrect : " + to_string(Incorrect) );
	delete s1;
	delete[]fcolor;

}