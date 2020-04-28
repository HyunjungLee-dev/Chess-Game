#pragma once
#include"Bitmap.h"
#include"Singleton.h"


class BitmapManager : public Singleton< BitmapManager>
{
	vector<Bitmap*> m_pBlcPiece;
	vector<Bitmap*> m_pWhiPiece;
	vector<Bitmap*> m_pBrdBlock;

public:
	void Init(HWND hWnd);
	void Release(vector<Bitmap*> bit);
	Bitmap* GetBlcPImg(PIECEBLOCK Btype) { return m_pBlcPiece[Btype]; }
	Bitmap* GetWhiPImg(PIECEBLOCK Btype) { return m_pWhiPiece[Btype]; }
	Bitmap* GetBrdBImg(BOARDBLOCK Btype) { return m_pBrdBlock[Btype]; }
	BitmapManager();
	~BitmapManager();
};

