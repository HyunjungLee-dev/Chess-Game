#include "BitmapManager.h"

BitmapManager* BitmapManager::_Singleton = NULL;

BitmapManager::BitmapManager()
{

}

void BitmapManager::Init(HWND hWnd)
{
	TCHAR buf[256];
	HDC hdc = GetDC(hWnd);
	int bpiece = 0, wpiece = 0, brdblock = 0;
	for (int i = IMG_START; i < IMG_END; i++)
	{

		if (bpiece < IMG_BPIECE)
		{
			m_pBlcPiece.push_back(new Bitmap);
			wsprintf(buf, L"Chess//block_b_0%d.bmp", bpiece++);
			m_pBlcPiece[bpiece]->Init(hdc, buf);
		}
		else if (wpiece < IMG_WPIECE)
		{
			m_pWhiPiece.push_back(new Bitmap);
			wsprintf(buf, L"Chess//block_w_0%d.bmp", wpiece++);
			m_pWhiPiece[wpiece]->Init(hdc, buf);
		}
		else if (brdblock < IMG_BRDBLOCK)
		{
			m_pBrdBlock.push_back(new Bitmap);
			wsprintf(buf, L"Chess//block0%d.bmp", brdblock++);
			m_pWhiPiece[brdblock]->Init(hdc, buf);
		}

	}

	ReleaseDC(hWnd, hdc);
}

void BitmapManager::Release(vector<Bitmap*> bit)
{
	for (vector<Bitmap*>::iterator it = bit.begin(); it != bit.end(); it++)
	{
		delete (*it);

	}
	bit.clear();
}


BitmapManager::~BitmapManager()
{
	Release(m_pBlcPiece);
	Release(m_pWhiPiece);
	Release(m_pBrdBlock);

}
