#include"SaveAction.h"

#include "..\ApplicationManager.h"

#include "..\GUI\input.h"	//to use GetString function
#include "..\GUI\Output.h"	//to print messages

SaveAction::SaveAction(ApplicationManager * pApp):Action(pApp)
{
	path="save/";
}

bool SaveAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	pOut->PrintMessage("Save the File: Please Enter the File name to save in, or press \"Escape\" to cancel");
	string FileName;
	FileName=pIn->GetSrting(pOut);

	if(FileName == "")		//the user pressed Esc
	{
		pOut->PrintMessage("Save is canceled!");
		return false;
	}

	if(FileName.find_first_of("\\/:*?\"<>|") != -1 )	//if it finds any of these characters
	{
		pOut->PrintMessage("Error: Invalid name, Please click on save icon again, then Enter a valid name ( without any of these characters (\\/:*?\"<>|) )");
		return false;
	}


	path+=FileName;
	path+=".txt";

	return true;
}

void SaveAction::Execute()
{
	/*Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	if ( ReadActionParameters() )
	{
		OutputFile.open(path);
		if( OutputFile.is_open() )
		{
			OutputFile<<to_number( pOut->getCrntDrawColor() )<<'\t';	//save current draw color

			if( pOut->CrntIsFilled() )		//save current fill color
				OutputFile<<to_number( pOut->getCrntFillColor() );
			else
				OutputFile<<-1;
			OutputFile<<'\n';

			pManager->SaveAll(OutputFile);
			OutputFile.close();
			pOut->PrintMessage("The File is Saved!");
		}
		else
			pOut->PrintMessage("Error: could't create the file. Please check if \"save\" folder exists,then try again");
	}
	*/
}

int to_number(const color& c)
{
	for(int i=0; i<ColorsNum; i++)
	{
		if(c==colors[i])
			return i;
	}
}
