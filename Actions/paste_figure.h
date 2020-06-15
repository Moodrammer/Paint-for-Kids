#ifndef PASTE_FIGURE_H
#define PASTE_FIGURE_H

#include"Action.h"

#include"../Figures/CFigure.h"
#include"../Figures/CEllipse.h"
#include"../Figures/CLine.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CTriangle.h"
#include"../Figures/CRhombos.h"



class paste_figure:public Action
{
private:
	
	Point P,P1,P2,P3;
	GfxInfo ellipse_gfxinfo;
	GfxInfo line_gfxinfo;
	GfxInfo triangle_gfxinfo;
	GfxInfo rectangle_gfxinfo;
	GfxInfo rhombos_gfxinfo;
	
	CFigure*cut_copied_figure;
	
	
	
	
public:
	paste_figure(ApplicationManager *pApp);


	virtual void ReadActionParameters();


	virtual void Execute() ;

	

};
#endif

