#include "ChessBoard.h"



ChessBoard::ChessBoard()
{
}

void ChessBoard::SetBlock(int x, int y)
{
}

void ChessBoard::SetPos()
{

}

void ChessBoard::Draw(HDC hdc)
{

}

Block* ChessBoard::AddBlock(BOARDBLOCK Type)
{
	switch (Type)
	{
	case BOARDBLOCK_LIGHT:
		return new Light;
		break;
	case BOARDBLOCK_DARK:
		return new Dark;
		break;
	default:
		break;
	}
}

void ChessBoard::ClearBlock()
{

}


ChessBoard::~ChessBoard()
{
}
