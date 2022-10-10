#include "stdafx.h"
#include "tightness.h"
//void Tightness::setBlock(position(*mino)[4])
//void Tightness::setBlock(position** mino)
//void Tightness::setBlock()
//{
//	/*this->block = tetromino;
//	
//	cout << "in setBlock()" << endl;
//	for (int i = 0; i < 7; i++)
//		this->printBlock(i);
//	cout << endl;
//	*/
//	//this->block = mino;
//	this->block = new position*[this->pb->getNumOfType()];
//	for (int i = 0; i < this->pb->getNumOfType(); i++)
//	{
//		this->block[i] = new position[4];
//		for (int j = 0; j < 4; j++)
//		{
//			this->block[i][j].x = this->pb->block[i][j].x;
//			this->block[i][j].y = this->pb->block[i][j].y;
//			//cout << this->block[i][j].x << ", " << this->block[i][j].y << "\t";
//		}
//		//cout << endl;
//	}
//}

Tightness::Tightness(Block* block, Gameboard* gameboard)
{
	this->pb = block;
	this->pg = gameboard;
}

Tightness::~Tightness()
{
	delete pb;
	delete pg;
}

void Tightness::init()
{
	srand(time(NULL));

	this->gameOver = false;
	this->preview = false;
	this->score = 0;
	this->point = 0;
	this->chain = 0;
	this->gameSpeed = 1000;
	this->cleardLine = 0;
	this->prevTime = timeGetTime();
}
void Tightness::playGame()
{
	this->init();
	this->currentCursor = { 0, 0 };
	this->currentBlock = new position[this->pb->getNumOfStone()];
	this->pg->setBlockSize(this->pb->getNumOfStone());
	this->pg->printAll();
	this->loadScore();
	
	this->randomType = rand() % this->pb->getNumOfType();
	this->createBlock(this->randomType);
	this->nextBlock();
	this->show(this->preview);

	while (!this->gameOver)
	{
		if (_kbhit())
		{
			this->control();
			this->show(this->preview);
		}

		if (this->checkTime(this->gameSpeed))
		{
			if (this->checkCollision(this->currentBlock, CHECK::DOWNSIDE))
				this->currentCursor.y += 1;
			else
				this->landing();
			this->show(this->preview);
		}
	}
	this->ending();
}

void Tightness::createBlock(int blocktype)
{
	this->currentCursor.x = this->pg->getxSize() / 2;
	this->currentCursor.y = 2;
	//randomType = rand() % this->pb->getNumOfType();
	this->currentType = blocktype;

	for (int i = 0; i < this->pb->getNumOfStone(); i++)
		this->currentBlock[i] = this->pb->block[blocktype][i];

	this->currentRotateType = this->pb->getRotateType(blocktype);

	if (!this->checkCollision(currentBlock, 0))
		this->gameOver = true;

	//cout << this->gameSpeed << endl;
}

//void Tightness::printBlock(int n)
void Tightness::printBlock(int center_x, int center_y, position* currentblock, int blockType)
{
	//this->pg->initGameboard();
	//this->pg->resetGameboard(); //현재 블록만을 지워준다

	for (int i = 0; i < this->pb->getNumOfStone(); i++)
	{
		//this->pg->setGameboard(1 + this->pb->block[type][i].y, this->pg->getBoardCenter_x() + this->pb->block[type][i].x, 2);
		if(currentblock[i].x != NOBLOCK && currentblock[i].y != NOBLOCK)
			this->pg->setGameboard(center_y + currentblock[i].y, center_x + currentblock[i].x, blockType);
	}
}

bool Tightness::checkCollision(position* currentblock, int flag)
{
	int x = this->currentCursor.x;
	int y = this->currentCursor.y;
	int next_x;
	int next_y;

	if (flag == CHECK::DOWNSIDE)
		y += 1;
	else if (flag == CHECK::RIGHTSIDE)
		x += 1;
	else if (flag == CHECK::LEFTSIDE)
		x -= 1;

	for (int i = 0; i < this->pb->getNumOfStone(); i++)
	{
		if (currentblock[i].x != NOBLOCK && currentblock[i].y != NOBLOCK)
		{
			next_x = currentblock[i].x + x;
			next_y = currentblock[i].y + y;
			if (this->pg->getGameboard(next_y, next_x) == 1 || this->pg->getGameboard(next_y, next_x) == 3)
				return false;
		}
	}

	return true;
}

