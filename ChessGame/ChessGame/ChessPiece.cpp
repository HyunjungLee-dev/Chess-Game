#include "ChessPiece.h"



ChessPiece::ChessPiece()
{
}

void ChessPiece::Init(int x, int y, COLOR color)	 // �Ҵ� -> ���� -> pos 
{
	SetPieceList();
	SetColor(color);
	SetPos(x, y);
}

void ChessPiece::SetPieceList()	
{
	// pawn 8�� king 1��, queen 1�� , knight 2��, bishop 2��, rook 2��

	for (int i = PIECENUM_NONE; i < PIECENUM_ALL; i++)
	{
		if (i >= PIECENUM_NONE && i < PIECENUM_PAWN)
			ChessPieceList.push_back(AddPiece(PIECEBLOCK_PAWN));
	}
}

void ChessPiece::SetPos(int x, int y)	//��� �ǽ� ���� �ǽ� ��ġ   �ֱ�
{
	if (m_ePieceColor == COLOR_B)
	{

	}
	else if(m_ePieceColor == COLOR_W)
	{

	}

}

void ChessPiece::SetColor(COLOR color)	//���� �ǽ��� ���� 
{
	m_ePieceColor = color;
	for (vector<Block*>::iterator it = ChessPieceList.begin(); it != ChessPieceList.end(); it++)
	{
		(*it)->SetColor(m_ePieceColor);
	}
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
