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

void King::SetMovableRange(vector<Piece*> v)
{

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

void Queen::SetMovableRange(vector<Piece*> v)
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


void Bishop::SetMovableRange(vector<Piece*> v)
{

}



Pawn::Pawn()
{
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

bool Pawn::FirstCheck()
{
	if (m_eColor == COLOR_W)
	{
		if (pos.y / IMG_HEIGHT == 6)
			return true;
		else
			return false;
	}
	else
	{
		if (pos.y / IMG_HEIGHT == 1)
			return true;
		else
			return false;
	}
}

void Pawn::SetMoveRange()
{
	POINT point;
	MoveRange.clear();

	MoveRange.push_back(pos);

	if (FirstCheck())
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


void Pawn::SetMovableRange(vector<Piece*> v)
{
	vector<POINT> MovableRange;
	MovableRange.push_back(pos);


	bool bCheck = false;

	for (auto it = MoveRange.begin(); it != MoveRange.end(); it++)
	{
		for (auto iter = v.begin(); iter != v.end(); iter++)
		{
			if ((*iter)->GetPos().x == (*it).x && ((*iter)->GetPos().y == (*it).y))
			{
				bCheck = false;
				break;
			}
			else
				bCheck = true;
		}
		if (bCheck == true)
			MovableRange.push_back((*it));

	if (m_eColor == COLOR_W) // 나중에 대각선 체크 용
	{
		;
	}
	else
	{
		;
	}

	}
	MoveRange.clear();
	MoveRange = MovableRange;
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


void Knight::SetMovableRange(vector<Piece*> v)
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


void Rook::SetMovableRange(vector<Piece*> v)
{

}
