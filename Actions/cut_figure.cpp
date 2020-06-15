#include "cut_figure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

cut_figure::cut_figure(ApplicationManager *pApp):Action(pApp)
{
	figure_cut=NULL;    //set the pointer to NULL in the first

}



void cut_figure::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("Cut Figure: Selected Figure was cut ");

}

void cut_figure::Execute(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

		if(pManager->get_sound_operation()){
	sndPlaySound(TEXT("sounds\\cut.wav"), SND_FILENAME | SND_ASYNC);
	}
	if(pManager->Getselectedfigure()==NULL)        //should select a figure before click on cut icon
	{

	pOut->PrintMessage("please,first,select a figure to be cut!");
	}

	else{
	
		if(pManager->get_cut_operation()){
			pManager->change_gfxinfo();
		
		}

	ReadActionParameters();

  figure_cut = pManager->Getselectedfigure();
  pManager->set_cut_copied_figure(figure_cut);
  CFigure*To_Be_Cut=pManager->get_cut_copied_figure();


		figure_gfxinfo.isFilled=figure_cut->get_is_filled();         //getting the graphics info of the cut figure
		figure_gfxinfo.DrawClr=figure_cut->get_draw_color();        // so if the figure graphics was changed after the copy action
		figure_gfxinfo.FillClr=figure_cut->get_fill_color();       //  the pasted figure will be similar to the old one 
		pManager->set_copied_cut_figure_gfxinfo(figure_gfxinfo);
	


		figure_cut->ChngDrawClr(GRAY); //changing the draw and fill colour of the cut figure to GRAY
		figure_cut->ChngFillClr(GRAY);
	
		pManager->set_cut_operation(true); //it's a cut operation so the function should be set to true 




}
}

