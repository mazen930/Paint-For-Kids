#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\DEFS.h"
#include "..\GUI\Output.h"

//for save & load operations (because of function to_number and CFigure_Type and CColor enums) 
#include "..\Actions\SaveAction.h"

//Base class for all figures
class CFigure
{
protected:
    int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info
	Point centre;
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);

    void SetSelected(bool s);	//select/unselect the figure
	virtual bool InsideMe(int a,int b) const = 0;	//check whether fig is selected
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	bool IsSelected()const;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color
	void set_ID(int);
	int Get_ID()const;
	virtual  void Rotates() = 0;
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	virtual void Save(ofstream &OutFile) = 0;	//Save the figure parameters to the file
	virtual bool Load(ifstream &Infile);	    //Load the figure parameters to the file	//(boolean function to indicate if loading succeeded)
	color get_color();
	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	int getcentre_X();
	int getcentre_Y();
	virtual CFigure* copy()=0;					//makes a new object of figure
	virtual void Transfer(Point,Point)=0;		//transfering the figure with a major center reference
	~CFigure();
};

#endif