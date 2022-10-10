#pragma once

#include "stdafx.h"

class Gameboard
{
private:
	int xSize;
	int ySize;
	int leftMargin;
	int topMargin;
	int nextBlockPos_x;
	int nextBlockPos_y;
	int nextBlockSize_x;
	int nextBlockSize_y;
	int holdBlockPos_x;
	int holdBlockPos_y;
	int holdBlockSize_x;
	int holdBlockSize_y;
	int infoPos_x;
	int infoPos_y;
	char** board;
	int blockSize;
public :
	Gameboard();
	Gameboard(int x, int y);
	~Gameboard();
	void initGameboard();
	void resetGameboard(); //<-추가함
	void setBlockSize(int size); //<-추가함2
	char getGameboard(int i, int j);
	void setGameboard(int i, int j, char type );
	void printGameboard();
	void printNextBlock();
	//void printNextBlock(position* block);
	void printNextBlock(position block);
	void printHoldBlock();
	//void printHoldBlock(position* block);
	void printHoldBlock(position block);
	void printInfo();
	void printInfo(TCHAR* name, unsigned int highscore);
	void printInfo(unsigned int score);
	void printAll();
	void gotoXY(int x, int y);
	void gotoXY(COORD pos);
	void gotoLast();

	int getxSize();
	int getySize();

	//void setMargin();
};