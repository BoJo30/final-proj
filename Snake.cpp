#include "Snake.h"
#include<fstream>

Snake::Snake(const CellPosition& startCellPos, const CellPosition& endCellPos) : GameObject(startCellPos)
{
	///TODO: Do the needed validation
	if (endCellPos.HCell() == startCellPos.HCell() && endCellPos.VCell() > startCellPos.VCell())
	{
		this->endCellPos = endCellPos;
	}

}

void Snake::Draw(Output* pOut) const
{
	pOut->DrawLadder(position, endCellPos);
}

void Snake::Apply(Grid* pGrid, Player* pPlayer)
{


	///TODO: Implement this function as mentioned in the guideline steps (numbered below) below
	Output* pOut = pGrid->GetOutput();
	Input* pIn = pGrid->GetInput();

	// == Here are some guideline steps (numbered below) to implement this function ==

	// 1- Print a message "You have reached a Snake. Click to continue ..." and wait mouse click

	pOut->PrintMessage("You have reached a Snake. Click to continue ...");
	pIn->GetCellClicked();
	pOut->ClearStatusBar();

	// 2- Apply the snake's effect by moving the player to the endCellPos
	//    Review the "pGrid" functions and decide which function can be used for that
	pGrid->UpdatePlayerCell(pPlayer, endCellPos);
}
bool Snake::IsOverlapping(GameObject* newObj)const
{
	Snake* passedsnake = dynamic_cast <Snake*> (newObj);
	if (passedsnake != NULL)
	{
		if (passedsnake->GetPosition().HCell() == this->GetPosition().HCell() || passedsnake->GetEndPosition().HCell() == this->GetPosition().HCell())
		{
			if (passedsnake->GetEndPosition().VCell() > this->GetPosition().VCell() && passedsnake->GetEndPosition().VCell() < this->GetEndPosition().VCell())
			{
				return true;
			}
			else if (passedsnake->GetPosition().VCell() > this->GetPosition().VCell() && passedsnake->GetPosition().VCell() < this->GetEndPosition().VCell())
			{
				return true;
			}
			else if (passedsnake->GetPosition().VCell() == this->GetPosition().VCell() || passedsnake->GetEndPosition().VCell() == this->GetPosition().VCell())
			{
				return true;
			}
			else return false;
		}
	}
}

void Snake::Save(ofstream& OutFile, ObjType Obj)
{
	if (Obj == snake)
	{
		OutFile << GetPosition().GetCellNum() << " " << GetEndPosition().GetCellNum();
	}
}

void Snake::Load(ifstream& Infile, Grid* pGrid)
{
	int  StartCellNum, EndCellNum;
	Infile >> StartCellNum, EndCellNum;
	CellPosition StartCellpos, EndCellpos;
	Snake* newpassedSnake = new Snake(StartCellpos.GetCellPositionFromNum(StartCellNum), EndCellpos.GetCellPositionFromNum(EndCellNum));
	pGrid->AddObjectToCell(newpassedSnake);
}

CellPosition Snake::GetEndPosition() const
{
	return endCellPos;
}

Snake::~Snake()
{
}

