#pragma once
#include "Board.h"

class Mine_Board : public Board
{
private:
	int numMines = 0;
	void set_Mine();
	void set_Num();
	int get_RandNum(int min, int max);

public:
	Mine_Board(int x, int y, int mine);

	~Mine_Board();

	int get_numMines();
};

	