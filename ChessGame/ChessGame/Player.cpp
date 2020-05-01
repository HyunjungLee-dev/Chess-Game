#include "Player.h"



Player::Player()
{
	m_SelectPiece = NULL;
	m_bPieceMove = FAILURE;
}

void Player::init(int x, int y, COLOR color)
{
	m_PieceList = new ChessPiece;
	m_PieceList->Init(x, y, color);
}

void Player::ListLineDraw(HDC hdc)
{
	Bitmap* LineBitmap = BitmapManager::GetSingleton()->GetBrdBImg(BOARDBLOCK_LINE);
	POINT pos;

	for (int i = 0; i < m_PieceList->GetListSize(); i++)
	{
		pos = m_PieceList->GetPiecePos(i);
		LineBitmap->Draw(hdc, pos.x, pos.y);
	}
}

void Player::SelectLineDraw(HDC hdc)
{
	Bitmap* LineBitmap = BitmapManager::GetSingleton()->GetBrdBImg(BOARDBLOCK_LINE);
	POINT pos;
	if(m_SelectPiece != NULL)
	{	if (!m_SelectPiece->GetRange().empty())
		{
			for (int i = 0; i < m_SelectPiece->GetRange().size(); i++)
			{
				pos.x = m_SelectPiece->GetRange()[i].x;
				pos.y = m_SelectPiece->GetRange()[i].y;
				LineBitmap->Draw(hdc, pos.x, pos.y);
			}
		}
	}
}

void Player::CheckPiece(POINT point)
{
	if (m_SelectPiece != NULL)
	{
		if (PtInRect(&m_SelectPiece->GetRect(), point))
		{
			m_SelectPiece->SetMovecheck(false);
			m_SelectPiece = NULL;
			m_bPieceMove = RETRY;
		}
		else
		{
			MovePiece(point);
		}
	}
	else
	{
		m_SelectPiece = m_PieceList->SetMoveRange(point);
		m_bPieceMove = FAILURE;
	}
	
}

void Player::MovePiece(POINT point)
{
	int size = m_SelectPiece->GetRange().size();
	POINT pos;
	for (int i = 0; i < size; i++)
	{
		pos.x = m_SelectPiece->GetRange()[i].x;
		pos.y = m_SelectPiece->GetRange()[i].y;
		RECT rc = { pos.x / 2 , pos.y / 2 , pos.x / 2 + IMG_WIDTH / 2 , pos.y / 2 + IMG_HEIGHT / 2 };
		if (PtInRect(&rc, point))
		{
			m_SelectPiece->SetPos(pos.x, pos.y);
			m_bPieceMove = SUCCESS;
			m_SelectPiece = NULL;
			return;
		}
		else
		{
			m_bPieceMove = FAILURE;
		}
	}
}


Player::~Player()
{
	delete m_PieceList;
}
