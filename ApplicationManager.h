#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"
#include"Actions/Action.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)
	CFigure* Been_undo_list[MaxFigCount];
	CFigure* SelectedFig; //Pointer to the selected figure

	//Pointers to Input and Output classes
	Input* pIn;
	Output* pOut;
	Action* undolist[5];
	int undocount;
	int undoexcuted; //number of undo action that achueved
	Action* redolist[5];
	int redocount;
	int redoexcuted;
public:
	ApplicationManager();
	~ApplicationManager();

	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType); //Creates an action and executes it

	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure* GetFigure(int x, int y) const; //Search for a figure given a point inside the figure

	// -- Interface Management Functions
	Input* GetInput() const; //Return pointer to the input
	Output* GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window
	//void Undo();
	int GetFigCount();
	int GetUndoExcuted();
	void deletefigure();
	Action* GetExcutedAction();
	void SetUndoExcuted();
	//////////////////////////
void setExcutedeundoAction(Action*);
	Action* getundoedaction();
	void drawlast();
	int getredocount();
};

#endif