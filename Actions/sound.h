#ifndef SOUND_H
#define SOUND_H

#include"Action.h"

class sound : public Action
{
private:

public:
	sound(ApplicationManager *pApp);


	virtual void ReadActionParameters();


	virtual void Execute() ;

};
#endif