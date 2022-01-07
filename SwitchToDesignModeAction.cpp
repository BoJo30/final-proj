#include "SwitchToDesignModeAction.h"
#include "Grid.h"

SwitchToDesignModeAction::SwitchToDesignModeAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToDesignModeAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pO = pGrid->GetOutput();
	pO->PrintMessage("Click anywhere to switch to Design Mode");
	pIn->GetCellClicked();
	pO->ClearStatusBar();
}

void SwitchToDesignModeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pO = pGrid->GetOutput();
	pGrid->NewGame(); //reset
	pO->CreateDesignModeToolBar();
}

SwitchToDesignModeAction::~SwitchToDesignModeAction()
{
}