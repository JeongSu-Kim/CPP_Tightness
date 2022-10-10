#include "stdafx.h"
#include "gameboard.h"

Gameboard::Gameboard()
{
	this->xSize = 12;
	this->ySize = 24;
	this->leftMargin = 2;
	this->topMargin = 2;
	//this->nextBlockSize_x = 6;
	//this->nextBlockSize_y = 8;
	this->blockSize = 5; //default값 추가함2

	this->initGameboard();
}
Gameboard::Gameboard(int x, int y)
{
	this->xSize = x;
	this->ySize = y;
	this->leftMargin = 2;
	this->topMargin = 2;
	//this->nextBlockSize_x = 6;
	//this->nextBlockSize_y = 8;
	this->blockSize = 5; //default값 추가함2

	this->initGameboard();
}
Gameboard::~Gameboard()
{
	for (int i = 0; i < this->ySize; i++)
		delete[] board[i];
	delete[] board;
}

void Gameboard::initGameboard()
{
	this->nextBlockPos_x = this->leftMargin + this->xSize + 2;
	this->nextBlockPos_y = this->topMargin + 1;

	this->board = new char*[this->ySize];
	for (int i = 0; i < this->ySize; i++)
	{
		this->board[i] = new char[this->xSize];
		for (int j = 0; j < this->xSize; j++)
		{
			if (j == 0 || j == this->xSize - 1 || i == this->ySize - 1)
				this->board[i][j] = 1; //벽
			else
				this->board[i][j] = 0; //빈공간
		}
	}
}

void Gameboard::resetGameboard()
{
	for (int i = 0; i < this->ySize - 1; i++)
	{
		for (int j = 1; j < this->xSize - 1; j++)
		{
			if (this->board[i][j] == 2 || this->board[i][j] == 4)
				this->board[i][j] = 0;
		}
	}
}

void Gameboard::setBlockSize(int size)
{
	this->blockSize = size;
	this->nextBlockSize_x = size + 2;
	this->nextBlockSize_y = size + 4;
	this->infoPos_x = this->nextBlockPos_x + this->nextBlockSize_x + 2;
	this->infoPos_y = this->topMargin;

	this->holdBlockPos_x = this->leftMargin + this->xSize + 2;
	this->holdBlockPos_y = this->topMargin + this->nextBlockSize_y + 4;
}

char Gameboard::getGameboard(int i, int j)
{
	return this->board[i][j];
}

void Gameboard::setGameboard(int i, int j, char type)
{
	this->board[i][j] = type;
}

void Gameboard::printGameboard()
{
	this->gotoXY(this->leftMargin * 2, this->topMargin);
	for (int i = 0; i < this->ySize; i++)
	{
		this->gotoXY(this->leftMargin * 2, this->topMargin + i);
		for (int j = 0; j < this->xSize; j++)
		{
			switch (this->board[i][j])
			{
			case 0: //빈공간
				cout << "  ";
				break;
			case 1: //벽
				cout << "■";
				break;
			case 2: //현재 블록
				cout << "▣";
				break;
			case 3: //쌓인 블록
				cout << "▩";
				break;
			case 4: //미리보기
				cout << "□";
				break;
			default:
				break;
			}
		}
		cout << endl;
	}
}

void Gameboard::printNextBlock()
{
	this->gotoXY(this->nextBlockPos_x * 2, this->nextBlockPos_y - 1);
	cout << "N E X T" << endl;

	for (int i = 0; i < this->nextBlockSize_y; i++)
	{
		this->gotoXY(this->nextBlockPos_x * 2, this->nextBlockPos_y + i);
		for (int j = 0; j < this->nextBlockSize_x; j++)
		{
			if (i == 0 || i == this->nextBlockSize_y - 1 || j == 0 || j == this->nextBlockSize_x - 1)
				cout << "■";
			else
				cout << "  ";
		}
	}

	this->gotoLast();
}

