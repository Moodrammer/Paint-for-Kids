#include "sound.h"


#include "..\ApplicationManager.h"

#include "..\GUI\input.h"
#include "..\GUI\Output.h"



sound::sound(ApplicationManager *pApp):Action(pApp)
{}

void sound::ReadActionParameters(){

	//Get a pointe for the input and output interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

}
 

void sound::Execute(){

	Output* pOut = pManager->GetOutput();
	//Call read action parameters to get the selected figure and the required colour
	ReadActionParameters();

	if(pManager->get_sound_operation()==false){
		pOut->PrintMessage("VOICE action is activated");
		pManager->set_sound_operation(true);
	}
	else {
		pOut->PrintMessage("VOICE action is deactivated");
		pManager->set_sound_operation(false);
	}

}