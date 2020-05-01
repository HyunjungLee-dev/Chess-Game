#include "ChessPiece.h"



ChessPiece::ChessPiece()
{
}

void ChessPiece::Init(int x, int y, COLOR color)	
{
	SetImgColor(color);
	SetPieceListPos(x, y);
}


void ChessPiece::SetPieceListPos(int x, int y)
{
	int index = 0;

	for (int i = 0; i < 8; i++) // y
	{
		for (int j = 0; j < 8; j++) // x
		{
			if (m_ePieceColor == COLOR_W)
			{
				if (i == 6) 
				{
					ChessPieceList.push_back(AddPiece(PIECETYPE_PAWN));
					SetColor(index);
					ChessPieceList[index]->SetPos((j + x)* BLOCK_WIDTH
						, (i + y) * BLOCK_HEIGHT);
					index++;
				}
				else if (i == 7)
				{
					if (j == 0 || j == 7) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_ROOK));
					else if (j == 1 || j == 6) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_KNIGHT));
					else if (j == 2 || j == 5) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_BISHOP));
					else if (j == 3) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_QUEEN));
					else 
					{
						ChessPieceList.push_back(AddPiece(PIECETYPE_KING));
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
					ChessPieceList.push_back(AddPiece(PIECETYPE_PAWN));
					SetColor(index);
					ChessPieceList[index]->SetPos((j + x)* BLOCK_WIDTH
						, (i + y) * BLOCK_HEIGHT);
					index++;
				}
				else if (i == 0)
				{
					if (j == 0 || j == 7) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_ROOK));
					else if (j == 1 || j == 6) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_KNIGHT));
					else if (j == 2 || j == 5) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_BISHOP));
					else if (j == 3) 
						ChessPieceList.push_back(AddPiece(PIECETYPE_QUEEN));
					else 
					{
						ChessPieceList.push_back(AddPiece(PIECETYPE_KING));
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
	ChessPieceList[index]->SetImgColor(m_ePieceColor);
}

void ChessPiece::PieceListDraw(HDC hdc)
{
	for (vector<Piece*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		(*it)->Draw(hdc);
	}
}

POINT ChessPiece::GetPiecePos(int index)
{
	return ChessPieceList[index]->GetPos();
}


Piece* ChessPiece::AddPiece(PIECETYPE Type)
{
	switch (Type)
	{
	case PIECETYPE_PAWN:
		return new Pawn;
		break;
	case PIECETYPE_KNIGHT:
		return new Knight;
		break;
	case PIECETYPE_BISHOP:
		return new Bishop;
		break;
	case PIECETYPE_ROOK:
		return new Rook;
		break;
	case PIECETYPE_QUEEN:
		return new Queen;
		break;
	case PIECETYPE_KING:
		return new King;
		break;
	default:
		break;
	}
}

void ChessPiece::ClearPiece()
{
	for (vector<Piece*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		delete (*it);

	}
	ChessPieceList.clear();
}


ChessPiece::~ChessPiece()
{
	ClearPiece();
}
