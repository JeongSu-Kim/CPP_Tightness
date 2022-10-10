// Tightness.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

#include "tightness.h"
#include "gameboard.h"
#include "block.h"

#include <crtdbg.h>
#ifdef _DEBUG
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	CONSOLE_CURSOR_INFO CurInfo;
	CurInfo.dwSize = 1;
	CurInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);

	Tightness* t = new Tightness(new Tetromino, new Gameboard);
	Tightness* t_2 = new Tightness(new Tightmino, new Gameboard(16, 24));
	Tightness* t_3 = new Tightness(new Pentomino, new Gameboard(18, 24));


	t->playGame(); //tetris
	//t_2->playGame(); //tightness
	//t_3->playGame(); //pentris
	//��ũ ������ C++ -> ��Ŀ -> �Է� -> �߰����Ӽ��� winmm.lib�� �߰�

	delete t;
	delete t_2;
	delete t_3;

	return 0;
}

