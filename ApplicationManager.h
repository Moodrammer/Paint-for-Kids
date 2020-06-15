#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "DEFS.h"
#include "Figures\CFigure.h"
#include "GUI\input.h"
#include "GUI\output.h"

//Main class that manages everything in the application.
class ApplicationManager
{
	enum { MaxFigCount = 200 };	//Max no of figures

private:
	int FigCount;		//Actual number of figures
	CFigure* FigList[MaxFigCount];	//List of all figures (Array of pointers)

	CFigure* SelectedFig; //Pointer to the selected figure
	CFigure* Clipboard;   //Pointer to the copied/cut figure

	GfxInfo copy_cut_gfxinfo; //MS the graphics info of the copied/cut figure
	bool cut_operation;      //MS boolean variable to detect if the operation is cut or paste
	
    bool figure_sound;

	//Pointers to Input and Output classes
	Input *pIn;
	Output *pOut;
	int ExistNum [6];
	int GameType;
public:	
	ApplicationManager(); 
	~ApplicationManager();
	
	// -- Action-Related Functions
	//Reads the input command from the user and returns the corresponding action type
	ActionType GetUserAction() const;
	void ExecuteAction(ActionType) ; //Creates an action and executes it
	
	// -- Figures Management Functions
	void AddFigure(CFigure* pFig);          //Adds a new figure to the FigList
	CFigure *GetFigure(int x, int y) const; //Search for a figure given a point inside the figure
		
	// -- Interface Management Functions
	Input *GetInput() const; //Return pointer to the input
	Output *GetOutput() const; //Return pointer to the output
	void UpdateInterface() const;	//Redraws all the drawing window

	// -- Select Action Functions
	void setselectedfig(CFigure* pFig); //M.a: Sets a figure to be selected
	CFigure* Getselectedfigure() const; //M.a: Returns the current selected figure
	void SetSelectedfigNULL(); //M.A: To set selcted figure to NULL

	// -- Save/Load Action functions
	void SaveAll(ofstream &outFile);
	void SaveByTypeFn(ofstream &outFile, ActionType A);
	void deleteAll();
	bool isEmpty();
	bool isFound(ActionType);

	// -- Delete Action Functions
	void DeleteFigure(CFigure* pFig); //M.A: searches for the selected figure,Deletes it,then shifts the whole array and decreases fig count
	
	//-- Play Mode actions
	int* ExistType ();
    int NumCertainShapes(int r);
	void setGameType(int);

	// -- Swaping Functions
	void SwapBackward(CFigure* pFig); //M.A:to send a Figure one step Backward
	void SwapForward(CFigure* pFig);
	
	//-- copy --cut--paste functions
	void copied_cut_figure_NULL();                //MS  set lipboard to NULL
	CFigure* get_cut_copied_figure();            //MS get clipboard
	void set_cut_copied_figure(CFigure*pFig);   //MS set clipboar

	void set_copied_cut_figure_gfxinfo(GfxInfo figure_gfxinfo); //MS set the copied/cut figure graphics info
	GfxInfo get_copied_cut_figure_gfxinfo();                   //MS get the copied/cut figure graphics info

	void set_cut_operation(bool);   //MS set this function to true if the operation is cut otherwise false
	bool get_cut_operation();      //MS returns true if the operation is cut otherwise returns false

	void change_gfxinfo();

//sound functions 
    void set_sound_operation(bool);
	bool get_sound_operation();


	

};

#endif