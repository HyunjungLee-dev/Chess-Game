#pragma once
#include"BitmapManager.h"



class Piece
{
protected:
	POINT pos;
	RECT m_PieceRect;
	Bitmap* m_pBitmap;
	PIECE m_ePieceType;
	vector<POINT> MoveRange;
public:
	void SetPos(int x, int y) ;
	void Draw(HDC hdc) ; 
	POINT GetPos() { return pos; }
	RECT GetRect() { return m_PieceRect; }
	virtual void SetImgColor(COLOR color) = 0;
	virtual void SetMoveRange() = 0; 
	Piece();
	virtual ~Piece();
};

/*Piece*/	 // 컬러필요한가

class King : public Piece
{
private:
	COLOR m_eColor;
public:
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange();
	King();
	virtual ~King() {};

};

class Queen : public Piece
{
private:
	COLOR m_eColor;
public:
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange();
	Queen();
	virtual ~Queen() {};

};

class Rook : public Piece
{
private:
	COLOR m_eColor;
public:
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange();
	Rook();
	virtual ~Rook() {};
};

class Bishop : public Piece
{
private:
	COLOR m_eColor;
public:
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange();
	Bishop();
	virtual ~Bishop() {};
};

class Knight : public Piece
{
private:
	COLOR m_eColor;
public:
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange();
	Knight();
	virtual ~Knight() {};
};

class Pawn : public Piece
{
private:
	COLOR m_eColor;
public:
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange();
	Pawn();
	virtual ~Pawn() {};
};