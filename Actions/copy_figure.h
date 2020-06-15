#ifndef COPY_FIGURE_H
#define COPY_FIGURE_H

#include"Action.h"
#include"../Figures/CFigure.h"

#include"../Figures/CFigure.h"
#include"../Figures/CEllipse.h"
#include"../Figures/CLine.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CTriangle.h"
#include"../Figures/CRhombos.h"

class copy_figure:public Action
{
private:
	
	CFigure*copied_figure;
	GfxInfo figure_gfxinfo;




public:
	copy_figure(ApplicationManager*pApp); //conctructor to intialize pointer of application manager class

	//read copied figyre parameters
	virtual void ReadActionParameters();

	//adding the selected figure to clipboar "make the clipboar pointer points to the coppied figure"
	virtual void Execute() ;
	
};
#endif
