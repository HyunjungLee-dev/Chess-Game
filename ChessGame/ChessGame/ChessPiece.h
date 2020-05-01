#pragma once
#include"Piece.h"
class ChessPiece : public Piece
{
private:
	COLOR m_ePieceColor;
	vector<Piece*> ChessPieceList;
public:
	void Init(int x, int y, COLOR color);
	Piece* AddPiece(PIECETYPE Type);
	void SetPieceListPos(int x, int y);
	void SetColor(int index);
	virtual void SetImgColor(COLOR color) { m_ePieceColor = color; }
	void PieceListDraw(HDC hdc);
	POINT GetPiecePos(int index);
	int GetListSize() { return ChessPieceList.size(); }
	virtual void SetMoveRange() {};
	Piece* SetMoveRange(POINT point);
	void ClearPiece();
	ChessPiece();
	~ChessPiece();
};

