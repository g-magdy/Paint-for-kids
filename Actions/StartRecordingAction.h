#pragma once
#include "Action.h"

class Action;

class StartRecordingAction : public Action
{
public:
	StartRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
};

