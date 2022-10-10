#include "stdafx.h"
#include "block.h"

Block::Block() { }

//동적 할당된 블록 좌표 객체 메모리 해제 
Block::~Block()
{
	for (int i = 0; i < this->numOfType; i++)
		delete[] this->block[i];
	delete[] this->block;

	delete rotateType;
}

//템플릿에 대한건 http://trowind.tistory.com/29 를 참고함
template <size_t Y>
void Block::setBlock(position (*mino)[Y])
{
	//this->block = tetromino;
	this->block = new position*[this->numOfType];
	for (int i = 0; i < this->numOfType; i++)
	{
		this->block[i] = new position[this->numOfStone];
		for (int j = 0; j < this->numOfStone; j++)
		{
			//cout << block[i][j].x << ", " << block[i][j].y << endl;
			block[i][j].x = mino[i][j].x;
			block[i][j].y = mino[i][j].y;
		}
	}//block[numOfType][numOfStone] 의 크기를 가지게 동적 할당 하여 값을 복사한다.

}

int Block::getNumOfType()
{
	return this->numOfType;
}

int Block::getNumOfStone()
{
	return this->numOfStone;
}

int Block::getRotateType(int blockType)
{
	return this->rotateType[blockType];
}

//position** Block::getBlock()
//{
//	return this->block;
//}

Tetromino::Tetromino() : Block()
{
	this->numOfType = 7;
	this->numOfStone = 4;
	position tetromino[7][4] =
	{
		{ 0, 0, 0, -1, 0, -2, 0, 1 },	// I
		{ 0, 0, 0, -1, -1, -1, -1, 0 },	// O
		{ 0, 0, 0, -1, 0, 1, -1, 0 },	// T
		{ 0, 0, 0, -1, 0, 1, -1, 1 },	// J
		{ 0, 0, 0, -1, -1, -1, 0, 1 },	// L
		{ 0, 0, 0, 1, -1, 0, -1, -1 },	// S
		{ 0, 0, 0, -1, -1, 1, -1, 0 }	// Z
	};

	this->setBlock(tetromino);

	int RT[7] = { 1, 0, 3, 3, 3, 1, 1 };
	this->rotateType = new int[7];
	for (int i = 0; i < 7; i++)
	{
		this->rotateType[i] = RT[i];
	}
}

Tetromino::~Tetromino() 
{ 

}

Tromino::Tromino() : Block()
{
	this->numOfType = 2;
	this->numOfStone = 3;
	position tromino[2][3] =
	{
		{ 0, 0, 0, -1, 0, 1 },	// I
		{ 0, 0, 0, 1, -1, 0 }	// L
	};

	this->setBlock(tromino);

	int RT[2] = { 3, 3 };
	this->rotateType = new int[2];
	for (int i = 0; i < 2; i++)
	{
		this->rotateType[i] = RT[i];
	}
}

Tromino::~Tromino()
{

}

Pentomino::Pentomino()
{
	this->numOfType = 18;
	this->numOfStone = 5;
	position pentomino[18][5] =
	{
		{ 0, 0, 0, -1, 0, -2, 0, 1, 0, 2 }, // I 
		{ 0, 0, 0, -1, 1, -1, 0, 1, -1, -1 }, // T 
		{ 0, 0, 1, -1, 1, 0, -1, 0, -1, -1 }, // U 
		{ 1, -1, 1, 0, 1, 1, 0, 1, -1, 1 }, // V 
		{ 0, 0, 1, -1, 1, 0, 0, 1, -1, 1 }, // W 
		{ 0, 0, 0, -1, 1, 0, 0, 1, -1, 0 }, // X 
		{ 0, 0, 0, -1, 1, -1, 0, 1, -1, 0 }, // F
		{ 0, 0, 0, -1, 1, 0, 0, 1, -1, -1 }, // F'
		{ 0, 0, 0, -1, 0, -2, 0, 1, 1, 1 }, // L
		{ 0, 0, 0, -1, 0, -2, 0, 1, -1, 1 }, // L'
		{ 0, 0, 0, -1, 0, -2, -1, 0, -1, 1 }, // N
		{ 0, 0, 0, -1, 0, -2, 1, 0, 1, 1 }, // N'
		{ 0, 0, 0, -1, 1, -1, 0, 1, 1, 0 }, // P
		{ 0, 0, 0, -1, -1, 0, 0, 1, -1, -1 }, // P'
		{ 0, 0, 0, -1, 0, -2, 0, 1, -1, -1 }, // Y
		{ 0, 0, 0, -1, 0, -2, 0, 1, 1, -1 }, // Y'
		{ 0, 0, 0, -1, 1, 1, 0, 1, -1, -1 }, // Z
		{ 0, 0, 0, -1, 1, -1, 0, 1, -1, 1 } // Z'
	};

	this->setBlock(pentomino);

	int RT[18] = { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
	this->rotateType = new int[18];
	for (int i = 0; i < 18; i++)
	{
		this->rotateType[i] = RT[i];
	}
}

Pentomino::~Pentomino()
{

}

Tightmino::Tightmino()
{
	this->numOfType = 7;
	this->numOfStone = 5;
	position tightmino[7][5] =
	{
		{ 0, 0, 0, -1, 0, -2, 0, 1, NOBLOCK, NOBLOCK },	// I
		{ 0, 0, 0, -1, 1, -1, 0, 1, -1, -1 }, // T 
		{ 0, 0, 0, -1, 1, -1, 0, 1, 1, 0 }, // P
		{ 0, 0, 0, -1, -1, 0, 0, 1, -1, -1 }, // P'
		{ 0, 0, 0, -1, 1, -1, 0, 1, -1, 1 }, // Z'
		{ 0, 0, 0, 1, -1, 0, NOBLOCK, NOBLOCK, NOBLOCK, NOBLOCK },	// L
		{ 0, 0, 0, -1, NOBLOCK, NOBLOCK, NOBLOCK, NOBLOCK, NOBLOCK, NOBLOCK }	// i
	};

	this->setBlock(tightmino);

	int RT[7] = { 1, 3, 3, 3, 3, 3, 1 };
	this->rotateType = new int[7];
	for (int i = 0; i < 7; i++)
	{
		this->rotateType[i] = RT[i];
	}
}

Tightmino::~Tightmino()
{

}

