#include "CSquare.h"

CSquare::CSquare( Point P, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	center = P;
	ID = GetNumberOfFigures();
	squareside = 50;
}

CSquare::CSquare()
{
	squareside = 50;
}

void CSquare::Draw(Output* pOut) const
{
	//Call Output::DrawRect to draw a rectangle on the screen	
	pOut->DrawSquare(center, FigGfxInfo, squareside, Selected);
}

bool CSquare::CheckInside(int X, int Y)
{
	//I have Point center
	Point corner1, corner2;
	corner1.x = center.x - 50;
	corner1.y = center.y - 50;
	corner2.x = center.x + 50;
	corner2.y = center.y + 50;

	return
	(
		X >= corner1.x
		&& X <= corner2.x
		&& Y >= corner1.y
		&& Y <= corner2.y
	);
}

void CSquare::PrintInfo(Output* pOut)
{
	string msg = "Square : ID = " + to_string(ID);
	msg += ", Center(" + to_string(center.x) + ", " + to_string(center.y) + ")";
	msg += ", side length = 100";
	pOut->PrintMessage(msg);
}

void CSquare::Save(ofstream& OutFile)
{
	OutFile << setw(10) << left << "SQUARE" << setw(5) << ID << setw(5) << center.x
		<< setw(5) << center.y << setw(8) << EncodeColor(FigGfxInfo.DrawClr);

	if (!FigGfxInfo.isFilled)
		OutFile << setw(8) << "NO_FILL" << endl << endl;
	else
		OutFile << setw(8) << EncodeColor(FigGfxInfo.FillClr) << endl << endl;
}

void CSquare::Load(ifstream& InFile)
{
	string color1, color2;

	InFile >> ID >> center.x >> center.y >> color1 >> color2;

	FigGfxInfo.DrawClr = DecodeColor(color1);
	UpdateFigGfxDrawClr(FigGfxInfo.DrawClr);

	if (color2 == "NO_FILL")
	{
		FigGfxInfo.isFilled = false;
		UnfillFigGfxInfo();
	}
	else
	{
		FigGfxInfo.isFilled = true;
		FigGfxInfo.FillClr = DecodeColor(color2);
		UpdateFigGfxFillClr(FigGfxInfo.FillClr);
	}
}

void CSquare::Move(Point destination)
{
	center = destination;
}
Point CSquare::GetCenter()
{
	return center;
}

char CSquare::GetMyType()
{
	return 's';
}

void CSquare::ResizeByDragging(Point NewLocation)
{
	squareside = 0.707 * sqrt(pow(center.x - NewLocation.x, 2) + pow(center.y - NewLocation.y, 2));
}
