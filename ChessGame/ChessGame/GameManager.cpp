#include "GameManager.h"



GameManager::GameManager()
{
	m_iGameTrun = 0;
}

void GameManager::Init(HWND hWnd)			// 비트맵 , 체스보드, 각각 플레이어의 기물
{
	BitmapManager::GetSingleton()->Init(hWnd);
	m_Chessbrd.SetPos(0, 0);
	m_Piece[COLOR_B].Init(0, 0, COLOR_B);
	m_Piece[COLOR_W].Init(0, 0, COLOR_W);
}

void GameManager::Draw(HDC hdc)
{
	m_Chessbrd.Draw(hdc);
	m_Piece[COLOR_B].Draw(hdc);
	m_Piece[COLOR_W].Draw(hdc);
}

void GameManager::TurnLineDraw(HDC hdc)
{
	if (m_iGameTrun % 2 != 0) // 백
	{

	}
	else // 흑
	{

	}

}


GameManager::~GameManager()
{
}
