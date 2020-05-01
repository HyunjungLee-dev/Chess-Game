#pragma once
#include"ChessBoard.h"
#include"Player.h"
class GameManager
{
	ChessBoard m_Chessbrd;
	Player  m_player[PLAYER_END];
	PLAYER m_iGameTurn;
public:
	void Init(HWND hWnd);
	void Draw(HDC hdc);
	void TurnLineDraw(HDC hdc);
	void ClickCheck(POINT point);
	void GamePlay(HWND hWnd, POINT point);
	GameManager();
	~GameManager();
};

