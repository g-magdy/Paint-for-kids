#ifndef CRECT_H
#define CRECT_H

#include "CFigure.h"

class CRectangle : public CFigure
{
private:
	Point Corner1;
	Point Corner2;

	// upper-left and bottom-right corners
	Point UL;
	Point BR;

public:
	CRectangle(Point, Point, GfxInfo FigureGfxInfo);
	CRectangle();
	virtual void Draw(Output* pOut) const;
	virtual void Save(ofstream& OutFile);
	virtual void Load(ifstream& InFile);
	virtual bool CheckInside(int x, int y);
	virtual void Move(Point destination) override;
	virtual Point GetCenter();
	virtual void PrintInfo(Output* pOut);
	virtual char GetMyType();
	virtual void ResizeByDragging(Point);
};

#endif