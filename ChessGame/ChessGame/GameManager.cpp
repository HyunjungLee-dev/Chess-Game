#include "GameManager.h"



GameManager::GameManager()
{
}

void GameManager::Init(HWND hWnd)			// ��Ʈ�� , ü������, ���� �÷��̾��� �⹰
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
