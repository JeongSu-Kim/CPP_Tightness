#pragma once

#include "stdafx.h"

#define NOBLOCK 100

class Block
{
protected:
	//����� ����
	int numOfType;

	//��ϴ� ������
	int numOfStone; 

	//������Ʈ�� ���� �߰�
	int* rotateType;

	//block�� ��ǥ ����, �����ڿ��� ȣ��
	template <size_t Y>
	void setBlock(position(*mino)[Y]);

	//Block��ü�� ��ü�� �����ϸ� �ȵǰ� ��ӹ��� �ڽ� Ŭ������� ��ü�� ������ �ϱ⶧���� protected�� �־�ô�.
	Block();

public:

	virtual ~Block();

	//��� ��ü ��ǥ�� ������
	position** block;

	//��� ���� ���� ��ȯ
	int getNumOfType();

	//��ϴ� ������ ��ȯ
	int getNumOfStone();

	////��� ��ü�� ��ǥ�� ����ִ� ������ ��ȯ
	//position** getBlock();

	int getRotateType(int blockType); //<-�߰�
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