#pragma once

#include "stdafx.h"

#define NOBLOCK 100

class Block
{
protected:
	//블록의 종류
	int numOfType;

	//블록당 벽돌수
	int numOfStone; 

	//로테이트를 위해 추가
	int* rotateType;

	//block에 좌표 설정, 생성자에서 호출
	template <size_t Y>
	void setBlock(position(*mino)[Y]);

	//Block자체는 객체를 생성하면 안되고 상속받은 자식 클래스들로 객체를 만들어야 하기때문에 protected에 넣어봤다.
	Block();

public:

	virtual ~Block();

	//블록 전체 좌표의 포인터
	position** block;

	//블록 종류 갯수 반환
	int getNumOfType();

	//블록당 벽돌수 반환
	int getNumOfStone();

	////블록 전체의 좌표가 들어있는 포인터 반환
	//position** getBlock();

	int getRotateType(int blockType); //<-추가
};

class Tetromino : public Block
{
private:
public:
	Tetromino();
	virtual ~Tetromino();
};

class Tromino : public Block
{
private:
public:
	Tromino();
	virtual ~Tromino();
};

class Pentomino : public Block
{
private:
public:
	Pentomino();
	virtual ~Pentomino();
};

class Tightmino : public Block
{
private:
public:
	Tightmino();
	virtual ~Tightmino();
};