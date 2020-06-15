#include "ChangeFillColour.h"
#include"..\ApplicationManager.h"
#include"..\Figures\CLine.h"



ChangeFillColour::ChangeFillColour(ApplicationManager * pApp):Action(pApp)
{}

void ChangeFillColour::ReadActionParameters()
{
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	CrntSelectedFig = pManager->Getselectedfigure();

	pOut->PrintMessage("Select a Colour from the colour pallete");
	newClr = pIn->GetUserAction();
}


void ChangeFillColour::Execute()
{
	Output* pOut = pManager->GetOutput();
	//Call read action parameters to get the selected figure and the required colour
			if(pManager->get_sound_operation()){
	sndPlaySound(TEXT("sounds\\change_fill_color.wav"), SND_FILENAME | SND_ASYNC);
	}
	ReadActionParameters();

	//Check if there is no selected fig
	if (CrntSelectedFig == NULL)
	{
		pOut->PrintMessage("Error: No figure selected!");
	}
	else
	{
		//line has no fill colour
		if (!(dynamic_cast<CLine*>(CrntSelectedFig)))
		{
			//Switch to determine the required colour
			switch (newClr)
			{

			case RED_CLR:

			/*     if(pManager->get_cut_operation()){    //for case changing fill color after cut the figure without pasting it
					pManager->copied_cut_figure_NULL();
				}*/ 
				CrntSelectedFig->ChngFillClr(RED);
				UI.FillColor = RED;
				pOut->PrintMessage("Fill Colour Changed to Red");
				UI.FigsFilled = true;  //To make rest of figures filled with the ui current fill colour
				break;

			case BLACK_CLR:

				/*if(pManager->get_cut_operation()){
					pManager->copied_cut_figure_NULL();
				} */
				CrntSelectedFig->ChngFillClr(BLACK);
				UI.FillColor = BLACK;
				pOut->PrintMessage("Fill Colour Changed to Black");
				UI.FigsFilled = true;
				break;

			case GREEN_CLR:
			    /*if(pManager->get_cut_operation()){
					pManager->copied_cut_figure_NULL();
				} */
				
				CrntSelectedFig->ChngFillClr(GREEN);
				UI.FillColor = GREEN;
				pOut->PrintMessage("Fill Colour Changed to Green");
				UI.FigsFilled = true;
				break;

			case BLUE_CLR:
			     /*if(pManager->get_cut_operation()){    //for case changing fill color after cut the figure without pasting it
					pManager->copied_cut_figure_NULL();
				} */
				CrntSelectedFig->ChngFillClr(BLUE);
				UI.FillColor = BLUE;
				pOut->PrintMessage("Fill Colour Changed to Blue");
				UI.FigsFilled = true;
				break;

			case WHITE_CLR:
			   /*if(pManager->get_cut_operation()){
					pManager->copied_cut_figure_NULL();
				} */
				CrntSelectedFig->ChngFillClr(WHITE);
				UI.FillColor = WHITE;
				pOut->PrintMessage("Fill Colour Changed to White");
				UI.FigsFilled = true;
				break;

			default:
				pOut->PrintMessage("Invalid Colour Selection");
			}
		}
		else
		{
			pOut->PrintMessage("Line has no Fill Colour!");
		}
	}
}


