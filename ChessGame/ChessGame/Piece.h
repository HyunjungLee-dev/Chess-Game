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
	vector<POINT> GetRange(){ return MoveRange; }
	virtual void SetImgColor(COLOR color) = 0;
	virtual void SetMoveRange() = 0; 
	virtual void SetMovableRange(vector<Piece*> v ) = 0;
	Piece();
	virtual ~Piece();
};

/*Piece*/	 

class King : public Piece
{
private:
	COLOR m_eColor;
public:
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange();
	virtual void SetMovableRange(vector<Piece*> v);
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
	virtual void SetMovableRange(vector<Piece*> v);
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
	virtual void SetMovableRange(vector<Piece*> v);
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
	virtual void SetMovableRange(vector<Piece*> v);
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
	virtual void SetMovableRange(vector<Piece*> v);
	Knight();
	virtual ~Knight() {};
};

class Pawn : public Piece
{
private:
	COLOR m_eColor;
public:
	bool FirstCheck();
	virtual void SetImgColor(COLOR color);
	virtual void SetMoveRange();
	virtual void SetMovableRange(vector<Piece*> v);
	Pawn();
	virtual ~Pawn() {};
};