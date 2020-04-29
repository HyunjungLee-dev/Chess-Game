#pragma once
#include"Block.h"

class ChessBoard : public Block
{
private:
	vector<Block*> ChessBrd;
public:
	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	Block* AddBlock(BOARDBLOCK Type);
	void ClearBlock();
	virtual void SetColor(COLOR color) {};
	ChessBoard();
	~ChessBoard();
};

