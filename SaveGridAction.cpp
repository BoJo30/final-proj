#include "SaveGridAction.h"
#include "Grid.h"
#include <fstream>

SaveGridAction::SaveGridAction(ApplicationManager* pApp) : Action(pApp)
{
}

void SaveGridAction::ReadActionParameters()
{
	Grid* pGrid = pManager->GetGrid();
	Input* pIn = pGrid->GetInput();
	Output* pO = pGrid->GetOutput();
	pO->PrintMessage("Enter name of the save file:");
	savefile = pIn->GetSrting(pO);
	savefile = savefile + ".txt"; //text file format required 
	pO->ClearStatusBar();
}

void SaveGridAction::Execute()
{
	ReadActionParameters();
	Grid* pGrid = pManager->GetGrid(); //pointer to grid interface for ease of function calls
	Input* pIn = pGrid->GetInput();
	Output* pO = pGrid->GetOutput();
	ofstream OutFile;
	OutFile.open(savefile, ios::out); //creates/opens the file in savefile and defines it being for output 
	if (OutFile.fail()) //check if the output file has failed to open, and if so, abort
	{
		pGrid->PrintErrorMessage("ERROR: the save file could not be opened");
		return;
	}
	OutFile << pGrid->GetLaddersNum() << endl; //can use ofstream as if it's cout,, printing the number of gameobjects before their details as specified and in the given order
	pGrid->SaveAll(OutFile, ladder);

	OutFile << pGrid->GetSnakesNum() << endl;
	pGrid->SaveAll(OutFile, snake);

	OutFile << pGrid->GetCardsNum() << endl;
	pGrid->SaveAll(OutFile, card);

	OutFile.close();
	pO->PrintMessage("Save successful, click anywhere to continue..");
	pIn->GetCellClicked();
	pO->ClearStatusBar();
}

SaveGridAction::~SaveGridAction()
{
}
