#pragma once
#include "Action.h"
class PickByType : public Action
{
	int TotalCount;
	int CorrectCount;
	int WrongCount;
	Point clicked;
	CFigure* pFig;
	Output* pOut;
	Input* pIn;

public:
	PickByType(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
	void ExecuteBodyOfLoop(char type, int TotalCount);
	~PickByType();
};

