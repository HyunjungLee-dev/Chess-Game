#pragma once
#include"ChessBoard.h"
#include"ChessPiece.h"
class GameManager
{
	ChessBoard m_Chessbrd;
	ChessPiece m_Piece[COLOR_END];
	int m_iGameTrun;
public:
	void Init(HWND hWnd);
	void Draw(HDC hdc);
	void TurnLineDraw(HDC hdc);
	GameManager();
	~GameManager();
};

