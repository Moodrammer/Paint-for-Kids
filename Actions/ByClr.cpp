#include "ByClr.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Figures/CRectangle.h"
#include "..\Figures/CEllipse.h"
#include "..\Figures/CLine.h"
#include "..\Figures/CRhombos.h"
#include "..\Figures/CTriangle.h"
#include <stdlib.h>
#include <time.h>


ByClr::ByClr(ApplicationManager * pApp):Action(pApp)
{}

void ByClr::ReadActionParameters()
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);

}

//Execute the action
void ByClr::Execute() 
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pManager->setGameType(1);
	int r;
	Input* pIn = pManager->GetInput();
	pManager->ExecuteAction(LOAD);
    pManager->UpdateInterface();
	int* ExistFig=pManager->ExistType();
	bool coloured=false;
	
	 if(ExistFig==NULL)
	  {
	 pOut->PrintMessage("Make some Shapes First to plaay !!!! ");
  	 return;
	  }
	 for(int i=0;i<6;i++)
  	  {
	 if(ExistFig[i]!=5 && ExistFig[i]!=-1)
	   {
	 coloured=true;
  	 break;
       }
	  }
	 if (coloured == false)
	  {
	 pOut->PrintMessage(" Colour Shapes First !!!  ");
	 return;
	  }
	 else
	  {
    // r=pManager->TypeRandom();
   int r;
  bool found=false;
  while(!found)
	{
	srand(time(NULL) );
	int random =rand()%5;
	   for(int i=0;i<5;i++)
	    {
	   if( random==ExistFig[i])
	   {
	   r=random;
	   found=true;
	   break;
	   }
	    }
	}
	 pOut->PrintMessage("Please Wait !!!! ");
	// pManager->playMessage(r);
	 switch (r)
        {
	   case 0 :
		pOut->PrintMessage("Pick up all RED SHAPES !!!! ");
	    break;
	   case 1 :
		pOut->PrintMessage("Pick up all WHITE SHAPES !!!! ");
		break;
	   case 2 : 
		pOut->PrintMessage("Pick up all BLACK SHAPES !!!! ");
		break;
	   case 3 :
		pOut->PrintMessage("Pick up all GREEN SHAPES!!!! ");
	    break;
	   case 4 :
		pOut->PrintMessage("Pick up all BLUE SHAPES !!!! ");
		break;
	    }
	 int Count =pManager->NumCertainShapes(r);
	 CFigure* playFigure=NULL;
	 int Correct =0 ;
	 int NonCorrect =0;
	 while(Count !=0) 
	{	
		 ReadActionParameters();
	    if ( P.y >= 0 && P.y < UI.ToolBarHeight)
	     {	
		int ClickedItemOrder = (P.x / UI.MenuItemWidth);
		switch (ClickedItemOrder)
		  {
		 case ITM_FIGTYPE: 
		   
		   pManager->ExecuteAction(SELECT_BY_TYPE);
		   return;
		 case ITM_FIGCOL: 
		   
		   pManager->ExecuteAction(SELECT_BY_COLOUR);
		   return;
		 case ITM_DRAW:
		   pManager->ExecuteAction(TO_DRAW);
           return;
		 case ITM_EXIT2: return;
		 default: return ;	//A click on empty place in desgin toolbar
			}
		
		}
		playFigure=pManager->GetFigure(P.x, P.y);
		  if (playFigure!=NULL)
		   {
		  //pManager->play( playFigure , r, Count, Correct, NonCorrect);
			   switch(r)
	   {
	 case 0 : 
		 if (playFigure->GetDrawClr()==RED )
			{
		Correct ++;
	    Count--;
		pManager->DeleteFigure(playFigure);
		break;
			}
		pManager->DeleteFigure(playFigure);
	    NonCorrect++;
        break;
      case 1 : 
		if (playFigure->GetDrawClr()==WHITE)
			{
		Correct ++;
	    Count--;
		pManager->DeleteFigure(playFigure);
		break;
			}
		pManager->DeleteFigure(playFigure);
	    NonCorrect++;
        break;
	  case 2 : 
		if (playFigure->GetDrawClr()==BLACK )
			{
		Correct ++;
	    Count--;
		pManager->DeleteFigure(playFigure);
		break;
			}
		pManager->DeleteFigure(playFigure);
	    NonCorrect++;
        break;
	  case 3 : 
	    if (playFigure->GetDrawClr()==GREEN && playFigure->get_is_filled()==true)
			{
		Correct ++;
	    Count--;
		pManager->DeleteFigure(playFigure);
		break;
			}
		pManager->DeleteFigure(playFigure);
	    NonCorrect++;
        break;
	  case 4 :
		if (playFigure->GetDrawClr()==BLUE )
			{
		Correct ++;
	    Count--;
		pManager->DeleteFigure(playFigure);
		break;
			}
		pManager->DeleteFigure(playFigure);
	    NonCorrect++;
        break;
	   	  }
		   }
	    pManager->UpdateInterface();
	    playFigure=NULL;
	 }
 	pOut->PrintMessage("Game Over ! Your Score ... Correct Picks : "  + to_string(Correct) + " , NonCorrect Picks : " + to_string(NonCorrect));
	
	}
}