#pragma once
#include "Action.h"
class MoveAction : public Action
{
	Point destination;
	CFigure* pFig;
	CFigure* saved;
	Point prevlocation;

public:
	MoveAction(ApplicationManager* pApp);
	virtual void ReadActionParameters() override;
	virtual void Execute(bool ReadParamsFirst = true) override;
	virtual void UndoExcute() override;
	virtual void RedoExcute() override;
	~MoveAction();
	virtual bool CheckRecordability() const;
};

