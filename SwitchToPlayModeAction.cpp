#include "SwitchToPlayModeAction.h"
#include "Grid.h"

SwitchToPlayModeAction::SwitchToPlayModeAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SwitchToPlayModeAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pO = pGrid->GetOutput();
	pO->PrintMessage("Click anywhere to switch to Play Mode");
	pIn->GetCellClicked();
	pO->ClearStatusBar();
}

void SwitchToPlayModeAction::Execute()
{
	// The first line of any Action Execution is to read its parameter first 
	// and hence initializes its data members
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid();
	Output* pO = pGrid->GetOutput();
	pGrid->NewGame(); //reset
	pO->CreatePlayModeToolBar();
}

SwitchToPlayModeAction::~SwitchToPlayModeAction()
{
}
