#include "GameManager.h"



GameManager::GameManager()
{
	m_iGameTurn = PLAYER_WHITE;
}

void GameManager::Init(HWND hWnd)			// ��Ʈ�� , ü������, ���� �÷��̾��� �⹰
{
	BitmapManager::GetSingleton()->Init(hWnd);
	m_Chessbrd.SetPos(0, 0);
	m_player[PLAYER_BLACK].init(0, 0, COLOR_B);
	m_player[PLAYER_WHITE].init(0, 0, COLOR_W);
}

void GameManager::Draw(HDC hdc)
{
	m_Chessbrd.Draw(hdc);
	m_player[PLAYER_BLACK].GetPiece()->PieceListDraw(hdc);
	m_player[PLAYER_WHITE].GetPiece()->PieceListDraw(hdc);
	TurnLineDraw(hdc);

}

void GameManager::TurnLineDraw(HDC hdc)
{
	if (m_iGameTurn == PLAYER_WHITE) // ��
	{
		m_player[PLAYER_WHITE].SelectLineDraw(hdc);
	}
	else // ��
	{
		m_player[PLAYER_BLACK].SelectLineDraw(hdc);
	}
}

void GameManager::ClickCheck(POINT point)
{
	if (m_iGameTurn == PLAYER_WHITE) // ��
	{
	}
	else // ��
	{
	}
}

void GameManager::GamePlay(HWND hWnd, POINT point)
{

}


GameManager::~GameManager()
{
}
