#pragma once
#include "Action.h"
class SaveGridAction :
    public Action
{
	string savefile;
public:
	SaveGridAction(ApplicationManager* pApp);
	virtual void ReadActionParameters();
	virtual void Execute();
	virtual ~SaveGridAction();
};

