#include "ApplicationManager.h"
#include "Actions\AddRectAction.h"
#include "Actions\AddLineAction.h"
#include "Actions\AddCircleAction.h"
#include "Actions\AddTriAction.h"
#include "Actions\ChngDrawClrAction.h"
#include "Actions\ChngFillClrAction.h"
#include "Actions\Select.h"
#include "Actions\Delete.h"
#include "Actions\ToPlay.h"
#include "Actions\SaveAction.h"
#include "Actions\LoadAction.h"
#include <vector>
#include "Actions\Copy.h"
#include "Actions\Cut.h"
#include "Actions\Paste.h"
#include"Figures\CFigure.h"
#include"Figures\CLine.h"
#include"Figures\CRectangle.h"
#include"Figures\CTriangle.h"
#include"Figures\CCircle.h"
#include"Actions\ToDrawMode.h"
#include"Actions\Figure_Type.h"
#include"Actions\Figure_Fill_Color.h"
#include"Actions\Figure_Type_and_Fill_Color.h"
#include"Actions\Rotate.h"
#include"Actions\SendToBack.h"
#include"Actions\BringToFront.h"

//Constructor
ApplicationManager::ApplicationManager()
{
	//Create Input and output
	pOut = new Output;
	pIn = pOut->CreateInput();
	FigCount = 0;
	//Create an array of figure pointers and set them to NULL		
	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;	
}

//==================================================================================//
//								Actions Related Functions							//
//==================================================================================//
ActionType ApplicationManager::GetUserAction() const
{
	int x,y;
	//Ask the input to get the action from the user.
	return pIn->GetUserAction(x,y);		
}
////////////////////////////////////////////////////////////////////////////////////
//Creates an action and executes it
void ApplicationManager::ExecuteAction(ActionType ActType) 
{
	Action* pAct = NULL;
	
	//According to Action Type, create the corresponding action object
	switch (ActType)
	{
		case DRAW_RECT:
			pAct = new AddRectAction(this);
			break;

		case DRAW_LINE:
			pAct = new AddLineAction(this);
			break;

		case DRAW_CIRC:
			pAct = new AddCircleAction(this);
			break;

		case DRAW_TRI:
			pAct = new AddTriAction(this);
			break;

		case CHNG_DRAW_CLR:
			pAct = new ChngDrawClrAction(this);
			break;

		case CHNG_FILL_CLR:
			pAct = new ChngFillClrAction(this);
			break;

		case SELECT:
			pAct = new Select(this);
			break;

		case COPY:
			pAct = new Copy(this);
			break;

		case CUT:
			pAct = new Cut(this);
			break;

		case PASTE:
			pAct = new Paste(this);
			break;

		case DEL:
			pAct = new Delete(this);
			break;

		case ROTATE:
			pAct = new Rotate(this);
			break;

		case SAVE:
			pAct = new SaveAction(this);
			break;

		case LOAD:
			pAct = new LoadAction(this);
			break;

		case SEND_TO_BACK:
			pAct=new SendToBack(this);
			break;

		case BRING_TO_FRONT:
			pAct=new BringToFront(this);
			break;

		case TO_PLAY:
			pAct=new ToPlay(this);
			break;

		case TO_DRAW:
			pAct = new TO_DRAW_MODE(this);
			break;

		case Figure_Fill_color:
			pAct = new Figure_Fill_Color(this);
			break;

		case Figure_type:
			pAct = new Figure_Type(this);
			break;

		case Figure_type_and_Fill_Color:
			pAct = new Figure_Type_and_Fill_Color(this);
			break;

		case EXIT:
			break;

		default:	//a click on the status bar or drawing area or empty place on the toolbar ==> only clear the message on the statusbar
			pOut->FlushCrntMsg();
			return;
	}
	
	//Execute the created action
	if(pAct != NULL)
	{
		pAct->Execute();//Execute
		delete pAct;	//Action is not needed any more ==> delete it
		pAct = NULL;
	}
}


//==================================================================================//
//						Figures Management Functions								//
//==================================================================================//

