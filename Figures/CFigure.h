#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info

	/// Add more parameters if needed.
	GfxInfo PrevFigGfxInfo;
public:
	CFigure(GfxInfo FigureGfxInfo);
	CFigure();

	static int NumberOfFigures;
	static bool FilledAsDefault;

	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected

	virtual void Draw(Output* pOut) const = 0;		//Draw the figure

	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	void MakeNotFilled();			//makes a figure not filled

	color GetDrawClr();             //returns the figure's drawing color
	color GetFillClr();

	FillColors GetFillClrENUM();

	void SetFilledAsDefault();		//sets filled as the default for figures
	void SetNotFilledAsDefault();	//sets not filled as the default for figures
	bool IsFilledAsDefault();		//returns whether the default for figures is filled or not
	bool IsFilled();				//returns whether the figure is filled or not

	string EncodeColor(color c) const; //takes color and returns corresponding string
	color DecodeColor(string s) const; //takes string and returns corresponding color

	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	

	static int GetNumberOfFigures();

	virtual void Save(ofstream& OutFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream& InFile) = 0;	//Load the figure parameters to the file

	virtual void Move(Point dest) = 0;

	virtual void PrintInfo(Output* pOut) = 0;	//print all figure info on the status bar
	
	// To check whether a point belongs to the shape's area or not 
	virtual bool CheckInside(int x, int y) = 0; /// pure virtual function (overridden in each class) 
	virtual Point GetCenter() = 0;

	void UseFigGfxInfo();
	void UpdateFigGfxDrawClr(color c);
	void UpdateFigGfxFillClr(color c);
	void UnfillFigGfxInfo();
	color GetPrevDrawClr();

	virtual void ResizeByDragging(Point) = 0;

	virtual char GetMyType() = 0;

	virtual ~CFigure();					//virtual destructor
};

#endif