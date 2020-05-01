#include "Player.h"



Player::Player()
{
}

void Player::init(int x, int y, COLOR color)
{
	m_Piece = new ChessPiece;
	m_Piece->Init(x, y, color);
}

void Player::SelectLineDraw(HDC hdc)
{
	Bitmap* LineBitmap = BitmapManager::GetSingleton()->GetBrdBImg(BOARDBLOCK_LINE);
	POINT pos;

	for (int i = 0; i < m_Piece->GetListSize(); i++)
	{
		pos = m_Piece->GetPiecePos(i);
		LineBitmap->Draw(hdc, pos.x, pos.y);
	}
}

void Player::CheckPiece(POINT point)
{
	for (int i = 0; i < m_Piece->GetListSize(); i++)
	{
		if (PtInRect(&m_Piece->GetRect(),point))//
		{
			//선택 체스 이동 가능 위치 line block
			MovePiece(i);
			break;
		}
	}
}

void Player::MovePiece(int index)
{

}


Player::~Player()
{
	delete m_Piece;
}
