#include "CFigure.h"

CFigure::CFigure(GfxInfo FigureGfxInfo)
{ 
	FigGfxInfo = FigureGfxInfo;	//Default status is non-filled.
	Selected = false;
}

void CFigure::SetSelected(bool s)
{	Selected = s; }

bool CFigure::IsSelected() const
{	return Selected; }

void CFigure::ChngDrawClr(color Dclr)
{	FigGfxInfo.DrawClr = Dclr; }

void CFigure::ChngFillClr(color Fclr)
{	
	FigGfxInfo.isFilled = true;
	FigGfxInfo.FillClr = Fclr; 
}

//M.A://///////////////////////
//int CFigure::IDSetter = 0; //initialization of IDSetter outside the class
void CFigure :: SetID(int id)
{
	ID = id;
}

///////////////////////////////
bool CFigure::get_is_filled(){
	
	return FigGfxInfo.isFilled;
}
color CFigure::get_fill_color(){
	

	if(get_is_filled())
	
	return FigGfxInfo.FillClr;
	
	else
	{
		return LIGHTGOLDENRODYELLOW;
	}
}

color CFigure::get_draw_color(){
	return FigGfxInfo.DrawClr;
}
color CFigure::GetDrawClr()
{
    return FigGfxInfo.FillClr;
}

