



#ifndef CELL_H
#define CELL_H

#include "CFigure.h"

class CEllipse : public CFigure
{
private:
	Point Centre;	
	
public:
	CEllipse(Point, GfxInfo FigureGfxInfo );
	virtual void Draw(Output* pOut) const;

	virtual bool Isinsideboundaries(int x, int y) const;
	virtual void PrintInfo(Output* pOut) const;

	virtual bool Isinvalid();
	
	virtual void Save(ofstream &outFile);	//Save the figure parameters to the file
	virtual void Load(ifstream &myFile);	//Load the figure parameters to the file

	virtual int get_P1_X();
	virtual int get_P1_Y();
	virtual int get_P2_X();
	virtual int get_P2_Y();
	virtual int get_P3_X();
	virtual int get_P3_Y();

};

#endif


