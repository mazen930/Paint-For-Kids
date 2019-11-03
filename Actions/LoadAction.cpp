#include"LoadAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"	//to use GetString function
#include "..\GUI\Output.h"	//to print messages

#include "..\Figures\CCircle.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures\CTriangle.h"

LoadAction::LoadAction(ApplicationManager * pApp):Action(pApp)
{
	path="save/";
}

bool LoadAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Load a File: Please Enter the File name to Load, or press \"Escape\" to cancel (THIS WILL DELETE CURRENT FIGURES!!)");
	string FileName;
	FileName=pIn->GetSrting(pOut);

	if(FileName == "")		//the user pressed Esc
	{
		pOut->PrintMessage("Load is canceled!");
		return false;
	}

	path+=FileName;
	path+=".txt";

	return true;
}

void LoadAction::Execute()
{
	/*Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if ( ReadActionParameters() )
	{
		InputFile.open(path);
		if( InputFile.is_open() )
		{
			pManager->DeleteAll();		//before doing anything delete currrent figures

			int dc,fc;	//read draw color & fill color
			InputFile>>dc>>fc;

			if(!(dc>=0 && dc<ColorsNum))
			{
				pOut->PrintMessage("Error: the file is corrupted!");
				return ;
			}

			pOut->setCrntDrawColor( colors[dc] );


			if(!(fc>=-1 && fc<ColorsNum))
			{
				pOut->PrintMessage("Error: the file is corrupted!");
				return ;
			}
			if(fc==-1)
				pOut->setCrntFilled(false);
			else
				pOut->setCrntFillColor( colors[fc] );

			int n;	//number of figures
			int type;
			CFigure* pFig;
			GfxInfo FigGfxInfo;
			FigGfxInfo.BorderWdth=pOut->getCrntPenWidth();	//to make new figures with default border width
			InputFile>>n;
			int i=0;
			while( i<n && !InputFile.eof() )
			{
				InputFile>>type;
				switch ( (CFigureType) type)
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

				default:
					pOut->PrintMessage("Error: the file is corrupted!");
					return;
				}

				if( !(pFig->Load(InputFile)) )
				{
					pOut->PrintMessage("Error: the file is corrupted!");
					return;
				}
				pManager->AddFigure(pFig);
				i++;
			}
			if(n>i)		//in case the input file ends before reaching n lines
				pOut->PrintMessage("Error: the file is corrupted!!");

			InputFile.close();
			pOut->PrintMessage("The file is loaded successfully");
		}
		else
			pOut->PrintMessage("Error: could't find the file. Please check if the file name is correct, then try again");
	}
	*/
}
