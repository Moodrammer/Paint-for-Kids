#ifndef CFIGURE_H
#define CFIGURE_H

#include "..\defs.h"
#include "..\GUI\Output.h"

//Base class for all figures
class CFigure
{
protected:
	int ID;		//Each figure has an ID
	bool Selected;	//true if the figure is selected.
	GfxInfo FigGfxInfo;	//Figure graphis info

	//static int IDSetter; //M.A:To set a unique ID to each Figure

	Point P1;
	Point P2;
	Point P3;
	
	/// Add more parameters if needed.

public:
	CFigure(GfxInfo FigureGfxInfo);
	color GetDrawClr();
	void SetSelected(bool s);	//select/unselect the figure
	bool IsSelected() const;	//check whether fig is selected
	virtual void Draw(Output* pOut) const  = 0 ;		//Draw the figure
	friend class ApplicationManager;
	void ChngDrawClr(color Dclr);	//changes the figure's drawing color
	void ChngFillClr(color Fclr);	//changes the figure's filling color

	virtual bool Isinsideboundaries(int x, int y) const = 0;    //M.A:To indentify if the point taken is inside the figure or not.

	//M.A : To prevent drawing on toolbar
	virtual bool Isinvalid() = 0;

	virtual void Save(ofstream &outFile) = 0;	//Save the figure parameters to the file
	virtual void Load(ifstream &infile) = 0;	//Load the figure parameters to the file
	///The following functions should be supported by the figure class
	///It should be overridden by each inherited figure

	///Decide the parameters that you should pass to each function	


	void SetID(int id);

	virtual void PrintInfo(Output* pOut) const = 0;	//print all figure info on the status bar

		//M.S
	bool get_is_filled(); // get the figure graphics info
	color get_fill_color();
	color get_draw_color();
	void set_is_filled(bool);

	virtual int get_P1_X()=0; //get the figure coordinates
	virtual int get_P1_Y()=0;
	virtual int get_P2_X()=0;
	virtual int get_P2_Y()=0;
	virtual int get_P3_X()=0;
	virtual int get_P3_Y()=0;


};

#endif