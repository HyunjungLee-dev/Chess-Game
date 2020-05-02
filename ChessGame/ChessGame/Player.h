#pragma once
#include"ChessPiece.h"
class Player
{
private:
	ChessPiece* m_PieceList;
	Piece* m_SelectPiece;
	COLOR m_PlayerColor;
	SELECT m_bPieceMove;

public:
	void init(int x,int y,COLOR color);
	void ListLineDraw(HDC hdc);
	void SelectLineDraw(HDC hdc);
	void CheckPiece(POINT point, vector<Piece*> v);
	void MovePiece(POINT point);
	ChessPiece* GetPieceList() { return m_PieceList; }
	Piece* GetSelectPiece() { return m_SelectPiece; }
	SELECT GetPieceMove() {return m_bPieceMove	;}
	Player();
	~Player();
};

