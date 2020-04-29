#pragma once
#include"BitmapManager.h"


class Block
{
public:
	virtual void SetPos(int x, int y) = 0;// 좌표
	virtual void Draw(HDC hdc) = 0; // 이미지 그리기
	Block();// Bitmap 이미지 SET , TYPE SET
	virtual void SetColor(COLOR color) = 0;
	virtual ~Block();
};

/*Piece*/	//컬러를 따로

class King : public Block
{
	private:
		int m_ix, m_iy;
		Bitmap* m_pBitmap[COLOR_END];
		PIECEBLOCK m_ePieceType;
		COLOR m_eColor;
		RECT m_PiecekRect;
	public:
		virtual void SetPos(int x, int y);
		virtual void Draw(HDC hdc);
		virtual void SetColor(COLOR color) { m_eColor = color; }
		King();
		virtual ~King() {};

 };

class Queen : public Block
{
private:
	int m_ix, m_iy;
	Bitmap* m_pBitmap[COLOR_END];
	PIECEBLOCK m_PieceType;
	COLOR m_eColor;
	RECT m_PiecekRect;
public:
	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	virtual void SetColor(COLOR color) { m_eColor = color; }
	Queen();
	virtual ~Queen() {};

};

class Rook : public Block
{
private:
	int m_ix, m_iy;
	Bitmap* m_pBitmap[COLOR_END];
	PIECEBLOCK m_PieceType;
	COLOR m_eColor;
	RECT m_PiecekRect;
public:
	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	virtual void SetColor(COLOR color) { m_eColor = color; }
	Rook();
	virtual ~Rook() {};
};

class Bishop : public Block
{
private:
	int m_ix, m_iy;
	Bitmap* m_pBitmap[COLOR_END];
	PIECEBLOCK m_PieceType;
	COLOR m_eColor;
	RECT m_PiecekRect;
public:
	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	virtual void SetColor(COLOR color) { m_eColor = color; }
	Bishop();
	virtual ~Bishop() {};
};

class Knight : public Block
{
private:
	int m_ix, m_iy;
	Bitmap* m_pBitmap[COLOR_END];
	PIECEBLOCK m_PieceType;
	COLOR m_eColor;
	RECT m_PiecekRect;
public:
	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	virtual void SetColor(COLOR color) { m_eColor = color; }
	Knight();
	virtual ~Knight() {};
};

class Pawn : public Block
{
private:
	int m_ix, m_iy;
	Bitmap* m_pBitmap[COLOR_END];
	PIECEBLOCK m_PieceType;
	COLOR m_eColor;
	RECT m_PiecekRect;
public:
	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	virtual void SetColor(COLOR color) { m_eColor = color; }
	Pawn();
	virtual ~Pawn() {};
};

/*Board Block*/

class Light : public Block
{
private:
	float m_ix, m_iy;
	Bitmap* m_pBitmap;
	BOARDBLOCK m_brdbckType;
	RECT m_brdBckRect;
public:
	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	virtual void SetColor(COLOR color) {};
	Light();
	virtual ~Light() {};
};

class Dark : public  Block
{
private:
	float m_ix, m_iy;
	Bitmap* m_pBitmap;
	BOARDBLOCK m_brdbckType;
	RECT m_brdBckRect;
public:
	virtual void SetPos(int x, int y);
	virtual void Draw(HDC hdc);
	virtual void SetColor(COLOR color) {};
	Dark();
	virtual ~Dark() {};
};

/*Select Line*/

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

