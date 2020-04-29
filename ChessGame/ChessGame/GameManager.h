#pragma once
#include"ChessBoard.h"
class GameManager
{
	ChessBoard m_Chessbrd;
public:
	void Init(HWND hWnd);
	void Draw(HDC hdc);
	GameManager();
	~GameManager();
};

