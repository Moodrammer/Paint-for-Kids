#include "paste_figure.h"
#include "..\ApplicationManager.h"
#include "..\GUI\input.h"
#include "..\GUI\Output.h"



paste_figure::paste_figure(ApplicationManager *pApp):Action(pApp)
{}

void paste_figure::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	

	pOut->PrintMessage("paste Figure:click at the point where you want to paste the copied\cut figure");
	pIn->GetPointClicked(P.x, P.y);  // getting the point where the user wnats to paste his figure
	
}

void paste_figure::Execute(){
	
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	cut_copied_figure=pManager->get_cut_copied_figure();
		if(cut_copied_figure==NULL){    //must click on the copy or cut icon before pasting the figure
	pOut->PrintMessage("please select a figure and click on the copy/cut icon first !");
	}	
		else{
	ReadActionParameters();

	    if(dynamic_cast<CRhombos*>(cut_copied_figure)){  //dynamic casting to detect the cut/copied figure 

		rhombos_gfxinfo=pManager->get_copied_cut_figure_gfxinfo();
		if(P.y>UI.ToolBarHeight&&P.y<UI.height-UI.StatusBarHeight){
		CRhombos *R=new CRhombos(P,rhombos_gfxinfo);	 //creating new Rhombos 
		pManager->AddFigure(R);
		pManager->UpdateInterface();


		if(pManager->get_cut_operation()){  //if the operation was cut operation the figure will be pasted once and then will be deleted
			pManager->DeleteFigure(cut_copied_figure);  
			pManager->UpdateInterface();
		}
		
		}

		if(P.y>UI.ToolBarHeight&&P.y<UI.height-UI.StatusBarHeight){  //using recursion to deal with multiple clicks on the drawing area
			                                                        // so the figure will be pasted more than one time if it was copied
			                                                       //  if it was a cut figure it will be pasted once then the clipboard 
			                                                      //   will be set to NULL
		   if(pManager->get_cut_operation()==false)
			Execute();
		   else
			  pManager->copied_cut_figure_NULL();
		}
	}
	
	
		else if(dynamic_cast<CEllipse*>(cut_copied_figure)){  //dynamic casting to detect the cut/copied figure 

		ellipse_gfxinfo=pManager->get_copied_cut_figure_gfxinfo();
		if(P.y>UI.ToolBarHeight&&P.y<UI.height-UI.StatusBarHeight){
		CEllipse *R=new CEllipse(P,ellipse_gfxinfo);	 //creating new ellipse 
		pManager->AddFigure(R);
		pManager->UpdateInterface();


		if(pManager->get_cut_operation()){  //if the operation was cut operation the figure will be pasted once and then will be deleted
			pManager->DeleteFigure(cut_copied_figure);  
			pManager->UpdateInterface();
		}
		
		}

		if(P.y>UI.ToolBarHeight&&P.y<UI.height-UI.StatusBarHeight){  //using recursion to deal with multiple clicks on the drawing area
			                                                        // so the figure will be pasted more than one time if it was copied
			                                                       //  if it was a cut figure it will be pasted once then the clipboard 
			                                                      //   will be set to NULL
		   if(pManager->get_cut_operation()==false)
			Execute();
		   else
			   pManager->copied_cut_figure_NULL();
		}
	}
	
   else if (dynamic_cast<CLine*>(cut_copied_figure)){
	   line_gfxinfo=pManager->get_copied_cut_figure_gfxinfo();  
	   int copied_P1_X=cut_copied_figure->get_P1_X(); // here we get the copied/cut figure coordinates
	   int copied_P1_Y=cut_copied_figure->get_P1_Y();
	   int copied_P2_X=cut_copied_figure->get_P2_X();
	   int copied_P2_Y=cut_copied_figure->get_P2_Y();
	   double copied_P_X=(copied_P1_X+copied_P2_X)/2;
	   double copied_P_Y=(copied_P1_Y+copied_P2_Y)/2;
	   int x_diff=-(copied_P_X-P.x);                 //using some geometric to make the pasted figure similar to the copied/cut figure
	   int y_diff=-(copied_P_Y-P.y);                // and make the clicked point the center of the pasted figure


	   P1.x=x_diff+copied_P1_X;
	   P1.y=y_diff+copied_P1_Y;
	   P2.x=x_diff+copied_P2_X;
	   P2.y=y_diff+copied_P2_Y;
	   if(P.y>UI.ToolBarHeight&&P.y<UI.height-UI.StatusBarHeight){
		CLine *R=new CLine(P1, P2,line_gfxinfo);
		pManager->AddFigure(R);
		pManager->UpdateInterface();

	 
		if(pManager->get_cut_operation()){    
			pManager->DeleteFigure(cut_copied_figure);
			pManager->UpdateInterface();
		}
	   }
		if(P.y>UI.ToolBarHeight&&P.y<UI.height-UI.StatusBarHeight){
		   if(pManager->get_cut_operation()==false)
			Execute();
		   else
			 pManager->copied_cut_figure_NULL();
		}

   }
   else if(dynamic_cast<CTriangle*>(cut_copied_figure)){
	   triangle_gfxinfo=pManager->get_copied_cut_figure_gfxinfo();
	   int copied_P1_X=cut_copied_figure->get_P1_X();
	   int copied_P1_Y=cut_copied_figure->get_P1_Y();
	   int copied_P2_X=cut_copied_figure->get_P2_X();
	   int copied_P2_Y=cut_copied_figure->get_P2_Y();
	   int copied_P3_X=cut_copied_figure->get_P3_X();
	   int copied_P3_Y=cut_copied_figure->get_P3_Y();

	   double copied_P_X=(copied_P1_X+copied_P2_X+copied_P3_X)/3;
	   double copied_P_Y=(copied_P1_Y+copied_P2_Y+copied_P3_Y)/3;

	   int x_diff=-(copied_P_X-P.x);
	   int y_diff=-(copied_P_Y-P.y);	

	   P1.x=x_diff+copied_P1_X;
	   P1.y=y_diff+copied_P1_Y;
	   P2.x=x_diff+copied_P2_X;
	   P2.y=y_diff+copied_P2_Y;
	   P3.x=x_diff+copied_P3_X;
	   P3.y=y_diff+copied_P3_Y;
	   
   if(P.y>UI.ToolBarHeight&&P.y<UI.height-UI.StatusBarHeight){
		CTriangle *R=new CTriangle(P1, P2,P3,triangle_gfxinfo);
		pManager->AddFigure(R);
		pManager->UpdateInterface();

	 
		if(pManager->get_cut_operation()){    
			pManager->DeleteFigure(cut_copied_figure);
			pManager->UpdateInterface();
		}
	   }
	if(P.y>UI.ToolBarHeight&&P.y<UI.height-UI.StatusBarHeight){
	if(pManager->get_cut_operation()==false)
		Execute();
    else
	 pManager->copied_cut_figure_NULL();
		}
		
   }

   else if(dynamic_cast<CRectangle*>(cut_copied_figure)){
	   
	   rectangle_gfxinfo=pManager->get_copied_cut_figure_gfxinfo();
	   double height=abs(cut_copied_figure->get_P1_Y()-cut_copied_figure->get_P2_Y())/2;
	   double width=abs(cut_copied_figure->get_P1_X()-cut_copied_figure->get_P2_X())/2;
	   P1.x=width+P.x;
	   P1.y=height+P.y;
	   P2.x=-width+P.x;
	   P2.y=-height+P.y;

	     if(P.y>UI.ToolBarHeight&&P.y<UI.height-UI.StatusBarHeight){
		CRectangle *R=new CRectangle(P1, P2, rectangle_gfxinfo);
		pManager->AddFigure(R);
		pManager->UpdateInterface();

	 
		if(pManager->get_cut_operation()){    
			pManager->DeleteFigure(cut_copied_figure);
			pManager->UpdateInterface();
		}
	   }
	if(P.y>UI.ToolBarHeight&&P.y<UI.height-UI.StatusBarHeight){
	if(pManager->get_cut_operation()==false)
		Execute();
    else
		   pManager->copied_cut_figure_NULL();
		}

   }   
   pManager->set_cut_operation(false);
}
}

