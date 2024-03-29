#pragma once
#include "Action.h"
class SoundAction : public Action
{

public:
	SoundAction (ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual bool Execute(bool ReadParamsFirst = true);
	virtual void UndoExcute();
	virtual void RedoExcute();
};
