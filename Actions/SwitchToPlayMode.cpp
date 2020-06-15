#include "SwitchToPlayMode.h"

#include "..\ApplicationManager.h"

#include "..\GUI\Input.h"
#include "..\GUI\Output.h"
#include <iostream>
#include <fstream>

SwitchToPlayMode::SwitchToPlayMode(ApplicationManager * pApp) :Action(pApp)
{}

SwitchToPlayMode::~SwitchToPlayMode()
{
}
void SwitchToPlayMode::ReadActionParameters() {
	//empty
}

void SwitchToPlayMode::Execute() {
	Output* pOut = pManager->GetOutput();
	pOut->ClearStatusBar();
	ofstream myfile;
	myfile.open("temp.txt");
	pManager->SaveAll(myfile);
	myfile.close();
	
	//To deselect the figure on  switching 
	CFigure* Deselect = pManager->Getselectedfigure();
	if(Deselect != NULL)
	{
	Deselect->SetSelected(false);
	pManager->SetSelectedfigNULL();
	}
	//To delete the cut operation
	if(pManager->get_cut_operation()){    //for handling the case of cut a figure then switch to play mode 
			pManager->change_gfxinfo();
		}
	
	pOut->ClearToolBar();
	pOut->CreatePlayToolBar();
}
