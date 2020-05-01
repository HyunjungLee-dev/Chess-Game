#pragma once
#include"Piece.h"
class ChessPiece : public Piece
{
private:
	COLOR m_ePieceColor;
	vector<Piece*> ChessPieceList;
public:
	void SetPieceListPos(int x, int y);
	void PieceListDraw(HDC hdc);
	POINT GetPiecePos(int index);
	void Init(int x, int y, COLOR color);
	void SetColor(int index);
	Piece* AddPiece(PIECETYPE Type);
	int GetListSize() { return ChessPieceList.size(); }	
	virtual void SetMoveRange() {};
	virtual void SetImgColor(COLOR color) { m_ePieceColor = color; }
	void ClearPiece();
	ChessPiece();
	~ChessPiece();
};

