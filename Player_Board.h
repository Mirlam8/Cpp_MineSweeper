#pragma once
#include "Board.h"
class Player_Board : public Board
{
private:
	int numMines = 0;
	int numOpened = 0;
	void init_Array(int k);
	//void open(int x, int y, Board *b);
	bool is_checked(int x, int y);

public:
	bool gameover = false;
	Player_Board(int x, int y, int mine);
	~Player_Board();
	void open(int x, int y, Board *b);
	void GameOver();
	void GameClear();
};