//Add a figure to the list of figures
void ApplicationManager::AddFigure(CFigure* pFig)
{
	if(FigCount < MaxFigCount )
		{
			FigList[FigCount++] = pFig;	
			pFig->set_ID(FigCount);
	    }
}
////////////////////////////////////////////////////////////////////////////////////
CFigure *ApplicationManager::GetFigure(int x, int y) const
{
	//If a figure is found return a pointer to it.
	//if this point (x,y) does not belong to any figure return NULL
	for(int i=FigCount-1;i>=0;i--)
	{
		bool temp=false;
		temp=FigList[i]->InsideMe(x,y);
		if(temp)
			{
				return FigList[i];
		    }
	}
	return NULL;
}
int ApplicationManager::Get_figcount()
{
	return FigCount;
}

void ApplicationManager::Get_fcolor(color fcolor[])
{
	for (int i = 0; i < FigCount; i++)
	{
		if (FigList[i]->get_color() == LIGHTGOLDENRODYELLOW)
			fcolor[i] = LIGHTGOLDENRODYELLOW;
		else
			for (int j = 0; j < ColorsNum; j++)
			{
				if (FigList[i]->get_color() == colors[j])
				{
					fcolor[i] = colors[j];
					break;
				}
			}

	}
}

void ApplicationManager::Get_ftypes(string ftype[])
{
	for (int i = 0; i < FigCount; i++)
	{
		if (dynamic_cast<CCircle*>(FigList[i])) ftype[i] = "Circle";
		else if (dynamic_cast<CLine*>(FigList[i])) ftype[i] = "Line";
		else if (dynamic_cast<CTriangle*>(FigList[i]))ftype[i] = "Triangle";
		else if (dynamic_cast<CRectangle*>(FigList[i]))ftype[i] = "Rectangle";

	}
}

void ApplicationManager::UnSelectAll()
{
	SelectedFigs.clear();

	for(int i=0;i<FigCount;i++)
		FigList[i]->SetSelected(false);
}

void ApplicationManager::UnSelect(int id)
{
	int selectcount=SelectedFigs.size();
	for(int i=0;i<selectcount;i++)
	{
		if(SelectedFigs[i]->Get_ID()==id)
		{
			SelectedFigs.erase(SelectedFigs.begin()+i);
			break;
		}
	}
}

void ApplicationManager::DeleteAll()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];

	for(int i=0; i<MaxFigCount; i++)
		FigList[i] = NULL;

	FigCount=0;
}

void ApplicationManager::send_to_back()
{
	CFigure*temp;
	int t;
	for(int i=(SelectedFigs[0]->Get_ID())-1;i>0;i--)
	{
		//shifting the id
		t=FigList[i]->Get_ID();
		FigList[i]->set_ID(FigList[i-1]->Get_ID());
		FigList[i-1]->set_ID(t);
		//shifting the pointers
		temp=FigList[i];
		FigList[i]=FigList[i-1];
		FigList[i-1]=temp;
	}
}

void ApplicationManager::bring_to_front()
{
	CFigure*temp;
	int t;
	for(int i=(SelectedFigs[0]->Get_ID())-1;i<FigCount-1;i++)
	{
		//shifting the id
		t=FigList[i]->Get_ID();
		FigList[i]->set_ID(FigList[i+1]->Get_ID());
		FigList[i+1]->set_ID(t);
		//shifting the pointers
		temp=FigList[i];
		FigList[i]=FigList[i+1];
		FigList[i+1]=temp;
	}
}

void ApplicationManager::Set_Selected_Fig(CFigure*c)
{
	//adding a pointer to the vector
	SelectedFigs.push_back(c);
}

vector<CFigure*>& ApplicationManager::Get_Selected_Figs()
{
	return SelectedFigs;
}

