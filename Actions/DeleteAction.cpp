#include "DeleteAction.h"
#include "..\ApplicationManager.h"

DeleteAction::DeleteAction(ApplicationManager* pApp) : Action(pApp)
{
}

void DeleteAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearDrawArea();
}

void DeleteAction::Execute()
{
	ReadActionParameters();
	//CFigure* pFig = pManager->GetSelectedFig();
	Output* pOut = pManager->GetOutput();
	bool done = pManager->DeleteFigure();
	if (!done)
		pOut->PrintMessage("No selected figure. Please select figure first!");
	else
		pOut->PrintMessage("Deleted selected figure.");
	pManager->addtoundolist(this);
}

DeleteAction::~DeleteAction()
{
}
void DeleteAction::UndoExcute()
{
	
	pManager->drawdeletedfigure();
}
void DeleteAction::RedoExcute()
{
	//pManager->deleteundoedaction();
}