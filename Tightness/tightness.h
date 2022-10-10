#pragma once

#include "stdafx.h"
#include "block.h"
#include "gameboard.h"

enum CHECK { ROTATE, DOWNSIDE, RIGHTSIDE, LEFTSIDE };
enum KEYTYPE { SPACE_BAR = 32, ESC = 27, UP = 72, LEFT = 75, RIGHT = 77, DOWN = 80, DIRECTION = 224 };

class Tightness
{
private:
	position currentCursor;
	position* currentBlock;
	int currentRotateType;
	int currentType;
	int randomType;
	int holdType;
	bool gameOver;
	bool canHold;
	bool preview;
	unsigned long prevTime;
	unsigned long currTime;
	unsigned int score; //ÃÑ Á¡¼ö
	unsigned int point; //È¹µæ Á¡¼ö
	unsigned int chain; //¿¬¼Ó ±ú±â
	unsigned int gameSpeed;
	unsigned int cleardLine;
	unsigned int highScore;
protected:
	//int blocknum;
public:
	Tightness(Block* block, Gameboard* gameboard);
	~Tightness();
	Block* pb;
	Gameboard* pg;
	//position(*block)[4];
	//position** block;
	//void setBlock(position (*mino)[4]);
	//void setBlock(position** mino);
	//void setBlock();
	//void printBlock(int n);
	void init();
	void playGame();
	void createBlock(int blocktype);
	void printBlock(int center_x, int center_y, position* currentblock, int blockType);
	bool checkCollision(position* currentblock, int flag);
	bool checkCollision(position* currentblock, int flag, int rt);
	void rotateBlock(position* currentblock, int& rt);
	void nextBlock();
	void holdBlock();
	void landing();
	void delLine(int deli);
	void show(bool previewFlag);
	void ending();
	void control();
	bool checkTime(unsigned long time);
	void pause();
	void loadScore();
	void saveScore();
	//void changeRotateType_2_and_3(int& rt);

	//void operator=(const position& p);
};