/*void Gameboard::printNextBlock(position* block)
{
	this->printNextBlock();

	for (int i = 0; i < this->blockSize; i++)
	{
		if (block[i].x != 100 && block[i].y != 100)
		{
			int x = (this->nextBlockPos_x + this->nextBlockSize_x / 2 + block[i].x) * 2;
			int y = (this->nextBlockPos_y + this->nextBlockSize_y / 2 + block[i].y);
			this->gotoXY(x, y);
			cout << "▣";
		}
	}
	
	this->gotoLast();
}*/

void Gameboard::printNextBlock(position block)
{
	int x = (this->nextBlockPos_x + this->nextBlockSize_x / 2 + block.x) * 2;
	int y = (this->nextBlockPos_y + this->nextBlockSize_y / 2 + block.y);
	this->gotoXY(x, y);
	cout << "▣";

	this->gotoLast();
}

void Gameboard::printHoldBlock()
{
	this->gotoXY(this->holdBlockPos_x * 2, this->holdBlockPos_y - 1);
	cout << "H O L D" << endl;

	for (int i = 0; i < this->nextBlockSize_y; i++)
	{
		this->gotoXY(this->holdBlockPos_x * 2, this->holdBlockPos_y + i);
		for (int j = 0; j < this->nextBlockSize_x; j++)
		{
			if (i == 0 || i == this->nextBlockSize_y - 1 || j == 0 || j == this->nextBlockSize_x - 1)
				cout << "■";
			else
				cout << "  ";
		}
	}

	this->gotoLast();
}

/*void Gameboard::printHoldBlock(position* block)
{
	this->printHoldBlock();

	for (int i = 0; i < this->blockSize; i++)
	{
		if (block[i].x != 100 && block[i].y != 100)
		{
			int x = (this->holdBlockPos_x + this->nextBlockSize_x / 2 + block[i].x) * 2;
			int y = (this->holdBlockPos_y + this->nextBlockSize_y / 2 + block[i].y);
			this->gotoXY(x, y);
			cout << "▣";
		}
	}

	this->gotoLast();
}*/

void Gameboard::printHoldBlock(position block)
{
	int x = (this->holdBlockPos_x + this->nextBlockSize_x / 2 + block.x) * 2;
	int y = (this->holdBlockPos_y + this->nextBlockSize_y / 2 + block.y);
	this->gotoXY(x, y);
	cout << "▣";

	this->gotoLast();
}

void Gameboard::printInfo()
{
	this->gotoXY(this->infoPos_x * 2, this->infoPos_y);
	cout << "N A M E : ";
	this->gotoXY(this->infoPos_x * 2, this->infoPos_y + 2);
	cout << "H I G H S C O R E : ";
	this->gotoXY(this->infoPos_x * 2, this->infoPos_y + 6);
	cout << "Y O U R S C O R E : ";
	this->gotoLast();
}

void Gameboard::printInfo(TCHAR* name, unsigned int highscore)
{
	this->gotoXY(this->infoPos_x * 2, this->infoPos_y);
	wcout << "N A M E : " << name;
	this->gotoXY(this->infoPos_x * 2, this->infoPos_y + 2);
	cout << "H I G H S C O R E : " << highscore;
	this->gotoXY(this->infoPos_x * 2, this->infoPos_y + 6);
	cout << "Y O U R S C O R E : ";
	this->gotoLast();
}

void Gameboard::printInfo(unsigned int score)
{
	this->gotoXY(this->infoPos_x * 2, this->infoPos_y + 6);
	cout << "Y O U R S C O R E : " << score;
	this->gotoLast();
}

void Gameboard::printAll()
{
	system("cls");
	this->printGameboard();
	this->printNextBlock();
	this->printHoldBlock();
	this->printInfo();
}

void Gameboard::gotoXY(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Gameboard::gotoXY(COORD pos)
{
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Gameboard::gotoLast()
{
	COORD pos = { this->leftMargin, this->ySize + this->topMargin + 1 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

int Gameboard::getxSize()
{
	//return (this->leftMargin + this->xSize / 2);
	return this->xSize;
}

int Gameboard::getySize()
{
	return this->ySize;
}