void ApplicationManager::Load_play()
{
	DeleteAll();
	ifstream inputFile;
	inputFile.open("temp/temp.txt");
	int number;
	inputFile >> number;
	int type;
	CFigure* pFig;
	GfxInfo FigGfxInfo;
	FigGfxInfo.BorderWdth = pOut->getCrntPenWidth();	//to make new figures with default border width

	for (int i = 0; i < number; i++)
	{
		inputFile >> type;
		switch ((CFigureType)type)
		{
		case LINE:
			pFig = new CLine(FigGfxInfo);
			break;

		case RECTANGLE:
			pFig = new CRectangle(FigGfxInfo);
			break;

		case CIRCLE:
			pFig = new CCircle(FigGfxInfo);
			break;

		case TRIANGLE:
			pFig = new CTriangle(FigGfxInfo);
			break;

		}
		pFig->Load(inputFile);

		AddFigure(pFig);
	}

}

CFigure*ApplicationManager::Get_Selected_Fig()const		//this function is used in play mode as it needs only one figure
{
	if (SelectedFigs.empty())
		return NULL;
	else
	return SelectedFigs[0];
}

void ApplicationManager::Delete_selected_figs()
{
	CFigure*temp;
	int size=SelectedFigs.size();
	for(int j=0;j<size;j++)						//passing on all selected figures
	{
		int x=SelectedFigs[j]->Get_ID();		//getting the id of every selected figure
		for(int i=x-1;i<FigCount-1;i++)
		{
			//setting the id
			FigList[i+1]->set_ID(i+1);
			//shifting the pointer of the selected figure to the end of the figlist
			temp=FigList[i];
			FigList[i]=FigList[i+1];
			FigList[i+1]=temp;
		}
		delete FigList[FigCount];				//deleteing the last figure in the figlist
		FigList[FigCount]=NULL;
		FigCount--;								//decreasing the number of figures
		SelectedFigs[j]=NULL;
	}
	SelectedFigs.clear();						//deleting the pointers it self
}

vector<CFigure*>& ApplicationManager::GetClipboard()
{
	return Clipboard;
}

void ApplicationManager::copytoclipboard()
{
	int selectcount=SelectedFigs.size();
    for(int i=0;i<selectcount;i++)
	{
		Clipboard.push_back(SelectedFigs[i]->copy());		//takes a copy of the selected figure
	}
}

void ApplicationManager::AddPastedFigure(Point P,Point Majorcentre)
{
	int size=Clipboard.size();
	for(int i=0;i<size;i++)
	{
		Clipboard[i]->Transfer(P,Majorcentre);				//transfering the figures
	    AddFigure(Clipboard[i]);
		Clipboard[i]=Clipboard[i]->copy();					//another copy to separate clipboard from figlist&selected figs
	}
}

void ApplicationManager::clearClipboard()
{
	Clipboard.clear();
}


//==================================================================================//
//							Interface Management Functions							//
//==================================================================================//

//Draw all figures on the user interface
void ApplicationManager::UpdateInterface() const
{	
	pOut->ClearDrawArea();		//First clear draw area
	
	for(int i=0; i<FigCount; i++)
	{
		FigList[i]->Draw(pOut);		//Call Draw function (virtual member fn)
	}

	//Clear the toolbar and statusbar if any figure was darwn on them

	pOut->ClearToolBar();
	pOut->ClearStatusBar();

	pOut->PrintMessage( pOut->getCrntMsg() );	//then print the last message
}

////////////////////////////////////////////////////////////////////////////////////
//Return a pointer to the input
Input *ApplicationManager::GetInput() const
{	return pIn; }

//Return a pointer to the output
Output *ApplicationManager::GetOutput() const
{	return pOut; }

////////////////////////////////////////////////////////////////////////////////////
//Destructor

void ApplicationManager::SaveAll(ofstream & OutFile)
{
	OutFile<<FigCount<<'\n';	//save number of figures
	for(int i=0; i<FigCount; i++)
		FigList[i]->Save(OutFile);
}

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<FigCount; i++)
		delete FigList[i];
	int size=Clipboard.size();
	for(int i=0;i<size;i++)
		delete Clipboard[i];
	Clipboard.clear();
	SelectedFigs.clear();
	delete pIn;
	delete pOut;
}