bool Tightness::checkCollision(position* currentblock, int flag, int rotatetype)
{
	//int x = this->currentCursor.x;
	//int y = this->currentCursor.y;

	if (flag == CHECK::ROTATE)
	{
		position* rotatedblock = new position[this->pb->getNumOfStone()];

		for (int i = 0; i < this->pb->getNumOfStone(); i++)
			rotatedblock[i] = currentblock[i];

		rotateBlock(rotatedblock, rotatetype);

		int rotated_x;
		int rotated_y;
		for (int i = 0; i < this->pb->getNumOfStone(); i++)
		{
			if (currentblock[i].x != NOBLOCK && currentblock[i].y != NOBLOCK)
			{
				rotated_x = rotatedblock[i].x + this->currentCursor.x;
				rotated_y = rotatedblock[i].y + this->currentCursor.y;
				if (this->pg->getGameboard(rotated_y, rotated_x) == 1 || this->pg->getGameboard(rotated_y, rotated_x) == 3)
					return false;
			}
		}
	}
	return true;
}

void Tightness::rotateBlock(position* currentblock, int& rt)
{
	
	int temp;
	switch (rt)
	{
	case 0:
		break;
	case 1:
		for (int i = 0; i < this->pb->getNumOfStone(); i++)
		{
			if (currentblock[i].x != NOBLOCK, currentblock[i].y != NOBLOCK)
			{
				temp = currentblock[i].x;
				currentblock[i].x = -currentblock[i].y;
				currentblock[i].y = temp;
			}
		}
		rt = 2;
		break;
	case 2:
		for (int i = 0; i < this->pb->getNumOfStone(); i++)
		{
			if (currentblock[i].x != NOBLOCK, currentblock[i].y != NOBLOCK)
			{
				temp = currentblock[i].x;
				currentblock[i].x = currentblock[i].y;
				currentblock[i].y = -temp;
			}
		}
		rt = 1;
		break;
	case 3:
		for (int i = 0; i < this->pb->getNumOfStone(); i++)
		{
			if (currentblock[i].x != NOBLOCK, currentblock[i].y != NOBLOCK)
			{
				temp = currentblock[i].x;
				currentblock[i].x = -currentblock[i].y;
				currentblock[i].y = temp;
			}
		}
		break;
	}
}

void Tightness::nextBlock()
{
	this->randomType = rand() % this->pb->getNumOfType();

	this->pg->printNextBlock();
	for (int i = 0; i < this->pb->getNumOfStone(); i++)
	{
		if (this->pb->block[this->randomType][i].x != NOBLOCK && this->pb->block[this->randomType][i].y != NOBLOCK)
			this->pg->printNextBlock(this->pb->block[this->randomType][i]);
	}
}

void Tightness::holdBlock()
{
	if (this->holdType < 0)
	{
		this->holdType = this->currentType;

		this->pg->printHoldBlock(); 
		for (int i = 0; i < this->pb->getNumOfStone(); i++)
		{
			if (this->pb->block[this->holdType][i].x != NOBLOCK && this->pb->block[this->holdType][i].y != NOBLOCK)
				this->pg->printHoldBlock(this->pb->block[this->holdType][i]);
		}
		this->createBlock(this->randomType);

		this->nextBlock();
	}
	else if(this->canHold)
	{
		int temp = this->currentType;
		this->createBlock(this->holdType);
		this->holdType = temp;

		this->pg->printHoldBlock();
		for (int i = 0; i < this->pb->getNumOfStone(); i++)
		{
			if (this->pb->block[this->holdType][i].x != NOBLOCK && this->pb->block[this->holdType][i].y != NOBLOCK)
				this->pg->printHoldBlock(this->pb->block[this->holdType][i]);
		}

		this->canHold = false;
	}
}

void Tightness::landing()
{
	int point = 0;

	this->printBlock(this->currentCursor.x, this->currentCursor.y, this->currentBlock, 3);

	for (int i = 1; i < this->pg->getySize() - 1; i++)
	{
		for (int j = 1; j < this->pg->getxSize() - 1; j++)
		{
			if (this->pg->getGameboard(i, j) == 0)
				break;
			if (j == this->pg->getxSize() - 2)
			{
				delLine(i);
				if (point == 0)
					point += 200;
				else
					point *= 2;
			}
			//추가할 점수가 0이면 +100, 100이면 + 200, 300이면 +400 식으로 이중 포문을 돌며 추가점수를 올려준다
		}
	}
	//if 추가점수가 있으면(라인을 꺳으면) n++, 없으면(연속깨기 실패) n = 0;
	if (point != 0)
	{
		this->chain++;
		this->score += point * this->chain;
		this->pg->printInfo(this->score);
	}
	else
		this->chain = 0;

	//최종점수 += 추가점수 * n

	this->createBlock(this->randomType);
	this->nextBlock();

	this->canHold = true;
}

