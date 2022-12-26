#include "ChangeFillClrAction.h"
#include "..\ApplicationManager.h"

ChangeFillClrAction::ChangeFillClrAction(ApplicationManager* pApp) : Action(pApp)
{
}

void ChangeFillClrAction::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	ActionType ActType;

	CFigure* pFig = pManager->GetSelectedFig();

	if (!pFig)
		pOut->PrintMessage("Please select a figure first!");

	else
	{
		pOut->PrintMessage("Change fill color: please choose a color: ");

		ActType = pManager->GetUserAction();

		chosen = false;

		switch (ActType)
		{
		case BLACKCLR:
			NewFill = BLACK; chosen = true;
			pOut->PrintMessage("Changed fill color to black!");
			break;
		case REDCLR:
			NewFill = RED; chosen = true;
			pOut->PrintMessage("Changed fill color to red!");
			break;
		case ORANGECLR:
			NewFill = ORANGE; chosen = true;
			pOut->PrintMessage("Changed fill color to orange!");
			break;
		case YELLOWCLR:
			NewFill = color(255, 215, 0); chosen = true;
			pOut->PrintMessage("Changed fill color to yellow!");
			break;
		case GREENCLR:
			NewFill = color(0, 135, 68); chosen = true;
			pOut->PrintMessage("Changed fill color to green!");
			break;
		case BLUECLR:
			NewFill = color(0, 87, 231); chosen = true;
			pOut->PrintMessage("Changed fill color to blue!");
			break;
		default:
			pOut->PrintMessage("You didn't pick a color.");
		}
		if (chosen) pOut->ClearDrawArea();
	}
}

void ChangeFillClrAction::Execute()
{
	ReadActionParameters();

	if (chosen)
	{
		CFigure* pFig = pManager->GetSelectedFig();

		if (!pFig)
			return;
		else
		{
			color prev = pFig->GetDrawClr();
			UI.FillColor = NewFill;
			pFig->SetFilledAsDefault();
			pFig->ChngFillClr(NewFill);
			pFig->SetSelected(false);
			pFig->ChngDrawClr(prev);
		}
	}
}

void ChangeFillClrAction::UndoExcute()
{
}

void ChangeFillClrAction::RedoExcute()
{
}

ChangeFillClrAction::~ChangeFillClrAction()
{
}