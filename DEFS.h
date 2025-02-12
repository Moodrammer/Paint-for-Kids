#ifndef DEFS_H
#define DEFS_H

#include "CMUgraphicsLib\CMUgraphics.h"

//This file contains some global constants and definitions to be used in the project.
enum ActionType //The actions supported (you can add more if needed)
{
	DRAW_LINE,		//Draw Line
	DRAW_RECT,		//Draw Rectangle
	DRAW_TRI,		//Draw Triangle
	DRAW_RHOMBUS,		//Draw Rhombus
	DRAW_ELLIPSE,		//Draw Ellipse
	SELECT,           //=========================M.A : TO SELECT A FIGURE
	CHNG_DRAW_CLR,	//Change the drawing color
	CHNG_FILL_CLR,	//Change the filling color
	RED_CLR,        //============================M.A : Choosing a colour
	BLUE_CLR,
	WHITE_CLR,
	GREEN_CLR,
	BLACK_CLR,
	CPY,            //===============M.A:COPY A FIGURE AFTER SELECTING
	CUT,             //================M.A:CUT A FIGURE AFTER SELECTING
	PASTE,           //================M.A: PASTE A FIGURE AFTER SELECTING
	DEL,			//Delete a figure(s)
	SAVE,			//Save the whole graph to a file
	SAVE_BY_TYPE,	//Save the all the figures that have a specific type
	LOAD,			//Load a graph from a file
	EXIT,			//Exit the application

	DRAWING_AREA,	//A click on the drawing area
	STATUS,			//A click on the status bar
	EMPTY,			//A click on empty place in the toolbar

	TO_DRAW,		//Switch interface to Draw mode
	TO_PLAY,			//Switch interface to Play mode
	SELECT_BY_TYPE,
	SELECT_BY_COLOUR,
	
	RESIZE,
	SEND_TO_BACK,
	BRING_TO_FRONT,
	SOUND

	///TODO: Add more action types (if needed)


	///TODO: Add more action types (if needed)
};

struct Point	//To be used for figures points
{ int x,y; };

struct GfxInfo	//Graphical info of each figure (you may add more members)
{
	color DrawClr;	//Draw color of the figure
	color FillClr;	//Fill color of the figure
	bool isFilled;	//Figure Filled or not
	int BorderWdth;	//Width of figure borders

};

#endif