void Tightness::delLine(int deli)
{
	for (int j = 1; j < this->pg->getxSize() - 1; j++)
		this->pg->setGameboard(deli, j, 0);

	for (int i = deli; i > 0; i--)
	{
		for (int j = 1; j < this->pg->getxSize() - 1; j++)
		{
			this->pg->setGameboard(i, j, this->pg->getGameboard(i - 1, j));
		}
	}

	this->cleardLine++;
	if (this->gameSpeed > 750)
		this->gameSpeed -= 40;
	else if (this->gameSpeed > 500)
		this->gameSpeed -= 20;
	else if (this->gameSpeed > 250)
		this->gameSpeed -= 10;
	else if (this->gameSpeed > 100)
		this->gameSpeed -= 5;
}

void Tightness::show(bool previewFlag)
{
	this->pg->resetGameboard();

	if (previewFlag)
	{
		int tempy = this->currentCursor.y;
		while (this->checkCollision(this->currentBlock, CHECK::DOWNSIDE))
			this->currentCursor.y += 1;
		this->printBlock(this->currentCursor.x, this->currentCursor.y, this->currentBlock, 4);
		this->currentCursor.y = tempy;
	}
	this->printBlock(this->currentCursor.x, this->currentCursor.y, this->currentBlock, 2);

	this->pg->printGameboard();
}

void Tightness::ending()
{
	cout << "GameOver" << endl;

	delete this->currentBlock;
	
	if(this->highScore <= this->score)
		this->saveScore();
}

void Tightness::control()
{
	short key = getch();
	switch (key)
	{
	case KEYTYPE::DIRECTION:
		key = getch();
		//cout << key << endl;
		switch (key)
		{
		case KEYTYPE::UP:
			if (this->checkCollision(this->currentBlock, CHECK::ROTATE, this->currentRotateType))
				this->rotateBlock(this->currentBlock, this->currentRotateType);
			break;
		case KEYTYPE::DOWN:
			if (this->checkCollision(this->currentBlock, CHECK::DOWNSIDE))
				this->currentCursor.y += 1;
			else
				this->landing();
			break;
		case KEYTYPE::RIGHT:
			if (this->checkCollision(this->currentBlock, CHECK::RIGHTSIDE))
				this->currentCursor.x += 1;
			break;
		case KEYTYPE::LEFT:
			if (this->checkCollision(this->currentBlock, CHECK::LEFTSIDE))
				this->currentCursor.x -= 1;
			break;
		}
		break;
	/*case 'w':
		if (this->checkCollision(this->currentBlock, KEY::UP, this->currentRotateType))
			this->rotateBlock(this->currentBlock, this->currentRotateType);
		break;
	case 'a':
		if (this->checkCollision(this->currentBlock, KEY::LEFT))
			this->currentCursor.x -= 1;
		break;
	case 'd':
		if (this->checkCollision(this->currentBlock, KEY::RIGHT))
			this->currentCursor.x += 1;
		break;
	case 's':
		if (this->checkCollision(this->currentBlock, KEY::DOWN))
			this->currentCursor.y += 1;
		else
			this->landing();
		break;
	case 'k':
		while (this->checkCollision(this->currentBlock, KEY::DOWN))
			this->currentCursor.y += 1;
		this->landing();
		break;*/
	case 'z':
		this->holdBlock();
		break;
	case 'v':
		if (this->preview)
			this->preview = false;
		else
			this->preview = true;
		break;
	case 'p':
		this->pause();
		break;
	case KEYTYPE::SPACE_BAR:
		while (this->checkCollision(this->currentBlock, CHECK::DOWNSIDE))
			this->currentCursor.y += 1;
		this->landing();
		break;
	case KEYTYPE::ESC:
		this->gameOver = true;
		break;
	}
}

bool Tightness::checkTime(unsigned long time)
{
	this->currTime = timeGetTime();

	if (this->currTime - this->prevTime > time)
	{
		this->prevTime = this->currTime;
		return true;
	}
	else
		return false;
}

void Tightness::pause()
{
	COORD pos = { 12, 10 };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	cout << "P A U S E" << endl;
	while (true)
	{
		if (_kbhit())
			break;
	}
}

void Tightness::loadScore()
{
	FILE* fp = _tfopen(_T("HighScore.txt"), _T("r, ccs=UNICODE"));
	if (fp == NULL)
		return;

	TCHAR name[10];
	unsigned int score;
	_ftscanf(fp, _T("%s %d"), name, &score);

	this->pg->printInfo(name, score);

	this->highScore = score;

	fclose(fp);
}

void Tightness::saveScore()
{
	FILE* fp = _tfopen(_T("HighScore.txt"), _T("w, ccs=UNICODE"));
	if (fp == NULL)
		return;

	cout << "최고 기록 달성!" << endl;

	TCHAR name[10];
	cout << "이름을 입력해 주세요 : ";
	wcin >> name;

	_ftprintf(fp, _T("%s %d"), name, score);

	fclose(fp);
}