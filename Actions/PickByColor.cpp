#include "PickByColor.h"

PickByColor::PickByColor(ApplicationManager* pApp) : Action(pApp)
{
	CorrectCount = 0;
	WrongCount = 0;
}

void PickByColor::ReadActionParameters()
{
}

void PickByColor::Execute(bool ReadParamsFirst)
{
	pOut = pManager->GetOutput();
	pIn = pManager->GetInput();
	
	if (pManager->GetFigCount() == 0)
	{
		pOut->PrintMessage("There are no more figures!");
		return;
	}

	pManager->CountFillColors();

	int NoFillFigs = pManager->GetNoFillFigs();
	if (NoFillFigs == pManager->GetFigCount())
	{
		pOut->PrintMessage("There are no colored figures!");
		return;
	}

	int r;
	FillColors clr;
	srand(time(0));
	do
	{
		r = rand() % pManager->GetFigCount();
		clr = pManager->GetRandomFillColor(r);

	} while (clr == UNFILLED);

	
	switch (clr)
	{
	case black:
		pOut->PrintMessage("Pick all black figures!");
		TotalCount = pManager->GetBlackFigs();
		ExecuteBodyOfLoop(black, TotalCount);
		break;

	case red:
		pOut->PrintMessage("Pick all red figures!");
		TotalCount = pManager->GetRedFigs();
		ExecuteBodyOfLoop(red, TotalCount);
		break;

	case orange:
		pOut->PrintMessage("Pick all orange figures!");
		TotalCount = pManager->GetOrangeFigs();
		ExecuteBodyOfLoop(orange, TotalCount);
		break;

	case yellow:
		pOut->PrintMessage("Pick all yellow figures!");
		TotalCount = pManager->GetYellowFigs();
		ExecuteBodyOfLoop(yellow, TotalCount);
		break;

	case green:
		pOut->PrintMessage("Pick all green figures!");
		TotalCount = pManager->GetGreenFigs();
		ExecuteBodyOfLoop(green, TotalCount);
		break;

	case blue:
		pOut->PrintMessage("Pick all blue figures!");
		TotalCount = pManager->GetBlueFigs();
		ExecuteBodyOfLoop(blue, TotalCount);
		break;
	}
	pManager->ResetFillColors();
	pManager->ResetCounts();
}

void PickByColor::UndoExcute()
{
}

void PickByColor::RedoExcute()
{
}


void PickByColor::ExecuteBodyOfLoop(FillColors fillclr, int TotalCount)
{
	while (TotalCount > 0)
	{
		pIn->GetPointClicked(clicked.x, clicked.y);
		pFig = pManager->GetFigure(clicked.x, clicked.y);

		if (pFig == NULL)
		{
			pOut->PrintMessage("You clicked on an empty area. Try clicking on a colored figure!");
			continue;
		}

		if (pFig->GetFillClrENUM() == fillclr)
		{
			pManager->DeleteFigure(pFig);
			CorrectCount++;
			TotalCount--;
			pOut->PrintMessage("Bravo!          Correct clicks: " + to_string(CorrectCount) + "   " + " Wrong clicks: "
				+ to_string(WrongCount) + "  " + to_string(TotalCount));
		}

		else
		{
			pManager->DeleteFigure(pFig);
			WrongCount++;
			pOut->PrintMessage("Try again!     Correct clicks: " + to_string(CorrectCount) + "   " + " Wrong clicks: "
				+ to_string(WrongCount));
		}
		pManager->UpdateInterface();
	}
	pOut->PrintMessage("End of game:   Correct clicks: " + to_string(CorrectCount) + "    Wrong clicks: "
		+ to_string(WrongCount));
}

PickByColor::~PickByColor()
{
}