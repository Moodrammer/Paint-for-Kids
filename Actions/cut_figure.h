#ifndef CUT_FIGURE_H
#define CUT_FIGURE_H
#include"Action.h"

#include"../Figures/CFigure.h"
#include"../Figures/CEllipse.h"
#include"../Figures/CLine.h"
#include"../Figures/CRectangle.h"
#include"../Figures/CTriangle.h"
#include"../Figures/CRhombos.h"



class cut_figure:public Action 
{
private:

	CFigure *figure_cut;
	CFigure* gray_figure;

	GfxInfo	figure_gfxinfo;
	ActionType next_action;
public:
	cut_figure(ApplicationManager *pApp);
	
	
	virtual void ReadActionParameters();


	virtual void Execute() ;

	~cut_figure();
};
#endif
