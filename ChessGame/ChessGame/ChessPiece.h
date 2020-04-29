#pragma once
#include"Block.h"
class ChessPiece : public Block
{
private:
	vector<Block*> ChessPieceList;
	COLOR m_ePieceColor;
public:
	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	void Init(int x, int y, COLOR color);	
	void SetPieceList();
	void SetColor(COLOR color);
	Block* AddPiece(PIECEBLOCK Type);
	void ClearPiece();
	ChessPiece();
	~ChessPiece();
};

