#include "Piece.h"



Piece::Piece()
{
}


void Piece::SetPos(int x, int y)
{
	pos.x = x;
	pos.y = y;
	m_PieceRect.left = x*0.5;
	m_PieceRect.top = y*0.5;
	m_PieceRect.right = m_PieceRect.left + m_pBitmap->GetSize().cx*0.5;
	m_PieceRect.bottom = m_PieceRect.top + m_pBitmap->GetSize().cy*0.5;
}

void Piece::Draw(HDC hdc)
{
	m_pBitmap->Draw(hdc, pos.x, pos.y);
}

Piece::~Piece()
{
}

King::King()
{
}

void King::SetImgColor(COLOR color)
{
	m_eColor = color;
	if (m_eColor == COLOR_W)
		m_ePieceType = PIECE_W_KING;
	else
		m_ePieceType = PIECE_B_KING;
	m_pBitmap = BitmapManager::GetSingleton()->GetPieceImg(m_ePieceType);
}


void King::SetMoveRange()
{
	int x[] = { -1,0,1,-1,0,1,-1,0,1 };
	int y[] = { -1,-1,-1,0,0,0,1,1,1 };

	for (int i = 0; i < 9; i++)
	{

	}
}



Queen::Queen()
{
}

void Queen::SetImgColor(COLOR color)
{
	m_eColor = color;
	if (m_eColor == COLOR_W)
		m_ePieceType = PIECE_W_QUEEN;
	else
		m_ePieceType = PIECE_B_QUEEN;
	m_pBitmap = BitmapManager::GetSingleton()->GetPieceImg(m_ePieceType);
}


void Queen::SetMoveRange()
{

}

Bishop::Bishop()
{
}

void Bishop::SetImgColor(COLOR color)
{
	m_eColor = color;
	if (m_eColor == COLOR_W)
		m_ePieceType = PIECE_W_BISHOP;
	else
		m_ePieceType = PIECE_B_BISHOP;
	m_pBitmap = BitmapManager::GetSingleton()->GetPieceImg(m_ePieceType);
}


void Bishop::SetMoveRange()
{

}


Pawn::Pawn()
{
	m_bMove = false;
}

void Pawn::SetImgColor(COLOR color)
{
	m_eColor = color;
	if(m_eColor == COLOR_W)
		m_ePieceType = PIECE_W_PAWN;
	else
		m_ePieceType = PIECE_B_PAWN;
	m_pBitmap = BitmapManager::GetSingleton()->GetPieceImg(m_ePieceType);
}


void Pawn::SetMoveRange()
{
	POINT point;
	MoveRange.clear();

	MoveRange.push_back(pos);


	if (!m_bMove) // 처음 위치
	{
		if (m_eColor == COLOR_W)
		{
			point = { pos.x,pos.y - 1 * IMG_HEIGHT };
			MoveRange.push_back(point);
			point = { pos.x,pos.y - 2 * IMG_HEIGHT };
			MoveRange.push_back(point);
		}
		else
		{
			point = { pos.x,pos.y +1 * IMG_HEIGHT };
			MoveRange.push_back(point);
			point = { pos.x,pos.y + 2 * IMG_HEIGHT };
			MoveRange.push_back(point);
		}
		m_bMove = true;
	}
	else
	{
		if (m_eColor == COLOR_W)
		{
			point = { pos.x,pos.y - 1 * IMG_HEIGHT };
			MoveRange.push_back(point);
		}
		else
			point = { pos.x,pos.y + 1 * IMG_HEIGHT };
			MoveRange.push_back(point);
	}
}



Knight::Knight()
{
}


void Knight::SetImgColor(COLOR color)
{
	m_eColor = color;
	if (m_eColor == COLOR_W)
		m_ePieceType = PIECE_W_KNIGHT;
	else
		m_ePieceType = PIECE_B_KNIGHT;
	m_pBitmap = BitmapManager::GetSingleton()->GetPieceImg(m_ePieceType);
}


void Knight::SetMoveRange()
{

}


Rook::Rook()
{
}


void Rook::SetImgColor(COLOR color)
{
	m_eColor = color;
	if (m_eColor == COLOR_W)
		m_ePieceType = PIECE_W_ROOK;
	else
		m_ePieceType = PIECE_B_ROOK;
	m_pBitmap = BitmapManager::GetSingleton()->GetPieceImg(m_ePieceType);
}


void Rook::SetMoveRange()
{

}
