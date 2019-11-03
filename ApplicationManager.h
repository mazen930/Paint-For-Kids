#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include "Actions\Copy.h"
#include "Actions\Cut.h"
#include "Actions\Paste.h"
#include<vector>
//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	 //Pointer to the selected figure
	vector<CFigure*> Clipboard;   //Pointer to the copied/cut figure
	vector<CFigure*>SelectedFigs;
	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;

public:	
	ApplicationManager(); 
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
	void Delete_selected_figs();			//delete selected figures
	void Set_Selected_Fig(CFigure*);		//add figure to the selected figs vector
	vector<CFigure*>&  Get_Selected_Figs(); 
	CFigure*Get_Selected_Fig()const;
	void UnSelectAll();						//unselect all figures
    void UnSelect(int);						//unselect one figure knowing its id
	void DeleteAll();	                    //this function is used in load operation
	vector<CFigure*>& GetClipboard();
	void copytoclipboard();					//takes copy from selected figs to clipboard
	void AddPastedFigure(Point ,Point);		//add pasted figures to figlist
	void clearClipboard();
	int Get_figcount();                     //return number of figers
	void send_to_back();					//shifts the selected figure to the beginning of the figlist
	void bring_to_front();					//shifts the selected figure to the end of the figlist
	void Get_fcolor(color fcolor[]);
	void Get_ftypes(string ftype[]);
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window	
	void Load_play();
	void SaveAll(ofstream & OutFile);
	~ApplicationManager();
};

#endif