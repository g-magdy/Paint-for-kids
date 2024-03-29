#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;

	NumberOfFigures++;
  
	if (FilledAsDefault)
		FigGfxInfo.isFilled = true;
	PrevFigGfxInfo = FigGfxInfo;
}

CFigure::CFigure()
{
	if (FilledAsDefault)
		FigGfxInfo.isFilled = true;
	PrevFigGfxInfo = FigGfxInfo;
	Selected = false;
}

int CFigure::NumberOfFigures = 0;

bool CFigure::FilledAsDefault = false;

void CFigure::SetSelected(bool s)
{
	Selected = s;
}

bool CFigure::IsSelected() const
{
	return Selected;
}

void CFigure::ChngDrawClr(color Dclr)
{
	FigGfxInfo.DrawClr = Dclr;
}

void CFigure::ChngFillClr(color Fclr)
{
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr;
}
void CFigure::MakeNotFilled()
{
	FigGfxInfo.isFilled = false;
}
color CFigure::GetDrawClr()
{
	return FigGfxInfo.DrawClr;
}
color CFigure::GetFillClr()
{
	return FigGfxInfo.FillClr;
}
FillColors CFigure::GetFillClrENUM()
{
	bool b = FigGfxInfo.isFilled;
	
	if (!b)
		return UNFILLED;

	color c = FigGfxInfo.FillClr;

	if (c == BLACK)
		return black;
	if (c == RED)
		return red;
	if (c == ORANGE)
		return orange;
	if (c == color(255, 215, 0))
		return yellow;
	if (c == color(0, 87, 231))
		return blue;
	if (c == color(0, 135, 68))
		return green;

}
void CFigure::SetFilledAsDefault()
{
	FilledAsDefault = true;
}
void CFigure::SetNotFilledAsDefault()
{
	FilledAsDefault = false;
}
bool CFigure::IsFilledAsDefault()
{
	return FilledAsDefault;
}
bool CFigure::IsFilled()
{
	return FigGfxInfo.isFilled;
}

color CFigure::DecodeColor(string s) const		//takes string and returns corresponding color
{
	if (s == "BLACK")
		return BLACK;
	if (s == "RED")
		return RED;
	if (s == "ORANGE")
		return ORANGE;
	if (s == "YELLOW")
		return color(255, 215, 0);
	if (s == "BLUE")
		return color(0, 87, 231);
	if (s == "GREEN")
		return color(0, 135, 68);
}
string CFigure::EncodeColor(color c) const      //takes color and returns corresponding string
{
	if (c == BLACK)
		return "BLACK";
	if (c == RED)
		return "RED";
	if (c == ORANGE)
		return "ORANGE";
	if (c == color(255, 215, 0))
		return "YELLOW";
	if (c == color(0, 87, 231))
		return "BLUE";
	if (c == color(0, 135, 68))
		return "GREEN";
}

void CFigure::PrintInfo(Output* pOut)
{
	pOut->PrintMessage("Figure of ID : " + to_string(ID));
}

int CFigure::GetNumberOfFigures()
{
	return NumberOfFigures;
}

void CFigure::UseFigGfxInfo()
{
	FigGfxInfo = PrevFigGfxInfo;
}

void CFigure::UpdateFigGfxDrawClr(color c)
{
	PrevFigGfxInfo.DrawClr = c;
}

void CFigure::UpdateFigGfxFillClr(color c)
{
	PrevFigGfxInfo.isFilled = true;
	PrevFigGfxInfo.FillClr = c;
}

void CFigure::UnfillFigGfxInfo()
{
	PrevFigGfxInfo.isFilled = false;
}

color CFigure::GetPrevDrawClr()
{
	return PrevFigGfxInfo.DrawClr;
}

CFigure::~CFigure()
{
}


