#include "CTriangle.h"
CTriangle::CTriangle(Point point1, Point point2,Point point3, GfxInfo FigureGfxInfo) :CFigure(FigureGfxInfo)
{
	p1 = point1;
	p2 = point2;
	p3 = point3;

	ID = GetNumberOfFigures();
}
CTriangle::CTriangle()
{}
void CTriangle::Draw(Output* pOut) const
{
	pOut->DrawTraingle(p1, p2, p3, FigGfxInfo, Selected);
}

float CTriangle::CalcArea(Point A, Point B, Point C) const
{
	return (1.0 / 2) * abs(A.x * (B.y - C.y) + B.x * (C.y - A.y) + C.x * (A.y - B.y));
}

float CTriangle::GetMyArea() const
{
	return CalcArea(p1, p2, p3);
}

void CTriangle::Move(Point destination)
{
	Point Centroid1;

	Centroid1.x = (p1.x + p2.x + p3.x) / 3;
	Centroid1.y = (p1.y + p2.y + p3.y) / 3;

	Point Centroid2 = destination;

	int dx1 = p1.x - Centroid1.x;
	int dx2 = p2.x - Centroid1.x;
	int dx3 = p3.x - Centroid1.x;

	int dy1 = p1.y - Centroid1.y;
	int dy2 = p2.y - Centroid1.y;
	int dy3 = p3.y - Centroid1.y;

	p1.x = Centroid2.x + dx1;
	p2.x = Centroid2.x + dx2;
	p3.x = Centroid2.x + dx3;

	p1.y = Centroid2.y + dy1;
	p2.y = Centroid2.y + dy2;
	p3.y = Centroid2.y + dy3;

}

bool CTriangle::CheckInside(int X, int Y)
{
	// the point clicked
	Point p;
	p.x = X;
	p.y = Y;

	float A1 = CalcArea(p, p1, p2);
	float A2 = CalcArea(p, p2, p3);
	float A3 = CalcArea(p, p3, p1);

	return (GetMyArea() == A1 + A2 + A3);
}

void CTriangle::PrintInfo(Output* pOut)
{
	string msg = "Triangle : ID =  " + to_string(ID);
	msg += ", P1 (" + to_string(p1.x) + ", " + to_string(p1.y) + ")";
	msg += " , P2 (" + to_string(p2.x) + ", " + to_string(p2.y) + ")";
	msg += " , P3 (" + to_string(p3.x) + ", " + to_string(p3.y) + ")";
	msg += " , Area = " + to_string((int)GetMyArea());
	pOut->PrintMessage(msg);
}

void CTriangle::Save(ofstream& OutFile)
{
	OutFile << setw(10) << left << "TRIANG" << setw(5) << ID << setw(5) << p1.x << setw(5)
		<< p1.y << setw(5) << p2.x << setw(5) << p2.y << setw(5) << p3.x << setw(5) << p3.y
		<< setw(8) << EncodeColor(FigGfxInfo.DrawClr);

	if (!FigGfxInfo.isFilled)
		OutFile << setw(8) << "NO_FILL" << endl << endl;
	else
		OutFile << setw(8) << EncodeColor(FigGfxInfo.FillClr) << endl << endl;
}

void CTriangle::Load(ifstream& InFile)
{
	string color1, color2;

	InFile >> ID >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y
		>> color1 >> color2;

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

Point CTriangle::GetCenter()
{
	Point c;
	c.x = (p1.x + p2.x + p3.x) / 3;
	c.y = (p1.y + p2.y + p3.y) / 3;
	return c;
}

char CTriangle::GetMyType()
{
	return 't';
}

void CTriangle::ResizeByDragging(Point NewLocation)
{
	int d1 = sqrt( pow(p1.x - NewLocation.x, 2) + pow(p1.y - NewLocation.y, 2) );
	int d2 = sqrt( pow(p2.x - NewLocation.x, 2) + pow(p2.y - NewLocation.y, 2) );
	int d3 = sqrt( pow(p3.x - NewLocation.x, 2) + pow(p3.y - NewLocation.y, 2) );

	if (d1 < d2 && d1 < d3)
		p1 = NewLocation;
	else if (d2 < d1 && d2 < d3)
		p2 = NewLocation;
	else
		p3 = NewLocation;

}
