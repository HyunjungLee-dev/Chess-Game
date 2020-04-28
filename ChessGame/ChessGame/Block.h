#pragma once
#include"BitmapManager.h"


class Block
{
public:
	virtual void SetBlock(int x, int y) = 0; // Bitmap 이미지 SET , TYPE SET
	virtual void Draw(HDC hdc) = 0; // 이미지 그리기
	Block();
	virtual ~Block();
};

/*Piece*/

class King : public Block
{
	private:
		int m_ix, m_iy;
		Bitmap* m_pBitmap[PIECECOLOR_END];
		PIECEBLOCK m_PieceType;
		RECT m_PiecekRect;
	public:
		virtual void SetBlock(int x, int y);
		virtual void Draw(HDC hdc);
		King() {};
		virtual ~King() {};

 };

class Queen : public Block
{
private:
	int m_ix, m_iy;
	Bitmap* m_pBitmap[PIECECOLOR_END];
	PIECEBLOCK m_PieceType;
	RECT m_PiecekRect;
public:
	virtual void SetBlock(int x, int y);
	virtual void Draw(HDC hdc);
	Queen() {};
	virtual ~Queen() {};

};

class Rook : public Block
{
private:
	int m_ix, m_iy;
	Bitmap* m_pBitmap[PIECECOLOR_END];
	PIECEBLOCK m_PieceType;
	RECT m_PiecekRect;
public:
	virtual void SetBlock(int x, int y);
	virtual void Draw(HDC hdc);
	Rook() {};
	virtual ~Rook() {};
};

class Bishop : public Block
{
private:
	int m_ix, m_iy;
	Bitmap* m_pBitmap[PIECECOLOR_END];
	PIECEBLOCK m_PieceType;
	RECT m_PiecekRect;
public:
	virtual void SetBlock(int x, int y);
	virtual void Draw(HDC hdc);
	Bishop() {};
	virtual ~Bishop() {};
};

class Knight : public Block
{
private:
	int m_ix, m_iy;
	Bitmap* m_pBitmap[PIECECOLOR_END];
	PIECEBLOCK m_PieceType;
	RECT m_PiecekRect;
public:
	virtual void SetBlock(int x, int y);
	virtual void Draw(HDC hdc);
	Knight() {};
	virtual ~Knight() {};
};

class Pawn : public Block
{
private:
	int m_ix, m_iy;
	Bitmap* m_pBitmap[PIECECOLOR_END];
	PIECEBLOCK m_PieceType;
	RECT m_PiecekRect;
public:
	virtual void SetBlock(int x, int y);
	virtual void Draw(HDC hdc);
	Pawn() {};
	virtual ~Pawn() {};
};

/*Board Block*/

class Light : public Block
{
private:
	int m_ix, m_iy;
	Bitmap* m_pBitmap;
	BOARDBLOCK m_brdbckType;
	RECT m_brdBckRect;
public:
	virtual void SetBlock(int x, int y);
	virtual void Draw(HDC hdc);
	Light() {};
	virtual ~Light() {};
};

class Dark : public  Block
{
private:
	int m_ix, m_iy;
	Bitmap* m_pBitmap;
	BOARDBLOCK m_brdbckType;
	RECT m_brdBckRect;
public:
	virtual void SetBlock(int x, int y);
	virtual void Draw(HDC hdc);
	Dark() {};
	virtual ~Dark() {};
};

//class Line : public Block
//{
//private:
//	int m_ix, m_iy;
//	Bitmap* m_pBitmap;
//	BOARDBLOCK m_brdbckType;
//	RECT m_brdBckRect;
//public:
//	virtual void SetBlock(int x, int y);
//	virtual void Draw(HDC hdc);
//	Line() {};
//	virtual ~Line() {};
//};

