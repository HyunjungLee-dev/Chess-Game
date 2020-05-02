#include "GameManager.h"



GameManager::GameManager()
{
	m_iGameTurn = PLAYER_WHITE;
	m_eSelectState = WAIT_SELECTION;
}

void GameManager::Init(HWND hWnd)			// 비트맵 , 체스보드, 각각 플레이어의 기물
{
	BitmapManager::GetSingleton()->Init(hWnd);
	m_Chessbrd.SetPos(0, 0);
	m_player[PLAYER_BLACK].init(0, 0, COLOR_B);
	m_player[PLAYER_WHITE].init(0, 0, COLOR_W);
}

void GameManager::Draw(HDC hdc)
{
	m_Chessbrd.Draw(hdc);
	m_player[PLAYER_BLACK].GetPieceList()->PieceListDraw(hdc);
	m_player[PLAYER_WHITE].GetPieceList()->PieceListDraw(hdc);
	TurnLineDraw(hdc);

}

void GameManager::TurnLineDraw(HDC hdc)
{
	if(m_eSelectState == WAIT_SELECTION)
		m_player[m_iGameTurn].ListLineDraw(hdc);
	else if(m_eSelectState == SELECTING)
		m_player[m_iGameTurn].SelectLineDraw(hdc);
}

vector<Piece*>  GameManager::MovableRange()
{
	vector<Piece*> AllPiece;
	vector<Piece*> BlackPiece = m_player[PLAYER_BLACK].GetPieceList()->GetPiece();
	vector<Piece*> WhitePiece  = m_player[PLAYER_WHITE].GetPieceList()->GetPiece();

	AllPiece.insert(AllPiece.end(), BlackPiece.begin(), BlackPiece.end());
	AllPiece.insert(AllPiece.end(), WhitePiece.begin(), WhitePiece.end());

	return AllPiece;
	
}

void GameManager::ClickCheck(POINT point)
{
		m_player[m_iGameTurn].CheckPiece(point, MovableRange());
		if (m_player[m_iGameTurn].GetPieceMove() == SUCCESS)
		{
			if (m_iGameTurn == PLAYER_WHITE)
				m_iGameTurn = PLAYER_BLACK;
			else
				m_iGameTurn = PLAYER_WHITE;
			m_eSelectState = WAIT_SELECTION;
		}
		else if(m_player[m_iGameTurn].GetPieceMove() == RETRY )
			m_eSelectState = WAIT_SELECTION;
		else if (m_player[m_iGameTurn].GetPieceMove() == FAILURE)
			m_eSelectState = SELECTING;
}


void GameManager::GamePlay(HWND hWnd, POINT point)
{
	m_eSelectState = SELECTING;
	ClickCheck(point);
	InvalidateRect(hWnd, NULL, true);
}


GameManager::~GameManager()
{
}
