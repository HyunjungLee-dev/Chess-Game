#pragma once
#include"Block.h"

class ChessBoard : public Block
{
private:
	vector<Block*> ChessBrd;
public:
	virtual void SetBlock(int x, int y);
	virtual void Draw(HDC hdc);
	Block* AddBlock(BOARDBLOCK Type);
	void SetPos();
	void ClearBlock();
	ChessBoard();
	~ChessBoard();
};

