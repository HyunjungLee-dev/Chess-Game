#include "Block.h"



Block::Block()
{
	
}
Block::~Block()
{
}

/* Piece*/

void King::SetBlock(int x, int y)
{
	m_PieceType = PIECEBLOCK_KING;
	m_pBitmap[PIECECOLOR_B] = BitmapManager::GetSingleton()->GetBlcPImg(m_PieceType);
	m_pBitmap[PIECECOLOR_W] = BitmapManager::GetSingleton()->GetBlcPImg(m_PieceType);
}

void King::Draw(HDC hdc)
{

}

void Queen::SetBlock(int x, int y)
{

}

void Queen::Draw(HDC hdc)
{

}

void Bishop::SetBlock(int x, int y)
{

}

void Bishop::Draw(HDC hdc)
{

}

void Pawn::SetBlock(int x, int y)
{

}

void Pawn::Draw(HDC hdc)
{

}

void Knight::SetBlock(int x, int y)
{

}

void Knight::Draw(HDC hdc)
{

}

void Rook::SetBlock(int x, int y)
{

}

void Rook::Draw(HDC hdc)
{

}

/*Board Block*/

void Light::SetBlock(int x, int y)
{
	m_brdbckType = BOARDBLOCK_LIGHT;
	m_pBitmap= BitmapManager::GetSingleton()->GetBrdBImg(m_brdbckType);

	m_ix = x;
	m_iy = y;
	m_brdBckRect.left = x;
	m_brdBckRect.top = y;
	m_brdBckRect.right = m_brdBckRect.left + m_pBitmap->GetSize().cx;
	m_brdBckRect.bottom = m_brdBckRect.top + m_pBitmap->GetSize().cy;
}

void Light::Draw(HDC hdc)
{
	m_pBitmap->Draw(hdc, m_ix, m_iy);
}

void Dark::SetBlock(int x, int y)
{
	m_brdbckType = BOARDBLOCK_DARK;
	m_pBitmap = BitmapManager::GetSingleton()->GetBrdBImg(m_brdbckType);

	m_ix = x;
	m_iy = y;
	m_brdBckRect.left = x;
	m_brdBckRect.top = y;
	m_brdBckRect.right = m_brdBckRect.left + m_pBitmap->GetSize().cx;
	m_brdBckRect.bottom = m_brdBckRect.top + m_pBitmap->GetSize().cy;
}

void Dark::Draw(HDC hdc)
{
	m_pBitmap->Draw(hdc, m_ix, m_iy);
}

//void Line::SetBlock(int x, int y)
//{
//	m_brdbckType = BOARDBLOCK_LINE;
//	m_pBitmap = BitmapManager::GetSingleton()->GetBrdBImg(m_brdbckType);
//
//	m_ix = x;
//	m_iy = y;
//	m_brdBckRect.left = x;
//	m_brdBckRect.top = y;
//	m_brdBckRect.right = m_brdBckRect.left + m_pBitmap->GetSize().cx;
//	m_brdBckRect.bottom = m_brdBckRect.top + m_pBitmap->GetSize().cy;
//}
//
//void Line::Draw(HDC hdc)
//{
//	m_pBitmap->Draw(hdc, m_ix, m_iy);
//}