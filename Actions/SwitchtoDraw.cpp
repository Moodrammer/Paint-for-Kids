#include "SwitchtoDraw.h"
#include"..\ApplicationManager.h"
#include<fstream>
#include "..\Figures\CRectangle.h"
#include "..\Figures\CEllipse.h"
#include "..\Figures\CLine.h"
#include "..\Figures\CRhombos.h"
#include "..\Figures\CTriangle.h"



SwitchtoDraw::SwitchtoDraw(ApplicationManager* pApp):Action(pApp)
{}


void SwitchtoDraw :: ReadActionParameters()
{}


void SwitchtoDraw :: Execute()
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pManager->ExecuteAction(LOAD);
		if(pManager->get_cut_operation()){    //for handling the case of cut a figure then switch to play mode 
			pManager->change_gfxinfo();
			pManager->copied_cut_figure_NULL();
		}
			pManager->copied_cut_figure_NULL();
	pOut ->CreateDrawToolBar();
}

