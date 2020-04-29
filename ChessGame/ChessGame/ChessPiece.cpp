#include "ChessPiece.h"



ChessPiece::ChessPiece()
{
}

void ChessPiece::Init(int x, int y, COLOR color)	
{
	SetColor(color);
	SetPos(x, y);
}


void ChessPiece::SetPos(int x, int y)	
{
	int index = 0;

	for (int i = 0; i < 8; i++) // y
	{
		for (int j = 0; j < 8; j++) // x
		{
			if (m_ePieceColor == COLOR_W)
			{
				if (i == 6) // 블랙 폰
				{
					ChessPieceList.push_back(AddPiece(PIECEBLOCK_PAWN));
					SetColor(index);
					ChessPieceList[index]->SetPos((j + x)* BLOCK_WIDTH
						, (i + y) * BLOCK_HEIGHT);
					index++;
				}
				else if (i == 7)
				{
					if (j == 0 || j == 7) 
						ChessPieceList.push_back(AddPiece(PIECEBLOCK_ROOK));
					else if (j == 1 || j == 6) 
						ChessPieceList.push_back(AddPiece(PIECEBLOCK_KNIGHT));
					else if (j == 2 || j == 5) 
						ChessPieceList.push_back(AddPiece(PIECEBLOCK_BISHOP));
					else if (j == 3) 
						ChessPieceList.push_back(AddPiece(PIECEBLOCK_QUEEN));
					else 
					{
						ChessPieceList.push_back(AddPiece(PIECEBLOCK_KING));
					}
					SetColor(index);
					ChessPieceList[index]->SetPos((j + x)* BLOCK_WIDTH
						, (i + y) * BLOCK_HEIGHT);
					index++;
				}
			}
			else if (m_ePieceColor == COLOR_B)
			{
				if (i == 1) 
				{
					ChessPieceList.push_back(AddPiece(PIECEBLOCK_PAWN));
					SetColor(index);
					ChessPieceList[index]->SetPos((j + x)* BLOCK_WIDTH
						, (i + y) * BLOCK_HEIGHT);
					index++;
				}
				else if (i == 0)
				{
					if (j == 0 || j == 7) 
						ChessPieceList.push_back(AddPiece(PIECEBLOCK_ROOK));
					else if (j == 1 || j == 6) 
						ChessPieceList.push_back(AddPiece(PIECEBLOCK_KNIGHT));
					else if (j == 2 || j == 5) 
						ChessPieceList.push_back(AddPiece(PIECEBLOCK_BISHOP));
					else if (j == 3) 
						ChessPieceList.push_back(AddPiece(PIECEBLOCK_QUEEN));
					else 
					{
						ChessPieceList.push_back(AddPiece(PIECEBLOCK_KING));
					}
					SetColor(index);
					ChessPieceList[index]->SetPos((j + x)* BLOCK_WIDTH
						, (i + y) * BLOCK_HEIGHT);
					index++;
				}
			}
		}
	}
}

void ChessPiece::SetColor(int index)	//개별 피스의 색상 
{
	ChessPieceList[index]->SetColor(m_ePieceColor);
}

void ChessPiece::Draw(HDC hdc)
{
	for (vector<Block*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		(*it)->Draw(hdc);
	}
}


Block* ChessPiece::AddPiece(PIECEBLOCK Type)
{
	switch (Type)
	{
	case PIECEBLOCK_PAWN:
		return new Pawn;
		break;
	case PIECEBLOCK_KNIGHT:
		return new Knight;
		break;
	case PIECEBLOCK_BISHOP:
		return new Bishop;
		break;
	case PIECEBLOCK_ROOK:
		return new Rook;
		break;
	case PIECEBLOCK_QUEEN:
		return new Queen;
		break;
	case PIECEBLOCK_KING:
		return new King;
		break;
	default:
		break;
	}
}

void ChessPiece::ClearPiece()
{
	for (vector<Block*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		delete (*it);

	}
	ChessPieceList.clear();
}


ChessPiece::~ChessPiece()
{
	ClearPiece();
}
