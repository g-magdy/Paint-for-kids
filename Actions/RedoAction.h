#pragma once
#include "Action.h"
class RedoAction:public Action
{
public:
	RedoAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual void UndoExcute();
	virtual void RedoExcute();


};
