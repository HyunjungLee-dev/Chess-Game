#include "GameManager.h"



GameManager::GameManager()
{
}

void GameManager::Init(HWND hWnd)			// 비트맵 , 체스보드, 각각 플레이어의 기물
{
	BitmapManager::GetSingleton()->Init(hWnd);
	m_Chessbrd.SetPos(0, 0);
}

void GameManager::Draw(HDC hdc)
{
	m_Chessbrd.Draw(hdc);
}


GameManager::~GameManager()
{
}
