#include "Block.h"



Block::Block()
{
	
}
Block::~Block()
{
}

/* Piece*/

King::King()
{
	m_ePieceType = PIECEBLOCK_KING;
	m_pBitmap[COLOR_B] = BitmapManager::GetSingleton()->GetBlcPImg(m_ePieceType);
	m_pBitmap[COLOR_W] = BitmapManager::GetSingleton()->GetWhiPImg(m_ePieceType);
}

void King::SetPos(int x, int y)
{
	m_ix = x;
	m_iy = y;
	m_PiecekRect.left = x;
	m_PiecekRect.top = y;
	m_PiecekRect.right = m_PiecekRect.left + m_pBitmap[m_eColor]->GetSize().cx;
	m_PiecekRect.bottom = m_PiecekRect.top + m_pBitmap[m_eColor]->GetSize().cy;
}

void King::Draw(HDC hdc)
{
	m_pBitmap[m_eColor]->Draw(hdc, m_ix, m_iy);
}

Queen::Queen()
{
	m_PieceType = PIECEBLOCK_QUEEN;
	m_pBitmap[COLOR_B] = BitmapManager::GetSingleton()->GetBlcPImg(m_PieceType);
	m_pBitmap[COLOR_W] = BitmapManager::GetSingleton()->GetWhiPImg(m_PieceType);
}

void Queen::SetPos(int x, int y)
{
	m_ix = x;
	m_iy = y;
	m_PiecekRect.left = x;
	m_PiecekRect.top = y;
	m_PiecekRect.right = m_PiecekRect.left + m_pBitmap[m_eColor]->GetSize().cx;
	m_PiecekRect.bottom = m_PiecekRect.top + m_pBitmap[m_eColor]->GetSize().cy;
}


void Queen::Draw(HDC hdc)
{
	m_pBitmap[m_eColor]->Draw(hdc, m_ix, m_iy);
}

Bishop::Bishop()
{
	m_PieceType = PIECEBLOCK_BISHOP;
	m_pBitmap[COLOR_B] = BitmapManager::GetSingleton()->GetBlcPImg(m_PieceType);
	m_pBitmap[COLOR_W] = BitmapManager::GetSingleton()->GetWhiPImg(m_PieceType);
}

void Bishop::SetPos(int x, int y)
{
	m_ix = x;
	m_iy = y;
	m_PiecekRect.left = x;
	m_PiecekRect.top = y;
	m_PiecekRect.right = m_PiecekRect.left + m_pBitmap[m_eColor]->GetSize().cx;
	m_PiecekRect.bottom = m_PiecekRect.top + m_pBitmap[m_eColor]->GetSize().cy;
}

void Bishop::Draw(HDC hdc)
{
	m_pBitmap[m_eColor]->Draw(hdc, m_ix, m_iy);
}

Pawn::Pawn()
{
	m_PieceType = PIECEBLOCK_PAWN;
	m_pBitmap[COLOR_B] = BitmapManager::GetSingleton()->GetBlcPImg(m_PieceType);
	m_pBitmap[COLOR_W] = BitmapManager::GetSingleton()->GetWhiPImg(m_PieceType);
}


void Pawn::SetPos(int x, int y)
{
	m_ix = x;
	m_iy = y;
	m_PiecekRect.left = x;
	m_PiecekRect.top = y;
	m_PiecekRect.right = m_PiecekRect.left + m_pBitmap[m_eColor]->GetSize().cx;
	m_PiecekRect.bottom = m_PiecekRect.top + m_pBitmap[m_eColor]->GetSize().cy;
}

void Pawn::Draw(HDC hdc)
{
	m_pBitmap[m_eColor]->Draw(hdc, m_ix, m_iy);
}

Knight::Knight()
{
	m_PieceType = PIECEBLOCK_KNIGHT;
	m_pBitmap[COLOR_B] = BitmapManager::GetSingleton()->GetBlcPImg(m_PieceType);
	m_pBitmap[COLOR_W] = BitmapManager::GetSingleton()->GetWhiPImg(m_PieceType);
}

void Knight::SetPos(int x, int y)
{
	m_ix = x;
	m_iy = y;
	m_PiecekRect.left = x;
	m_PiecekRect.top = y;
	m_PiecekRect.right = m_PiecekRect.left + m_pBitmap[m_eColor]->GetSize().cx;
	m_PiecekRect.bottom = m_PiecekRect.top + m_pBitmap[m_eColor]->GetSize().cy;
}

void Knight::Draw(HDC hdc)
{
	m_pBitmap[m_eColor]->Draw(hdc, m_ix, m_iy);
}

Rook::Rook()
{
	m_PieceType = PIECEBLOCK_ROOK;
	m_pBitmap[COLOR_B] = BitmapManager::GetSingleton()->GetBlcPImg(m_PieceType);
	m_pBitmap[COLOR_W] = BitmapManager::GetSingleton()->GetWhiPImg(m_PieceType);
}

void Rook::SetPos(int x, int y)
{
	m_ix = x;
	m_iy = y;
	m_PiecekRect.left = x;
	m_PiecekRect.top = y;
	m_PiecekRect.right = m_PiecekRect.left + m_pBitmap[m_eColor]->GetSize().cx;
	m_PiecekRect.bottom = m_PiecekRect.top + m_pBitmap[m_eColor]->GetSize().cy;
}

void Rook::Draw(HDC hdc)
{
	m_pBitmap[m_eColor]->Draw(hdc, m_ix, m_iy);
}

/*Board Block*/

Light::Light()
{
	m_brdbckType = BOARDBLOCK_LIGHT;
	m_pBitmap = BitmapManager::GetSingleton()->GetBrdBImg(m_brdbckType);
}

void Light::SetPos(int x, int y)
{
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

Dark::Dark()
{
	m_brdbckType = BOARDBLOCK_DARK;
	m_pBitmap = BitmapManager::GetSingleton()->GetBrdBImg(m_brdbckType);

}

void Dark::SetPos(int x, int y)
{
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