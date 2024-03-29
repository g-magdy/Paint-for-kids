#pragma once
#include "Action.h"
#include "../ApplicationManager.h"

class Action;

class StopRecordingAction : public Action
{
public:
	StopRecordingAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
};

