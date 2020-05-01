#pragma once
#include"ChessPiece.h"
class Player
{
private:
	ChessPiece* m_Piece;
	COLOR m_PlayerColor;

public:
	void init(int x,int y,COLOR color);
	void SelectLineDraw(HDC hdc);
	void CheckPiece(POINT point);
	void MovePiece(int index);
	ChessPiece* GetPiece() { return m_Piece; }
	Player();
	~Player();
};

