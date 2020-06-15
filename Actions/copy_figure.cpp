#include "copy_figure.h"

#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"

copy_figure::copy_figure(ApplicationManager *pApp):Action(pApp)
{
		copied_figure=NULL;  //set the pointer to NULL in the first

}

void copy_figure:: ReadActionParameters(){
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pOut->PrintMessage("copy Figure: Selected Figure was copied to clipboard ");

}

void copy_figure::Execute(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
		if(pManager->get_sound_operation()){
	sndPlaySound(TEXT("sounds\\copy.wav"), SND_FILENAME | SND_ASYNC);
	}

	if(pManager->Getselectedfigure()==NULL)   //should select a figure before click on copy icon
	{
		pOut->PrintMessage("please,first,select a figure to be copied!");
	}
	else{

		if(pManager->get_cut_operation()){
			pManager->change_gfxinfo();
		}
	
	ReadActionParameters();
    CFigure* To_Be_Copied= pManager->Getselectedfigure();

	pManager->set_cut_copied_figure(To_Be_Copied);

	copied_figure=pManager->get_cut_copied_figure();




		figure_gfxinfo.isFilled=copied_figure->get_is_filled();   //getting the graphics info of the copied figure
		figure_gfxinfo.DrawClr=copied_figure->get_draw_color();  // so if the figure graphics was changed after the copy action 
		figure_gfxinfo.FillClr=copied_figure->get_fill_color(); //  the pasted figure will be similar to the old one 
		pManager->set_copied_cut_figure_gfxinfo(figure_gfxinfo);  

	

	pManager->set_cut_operation(false);       //the operation is copy so we set cut operation to false

}
}