#pragma once
#include"Block.h"
class ChessPiece : public Block
{
private:
	COLOR m_ePieceColor;
	vector<Block*> ChessPieceList;
public:
	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	void Init(int x, int y, COLOR color);
	void SetColor(int index);
	Block* AddPiece(PIECEBLOCK Type);
	void ClearPiece();
	virtual void SetColor(COLOR color){m_ePieceColor	= color;}
	ChessPiece();
	~ChessPiece();
};

