#include "..\Actions\ByType.h"
#include "..\ApplicationManager.h"
#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include "..\Figures\CRectangle.h"
#include "..\Figures/CEllipse.h"
#include "..\Figures/CLine.h"
#include "..\Figures/CRhombos.h"
#include "..\Figures/CTriangle.h"
#include <stdlib.h>
#include <time.h>

ByType::ByType(ApplicationManager * pApp):Action(pApp)
{}
void ByType::ReadActionParameters()
{	
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	pIn->GetPointClicked(P.x, P.y);

}

//Execute the action
void ByType::Execute() 
{
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	pManager->setGameType(0); //To get the output of application manager as pick by type mode
	int r; // random	
	Input* pIn = pManager->GetInput();
    pManager->ExecuteAction(LOAD);  ////// restart  //////////////
    pManager->UpdateInterface();   ////// the game /////////////
	int* ExistFig=pManager->ExistType(); // determine exist shapes or coloures
	if(ExistFig==NULL)
	  {
    pOut->PrintMessage("Make some Shapes First to plaay !!!! ");
	  }
	else
	  {
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
	  switch (r)
         { 
        case 0 :
		 pOut->PrintMessage("Pick up all Ellipses !!!! ");
	     break;
	    case 1 :
		 pOut->PrintMessage("Pick up all Lines !!!! ");
		 break;
		case 2 : 
		 pOut->PrintMessage("Pick up all Rectangles !!!! ");
	  	 break;
		case 3 :
		 pOut->PrintMessage("Pick up all Rhomboses!!!! ");
   		 break;
		case 4 :
		 pOut->PrintMessage("Pick up all Triangles !!!! ");
		 break;
         }
	int Count =pManager->NumCertainShapes(r); // determine number of shapes should be picked to win
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
		 case ITM_EXIT2:
		   return;
		 default:
		   return;	//A click on empty place in desgin toolbar
			}
		  }
	   playFigure=pManager->GetFigure(P.x, P.y);
	   if (playFigure!=NULL)
		 {
	  switch(r)
		  {
		 case 0:
		   CEllipse * ell;
		   ell = dynamic_cast<CEllipse *> (playFigure);
		   if (ell != NULL)
			 {
		   Correct ++;
		   Count--;
		   pManager->DeleteFigure(playFigure);
		   break;
			 }
		   pManager->DeleteFigure(playFigure);
		   NonCorrect++;
		   break;
		  case 1:
		   CLine * line;
		   line = dynamic_cast<CLine *> (playFigure);
		   if (line != NULL  )
			 {
		   Correct ++;
		   Count--;
		   pManager->DeleteFigure(playFigure);
		   break;
			 }
		   pManager->DeleteFigure(playFigure);
		   NonCorrect++;
		   break;
		  case 2:
		   CRectangle * rect;
		   rect = dynamic_cast<CRectangle *> (playFigure);
		   if (rect != NULL)
			 {
		   Correct ++;
		   Count--;
		   pManager->DeleteFigure(playFigure);
		   break;
     		 }
		   pManager->DeleteFigure(playFigure);
		   NonCorrect++;
		   break;
		  case 3:
		   CRhombos * rhom;
		   rhom = dynamic_cast<CRhombos *> (playFigure);
		   if (rhom != NULL)
			 {
		   Correct ++;
		   Count--;
		   pManager->DeleteFigure(playFigure);
		   break;
			 }
		   pManager->DeleteFigure(playFigure);
		   NonCorrect++;
		   break;
		  case 4:
	   CTriangle * tri;
	   tri = dynamic_cast<CTriangle *> (playFigure);
	   if (tri != NULL)
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